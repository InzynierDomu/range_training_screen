#include "Havy_fire.h"

void Havy_fire::onOpen()
{
    Serial.println("hv open");
}
void Havy_fire::onStart() 
{
    Serial.println("hv start");
}

void Havy_fire::onStop() 
{
    Serial.println("hv stop");
}

void Havy_fire::onClose() 
{
    Serial.println("hv Close");
}

void Havy_fire::onUpdate() 
{
    Serial.println("hv update");
}

void Havy_fire::drawUI() 
{
    Serial.println("hv draw ui");
}