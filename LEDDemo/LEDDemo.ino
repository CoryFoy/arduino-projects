int ledPin = 7;
int ledPin2 = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin2, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    digitalWrite(ledPin2, LOW);
    delay(200);
}



