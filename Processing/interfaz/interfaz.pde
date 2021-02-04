import processing.serial.*;

Serial myPort;  // The serial port
String receiveSerial, buffer_semaforos;
PImage button1, bluepill;  // Declare a variable of type PImage

//  Cuántas veces se han ejecutado los procesos
int produciendo, consumiendo, despachando_orden, empacador, cocinero, cajero, pedido_cliente, pedir_ayuda, asegurar_zona, matar_dragon;

// Posición en X para texto (buffer_semaforos)
int posX;

void setup() { //<>//
  
  // Inicialización ventana
  size(1024,640);
  
  // Inicialización Puerto Serial 
  myPort = new Serial(this, "COM5", 115200, 'N', 8, 1);
  
  // Imágenes
  button1 = loadImage("button.png");
  bluepill = loadImage("bluepill.png");
  button1.resize(128,128);
  
  // Valores iniciales
  produciendo = -1;
  consumiendo = -1;
  despachando_orden = -1;
  empacador = -1;
  cocinero = -1;
  cajero = -1;
  pedido_cliente = -1;
  pedir_ayuda = -1;
  asegurar_zona = -1;
  matar_dragon = -1;
  buffer_semaforos = "";
}

void draw() {
  fill(26, 2, 120);
  background(133, 211, 242);
  textSize(24);
  
  text("Problema 7", 88, 186);
  text("Problema 8", 388, 186);
  text("Problema propuesto", 688, 186);
  
  image(button1,120,28);
  image(button1,400,28);
  image(button1,672+96,28);
  image(bluepill, 312, 422);  
  
    
  if(despachando_orden != -1 || empacador  != -1 || cocinero  != -1 || cajero  != -1 || pedido_cliente != -1){
    buffer_semaforos = String.format("Despachando orden = %d\nEmpacador = %d\nCocinero = %d\nCajero = %d\nPedido cliente = %d",despachando_orden,empacador,cocinero,cajero,pedido_cliente);
    posX = 350;
  }
  else if(produciendo != -1 || consumiendo != -1){
    buffer_semaforos = String.format("Produciendo = %d\nConsumiendo = %d",produciendo,consumiendo);
    posX = 75;
  }
  else if(pedir_ayuda != -1 || asegurar_zona != -1 || matar_dragon != -1){
    buffer_semaforos = String.format("Pedir Ayuda = %d\nAsegurar Zona = %d\nMatar dragón = %d",pedir_ayuda,asegurar_zona,matar_dragon);
    posX = 700;
  }
  else{
    buffer_semaforos = String.format("");
    posX = 480;
  }
  text(buffer_semaforos,posX,250);
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
    produciendo++;
    despachando_orden = -1;
    empacador = -1;
    cocinero = -1;
    cajero = -1;
    pedido_cliente = -1;
    pedir_ayuda = -1;
    asegurar_zona = -1;
    matar_dragon = -1;
  }
  else if(receiveSerial.equals("b")){
    if(produciendo == -1){
      produciendo = 0;
    }
    if(consumiendo == -1){
      consumiendo = 0;
    }
    consumiendo++;
    despachando_orden = -1;
    empacador = -1;
    cocinero = -1;
    cajero = -1;
    pedido_cliente = -1;
    pedir_ayuda = -1;
    asegurar_zona = -1;
    matar_dragon = -1;
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
  pedir_ayuda = -1;
  asegurar_zona = -1;
  matar_dragon = -1;
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
    pedir_ayuda = -1;
    asegurar_zona = -1;
    matar_dragon = -1;
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
    pedir_ayuda = -1;
    asegurar_zona = -1;
    matar_dragon = -1;
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
    pedir_ayuda = -1;
    asegurar_zona = -1;
    matar_dragon = -1;
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
    pedir_ayuda = -1;
    asegurar_zona = -1;
    matar_dragon = -1;
    pedido_cliente++;
  }
  else if(receiveSerial.equals("h")){
    if(pedir_ayuda == -1){
      pedir_ayuda = 0;
    }
    if(asegurar_zona == -1){
      asegurar_zona = 0;
    }
    if(cocinero == -1){
      cocinero = 0;
    }
    if(matar_dragon == -1){
      matar_dragon = 0;
    }
    produciendo = -1;
    consumiendo = -1;
    despachando_orden = -1;
    empacador = -1;
    cocinero = -1;
    cajero = -1;
    pedido_cliente = -1;
    pedir_ayuda++;
  }
    else if(receiveSerial.equals("i")){
    if(pedir_ayuda == -1){
      pedir_ayuda = 0;
    }
    if(asegurar_zona == -1){
      asegurar_zona = 0;
    }
    if(matar_dragon == -1){
      matar_dragon = 0;
    }
    produciendo = -1;
    consumiendo = -1;
    despachando_orden = -1;
    empacador = -1;
    cocinero = -1;
    cajero = -1;
    pedido_cliente = -1;
    asegurar_zona++;
  }
    else if(receiveSerial.equals("j")){
    if(pedir_ayuda == -1){
      pedir_ayuda = 0;
    }
    if(asegurar_zona == -1){
      asegurar_zona = 0;
    }
    if(matar_dragon == -1){
      matar_dragon = 0;
    }
    produciendo = -1;
    consumiendo = -1;
    despachando_orden = -1;
    empacador = -1;
    cocinero = -1;
    cajero = -1;
    pedido_cliente = -1;
    matar_dragon++;
  }
  redraw();
}
