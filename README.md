# STM32-FreeRTOS-zhihuichufang
## 智慧厨房

###  主要硬件
包括：STM32F103ZET6单片机、MQ-2烟雾传感器、MQ-4天然气传感器、MQ-7一氧化碳传感器、火焰传感、DHT11温湿度传感器、通风扇。

###  FreeRTOS移植到STM32F103ZET6
1、创建启动文件

2、创建Main文件

3、包含库函数包
###  创建FreeRTOS文件夹
在FreeRTOS原文件里Demo中找到STM32F103的keil的FreeRTOS中Config.h文件
###  RTOS配置
在启动文件中添加  
IMPORT xPortPendSVHandler(任务切换)

IMPORT xPortSysTickHandler(FreeRTOS选择SysTick作为时钟源)

IMPORT vPortSVCHandler(使能全局中断，并手动触发SVC中断后，会进入SVC的中断服务函数。**注意：SVC中断只在启动第一次任务时会调用一次，以后均不调用。**)

对应的，将74行改为   DCD  vPortSVCHandler   ,

77、78行改为    DCD     xPortPendSVHandler  , DCD     xPortSysTickHandler 

在main.c中包含一下FreeRTOS的头文件，FreeRTOS.h, Task.h, queue.h。

发数据：Keil发送到串口，串口发送到ESP8266；

接数据：通过中断，环形缓冲区。

