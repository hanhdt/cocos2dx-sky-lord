#ifndef __WELCOMEBUTTON_LAYER_H__
#define __WELCOMEBUTTON_LAYER_H__

#include "cocos2d.h"
#include "SelectScene.h"

/**
 *  Show the start game button in the welcome scene.
 */
class WelcomeButtonLayer : public cocos2d::Layer
{
public:

	CREATE_FUNC(WelcomeButtonLayer);

private:
    virtual bool init() override;

    void startGameButtonCallback(cocos2d::Ref* pSender);

};

#endif // __WELCOMEBUTTON_LAYER_H__
