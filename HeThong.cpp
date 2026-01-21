
#include "HeThong.h"
#include <fstream>
#include <iomanip>

HeThong::HeThong() { docFile(); }

// Lưu ý: Năm 2026, ghi file chứa string/vector cần chuyển đổi sang char array cố định
void HeThong::ghiFile() { /* Code ghi file nhi phan */ }
void HeThong::docFile() { /* Code doc file nhi phan */ }

void HeThong::themSP() { SanPham p; p.nhap(); dsSP.push_back(p); ghiFile(); }

void HeThong::suaSP() {
    cout << "Ma SP can sua: "; 
    string m; cin >> m;
    for (int i = 0; i < dsSP.size(); i++) {
        if (dsSP[i].getMa() == m) { dsSP[i].nhap(); ghiFile(); cout << "Sua thanh cong!\n" << endl; return; }
    }
    cout << "Khong tim thay SP!\n" << endl;
}

void HeThong::xoaSP() {
    cout << "Ma SP can xoa: "; 
    string m; cin >> m;
    for (int i = 0; i < dsDH.size(); i++) {
        for (int j = 0; j < dsDH[i].getDsCT().size(); j++) {
            if (dsDH[i].getDsCT()[j].maSP == m) {
                cout << "Loi: SP dang co trong don hang!\n" << endl; return;
            }
        }
    }
    for (int i = 0; i < dsSP.size(); i++) {
        if (dsSP[i].getMa() == m) { dsSP.erase(dsSP.begin() + i); ghiFile(); cout << "Xoa thanh cong!\n" << endl; return; }
    }
    cout << "Khong tim thay SP!\n" << endl;
}

void HeThong::nhapDH() {
    cout << "\nNhap thong tin don hang:" << endl;
    DonHang d; d.nhap(); dsDH.push_back(d); ghiFile();
    cout << "Them thanh cong!\n" << endl;
}

void HeThong::suaDH() {
    cout << "Ma DH can sua: "; 
    string m; cin >> m;
    for (int i = 0; i < dsDH.size(); i++) {
        if (dsDH[i].getMa() == m) { dsDH[i].sua(); ghiFile(); cout << "Sua thanh cong!\n" << endl; return; }
    }
    cout << "Khong tim thay DH!\n" << endl;
}

void HeThong::xoaDH() {
    cout << "Ma DH can xoa: "; 
    cin.ignore();
    string m; getline(cin, m);
    for (int i = 0; i < dsDH.size(); i++) {
        if (dsDH[i].getMa() == m) { dsDH.erase(dsDH.begin() + i); ghiFile(); cout << "Xoa thanh cong!\n" << endl; return; }
    }
    cout << "Khong tim thay DH!\n" << endl;
}

void HeThong::lietKeSP() {
    cout << "\n" << string(50, '=') << endl;
    cout << left << setw(15) << "MA SP" << setw(30) << "TEN SP" << "GIA" << endl;
    cout << string(50, '-') << endl;
    if (dsSP.size() == 0) {
        cout << "Chua co san pham nao!" << endl;
    } else {
        for (int i = 0; i < dsSP.size(); i++) dsSP[i].hienThi();
    }
    cout << string(50, '=') << "\n" << endl;
}

void HeThong::lietKeDH() {
    cout << "\n" << string(50, '=') << endl;
    cout << "DANH SACH DON HANG" << endl;
    cout << string(50, '-') << endl;
    if (dsDH.size() == 0) {
        cout << "Chua co don hang nao!" << endl;
    } else {
        for (int i = 0; i < dsDH.size(); i++) dsDH[i].hienThi();
    }
    cout << string(50, '=') << "\n" << endl;
}
