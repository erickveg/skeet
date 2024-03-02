/***********************************************************************
 * Source File:
 *    GAME INTERFACE
 * Author:
 *    Team 2
 * Summary:
 *    The container class that deals with drawing objects
 *    and handling user input.
 ************************************************************************/
#include "gameInterface.h"
#include <string>
#include <sstream>
using namespace std;


#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

/************************
 * SKEET INTERACT
 * handle all user input
 ************************/
void GameInterface::interact(const UserInput& ui)
{
    Time time = storage.getTime();
    Score score = storage.Score();
    HitRadio hitRadio = storage.getHiRatio();
    Gun gun = storage.getGun();
    bool bullseye = storage.getBullseye();
    std::list<Bullet*> bullets;   

    // reset the game
    if (time.isGameOver() && ui.isSpace())
    {
        time.reset();
        score.reset();
        hitRatio.reset();
        return;
    }

    // gather input from the interface
    gun.interact(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft());
    Bullet* p = logic.setBullet(ui);

    bullseye = logic.setBullseye(ui);

    // add something if something has been added
    if (nullptr != p)
        storage.getBullets().push_back(p);

    // send movement information to all the bullets. Only the missile cares.
    for (auto bullet : bullets)
        BulletType bulletType = bullet.getType()
        logic.bulletLogics[bulletType].input(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft(), ui.isB());
}

/************************
* SKEET DRAW LEVEL
* output everything that will be on the screen
************************/
void GameInterface::drawLevel() const
{
    bool bullseye = storage.getBullseye();
    Time time = storage.getTime();
    Gun gun = storage.getGun();
    Position dimensions = storage.getDimensions();
    Score score = storage.getScore();
    HitRadio hitRadio = storage.getHitRadio();    

    // output the background
    drawBackground(time.level() * .1, 0.0, 0.0);

    // draw the bullseye
    if (bullseye)
        drawBullseye(gun.getAngle());

    // output the gun
    gunInterface().display();

    // output the birds, bullets, and fragments
    for (auto& pts : storage.getPoints())
        pts.show();

    for (auto effect : storage.getEffects())
    {
        EffectType effectType = effect.getType();
        effectInterfaces[effectType].draw();
    }

    for (auto bullet : storage.getBullets())
    {
        EffectType effectType = bullet.getType();
        bulletInterfaces[effectType].draw();
    }

    for (auto bird : storage.getBirds())
    {
        EffectType effectType = bird.getType();
        birdInterfaces[effectType].draw();
    }

    // status
    drawText(Position(10, dimensions.getY() - 30), score.getText());
    drawText(Position(dimensions.getX() / 2 - 30, dimensions.getY() - 30), time.getText());
    drawText(Position(dimensions.getX() - 110, dimensions.getY() - 30), hitRatio.getText());
}

/************************
 * SKEET DRAW STATUS
 * place the status message on the center of the screen
 ************************/
void GameInterface::drawStatus() const
{
    Time time = storage.getTime();
    Position dimensions = storage.getDimensions();
    Score score = storage.getScore();

    // output the text information
    ostringstream sout;
    if (time.isGameOver())
    {
        // draw the end of game message
        drawText(Position(dimensions.getX() / 2 - 30, dimensions.getY() / 2 + 10),
            "Game Over");

        // draw end of game status
        drawText(Position(dimensions.getX() / 2 - 30, dimensions.getY() / 2 - 10),
            score.getText());
    }
    else
    {
        // output the status timer
        drawTimer(1.0 - time.percentLeft(),
            (time.level() - 0.0) * .1, 0.0, 0.0,
            (time.level() - 1.0) * .1, 0.0, 0.0);

        // draw the message giving a countdown
        sout << "Level " << time.level()
            << " begins in " << time.secondsLeft() << " seconds";
        drawText(Position(dimensions.getX() / 2 - 110, dimensions.getY() / 2 - 10),
            sout.str());
    }
}

/************************************************************************
 * DRAW Background
 * Fill in the background
 *  INPUT color   Background color
 *************************************************************************/
