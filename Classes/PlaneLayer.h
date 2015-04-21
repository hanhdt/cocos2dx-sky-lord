#ifndef __PLANE_LAYER_H__
#define __PLANE_LAYER_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

enum {
	kBackground, kMiddleground, kForeground
};

USING_NS_CC;
using namespace CocosDenshion;

/**
 *  Plane Layer, Interactive layer of the game.
 */
class PlaneLayer: public cocos2d::Layer {
public:
	PlaneLayer();
	CREATE_FUNC(PlaneLayer);
	cocos2d::Sprite* getMyPlane();
	int getInitHP() const;
	ParticleSystem * _jet1;
	ParticleSystem * _jet2;
	ParticleSystem * _warp;
	void createPlaneParticles();
private:
	const int initHP;
	void update(float dt) override;
	virtual bool init() override;

	cocos2d::Size _visibleSize;
	cocos2d::Sprite* _mPlane;

	virtual bool onTouchBegan(cocos2d::Touch *touch,
			cocos2d::Event *unused_event) override;
	virtual void onTouchMoved(cocos2d::Touch *touch,
			cocos2d::Event *unused_event) override;
	virtual void onTouchEnded(cocos2d::Touch *touch,
				cocos2d::Event *unused_event) override;
};

#endif // __GAMEBACKGROUND_LAYER_H__
