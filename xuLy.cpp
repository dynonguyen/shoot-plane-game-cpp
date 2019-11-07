#include "xuLy.h"
#include "display.h"

//ham an con tro


void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

//===== XU LY VAT CAN =======//

int capbac = 0;

void xuLyVatCan(vatCan &barrier, mayBay &planes)
{

	del_barrier(barrier);

	//vat can di xuong

	barrier.td_trungtam.y++;

	draw_barrier(barrier);

	Sleep(barrier.tocDo);

	//cham bien thi khoi tao lai vi tri

	if (barrier.td_trungtam.y >= yConsole - 1)
	{

		++barrier.soLanChamBien;

		//tru mang song

		if (barrier.soLanChamBien == 3)
		{
			--planes.life;
			barrier.soLanChamBien = 0;
		}

		//xoa barrier cu

		remove_Barrier(barrier);

		//khoi tao vi tri moi

		srand((unsigned)time(NULL));

		int random = (xConsole_Right - 2) - (xConsole_Left + 2);

		barrier.td_trungtam.x = rand() % random + (xConsole_Left + 2);

		barrier.td_trungtam.y = 1;

		barrier.mau = 100;

	}
}

//========================== XU LY MAY BAY =======================//

void xuLyMayBay(mayBay &planes, vatCan &barrier, vatPham &vp, boss &boss)
{

	//Dieu khien may bay

	if (!_kbhit())
		draw_Planes(planes);
	else
	{
		char key = _getch();

		switch (key)
		{

		case 'w': case 'W': case 72:
		{
			if (planes.td_trungtam.y > 2)
			{

				del_Planes(planes);

				planes.td_trungtam.y -= 2;

				draw_Planes(planes);

			}
			break;
		}

		case 's': case 'S': case 80:
		{
			if (planes.td_trungtam.y <= yConsole - 3)
			{

				del_Planes(planes);

				planes.td_trungtam.y += 2;

				draw_Planes(planes);

			}
			break;
		}

		case 'a': case 'A': case 75:
		{
			if (planes.td_trungtam.x > xConsole_Left + 2)
			{

				del_Planes(planes);

				planes.td_trungtam.x -= 2;

				draw_Planes(planes);

			}
			break;
		}

		case 'd': case 'D': case 77:
		{
			if (planes.td_trungtam.x < xConsole_Right - 2)
			{

				del_Planes(planes);

				planes.td_trungtam.x += 2;

				draw_Planes(planes);

			}
			break;
		}
		case 32:
		{
			if (planes.soDan > 0)
				PlaySound(TEXT("Shoot_Music"), NULL, SND_ASYNC);

			if (planes.soDan < planes.max_Dan)
			{
				++planes.soDan;
				planes.dan[planes.soDan - 1].x = planes.td_trungtam.x;
				planes.dan[planes.soDan - 1].y = planes.td_trungtam.y - 2;
			}
			break;
		}
		case 'E': case 'e':
		{
			if (vp.power_laser > 0)
			{
				PlaySound(TEXT("Lazer_Music"), NULL, SND_ASYNC);
				xuLyDanLaser(planes, barrier, vp, boss);
			}
			break;
		}

		case 'X': case 'x':
		{
			if (planes.level == 2 && planes.soDanDebug == 0)
			{
				planes.soDanDebug = 1;
				planes.danDebug.x = planes.td_trungtam.x;
				planes.danDebug.y = planes.td_trungtam.y - 1;

			}
			break;
		}

		case 'Q': case 'q':
		{
			system("cls");

			gotoXY(30, 15);

			cout << "< Tam dung. Nhan phim bat ki de tiep tuc ! >";

			_getch();

			system("cls");

			draw_Wall(planes, boss);

			break;
		}

		}
	}

}

// ========================== CAC XU LY KHAC ===================== //

void xuLyVaCham(mayBay &planes, vatCan &barrier)
{

	//khoang cach tu may bay den vat can

	int dx = abs(barrier.td_trungtam.x - planes.td_trungtam.x);

	int dy = abs(barrier.td_trungtam.y - planes.td_trungtam.y);

	if (dx < 3 && dy < 3)
	{
		PlaySound(TEXT("BarrierGoOff"), NULL, SND_ASYNC);

		--planes.life;

		//xoa vat can tai vi tri va cham

		remove_Barrier(barrier);

		//khoi tao lai vi tri moi

		srand((unsigned)time(NULL));

		int random = (xConsole_Right - 2) - (xConsole_Left + 2);

		barrier.td_trungtam.x = rand() % random + (xConsole_Left + 2);

		barrier.td_trungtam.y = 1;

		barrier.mau = 100;
	}

}

