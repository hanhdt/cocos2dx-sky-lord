#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"
#include "Definitions.h"
#include <string>
#include <vector>

USING_NS_CC;



struct SteeringOutput{
	Vec2 linear;
	float angular;

	SteeringOutput(): linear(Vec2::ZERO), angular(0.0f){}
	Vec2 getLinear()
	{
		return linear;
	}
	void setLinear(Vec2 iLinear){ linear = iLinear;}
	float getAngular(){ return angular; }
	void setAngular(float iAngular){ angular = iAngular;}
};

struct KinematicSteeringOutput{
	Vec2 velocity;
	float rotation;
};

struct Kinematic{
	Vec2 position;
	float orientation;
	Vec2 velocity;
	float rotation;

	Kinematic(): position(Vec2::ZERO),
			orientation(0.0f), velocity(Vec2::ZERO), rotation(0.0f){}

	void update(SteeringOutput steering, float time)
	{
		position.x += velocity.x * time;
		position.y += velocity.y * time;
		orientation += rotation * time;

		velocity.x += steering.linear.x * time;
		orientation += steering.angular * time;
	}

	Vec2 getPosition(){ return position; }
	void setPosition(Vec2 iPosition) { position = iPosition;}
};
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
	ParticleSystem * _boom;
	ParticleSystem * _comet;
	ParticleSystem * _pickup;
	ParticleSystem * _star;

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
