#ifndef CONFIG_H      
#define CONFIG_H      

#include "hal_buttons.h"
// Chế độ hoạt động của hệ thống
typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} SystemMode_t;

// Trạng thái của bơm nước
typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState_t;

//Trạng thái của đèn LED
typedef enum {
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LedState_t;

// Cấu trúc lưu trữ dữ liệu đọc từ cảm biến
typedef struct {
    float soilMoisturePercent;
    float airTemperatureCelsius;
} SensorData_t;

//Cấu trúc lưu trữ các thông số cài đặt của hệ thống
typedef struct {
    float minMoistureThreshold; //Ngưỡng độ ẩm tối thiểu để bắt đầu tưới
    float maxMoistureThreshold; // Ngưỡng độ ẩm tôi đa để bắt đầu tưới
    unsigned int maxWateringDuration_s; //Thời gian tưới tối đa (giây)
    unsigned int sensorReadInterval_s; // Chu kỳ đọc cảm biến (giây)
    unsigned int manualWateringDuration_s; //Thời gian tưới thủ công (giây)
} SystemSettings_t;

//Cấu trúc quản lý trạng thái động của toàn bộ hệ thống
typedef struct{
    SystemMode_t currentMode;
    PumpState_t pumpState;
    LedState_t ledState;
    unsigned int wateringTimeCounter;
    unsigned int sensorCheckCounter;
} SystemState_t;


#endif