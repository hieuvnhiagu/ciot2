#include <stdio.h>
#include "config.h"
#include "hal_actuators.h"
#include "hal_sensors.h"
#include "hal_buttons.h"
#include "spws_controller.h"
#include <windows.h>

//1.1.Thiết lập các giá trị mặc định cho SystemSettings_t.
void System_Init(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData){
    //Khởi tạo SystemState
    //1.2.Đặt hệ thống vào trạng thái ban đầu: MODE_AUTO, bơm PUMP_OFF
    pSystemState->currentMode = MODE_AUTO;
    pSystemState->pumpState = PUMP_OFF;
    pSystemState->ledState = LED_NORMAL;
    pSystemState->wateringTimeCounter = 0;
    pSystemState->sensorCheckCounter = 0;

    //Khởi tạo SystemSettings
    pSystemSettings->minMoistureThreshold = 5; 
    pSystemSettings->maxMoistureThreshold = 99; 
    pSystemSettings->maxWateringDuration_s = 10;  //Thời gian tưới lớn nhất cho AUTO_MODE là 10(s)
    pSystemSettings->sensorReadInterval_s = 1000; //Chu kỳ 1000ms = 1s 
    pSystemSettings->manualWateringDuration_s = 5; //Thời gian tưới lớn nhất cho MANUAL_MODE là 5(s)
    
    //Khởi tạo SensorData
    pSensorData->airTemperatureCelsius = 20;
    pSensorData->soilMoisturePercent = 0;
};

int main(){
    SystemSettings_t SystemSettings;
    SystemState_t SystemState;
    SensorData_t SensorData;
    SystemSettings_t *pSystemSettings = &SystemSettings;
    SystemState_t *pSystemState = &SystemState;
    SensorData_t *pSensorData = &SensorData;

    System_Init(pSystemSettings, pSystemState, pSensorData);


    int count = 0;
    int Button1 = BUTTON1_ON; 
    int Button2 = BUTTON2_OFF;
    int countButton1 =0;
    while(1){
        //0. Đếm số chu kỳ Sensor Interval và thời gian thực (s)
        printf("Sensor Interval lan thu %d; Thoi gian thuc(s): %d\n",count, (count*pSystemSettings->sensorReadInterval_s/1000));


        //2.1.Đọc giá trị cảm biến độ ẩm và nhiệt độ theo sensorReadInterval_s.
        pSensorData->airTemperatureCelsius = ReadAirTemperature();
        pSensorData->soilMoisturePercent = ReadSoilMoisture();

        Button1 = ReadButton1();
        Button2 = ReadButton1();
        printf("Do am: %.2f, Nhiet do: %.2f\n",pSensorData->soilMoisturePercent, pSensorData->airTemperatureCelsius);


        //2. Từ các nút nhấn và dữ liệu từ cảm biến -> cập nhật SystemState và LED
        //2.1 Cập nhật System State
        if (Button1 == BUTTON1_ON && countButton1 %2==0){
            pSystemState->currentMode = MODE_AUTO; //Nếu ấn button 1 thì ra mode_auto
            countButton1++;
        }
        else if(Button1 == BUTTON1_ON && countButton1 %2 ){
            pSystemState->currentMode = MODE_MANUAL; //Nếu không ấn button 1 thì ra mode_manual
            countButton1++;
        }

        //In ra trang thai cua PUMP
        switch (pSystemState->pumpState){
            case PUMP_ON:
                printf("3. Bom BAT\n");
                break;
            case PUMP_OFF:
                printf("3. Bom TAT\n");
                break;
        }

        //Cập nhật LED
        UpdateLedState(pSystemSettings, pSystemState, pSensorData); //Update LED

        //Dựa vào mode hiện tại và nút nhấn để điều khiển tưới
        if (pSystemState->currentMode == MODE_AUTO){
            SPWS_RunAutoMode(pSystemSettings, pSystemState, pSensorData);
            printf("2. Dang chay mode auto \n");
        }
        else if (pSystemState->currentMode == MODE_MANUAL){
            SPWS_RunManualMode(pSystemSettings, pSystemState, pSensorData, &Button2);
            printf("2. Dang chay mode manual\n");
        };

        Sleep(pSystemSettings->sensorReadInterval_s); //Cho delay một khoảng thời gian là sensorReadInterval_s
        count++; //Tăng biến điếm cho vòng lặp tổng
    }

    return 0;
}

