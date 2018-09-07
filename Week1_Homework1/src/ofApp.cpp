#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    startPos = 0;
    endPos = 700;
    pct = 0;
    ofSetBackgroundColor(ofColor::black);
   
}

//--------------------------------------------------------------
void ofApp::update(){
    if(pct<1){
        pct += 0.005;}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
float pct1 = easeOutBounce(pct);
    float cpos1 = (1-pct1) * startPos + pct1 * endPos;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( 100, cpos1,40);
    
    float pct2 = easeOutQuint(pct);
    float cpos2 = (1-pct2) * startPos + pct2 * endPos;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( 300, cpos2, 40);
    
    float pct3 = easeOutQuad(pct);
    float cpos3 = (1-pct3) * startPos + pct3 * endPos;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( 500, cpos3, 40);
    
    float pct4 = easeInOutQuint(pct);
    float cpos4 = (1-pct4) * startPos + pct4 * endPos;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle(700, cpos4, 40);
    
    float pct5 = easeOutCubic(pct);
    float cpos5 = (1-pct5) * startPos + pct5 * endPos;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( 900, cpos5, 40);
    
    
}

//--------------------------------------------------------------
float ofApp::easeOutBounce(float t){
        if ((t /= 1) < (1 / 2.75)) {
            return (7.5625 * t * t);
        } else if (t < (2 / 2.75)) {
            return (7.5625 * (t -= (1.5 / 2.75)) * t + .75);
        } else if (t < (2.5 / 2.75)) {
            return (7.5625 * (t -= (2.25 / 2.75)) * t + .9375);
        } else {
            return (7.5625 * (t -= (2.625 / 2.75)) * t + .984375);
        }

}


float ofApp::easeOutQuint(float t){
    return 1 + (--t) * t * t * t * t;
}

float ofApp::easeOutQuad(float t){
return t * (2 - t);
}

float ofApp::easeInOutQuint(float t){
    return t < .5 ? 16 * t * t * t * t * t : 1 + 16 * (--t) * t * t * t * t;

}

float ofApp::easeOutCubic(float t){
    return (--t) * t * t + 1;
}

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
