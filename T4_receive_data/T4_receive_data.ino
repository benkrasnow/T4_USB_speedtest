// USB Virtual Serial Receive Speed Benchmark
//
// This program receives data as rapidly as possible
// using Serial.readBytes() to read 500 bytes at a time.


// use one of these to define
// the USB virual serial name
//
#define USBSERIAL Serial      // Arduino Leonardo, Teensy, Fubarino
//#define USBSERIAL SerialUSB   // Arduino Due, Maple


void setup() {
  USBSERIAL.begin(9600);
  USBSERIAL.setTimeout(0);
  pinMode(2, OUTPUT);  // frequency is kbytes/sec
  pinMode(3, OUTPUT);  // duty cycle is CPU free time
}

byte pinstate=LOW;

void loop() {
  char buf[500];
  int count=0;
  int n;
  
  // receive 500 bytes, using Serial.readBytes
  // as many times as necessary until all 500
  while (count < 500) {
    n = USBSERIAL.readBytes(buf+count, 500-count);
    if (n == 0) {
      digitalWriteFast(3, HIGH);
      while (!USBSERIAL.available()) ; // wait
      digitalWriteFast(3, LOW); 
    }
    count = count + n;
  }
  
  // toggle pin 2, so the frequency is kbytes/sec
  if (pinstate == LOW) {
    digitalWriteFast(2, HIGH);
    pinstate = HIGH;
  } else {
    digitalWriteFast(2, LOW);
    pinstate = LOW;
  }
}
