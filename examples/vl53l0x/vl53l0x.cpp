#include "Adafruit_VL53L0X.h"

#include "pico/stdlib.h"
#include <stdio.h>

Adafruit_VL53L0X lox;

int main(){
    stdio_init_all();
    printf("Hello, world! VL53L0X Test\n");
    if(!lox.begin()){
        while(1){
            printf("Failed to boot VL53L0X\n");
            sleep_ms(1000);
        }
    }
    printf("VL53L0X API Simple Ranging example\n\n");

    VL53L0X_RangingMeasurementData_t measure;

    printf("Reading a measurement... ");
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
    
    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
        printf("Distance (mm): %d\n", measure.RangeMilliMeter);
    } else {
        printf(" out of range\n");
    }
    
    sleep_ms(100);
}
