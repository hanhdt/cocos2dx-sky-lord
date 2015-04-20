#include "WelcomeBackgroundLayer.h"

USING_NS_CC;

bool WelcomeBackgroundLayer::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Setup keyboard listener
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(WelcomeBackgroundLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

	// Add background image to layer
	Sprite* background = Sprite::createWithSpriteFrameName("img_bg_welcome.jpg");
	background->setAnchorPoint(Vec2::ZERO);
	background->setScale(3);
	this->addChild(background);

	// Add logo image
	Sprite* logo = Sprite::createWithSpriteFrameName("logo.png");
	logo->setAnchorPoint(Vec2(0.5, 0.5));
	logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.55));
	this->addChild(logo);

	return true;
}

void WelcomeBackgroundLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch(keyCode){
	case EventKeyboard::KeyCode::KEY_BACK:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}
