#include "sanpham.h"
#include <iostream>
#include <iomanip>
using namespace std;

void SanPham::hienThi() {
    cout << left << setw(10) << ma << setw(20) << ten << setw(10) << gia << setw(10) << soLuong << endl;
}