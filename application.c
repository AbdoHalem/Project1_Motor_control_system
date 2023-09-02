/* 
 * File:   application.c
 * Author: Abdo Halem
 * Project: Controlling dc motors using temperature sensor
 * Created on August 25, 2023, 11:04 PM
 */

#include "application.h"

uint8 modes = 'c';          
uint8 motor1_mode = 'c';
uint8 motor2_mode = 'c';

int main() {
    Std_Return_Type ret = E_OK;
    ret = app_initialize();
    while(1){
        modes = 'c'; motor1_mode = 'c'; motor2_mode = 'c';          //Initialization modes
        ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
        ret &= lcd_4bit_send_command(&lcd, LCD_RETURN_HOME); __delay_ms(200);
        /* Delay 0.2 second to isolate the click between each two consecutive keypad values */
        ret &= lcd_4bit_send_string_data(&lcd, "Select motors mode:"); __delay_ms(1500);
        ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
        ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 1, "1- Motor1 ON");
        ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 1, "2- Motor2 ON");
        ret &= lcd_4bit_send_string_data_pos(&lcd, 3, 1, "3- BOTH motors ON");
        ret &= lcd_4bit_send_string_data_pos(&lcd, 4, 1, "4- Stop both motors");
        while('c' == modes){
            ret &= keypad_get_button(&keypad, &modes);
        }
        
        if('1' == modes){
            ret &= dc_motor_stop(&motor2); ret &= led_turn_off(&led2); ret &= led_turn_off(&led3);
            ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY); __delay_ms(200);
            ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 1,"Select M1 direction:");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 1, "1- CW direction ");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 3, 1, "2- CCW direction");
            while('c' == motor1_mode){
                ret &= keypad_get_button(&keypad, &motor1_mode);
            }
            switch(motor1_mode){
                case '1' :
                    ret &= dc_motor_turn_right(&motor1); break;
                case '2' :
                    ret &= dc_motor_turn_left(&motor1); break;
                default :
                    ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
                    ret &= lcd_4bit_send_command(&lcd, LCD_RETURN_HOME);
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 5, "Invalid mode!");
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 3, "Enter valid mode");
                   __delay_ms(2000); break;
            }
            ret &= led_turn_on(&led1);
        }
        
        else if('2' == modes){
            ret &= dc_motor_stop(&motor1); ret &= led_turn_off(&led1); ret &= led_turn_off(&led3);
            ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY); __delay_ms(200);
            ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 1,"Select M2 direction:");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 1, "1- CW direction ");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 3, 1, "2- CCW direction");
            while('c' == motor2_mode){
                ret &= keypad_get_button(&keypad, &motor2_mode);
            }
            switch(motor2_mode){
                case '1' :
                    ret &= dc_motor_turn_right(&motor2); break;
                case '2' :
                    ret &= dc_motor_turn_left(&motor2); break;
                default :
                    ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
                    ret &= lcd_4bit_send_command(&lcd, LCD_RETURN_HOME);
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 5, "Invalid mode!");
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 3, "Enter valid mode");
                    modes = 'c'; __delay_ms(2000); break;
            }
            ret &= led_turn_on(&led2);
        }
        
        else if('3' == modes){
            ret &= led_turn_off(&led1); ret &= led_turn_off(&led2);
            ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY); __delay_ms(200);
            ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 1,"Select M1 direction:");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 1, "1- CW direction ");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 3, 1, "2- CCW direction");
            while('c' == motor1_mode){
                ret &= keypad_get_button(&keypad, &motor1_mode);
            }
            switch(motor1_mode){
                case '1' :
                    ret &= dc_motor_turn_right(&motor1); break;
                case '2' :
                    ret &= dc_motor_turn_left(&motor1); break;
                default :
                    ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
                    ret &= lcd_4bit_send_command(&lcd, LCD_RETURN_HOME);
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 5, "Invalid mode!");
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 3, "Enter valid mode");
                    modes = 'c'; __delay_ms(2000); break;
            }
            ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY); __delay_ms(200);
            ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 1,"Select M2 direction:");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 1, "1- CW direction ");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 3, 1, "2- CCW direction");
            while('c' == motor2_mode){
                ret &= keypad_get_button(&keypad, &motor2_mode);
            }
            switch(motor2_mode){
                case '1' :
                    ret &= dc_motor_turn_right(&motor2); break;
                case '2' :
                    ret &= dc_motor_turn_left(&motor2); break;
                default :
                    ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
                    ret &= lcd_4bit_send_command(&lcd, LCD_RETURN_HOME);
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 5, "Invalid mode!");
                    ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 3, "Enter valid mode");
                    modes = 'c'; __delay_ms(2000); break;
            }
            ret &= led_turn_on(&led3);
        }
        
        else if('4' == modes){
            ret &= dc_motor_stop(&motor1); ret &= dc_motor_stop(&motor2);
            ret &= led_turn_off(&led1); ret &= led_turn_off(&led2); ret &= led_turn_off(&led3);
        }
        
        else{
            ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
            ret &= lcd_4bit_send_command(&lcd, LCD_RETURN_HOME);
            ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 5, "Invalid mode!");
            ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 3, "Enter valid mode");
            modes = 'c'; __delay_ms(2000);
        }
        ret &= lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
        ret &= lcd_4bit_send_string_data_pos(&lcd, 2, 1, "Click 0 to main menu");
        while('0' != modes){
            ret &= keypad_get_button(&keypad, &modes);
        }
    }
    return (EXIT_SUCCESS);
}

Std_Return_Type app_initialize(){
    Std_Return_Type ret = E_OK;
    ret &= ecu_initialize();
    ret &= lcd_4bit_send_string_data_pos(&lcd, 1, 5, "Welcome Abdo");
    __delay_ms(1500);
    return ret;
}
