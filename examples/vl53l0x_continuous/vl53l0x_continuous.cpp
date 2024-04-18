#include "Adafruit_VL53L0X.h"

#include "pico/stdlib.h"
#include <stdio.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

int main(){
    stdio_init_all();
    printf("Hello, world! VL53L0X Test\n");

    if(!lox.begin()){
        printf("Failed to boot VL53L0X\n");
        while(1);
    }

    printf("VL53L0X API Continuous Ranging example\n\n");

    lox.startRangeContinuous();

    while(1){
        if(lox.isRangeComplete()){
            printf("Distance in mm: %d\n", lox.readRange());
        }
    }
}
