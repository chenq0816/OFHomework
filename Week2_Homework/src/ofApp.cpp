#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add( freqSlider.setup("Sin Freq", 1, .25,10));
    gui.add( sizeSlider.setup("Size", 1, .05,1));

//    ofSetBackgroundColor(198, 214, 184);
  
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//     float Rheight = ofMap(sin( ofGetElapsedTimef()), -1, 1, 0, 80);
//
//    for (int x =0; x < ofGetWidth(); x = x +10)
//    {
//        int y =400;
//        ofSetColor(229, 252, 194);
//
//        ofDrawRectangle(x, y, 10, (sin(x + ofGetElapsedTimef())-1) * Rheight);
//    }
    
    float sinValue = ofMap(sin( ofGetElapsedTimef()), -1, 1, 36, 40);
    ofLog() << sinValue;
    
    
    //    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 20 + sinValue);
    
    for(int x =0; x < ofGetWidth(); x +=sizeSlider * 50){
        for(int y = 0; y < ofGetHeight()/8; y+=50){
             ofSetColor(255, 255, 255);
            ofDrawRectangle(x, y + 400, freqSlider*(40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
            
            
             ofSetColor(233, 242, 249);
              ofDrawRectangle(x, y + 430, freqSlider* (40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
            
            ofSetColor(58, 137, 201);
            ofDrawRectangle(x, y + 460, freqSlider*(40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), 2*sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
            
            ofSetColor(27, 50, 95);
            ofDrawRectangle(x, y + 500, freqSlider*(40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), 2*sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
            
            ofSetColor(27, 50, 95);
            ofDrawRectangle(x, y + 540, freqSlider*(40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), 2*sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
            
            ofSetColor(27, 50, 95);
            ofDrawRectangle(x, y + 580, freqSlider*(40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), 2*sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
            
            ofSetColor(27, 50, 95);
            ofDrawRectangle(x, y + 620, freqSlider*(40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), 2*sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
            
            ofSetColor(27, 50, 95);
            ofDrawRectangle(x, y + 660, freqSlider*(40+sin(y*0.4) * sin(ofGetElapsedTimef()+x)*sinValue), 2*sin(y*0.4) * sin(ofGetElapsedTimef()+x) * sinValue);
        }
        
        gui.draw();
       
        
        
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        
//            float targetAngle = atan2( mouseY - ofGetHeight()/4 , mouseX - 3*ofGetWidth()/4);
//        
//            //translate to center of screen and draw rectangle
//            ofPushMatrix();
//            ofTranslate(3*ofGetWidth()/4, ofGetHeight()/4);
//            ofRotateZRad(targetAngle);
//        ofSetColor(255, 194, 21);
//            ofDrawRectangle(0, 0, 50, 50);
//            ofPopMatrix();
     
        
//        for(int i = 0; i < 1440; i +=5){
//            float angle = ofDegToRad(i);
//            float angle2 = ofDegToRad(sin(ofGetElapsedTimef()));
//            float x = ofGetWidth()/2 + (i*.5) * cos(angle);
//            float y = ofGetHeight()/2 + (i*.5) * sin(angle);
//            ofNoFill();
//            ofSetColor(255, 255, 255);
//            
//            ofDrawCircle(x, y, 3000*sin(angle2));
//            
//        }
        
        
        for(int i = 0; i <1080; i +=1){
            float angle = ofDegToRad(i);
            float x = 1.5*ofGetWidth()/4+ofGetWidth()/2 + 0.08*(i*.5) * cos(angle)-100;
            float y = ofGetHeight()/2 + 0.08*(i*.5) * sin(angle)-200;
           ofSetColor(255, 190, 64);
            ofDrawCircle(x, y, 4);

        }

        
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
