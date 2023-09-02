/* 
 * File:   hal_gpio.h
 * Author: Abdo Halem
 *
 * Created on August 25, 2023, 11:19 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section: Includes*/
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"

/* Section: Macro Declarations*/
#define BIT_MASK    (uint8)1

/* Section: Macro Function Declarations*/
#define HWREG8(_X) (*((volatile uint8 *)(_X)))

#define SET_BIT(reg, BIT_POS)    (reg |= (BIT_MASK<<BIT_POS))
#define CLEAR_BIT(reg, BIT_POS)  (reg &= ~(BIT_MASK<<BIT_POS))
#define TOGGLE_BIT(reg, BIT_POS) (reg ^= (BIT_MASK<<BIT_POS)) 
#define READ_BIT(reg, BIT_POS)   ((reg >> BIT_POS) & BIT_MASK)


/* Section: Data Type Declarations*/
typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef enum{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum{
    GPIO_LOW = 0,
    GPIO_HIGH
}logic_t;

typedef struct{
    uint8 port :3;      /* @ref port_index_t */
    uint8 pin :3;       /* @ref pin_index_t  */
    uint8 direction :1; /* @ref direction_t  */
    uint8 logic :1;     /* @ref logic_t      */
}pin_config_t;

/* Section: Software Interfaces Declarations*/
Std_Return_Type gpio_pin_initialize(const pin_config_t *_pin_config);
Std_Return_Type gpio_pin_direction_initialize(const pin_config_t *_pin_config);
Std_Return_Type gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direc_status);
Std_Return_Type gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);
Std_Return_Type gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);
Std_Return_Type gpio_pin_toggle_logic(const pin_config_t *_pin_config);

Std_Return_Type gpio_port_initialize(port_index_t port, direction_t direction, logic_t logic);
Std_Return_Type gpio_port_direction_initialize(port_index_t port, direction_t direction);
Std_Return_Type gpio_port_get_direction_status(port_index_t port, direction_t *direc_status);
Std_Return_Type gpio_port_write_logic(port_index_t port, logic_t logic);
Std_Return_Type gpio_port_read_logic(port_index_t port, logic_t *logic);
Std_Return_Type gpio_port_toggle_logic(port_index_t port);

#endif	/* HAL_GPIO_H */

