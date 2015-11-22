#include <Stepper.h>  
#define STEPS 200


Stepper stepper(STEPS, 8,9,10,11);  
     



      
void setup()  
{  
   
  stepper.setSpeed(140);    
 
}  

void loop()  
{  
 
  stepper.step(-240);//正8圈  

    delay(500);
     
    stepper.step(240);

    delay(500);
}  
