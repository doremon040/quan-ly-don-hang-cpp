#ifndef DONHANG_H
#define DONHANG_H
#include <vector>
#include <string>
using namespace std;

struct ChiTiet {
    string maSP;
    int soLuong;
};

class DonHang {
private:
    string maDH;
    string tenKH;
    vector<ChiTiet> dsCT;
public:
    string getMa() { return maDH; }
    vector<ChiTiet>& getDsCT() { return dsCT; }
    void nhap();
    void sua();
    void hienThi();
};
#endif
