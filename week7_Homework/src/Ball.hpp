//
//  Ball.hpp
//  week7_Homework
//
//  Created by 陈启钊 on 16/10/2018.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include "ofMain.h"

class Ball{
    
public:
    
    void setup(ofPoint _pos);
    void update();
    void draw();
    
    void addForce(ofPoint force_);
    
    ofPoint vel;
    ofPoint acc;
    ofPoint pos;
    
    ofPoint startPos;
    bool goToStart;
    
   Ball();
private:
    
};

#endif /* Ball_hpp */
