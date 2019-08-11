import processing.serial.*;

Serial T4Serial;

private static final int BLOCKSIZE = 32000;
void setup() {
  size(800, 800);  // create the window
  String[] list = Serial.list();
  delay(20);
  println("Serial Ports List:");
  println(list);
  
  T4Serial = new Serial(this, "COM26");
  
}

byte[] randomdata = new byte[BLOCKSIZE];

void draw() {
   
  
  background(255);
  fill(0);
   int d = millis();
   for(int i = 0; i <10; i++)
    {
       T4Serial.write(randomdata);
    }
    
   int e = millis();
   print("Time:");
   print(((BLOCKSIZE*10)/(e - d)));
   println(" KB/sec");
   
}
