#include "HelloWorldScene.h"

USING_NS_CC;



CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
	/*CCLayerColor * layerColor = CCLayerColor::create(ccc4(255, 255, 255, 255));
	scene->addChild(layerColor);*/
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
 //   CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
 //                                       "CloseNormal.png",
 //                                       "CloseSelected.png",
 //                                       this,
 //                                       menu_selector(HelloWorld::menuCloseCallback));
 //   
	//pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
 //                               origin.y + pCloseItem->getContentSize().height/2));

 //    create menu, it's an autorelease object
 //   CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
 //   pMenu->setPosition(CCPointZero);
 //   this->addChild(pMenu, 1);

 //   ///////////////////////////
 //    3. add your codes below...

 //    add a label shows "Hello World"
 //    create and initialize a label
 //   
 //   CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
 //   
 //    position the label on the center of the screen
 //   pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
 //                           origin.y + visibleSize.height - pLabel->getContentSize().height));

 //    add the label as a child to this layer
 //   this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"

	// 

	int i, j;

	animateArr = CCArray::create();
	animateArr->retain();

	G = new Graphm(10);

	// 设置图中的关系
	G->setEdge(0, 1, 1259);
	G->setEdge(0, 3, 1257);
	G->setEdge(1, 3, 1283);
	G->setEdge(1, 4, 696);
	G->setEdge(2, 0, 1249);
	G->setEdge(2, 4, 602);
	G->setEdge(3, 2, 629);
	G->setEdge(4, 2, 602);
	G->setEdge(4, 5, 648);
	G->setEdge(5, 9, 1050);
	G->setEdge(5, 8, 690);
	G->setEdge(6, 5, 835);
	G->setEdge(7, 6, 700);
	G->setEdge(7, 3, 1660);
	G->setEdge(8, 7, 615);
	G->setEdge(8, 4, 1233);
	G->setEdge(9, 1, 1335);
	G->setEdge(9, 8, 1044);

	for (i = 0; i < MAXV; i++)
	{
		G->setEdge(i, i, 0);
	}
	




	// 初始化shortestPath
	for (i = 0; i < MAXV; i++)
	{
		shortestPath[i] = -1;
	}

	// 算出最短路径
	Floyd(G);



    CCSprite* pSprite = CCSprite::create("map.png");
	pSprite->setAnchorPoint(ccp(0, 0.5));

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(0, visibleSize.height/2));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

	// 拉萨
	sp0 = CCSprite::create("position.png");
	sp0->setPosition(ccp(95, 205));
	addChild(sp0, 1);
	sp0->setTag(0);

	CCLabelBMFont *lasa = CCLabelBMFont::create("0", "fonts/boundsTestFont.fnt");
	lasa->setPosition(ccp(101, 240));
	addChild(lasa, 1);

	// 西宁
	sp1 = CCSprite::create("position.png");
	sp1->setPosition(ccp(385, 432));
	addChild(sp1, 1);
	sp1->setTag(1);

	CCLabelBMFont *xining = CCLabelBMFont::create("1", "fonts/boundsTestFont.fnt");
	xining->setPosition(ccp(391, 467));
	addChild(xining, 1);

	// 成都
	sp2 = CCSprite::create("position.png");
	sp2->setPosition(ccp(448, 238));
	addChild(sp2, 1);
	sp2->setTag(2);

	CCLabelBMFont *chengdu = CCLabelBMFont::create("2", "fonts/boundsTestFont.fnt");
	chengdu->setPosition(ccp(454, 273));
	addChild(chengdu, 1);

	// 昆明
	sp3 = CCSprite::create("position.png");
	sp3->setPosition(ccp(411, 65));
	addChild(sp3, 1);
	sp3->setTag(3);

	CCLabelBMFont *kunming = CCLabelBMFont::create("3", "fonts/boundsTestFont.fnt");
	kunming->setPosition(ccp(417, 100));
	addChild(kunming, 1);

	// 西安
	sp4 = CCSprite::create("position.png");
	sp4->setPosition(ccp(581, 354));
	addChild(sp4, 1);
	sp4->setTag(4);

	CCLabelBMFont *xian = CCLabelBMFont::create("4", "fonts/boundsTestFont.fnt");
	xian->setPosition(ccp(587, 389));
	addChild(xian, 1);

	// 武汉
	sp5 = CCSprite::create("position.png");
	sp5->setPosition(ccp(727, 235));
	addChild(sp5, 1);
	sp5->setTag(5);

	CCLabelBMFont *wuhan = CCLabelBMFont::create("5", "fonts/boundsTestFont.fnt");
	wuhan->setPosition(ccp(733, 268));
	addChild(wuhan, 1);

	// 广州
	sp6 = CCSprite::create("position.png");
	sp6->setPosition(ccp(697, 8));
	addChild(sp6, 1);
	sp6->setTag(6);

	CCLabelBMFont *guangzhou = CCLabelBMFont::create("6", "fonts/boundsTestFont.fnt");
	guangzhou->setPosition(ccp(703, 43));
	addChild(guangzhou, 1);

	// 福州
	sp7 = CCSprite::create("position.png");
	sp7->setPosition(ccp(862, 95));
	addChild(sp7, 1);
	sp7->setTag(7);

	CCLabelBMFont *fuzhou = CCLabelBMFont::create("7", "fonts/boundsTestFont.fnt");
	fuzhou->setPosition(ccp(868, 130));
	addChild(fuzhou, 1);

	// 上海
	sp8 = CCSprite::create("position.png");
	sp8->setPosition(ccp(922, 255));
	addChild(sp8, 1);
	sp8->setTag(8);

	CCLabelBMFont *shanghai = CCLabelBMFont::create("8", "fonts/boundsTestFont.fnt");
	shanghai->setPosition(ccp(928, 290));
	addChild(shanghai, 1);

	// 北京
	sp9 = CCSprite::create("position.png");
	sp9->setPosition(ccp(785, 544));
	addChild(sp9, 1);
	sp9->setTag(9);

	CCLabelBMFont *beijing = CCLabelBMFont::create("9", "fonts/boundsTestFont.fnt");
	beijing->setPosition(ccp(791, 579));
	addChild(beijing, 1);

	array = CCArray::create();
	array->retain();
	array->addObject(sp0);
	array->addObject(sp1);
	array->addObject(sp2);
	array->addObject(sp3);
	array->addObject(sp4);
	array->addObject(sp5);
	array->addObject(sp6);
	array->addObject(sp7);
	array->addObject(sp8);
	array->addObject(sp9);

	CCLabelTTF *originText = CCLabelTTF::create("Start position", "微软雅黑", 20);
	originText->setPosition(ccp(visibleSize.width * 0.92, visibleSize.height * 0.9));
	originText->setColor(ccc3(255, 255, 255));
	addChild(originText, 1);

	start = CCSprite::create("origin.png");
	start->setPosition(ccp(visibleSize.width * 0.92, visibleSize.height * 0.85));
	addChild(start);
	origPos1 = start->getPosition();

	CCLabelTTF *terminalText = CCLabelTTF::create("Ternimal position", "微软雅黑", 20);
	terminalText->setPosition(ccp(visibleSize.width * 0.92, visibleSize.height * 0.7));
	terminalText->setColor(ccc3(255, 255, 255));
	addChild(terminalText, 1);

	end = CCSprite::create("terminal.png");
	end->setPosition(ccp(visibleSize.width * 0.92, visibleSize.height * 0.65));
	addChild(end);
	origPos2 = end->getPosition();

	pathLabel = CCLabelTTF::create("", "微软雅黑", 10);
	pathLabel->setPosition(ccp(visibleSize.width * 0.92, visibleSize.height * 0.5));
	addChild(pathLabel, 1);

	setTouchEnabled(true);

	runPath = CCSprite::create("SpinningPeas.png");
	runPath->setPosition(ccp(-100, -100));
	addChild(runPath, 1);

	/*test = CCSprite::create("Icon.png");
	test->setPosition(ccp(500, 500));
	addChild(test, 1);
	test->setVisible(false);
*/
    
    return true;
}


bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}
void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint pos = pTouch->getLocation();
	// 判断是否点击在起点或者终点上，以及具体点击在那个精灵上
	if (start->boundingBox().containsPoint(pos))
	{
		flag = true;
		CCPoint prePos = pTouch->getPreviousLocation();
		CCPoint offsetPos = ccpSub(pos, prePos);
		start->setPosition(ccpAdd(pos, offsetPos));
	}
	else if (end->boundingBox().containsPoint(pos))
	{
		flag = false;
		CCPoint prePos = pTouch->getPreviousLocation();
		CCPoint offsetPos = ccpSub(pos, prePos);
		end->setPosition(ccpAdd(pos, offsetPos));
	}
	
}
void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint pos = pTouch->getLocation();
	CCObject *obj = NULL;
	CCAction *moveTo;
	if (flag)
	{
		// 遍历是否与每个框有接触
		CCARRAY_FOREACH(array, obj)
		{
			CCSprite *box = (CCSprite *)obj;
			if (box->boundingBox().containsPoint(start->getPosition()))
			{
				moveTo = CCMoveTo::create(0.2f, box->getPosition());
				startOK = true;
				originID = box->getTag();
				break;
			}
			else
			{
				moveTo = CCMoveTo::create(0.2f, origPos1);
				originID = -1;
				startOK = false;
				/*test->setVisible(false);*/
			}

		}
		start->runAction(moveTo);
	}
	else
	{
		CCARRAY_FOREACH(array, obj)
		{
			CCSprite *box = (CCSprite *)obj;
			if (box->boundingBox().containsPoint(end->getPosition()))
			{
				moveTo = CCMoveTo::create(0.2f, box->getPosition());
				endOK = true;
				terminalID = box->getTag();
				break;
			}
			else
			{
				moveTo = CCMoveTo::create(0.2f, origPos2);
				terminalID = -1;
				endOK = false;
				/*test->setVisible(false);*/
			}
		}
		end->runAction(moveTo);
	}
	
	if (startOK && endOK && (originID != -1) && (terminalID != -1))
	{
		p = 1;
		getPath();
		// 输出路径
		int q = 0;
		char spath[50] = {0};
		char ch[10];
		while (shortestPath[q] != -1)
		{
			sprintf(ch, "%d", shortestPath[q]);
			strcat(spath, ch);
			strcat(spath, "   ");
			q++;
		}
		
		pathLabel->setString(spath);
		animateArr->removeAllObjects();
		showAnimate();
		// showPath();
	}
}

