#ifndef MENU_H
#define MENU_H

#include <vector>
#include "sanpham.h"
#include "donhang.h"
#include "quanlyfile.h"
using namespace std;

class Menu {
private:
    QuanLyFile quanLyFile;
    
public:
    void hienThiMenuChinh();
    void hienThiMenuDonHang();
    
    void themSanPham(vector<SanPham>& danhSach);
    void suaSanPham(vector<SanPham>& danhSach);
    void xoaSanPham(vector<SanPham>& danhSach, const vector<DonHang>& donHangList);
    void taoDonHang(vector<DonHang>& danhSach, vector<SanPham>& sanPhamList);
    void suaDonHang(vector<DonHang>& danhSach, vector<SanPham>& sanPhamList);
    void xoaDonHang(vector<DonHang>& danhSach);
    void xemSanPham(const vector<SanPham>& danhSach);
    void xemDonHang(const vector<DonHang>& danhSach, const vector<SanPham>& sanPhamList);
};

#endif