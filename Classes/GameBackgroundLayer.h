#ifndef __GAMEBACKGROUND_LAYER_H__
#define __GAMEBACKGROUND_LAYER_H__

#include "cocos2d.h"
#include "Definitions.h"

/**
 *  Background Layer, auto loading the background image and rolling.
 */
class GameBackgroundLayer : public cocos2d::Layer
{
public:

	CREATE_FUNC(GameBackgroundLayer);

private:
	void update(float dt) override;
	void updateBgPosition(cocos2d::Sprite* pBg);
	cocos2d::Sprite* backgroundSprite1;
	cocos2d::Sprite* backgroundSprite2;
	cocos2d::Sprite* backgroundSprite3;
	cocos2d::Size _visibleSize;

    virtual bool init() override;
};

#endif // __GAMEBACKGROUND_LAYER_H__