//ham hien thi khac

void hienThi(mayBay planes, vatPham vp)
{
	srand((unsigned)time(NULL));

	//hien thi ten 

	gotoXY(xConsole_Right + 3, 1);
	TextColor(rand() % 14 + 1);
	cout << "Name: " << planes.name;

	//hien thi diem

	gotoXY(xConsole_Right + 3, 3);
	TextColor(rand() % 14 + 1);
	cout << "Score: " << planes.scores;

	//hien thi mang song

	gotoXY(xConsole_Right + 3, 5);
	TextColor(rand() % 14 + 1);
	cout << "Life  : " << planes.life;
	gotoXY(xConsole_Right + 8, 5);
	putchar(3);

	//hien thi level

	gotoXY(xConsole_Right + 3, 7);
	TextColor(rand() % 14 + 1);
	cout << "Level: " << planes.level + capbac;

	if (planes.level == 2)
	{
		//xu li so dan
		gotoXY(xConsole_Right + 3, yConsole - 11);
		TextColor(rand() % 14 + 1);
		cout << "Nang luong Debug: ";

		if (planes.soDanDebug == 0)
		{
			gotoXY(xConsole_Right + 3, yConsole - 10);
			cout << "Nhan X de kich hoat !";
		}
		else
		{
			gotoXY(xConsole_Right + 3, yConsole - 10);
			cout << "Khong du nang luong !!";
		}
	}

	gotoXY(xConsole_Right + 3, yConsole - 8);
	TextColor(rand() % 14 + 1);
	cout << "Nang luong: ";

	gotoXY(xConsole_Right + 3, yConsole - 6);
	for (int i = 0; i < planes.max_Dan; i++)
		putchar('  ');

	gotoXY(xConsole_Right + 3, yConsole - 6);
	TextColor(rand() % 14 + 1);
	for (int i = 0; i < planes.max_Dan - planes.soDan; i++)
		cout << "*";

	//hien thi nang luog laser

	gotoXY(xConsole_Right + 3, yConsole - 4);
	cout << "Nang Luong Laser: ";

	for (int i = 0; i < max_Laser; ++i)
	{
		gotoXY(xConsole_Right + 3 + i, yConsole - 2);
		TextColor(7);
		putchar('  ');
	}


	for (int i = 0; i < vp.power_laser; ++i)
	{
		gotoXY(xConsole_Right + 3 + i, yConsole - 2);
		TextColor(176);
		putchar('  ');
		TextColor(7);
	}

}

//xu ly tang diem, tang mang.....

void thaoTac(mayBay &planes, vatCan barrier, vatPham &vp, boss &boss)
{
	//tang diem
	if (planes.level == 1)
	{
		if (barrier.td_trungtam.y >= yConsole - 2)
			if (planes.scores >= 100)
				planes.scores -= 100;
	}

	//ket thuc game

	if (planes.life == 0)
	{

		PlaySound(TEXT("Game_Over"), NULL, SND_ASYNC);

		//ghi lai so luong hiscores

		if (planes.n_Hiscore < 11)
		{
			ofstream ofs("n_Hiscores.txt");

			ofs << planes.n_Hiscore + 1 << endl;

			ofs.close();
		}

		//luu diem cao
		out_Hiscores(planes);

		system("cls");
		gotoXY((xConsole_Left + xConsole_Right) / 2 + 2, yConsole / 2 + 5);
		cout << "GAME OVER.";

		gotoXY((xConsole_Left + xConsole_Right) / 2 - 15, yConsole / 2 + 7);
		TextColor(rand() % 14 + 1);
		cout << "< Nhan Enter de choi lai. Nhan Esc de thoat >";

		char key = _getch();

		while (key != 13 || key != 27)
		{
			if (key == 13)
			{
				system("cls");
				display(planes, barrier, vp, boss);
			}
			if (key == 27)
				exit(0);

			if (key != 13 || key != 27)
				key = _getch();
		}

	}

	//chien thang

	if (planes.level == 2 && boss.mau <= 0)
	{

		PlaySound(TEXT("Boss_die"), NULL, SND_ASYNC);

		planes.scores += 1000;

		//ghi lai so luong hiscores

		if (planes.n_Hiscore < 11)
		{
			ofstream ofs("n_Hiscores.txt");

			ofs << planes.n_Hiscore + 1 << endl;

			ofs.close();
		}

		//luu diem cao
		out_Hiscores(planes);

		system("cls");
		gotoXY((xConsole_Left + xConsole_Right) / 2 + 4, yConsole / 2 + 5);
		cout << "YOU WIN.";

		gotoXY((xConsole_Left + xConsole_Right) / 2 - 15, yConsole / 2 + 7);
		TextColor(rand() % 14 + 1);
		cout << "< Nhan Enter de choi lai. Nhan Esc de thoat >";

		char key = _getch();

		while (key != 13 || key != 27)
		{
			if (key == 13)
			{
				system("cls");
				display(planes, barrier, vp, boss);
			}
			if (key == 27)
				exit(0);

			if (key != 13 || key != 27)
				key = _getch();
		}

	}


	//tang level
	if (planes.scores % 1000 == 0 && planes.scores > 0)
	{
		barrier.tocDo -= 5;
		capbac = planes.scores / 1000;
		if (planes.scores / 1000 != 6)
			planes.life = 5;
	}


	if (planes.scores >= 6000)
		planes.level = 2;
}

