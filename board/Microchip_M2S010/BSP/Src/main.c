#include "main.h"

#define APPLICATION_TASK_STK_SIZE           1024
extern void application_entry(void *arg);

osThreadDef(application_entry, osPriorityNormal, 1, APPLICATION_TASK_STK_SIZE);

__weak void application_entry(void *arg)
{
    while (1) {
        printf("This is a demo task,please use your task entry!\r\n");
        tos_task_delay(1000);
    }
}

int main(void)
{
    /* peripheral initial*/
    board_init();
    
    printf("Hello TencentOS-tiny! By Microchip SmartFusion2 Family FPGA����M2S010.\r\n");
    
    osKernelInitialize(); // TOS Tiny kernel initialize
    osThreadCreate(osThread(application_entry), NULL); // Create TOS Tiny task
    osKernelStart();      // Start TOS Tiny
}
