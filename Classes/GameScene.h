#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameBackgroundLayer.h"
#include "PlaneLayer.h"
#include "EnemyLayer.h"

class GameScene : public cocos2d::Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    GameBackgroundLayer* getGameBackgroundLayer();
    PlaneLayer* getPlaneLayer();
    EnemyLayer* getEnemyLayer();
private:
    static cocos2d::Scene* gameScene;
    static GameBackgroundLayer* gameBackgroundLayer;
    static PlaneLayer* planeLayer;
    static EnemyLayer* enemyLayer;
};

#endif // __GAME_SCENE_H__
