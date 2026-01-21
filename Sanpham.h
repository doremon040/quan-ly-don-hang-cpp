#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>
using namespace std;

class SanPham {
    public:
    string ma;
    string ten;
    double gia;
    int soLuong;
    
    void hienThi();
};

#endif