#include "WelcomeScene.h"

USING_NS_CC;

Scene* WelcomeScene::welcomeScene = nullptr;
WelcomeBackgroundLayer* WelcomeScene::welcomeBackgroundLayer = nullptr;
WelcomeButtonLayer* WelcomeScene::welcomeButtonLayer = nullptr;

Scene* WelcomeScene::create()
{
    // 'scene' is an autorelease object
	welcomeScene = Scene::create();
    
    // add background layer as a child to welcome scene
    welcomeBackgroundLayer = WelcomeBackgroundLayer::create();
    welcomeBackgroundLayer->setParent(welcomeScene);
    welcomeScene->addChild(welcomeBackgroundLayer);

    // add button layer as a child to welcome scene
    welcomeButtonLayer = WelcomeButtonLayer::create();
    welcomeButtonLayer->setParent(welcomeScene);
    welcomeScene->addChild(welcomeButtonLayer);

    // return the scene
    return welcomeScene;
}
