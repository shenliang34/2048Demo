//
//  minuteHand.h
//  HelloWorldDemo
//
//  Created by sll on 15/3/3.
//
//

#ifndef __HelloWorldDemo__minuteHand__
#define __HelloWorldDemo__minuteHand__

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class minuteHand:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(minuteHand);
    Sprite *getSprite();
    void bindSprite(Sprite *sprite);
private:
    Sprite *m_sprite;
};
#endif /* defined(__HelloWorldDemo__minuteHand__) */
