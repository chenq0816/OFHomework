//
//  Box.hpp
//  Week3_Homework
//
//  Created by 陈启钊 on 18/09/2018.
//
//

#ifndef Box_hpp
#define Box_hpp

#include "ofMain.h"


class Box{
    
    
public:
    
    
    void setup(ofPoint _pos);
    void update();
    void draw();

    
    void addForce(ofPoint force_);
    void addAttractionForce(ofPoint attraction_,float _rad, float scale);
    Box();
    
    ofPoint vel;
    ofPoint acc;
    ofPoint pos;
    
     ofPoint noiseRandomOffset;
    
    ofPoint startPos;
    bool goToStart;
    
    
private:
};

#endif /* Box_hpp */


