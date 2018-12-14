#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Box.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofEasyCam cam;
    
    ofxPanel gui;
    ofxFloatSlider Boxsize;
    ofxFloatSlider lsc;
        ofxFloatSlider lsc2;
          ofxFloatSlider lsc3;
//    ofxFloatSlider BallSize;
    
    float x,y;
    float sinValue;
    float cosValue;
    ofPoint pos;
    
    vector <Box> mybox;
//    Box mybox;
    
    ofImage star;
    
    float rotationX;
    float rotationY;
    float rotationZ;
    
//    vector <ofPoint> constellation;
    ofPoint constellation[20];
    
    int star1 = -1;
    int star2 = 1;
    
    float stella1;
    float stella2;
    float stella3;
    
    
};