//Xu ly dan

void xulyDan(mayBay &planes, vatCan &barrier, boss &boss)
{

	//hien thi dan

	for (int i = 0; i < planes.soDan; i++)
	{
		--planes.dan[i].y;
		gotoXY(planes.dan[i].x, planes.dan[i].y);
		putchar('*');
		gotoXY(planes.dan[i].x, planes.dan[i].y + 1);
		putchar(' ');
	}

	//xoa dan cu di

	for (int i = 0; i < planes.soDan; i++)
	{
		if (planes.dan[i].y < 1)
		{
			gotoXY(planes.dan[i].x, planes.dan[i].y);
			putchar(' ');
			for (int j = i; j < planes.soDan - 1; j++)
			{
				planes.dan[j].x = planes.dan[j + 1].x;
				planes.dan[j].y = planes.dan[j + 1].y;
			}
			--planes.soDan;
		}
	}

	//dan cham vat can

	if (planes.level == 1)
	{
		for (int i = 0; i < planes.soDan; i++)
		{
			int dx = abs(planes.dan[i].x - barrier.td_trungtam.x);

			if ((planes.dan[i].y <= barrier.td_trungtam.y + 1) && (dx <= 1))
			{
				//tru mau vat can

				barrier.mau -= 50;

				//xoa dan

				gotoXY(planes.dan[i].x, planes.dan[i].y);
				putchar(' ');

				for (int j = i; j < planes.soDan - 1; j++)
				{
					planes.dan[j].x = planes.dan[j + 1].x;
					planes.dan[j].y = planes.dan[j + 1].y;
				}

				--planes.soDan;
				//xoa vat can, khoi tao lai

				if (barrier.mau == 0)
				{
					remove_Barrier(barrier);

					//khoi tao lai vat can

					srand((unsigned)time(NULL));

					int random = (xConsole_Right - 1) - (xConsole_Left + 1);

					barrier.td_trungtam.x = rand() % random + (xConsole_Left + 1);

					barrier.td_trungtam.y = 1;

					barrier.mau = 100;

					draw_barrier(barrier);

					//tang diem

					planes.scores += 100;
				}
			}
		}
	}
	else if (planes.level == 2)
	{
		for (int i = 0; i < planes.soDan; ++i)
		{
			int dx = abs(planes.dan[i].x - boss.td.x);

			if ((planes.dan[i].y <= boss.td.y) && dx <= 12 && dx >= 6)
			{
				boss.mau--;
				gotoXY(planes.dan[i].x, planes.dan[i].y);
				putchar(' ');
			}
		}

	}

}

void khoiTaoDanLaser(vatPham &vp)
{
	vp.power_laser = 5;
}

