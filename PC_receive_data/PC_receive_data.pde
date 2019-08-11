import processing.serial.*;

Serial T4Serial;

private static final int BLOCKSIZE = 4000000;
void setup() {
  size(800, 800);  // create the window
  String[] list = Serial.list();
  delay(20);
  println("Serial Ports List:");
  println(list);
  
  T4Serial = new Serial(this, "COM26");
  
}


int incomingdata;
int cnt;
void draw() {
   background(255);
   fill(0);
   cnt = 0;
   int d = millis();
    while(cnt < BLOCKSIZE)
        {
          while(T4Serial.available() > 0)
            {
              incomingdata = T4Serial.read();
              cnt++;
            }
         for(int i = 0; i<100000; i++);
        }
       
   int e = millis();
   print("Time:");
   print((BLOCKSIZE/(e - d)));
 
   println(" KB/sec");
   delay(10);
}
