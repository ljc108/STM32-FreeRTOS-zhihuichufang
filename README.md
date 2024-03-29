# STM32-FreeRTOS-zhihuichufang
## 智慧厨房
##   任务间看似是同步运行，互不干扰，其实是操作系统分时运行，只是运行的速度非常快，近似同时运行，这也是FreeRTOS最主要的特点之一！！!
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

接数据：通过中断，环形缓冲区。(**环形缓冲区就是一个数组，如buf[128],写一个后，w++；读一个后，r++。**)

ESP8266串口接收一个字节数据-->进入中断-->一个字节数据写到buffer，写完一个字节就立马退出中断-->读buffer-->读到数据

通过中断接收数据，buffer里读，如果读不到就一直阻塞，如果读到了就读一个把它返回出去，返回监听任务，后监听任务就读到一个字符加结束符的字符串，
对这个收到的字符串进行判断,是不是到末尾了，末尾是ok还是error。

###  A.硬件系统控制细节
1、感知数据有厨房温度、火焰辐射强度、co浓度、烟雾浓度和可燃气体浓度5种，为减少能耗，拟采用定时采集方式，每隔5秒采集一次数据。

2、采用自动控制方式(单片机根据用户设置的控制条件自动控制燃气法开关)，设计的参数有厨房温度、火焰辐射强度、co浓度、烟雾浓度和可燃气体浓度5种。当达到所设参数
时，STM32进行中断并执行命令。

3、采用远程控制方式，用户可以使用手机上的app进行远程控制家庭中的厨房状态。

4、采用双线程警报，让用户的手机与厨房中蜂鸣器同时报警，同时自动关闭煤气或天然气的阀门，避免灾难发生。

###  B.软件系统设计
1、基本功能
用户管理+实时监测+远程控制+设备管理

2、软件界面描述
首页界面        设备管理        个人中心

