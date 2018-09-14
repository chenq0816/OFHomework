//
//  ball.hpp
//  Week2_Homework3
//
//  Created by 陈启钊 on 13/09/2018.
//
//

#ifndef ball_hpp
#define ball_hpp

#include "ofMain.h"

class ball{
public:
    void setup(float _x, float _y, float _z);
    void update();
    void draw();
    
    ball();
    float x;
    float y;
    float z;
    
    float speedX;
    float speedY;
    
    float pct;
    
    
private:
    
};
#endif /* ball_hpp */
