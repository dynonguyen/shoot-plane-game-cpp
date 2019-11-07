#include "display.h"

//Ten game

void drawNameGame()
{
	//ve ten game

	srand((unsigned)time('\0'));
	int x = 20;
	int y = 12;
	int z = 29;
	int color = rand() % 14 + 1;
	int pause = 4;

	for (int i = 1; i <= x; ++i)
	{
		gotoXY(i, y - 3);
		TextColor(color);
		cout << "                       $$$\\ ";

		gotoXY(i, y - 2);
		cout << "                      $$ $$\\";

		gotoXY(i, y - 1);
		cout << "                     $$  \\$$\\";

		gotoXY(i, y);
		cout << "$$\\       $$\\        \\__/ \\__|";

		gotoXY(i, y + 1);
		cout << "$$ |      $$ |";

		gotoXY(i, y + 2);
		cout << "$$ |  $$\\ $$$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\";

		gotoXY(i, y + 3);
		cout << "$$ | $$  |$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\";

		gotoXY(i, y + 4);
		cout << "$$$$$$  / $$ |  $$ |$$ /  $$ |$$ |  $$ |$$ /  $$ |";

		gotoXY(i, y + 5);
		cout << "$$  _$$<  $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |";

		gotoXY(i, y + 6);
		cout << "$$ | \\$$\\ $$ |  $$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$$ |";

		gotoXY(i, y + 7);
		cout << "\\__|  \\__|\\__|  \\__| \\______/ \\__|  \\__| \\____$$ |";

		gotoXY(i, y + 8);
		cout << "                                        $$\\   $$ |";

		gotoXY(i, y + 9);
		cout << "                                        \\$$$$$$  |";

		gotoXY(i, y + 10);
		cout << "                                         \\______/ ";

		//================================================================//

		gotoXY(i + 15, z - 5);
		cout << "                                     / \\";

		gotoXY(i + 15, z - 4);
		cout << "                                    /  $$";

		gotoXY(i + 15, z - 3);
		cout << "                            __     /  $$";

		gotoXY(i + 15, z - 2);
		cout << "                           /  $\\  |  $$";

		gotoXY(i + 15, z - 1);
		cout << "                          /  $$$\\  \\$$";

		gotoXY(i + 15, z);
		cout << "           __        __  |  $$\\$$\\";

		gotoXY(i + 15, z + 1);
		cout << "          |  \\      |  \\  \\$$  \\$$";

		gotoXY(i + 15, z + 2);
		cout << "  _______ | $$____   \\$$  ______   _______";

		gotoXY(i + 15, z + 3);
		cout << " /       \\| $$    \\ |  \\ /      \\ |       \\ ";

		gotoXY(i + 15, z + 4);
		cout << "|  $$$$$$$| $$$$$$$\\| $$|  $$$$$$\\| $$$$$$$\\";

		gotoXY(i + 15, z + 5);
		cout << "| $$      | $$  | $$| $$| $$    $$| $$  | $$";

		gotoXY(i + 15, z + 6);
		cout << "| $$_____ | $$  | $$| $$| $$$$$$$$| $$  | $$";

		gotoXY(i + 15, z + 7);
		cout << " \\$$     \\| $$  | $$| $$ \\$$     \\| $$  | $$";

		gotoXY(i + 15, z + 8);
		cout << "  \\$$$$$$$ \\$$   \\$$ \\$$  \\$$$$$$$ \\$$   \\$$";

		if (i < x)
		{
			system("cls");
			Sleep(pause);
		}
		
	}
	
	//ve khung ben ngoai

	int xConsole = 98;
	int yconsole = 49;
	int wall_Color = 10;
	for (int i = 1; i < xConsole; ++i)
	{
		gotoXY(i, 0);
		TextColor(wall_Color);
		putchar(26);

		gotoXY(i, yconsole);
		putchar(27);
	}

	for (int i = 1; i < yconsole ; ++i)
	{
		gotoXY(1, i);
		TextColor(wall_Color);
		putchar(24);

		gotoXY(xConsole, i);
		putchar(25);
	}

	//bat dau choi game

	gotoXY(xConsole / 2 - 13, yconsole - 2);
	TextColor(12);
	cout << "< Press Enter to Continue >";

	char key = _getch();
	while (key != 13)
	{
		if (key != 13)
			key = _getch();
		else
			break;
	}


}

//huong dan

