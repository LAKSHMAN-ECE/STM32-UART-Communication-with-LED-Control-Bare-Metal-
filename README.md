# STM32-UART-Communication-with-LED-Control-Bare-Metal-Programming 
Implements UART communication on STM32 using direct register access. Receives user input from a serial monitor via USART2 and controls an LED in real time based on the input.

 **Overview**  

This project demonstrates bare-metal UART communication on an STM32 microcontroller without using HAL libraries.  
It enables serial communication via USART2 and controls an LED based on user input from a serial terminal.  
Type 'a' → LED turns ON  
Any other character → LED turns OFF  
This project is ideal for understanding register-level programming, peripheral configuration, and UART communication.  
  
 **Hardware Requirements**:  
STM32 Development Board (e.g., STM32F401CCU6)  
USB to Serial Converter / ST-Link  

 **Software Requirements**:  
     STM32CubeIDE  
     Serial Terminal  
       
 **Project Flow**   
Enable clocks for GPIOA, GPIOC, and USART2  
Configure PA2 (TX) and PA3 (RX) as alternate function  
Map USART2 to AF7  
Set baud rate (9600 for 16 MHz clock)  
Enable USART TX and RX  
Configure PC13 as output (LED)  
Wait for user input from serial terminal  
Control LED based on received character  
  

 **Key Concepts Used**  
Register-level programming  
AHB1 & APB1 clock control  
GPIO configuration  
Alternate function mapping  
USART communication  
Serial input handling  


