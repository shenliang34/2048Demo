//
//  minuteHand.cpp
//  HelloWorldDemo
//
//  Created by sll on 15/3/3.
//
//

#include "minuteHand.h"
Sprite *minuteHand::getSprite(){
    return this->m_sprite;
}
void minuteHand::bindSprite(Sprite *sprite){
    m_sprite = sprite;
    m_sprite->setAnchorPoint(Vec2(0, 0.5));
    m_sprite->setScale(0.2f);
    m_sprite->setRotation(-90);
    this->addChild(m_sprite);
}
bool minuteHand::init(){
    return true;
}