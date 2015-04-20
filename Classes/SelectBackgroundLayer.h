#ifndef __SELECTBACKGROUND_LAYER_H__
#define __SELECTBACKGROUND_LAYER_H__

#include "cocos2d.h"

/**
 *  To show Select Scene's background.
 */
class SelectBackgroundLayer : public cocos2d::Layer
{
public:

	CREATE_FUNC(SelectBackgroundLayer);

private:
    virtual bool init() override;

    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event) override;
};

#endif // __SELECTBACKGROUND_LAYER_H__
