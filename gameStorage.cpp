/***********************************************************************
 * Source File:
 *    GAME STORAGE
 * Author:
 *    Team 2
 * Summary:
 *    The container class that stores all our game data.
 ************************************************************************/
#include "gameStorage.h"

// defines static dimensions used for game's viewport
Position GameStorage::dimensions = Position(WIDTH, HEIGHT);

void GameStorage::initialize(GameInterface& gameViews){
	views.push_back(gameViews);
}

void GameStorage::addBird(BirdStorage* newBird) {
	birds.push_back(newBird);
}

void GameStorage::addBullet(BulletStorage* newBullet) {
	bullets.push_back(newBullet);
}

void GameStorage::addEffect(EffectStorage* newEffect) {
	effects.push_back(newEffect);
}

//Commented out due to errors
//void GameStorage::addPoints(Position pos, int pts) {
//	points.push_back(PointsStorage(pos, pts));
//}