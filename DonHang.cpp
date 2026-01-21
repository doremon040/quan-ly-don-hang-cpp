#include "DonHang.h"
#include <iostream>
#include <iomanip>

void DonHang::nhap() {
    cout << "\nNhap ma DH: "; cin >> maDH;
    cout << "Nhap ten khach hang: "; cin.ignore(); getline(cin, tenKH);
    dsCT.clear();
    char tiep;
    do {
        ChiTiet ct;
        cout << "Ma SP: "; cin >> ct.maSP;
        cout << "So luong: "; cin >> ct.soLuong;
        dsCT.push_back(ct);
        cout << "Them SP khac? (y/n): "; cin >> tiep;
    } while (tiep == 'y' || tiep == 'Y');
}

void DonHang::sua() {
    char chon;
    do {
        cout << "\n[a] Them SP   [b] Sua SL   [c] Xoa SP   [d] Thoat" << endl;
        cout << "Chon: "; cin >> chon;
        if (chon == 'a') {
            ChiTiet ct;
            cout << "Ma SP: "; cin >> ct.maSP;
            cout << "So luong: "; cin >> ct.soLuong;
            dsCT.push_back(ct);
            cout << "--- Them thanh cong! ---" << endl;
        } else if (chon == 'b' || chon == 'c') {
            string m; cout << "Ma SP: "; cin >> m;
            for (int i = 0; i < dsCT.size(); i++) {
                if (dsCT[i].maSP == m) {
                    if (chon == 'b') { cout << "SL moi: "; cin >> dsCT[i].soLuong; cout << "--- Cap nhat thanh cong! ---" << endl; }
                    else { dsCT.erase(dsCT.begin() + i); cout << "--- Xoa thanh cong! ---" << endl; }
                    break;
                }
            }
        }
    } while (chon != 'd');
}

void DonHang::hienThi() {
    cout << "\n" << left << "Ma DH: " << maDH << " | Khach hang: " << tenKH << endl;
    cout << setw(20) << "Ma SP" << "So luong" << endl;
    cout << string(30, '-') << endl;
    for (int i = 0; i < dsCT.size(); i++)
        cout << left << setw(20) << dsCT[i].maSP << dsCT[i].soLuong << endl;
}
