/* Driver includes */
#include "HWS_Driver/HWS_conf.h"
static const char character[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x06D, 0x7D, 0x07, 0x7F, 0x6F };

/* Priorities at which the tasks are created. */
#define task_prioritet		( tskIDLE_PRIORITY + 2 )

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "I_Vezba.h"


static mxDisp7seg_Handle myDisp;

/* Local function declaration */
static void DisplayDigit_0();

/* Local function implementation */ 
static void DisplayDigit_0() {
	static uint8_t displayValue = 0;
	mxDisp7seg_SelectDigit(myDisp, 0);
	if (displayValue == 0) {
		mxDisp7seg_SetDigit(myDisp, character[displayValue]);
		displayValue = 1;
	}
	else {
		mxDisp7seg_SetDigit(myDisp, character[displayValue]);
		displayValue = 0;
	}
}


void I_vezba(void)
{
	/* Inicijalizacija drajvera za displej */
	mxDisp7seg_Init();
	myDisp = mxDisp7seg_Open(MX7_DISPLAY_0);


	/* Kreiranje taskova */


	vTaskStartScheduler();
	while (1);
}