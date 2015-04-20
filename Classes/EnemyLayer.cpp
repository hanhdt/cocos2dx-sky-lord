#include "EnemyLayer.h"

USING_NS_CC;

EnemyLayer::EnemyLayer():
		_visibleSize(Director::getInstance()->getVisibleSize()),
		baseEnemyAppearProbability(UserDefault::getInstance()->getFloatForKey("probabilityOfBaseEnemyAppear")),
		deltaEnemyAppearProbability(UserDefault::getInstance()->getFloatForKey("probabilityOfDeltaEnemyAppear")),
		nowEnemyAppearProbability(baseEnemyAppearProbability){

}

EnemyLayer::~EnemyLayer()
{

}

void EnemyLayer::createPlaneParticles() {

}

bool EnemyLayer::init() {
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->createPlaneParticles();

	// setup enemies' texture name.
	std::string name1 = "enemy1.png";
	std::string name2 = "enemy2.png";
	std::string name3 = "enemy3.png";
	enemyTextureName.push_back(name1);
	enemyTextureName.push_back(name2);
	enemyTextureName.push_back(name3);

	// setup enemies' fly time
	enemyFlyTime.push_back(UserDefault::getInstance()->getIntegerForKey("FlytimeOfEnemy1"));
	enemyFlyTime.push_back(UserDefault::getInstance()->getIntegerForKey("FlytimeOfEnemy2"));
	enemyFlyTime.push_back(UserDefault::getInstance()->getIntegerForKey("FlytimeOfEnemy3"));

	startAddEnemy();

	scheduleUpdate();

	return true;
}

void EnemyLayer::addEnemySprite(float useless)
{
	float experimentProbability = rand_0_1();
	if(experimentProbability < nowEnemyAppearProbability)
	{
		int randomEnemyLevel = cocos2d::rand_0_1() * 3;
//		cocos2d::log("generated enemy at level %i", randomEnemyLevel);
		Sprite* enemySprite = Sprite::createWithSpriteFrameName(enemyTextureName[randomEnemyLevel].c_str());
		int randomX = rand_0_1() * _visibleSize.width;
		// Init position Y beyond screen height
		float positionY = _visibleSize.height + enemySprite->getContentSize().height * 0.5f;
		enemySprite->setPosition(randomX, positionY);
		this->addChild(enemySprite);
		allEnemy.pushBack(enemySprite);

		// Run moving action of enemies
		this->movingEnemy(enemySprite, useless, randomEnemyLevel, randomX);
	}
	nowEnemyAppearProbability += deltaEnemyAppearProbability;
	if(nowEnemyAppearProbability > 1)
	{
		this->stopAddEnemy();
	}
}

void EnemyLayer::movingEnemy(Sprite* enemy, float time, float randomLevel, float randomPositionX)
{
	FiniteTimeAction* enemyMove = MoveTo::create(enemyFlyTime[randomLevel], Vec2(randomPositionX, - enemy->getContentSize().height * 0.5f));
	FiniteTimeAction* enemyRemove = CallFuncN::create(CC_CALLBACK_1(EnemyLayer::enemyMoveFinished, this));
	Action* enemyAction = Sequence::create(enemyMove, enemyRemove, NULL);
	enemy->runAction(enemyAction);
}

void EnemyLayer::startAddEnemy()
{
	this->schedule(schedule_selector(EnemyLayer::addEnemySprite), UserDefault::getInstance()->getFloatForKey("intervalOfAddEnemy"));
}

void EnemyLayer::stopAddEnemy()
{
	this->unschedule(schedule_selector(EnemyLayer::addEnemySprite));
}

void EnemyLayer::enemyMoveFinished(Node* pSender) {
	Sprite* enemy = (Sprite*) pSender;
	allEnemy.eraseObject(enemy);
//	delete static_cast<EnemyUserData*>(enemy->getUserData());
	this->removeChild(enemy, true);
}

void EnemyLayer::update(float dt) {

}
