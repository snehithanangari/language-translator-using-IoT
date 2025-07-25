// Flex Sensor pins connected to A0-A3
const int flex1 = A0;
const int flex2 = A1;
const int flex3 = A2;
const int flex4 = A3;

void setup() {
  Serial.begin(9600);
  pinMode(flex1, INPUT);
  pinMode(flex2, INPUT);
  pinMode(flex3, INPUT);
  pinMode(flex4, INPUT);
}

void loop() {
  int f1 = analogRead(flex1);
  int f2 = analogRead(flex2);
  int f3 = analogRead(flex3);
  int f4 = analogRead(flex4);

  // Print values (for calibration)
  Serial.print("F1: "); Serial.print(f1);
  Serial.print(" F2: "); Serial.print(f2);
  Serial.print(" F3: "); Serial.print(f3);
  Serial.print(" F4: "); Serial.println(f4);

  delay(500);

  // Simple gesture recognition logic
  if (f1 < 400 && f2 < 400 && f3 > 600 && f4 > 600) {
    Serial.println("Gesture: HELLO");
    // Send to IoT / Speak
  } else if (f1 > 600 && f2 < 400 && f3 < 400 && f4 > 600) {
    Serial.println("Gesture: YES");
  } else if (f1 < 400 && f2 > 600 && f3 > 600 && f4 < 400) {
    Serial.println("Gesture: NO");
  }
}

