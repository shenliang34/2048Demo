//
//  TouchSpriteScene.cpp
//  2048Demo
//
//  Created by sll on 15/3/3.
//
//

#include "TouchSpriteScene.h"
#include "CardSprite.h"
#include "cocos2d.h"
#include <iostream>
#include <math.h>
using namespace std;
USING_NS_CC;
Scene* TouchSpriteScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchSpriteScene::create();
    scene->addChild(layer);
    return  scene;
}
bool TouchSpriteScene::init(){
    if(!Layer::init())
    {
        return false;
    }
    float f=0.5;
//    log("%d",f);
    //注册点击事件
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan= CC_CALLBACK_2(TouchSpriteScene::onTouchBegan, this);
    touchListener->onTouchEnded= CC_CALLBACK_2(TouchSpriteScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
    
    Size size = Director::getInstance()->getWinSize();
    createCardSprite(size);
    log("%i%i",size.width,size.height);
    return true;
}
void TouchSpriteScene::autoCreateCard()
{
//    int i = CCRANDOM_0_1()*4;
//    int j = CCRANDOM_0_1()*4;
//    
//    if (cardArray[i][j]->getNumber()<=0) {
//        cardArray[i][j]->setNumber(CCRANDOM_0_1()*10<2?4:2);
//    }
//    else
//    {
//        autoCreateCard();
//    }
    
//    CardSprite *autoCardArr=new CardSprite[0];
    //清除数组
    Vector <CardSprite*> vec;
//    vec.clear();
    int index = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            //所在位置为空
            if (cardArray[i][j]->getNumber()<=0) {
                index++;
                log("%s%d","扔进数组",vec.size());
                vec.pushBack(cardArray[i][j]);
                //扔进数组
            }
        }
    }
    log("%s%i","个数",index);
    index=0;
    //数组内是否有空位置
    log("%d",vec.size());
    if (vec.size()>0) {
        //数组内有空位置随机选一个
        index = CCRANDOM_0_1()*vec.size();
        vec.at(index)->setNumber(CCRANDOM_0_1()*10<2?4:2);
    }
    else
    {
        log("没有位置");
    }
    checkGameOver();
}
void TouchSpriteScene::checkGameOver()
{
    bool isGameOver = true;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (cardArray[i][j]->getNumber()==0||
                (i>=0&&i<3&&cardArray[i][j]->getNumber() == cardArray[i+1][j]->getNumber())||
//                (i<3&&cardArray[i][j]->getNumber() == cardArray[i+1][j]->getNumber())||
                (j>=0&&j<3&&cardArray[i][j]->getNumber() == cardArray[i][j+1]->getNumber())
//                (i<3&&cardArray[i][j]->getNumber() == cardArray[i][j+1]->getNumber()
                ) {
                isGameOver = false;
            }
        }
    }
    if (isGameOver) {
        log("Game over");
        Director::getInstance()->replaceScene(TransitionFade::create(1, TouchSpriteScene::createScene()));
    }
}
void TouchSpriteScene::createCardSprite(Size size)
{
    int unitSize = (size.height-150)/4;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            CardSprite *card = CardSprite::createCardSprite(2, unitSize, unitSize, (unitSize+5)*i+230, (unitSize+5)*j+5);
            this->addChild(card);
            cardArray[i][j]=card;
        }
    }
    auto scoreTTF = LabelTTF::create(String::createWithFormat("%s","Score")->getCString(), "宋体", 50);
    scoreTTF->setPosition(size.width-100, size.height-300);
    this->addChild(scoreTTF);
//    cocos2d::LabelTTF *labelTTFNumber;
    lableTTFScore = LabelTTF::create(String::createWithFormat("%i",score)->getCString(), "宋体", 50);
    lableTTFScore->setPosition(size.width-100, size.height-400);
    this->addChild(lableTTFScore);
