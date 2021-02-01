import processing.serial.*;

Serial myPort;  // The serial port
String receiveSerial

PImage button1;  // Declare a variable of type PImage

void setup() {
  size(1024,1024);
  //
  //Serial port declaration
  //
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, "COM3", 115200, 'N', 8, 1);
  //
  //Images declarations
  //
  button1 = loadImage("bottones.png");
  button1.resize(128,128);
}

void draw() {
  textSize(32);
  background(41,239,152);
  text("problema 7",128,736);
  text("problema 8",384,736);
  text("problema propuesto",672,736);
  image(button1,160,768);
  image(button1,384,768);
  image(button1,672+96,768);
  /*while (myPort.available() > 0) {
    int inByte = myPort.read();
    println(inByte);
  }*/
 
 
}


void mouseClicked(){
  //faltan las posiciones de los botones
  //problema 7
  if(mouseX > && mouseX < && mouseY < && mouseY < ){
    //manda el caracter 1 al micro para indicar que se corra el problema 7
    myPort.write(49);
    while(myPort.available()){
      String s;
      String buffer = myPort.readString();
      s = concant(s, buffer);
      text(s, 10, 10, 500, 500);
      
    }
  }
}
void serialEvent(Serial p){
  
}
