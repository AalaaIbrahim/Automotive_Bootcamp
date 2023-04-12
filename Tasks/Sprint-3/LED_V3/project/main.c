#include "Services/STD_TYPES.h"
#include "APP3/App.h"

void main(void)
{
	App3_Init();
	
	while(1)
	{
		App3();
	}
}
