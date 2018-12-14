//
//  Ball.cpp
//  week7_Homework
//
//  Created by 陈启钊 on 16/10/2018.
//
//

#include "Ball.hpp"
Ball::Ball(){
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    
}

void Ball::setup(ofPoint pos_){
    pos = pos_;
    vel.set(ofRandom(-.2,.2), ofRandom(-.2,.2), ofRandom(0,.2));
    startPos = pos_;
    goToStart = false;
}

void Ball::update(){
    if(goToStart){
        pos = pos + vel;
        vel = vel + acc;
    }
 
}

void Ball::draw(){
    float h;
    
    
    
    h = 1;
    
    ofDrawSphere(pos.x, pos.y, pos.z, h);
}

void Ball::addForce(ofPoint force){
    acc -= force;
}

