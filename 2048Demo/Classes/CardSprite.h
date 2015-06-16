//
//  CardSprite.h
//  2048Demo
//
//  Created by sll on 15/3/3.
//
//

#ifndef ___048Demo__CardSprite__
#define ___048Demo__CardSprite__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class CardSprite:public cocos2d::Sprite
{
public:
    static CardSprite*createCardSprite(int num,int width,int height,float px,float py);
    virtual bool init();
    CREATE_FUNC(CardSprite);
    
    //获取数字
    int getNumber();
    //设置数字
    void setNumber(int num);
private:
    //数字
    int number;
    void enemyInit(int num,int width,int height,float px,float py);
    cocos2d::LabelTTF *labelTTFNumber;
    
    cocos2d::LayerColor *layerColorBg;
};
#endif /* defined(___048Demo__CardSprite__) */
