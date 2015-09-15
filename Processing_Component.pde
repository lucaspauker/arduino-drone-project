import processing.serial.*;

Serial myPort;

color fillVal1=color(255);
color fillVal2=color(255);
color fillVal3=color(255);
color fillVal4=color(255);
color fillVal5=color(255);
color fillVal6=color(255);
color fillVal7=color(255);
color fillVal8=color(255);

void setup(){
  size(200,225);
  background(255);
  String portName = Serial.list()[0]; 
  myPort = new Serial(this, portName, 9600);
}

void draw(){
  fill(fillVal1);
  
  rect(25,100,50,50,15);
  fill(fillVal2);
  rect(75,150,50,50,15);
  fill(fillVal3);
  rect(125,100,50,50,15);
  fill(fillVal4);
  rect(75,50,50,50,15);
  fill(fillVal5);
  rect(0,0,75,25,10);
  fill(fillVal6);
  rect(125,0,75,25,10);
  fill(fillVal7);
  rect(10,170,50,50,25);
  fill(fillVal8);
  rect(140,170,50,50,25);
}

void keyPressed(){
  if (key=='a'||key=='A'){
    fillVal5 = (#FF00FF);
    myPort.write('W');  //CCW
    }
  if (key=='s'||key=='S'){
    fillVal6 = (#FFA500);
    myPort.write('C');  //CW
    }
  if (key==TAB){
    fillVal8 = (000);
    myPort.write('U');  //UP
    }
  if (key==CODED){
    if (keyCode==UP){
      fillVal4 = (#FF0000);
      myPort.write('F');  //FORWARD
    }
      else if (keyCode==LEFT){
        fillVal1 = (#0000FF);
        myPort.write('L');  //LEFT
      }
        else if (keyCode==DOWN){
          fillVal2 = (#FFFF00);
          myPort.write('B');  //BACKWARD
        }
          else if (keyCode==RIGHT){
            fillVal3 = (#00FF00);
            myPort.write('R');  //RIGHT
          }
              else if (keyCode==SHIFT){
                fillVal7 = (000);
                myPort.write('D');  //DOWN
                }
  }
  if (key==' '){
    myPort.write('K');  //KILL
    fillVal1=color(#FF0000);
    fillVal2=color(#FF0000);
    fillVal3=color(#FF0000);
    fillVal4=color(#FF0000);
    fillVal5=color(#FF0000);
    fillVal6=color(#FF0000);
    fillVal7=color(#FF0000);
    fillVal8=color(#FF0000);    
  }
  if (key=='1'){
    myPort.write('1');
  }
  if (key=='k'){
    myPort.write('k');
  }
  if (key=='j'){
    myPort.write('j');
  }
  if (key=='l'){
    myPort.write('l');
  }
  if (key=='i'){
    myPort.write('i');
  }
}


void keyReleased(){
  if (key=='a'||key=='A'){
    fillVal5 = (255);
    myPort.write('X');  //NOCCW
  }
  if (key=='s'||key=='S'){
    fillVal6 = (255);
    myPort.write('E');  //NOCW
  }
  if (keyCode==UP){
    fillVal4 = (255);
    myPort.write('G');  //NOFORWARD
  }
  if (keyCode==DOWN){
    fillVal2 = (255);
    myPort.write('A');  //NOBACKWARD
  }
  if (keyCode==RIGHT){
    fillVal3 = (255);
    myPort.write('S');  //NORIGHT
  }
  if (keyCode==LEFT){
    fillVal1 = (255);
    myPort.write('M');  //NOLEFT
  }
  if (keyCode==TAB){
    fillVal8 = (255);
    myPort.write('V');  //NOUP
  }
  if (keyCode==SHIFT){
    fillVal7 = (255);
    myPort.write('F');  //NODOWN
  }
//  if (key=='i'||key=='j'||key=='k'||key=='l'){
//    myPort.write('x');
//  }
  if (key==' '){
    fillVal1=color(255);
    fillVal2=color(255);
    fillVal3=color(255);
    fillVal4=color(255);
    fillVal5=color(255);
    fillVal6=color(255);
    fillVal7=color(255);
    fillVal8=color(255);    
  }
}
