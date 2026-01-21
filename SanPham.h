#ifndef SANPHAM_H
#define SANPHAM_H
#include <iostream>

class SanPham {
private:
    std::string maSP, tenSP;
    double gia;
public:
    std::string getMa() { return maSP; }
    void nhap();
    void hienThi();
};
#endif
