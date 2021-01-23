#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void soundEcho(int soundId, float vol, float pan);
		float rangeCheck(float val, float min, float max);

		//bgm
		ofSoundPlayer bgm;
		
		//effect
		ofSoundPlayer sound1;
		ofSoundPlayer sound2;
		ofSoundPlayer sound3;

		ofxOscReceiver rcv;
		ofImage img;
};
