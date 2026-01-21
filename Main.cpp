#include <iostream>
#include <vector>
#include "sanpham.h"
#include "donhang.h"
#include "quanlyfile.h"
#include "menu.h"
using namespace std;

int main() {
    vector<SanPham> danhSachSP;
    vector<DonHang> danhSachDH;
    
    // Tạo instance
    Menu menu;
    QuanLyFile quanLyFile;
    
    // Đọc dữ liệu từ file
    quanLyFile.docSanPham(danhSachSP);
    quanLyFile.docDonHang(danhSachDH);
    
    int luaChon;
    
    do {
        menu.hienThiMenuChinh();
        cin >> luaChon;
        
        switch(luaChon) {
            case 1:
                menu.themSanPham(danhSachSP);
                quanLyFile.luuSanPham(danhSachSP);
                break;
                
            case 2:
                menu.suaSanPham(danhSachSP);
                quanLyFile.luuSanPham(danhSachSP);
                break;
                
            case 3:
                menu.xoaSanPham(danhSachSP, danhSachDH);
                quanLyFile.luuSanPham(danhSachSP);
                break;
                
            case 4:
                menu.taoDonHang(danhSachDH, danhSachSP);
                quanLyFile.luuDonHang(danhSachDH);
                quanLyFile.luuSanPham(danhSachSP);
                break;
                
            case 5:
                menu.suaDonHang(danhSachDH, danhSachSP);
                quanLyFile.luuDonHang(danhSachDH);
                quanLyFile.luuSanPham(danhSachSP);
                break;
                
            case 6:
                menu.xoaDonHang(danhSachDH);
                quanLyFile.luuDonHang(danhSachDH);
                break;
                
            case 7:
                menu.xemSanPham(danhSachSP);
                break;
                
            case 8:
                menu.xemDonHang(danhSachDH, danhSachSP);
                break;
                
            case 9:
                cout << "Cam on ban da su dung! Tam biet!" << endl;
                break;
                
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (luaChon != 9);
    
    return 0;
}