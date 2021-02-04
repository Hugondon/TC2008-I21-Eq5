import processing.serial.*;

Serial myPort;  // The serial port

int count;

String[] test = {"a","b","a","b","c","d","e","f","g","d","h","i","j"};

void setup() {
  myPort = new Serial(this, "COM2", 115200, 'N', 8, 1);
  count = 0;
}

void draw(){
  fill(255);
  rect(25, 25, 50, 50);
}

void mouseClicked() {
  myPort.write(test[count]);
  print(test[count]);
  count =(count + 1)%13;
}
