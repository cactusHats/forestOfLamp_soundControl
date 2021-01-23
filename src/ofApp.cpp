#include "ofApp.h"
#include "define.h"

//--------------------------------------------------------------
void ofApp::setup(){
	rcv.setup(PORT_TO_SCON);

	//BGMの設定
	bgm.load("bgm.mp3"); //データロード
	bgm.play(); //再生
	bgm.setLoop(true); //繰り返し再生許可
	bgm.setVolume(0.3); //音量設定

	//効果音の設定
	//データのロード
	sound1.load("sound1.mp3");
	sound2.load("sound2.mp3");
	sound3.load("sound3.mp3");

	//音量設定
	sound1.setVolume(0.5);
	sound2.setVolume(0.5);
	sound3.setVolume(0.5);

	//重なり再生を許可
	sound1.setMultiPlay(true);
	sound2.setMultiPlay(true);
	sound3.setMultiPlay(true);

	//画像ファイルのロード
	img.load("speaker.png");

	cout << "---------------------" << endl;
	cout << "--- Process start ---" << endl;
	cout << "---------------------" << endl;
	cout << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

	//効果音の再生
	//OSCデータの受信
	while (rcv.hasWaitingMessages()) {
		ofxOscMessage m;
		rcv.getNextMessage(&m);

		float vol = 0; //音量
		float pan = 0; //左右の音量バランス

		vol = m.getArgAsFloat(0);
		pan = m.getArgAsFloat(1);

		//範囲内の値であること確認
		vol = rangeCheck(vol, 0.0f, 1.0f);
		pan = rangeCheck(pan, -1.0f, 1.0f);

		printf("get osc msg: vol=%.1f pan=%.1f\n", vol, pan);

		//サウンド再生
		if (m.getAddress() == "/lamp/spund/1/play") {
			soundEcho(1, vol, pan);
		}
		else if (m.getAddress() == "/lamp/spund/2/play") {
			soundEcho(2, vol, pan);
		}
		else if (m.getAddress() == "/lamp/spund/3/play") {
			soundEcho(3, vol, pan);
		}
		else {
			cout << "No sound data assigned" << endl;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	img.draw(22, 22);
}

//--------------------------------------------------------------
void ofApp::soundEcho(int soundId, float vol, float pan) {

	switch (soundId) {
	case 1:
		sound1.play();
		sound1.setVolume(vol);
		sound1.setPan(pan);
		break;
	case 2:
		sound2.play();
		sound2.setVolume(vol);
		sound2.setPan(pan);
		break;
	case 3:
		sound3.play();
		sound3.setVolume(vol);
		sound3.setPan(pan);
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
float ofApp::rangeCheck(float val, float min, float max) {
	if (val < min) val = min;
	else if (max < val) val = max;
	return val;
}