void xuLyDanLaser(mayBay &planes, vatCan &barrier, vatPham &vp, boss &boss)
{
	//tru nang nang luong

	--vp.power_laser;

	//Ve Duong dan ra

	for (int i = planes.td_trungtam.y - 2; i > 0; i--)
	{

		gotoXY(planes.td_trungtam.x, i);

		TextColor(176);

		cout << " ";

		if (planes.td_trungtam.x + 1 != xConsole_Right)
		{

			gotoXY(planes.td_trungtam.x + 2, i);

			TextColor(7);

			cout << " ";
		}
		if (planes.td_trungtam.x - 1 != xConsole_Left)
		{
			gotoXY(planes.td_trungtam.x - 2, i);

			TextColor(7);

			cout << " ";
		}
	}

	//Xoa dan cu

	Sleep(30);

	for (int i = planes.td_trungtam.y - 2; i > 0; i--)
	{
		gotoXY(planes.td_trungtam.x, i);

		TextColor(7);

		cout << " ";
	}

	//Dan ban trung vat can

	if (planes.level == 1)
	{
		if (abs(planes.td_trungtam.x - barrier.td_trungtam.x) <= 2)
		{
			barrier.mau -= 100;

			//Xoa vat can

			remove_Barrier(barrier);

			//Xoa dan cu

			for (int i = planes.td_trungtam.y - 2; i > 0; i--)
			{
				gotoXY(planes.td_trungtam.x, i);

				TextColor(7);

				cout << " ";
			}


			//khoi tao lai vat can

			srand((unsigned)time(NULL));

			int random = (xConsole_Right - 1) - (xConsole_Left + 1);

			barrier.td_trungtam.x = rand() % random + (xConsole_Left + 1);

			barrier.td_trungtam.y = 1;

			barrier.mau = 100;

			draw_barrier(barrier);

			//tang diem

			planes.scores += 100;
		}
	}

	if (planes.level == 2)
	{
		if (abs(planes.td_trungtam.x - (boss.td.x)) <= 12 && abs(planes.td_trungtam.x - (boss.td.x)) >= 6)
			boss.mau -= 3;
	}

}

void xulyDanDebug(mayBay &planes, vatCan &barrier, boss &boss)
{
	if (planes.soDanDebug == 1)
	{
		//hien thi dan
		gotoXY(planes.danDebug.x - 2, planes.danDebug.y);
		cout << "     ";

		--planes.danDebug.y;

		gotoXY(planes.danDebug.x - 2, planes.danDebug.y);
		cout << "DEBUG";

		//dan cham boss

		int dx = abs(planes.danDebug.x - boss.td.x);

		if ((planes.danDebug.y <= boss.td.y) && dx <= 12 && dx >= 6)
		{
			boss.mau -= boss.mau / 4;
			gotoXY(planes.danDebug.x - 2, planes.danDebug.y);
			cout << "     ";
		}

		if (planes.danDebug.y <= 1)
		{
			gotoXY(planes.danDebug.x - 2, planes.danDebug.y);
			cout << "     ";

			//khong the ban duoc nua

			planes.soDanDebug = 2;
		}
	}
}

//================= HISCORES =====================///

//luu hisoce

void out_Hiscores(mayBay &planes)
{

	ofstream ofs("Hiscores.txt", ios::app);

	ofs << planes.name << endl;

	ofs << planes.scores << endl;

	ofs.close();

}

//=================  VAT PHAM  ==========================//

void khoiTaoVatPham(vatPham &vp)
{
	vp.flag = 0;

	vp.random = 0;

}

