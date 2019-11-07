#include "display.h"

int main()
{
	mayBay planes;

	vatCan barrier;

	vatPham vp;

	boss boss;

	PlaySound(TEXT("BackGroud_Music.wma"), NULL, SND_ASYNC);

	display(planes, barrier, vp, boss);

	return 0;
}