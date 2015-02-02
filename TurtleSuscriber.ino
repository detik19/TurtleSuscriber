/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <turtlesim/Velocity.h>

ros::NodeHandle  nh;

void messageCb( const turtlesim::Velocity& vel){
  if (vel.linear==2.0){
    digitalWrite(13, HIGH);   // blink the led
  }else
  {
    digitalWrite(13, LOW);
  }
    
  
}

ros::Subscriber<turtlesim::Velocity> sub("turtle1/command_velocity", &messageCb );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

