int sensorPin =  7;
int ledPin = 4;
int speakerPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Warming up...");
  for(int i = 1; i <= 10; i++) {
    Serial.print(20-i);
    Serial.println(" seconds remaining");
    delay(1000);
  }
}

void loop() {
  if(digitalRead(sensorPin) == 1) {
    digitalWrite(ledPin, HIGH);
    playNote('c', 500);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(200);
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
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'c'};
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  for(int i = 0; i < 8; i++) {
   if(names[i] == note) {
    playTone(tones[i], duration);
   } 
  }
}
