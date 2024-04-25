#include "Pico_VL53L0X.h"

#include "pico/stdlib.h"
#include <stdio.h>

Pico_VL53L0X lox = Pico_VL53L0X();

int main(){
    stdio_init_all();
    printf("Hello, world! VL53L0X Test\n");
    sleep_ms(5000);

    if(!lox.begin()){
        while(1){
            printf("Failed to boot VL53L0X\n");
            sleep_ms(1000);
        };
    }

    printf("VL53L0X API Continuous Ranging example\n\n");

    lox.startRangeContinuous();

    while(1){
        if(lox.isRangeComplete()){
            printf("Distance in mm: %d\n", lox.readRange());
        }
    }
}
