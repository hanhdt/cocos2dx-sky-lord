#ifndef __SELECT_SCENE_H__
#define __SELECT_SCENE_H__

#include "cocos2d.h"
#include "SelectBackgroundLayer.h"
#include "SelectButtonLayer.h"

class SelectScene : public cocos2d::Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
private:
    static cocos2d::Scene* selectScene;

};

#endif // __SELECT_SCENE_H__
