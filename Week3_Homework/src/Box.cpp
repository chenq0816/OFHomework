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
    vel.set(ofRandom(-1,1), ofRandom(-1,1),0);
    
    
}

void Box::update(){

    pos += vel;
    vel += acc;
     acc *= 0.0;
    
    
}



void Box::draw(){
    
    float h;
    

//    h = ofRandom(5,9) * (sin(ofGetElapsedTimef()) + 1.2);
    h = 2;
    
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
