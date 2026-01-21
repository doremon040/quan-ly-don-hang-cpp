#include "quanlyfile.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void QuanLyFile::luuSanPham(const vector<SanPham>& danhSach) {
    ofstream file("sanpham.dat", ios::binary);
    int soLuong = danhSach.size();
    file.write((char*)&soLuong, sizeof(soLuong));
    
    for (const auto& sp : danhSach) {
        // Lưu mã
        int doDai = sp.ma.length();
        file.write((char*)&doDai, sizeof(doDai));
        file.write(sp.ma.c_str(), doDai);
        
        // Lưu tên
        doDai = sp.ten.length();
        file.write((char*)&doDai, sizeof(doDai));
        file.write(sp.ten.c_str(), doDai);
        
        // Lưu giá và số lượng
        file.write((char*)&sp.gia, sizeof(sp.gia));
        file.write((char*)&sp.soLuong, sizeof(sp.soLuong));
    }
    file.close();
}

void QuanLyFile::docSanPham(vector<SanPham>& danhSach) {
    ifstream file("sanpham.dat", ios::binary);
    if (!file) return;
    
    danhSach.clear();
    int soLuong;
    file.read((char*)&soLuong, sizeof(soLuong));
    
    for (int i = 0; i < soLuong; i++) {
        SanPham sp;
        
        // Đọc mã
        int doDai;
        file.read((char*)&doDai, sizeof(doDai));
        sp.ma.resize(doDai);
        file.read(&sp.ma[0], doDai);
        
        // Đọc tên
        file.read((char*)&doDai, sizeof(doDai));
        sp.ten.resize(doDai);
        file.read(&sp.ten[0], doDai);
        
        // Đọc giá và số lượng
        file.read((char*)&sp.gia, sizeof(sp.gia));
        file.read((char*)&sp.soLuong, sizeof(sp.soLuong));
        
        danhSach.push_back(sp);
    }
    file.close();
}

void QuanLyFile::luuDonHang(const vector<DonHang>& danhSach) {
    ofstream file("donhang.dat", ios::binary);
    int soLuong = danhSach.size();
    file.write((char*)&soLuong, sizeof(soLuong));
    
    for (const auto& dh : danhSach) {
        // Lưu mã đơn
        string ma = dh.getMa();
        int doDai = ma.length();
        file.write((char*)&doDai, sizeof(doDai));
        file.write(ma.c_str(), doDai);
        
        // Lưu tên khách
        string tenKh = dh.getTenKhachHang();
        doDai = tenKh.length();
        file.write((char*)&doDai, sizeof(doDai));
        file.write(tenKh.c_str(), doDai);
        
        // Lưu ngày
        string ngay = dh.getNgay();
        doDai = ngay.length();
        file.write((char*)&doDai, sizeof(doDai));
        file.write(ngay.c_str(), doDai);
        
        // Lưu số sản phẩm
        const auto& danhSachCT = dh.getDanhSachSanPham();
        int soSP = danhSachCT.size();
        file.write((char*)&soSP, sizeof(soSP));
        
        // Lưu từng sản phẩm
        for (const auto& sp : danhSachCT) {
            string maSP = sp.getMaSanPham();
            doDai = maSP.length();
            file.write((char*)&doDai, sizeof(doDai));
            file.write(maSP.c_str(), doDai);
            
            int soLuong = sp.getSoLuong();
            file.write((char*)&soLuong, sizeof(soLuong));
        }
    }
    file.close();
}

void QuanLyFile::docDonHang(vector<DonHang>& danhSach) {
    ifstream file("donhang.dat", ios::binary);
    if (!file) return;
    
    danhSach.clear();
    int soLuong;
    file.read((char*)&soLuong, sizeof(soLuong));
    
    for (int i = 0; i < soLuong; i++) {
        DonHang dh;
        
        // Đọc mã đơn
        int doDai;
        file.read((char*)&doDai, sizeof(doDai));
        string ma(doDai, ' ');
        file.read(&ma[0], doDai);
        dh.setMa(ma);
        
        // Đọc tên khách
        file.read((char*)&doDai, sizeof(doDai));
        string tenKh(doDai, ' ');
        file.read(&tenKh[0], doDai);
        dh.setTenKhachHang(tenKh);
        
        // Đọc ngày
        file.read((char*)&doDai, sizeof(doDai));
        string ngay(doDai, ' ');
        file.read(&ngay[0], doDai);
        dh.setNgay(ngay);
        
        // Đọc số sản phẩm
        int soSP;
        file.read((char*)&soSP, sizeof(soSP));
        
        // Đọc từng sản phẩm
        for (int j = 0; j < soSP; j++) {
            file.read((char*)&doDai, sizeof(doDai));
            string maSP(doDai, ' ');
            file.read(&maSP[0], doDai);
            
            int soLuong;
            file.read((char*)&soLuong, sizeof(soLuong));
            
            ChiTietDon ct(maSP, soLuong);
            dh.themSanPham(ct);
        }
        
        danhSach.push_back(dh);
    }
    file.close();
}

bool QuanLyFile::kiemTraSanPhamTrongDon(const string& maSP, const vector<DonHang>& donHangList) {
    for (const auto& dh : donHangList) {
        for (const auto& sp : dh.getDanhSachSanPham()) {
            if (sp.getMaSanPham() == maSP) {
                return true;
            }
        }
    }
    return false;
}