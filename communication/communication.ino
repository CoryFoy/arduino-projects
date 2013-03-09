int ledPin = 10;
int speakerPin = 11;

char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'c'};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    int on_or_off = Serial.read();
    if(on_or_off == 1) {
      digitalWrite(ledPin, HIGH);
      playNote('a', 200);
    } else if(on_or_off == 0) {
      digitalWrite(ledPin, LOW);
    } else {
      playNote(names[on_or_off-2], 100);
    }
  }
}

void playTone(int tone, int duration) {
  for(long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  for(int i = 0; i < 8; i++) {
   if(names[i] == note) {
    playTone(tones[i], duration);
   } 
  }
}
