#ifndef QUANLYFILE_H
#define QUANLYFILE_H

#include <vector>
#include "sanpham.h"
#include "donhang.h"
using namespace std;

class QuanLyFile {
public:
    void luuSanPham(const vector<SanPham>& danhSach);
    void docSanPham(vector<SanPham>& danhSach);
    
    void luuDonHang(const vector<DonHang>& danhSach);
    void docDonHang(vector<DonHang>& danhSach);
    
    bool kiemTraSanPhamTrongDon(const string& maSP, const vector<DonHang>& donHangList);
};

#endif