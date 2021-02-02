import processing.serial.*;

Serial myPort;  // The serial port
String receiveSerial;
String printFlags;

PImage button1;  // Declare a variable of type PImage

//variables off how many times a certain process has been executed
int produciendo;
int consumiendo;
int despachando_orden;
int empacador;
int cocinero;
int cajero;
int pedido_cliente;


void setup() { //<>//
  size(1024,1024);
  //
  //Serial port declaration
  //
  // List all the available serial ports
  //printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, "COM2", 115200, 'N', 8, 1);
  //
  //Images declarations
  //
  button1 = loadImage("bottones.png");
  button1.resize(128,128);
  produciendo = -1;
  consumiendo = -1;
  despachando_orden = -1;
  empacador = -1;
  cocinero = -1;
  cajero = -1;
  pedido_cliente = -1;
  printFlags = "";
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
  
  if(despachando_orden != -1 || empacador  != -1 || cocinero  != -1 || cajero  != -1 || pedido_cliente != -1){
     printFlags = String.format("despachando_orden = %d\nempacador = %d\ncocinero = %d\ncajero = %d\npedido_cliente = %d",despachando_orden,empacador,cocinero,cajero,pedido_cliente);
  }
  else if(produciendo != -1 || consumiendo != -1){
    printFlags = String.format("produciendo = %d\nconsumiendo = %d",produciendo,consumiendo);
  }
  else{
    printFlags = String.format("");
  }
  text(printFlags,0,64);
}

void serialEvent(Serial p){
  receiveSerial = p.readString();
   print(receiveSerial);
  //actualizar cuantas veces se hizo cada proceso
  if(receiveSerial.equals("a")){
    if(produciendo == -1){
      produciendo = 0;
    }
    if(consumiendo == -1){
      consumiendo = 0;
    }
    produciendo = produciendo + 1;
    despachando_orden = -1;
    empacador = -1;
    cocinero = -1;
    cajero = -1;
    pedido_cliente = -1;
  }
  else if(receiveSerial.equals("b")){
    if(produciendo == -1){
      produciendo = 0;
    }
    if(consumiendo == -1){
      consumiendo = 0;
    }
    consumiendo = consumiendo + 1;
    despachando_orden = -1;
    empacador = -1;
    cocinero = -1;
    cajero = -1;
    pedido_cliente = -1;
  }
  else if(receiveSerial.equals("c")){
  if(despachando_orden == -1){
    despachando_orden = 0;
  }
  if(empacador == -1){
    empacador = 0;
  }
  if(cocinero == -1){
    cocinero = 0;
  }
  if(cajero == -1){
    cajero = 0;
  }
  if(pedido_cliente == -1){
    pedido_cliente = 0;
  }
  produciendo = -1;
  consumiendo = -1;
  despachando_orden = despachando_orden + 1;
  }
  else if(receiveSerial.equals("d")){
    if(despachando_orden == -1){
      despachando_orden = 0;
    }
    if(empacador == -1){
      empacador = 0;
    }
    if(cocinero == -1){
      cocinero = 0;
    }
    if(cajero == -1){
      cajero = 0;
    }
    if(pedido_cliente == -1){
      pedido_cliente = 0;
    }
    produciendo = -1;
    consumiendo = -1;
    empacador = empacador + 1;
  }
    else if(receiveSerial.equals("e")){
    if(despachando_orden == -1){
      despachando_orden = 0;
    }
    if(empacador == -1){
      empacador = 0;
    }
    if(cocinero == -1){
      cocinero = 0;
    }
    if(cajero == -1){
      cajero = 0;
    }
    if(pedido_cliente == -1){
      pedido_cliente = 0;
    }
    produciendo = -1;
    consumiendo = -1;
    cocinero = cocinero + 1;
   }
  else if(receiveSerial.equals("f")){
    if(despachando_orden == -1){
      despachando_orden = 0;
    }
    if(empacador == -1){
      empacador = 0;
    }
    if(cocinero == -1){
      cocinero = 0;
    }
    if(cajero == -1){
      cajero = 0;
    }
    if(pedido_cliente == -1){
      pedido_cliente = 0;
    }
    produciendo = -1;
    consumiendo = -1;
    cajero = cajero + 1;
  }
  else if(receiveSerial.equals("g")){
    if(despachando_orden == -1){
      despachando_orden = 0;
    }
    if(empacador == -1){
      empacador = 0;
    }
    if(cocinero == -1){
      cocinero = 0;
    }
    if(cajero == -1){
      cajero = 0;
    }
    if(pedido_cliente == -1){
      pedido_cliente = 0;
    }
    produciendo = -1;
    consumiendo = -1;
    pedido_cliente = pedido_cliente + 1;
  }
  redraw();
}
