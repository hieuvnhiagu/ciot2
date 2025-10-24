#include <stdio.h>
#include "config.h"

//Bật bơm
void TurnPumpOn(SystemState_t *pSystemState){
    pSystemState->pumpState = PUMP_ON; 
};

//Tắt bơm
void TurnPumpOff(SystemState_t *pSystemState){
    pSystemState -> pumpState = PUMP_OFF;
};

//Update LED
void UpdateLedState(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData) {
    if (pSystemState->pumpState == PUMP_ON) {
        pSystemState->ledState = LED_WATERING; //Ưu tiên cao nhất: khi bơm bật thì LED vàng
        printf("1. LED vang - Dang tuoi\n");
    } else if (pSensorData->soilMoisturePercent < pSystemSettings->minMoistureThreshold) {
        pSystemState->ledState = LED_LOW_MOISTURE_ALERT; //Báo độ ẩm thấp hoặc ERROR
        printf("1. LED do - Do am thap hoac ERROR\n");
    } else {
        pSystemState->ledState = LED_NORMAL; //Trạng thái chờ hoặc bình thường
        printf("1. LED xanh - Trang thai cho\n");
    }
};