void GameInterface::drawBackground(double redBack, double greenBack, double blueBack) const
{
    Position dimensions = storage.getDimensions();

    glBegin(GL_TRIANGLE_FAN);

    // two rectangles is the fastest way to fill the screen.
    glColor3f((GLfloat)redBack /* red % */, (GLfloat)greenBack /* green % */, (GLfloat)blueBack /* blue % */);
    glVertex2f((GLfloat)0.0, (GLfloat)0.0);
    glVertex2f((GLfloat)dimensions.getX(), (GLfloat)0.0);
    glVertex2f((GLfloat)dimensions.getX(), (GLfloat)dimensions.getY());
    glVertex2f((GLfloat)0.0, (GLfloat)dimensions.getY());

    glEnd();
}

/************************************************************************
 * DRAW Timer
 * Draw a large timer on the screen
 *  INPUT percent     Amount of time left
 *        Foreground  Foreground color
 *        Background  Background color
 *************************************************************************/
void GameInterface::drawTimer(double percent,
    double redFore, double greenFore, double blueFore,
    double redBack, double greenBack, double blueBack) const
{
    Position dimensions = storage.getDimensions();

    double radians;

    GLfloat length = (GLfloat)dimensions.getX();
    GLfloat half = length / (GLfloat)2.0;

    // do the background stuff
    drawBackground(redBack, greenBack, blueBack);

    // foreground stuff
    radians = percent * M_PI * 2.0;
    GLfloat x_extent = half + length * (GLfloat)sin(radians);
    GLfloat y_extent = half + length * (GLfloat)cos(radians);

    // get read to draw the triangles
    glBegin(GL_TRIANGLE_FAN);
    glColor3f((GLfloat)redFore /* red % */, (GLfloat)greenFore /* green % */, (GLfloat)blueFore /* blue % */);
    glVertex2f(half, half);

    // fill in the triangles, one eight at a time
    switch ((int)(percent * 8.0))
    {
    case 7: // 315 - 360
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, length);
        break;
    case 6: // 270 - 315
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, half);
        break;
    case 5: // 225 - 270
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(0.0, 0.0);
        break;
    case 4: // 180 - 225
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(half, 0.0);
        break;
    case 3: // 135 - 180
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, half);
        glVertex2f(length, 0.0);
        break;
    case 2: // 90 - 135 degrees
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, half);
        break;
    case 1: // 45 - 90 degrees
        glVertex2f(half, length);
        glVertex2f(length, length);
        break;
    case 0: // 0 - 45 degrees
        glVertex2f(half, length);
        break;
    }
    glVertex2f(x_extent, y_extent);

    // complete drawing
    glEnd();

    // draw the red line now
    glBegin(GL_LINES);
    glColor3f((GLfloat)0.6, (GLfloat)0.0, (GLfloat)0.0);
    glVertex2f(half, half);
    glVertex2f(x_extent, y_extent);
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 *   INPUT  topLeft   The top left corner of the text
 *          text      The text to be displayed
 ************************************************************************/
void drawText(const Position& topLeft, const char* text)
{
    void* pFont = GLUT_TEXT;
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);

    // prepare to output the text from the top-left corner
    glRasterPos2f((GLfloat)topLeft.getX(), (GLfloat)topLeft.getY());

    // loop through the text
    for (const char* p = text; *p; p++)
        glutBitmapCharacter(pFont, *p);
}
void drawText(const Position& topLeft, const string& text)
{
    drawText(topLeft, text.c_str());
}

/************************
 * DRAW BULLSEYE
 * Put a bullseye on the screen
 ************************/
void GameInterface::drawBullseye(double angle) const
{
    Position dimensions = storage.getDimensions();

    // find where we are pointing
    double distance = dimensions.getX();
    GLfloat x = dimensions.getX() - distance * cos(angle);
    GLfloat y = distance * sin(angle);

    // draw the crosshairs
    glBegin(GL_LINES);
    glColor3f((GLfloat)0.6, (GLfloat)0.6, (GLfloat)0.6);

    // Draw the actual lines
    glVertex2f(x - 10.0, y);
    glVertex2f(x + 10.0, y);

    glVertex2f(x, y - 10.0);
    glVertex2f(x, y + 10.0);

    glColor3f((GLfloat)0.2, (GLfloat)0.2, (GLfloat)0.2);
    glVertex2f(dimensions.getX(), 0.0);
    glVertex2f(x, y);

    // Complete drawing
    glEnd();
}