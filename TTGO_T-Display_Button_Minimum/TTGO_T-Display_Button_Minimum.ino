#include "Button2.h"
#define BUTTON_1            35
#define BUTTON_2            0
Button2 btn1(BUTTON_1);
Button2 btn2(BUTTON_2);

int btn1Click = false;
int btn2Click = false;

void button_init()
{
    btn1.setPressedHandler([](Button2 & b) {
        btn1Click = true;      
    });
    btn2.setPressedHandler([](Button2 & b) {
        btn2Click = true;
    });
}

void button_loop()
{
    btn1.loop();
    btn2.loop();
}

void setup()
{
    delay(1000);  
    Serial.begin(9600);
    Serial.println("Start");
    button_init();
}    

void loop()
{
    button_loop();
    if(btn1Click){
        Serial.println("Button1 Press");
        btn1Click = false;
    }
        if(btn2Click){
        Serial.println("Button2 Press");
        btn2Click = false;              
    }    
}
