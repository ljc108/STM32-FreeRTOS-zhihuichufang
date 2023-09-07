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
#define configUSE_PREEMPTION                     1	//��������ϵͳ�ĵ��ȷ�ʽ������Ϊ1ʱ��ϵͳʹ����ռʽ���ȣ�����Ϊ0ʱ��ϵͳʹ��Э��ʽ���ȡ�
#define configSUPPORT_STATIC_ALLOCATION          0  //������Ϊ1ʱ��FreeRTOS֧��ʹ�þ�̬��ʽ�����ڴ棻Ĭ������Ϊ0��
#define configSUPPORT_DYNAMIC_ALLOCATION         1	//������Ϊ1ʱ��FreeRTOS֧��ʹ�ö�̬��ʽ�����ڴ棬Ĭ������Ϊ1��
#define configUSE_IDLE_HOOK                      0	//����ʹ��ʹ�ÿ��������Ӻ���������Ϊ1ʱ��ʹ�ܣ�����Ϊ0ʱ����ʹ�ܡ�
#define configUSE_TICK_HOOK                      0	//����ʹ��ʹ��ϵͳʱ�ӽ����жϹ��Ӻ���������Ϊ1ʱ��ʹ�ܣ�����Ϊ0ʱ����ʹ�ܡ�
#define configCPU_CLOCK_HZ                       ( SystemCoreClock )	//����ΪCPU���ں�ʱ��Ƶ�ʣ���λΪHz��
#define configTICK_RATE_HZ                       (100) //����Ϊ10ms  ��������FreeRTOSϵͳ���ĵ��ж�Ƶ�ʣ���λΪHz��
#define configMAX_PRIORITIES                     ( 56 )	//���ڶ���ϵͳ֧�ֵ�����������ȼ�����������������ȼ���ֵΪconfigMAX_PRIORITIES-1
#define configMINIMAL_STACK_SIZE                 ((uint16_t)512)	//�������ÿ��������ջ�ռ��С����λΪword��
#define configTOTAL_HEAP_SIZE                    ((size_t)(1024*10))	//���ڶ�������FreeRTOS��̬�ڴ������ڴ��С����FreeRTOS���ڴ�ѣ���λΪByte��
#define configMAX_TASK_NAME_LEN                  ( 16 )	//�������ÿ���������������ַ�����
#define configUSE_TRACE_FACILITY                 1	//����ʹ�ܿ��ӻ����ٵ��ԣ�����Ϊ1ʱ��ʹ�ܣ�����Ϊ0ʱ����ʹ�ܡ�
#define configUSE_16_BIT_TICKS                   0	//���ڶ���ϵͳ���������������ͣ�����Ϊ1ʱ����������Ϊ16λ�޷������ͣ�����Ϊ0ʱ����������Ϊ32λ�޷������͡�
#define configUSE_MUTEXES                        1	//����ʹ�ܻ����ź���������Ϊ1ʱ��ʹ�ܣ�����Ϊ0ʱ����ʹ�ܡ�
#define configQUEUE_REGISTRY_SIZE                8	//���ڶ���ע��Ķ��к��ź�������������������ڵ���ʹ�á�
#define configUSE_RECURSIVE_MUTEXES              1	//����ʹ�ܵݹ黥���ź���������Ϊ1ʱ��ʹ�ܣ�����Ϊ0ʱ����ʹ�ܡ�
#define configUSE_COUNTING_SEMAPHORES            1	//����ʹ�ܼ������ź���������Ϊ1ʱ��ʹ�ܣ�����Ϊ0ʱ����ʹ�ܡ�
#define configUSE_PORT_OPTIMISED_TASK_SELECTION  0	//FreeRTOS֧�����ַ�����ѡ����һ��Ҫִ�е����񣬷ֱ�Ϊͨ�÷��������ⷽ����
																										//����Ϊ0ʱ��ʹ��ͨ�÷�����ͨ�÷�������ȫʹ��Cʵ�ֵ�����㷨�����֧������Ӳ�������Ҳ������������ȼ���
																										//���ֵ������Ч����������ⷽ���͡�
																										//����Ϊ1ʱ��ʹ�����ⷽ�������ⷽ����Ч�������ͨ�÷����ߣ��������ⷽ��������һ�������ض��ܹ��Ļ��ָ��
																										//������ⷽ������֧������Ӳ�������Ҷ��������ȼ������ֵһ��Ҳ�����ƣ�ͨ��Ϊ32��

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES                    0	//��������Э�̣�����Ϊ1ʱ������Э�̣�����Ϊ0ʱ��������Э�̡�
#define configMAX_CO_ROUTINE_PRIORITIES          ( 2 )	//��������Э�̵�����������ȼ�������Э�̵�����������ȼ���ֵΪconfigMAX_CO_ROUTINE_PRIORITIES-1��

/* Software timer definitions. */
#define configUSE_TIMERS                         1	//�������������ʱ�����ܣ�����Ϊ1ʱ�����������ʱ�����ܣ�����Ϊ0ʱ�������������ʱ�����ܡ�
#define configTIMER_TASK_PRIORITY                ( 2 )	//�������������ʱ��������������ȼ��������������ʱ������ʱ��ϵͳ�ᴴ��һ�����ڴ��������ʱ��
																												//�������ʱ����������
#define configTIMER_QUEUE_LENGTH                 10	//���ڶ��������ʱ�����еĳ��ȣ������ʱ���Ŀ�����ֹͣ�����ٵȲ�������ͨ������ʵ�ֵġ�
#define configTIMER_TASK_STACK_DEPTH             256	//�������������ʱ�����������ջ�ռ��С�������������ʱ������ʱ��ϵͳ�ᴴ��һ�����ڴ��������ʱ����
																											//�����ʱ����������

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet            1	//�����������ȼ�
#define INCLUDE_uxTaskPriorityGet           1	//��ȡ�������ȼ�
#define INCLUDE_vTaskDelete                 1	//ɾ������
#define INCLUDE_vTaskCleanUpResources       0	//����������ȡ����������ʹ�õ���Դ
#define INCLUDE_vTaskSuspend                1	//��������
#define INCLUDE_vTaskDelayUntil             1	//���������ʱ
#define INCLUDE_vTaskDelay                  1	//������ʱ
#define INCLUDE_xTaskGetSchedulerState      1	//��ȡ���������״̬
#define INCLUDE_xTimerPendFunctionCall      1	//��������ִ�йҵ���ʱ����������
#define INCLUDE_xQueueGetMutexHolder        1	//���ڻ�ȡӵ�л��������е��߳�
#define INCLUDE_uxTaskGetStackHighWaterMark 1	//��ȡ�����ջ��ʷʣ����Сֵ
#define INCLUDE_eTaskGetState               1	//��ȡ����״̬

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
