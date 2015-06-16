//
//  clockBackGroundScene.cpp
//  HelloWorldDemo
//
//  Created by sll on 15/3/3.
//
//

#include "clockBackGroundScene.h"
Scene *clockBackGroundScene::scene()
{
    clockBackGroundScene *layer = clockBackGroundScene::create();
    Scene *scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}
bool clockBackGroundScene::init(){
    Size winSize = Director::sharedDirector()->getWinSize();
    Sprite *clockBk = Sprite::create("background.jpg");
    clockBk->setPosition(winSize.width/2,winSize.height/2);
    clockBk->setScale(0.5f);
    this->addChild(clockBk);
    
    //时针
    m_hour = hourHand::create();
    m_hour->bindSprite(Sprite::create("shi.png"));
    m_hour->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(m_hour);
    //分针
    m_minute = minuteHand::create();
    m_minute->bindSprite(Sprite::create("fen.png"));
    m_minute->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(m_minute);
    //秒针
    m_second = secondHand::create();
    m_second->bindSprite(Sprite::create("miao.png"));
    m_second->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(m_second);
    
    //获取当前时间
       MutUpdate(0);
    
    this->scheduleUpdate();//每针都会跳用
    this->schedule(schedule_selector(clockBackGroundScene::MutUpdate), 1.0f,kRepeatForever,0);
    return true;
}
void clockBackGroundScene::MutUpdate(float dt){
    
    struct tm *tm;
    time_t timep;
    time(&timep);
    tm = localtime(&timep);
    int year = tm->tm_year+1900;
    int month = tm->tm_mon+1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;
    int second = tm->tm_sec;
    nMinute = minute;
    nSecond = second;
    nHour = hour;
    std::cout<<"当前时间："<<hour<<":"<<minute<<":"<<second;
    std::cout<<"当前日期："<<year<<"-"<<month<<"-"<<day<<"end";

    
    static int mRotation = nMinute*6;
    static int sRotation = nSecond*6;
    static int hRotation = nHour*6;
//    CCLOG("update");
    if (nHour>12) {
        hRotation = (nHour-12)*5*6+(mRotation/72)*6;
    }
    else{
        hRotation = (nHour)*5*6+(mRotation/72)*6;
    }
    
    m_second->setRotation(sRotation);
    m_minute->setRotation(mRotation);
    m_hour->setRotation(hRotation);
    
    if (sRotation >=360) {
        sRotation = 0;
        mRotation+=6;
        m_minute->setRotation(mRotation);
        if (mRotation%72==0) {
            hRotation +=6;
            m_hour->setRotation(hRotation);
            if (mRotation>=360) {
                mRotation = 0;
            }
        }
        
    }
    sRotation+=6;
    
}