//
//  CardSprite.cpp
//  2048Demo
//
//  Created by sll on 15/3/3.
//
//

#include "CardSprite.h"
CardSprite *CardSprite::createCardSprite(int nums, int wid, int hei, float pointx, float pointy)
{
    CardSprite *enemy = new CardSprite();
    if (enemy&&enemy->init()) {
        enemy->autorelease();
        enemy->enemyInit(nums, wid, hei, pointx, pointy);
        return enemy;
    }
    CC_SAFE_DELETE(enemy);
    return NULL;
}
bool CardSprite::init()
{
    if (!Sprite::init()) {
        return false;
    }
    return true;
}
void CardSprite::enemyInit(int nums, int wid, int hei, float pointx, float pointy)
{
    number = nums;
    
    layerColorBg = LayerColor::create(Color4B(200, 190, 180, 255), wid, hei);
    layerColorBg->setPosition(Point(pointx,pointy));
    if (number>0) {
        labelTTFNumber = LabelTTF::create(String::createWithFormat("%i",nums)->getCString(), "宋体", 100);
        labelTTFNumber->setPosition(Point(layerColorBg->getContentSize().width/2,layerColorBg->getContentSize().height/2));
        labelTTFNumber->setTag(8);
        layerColorBg->addChild(labelTTFNumber);
    }
    else
    {
        labelTTFNumber = LabelTTF::create("", "宋体", 100);
        labelTTFNumber->setPosition(Point(layerColorBg->getContentSize().width/2,layerColorBg->getContentSize().height/2));
        labelTTFNumber->setTag(8);
        layerColorBg->addChild(labelTTFNumber);
    }
    this->addChild(layerColorBg);
}
int CardSprite::getNumber()
{
    return number;
}
void CardSprite::setNumber(int nums)
{
    number = nums;
    if (nums>=0) {
        labelTTFNumber->setFontSize(100);
    }
    if (nums>=16) {
        labelTTFNumber->setFontSize(80);
    }
    if (nums>=128) {
        labelTTFNumber->setFontSize(60);
    }
    if (nums>=1024) {
        labelTTFNumber->setFontSize(40);
    }
    if (number>0) {
        labelTTFNumber->setString(String::createWithFormat("%i",number)->getCString());
    }
    else{
        labelTTFNumber->setString("");
    }
    
    switch (nums) {
        case 0:
            layerColorBg->setColor(Color3B(200, 190, 180));
            break;
        case 2:
            layerColorBg->setColor(Color3B(200, 170, 220));
            break;
        case 4:
            layerColorBg->setColor(Color3B(200, 150, 200));
            break;
        case 8:
            layerColorBg->setColor(Color3B(200, 140, 180));
            break;
        case 16:
            layerColorBg->setColor(Color3B(200, 130, 120));
            break;
        case 32:
            layerColorBg->setColor(Color3B(200, 120, 60));
            break;
        case 64:
            layerColorBg->setColor(Color3B(200, 110, 30));
            break;
        case 128:
            layerColorBg->setColor(Color3B(200, 90, 50));
            break;
        case 256:
            layerColorBg->setColor(Color3B(200, 70, 80));
            break;
        case 512:
            layerColorBg->setColor(Color3B(200, 50, 90));
            break;
        case 1024:
            layerColorBg->setColor(Color3B(200, 30, 180));
            break;
        default:
            break;
    }
}