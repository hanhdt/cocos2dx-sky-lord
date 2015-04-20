#include "SelectBackgroundLayer.h"

USING_NS_CC;

bool SelectBackgroundLayer::init() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Setup keyboard listener
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(
			SelectBackgroundLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad,
			this);

	// Add background image to layer
	Sprite* background = Sprite::createWithSpriteFrameName(
			"selectSceneBackground.jpg");
	background->setAnchorPoint(Vec2::ZERO);
	background->setScale(3);
	this->addChild(background);

	Sprite* blank1 = Sprite::createWithSpriteFrameName("img_bg_1.jpg");
	blank1->setScale(0.5);
	//blank1->setAnchorPoint(Point(0, 0));
	blank1->setPosition( origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 + blank1->getContentSize().height * 0.5);
	this->addChild(blank1);

	Sprite* blank2 = Sprite::createWithSpriteFrameName("img_bg_2.jpg");
	blank2->setScale(0.5);
	blank2->setPosition(blank1->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 + blank1->getContentSize().height * 0.5);
	this->addChild(blank2);
	Sprite* blank2_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank2_locked->setPosition(blank1->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 + blank1->getContentSize().height * 0.5);
	this->addChild(blank2_locked);

	Sprite* blank3 = Sprite::createWithSpriteFrameName("img_bg_3.jpg");
	blank3->setScale(0.5);
	blank3->setPosition(blank2->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 + blank1->getContentSize().height * 0.5);
	this->addChild(blank3);
	Sprite* blank3_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank3_locked->setPosition(blank2->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 + blank1->getContentSize().height * 0.5);
	this->addChild(blank3_locked);

	Sprite* blank4 = Sprite::createWithSpriteFrameName("img_bg_4.jpg");
	blank4->setScale(0.5);
	blank4->setPosition(origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 - blank1->getContentSize().height * 0.2);
	this->addChild(blank4);
	Sprite* blank4_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank4_locked->setPosition(origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 - blank1->getContentSize().height * 0.2);
	this->addChild(blank4_locked);

	Sprite* blank5 = Sprite::createWithSpriteFrameName("img_bg_5.jpg");
	blank5->setScale(0.5);
	blank5->setPosition(blank4->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 - blank1->getContentSize().height * 0.2);
	this->addChild(blank5);
	Sprite* blank5_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank5_locked->setPosition(blank4->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 - blank1->getContentSize().height * 0.2);
	this->addChild(blank5_locked);

	Sprite* blank6 = Sprite::createWithSpriteFrameName("blank.png");
	blank6->setPosition(blank5->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 - blank1->getContentSize().height * 0.2);
	this->addChild(blank6);
	Sprite* blank6_locked = Sprite::createWithSpriteFrameName("locked.png");
	blank6_locked->setPosition(blank5->getPositionX() + origin.x + blank1->getBoundingBox().size.width * 1.5,
			visibleSize.height * 0.5 - blank1->getContentSize().height * 0.2);
	this->addChild(blank6_locked);

	TTFConfig ttfConfig("fonts/SIMLI.TTF", 100);

	Label* titleLabel = Label::createWithTTF(ttfConfig, "Select Maps",
			TextHAlignment::CENTER);
	titleLabel->enableShadow();
	titleLabel->setColor(Color3B(255, 201, 37));
	titleLabel->setPosition(Director::getInstance()->getWinSize().width / 2,
			Director::getInstance()->getWinSize().height - 100);
	this->addChild(titleLabel);

	return true;
}

void SelectBackgroundLayer::onKeyReleased(EventKeyboard::KeyCode keyCode,
		Event* event) {
	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_BACK:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}
