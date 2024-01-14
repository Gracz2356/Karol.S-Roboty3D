/* 
* Lesson 95: Control 4 DC Motor for Smart car using Motor Shield 
* this code works with Arduino UNO and Arduino Mega. 
* Wiring diagram and how to wire and connect power supply is shonw in the video.
 
  Watch full video instruction:  https://youtu.be/0XihwdulmDQ
 * Download this code from: http://robojax.com
 * 
* Written by Ahmad Shamshiri for Robojax.com on Jan 09, 2022
 * in Ajax, Ontario, Canada
  
This video is part of Arduino Step by Step Course which starts here: https://youtu.be/-6qSrDUA5a8
 

If you found this tutorial helpful, please support me so I can continue creating contents like this
and make donation using PayPal http://robojax.com/L/?id=64
  
 * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. 
 *  Library location: https://github.com/adafruit/Adafruit-Motor-Shield-library
 Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!
*/

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Robojax L293D Example");
}

void loop() {

  motor1.setSpeed( speed(50) ); //set speed for motor 1 at 50%
  motor1.run(FORWARD);//send motor 1 to Foarward rotation

  delay(2000);//wait for 2 seconds
  motor2.setSpeed( speed(100) );//set speed for motor 2 at 100%
  motor2.run(BACKWARD);//send motor 2 to Foarward rotation

  delay(2000);
  motor3.setSpeed( speed(70) );
  motor3.run(FORWARD);
  
  delay(2000);
  motor4.setSpeed( speed(90) );
  motor4.run(FORWARD);

    
  delay(2000);
  
  motor1.run(BRAKE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);   
  delay(2000);

  
  motor1.setSpeed(speed(100));
  motor1.run(BACKWARD);
  delay(2000);
  
  motor1.run(RELEASE);

  delay(1000);
}

/*
 * speed percent to speed converter
 * receives value between 0 to 100 and converts it to value between
 * 0 to 255 which are 8 bits Arduino PWM value
 * www.Robojax.com
 Watch full video instruction:  https://youtu.be/0XihwdulmDQ
 */
int  speed(int percent)
{
  return map(percent, 0, 100, 0, 255);
}

