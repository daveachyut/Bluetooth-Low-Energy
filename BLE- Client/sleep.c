#include "sleep.h"
#include "em_emu.h"
#include "em_core.h"
#include "cmu.h"

void blockSleepMode(sleepstate_enum minimumMode)
{
	CORE_ATOMIC_IRQ_DISABLE();
	sleep_enter[minimumMode]++;
	CORE_ATOMIC_IRQ_ENABLE();

}
void unblockSleepMode(sleepstate_enum minimumMode)
{

	CORE_ATOMIC_IRQ_DISABLE();
	if (sleep_enter[minimumMode]>0)
	{
		sleep_enter[minimumMode]--;

	}
	CORE_ATOMIC_IRQ_ENABLE();

}

void sleep(void)	//sleep routine
{
	if (sleep_enter[0]>0)
	{
		return;
	}
	else if (sleep_enter[1]>0)
		{
			EMU_EnterEM1();
		}
	else if (sleep_enter[2]>0)
		{
			EMU_EnterEM2(true);
		}
	else
	{
		EMU_EnterEM3(true);
	}
	return;

}