void HelloWorld::setTouchEnabled(bool flag)
{

	if (m_bTouchEnabled != flag)
	{
		m_bTouchEnabled = flag;
		if (flag)
		{
			CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
		}
		else
		{
			CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
		}
	}
	
}
void HelloWorld::getPath()
{
	//// 输出路径
	//test->setVisible(true);

	// 最短距离
	if (D[originID][terminalID] == NOPATH)
	{
		/*cout << "无法从" + origin + "到达" + terminal;*/
	}
	else
	{
		/*cout << "从" + origin + "到" + terminal + "的最短距离为：";
		cout << D[originID][terminalID] << endl;

		cout << "从" + origin + "到" + terminal + "的最短路径为：";*/

		// 初始化shortestPath
		for (int i = 0; i < MAXV; i++)
		{
			shortestPath[i] = -1;
		}

		getShortestPath(originID, terminalID);
		shortestPath[0] = originID;

		int q = 0;
		while (shortestPath[q] != -1)
		{
			cout << shortestPath[q];
			cout << "  ";
			q++;
		}
	}
}

void HelloWorld::Floyd(Graphm *G)
{
	int i, j, k, n = G->n();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			D[i][j] = G->weight(i, j);
			path[i][j] = -1;
		}
	}

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j<n; j++)
			{
				if (D[i][j]>(D[i][k] + D[k][j]))
				{
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
void HelloWorld::getShortestPath(int v1, int v2)
{
	// 中间必须要经过的城市
	int mid = path[v1][v2];

	// mid=-1 说明可以直达
	if (mid == -1)
	{
		shortestPath[p] = v2;
		p++;
	}
	else
	{
		getShortestPath(v1, mid);
		getShortestPath(mid, v2);
	}
}

void HelloWorld::showAnimate()
{
	CCSprite * sp = (CCSprite *)this->getChildByTag(shortestPath[0]);
	CCSprite *sp1;
	runPath->setPosition(sp->getPosition());

	int q = 1;
	while (shortestPath[q] != -1)
	{
		
		sp1 = (CCSprite *)this->getChildByTag(shortestPath[q]);
		CCMoveTo *moveTo = CCMoveTo::create(1.0f, sp1->getPosition());
		animateArr->addObject(moveTo);
		q++;
	}

	CCActionInstant * func = CCCallFunc::create(this, callfunc_selector(HelloWorld::hideSprite));
	animateArr->addObject(func);
	
	runPath->runAction(CCSequence::create(animateArr));

}

void HelloWorld::hideSprite()
{
	runPath->setPosition(ccp(-100, -100));
}



void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
