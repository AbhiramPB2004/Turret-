

#include<Servo.h>

Servo x, y;
Servo shoot;
int a = 3;
int width = 640, height = 480;  
int xpos = 90, ypos = 90;  
void setup() {

  Serial.begin(9600);
  x.attach(0); //d3
  y.attach(2); //d4

  x.write(xpos);
  y.write(ypos);
  
  shoot.attach(5);
  shoot.write(100);
}
const int anglex = 1;   
const int angley = 1;
int xvalue;
int yvalue;
void loop() {
  if (Serial.available() > 0)
  {
    int x_mid, y_mid;
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt();  
      if (Serial.read() == 'Y')
        y_mid = Serial.parseInt(); 
    }
  
    xvalue = x_mid;
    yvalue = y_mid;
    
    if(x_mid >= 300  && x_mid <= 340 && y_mid >= 220 && y_mid <=260 ){
      shoot.write(0);
      delay(50);
      shoot.write(120);
      delay(50);
    }else{
    if (x_mid > width / 2 + 30)
      xpos += anglex;
    if (x_mid < width / 2 - 30)
      xpos -= anglex;
    if (y_mid < height / 2 + 30)
      // ypos -= angle;
      ypos += angley;
    if (y_mid > height / 2 - 30)
      // ypos += angle;
      ypos -= angley;
    }


    // if the servo degree is outside its range
      if (xpos >= 180)
        xpos = 180;
      else if (xpos <= 0)
        xpos = 0;
      if (ypos >= 180)
        ypos = 180;
      else if (ypos <= 0)
        ypos = 0;

      x.write(xpos);
      y.write(ypos);    

  }
}
  // else{

  //     while(Serial.available() == 0 && xpos<180){
  //       delay(10);
  //       xpos += 1;
  //       x.write(xpos);
  //       delay(10);
  //     }
  //     if(Serial.available() == 0){
  //       xpos = 0;
  //       x.write(xpos);
  //     }

  //     }
    
  // }
