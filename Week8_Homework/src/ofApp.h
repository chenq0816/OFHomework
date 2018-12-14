#pragma once

#include "ofMain.h"

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
    
    ofSoundPlayer sound1;
        ofSoundPlayer sound2;
        ofSoundPlayer sound3;
    
    ofPoint vel;
    ofPoint acc;
    ofPoint pos;
    ofPoint force;
    ofPoint color;
    
    vector<ofPoint> ballPos;
    vector<ofPoint> ballAcc;
    vector<ofPoint> ballVel;
    vector<ofPoint> ballForce;
     vector<ofPoint> ballColor;
    
    int count;
    float diffx;
    float diffy;
    
    
};
