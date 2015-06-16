//
//  hourHand.h
//  HelloWorldDemo
//
//  Created by sll on 15/3/3.
//
//

#ifndef __HelloWorldDemo__hourHand__
#define __HelloWorldDemo__hourHand__
#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class hourHand:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(hourHand);
    Sprite *getSprite();
    void bindSprite(Sprite *sprite);
private:
    Sprite *m_sprite;
};
#endif /* defined(__HelloWorldDemo__hourHand__) */
