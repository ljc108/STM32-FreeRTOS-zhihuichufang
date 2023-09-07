/* USER CODE BEGIN Header */
/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */
/* USER CODE END Header */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * These parameters and more are described within the 'configuration' section of the
 * FreeRTOS API documentation available on the FreeRTOS.org web site.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/* USER CODE BEGIN Includes */
/* Section where include file can be added */
/* USER CODE END Includes */

/* Ensure definitions are only used by the compiler, and not by the assembler. */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
  #include <stdint.h>
  extern uint32_t SystemCoreClock;
#endif
#define configUSE_PREEMPTION                     1	//用于设置系统的调度方式，设置为1时，系统使用抢占式调度；设置为0时，系统使用协程式调度。
#define configSUPPORT_STATIC_ALLOCATION          0  //当设置为1时，FreeRTOS支持使用静态方式管理内存；默认设置为0。
#define configSUPPORT_DYNAMIC_ALLOCATION         1	//当设置为1时，FreeRTOS支持使用动态方式管理内存，默认设置为1。
#define configUSE_IDLE_HOOK                      0	//用于使能使用空闲任务钩子函数，设置为1时，使能；设置为0时，不使能。
#define configUSE_TICK_HOOK                      0	//用于使能使用系统时钟节拍中断钩子函数，设置为1时，使能；设置为0时，不使能。
#define configCPU_CLOCK_HZ                       ( SystemCoreClock )	//设置为CPU的内核时钟频率，单位为Hz。
#define configTICK_RATE_HZ                       (100) //周期为10ms  用于设置FreeRTOS系统节拍的中断频率，单位为Hz。
#define configMAX_PRIORITIES                     ( 56 )	//用于定义系统支持的最大任务优先级数量，最大任务优先级数值为configMAX_PRIORITIES-1
#define configMINIMAL_STACK_SIZE                 ((uint16_t)512)	//用于设置空闲任务的栈空间大小，单位为word。
#define configTOTAL_HEAP_SIZE                    ((size_t)(1024*10))	//用于定义用于FreeRTOS动态内存管理的内存大小，即FreeRTOS的内存堆，单位为Byte。
#define configMAX_TASK_NAME_LEN                  ( 16 )	//用于设置空闲任务名的最大字符数。
#define configUSE_TRACE_FACILITY                 1	//用于使能可视化跟踪调试，设置为1时，使能；设置为0时，不使能。
#define configUSE_16_BIT_TICKS                   0	//用于定义系统节拍器的数据类型，设置为1时，数据类型为16位无符号整型；设置为0时，数据类型为32位无符号类型。
#define configUSE_MUTEXES                        1	//用于使能互斥信号量，设置为1时，使能；设置为0时，不使能。
#define configQUEUE_REGISTRY_SIZE                8	//用于定义注册的队列和信号量的最大数量，仅用于调试使用。
#define configUSE_RECURSIVE_MUTEXES              1	//用于使能递归互斥信号量，设置为1时，使能；设置为0时，不使能。
#define configUSE_COUNTING_SEMAPHORES            1	//用于使能计数型信号量，设置为1时，使能；设置为0时，不使能。
#define configUSE_PORT_OPTIMISED_TASK_SELECTION  0	//FreeRTOS支持两种方法来选择下一个要执行的任务，分别为通用方法和特殊方法。
																										//设置为0时，使用通用方法。通用方法是完全使用C实现的软件算法，因此支持所用硬件，并且不限制任务优先级的
																										//最大值，但是效率相较于特殊方法低。
																										//设置为1时，使用特殊方法。特殊方法的效率相较于通用方法高，但是特殊方法依赖于一个或多个特定架构的汇编指令
																										//因此特殊方法并不支持所有硬件，并且对任务优先级的最大值一般也有限制，通常为32。

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES                    0	//用于启用协程，设置为1时，启用协程；设置为0时，则不启用协程。
#define configMAX_CO_ROUTINE_PRIORITIES          ( 2 )	//用于设置协程的最大任务优先级数量，协程的最大任务优先级数值为configMAX_CO_ROUTINE_PRIORITIES-1。

/* Software timer definitions. */
#define configUSE_TIMERS                         1	//用于启用软件定时器功能，设置为1时，启用软件定时器功能；设置为0时，则不启用软件定时器功能。
#define configTIMER_TASK_PRIORITY                ( 2 )	//用于设置软件定时器处理任务的优先级，当启用软件定时器功能时，系统会创建一个用于处理软件定时器
																												//的软件定时器处理任务。
#define configTIMER_QUEUE_LENGTH                 10	//用于定义软件定时器队列的长度，软件定时器的开启、停止与销毁等操作都是通过队列实现的。
#define configTIMER_TASK_STACK_DEPTH             256	//用于设置软件定时器处理任务的栈空间大小，当启用软件定时器功能时，系统会创建一个用于处理软件定时器的
																											//软件定时器处理任务。

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet            1	//设置任务优先级
#define INCLUDE_uxTaskPriorityGet           1	//获取任务优先级
#define INCLUDE_vTaskDelete                 1	//删除任务
#define INCLUDE_vTaskCleanUpResources       0	//用于清理已取消的任务所使用的资源
#define INCLUDE_vTaskSuspend                1	//挂起任务
#define INCLUDE_vTaskDelayUntil             1	//任务绝对延时
#define INCLUDE_vTaskDelay                  1	//任务延时
#define INCLUDE_xTaskGetSchedulerState      1	//获取任务调度器状态
#define INCLUDE_xTimerPendFunctionCall      1	//将函数的执行挂到定时器服务任务
#define INCLUDE_xQueueGetMutexHolder        1	//用于获取拥有互斥量队列的线程
#define INCLUDE_uxTaskGetStackHighWaterMark 1	//获取任务堆栈历史剩余最小值
#define INCLUDE_eTaskGetState               1	//获取任务状态

/*
 * The CMSIS-RTOS V2 FreeRTOS wrapper is dependent on the heap implementation used
 * by the application thus the correct define need to be enabled below
 */
#define USE_FreeRTOS_HEAP_4

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
 /* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
 #define configPRIO_BITS         __NVIC_PRIO_BITS
#else
 #define configPRIO_BITS         4
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY   15

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
/* USER CODE BEGIN 1 */
#define configASSERT( x ) if ((x) == 0) {taskDISABLE_INTERRUPTS(); for( ;; );}
/* USER CODE END 1 */

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */

//
/* IMPORTANT: This define is commented when used with STM32Cube firmware, when the timebase source is SysTick,
              to prevent overwriting SysTick_Handler defined within STM32Cube HAL */

//
/* USER CODE BEGIN Defines */
/* Section where parameter definitions can be added (for instance, to override default ones in FreeRTOS.h) */
/* USER CODE END Defines */

#endif /* FREERTOS_CONFIG_H */
