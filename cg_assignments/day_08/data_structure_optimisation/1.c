/* 1. You need to store the status of traffic light i.e status of Red, Green, Organge Bulb On/Off status. Define an appropriate data structure for this. */
 

#include <stdio.h>
#include <stdbool.h> 

// Define a structure to store the status of the traffic light bulbs
typedef struct {
    bool red;     
    bool green;   
    bool orange;  
} TrafficLight;

int main() {
    TrafficLight lightStatus = {true, false, false};  // Red is ON, Green and Orange are OFF
    printf("Traffic Light Status:\n");
    printf("Red Light: %s\n", lightStatus.red ? "ON" : "OFF");
    printf("Green Light: %s\n", lightStatus.green ? "ON" : "OFF");
    printf("Orange Light: %s\n", lightStatus.orange ? "ON" : "OFF");

    return 0;
}
