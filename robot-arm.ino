#include <Servo.h>

#define joyLeftX A3
#define joyLeftY A4
#define joyRightX A5
#define joyRightY A0

Servo base;
Servo distance;
Servo claw;
Servo upDown;

int joyLeftXValue;
int joyLeftYValue;
int joyRightXValue;
int joyRightYValue;

int baseValue;
int distanceValue;
int clawValue;
int upDownValue;

void setup()
{
  pinMode(joyLeftX, INPUT);
  pinMode(joyLeftY, INPUT);
  pinMode(joyRightX, INPUT);
  pinMode(joyRightY, INPUT);

  baseValue = 0;
  distanceValue = 0;
  clawValue = 0;
  upDownValue = 0;

  base.attach(A1);
  distance.attach(9);
  claw.attach(8);
  upDown.attach(A2);

  Serial.begin(9600);
}

void loop()
{
  joyLeftXValue = analogRead(joyLeftX);
  joyLeftYValue = analogRead(joyLeftY);
  joyRightXValue = analogRead(joyRightX);
  joyRightYValue = analogRead(joyRightY);

  Serial.println(joyRightYValue);
  // // Serial.println(joyLeftYVaelue);

  if (joyLeftXValue > 800 && baseValue < 180)
  {
    baseValue += 3;
  } else if (joyLeftXValue < 1 && baseValue > 0)
  {
    baseValue -= 3;
  }

  if (joyLeftYValue > 900 && distanceValue < 180)
  {
    distanceValue += 1;
  } else if (joyLeftYValue < 100 && distanceValue > 0)
  {
    distanceValue -= 1;
  }

  if (joyRightXValue > 600 && clawValue < 180)
  {
    clawValue += 1;
  } else if (joyRightXValue < 200 && clawValue > 0)
  {
    clawValue -= 1;
  }

  if (joyRightYValue > 600 && upDownValue < 180)
  {
    upDownValue += 1;
  } else if (joyRightYValue < 200 && upDownValue > 0)
  {
    upDownValue -= 1;
  }

  Serial.println(joyRightYValue);

  base.write(baseValue);
  distance.write(distanceValue);
  upDown.write(upDownValue);
  claw.write(clawValue);
}
