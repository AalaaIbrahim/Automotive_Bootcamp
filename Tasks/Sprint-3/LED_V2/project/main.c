#include "Services/STD_TYPES.h"
#include "APP2/App.h"

void main(void)
{
	App2_Init();
	
	while(1)
	{
		App2();
	}
}
