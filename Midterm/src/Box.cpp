//
//  Box.cpp
//  Week3_Homework
//
//  Created by 陈启钊 on 18/09/2018.
//
//

#include "Box.hpp"
Box::Box(){
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    
}

void Box::setup(ofPoint pos_){

    
    pos = pos_;
    vel.set(ofRandom(-.2,.2), ofRandom(-.2,.2),ofRandom(0,.2));
    
    noiseRandomOffset.set(ofRandom(10), ofRandom(10), ofRandom(10));
    
    startPos = pos_;
    goToStart = false;
    
}

void Box::update(){
    
    if(goToStart){
        pos = .9 * pos + .1 *startPos;
        // check distance between pos and startPos, set goToStart to false
        float diff = (pos-startPos).length();
        if(diff < 5){
            goToStart = false;
            
        }
    }else{
        pos += vel;
        vel += acc;
        acc *= 0.0;
    }
    
}





void Box::draw(){
    
    float h;
    


    h = 2.5;
    
    ofDrawBox(pos.x, pos.y, pos.z, h);
    
    
}

void Box::addForce(ofPoint force){
    acc += force;
}

void Box::addAttractionForce(ofPoint _attraction,float _rad, float scale){
    ofPoint diff = _attraction - pos;
    if(diff.length() < _rad){
        addForce(diff*scale);
            }
}