void xuLyVatPham(vatCan barrier, vatPham &vp, mayBay &planes)
{
	static int count_time = 0;

	int x = (xConsole_Right - 1) - (xConsole_Left + 1);

	if (vp.flag == 0)
	{
		vp.random = rand() % 20;

		vp.flag = 1;

	}

	switch (vp.random)
	{
		// vat pham tang mang song

	case 1:
	{

		//khoi tao lan dau

		if (vp.flag == 1)
		{

			vp.tangMang.x = rand() % x + (xConsole_Left + 1);

			vp.tangMang.y = 0;

			vp.flag = 2;
		}

		//hien thi va di chuyen

		if (vp.flag == 2)
		{
			gotoXY(vp.tangMang.x, vp.tangMang.y);
			TextColor(12);
			putchar(3);

			vp.tangMang.y++;

			Sleep(10);

			gotoXY(vp.tangMang.x, vp.tangMang.y - 2);
			putchar(' ');
		}
		//kiem tra cham bien duoi

		if (vp.tangMang.y > yConsole - 1)
		{
			gotoXY(vp.tangMang.x, vp.tangMang.y - 1);
			putchar(' ');

			vp.flag = 3;

		}

		//may bay an vat pham

		if (abs(planes.td_trungtam.x - vp.tangMang.x) <= 1 && abs(vp.tangMang.y - planes.td_trungtam.y) < 2)
		{
			PlaySound(TEXT("anMoi"), NULL, SND_ASYNC);

			planes.life++;

			gotoXY(vp.tangMang.x, vp.tangMang.y - 1);
			putchar(' ');

			vp.tangMang.y = 0;

			vp.flag = 3;

		}

		//doi thoi gian srand len 1 giay de thay doi bo so rand()

		++count_time;

		if (count_time == 50)
		{
			vp.flag = 0;
			count_time = 0;
		}

		break;
	}

	//vat pham tang luong laser len 1

	case 2:
	{

		//khoi tao lan dau

		if (vp.flag == 1)
		{

			vp.danLaser.x = rand() % x + (xConsole_Left + 1);

			vp.danLaser.y = 0;

			vp.flag = 2;
		}

		//hien thi va di chuyen

		if (vp.flag == 2)
		{
			gotoXY(vp.danLaser.x, vp.danLaser.y);
			TextColor(11);
			putchar(23);

			vp.danLaser.y++;

			Sleep(10);

			gotoXY(vp.danLaser.x, vp.danLaser.y - 2);
			putchar(' ');
		}
		//kiem tra cham bien duoi

		if (vp.danLaser.y > yConsole - 1)
		{
			gotoXY(vp.danLaser.x, vp.danLaser.y - 1);
			putchar(' ');

			vp.flag = 3;

		}

		//may bay an vat pham

		if (abs(planes.td_trungtam.x - vp.danLaser.x) <= 1 && abs(vp.danLaser.y - planes.td_trungtam.y) < 2)
		{

			PlaySound(TEXT("anMoi"), NULL, SND_ASYNC);

			if (vp.power_laser <= max_Laser)
				vp.power_laser++;

			gotoXY(vp.danLaser.x, vp.danLaser.y - 1);
			putchar(' ');

			vp.danLaser.y = 0;

			vp.flag = 3;

		}

		//doi thoi gian srand len 1 giay de thay doi bo so rand()

		++count_time;

		if (count_time == 50)
		{
			vp.flag = 0;
			count_time = 0;
		}

		break;
	}

	//vat pham full Laser

	case 3:
	{

		//khoi tao lan dau

		if (vp.flag == 1)
		{

			vp.danLaser.x = rand() % x + (xConsole_Left + 1);

			vp.danLaser.y = 0;

			vp.flag = 2;
		}

		//hien thi va di chuyen

		if (vp.flag == 2)
		{
			gotoXY(vp.danLaser.x, vp.danLaser.y);
			TextColor(11);
			putchar(29);

			vp.danLaser.y++;

			Sleep(10);

			gotoXY(vp.danLaser.x, vp.danLaser.y - 2);
			putchar(' ');
		}
		//kiem tra cham bien duoi

		if (vp.danLaser.y > yConsole - 1)
		{
			gotoXY(vp.danLaser.x, vp.danLaser.y - 1);
			putchar(' ');

			vp.flag = 3;

		}

		//may bay an vat pham

		if (abs(planes.td_trungtam.x - vp.danLaser.x) <= 1 && abs(vp.danLaser.y - planes.td_trungtam.y) < 2)
		{
			PlaySound(TEXT("anMoi"), NULL, SND_ASYNC);

			vp.power_laser = max_Laser;

			gotoXY(vp.danLaser.x, vp.danLaser.y - 1);
			putchar(' ');

			vp.danLaser.y = 0;

			vp.flag = 3;

		}

		//doi thoi gian srand len 1 giay de thay doi bo so rand()

		++count_time;

		if (count_time == 50)
		{
			vp.flag = 0;
			count_time = 0;
		}

		break;
	}

	case 4:
	{
		if (planes.level == 2) {
			//khoi tao lan dau

			if (vp.flag == 1)
			{

				vp.tangMang.x = rand() % x + (xConsole_Left + 1);

				vp.tangMang.y = 0;

				vp.flag = 2;
			}

			//hien thi va di chuyen

			if (vp.flag == 2)
			{
				gotoXY(vp.tangMang.x, vp.tangMang.y);
				TextColor(12);
				cout << "Vip";

				vp.tangMang.y++;

				Sleep(10);

				gotoXY(vp.tangMang.x, vp.tangMang.y - 2);
				cout << "   ";
			}
			//kiem tra cham bien duoi

			if (vp.tangMang.y > yConsole - 1)
			{
				gotoXY(vp.tangMang.x, vp.tangMang.y - 1);
				cout << "   ";

				vp.flag = 3;

			}

			//may bay an vat pham

			if (abs(planes.td_trungtam.x - vp.tangMang.x) <= 1 && abs(vp.tangMang.y - planes.td_trungtam.y) < 2)
			{
				PlaySound(TEXT("anMoi"), NULL, SND_ASYNC);

				planes.soDanDebug = 0;

				gotoXY(vp.tangMang.x, vp.tangMang.y - 1);
				cout << "   ";

				vp.tangMang.y = 0;

				vp.flag = 3;

			}

			//doi thoi gian srand len 1 giay de thay doi bo so rand()

			++count_time;

			if (count_time == 50)
			{
				vp.flag = 0;
				count_time = 0;
			}
		}
		break;
	}
	default:
	{
		vp.flag = 0;
		break;
	}
	}

}

