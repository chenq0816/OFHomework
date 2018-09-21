#include "ofApp.h"
#include "Box.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    star.load("/Users/chenqizhao/Downloads/star.png");
    ofSetBackgroundColor(0);
    

    ofSetVerticalSync(true);
    cam.setDistance(900);
    
    
    for(int i = 0; i <12000; i++){
        Box b;
        mybox.push_back(b);
        mybox[i].setup(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0));
    }
   
    
}


//--------------------------------------------------------------
void ofApp::update(){
 for(int i = 0; i <12000; i++){
     
     mybox[i].addAttractionForce(ofPoint(ofGetWidth()/2, ofGetHeight()/2,0),300,.001);
     mybox[i].update();
 }
}




//--------------------------------------------------------------
void ofApp::draw(){
  
    ofEnableDepthTest();
    cam.begin();
   star.draw(-400, -100,-50);
    
    
    

    for(int i = 0; i <12000; i++){

        
//        float angle = ofDegToRad(30*i);

//        mybox[i].pos.x = 60 * cos(angle);
//         mybox[i].pos.y = 60 * sin(angle);
//        mybox[i].pos.z = 0;
        
        
        ofSetColor(ofRandom(180,240), ofRandom(182,200), 255);
        mybox[i].draw();
        ofSetColor(255);
        ofNoFill();
                ofDrawSphere(ofGetWidth()/2, ofGetHeight()/2, 0, 40);
        ofFill();

            }
    
    
    
//    
//    for(int m = 0; m <60; m++){
//
//        
//        float angle = ofDegToRad(6*m);
//       
//        mybox[m].pos.x = 120 * cos(angle);
//        mybox[m].pos.y = 120 * sin(angle);
//        mybox[m].pos.z = 0;
//        
//        
//        
//        
//        mybox[m].draw();
//    }
//    
//    
//    for(int n = 0; n <60; n++){
//
//        
//        float angle = ofDegToRad(6*n);
//   
//        mybox[n].pos.x = 180 * cos(angle);
//        mybox[n].pos.y = 180 * sin(angle);
//        mybox[n].pos.z = 0;
//        
//        
//        
//        mybox[n].draw();
//
//        ofDrawSphere(pos.x, pos.y, pos.z, 40);
//
//    }



    
    
    
    cam.end();
    ofDisableDepthTest();
    gui.draw();

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
