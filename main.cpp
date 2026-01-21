#include "HeThong.h"
#include <iostream>
using namespace std;

void hienThiMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "  HE THONG QUAN LY DON HANG " << endl;
    cout << string(50, '=') << endl;
    cout << "[1] Them san pham         [2] Sua san pham\n";
    cout << "[3] Xoa san pham          [4] Them don hang\n";
    cout << "[5] Sua don hang          [6] Xoa don hang\n";
    cout << "[7] Danh sach san pham    [8] Danh sach don hang\n";
    cout << "[9] Thoat\n";
    cout << "Chon: ";
}

int main() {
    HeThong app;
    int chon;
    do {
        hienThiMenu();
        if (!(cin >> chon)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Lua chon khong hop le!\n" << endl;
            continue;
        }
        switch(chon) {
            case 1: app.themSP(); break;
            case 2: app.suaSP(); break;
            case 3: app.xoaSP(); break;
            case 4: app.nhapDH(); break;
            case 5: app.suaDH(); break;
            case 6: app.xoaDH(); break;
            case 7: app.lietKeSP(); break;
            case 8: app.lietKeDH(); break;
            case 9: cout << "\nTam biet!\n" << endl; break;
            default: cout << "Lua chon khong hop le!\n" << endl;
        }
    } while(chon != 9);
    return 0;
}