// ================== BOSS ============================//

void xuLyBoss(boss &boss, mayBay &planes)
{
	del_Boss(boss);

	//cham bien doi huong di chuyen

	if (boss.td.x == xConsole_Right - 18)
		boss.diChuyen = Left;
	else if (boss.td.x == xConsole_Left + 1)
		boss.diChuyen = Right;

	//di chuyen

	if (boss.diChuyen == Right)
		boss.td.x++;
	else
		boss.td.x--;

	draw_Boss(boss);

	Sleep(speedBoss);


	//boss ban dan

	for (int i = 0; i < 4; ++i)
	{

		gotoXY(boss.dan[i].x, boss.dan[i].y);
		putchar(' ');

		++boss.dan[i].y;

		gotoXY(boss.dan[i].x, boss.dan[i].y);
		TextColor(13);
		putchar('!');


	}

	for (int i = 0; i < 4; ++i)
	{
		//cham bien

		if (boss.dan[i].y >= yConsole - 1)
		{
			gotoXY(boss.dan[i].x, boss.dan[i].y);
			putchar(' ');

			gotoXY(boss.dan[i + 1].x, boss.dan[i].y);
			putchar(' ');

			gotoXY(boss.dan[i + 2].x, boss.dan[i].y);
			putchar(' ');

			gotoXY(boss.dan[i + 3].x, boss.dan[i].y);
			putchar(' ');

			boss.dan[0].x = boss.td.x + 6;
			boss.dan[1].x = boss.td.x + 9;
			boss.dan[2].x = boss.td.x + 12;
			boss.dan[3].x = boss.td.x + 15;

			for (int i = 0; i < 4; ++i)
				boss.dan[i].y = boss.td.y + 1;
		}
		if (abs(boss.dan[i].x - planes.td_trungtam.x) <= 1 && boss.dan[i].y == planes.td_trungtam.y)
		{
			--planes.life;

			for (int i = 0; i < 4; ++i)
			{
				gotoXY(boss.dan[i].x, boss.dan[i].y);
				putchar(' ');
			}


			boss.dan[0].x = boss.td.x + 6;
			boss.dan[1].x = boss.td.x + 9;
			boss.dan[2].x = boss.td.x + 12;
			boss.dan[3].x = boss.td.x + 15;

			for (int i = 0; i < 4; ++i)
				boss.dan[i].y = boss.td.y + 1;
		}

	}

}

//============================ VONG LAP MAIN_GAME ============================//

void xuLyTrungTam(mayBay &planes, vatCan &barrier, vatPham &vp, boss &boss)
{

	khoiTaoBoss(boss);

	khoiTaoMayBay(planes);

	khoiTaoVatCan(barrier);

	khoiTaoVatPham(vp);

	khoiTaoDanLaser(vp);

	while (planes.level == 1)
	{

		srand((unsigned)time(NULL));

		xuLyMayBay(planes, barrier, vp, boss);

		xulyDan(planes, barrier, boss);

		xuLyVatCan(barrier, planes);

		xuLyVaCham(planes, barrier);

		xuLyVatPham(barrier, vp, planes);

		thaoTac(planes, barrier, vp, boss);

		hienThi(planes, vp);

	}

	PlaySound(TEXT("Oh_yeah"), NULL, SND_ASYNC);

	gotoXY(xConsole_Left + 13, yConsole / 2);
	cout << "LEVEL UP";
	Sleep(500);

	system("cls");

	draw_Wall(planes, boss);

	//planes.life += 5;



	while (planes.level == 2)
	{

		xuLyMayBay(planes, barrier, vp, boss);

		xuLyBoss(boss, planes);

		xulyDan(planes, barrier, boss);

		xulyDanDebug(planes, barrier, boss);

		xuLyVatPham(barrier, vp, planes);

		thaoTac(planes, barrier, vp, boss);

		hienThi(planes, vp);

	}

}