#ifndef __WELCOME_SCENE_H__
#define __WELCOME_SCENE_H__

#include "cocos2d.h"
#include "WelcomeBackgroundLayer.h"
#include "WelcomeButtonLayer.h"

/**
 *  Welcome scene, the loading image.
 */
class WelcomeScene : public cocos2d::Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* create();

private:
    static Scene* welcomeScene;
    static WelcomeBackgroundLayer* welcomeBackgroundLayer;
    static WelcomeButtonLayer* welcomeButtonLayer;
};

#endif // __WELCOME_SCENE_H__