void huongDan()
{
	int x = (xConsole_Left + xConsole_Right) / 2;

	int y = yConsole / 2;

	gotoXY(x - 20, y);
	TextColor(2);
	cout << "=================== HUONG DAN ===================";

	gotoXY(x - 10, y + 2);
	TextColor(3);
	cout << "Nhan W (UP) de di len.";

	gotoXY(x - 10, y + 4);
	TextColor(4);
	cout << "Nhan S (DOWN) de di xuong.";

	gotoXY(x - 10, y + 6);
	TextColor(5);
	cout << "Nhan A (LEFT) de di sang trai.";

	gotoXY(x - 10, y + 8);
	TextColor(6);
	cout << "Nhan D (RIGHT) de di sang phai.";

	gotoXY(x - 10, y + 10);
	TextColor(8);
	cout << "Nhan Space de ban dan thuong.";

	gotoXY(x - 10, y + 12);
	TextColor(9);
	cout << "Nhan E de ban dan Laser.";


	gotoXY(x - 10, y + 14);
	TextColor(13);
	cout << "Nhan Q khi dang choi de tam dung.";

	gotoXY(x - 10, y + 16);
	char c = 3;
	TextColor(11);
	cout << "Vat pham " << c << " tang 1 mang song.";

	gotoXY(x - 10, y + 18);
	c = 18;
	TextColor(12);
	cout << "Vat pham " << c << " tang 1 nang luong laser.";

	gotoXY(x - 10, y + 20);
	c = 29;
	TextColor(11);
	cout << "Vat pham " << c << " tang full nang luong laser.";

	gotoXY(x - 37, y + 22);
	TextColor(10);
	cout << "Dieu khien may bay ban ha cac vat can. Dan thuong -50% mau vat can, dan laser -100% mau vat can.";

	gotoXY(x - 20, y + 24);
	TextColor(10);
	cout << "Vat cham may bay hoac vat can di xuong bien 3 lan se -1 mang song.";

	gotoXY(x - 20, y + 26);
	TextColor(12);
	cout << "Dan DEBUG giup -1/3 luong mau cua boss. Nhan X de kich hoat.";

	gotoXY(x - 9, y + 28);
	TextColor(14);
	cout << "Diem yeu cua boss la o giua than.";

}

//hien thi hiscores

