// USB Virtual Serial Receive Speed Benchmark
//
// This program sends data as rapidly as possible



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
  
  // send in chunks, toggle pin 3 after each chunk
  while (1) {
    USBSERIAL.write(buf, 500);
    digitalWriteFast(3, !digitalRead(3));
  }
  
}
