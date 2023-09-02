/* 
 * File:   application.h
 * Author: Abdo Halem
 *
 * Created on August 25, 2023, 11:05 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section: Includes*/
#include "ECU_Layer/initializations.h"

/* Section: Macro Declarations*/

/* Section: Macro Function Declarations*/

/* Section: Data Type Declarations*/
extern lcd_4bits_t lcd; 
extern keypad_t keypad;
extern dc_motor_t motor1;
extern dc_motor_t motor2;
extern led_t led1;
extern led_t led2;
extern led_t led3;

/* Section: Software Interfaces Declarations*/
Std_Return_Type app_initialize();

#endif	/* APPLICATION_H */

