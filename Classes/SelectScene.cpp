#include "SelectScene.h"

USING_NS_CC;

Scene* SelectScene::selectScene = nullptr;

Scene* SelectScene::createScene()
{
    // 'scene' is an auto-release object
	selectScene = Scene::create();
    
	// Add background layer to scene
	SelectBackgroundLayer* selectBackgroundLayer = SelectBackgroundLayer::create();
	selectBackgroundLayer->setParent(selectScene);
	selectScene->addChild(selectBackgroundLayer);

	// Add button layer to scene
	SelectButtonLayer* selectButtonLayer = SelectButtonLayer::create();
	selectButtonLayer->setParent(selectScene);
	selectScene->addChild(selectButtonLayer);

    // return the scene
    return selectScene;
}

