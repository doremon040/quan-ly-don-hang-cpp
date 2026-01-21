#include "donhang.h"
#include <iostream>
using namespace std;

// ChiTietDon constructors
ChiTietDon::ChiTietDon() : maSanPham(""), soLuong(0) {}

ChiTietDon::ChiTietDon(string ma, int sl) : maSanPham(ma), soLuong(sl) {}

// ChiTietDon getters
string ChiTietDon::getMaSanPham() const {
    return maSanPham;
}

int ChiTietDon::getSoLuong() const {
    return soLuong;
}

// ChiTietDon setters
void ChiTietDon::setMaSanPham(string ma) {
    maSanPham = ma;
}

void ChiTietDon::setSoLuong(int sl) {
    soLuong = sl;
}

// DonHang constructors
DonHang::DonHang() : ma(""), tenKhachHang(""), ngay("") {}

DonHang::DonHang(string m, string tenkh, string n) 
    : ma(m), tenKhachHang(tenkh), ngay(n) {}

// DonHang getters
string DonHang::getMa() const {
    return ma;
}

string DonHang::getTenKhachHang() const {
    return tenKhachHang;
}

string DonHang::getNgay() const {
    return ngay;
}

vector<ChiTietDon>& DonHang::getDanhSachSanPham() {
    return danhSachSanPham;
}

const vector<ChiTietDon>& DonHang::getDanhSachSanPham() const {
    return danhSachSanPham;
}

// DonHang setters
void DonHang::setMa(string m) {
    ma = m;
}

void DonHang::setTenKhachHang(string tenkh) {
    tenKhachHang = tenkh;
}

void DonHang::setNgay(string n) {
    ngay = n;
}

// DonHang methods
void DonHang::themSanPham(const ChiTietDon& ct) {
    danhSachSanPham.push_back(ct);
}

void DonHang::hienThi() {
    cout << "\nMa DH: " << ma << endl;
    cout << "Khach hang: " << tenKhachHang << endl;
    cout << "Ngay: " << ngay << endl;
    cout << "So san pham: " << danhSachSanPham.size() << endl;
}