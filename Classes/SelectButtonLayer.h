#ifndef __SELECTBUTTON_LAYER_H__
#define __SELECTBUTTON_LAYER_H__

#include "cocos2d.h"
#include "GameScene.h"
#include "Definitions.h"

/**
 *  To show Select Scene's background.
 */
class SelectButtonLayer : public cocos2d::Layer
{
public:

	CREATE_FUNC(SelectButtonLayer);

private:
    virtual bool init() override;

    void startGameButtonCallback(Ref* pSender);
};

#endif // __SELECTBUTTON_LAYER_H__
