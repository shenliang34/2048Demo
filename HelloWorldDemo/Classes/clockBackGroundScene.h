//
//  clockBackGroundScene.h
//  HelloWorldDemo
//
//  Created by sll on 15/3/3.
//
//

#ifndef __HelloWorldDemo__clockBackGroundScene__
#define __HelloWorldDemo__clockBackGroundScene__

#include <iostream>
#include "cocos2d.h"
#include "minuteHand.h"
#include "hourHand.h"
#include "secondHand.h"
USING_NS_CC;

class clockBackGroundScene:public Layer
{
public:
    virtual bool init();
    static Scene *scene();
    CREATE_FUNC(clockBackGroundScene)
//    virtual void update(float dt);
    void MutUpdate(float dt);
    
    hourHand *m_hour;
    minuteHand *m_minute;
    secondHand *m_second;
    
    int nHour;
    int nMinute;
    int nSecond;
};
#endif /* defined(__HelloWorldDemo__clockBackGroundScene__) */
