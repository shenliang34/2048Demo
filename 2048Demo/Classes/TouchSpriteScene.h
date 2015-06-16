//
//  TouchSpriteScene.h
//  2048Demo
//
//  Created by sll on 15/3/3.
//
//

#ifndef ___048Demo__TouchSpriteScene__
#define ___048Demo__TouchSpriteScene__

#include <stdio.h>
#include "cocos2d.h"
#include "CardSprite.h"
//#include <vect>
USING_NS_CC;
class TouchSpriteScene:public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TouchSpriteScene);
    
    virtual bool onTouchBegan(cocos2d::Touch *touch,cocos2d::Event*unEvent);
    virtual void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event*unEvent);
    
    bool doUp();
    bool doDown();
    bool doLeft();
    bool doRight();
    
    void autoCreateCard();
    void createCardSprite(Size size);
    void checkGameOver();
private:
    int firstX,firstY,endX,endY;
    int score;
    
    cocos2d::LabelTTF *lableTTFScore;
//    cocos2d::LabelTTF *lableTTFScore;
    
    CardSprite *cardArray[4][4];
    
};
#endif /* defined(___048Demo__TouchSpriteScene__) */
