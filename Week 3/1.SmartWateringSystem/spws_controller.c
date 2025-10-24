#include <stdio.h>
#include "config.h"
#include "hal_actuators.h"

void SPWS_RunAutoMode(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData){
    switch (pSystemState->pumpState){
        case PUMP_OFF:
            if (pSensorData->soilMoisturePercent < pSystemSettings->minMoistureThreshold) 
              {
                TurnPumpOn(pSystemState);
                pSystemState->wateringTimeCounter = 0;
              };
            break;
        case PUMP_ON:
            pSystemState->wateringTimeCounter++;
            if ((pSensorData->soilMoisturePercent >= pSystemSettings->maxMoistureThreshold) || (pSystemState->wateringTimeCounter >= pSystemSettings->maxWateringDuration_s))
              {
                TurnPumpOff(pSystemState);
              };
            break;  
    };
};

void SPWS_RunManualMode(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData,int *Button2){
    if(pSystemState->pumpState == PUMP_ON){
        pSystemState->wateringTimeCounter++;
        if (pSystemState->wateringTimeCounter >= pSystemSettings->manualWateringDuration_s){
            TurnPumpOff(pSystemState);
        };
    };

    if ((pSystemState->pumpState == PUMP_OFF)  && (*Button2 == BUTTON2_ON)){
        TurnPumpOn(pSystemState);
        pSystemState->wateringTimeCounter = 0; 
        *Button2 = BUTTON2_OFF;
    };    
};

