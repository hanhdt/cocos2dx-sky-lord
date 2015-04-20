#include "WelcomeButtonLayer.h"

USING_NS_CC;

bool WelcomeButtonLayer::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	MenuItemSprite* startGameButtonSprite = MenuItemSprite::create(Sprite::create("play_btn.png"),
			Sprite::create("selected_play_btn.png"), CC_CALLBACK_1(WelcomeButtonLayer::startGameButtonCallback,this));
	Menu* startGameButton = Menu::create(startGameButtonSprite, nullptr);
	startGameButton->setAnchorPoint(Vec2::ZERO);
	startGameButton->setPosition(visibleSize.width * 0.5f, visibleSize.height * 0.3f);
	this->addChild(startGameButton);

	return true;
}

void WelcomeButtonLayer::startGameButtonCallback(Ref* pSender)
{
	cocos2d::log("Start game");
	auto selectSceneWithAnimation = TransitionFade::create(2.0f, SelectScene::createScene());
	Director::getInstance()->replaceScene(selectSceneWithAnimation);
}
