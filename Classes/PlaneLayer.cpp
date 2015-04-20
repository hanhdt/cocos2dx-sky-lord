#include "PlaneLayer.h"

USING_NS_CC;

PlaneLayer::PlaneLayer() :
		initHP(1000), _mPlane(nullptr), _visibleSize(
				Director::getInstance()->getVisibleSize()){
}

void PlaneLayer::createPlaneParticles() {
	_jet1 = ParticleSystemQuad::create("jet.plist");
	_jet1->setSourcePosition(
			Vec2((_mPlane->getBoundingBox().size.width * 0.5f) * 0.8f, 0));
	_jet1->setAngle(-90);
	_jet1->stopSystem();
	this->addChild(_jet1, kBackground);

	_jet2 = ParticleSystemQuad::create("jet.plist");
	_jet2->setAngle(-90);
	_jet2->stopSystem();
	_jet2->setSourcePosition(Vec2((_mPlane->getBoundingBox().size.width * 0.5f) * 0.8f,0));
	this->addChild(_jet2, kBackground);

	_boom = ParticleSystemQuad::create("boom.plist");
	_boom->stopSystem();
	this->addChild(_boom, kForeground);

	_comet = ParticleSystemQuad::create("comet.plist");
	_comet->stopSystem();
	_comet->setPosition(Vec2(0, _visibleSize.height * 0.6f));
	_comet->setVisible(false);
	this->addChild(_comet, kForeground);

	_pickup = ParticleSystemQuad::create("plink.plist");
	_pickup->stopSystem();
	this->addChild(_pickup, kMiddleground);

	// Warm-up starting position
	_warp = ParticleSystemQuad::create("warp.plist");
	_warp->setPosition(_mPlane->getPosition());
	this->addChild(_warp, kBackground);

	// Particle system for the star
	_star = ParticleSystemQuad::create("star.plist");
	_star->stopSystem();
	_star->setVisible(false);
	this->addChild(_star, kBackground);
}

bool PlaneLayer::init() {

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlaneLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlaneLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PlaneLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	_visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_mPlane = Sprite::createWithSpriteFrameName("myPlane.png");
	_mPlane->setAnchorPoint(Vec2(0.5, 0));
	_mPlane->setPosition(_visibleSize.width / 2,
			origin.y + _mPlane->getContentSize().height * 0.5);
	this->addChild(_mPlane, kForeground, "PLANE");

	this->createPlaneParticles();

	scheduleUpdate();

	return true;
}

void PlaneLayer::update(float dt) {

}

bool PlaneLayer::onTouchBegan(cocos2d::Touch *touch,
		cocos2d::Event *unused_event) {
	// Stop warp effect
	if(_warp->isActive())
		_warp->stopSystem();
	return true;
}

int PlaneLayer::getInitHP() const {
	return this->initHP;
}

void PlaneLayer::onTouchMoved(cocos2d::Touch *touch,
		cocos2d::Event *unused_event) {
	if (Director::getInstance()->isPaused() == false) {
		_mPlane->setPosition(_mPlane->getPosition() + touch->getDelta());
		if (_mPlane->getPositionX() < 0) {
			_mPlane->setPositionX(0);
		} else if (_mPlane->getPositionX() > _visibleSize.width) {
			_mPlane->setPositionX(_visibleSize.width);
		}
		if (_mPlane->getPositionY() < 0) {
			_mPlane->setPositionY(0);
		} else if (_mPlane->getPositionY() + _mPlane->getContentSize().height
				> _visibleSize.height) {
			_mPlane->setPositionY(
					_visibleSize.height - _mPlane->getContentSize().height);
		}

		if(!_jet1->isActive()){
			_jet1->resetSystem();
			_jet2->resetSystem();
		}

		_jet1->setRotation(_mPlane->getRotation());
		_jet1->setPosition(_mPlane->getPosition());
		_jet2->setRotation(_mPlane->getRotation());
		_jet2->setPosition(Vec2(_mPlane->getPositionX() - _mPlane->getContentSize().width * 0.8, _mPlane->getPositionY()));
	}

}

void PlaneLayer::onTouchEnded(cocos2d::Touch *touch,
		cocos2d::Event *unused_event)
{
	if(_jet1->isActive())
	{
		_jet1->stopSystem();
		_jet2->stopSystem();
	}
}
