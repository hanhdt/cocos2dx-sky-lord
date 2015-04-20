#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"
#include <string>
#include <vector>

USING_NS_CC;
using namespace CocosDenshion;

/**
 *  Loading the enemies, and also, providing the interface of the crash detecting.
 */
class EnemyLayer: public cocos2d::Layer {
public:
	EnemyLayer();
	~EnemyLayer();
	CREATE_FUNC(EnemyLayer);
	cocos2d::Sprite* getBossSprite();
	void createEnemyParticles();
	cocos2d::Animate* _actionExplosion;

private:
	const float  baseEnemyAppearProbability;
	const float deltaEnemyAppearProbability;
	float nowEnemyAppearProbability;
	std::vector<std::string> enemyTextureName;
	std::vector<int> enemyFlyTime;
	cocos2d::Vector<cocos2d::Sprite*> allEnemy;
	const cocos2d::Size _visibleSize;

	virtual bool init() override;
	void addEnemySprite(float useless);
	void movingEnemy(cocos2d::Sprite* enemy, float time,
			float randomLevel, float randomPositionX);
	void enemyMoveFinished(Node* pSender);
	void startAddEnemy();
	void stopAddEnemy();
	void update(float dt) override;
	void changeSceneCallBack(float useless);
};

#endif // __ENEMY_LAYER_H__
