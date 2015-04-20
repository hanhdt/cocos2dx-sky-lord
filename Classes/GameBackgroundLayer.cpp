#include "GameBackgroundLayer.h"

USING_NS_CC;

bool GameBackgroundLayer::init() {
	_visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Add first background
	backgroundSprite1 = Sprite::createWithSpriteFrameName("img_bg_1.jpg");
	backgroundSprite1->setAnchorPoint(Vec2::ZERO);
	backgroundSprite1->setScale(3);
	backgroundSprite1->setPosition(Vec2::ZERO);
	this->addChild(backgroundSprite1);

	// Add second background
	backgroundSprite2 = Sprite::createWithSpriteFrameName("img_bg_1.jpg");
	backgroundSprite2->setAnchorPoint(Vec2::ZERO);
	backgroundSprite2->setScale(3);
	backgroundSprite2->setPosition(
			Vec2(0, backgroundSprite1->getBoundingBox().size.height - 1));
	this->addChild(backgroundSprite2);

	// Add third background
	backgroundSprite3 = Sprite::createWithSpriteFrameName("img_bg_1.jpg");
	backgroundSprite3->setAnchorPoint(Vec2::ZERO);
	backgroundSprite3->setScale(3);
	backgroundSprite3->setPosition(
			Vec2(0, 2 * (backgroundSprite1->getBoundingBox().size.height - 1)));
	this->addChild(backgroundSprite3);

	scheduleUpdate();

	return true;
}

void GameBackgroundLayer::update(float dt) {
	updateBgPosition(backgroundSprite1);
	updateBgPosition(backgroundSprite2);
	updateBgPosition(backgroundSprite3);
}

/**
 * Move the background sprites.
 * If a part is moved off the screen to bottom,
 * it is moved back off the screen to the top.
 *
 * @param pBg The background sprite that should be moved.
 */
void GameBackgroundLayer::updateBgPosition(Sprite* pBg) {
	if (pBg) {
		Vec2 bgPos = pBg->getPosition();
		bgPos.y -= 1;
		float bgHeight = pBg->getBoundingBox().size.height;
		if (bgPos.y < -bgHeight) {
			bgPos.y = 2 * bgHeight - 4;
			// To remove a black line between third and first part of the background,
			// after the first part has been moved to the right,
			// the part needs to be detached from the layer and added again.
			// This will move the first part on top of the others.
			// The object needs to be retained as removeChild would delete the object.
			pBg->retain();
			this->removeChild(pBg, false);
			this->addChild(pBg);
		};
		pBg->setPosition(bgPos);
	}
}
