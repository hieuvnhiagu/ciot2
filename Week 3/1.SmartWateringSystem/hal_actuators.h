#ifndef HAL_ACTUATORS_H
#define HAL_ACTUATORS_H

#include "config.h"

void TurnPumpOn(SystemState_t *pSystemState);

void TurnPumpOff(SystemState_t *pSystemState);

void UpdateLedState(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData);

#endif 