char val;

int throttle=3;
int rotation=9;
int Xaxis=10;
int Yaxis=11;

float throttlevar = 0.5;
int timevar=0;

float xaxistrim = 0;
float yaxistrim = 0;

int trimvar=2;

//let's first optimize this without serial ports. let's go up then down...

void setup() {
  // put your setup code here, to run once:
  pinMode(throttle, OUTPUT);
  pinMode(rotation, OUTPUT);
  pinMode(Xaxis, OUTPUT);
  pinMode(Yaxis, OUTPUT);
  
//  analogWrite(throttle, 254);
  writeVolts(throttle, 0);  //  full(3)/none(0), doesn't move at .5
  writeVolts(rotation, 1.5); //  CW(0)/CCW(3)
  writeVolts(Xaxis, 1.5); //   left(3)/right(0)
  writeVolts(Yaxis, 1.5); //   forward(3)/backward(0)
  
  Serial.begin(9600);              // Start serial communication at 9600 bps 
  
}
  
void loop() {
//  writeVolts(throttle,3); //THIS CODE IS FOR WHEN THE DRONE CANT CONNECT TO THE CONTROLLER
//  delay(250);
//  writeVolts(throttle,0);
//  delay(100000);
  

////UP (TURN) AND DOWN

//  writeVolts(throttle, 1.5);
//  double countvar=0;
//  double stepvar=.1;
//  double voltage=2;
//  while(countvar < voltage){    //Increase voltage by increments of stepvar
//    writeVolts(throttle, countvar);
//    countvar = countvar + stepvar;
//    delay(1000);
//  }
////  writeVolts(rotation,3)
////  delay(1000)
////  writeVolts(rotation,1.5)
//  while(countvar > 0){    //Decrease voltage by increments of stepvar
//    writeVolts(throttle, countvar);
//    countvar = countvar - stepvar;
//    delay(1000);
//  }


//SERIAL PORTS AND KEY COMMANDS:


  if (Serial.available()) {        // If data is available to read, 
    val = Serial.read();           // read it and store it in val 
  }
  if (val== 'W'){ //a
    writeVolts(rotation, 2.25);
 //   writeVolts(throttle,0);
  }
  if (val== 'C'){
    writeVolts(rotation, .75);
  }
  if (val== 'F'){
    writeVolts(Yaxis, 2);
  }
  if (val== 'B'){
    writeVolts(Yaxis, 1);
  }
  if (val== 'L'){
    writeVolts(Xaxis, 2.25);
  }
  if (val=='R'){
    writeVolts(Xaxis, .75);
  }
  if (timevar % 20 == 0){
    if (val== 'U'){
      throttlevar = throttlevar + .1;
      writeVolts(throttle, throttlevar);
    }
    if (val== 'D' ){
      if (throttlevar > .1){
        throttlevar = throttlevar - .1;
        writeVolts(throttle, throttlevar);
    
      }
    }
  }
  
  if (val== 'X'){
    writeVolts(rotation, 1.5);
  }
  if (val== 'E'){
    writeVolts(rotation, 1.5);
  }
  if (val== 'G'){
    writeVolts(Yaxis, 1.5);
  }
  if (val== 'A'){
    writeVolts(Yaxis, 1.5);
  }
  if (val== 'M'){
    writeVolts(Xaxis, 1.5);
  }
  if (val=='S'){
    writeVolts(Xaxis, 1.5);
  }
  if (val== 'V'){
    //i dont think i need anything here
  }
  if (val== 'F'){
    //i dont think i need anything here
  }
  if (val== 'K'){  //Everything back to normal
    writeVolts(throttle, 0);   //Kill Command
    writeVolts(rotation, 1.5); 
    writeVolts(Xaxis, 1.5);
    writeVolts(Yaxis, 1.5); 
    throttlevar = 0;
  }

//    if (val== '1'){
//      //First in the set of predetermined commands. 1 will 
//      //make the drone go up, turn 180 degrees ccw, go forward, 
//      //turn 180 degrees cw and go backwards to the original location
//      //then go back down
//      
//      double countvar=0;
//      double stepvar=.1;
//      double voltage=1.5;
//      while(countvar < voltage){    //Go up
//        writeVolts(throttle, countvar);
//        countvar = countvar + stepvar;
//        delay(200);
//      }
//      
//      delay(5000);
//      
//      writeVolts(rotation, 2);  //Rotate
//      delay(1500);
//      writeVolts(rotation,1.5);
//      delay(1000);
//      
//      writeVolts(Yaxis, 1.6);  //Forward
//      delay(500);
//      writeVolts(Yaxis, 1.5);
//      delay(1000);
//      
//      writeVolts(rotation, 1);  //Rotate other way
//      delay(500);
//      writeVolts(rotation, 1.5);
//      delay(1000);
//      
//      writeVolts(Yaxis, 1.4);  //Backwards
//      delay(500);
//      writeVolts(Yaxis, 1.5);
//      delay(1000);
//      
//      while(countvar > 0){    //Go down
//        writeVolts(throttle, countvar);
//        countvar = countvar - stepvar;
//        delay(1000);
//      }
//    }
  
  //REAL TIME TRIMMING
  
//  if (trimvar = 2){  
    if (val == 'k'){
      yaxistrim = yaxistrim - 0.1;
      delay(1000);
//      trimvar = 1;
    }
    if (val == 'j'){
      xaxistrim = xaxistrim + 0.1;
      delay(1000);
//      trimvar = 1;
    }
    if (val == 'l'){
      xaxistrim = xaxistrim - 0.1;
      delay(1000);
//      trimvar = 1;
    }
    if (val == 'i'){
      yaxistrim = yaxistrim + 0.1;
      delay(1000);
//      trimvar = 1;
    }
//  }
  if (yaxistrim < -1){
    yaxistrim = -1;
  }
  if (yaxistrim > 1){
    yaxistrim = 1;
  }
  if (xaxistrim < -0.75){
    xaxistrim = -0.75;
  }
  if (xaxistrim > 0.75){
    xaxistrim = 0.75;
  }
  if (val == 'x'){
    trimvar = 2;
  }


  
  delay(10);
  timevar = timevar + 1;  //when timevar is a multiple of 100 (every second), we can change the throttle
}

void writeVolts(double object, double volts){
  double pwm=0;
  if (object==throttle){
    //pwm=255;
    pwm=(255.0/5.)*(volts*(1.14));   //analogWrite goes from 0 to 255, we want 0-3 volts (regular is 0-5)
  }
    else if (object==rotation){
      //pwm=255;
      pwm=(255.0/5)*(volts-.3)*(1.26);
    }
        else if (object==Xaxis){ //.5-2.5??
        //pwm=255;
        pwm=((255.0/5)*(volts+xaxistrim)*(1.26));
        }
          else if (object==Yaxis){ //.5-2.5???
          //pwm=255;
          pwm=((255.0/5)*(volts+yaxistrim)*(1.26));
          }
  analogWrite(object, pwm);
}
