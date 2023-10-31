#include <pitches.h>
// 음정에 해당하는 주파수를 매크로로 설정.

int speakerPin = 57;  // 스피커 연결 핀
int melody[] = {  // 학교 종 멜로디, 0은 쉼표
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, 0,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, 0
};
int noteDuration = 4; // 4분 음표

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  // 멜로디 배열의 총 사이즈를 int형으로 나누어서 갯수 찾기.
  for(int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
    // 음표 길이를 시간으로 변환
    int noteLength = 1000 / noteDuration;
    // 단음 재생
    tone(speakerPin, melody[thisNote], noteLength);
    delay(noteLength);
    noTone(speakerPin); // 현재 음 재생 중지
  }
  while(true);  // 1회 재생 후 대기.
}
