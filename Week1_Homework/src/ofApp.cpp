#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofColor::black);
   moveMousex = 0;
       moveMousey = 0;
    movepct = 0.1;
    
    startPos = 0;
    endPos = 700;
    pct = 0;
    for(int i =0; i < 10; i++){
        
        manyPoints.push_back( ofPoint(i*20,i*20));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
 
    if(pct<1){
        pct += 0.001;}
//    for(int i = 0; i < manyPoints.size(); i++){
//        movepct = .05 * (i+1);
//        
//    }
    
   

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetCircleResolution(60);
    moveMousex = (1-movepct) * moveMousex + movepct * mouseX;
    moveMousey = (1-movepct) * moveMousey + movepct * mouseY;
    ofDrawCircle(moveMousex, moveMousey, 40);
    
    float pct1 = easeOutBounce(pct);
    float cpos1 = (1-pct1) * startPos + pct1 * moveMousex;
     float cpos11 = (1-pct1) * startPos + pct1 * moveMousey;
    
  
    float cpos12 = (1-pct1) * 400 + pct1 * moveMousex;
    float cpos112 = (1-pct1) * 200 + pct1 * moveMousey;
    

    float cpos13 = (1-pct1) * 200 + pct1 * moveMousex;
    float cpos113 = (1-pct1) * 500 + pct1 * moveMousey;
    
 
    float cpos14 = (1-pct1) * 700 + pct1 * moveMousex;
    float cpos114 = (1-pct1) * 700 + pct1 * moveMousey;
    

    float cpos15 = (1-pct1) * 100 + pct1 * moveMousex;
    float cpos115 = (1-pct1) * 500 + pct1 * moveMousey;
    
    
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( cpos1, cpos11,100);
     ofDrawCircle( cpos12, cpos112,110);
     ofDrawCircle( cpos13, cpos113,60);
     ofDrawCircle( cpos14, cpos114,120);
     ofDrawCircle( cpos15, cpos115,130);
    
    
//    float pct2 = easeOutBounce(pct);
//    float cpos2 = (1-pct2) * 50 + pct2 * 100;
//    float c1pos2 = (1-pct2) * 40 + pct2 * 200;
//    float c2pos2 = (1-pct2) * 30 + pct2 * 300;
//    float c3pos2 = (1-pct2) * 20 + pct2 * 400;
//    float c4pos2 = (1-pct2) * 10 + pct2 * 500;
//    
//    float cpos21 = (1-pct2) * 800 + pct2 * moveMousey;
//    ofSetColor(255);
//    ofSetCircleResolution(50);
//    ofDrawCircle( 500, 400, cpos2);
//    ofDrawCircle( 500, 400, c1pos2);
//    ofDrawCircle( 500, 400, c2pos2);
//    ofDrawCircle( 500, 400, c3pos2);
//    ofDrawCircle( 500, 400, c4pos2);
    
    float pct2 = easeOutBounce(pct);
    float cpos2 = (1-pct2) * 1000 + pct2 * moveMousex;
     float cpos21 = (1-pct2) * 800 + pct2 * moveMousey;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( cpos2, cpos21, 80);
    
    float pct3 = easeOutBounce(pct);
    float cpos3 = (1-pct3) * 1000 + pct3 * moveMousex;
     float cpos31 = (1-pct3) * 0 + pct3 * moveMousey;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( cpos3, cpos31, 70);
    
    float pct4 = easeOutBounce(pct);
    float cpos4 = (1-pct4) * 0 + pct4 * moveMousex;
     float cpos41 = (1-pct4) * 800 + pct4 * moveMousey;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle(cpos4, cpos41, 50);
    
    float pct5 = easeOutBounce(pct);
    float cpos5 = (1-pct5) * 500 + pct5 * moveMousex;
     float cpos51 = (1-pct5) * 0 + pct5 * moveMousey;
    ofSetColor(255);
    ofSetCircleResolution(50);
    ofDrawCircle( cpos5, cpos51, 90);
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
