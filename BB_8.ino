#include <Servo.h>
#include <SoftwareSerial.h>
#include <AFMotor.h> 

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 

char command;
Servo servoMotor; 
int servoAngle = 90;

void setup() 
{
  Serial.begin(9600); 
  servoMotor.attach(9); 
  servoMotor.write(servoAngle);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    command = Serial.read();
  
  switch (command) 
   {
    case 'F': // Move forward
      moveForward();
      break;
    case 'B': // Move backward
      moveBackward();
      break;
    case 'L': // Turn left
      turnLeft();
      break;
    case 'R': // Turn right
      turnRight();
      break;
    case 'S': // Stop
      stopCar();
      break;
    default:
    Servopos(command); // Handle servo angle command
      break;
    }
  }   
}

void moveForward() 
 {
  motor1.setSpeed(255); 
  motor2.setSpeed(255);
  motor1.run(FORWARD); // Rotate motor 1 forward
  motor2.run(FORWARD); // Rotate motor 2 forward

 }

void moveBackward() 
 {
  motor1.setSpeed(255); 
  motor2.setSpeed(255);
  motor1.run(BACKWARD); // Rotate motor 1 backward
  motor2.run(BACKWARD); // Rotate motor 2 backward
 }

void turnLeft()
 {
  motor1.setSpeed(150); 
  motor2.setSpeed(150);
  motor1.run(BACKWARD); // Rotate motor 1 backward
  motor2.run(FORWARD); // Rotate motor 2 forward
 }

void turnRight() 
 {
  motor1.setSpeed(150); 
  motor2.setSpeed(150);
  motor1.run(FORWARD); // Rotate motor 1 forward
  motor2.run(BACKWARD); // Rotate motor 2 backward
 }

void stopCar() 
 {
  motor1.run(RELEASE); // Release motor 1 to stop
  motor2.run(RELEASE); // Release motor 2 to stop
 }

void Servopos(char command) 
 {
  int angleValue = command - '0'; 
  if (angleValue >= 0 && angleValue <= 180) 
   {
    servoAngle = angleValue; 
    servoMotor.write(servoAngle); 
   }
  }
