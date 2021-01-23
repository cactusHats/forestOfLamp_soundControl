#include "ofApp.h"
#include "define.h"

//--------------------------------------------------------------
void ofApp::setup(){
	rcv.setup(PORT_TO_SCON);

	//BGM�̐ݒ�
	bgm.load("bgm.mp3"); //�f�[�^���[�h
	bgm.play(); //�Đ�
	bgm.setLoop(true); //�J��Ԃ��Đ�����
	bgm.setVolume(0.3); //���ʐݒ�

	//���ʉ��̐ݒ�
	//�f�[�^�̃��[�h
	sound1.load("sound1.mp3");
	sound2.load("sound2.mp3");
	sound3.load("sound3.mp3");

	//���ʐݒ�
	sound1.setVolume(0.5);
	sound2.setVolume(0.5);
	sound3.setVolume(0.5);

	//�d�Ȃ�Đ�������
	sound1.setMultiPlay(true);
	sound2.setMultiPlay(true);
	sound3.setMultiPlay(true);

	//�摜�t�@�C���̃��[�h
	img.load("speaker.png");

	cout << "---------------------" << endl;
	cout << "--- Process start ---" << endl;
	cout << "---------------------" << endl;
	cout << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

	//���ʉ��̍Đ�
	//OSC�f�[�^�̎�M
	while (rcv.hasWaitingMessages()) {
		ofxOscMessage m;
		rcv.getNextMessage(&m);

		float vol = 0; //����
		float pan = 0; //���E�̉��ʃo�����X

		vol = m.getArgAsFloat(0);
		pan = m.getArgAsFloat(1);

		//�͈͓��̒l�ł��邱�Ɗm�F
		vol = rangeCheck(vol, 0.0f, 1.0f);
		pan = rangeCheck(pan, -1.0f, 1.0f);

		printf("get osc msg: vol=%.1f pan=%.1f\n", vol, pan);

		//�T�E���h�Đ�
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
