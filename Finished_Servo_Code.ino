#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <DRV8835MotorShield.h>
#include <Servo.h>
DRV8835MotorShield motors;
Servo launcher;
Servo winch;
// Hayden Stubbendeck, Group F.6
// Code used to control the projectile launcher and the winch
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Dabble.begin(9600);
  launcher.attach(12);
  launcher.write(90);
  winch.attach(13);
  winch.write(90);
  //motors.setM1Speed(0);
  //motors.setM2Speed(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();

/*
  if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    motors.setM1Speed(-300);
    motors.setM2Speed(-300);
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("DOWN");
    motors.setM1Speed(300);
    motors.setM2Speed(300);
  }
*/
  if(GamePad.isCrossPressed()){
    launcher.write(120);
  }
  //
  if(GamePad.isSquarePressed()){
    winch.write(100);
  }

  if(GamePad.isTrianglePressed()){
    winch.write(80);
  }
  if(GamePad.isCirclePressed()){
    launcher.write(90);
    winch.write(90);
  }
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

