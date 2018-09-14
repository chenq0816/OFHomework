//
//  Creator.cpp
//  Week2_Homework2
//
//  Created by 陈启钊 on 13/09/2018.
//
//

#include "Creator.hpp"

Creator::Creator(){
}

//void Creator::setup(){
//    x = ofRandom(0, ofGetWidth());      // give some random positioning
//    y = ofRandom(0, ofGetHeight());
//    
//    speedX = ofRandom(-1, 1);           // and random speed and direction
//    speedY = ofRandom(-1, 1);
//    
//    dim = 20;
//     color.set(ofRandom(255),ofRandom(255),ofRandom(255));
//}
void Creator::setup(float _x, float _y, int _dim){
    x = _x;
    y = _y;
    dim = _dim;
    
    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Creator::update(){
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
}



void Creator::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
}
