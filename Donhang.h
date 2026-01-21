#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include <vector>
#include "sanpham.h"
using namespace std;

class ChiTietDon {
private:
    string maSanPham;
    int soLuong;
    
public:
    ChiTietDon();
    ChiTietDon(string ma, int sl);
    
    string getMaSanPham() const;
    int getSoLuong() const;
    
    void setMaSanPham(string ma);
    void setSoLuong(int sl);
};

class DonHang {
private:
    string ma;
    string tenKhachHang;
    string ngay;
    vector<ChiTietDon> danhSachSanPham;
    
public:
    DonHang();
    DonHang(string m, string tenkh, string n);
    
    string getMa() const;
    string getTenKhachHang() const;
    string getNgay() const;
    vector<ChiTietDon>& getDanhSachSanPham();
    const vector<ChiTietDon>& getDanhSachSanPham() const;
    
    void setMa(string m);
    void setTenKhachHang(string tenkh);
    void setNgay(string n);
    
    void themSanPham(const ChiTietDon& ct);
    void hienThi();
};

#endif