//    lableTTFScore = LabelTTF::create(String::createWithFormat("%s","SCORE"), "宋体", 50);
}
//点击开始
bool TouchSpriteScene::onTouchBegan(Touch *touch,Event *event )
{
    Point touchPoint = touch->getLocation();
//    touch->getLocationInView();
    firstX = touchPoint.x;
    firstY = touchPoint.y;
    return true;
}
//鼠标抬起
void TouchSpriteScene::onTouchEnded(Touch *touch, Event *event)
{
    Point touchpoint = touch->getLocation();
    endX = firstX - touchpoint.x;
    endY = firstY - touchpoint.y;
    
    bool isdo = false;
    int distance = 20;
    if (abs(endX)>abs(endY)) {
        if (endX>distance) {
            isdo = doLeft();
        }
        else if(endX<-distance)
        {
            isdo=doRight();
        }
    }
    else if(abs(endX)<abs(endY)){
        if (endY>distance) {
            isdo=doDown();
        }
        else if(endY<-distance)
        {
            isdo=doUp();
        }
    }
    //判断是否已满
    int emptySize = 0;
    for (int i=0; i<4;i++) {
        for (int j=0; j<4; j++) {
            if (cardArray[i][j]->getNumber()<=0) {
                emptySize++;
            }
        }
    }
    if (emptySize>0) {
        if (isdo) {
            autoCreateCard();
        }
    }
    else
    {
        checkGameOver();
    }
    
}
bool TouchSpriteScene::doUp(){
    log("up");
    bool isdo = false;
    for (int x=0; x<4; x++) {
        for (int y=3; y>=0; y--) {
        
            for (int y1=y-1; y1>=0; y1--) {
                if (cardArray[x][y1]->getNumber()>0) {
                    if (cardArray[x][y]->getNumber()<=0) {
                        cardArray[x][y]->setNumber(cardArray[x][y1]->getNumber());
                        cardArray[x][y1]->setNumber(0);
                        y++;
                        isdo = true;
                    }
                    else if(cardArray[x][y]->getNumber()==cardArray[x][y1]->getNumber())
                    {
                        cardArray[x][y]->setNumber(cardArray[x][y]->getNumber()*2);
                        cardArray[x][y1]->setNumber(0);
                        score+=cardArray[x][y]->getNumber();
                        lableTTFScore->setString(String::createWithFormat("%i",score)->getCString());
                        isdo = true;
                    }
                    break;
                }
            }
        }
    }
    return isdo;
}
bool TouchSpriteScene::doDown(){
    log("down");
    bool isdo = false;
    for (int x=0; x<4; x++) {
        for (int y=0; y<4; y++) {
            
            for (int y1=y+1; y1<4; y1++) {
                if (cardArray[x][y1]->getNumber()>0) {
                    if (cardArray[x][y]->getNumber()<=0) {
                        cardArray[x][y]->setNumber(cardArray[x][y1]->getNumber());
                        cardArray[x][y1]->setNumber(0);
                        y--;
                        isdo = true;
                    }
                    else if(cardArray[x][y]->getNumber()==cardArray[x][y1]->getNumber())
                    {
                        cardArray[x][y]->setNumber(cardArray[x][y]->getNumber()*2);
                        cardArray[x][y1]->setNumber(0);
                        score+=cardArray[x][y]->getNumber();
                        lableTTFScore->setString(String::createWithFormat("%i",score)->getCString());
                        isdo = true;
                    }
                    break;
                }
            }
        }
    }
    return isdo;
}
bool TouchSpriteScene::doRight(){
    log("right");
    bool isdo = false;
    for (int y=0; y<4; y++) {
        for (int x=3; x>=0; x--) {
            for (int x1=x-1; x1>=0; x1--) {
                if (cardArray[x1][y]->getNumber()>0) {
                    if (cardArray[x][y]->getNumber()<=0) {
                        cardArray[x][y]->setNumber(cardArray[x1][y]->getNumber());
                        cardArray[x1][y]->setNumber(0);
                        x++;
                        isdo = true;
                    }
                    else if(cardArray[x][y]->getNumber()==cardArray[x1][y]->getNumber())
                    {
                        cardArray[x][y]->setNumber(cardArray[x][y]->getNumber()*2);
                        cardArray[x1][y]->setNumber(0);
                        score+=cardArray[x][y]->getNumber();
                        lableTTFScore->setString(String::createWithFormat("%i",score)->getCString());
                        isdo = true;
                    }
                    break;
                }
               
            }
        }
    }
    return isdo;
}
bool TouchSpriteScene::doLeft(){
    log("left");
    bool isdo = false;
    for (int y=0; y<4; y++) {
        for (int x=0; x<4; x++) {
            for (int x1=x+1; x1<4; x1++) {
                if (cardArray[x1][y]->getNumber()>0) {
                    if (cardArray[x][y]->getNumber()<=0) {
                        cardArray[x][y]->setNumber(cardArray[x1][y]->getNumber());
                        cardArray[x1][y]->setNumber(0);
                        x--;
                        isdo = true;
                    }
                    else if(cardArray[x][y]->getNumber()==cardArray[x1][y]->getNumber())
                    {
                        cardArray[x][y]->setNumber(cardArray[x][y]->getNumber()*2);
                        cardArray[x1][y]->setNumber(0);
                        
                        score+=cardArray[x][y]->getNumber();
                        lableTTFScore->setString(String::createWithFormat("%i",score)->getCString());
                        isdo = true;
                    }
                    break;

                }
            }
        }
    }
    return isdo;
}