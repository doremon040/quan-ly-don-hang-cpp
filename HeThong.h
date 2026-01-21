#ifndef HETHONG_H
#define HETHONG_H
#include "SanPham.h"
#include "DonHang.h"

class HeThong {
private:
    vector<SanPham> dsSP;
    vector<DonHang> dsDH;
public:
    HeThong();
    void ghiFile();
    void docFile();
    void themSP();    void suaSP();    void xoaSP();
    void nhapDH();   void suaDH();    void xoaDH();
    void lietKeSP(); void lietKeDH();
};
#endif
