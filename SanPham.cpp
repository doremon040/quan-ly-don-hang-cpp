#include "SanPham.h"
#include <iomanip>
using namespace std;

void SanPham::nhap() {
    cout << "Ma SP: "; cin >> maSP;
    cout << "Ten SP: "; cin.ignore(); getline(cin, tenSP);
    cout << "Gia: "; cin >> gia;
}
void SanPham::hienThi() {
    cout << left << setw(15) << maSP 
         << left << setw(30) << tenSP 
         << right << setw(12) << fixed << setprecision(2) << gia << " VND" << endl;
}