void outConsoleHiscores(mayBay planes, vatCan barrier, vatPham vp, boss boss)
{
	int x = 50;
	int n_Hiscore;

	srand((unsigned)time(NULL));
	gotoXY(x - 2, yConsole / 2 - 4);
	TextColor(rand() % 14 + 1);
	cout << "HISCORE";

	gotoXY(x - 20, yConsole / 2 - 2);
	cout << "~~~~~~~~~~~~~~~~~~~ ^-^ ~~~~~~~~~~~~~~~~~~~";

	gotoXY(x - 10, yConsole / 2 );
	cout << "RANK";

	gotoXY(x , yConsole / 2 );
	cout << "NAME";

	gotoXY(x + 10, yConsole / 2);
	cout << "SCORE";

	//lay so luong hiscore

	ifstream ifs("n_Hiscores.txt");

	if(!ifs.fail())
		ifs >> n_Hiscore;
	else
	{
		system("cls");
		gotoXY(x - 22, yConsole / 2 + 5);
		cout << "Chua co lan choi nao truoc day. Play game di ne :\">";
		gotoXY(x - 20, yConsole / 2 + 7);
		cout << "< Nhan Enter de choi tiep. Nhap Esc de thoat. >";
		char key = _getch();
		if (key == 13)
		{
			ifs.close();
			system("cls");
			display(planes, barrier, vp, boss);
		}
		if (key == 27)
		{
			ifs.close();
			exit(0);
		}
	}

	ifs.close();

	if (n_Hiscore == 0)
	{
		system("cls");
		gotoXY(x - 22, yConsole / 2 + 5);
		cout << "Chua co lan choi nao truoc day. Play game di ne :\">";
		gotoXY(x - 20, yConsole / 2 + 7);
		cout << "< Nhan Enter de choi tiep. Nhap Esc de thoat. >";
		char key = _getch();
		if (key == 13)
		{
			ifs.close();
			system("cls");
			display(planes, barrier, vp, boss);
		}
		if (key == 27)
		{
			ifs.close();
			exit(0);
		}
	}
	else
	{
		//lay du lieu tu file

		ifstream ifs_2("Hiscores.txt");

		string name[11];

		int score[11];

		for (int i = 0; i < n_Hiscore; ++i)
		{
			ifs_2 >> name[i];
			ifs_2 >> score[i];
		}

		ifs_2.close();


		//sap xep rank

		for(int i=0; i < n_Hiscore - 1; ++i)
			for (int j = n_Hiscore - 1; j > i; --j)
			{
				if (score[j] > score[j - 1])
				{
					int t = score[j - 1];
					score[j - 1] = score[j];
					score[j] = t;

					string temp = name[j - 1];
					name[j - 1] = name[j];
					name[j] = temp;
				}
			}

		// tra lai trong file

		ofstream ofs("Hiscores.txt");

		for (int i = 0; i < n_Hiscore; ++i)
		{
			ofs << name[i] << endl;
			ofs << score[i] << endl;
		}

		ofs.close();


		//xuat ra man hinh console
		if (n_Hiscore < 11)
		{
			for (int i = 0; i < n_Hiscore; ++i)
			{
				gotoXY(x - 10, yConsole / 2 + (i + 1) * 2);
				cout << i + 1;

				gotoXY(x, yConsole / 2 + (i + 1) * 2);
				cout << name[i];

				gotoXY(x + 10, yConsole / 2 + (i + 1) * 2);
				cout << score[i];
			}

		}
		else
		{
			for (int i = 0; i < 10; ++i)
			{
				gotoXY(x - 10, yConsole / 2 + (i + 1) * 2);
				cout << i + 1;

				gotoXY(x, yConsole / 2 + (i + 1) * 2);
				cout << name[i];

				gotoXY(x + 10, yConsole / 2 + (i + 1) * 2);
				cout << score[i];
			}
		}

		//xoa di vi tri thu 11
		if (n_Hiscore == 11)
		{
			ofstream ofs_3("Hiscores.txt");

			for (int i = 0; i < n_Hiscore - 1; ++i)
			{
				ofs_3 << name[i] << endl;
				ofs_3 << score[i] << endl;
			}

			ofs_3.close();

			ofstream ofs_4("n_Hiscores.txt");

			ofs_4 << 10 << endl;

			ofs_4.close();
		}

		// quay lai hoac thoat hoac reset

		gotoXY(x - 30, yConsole / 2 + (n_Hiscore + 1) * 2);
		TextColor(rand() % 14 + 1);
		cout << "< Nhan Enter de choi lai. Nhan Esc de thoat. Nhan R de reset lai hiscore >";

		char key = _getch();

		if (key == 13)
		{
			system("cls");
			display(planes, barrier, vp, boss);
		}

		if (key == 27)
			exit(0);
		if (key == 'R' || key == 'r')
		{
			ofstream ofs("Hiscores.txt");

			ofs << ' ';
			 
			ofs.close();

			ofstream ofs_2("n_Hiscores.txt");

			ofs_2 << 0;

			ofs_2.close();

			system("cls");
			gotoXY(80 / 2, yConsole / 2 + 10);
			cout << "Reset thanh cong.";
			_getch();
			exit(0);

		}


	}

}

//ham hien thi ra

void display(mayBay &planes, vatCan &barrier, vatPham &vp, boss &boss)
{
	//an con tro

	ShowConsoleCursor(false);

	//ve ten game

	drawNameGame();

	system("cls");

	int x = (xConsole_Left + xConsole_Right) / 2;

	int y = yConsole / 2 + 5;

	//in ra cac lua chon

	
	srand((unsigned)time(NULL));

	gotoXY(x, y);
	TextColor(rand() % 14 + 1);
	cout << "1 - Play Game";

	gotoXY(x, y + 2);
	cout << "2 - Hiscores";

	gotoXY(x, y + 4);
	cout << "3 - Help";

	gotoXY(x, y + 6);
	cout << "4 - Exit";

	gotoXY(x, y + 8);
	TextColor(rand() % 14 + 1);
	cout << "choose: ";

	int choose;

	cin >> choose;

	switch (choose)
	{

	case 1:
	{
		system("cls");
		gotoXY(x, y + 2);
		cout << "your name: ";
		cin.ignore();
		getline(cin, planes.name);

		system("cls");
		draw_Wall(planes, boss);
		xuLyTrungTam(planes, barrier, vp, boss);
		break;
	}

	case 2:
	{
		system("cls");
		outConsoleHiscores(planes, barrier, vp, boss);
		break;
	}

	case 3:
	{
		system("cls");

		huongDan();

		gotoXY(x - 15, y + 26);
		TextColor(rand() % 14 + 1);
		cout << "< Nhan Enter de choi lai. Nhan Esc de thoat >";

		char key = _getch();

		if (key == 13)
		{
				system("cls");
				display(planes, barrier, vp, boss);
		}

		if (key == 27)
			exit(0);

		break;
	}
	case 4:
	{
		exit(0);
		break;
	}
	default:
	{
		system("cls");
		display(planes, barrier, vp, boss);
		break;
	}
	}
}