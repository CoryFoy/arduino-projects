int temperaturePin = 0;
float digitalRangeConversion = 0.004882814;

int ledPin1 = 7;
int ledPin2 = 6;
int ledPin4 = 5;
int ledPin8 = 4;
int ledPin16 = 3;
int ledPin32 = 2;
int ledPin64 = 1;
int ledPin128 = 0;

int cPin1 = 8;
int cPin2 = 9;
int cPin4 = 10;
int cPin8 = 11;
int cPin16 = 12;
int cPin32 = 13;

const int fPinLength = 8;
int fPins[fPinLength] = {ledPin1, ledPin2, ledPin4, ledPin8, ledPin16, ledPin32, ledPin64, ledPin128};

const int cPinLength = 6;
int cPins[cPinLength] = {cPin1, cPin2, cPin4, cPin8, cPin16, cPin32};

float tempInF(float tempInCelsius) {
 return tempInCelsius * 9/5 + 32; 
}

void setup() {
  
  for(int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  delay(500);
  
  for(int i = 0; i < 14; i++) {
    digitalWrite(i, LOW);
    delay(250);
  }
 
 Serial.begin(9600); 
}

void loop() {
 float temperature = getVoltage(temperaturePin);
 temperature = (temperature - .5) * 100;
 Serial.print(temperature);
 Serial.print("C, ");
 Serial.print(tempInF(temperature));
 Serial.println("F");
 displayCTemp(temperature);
 displayFTemp(tempInF(temperature));
 delay(1000); 
}

void displayTemp(float temperature, int pins[], int pinCount) {
  int temp = (int)temperature;
  int currentCycle = 2^(pinCount-1);
  
  for(int i = 0; i < pinCount; i++) {
    if((temp / currentCycle) > 0) {
      Serial.print("1");
      digitalWrite(pins[i], HIGH);
      temp = temp - currentCycle;
    } else {
      Serial.print("0");
      digitalWrite(pins[i], LOW);
    }
    currentCycle = currentCycle / 2;
  }
  Serial.println("");
}

void displayCTemp(float tempInC) {
  Serial.print("C: ");
  displayTemp(tempInC, cPins, cPinLength);
}

void displayFTemp(float tempInF) {
  Serial.print("F: ");
  displayTemp(tempInF, fPins, fPinLength);
}

float getVoltage(int pin) {
  return (analogRead(pin) * digitalRangeConversion);
}
