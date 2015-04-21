#include "EnemyLayer.h"
#include "PlaneLayer.h"
#include "GameScene.h"
#include "ResultScene.h"

USING_NS_CC;

EnemyLayer::EnemyLayer():
		_visibleSize(Director::getInstance()->getVisibleSize()), baseEnemyAppearProbability(
				UserDefault::getInstance()->getFloatForKey(
						"probabilityOfBaseEnemyAppear")), deltaEnemyAppearProbability(
				UserDefault::getInstance()->getFloatForKey(
						"probabilityOfDeltaEnemyAppear")), nowEnemyAppearProbability(
				baseEnemyAppearProbability), _pickup(nullptr), _star(nullptr), _comet(nullptr), _boom(nullptr){

}

EnemyLayer::~EnemyLayer() {

}

void EnemyLayer::createEnemyParticles() {
	_boom = ParticleSystemQuad::create("boom.plist");
	_boom->stopSystem();
	this->addChild(_boom, kForeground);

	_comet = ParticleSystemQuad::create("comet.plist");
	_comet->stopSystem();
	_comet->setPosition(Vec2(0, _visibleSize.height * 0.6f));
	_comet->setVisible(false);
	this->addChild(_comet, kForeground);

	_pickup = ParticleSystemQuad::create("plink.plist");
	_pickup->stopSystem();
	this->addChild(_pickup, kMiddleground);
	// Particle system for the star
	_star = ParticleSystemQuad::create("star.plist");
	_star->stopSystem();
	_star->setVisible(false);
	this->addChild(_star, kBackground);
}

bool EnemyLayer::init() {
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->createEnemyParticles();

	// setup enemies' texture name.
	std::string name1 = "enemy1.png";
	std::string name2 = "enemy2.png";
	std::string name3 = "enemy3.png";
	enemyTextureName.push_back(name1);
	enemyTextureName.push_back(name2);
	enemyTextureName.push_back(name3);

	// setup enemies' fly time
	enemyFlyTime.push_back(
			UserDefault::getInstance()->getIntegerForKey("FlytimeOfEnemy1"));
	enemyFlyTime.push_back(
			UserDefault::getInstance()->getIntegerForKey("FlytimeOfEnemy2"));
	enemyFlyTime.push_back(
			UserDefault::getInstance()->getIntegerForKey("FlytimeOfEnemy3"));

	startAddEnemy();

	scheduleUpdate();

	return true;
}

void EnemyLayer::addEnemySprite(float useless) {
	float experimentProbability = rand_0_1();
	if (experimentProbability < nowEnemyAppearProbability) {
		int randomEnemyLevel = cocos2d::rand_0_1() * 3;
//		cocos2d::log("generated enemy at level %i", randomEnemyLevel);
		Sprite* enemySprite = Sprite::createWithSpriteFrameName(
				enemyTextureName[randomEnemyLevel].c_str());
		int randomX = rand_0_1() * _visibleSize.width;
		// Init position Y beyond screen height
		float positionY = _visibleSize.height
				+ enemySprite->getContentSize().height * 0.5f;

		enemySprite->setPosition(randomX, positionY);

		this->addChild(enemySprite);
		allEnemy.pushBack(enemySprite);

		// Run moving action of enemies
		this->movingEnemy(enemySprite, useless, randomEnemyLevel, randomX);
	}

	nowEnemyAppearProbability += deltaEnemyAppearProbability;

	if (nowEnemyAppearProbability > 1) {
		this->stopAddEnemy();
	}
}

void EnemyLayer::movingEnemy(Sprite* enemy, float time, float randomLevel,
		float randomPositionX) {
	FiniteTimeAction* enemyMove = MoveTo::create(enemyFlyTime[randomLevel],
			Vec2(randomPositionX, -enemy->getContentSize().height * 0.5f));

	FiniteTimeAction* enemyRemove = CallFuncN::create(
			CC_CALLBACK_1(EnemyLayer::enemyMoveFinished, this));

	Action* enemyAction = Sequence::create(enemyMove, enemyRemove, NULL);

	enemy->runAction(enemyAction);

}

void EnemyLayer::startAddEnemy() {
	this->schedule(schedule_selector(EnemyLayer::addEnemySprite),
			UserDefault::getInstance()->getFloatForKey("intervalOfAddEnemy"));
}

void EnemyLayer::stopAddEnemy() {
	this->unschedule(schedule_selector(EnemyLayer::addEnemySprite));
}

void EnemyLayer::enemyMoveFinished(Node* pSender) {
	Sprite* enemy = (Sprite*) pSender;
	allEnemy.eraseObject(enemy);
//	delete static_cast<EnemyUserData*>(enemy->getUserData());
	this->removeChild(enemy, true);
}

void EnemyLayer::update(float dt) {

	//	SteeringOutput steering;
	//	steering.setLinear(Vec2(rand_0_1(),rand_0_1() * 2));
	//	steering.setAngular(rand_0_1());

//	if (allEnemy.empty() == true) {
//			static_cast<GameScene*>(this->getParent())->getEnemyBulletLayer()->bossStopShooting();
//			scheduleOnce(schedule_selector(EnemyLayer::changeSceneCallBack), 1.0f);
//	}
	// traveling all enemies
	for (Sprite* enemy : this->allEnemy) {
		FiniteTimeAction* enemyRemove = CallFuncN::create(
				CC_CALLBACK_1(EnemyLayer::enemyMoveFinished, this));
//		 detect collision with the plane
		if (enemy->getBoundingBox().intersectsRect(
				static_cast<GameScene*>(this->getParent())->getPlaneLayer()->getMyPlane()->getBoundingBox())) {
//			cocos2d::log("enemy %i collision with plane", enemy->_ID);

			enemy->stopAllActions();
//			static_cast<EnemyUserData*>(enemy->getUserData())->setIsDeleting();
			if(!_boom->isActive())
			{
				_boom->resetSystem();
			}
			_boom->setPosition(enemy->getPosition());
			enemy->runAction(Sequence::create(enemyRemove, NULL));
		}
	}
}

void EnemyLayer::changeSceneCallBack(float useless) {
	cocos2d::log("Change scene!");
//	Scene* resultSceneWithAnimation;
//	if((allEnemy.empty() == true) && (this->bossAppeared == true)){
//		resultSceneWithAnimation = TransitionFade::create(TRANSITION_TIME, ResultScene::create(true, static_cast<GameScene*>(this->getParent())->getControlLayer()->getScore()));
//	}else{
//		resultSceneWithAnimation = TransitionFade::create(TRANSITION_TIME, ResultScene::create(false, static_cast<GameScene*>(this->getParent())->getControlLayer()->getScore()));
//	}
//	Director::getInstance()->replaceScene(resultSceneWithAnimation);
}

