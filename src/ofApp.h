#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT_TO_SCON 8000

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

		void soundEcho(int soundId, float vol, float pan);
		float rangeCheck(float val, float min, float max);

		ofSoundPlayer bgm; //bgm
		ofSoundPlayer sound1; //effect
		ofSoundPlayer sound2;
		ofSoundPlayer sound3;

		ofImage img;

		ofxOscReceiver rcv;
		
};
