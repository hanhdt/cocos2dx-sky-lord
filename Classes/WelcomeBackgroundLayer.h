#ifndef __WELCOMEBACKGROUND_LAYER_H__
#define __WELCOMEBACKGROUND_LAYER_H__

#include "cocos2d.h"

/**
 *  Show background image in the welcome scene
 */
class WelcomeBackgroundLayer : public cocos2d::Layer
{
public:

	CREATE_FUNC(WelcomeBackgroundLayer);

private:
    virtual bool init() override;

    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event) override;
};

#endif // __WELCOMEBACKGROUND_LAYER_H__
