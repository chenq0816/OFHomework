//
//  Creator.hpp
//  Week2_Homework2
//
//  Created by 陈启钊 on 13/09/2018.
//
//

#ifndef Creator_hpp
#define Creator_hpp

#include "ofMain.h"


class Creator{
public:
    void setup(float _x, float _y, int _dim);
    void update();
    void draw();
    
    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int dim;        // size
    ofColor color;
    
    Creator();
private:
    
};

#endif /* Creator_hpp */
