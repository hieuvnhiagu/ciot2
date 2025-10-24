#ifndef HAL_BUTTONS_H
#define HAL_BUTTONS_H

//Trạng thái của Button 1
typedef enum {
    BUTTON1_OFF, //TẮT mode-auto = Bật mode_manual
    BUTTON1_ON //BẬT mode-auto
} Button1_t;

//Trạng thái của Button 2
typedef enum{
    BUTTON2_OFF, //Tắt chế độ tưới thủ công
    BUTTON2_ON //Bật chế độ tưới thủ công
} Button2_t;

#endif