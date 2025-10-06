// Arduino Joystick + 6 LEDs

const int joyX = A0;       // محور X
const int joySW = 8;       // زر الضغط (اختياري)
const int leds[] = {2, 3, 4, 5, 6, 7};
const int ledCount = 6;

int xValue = 0;
int numLEDsOn = 0;

void setup() {
  Serial.begin(9600);

  pinMode(joySW, INPUT_PULLUP);  // الزر عادة LOW عند الضغط

  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  xValue = analogRead(joyX);  // قراءة قيمة المحور X (0 - 1023)

  // تحويل قيمة X إلى عدد LEDs مضاءة (من 0 إلى 6)
  numLEDsOn = map(xValue, 0, 1023, 0, ledCount);
  numLEDsOn = constrain(numLEDsOn, 0, ledCount);

  // تشغيل LEDs حسب موضع العصا
  for (int i = 0; i < ledCount; i++) {
    if (i < numLEDsOn) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }

  // قراءة الزر (اختياري)
  if (digitalRead(joySW) == LOW) {
    Serial.println("Joystick button pressed!");
  }

  Serial.print("X Value: ");
  Serial.print(xValue);
  Serial.print("  -> LEDs ON: ");
  Serial.println(numLEDsOn);

  delay(100);
}
