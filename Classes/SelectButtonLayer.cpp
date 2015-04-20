#include "SelectButtonLayer.h"

USING_NS_CC;

bool SelectButtonLayer::init() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	MenuItemSprite* startGameButtonItemSprite = MenuItemSprite::create(
			Sprite::createWithSpriteFrameName("selectStartButton.png"),
			Sprite::createWithSpriteFrameName("selectStartButton.png"),
			CC_CALLBACK_1(SelectButtonLayer::startGameButtonCallback, this));
	Menu* startGameButton = Menu::create(startGameButtonItemSprite, nullptr);

	startGameButton->setPosition(visibleSize.width * 0.5 + origin.x, 200 + origin.y);
	this->addChild(startGameButton);

	return true;
}

void SelectButtonLayer::startGameButtonCallback(Ref* pSender)
{
	Scene* gameSceneWithAnimation = TransitionFade::create(TRANSITION_TIME, GameScene::createScene());
	Director::getInstance()->replaceScene(gameSceneWithAnimation);
}
