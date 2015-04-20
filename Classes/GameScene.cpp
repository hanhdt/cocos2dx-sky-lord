#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::gameScene = nullptr;
GameBackgroundLayer* GameScene::gameBackgroundLayer = nullptr;
PlaneLayer* GameScene::planeLayer = nullptr;
EnemyLayer* GameScene::enemyLayer = nullptr;

Scene* GameScene::createScene()
{
    // 'scene' is an auto-release object
	gameScene = Scene::create();
    
	// Add background layer
	gameBackgroundLayer = GameBackgroundLayer::create();
	gameBackgroundLayer->setParent(gameScene);

	// Add plane player
	planeLayer = PlaneLayer::create();
	planeLayer->setParent(gameScene);

	// Add enemy layer
	enemyLayer = EnemyLayer::create();
	enemyLayer->setParent(gameScene);



	gameScene->addChild(gameBackgroundLayer);
	gameScene->addChild(planeLayer);
	gameScene->addChild(enemyLayer);
    // return the scene
    return gameScene;
}

GameBackgroundLayer* GameScene::getGameBackgroundLayer()
{
	return this->gameBackgroundLayer;
}

PlaneLayer* GameScene::getPlaneLayer(){
	return this->planeLayer;
}

EnemyLayer* GameScene::getEnemyLayer(){
	return this->enemyLayer;
}
