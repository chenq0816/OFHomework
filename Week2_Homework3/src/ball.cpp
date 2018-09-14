//
//  ball.cpp
//  Week2_Homework3
//
//  Created by 陈启钊 on 13/09/2018.
//
//

#include "ball.hpp"


ball::ball(){
    
}

void ball::setup(float _x,float _y,float _z){
    pct = 0;
    
    x= _x;
    y= _y;
    z= _z;
    
    x = ofRandom(0,ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    z = ofRandom(1,3);
    
    
    
//    speedX = ofRandom(0,1);
//     speedY = ofRandom(0,1);
    
}

void ball::update(){
    
    if(pct<1){
        pct = pct + ofRandom(0,0.00005);
            ofLog() << pct;
    
    
    
        x = (1-pct)*x + pct * ofGetMouseX();
        y = (1-pct)*y + pct * ofGetMouseY();
    }


//    x = x+speedX;
//    y = y + speedY;
//    pct = ofRandom(0,1);
    
}

void ball::draw(){
    ofDrawCircle(x, y, z);
}


