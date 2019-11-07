#include "khoiTao.h"

//chuyen den toa do (x,y)

void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//ham doi mau

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//ham xoa man hinh

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

//==================================== VE MAN HINH ===================================//

void draw_Wall(mayBay planes, boss boss)
{
	for (int i = 0; i <= yConsole; ++i)
	{
		gotoXY(xConsole_Left - 1, i);
		TextColor(wallColor);
		putchar(221);

		gotoXY(xConsole_Right + 1, i);
		TextColor(wallColor);
		putchar(222);
	}

	for (int i = xConsole_Left - 1; i <= xConsole_Right + 1; ++i)
	{
		gotoXY(i, yConsole + 1);
		TextColor(wallColor);
		putchar(223);
	}

	//ve hinh vat can ben thanh mau

	if (planes.level <= 1)
	{

		char a[3][3] = { {201,205,187},
						{221,'!',222},
						{200,205,188} };

		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				gotoXY(xConsole_Left - 20 + j, 2 + i);

				cout << a[i + 1][j + 1];
			}
		}
	}

	if (planes.level >= 2)
	{
		gotoXY(xConsole_Left - 20, 2);
		TextColor(2);
		cout << "Boss BUG:";
	}
	
}

//========================================== MAY BAY =========================================//

void khoiTaoMayBay(mayBay &planes)
{
	//Khoi tao hinh dang

	char a[3][3] = { { ' ', 186, ' ' },
					{205, 219, 205},
					{222, 202, 221}};

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			planes.hinhDang[i][j] = a[i][j];

	//Khoi tao toa do trung tam

	planes.td_trungtam.x = (xConsole_Left + xConsole_Right) / 2;
	planes.td_trungtam.y = yConsole - 3;

	//khoi tao mang song

	planes.life = 5;

	//khoi tao diem

	planes.scores = 0;

	//khoi tao dan

	planes.soDan = 0;

	planes.soDanDebug = 0;

	//khoi tao so dan max

	planes.max_Dan = 5;

	//khoi tao n_hiscore

	ifstream ifs("n_Hiscores.txt");

	if (!ifs.fail())
	{
		ifs >> planes.n_Hiscore;

		//thay doi so Hiscores

	}
	else
	{
		planes.n_Hiscore = 0;
	}

	ifs.close();
	
	//khoi tao level

	planes.level = 1;
	
}

void draw_Planes(mayBay planes)
{

	//ve may bay ra man hinh

	for(int i = -1; i < 2; ++i)
		for (int j = -1; j < 2; ++j)
		{
			int x = planes.td_trungtam.x + j;
			int y = planes.td_trungtam.y + i;
			gotoXY(x, y);
			TextColor(planes_Color);
			putchar(planes.hinhDang[i + 1][j + 1]);
		}

}

void del_Planes(mayBay planes)
{

	//ve may bay ra man hinh

	for (int i = -1; i < 2; ++i)
		for (int j = -1; j < 2; ++j)
		{
			int x = planes.td_trungtam.x + j;
			int y = planes.td_trungtam.y + i;
			gotoXY(x, y);
			putchar(' ');
		}
}

// ======================================== VAT CAN 1 ======================================= //

void khoiTaoVatCan(vatCan &barrier)
{

	//khoi tao hinh dang

	char a[3][3] = { {201,205,187},
					{221,'!',222},
					{200,205,188} };

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			barrier.hinhDang[i][j] = a[i][j];

	//khoi tao vi tri

	srand((unsigned)time(NULL));

	int random = (xConsole_Right - 1) - (xConsole_Left + 1);

	barrier.td_trungtam.x = rand() % random + (xConsole_Left + 1);

	barrier.td_trungtam.y = 1;
	
	//khoi tao toc do

	barrier.tocDo = barrier_speed;

	//khoi tao mau

	barrier.mau = 100;

	//khoi tao so lan cham bien

	barrier.soLanChamBien = 0;

}

void draw_barrier(vatCan barrier)
{
	//ve vat can

	for (int i = -1; i < 2; ++i)
		for (int j = -1; j < 2; ++j)
		{
			int x = barrier.td_trungtam.x + j;
			int y = barrier.td_trungtam.y + i;
			gotoXY(x, y);
			TextColor(barrier_Color);
			putchar(barrier.hinhDang[i + 1][j + 1]);
		}

	// ve mau vat can

	if (barrier.mau == 100) 
		for (int i = 0; i < 10; ++i)
		{
			gotoXY(xConsole_Left - 15 + i, 2);
			TextColor(67);
			putchar(' ');
			TextColor(7);
		}
	else if (barrier.mau == 50)
	{
		for (int i = 0; i < 5; ++i)
		{
			gotoXY(xConsole_Left - 15 + i, 2);
			TextColor(67);
			putchar(' ');
			TextColor(7);
		}
		for (int i = 5; i < 10; ++i)
		{
			gotoXY(xConsole_Left - 15 + i,2);
			TextColor(7);
			putchar(' ');
		}
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			gotoXY(xConsole_Left - 15 + i, 2);
			TextColor(7);
			putchar(' ');
		}
	}

	
}

//xoa vat can khi di chuyen 

void del_barrier(vatCan barrier)
{
	int x = barrier.td_trungtam.x - 1;
	int y = barrier.td_trungtam.y - 1;

	for (int i = 0; i < 3; ++i)
	{
		gotoXY(x++, y);
		putchar(' ');
	}

}

//xoa toan bo vat can

void remove_Barrier(vatCan barrier)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			gotoXY(barrier.td_trungtam.x + i - 1, barrier.td_trungtam.y + j - 1);
			putchar(' ');
		}
}

//==================================== BOSS ==========================================//

void khoiTaoBoss(boss &boss)
{
	boss.mau = 100;

	boss.td.x = xConsole_Left + 5;

	boss.td.y = 5;

	boss.diChuyen = Right;

	boss.dan[0].x = boss.td.x + 6;
	boss.dan[1].x = boss.td.x + 9;
	boss.dan[2].x = boss.td.x + 12;
	boss.dan[3].x = boss.td.x + 15;

	for (int i = 0; i < 4; ++i)
		boss.dan[i].y = boss.td.y + 1;
}

void draw_Boss(boss boss)
{

	gotoXY(boss.td.x, boss.td.y - 4);
	TextColor(bossColor);
	cout << " ____  __  __  ___ ";

	gotoXY(boss.td.x, boss.td.y - 3);
	TextColor(bossColor);
	cout << "(  _ \\(  )(  )/ __)";

	gotoXY(boss.td.x, boss.td.y - 2);
	TextColor(bossColor);
	cout << " ) _ < )(__)(( (_-.";

	gotoXY(boss.td.x, boss.td.y - 1);
	TextColor(bossColor);
	cout << "(____/(______)\\___/";

	gotoXY(boss.td.x, boss.td.y);
	TextColor(bossColor);
	char c = 186;
	cout << "  " << c << "     " << c << "  " << c << "    " << c;

	//ve thanh mau

	for (int i = 0; i < 20; ++i)
	{
		gotoXY(xConsole_Left - 23 + i, 4);
		TextColor(7);
		putchar(' ');
	}

	for (int i = 0; i < boss.mau / 5 ; ++i)
	{
		gotoXY(xConsole_Left - 23 + i, 4);
		TextColor(208);
		putchar(' ');
		TextColor(7);
	}

}

void del_Boss(boss boss)
{
	for (int i = 0; i < 5; ++i)
	{
		gotoXY(boss.td.x, boss.td.y - i);
		cout << "                   ";
	}
}