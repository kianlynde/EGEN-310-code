/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
// Hayden Stubbendeck, Group F.6
//code for steering, moving forward and moving backward 
#define CUSTOM_SETTINGS 
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <DRV8835MotorShield.h> 
#include <ServoTimer2.h> 
ServoTimer2 servoSteering;
DRV8835MotorShield motors;
//ServoTimer2 winch;
//ServoTimer2 launcher;

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600); //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive  servoSteering.attach(11); //Steering Ser
  servoSteering.write(1320); //corresponding to straight 
  servoSteering.attach(11);
  //launcher.attach(12);
  //launcher.write(750);
  //winch.attach(13);
  //winch.write(750);  
}

void loop() {
  
  Dabble.processInput();  
  motors.setM1Speed(0);
  motors.setM2Speed(0);           //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    motors.setM1Speed(-300);// makes the rover go forward
    motors.setM2Speed(-300);
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("DOWN");
    motors.setM1Speed(300);// makes the rover go backward 
    motors.setM2Speed(300);
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    servoSteering.write(1200);// moves servo to the left making the rover go to the left 
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    servoSteering.write(1550); // moves servo to the right making the rover go the left 
   
  }
  if (GamePad.isSquarePressed())
  {
    Serial. print("Square");
    //winch.write(140);
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    //launcher.write(90);
    //winch.write(90);
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
    //launcher.write(120);
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
    //winch.write(30);
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
     //corresponding to zero (750-2250)
    servoSteering.write(1375); //corresponding to straight
  }
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}
