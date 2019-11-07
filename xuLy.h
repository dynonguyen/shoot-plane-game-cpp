#pragma once

#include "khoiTao.h"

void ShowConsoleCursor(bool );

//====== XU LY MAY BAY =======//

void xuLyMayBay(mayBay &, vatCan &, vatPham &, boss &);

//====== XU LY VAT CAN =======//

void xuLyVatCan(vatCan &, mayBay &);

// ==== CAC XU LY KHAC ===== //

void xuLyVaCham(mayBay &, vatCan &);

void hienThi(mayBay, vatPham);

void thaoTac(mayBay &, vatCan, vatPham &, boss &);

void xulyDan(mayBay &, vatCan &, boss &);

void khoiTaoDanLaser(vatPham &);

void xuLyDanLaser(mayBay &, vatCan &, vatPham &, boss &);

void xulyDanDebug(mayBay &, vatCan &, boss &);

//========== HISCORES ===============//

void out_Hiscores(mayBay &);

//================== VAT PHAM =====================//

void khoiTaoVatPham(vatPham &);

void xuLyVatPham(vatCan , vatPham &, mayBay &);

//================= BOSS ======================//

void xuLyBoss(boss &, mayBay &);


//=================== XU LY MAIN_GAME ==========================//

void xuLyTrungTam(mayBay &, vatCan &, vatPham &, boss &boss);
