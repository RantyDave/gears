// For Digispark ATTiny85
// https://www.jaycar.co.nz/duinotech-attiny85-micro-usb-development-board/p/XC3940
// https://www.jaycar.co.nz/medias/sys_master/images/images/9487605497886/XC3940-manualMain.pdf
// not that I'm recommending it
// note that p3 is effectively verboten

// 0-5v into p2 sets centre
// 0-5v into p5 sets amplitude
// 0-5v (with pull down) into p0, p1 for gear up and down
// control pulse out on p4 for servo

// Note that the provided digistump toolchain is 32 bit only
// Fix it with: https://forum.arduino.cc/index.php?topic=620175.msg4374194#msg4374194

// Servo can't be plugged in when you're programming!

void setup() {
  pinMode(2, INPUT);  // p2, analog input 1
  pinMode(5, INPUT);  // p5, analog input 0
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // calculate desired output (starts at centre)
  float output = analogRead(1) / 2048;  // 10 bit adc, divided by two
  float amplitude = analogRead(0) / 2048;
  if (digitalRead(0)) output += amplitude;
  if (digitalRead(1)) output -= amplitude;

  // output desired pulse
  digitalWrite(4, HIGH);
  delayMicroseconds(1000 + 1000 * output);
  digitalWrite(4, LOW);
  delay(5);
}
