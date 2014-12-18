#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "stdafx.h"

using namespace cocos2d;
using namespace std;

#define MAXV 10
#define NOPATH -1
#define BIGGER_THAN_BIGGER 10000


class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	// µ¥µã´¥Ãþ
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	virtual void setTouchEnabled(bool flag);

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	void getPath();

	void showAnimate();

	void hideSprite();

	CCSprite *sp0;
	CCSprite *sp1;
	CCSprite *sp2;
	CCSprite *sp3;
	CCSprite *sp4;
	CCSprite *sp5;
	CCSprite *sp6;
	CCSprite *sp7;
	CCSprite *sp8;
	CCSprite *sp9;

	CCArray *array;

	CCSprite *start;
	CCSprite *end;

	bool flag = true;

	CCPoint origPos1;
	CCPoint origPos2;

	CCLabelTTF *pathLabel;

	bool startOK = false;
	bool endOK = false;

	int originID = -1;
	int terminalID = -1;

	/*CCSprite *test;*/

	void Floyd(Graphm *G);
	void getShortestPath(int v1, int v2);

	int D[MAXV][MAXV];
	int path[MAXV][MAXV];

	int shortestPath[MAXV];
	int p = 1;

	Graphm *G;

	string postions[MAXV];

	CCArray *animateArr;

	CCSprite *runPath;

    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
