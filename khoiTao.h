#pragma once

#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <mmsystem.h> //Thư viện dùng để chèn nhạc

#pragma comment (lib, "winmm.lib") //chèn thư viện phát nhạc

using namespace std;

#define xConsole_Left 25
#define xConsole_Right 55
#define yConsole 23
#define wallColor 1
#define planes_Color 14
#define barrier_Color 12
#define barrier_speed 50
#define max_Bullet 10
#define max_Laser 10
#define bossColor 13
#define speedBoss 40

// ==================================== CAC STRUCT ============================== //

struct toaDo
{
	int x, y;
};

struct mayBay
{

	toaDo td_trungtam;

	char hinhDang[3][3];

	string name;

	int life;

	int scores;

	toaDo dan[max_Bullet];

	toaDo danDebug;

	int soDanDebug;

	int soDan;

	int max_Dan;

	int n_Hiscore; //so luong diem cao

	int level;

};

struct vatCan
{

	toaDo td_trungtam;

	char hinhDang[3][3];

	int tocDo;

	int mau;

	int soLanChamBien;

};

struct vatPham
{
	int flag; //danh dau

	int random;

	toaDo tangMang;

	toaDo danLaser;

	int power_laser;

};

enum control{ Left, Right };

struct boss
{
	int mau;

	toaDo td;

	toaDo dan[5];

	control diChuyen;
};



//================================ cac ham do hoa co ban =========================//

void gotoXY(int , int );

void TextColor(int );

void clrscr();

//============================== VE MAN HINH ==================================//

void draw_Wall(mayBay, boss);

//===================================== MAY BAY =================================//

void khoiTaoMayBay(mayBay &);

void draw_Planes(mayBay );

void del_Planes(mayBay );

// ==================================== VAT CAN ======================================//

void khoiTaoVatCan(vatCan &);

void draw_barrier(vatCan );

void del_barrier(vatCan );

void remove_Barrier(vatCan );

//==================================== BOSS ========================================//

void khoiTaoBoss(boss &);

void draw_Boss(boss );

void del_Boss(boss );
