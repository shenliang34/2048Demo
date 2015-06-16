//
//  secondHand.h
//  HelloWorldDemo
//
//  Created by sll on 15/3/3.
//
//

#ifndef __HelloWorldDemo__secondHand__
#define __HelloWorldDemo__secondHand__

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class secondHand:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(secondHand);
    Sprite *getSprite();
    void bindSprite(Sprite *sprite);
private:
    Sprite *m_sprite;
};
#endif /* defined(__HelloWorldDemo__secondHand__) */
