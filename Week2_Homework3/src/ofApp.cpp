#include "ofApp.h"
#include "ball.hpp"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
  
    for(int i =0; i<NBALLS;i++){
        
        groupOfBalls[i].setup(x, y, z);
        
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i =0; i<NBALLS;i++){
        
        groupOfBalls[i].update();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofNoFill();
    for(int i =0; i<NBALLS;i++){
        
        groupOfBalls[i].draw();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
