#include "menu.h"
#include "quanlyfile.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Menu::hienThiMenuChinh() {
    cout << "\n=== QUAN LY DON HANG ===" << endl;
    cout << "1. Them san pham" << endl;
    cout << "2. Sua san pham" << endl;
    cout << "3. Xoa san pham" << endl;
    cout << "4. Tao don hang" << endl;
    cout << "5. Sua don hang" << endl;
    cout << "6. Xoa don hang" << endl;
    cout << "7. Xem san pham" << endl;
    cout << "8. Xem don hang" << endl;
    cout << "9. Thoat" << endl;
    cout << "Chon (1-9): ";
}

void Menu::hienThiMenuDonHang() {
    cout << "\n=== SUA DON HANG ===" << endl;
    cout << "a. Them san pham" << endl;
    cout << "b. Sua so luong" << endl;
    cout << "c. Xoa san pham" << endl;
    cout << "d. Thoat" << endl;
    cout << "Chon (a-d): ";
}

void Menu::themSanPham(vector<SanPham>& danhSach) {
    SanPham sp;
    cout << "\n=== THEM SAN PHAM ===" << endl;
    cout << "Nhap ma: ";
    cin.ignore();
    getline(cin, sp.ma);
    
    cout << "Nhap ten: ";
    getline(cin, sp.ten);
    
    cout << "Nhap gia: ";
    cin >> sp.gia;
    
    cout << "Nhap so luong: ";
    cin >> sp.soLuong;
    
    danhSach.push_back(sp);
    cout << "Da them san pham!" << endl;
}

void Menu::suaSanPham(vector<SanPham>& danhSach) {
    string ma;
    cout << "\n=== SUA SAN PHAM ===" << endl;
    cout << "Nhap ma san pham can sua: ";
    cin.ignore();
    getline(cin, ma);
    
    for (auto& sp : danhSach) {
        if (sp.ma == ma) {
            cout << "Nhap ma moi (hien tai: " << sp.ma << "): ";
            getline(cin, sp.ma);
            
            cout << "Nhap ten moi: ";
            getline(cin, sp.ten);
            
            cout << "Nhap gia moi: ";
            cin >> sp.gia;
            
            cout << "Nhap so luong moi: ";
            cin >> sp.soLuong;
            
            cout << "Da sua san pham!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}

void Menu::xoaSanPham(vector<SanPham>& danhSach, const vector<DonHang>& donHangList) {
    string ma;
    cout << "\n=== XOA SAN PHAM ===" << endl;
    cout << "Nhap ma san pham can xoa: ";
    cin.ignore();
    getline(cin, ma);
    
    // Kiểm tra sản phẩm có trong đơn hàng không
    if (quanLyFile.kiemTraSanPhamTrongDon(ma, donHangList)) {
        cout << "Khong the xoa! San pham dang co trong don hang." << endl;
        return;
    }
    
    for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (it->ma == ma) {
            danhSach.erase(it);
            cout << "Da xoa san pham!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}

void Menu::taoDonHang(vector<DonHang>& danhSach, vector<SanPham>& sanPhamList) {
    DonHang dh;
    string ma, tenKhachHang, ngay;
    cout << "\n=== TAO DON HANG ===" << endl;
    cout << "Nhap ma don: ";
    cin.ignore();
    getline(cin, ma);
    dh.setMa(ma);
    
    cout << "Nhap ten khach hang: ";
    getline(cin, tenKhachHang);
    dh.setTenKhachHang(tenKhachHang);
    
    cout << "Nhap ngay (dd/mm/yyyy): ";
    getline(cin, ngay);
    dh.setNgay(ngay);
    
    char tiep;
    do {
        string maSP;
        int soLuong;
        
        cout << "Nhap ma san pham: ";
        getline(cin, maSP);
        
        bool timThay = false;
        for (auto& sp : sanPhamList) {
            if (sp.ma == maSP) {
                timThay = true;
                cout << "Nhap so luong: ";
                cin >> soLuong;
                cin.ignore();
                
                if (soLuong <= sp.soLuong) {
                    ChiTietDon ct(maSP, soLuong);
                    dh.themSanPham(ct);
                    
                    // Giảm số lượng trong kho
                    sp.soLuong -= soLuong;
                    cout << "Da them san pham vao don!" << endl;
                } else {
                    cout << "So luong khong du!" << endl;
                }
                break;
            }
        }
        
        if (!timThay) {
            cout << "Khong tim thay san pham!" << endl;
        }
        
        cout << "Them san pham khac? (y/n): ";
        cin >> tiep;
        cin.ignore();
    } while (tiep == 'y' || tiep == 'Y');
    
    danhSach.push_back(dh);
    cout << "Da tao don hang!" << endl;
}

void Menu::suaDonHang(vector<DonHang>& danhSach, vector<SanPham>& sanPhamList) {
    string ma;
    cout << "\n=== SUA DON HANG ===" << endl;
    cout << "Nhap ma don can sua: ";
    cin.ignore();
    getline(cin, ma);
    
    DonHang* dh = nullptr;
    for (auto& d : danhSach) {
        if (d.getMa() == ma) {
            dh = &d;
            break;
        }
    }
    
    if (!dh) {
        cout << "Khong tim thay don hang!" << endl;
        return;
    }
    
    char luaChon;
    do {
        hienThiMenuDonHang();
        cin >> luaChon;
        cin.ignore();
        
        switch(luaChon) {
            case 'a': { // Thêm sản phẩm
                string maSP;
                int soLuong;
                
                cout << "Nhap ma san pham: ";
                getline(cin, maSP);
                
                bool timThay = false;
                for (auto& sp : sanPhamList) {
                    if (sp.ma == maSP) {
                        timThay = true;
                        cout << "Nhap so luong: ";
                        cin >> soLuong;
                        cin.ignore();
                        
                        ChiTietDon ct(maSP, soLuong);
                        dh->themSanPham(ct);
                        
                        // Giảm số lượng trong kho
                        sp.soLuong -= soLuong;
                        cout << "Da them san pham!" << endl;
                        break;
                    }
                }
                
                if (!timThay) cout << "Khong tim thay san pham!" << endl;
                break;
            }
            
            case 'b': { // Sửa số lượng
                string maSP;
                int soLuongMoi;
                
                cout << "Nhap ma san pham: ";
                getline(cin, maSP);
                
                bool timThay = false;
                for (auto& ct : dh->getDanhSachSanPham()) {
                    if (ct.getMaSanPham() == maSP) {
                        timThay = true;
                        cout << "Nhap so luong moi: ";
                        cin >> soLuongMoi;
                        cin.ignore();
                        
                        // Tìm sản phẩm trong kho để điều chỉnh
                        for (auto& sp : sanPhamList) {
                            if (sp.ma == maSP) {
                                int chechLech = soLuongMoi - ct.getSoLuong();
                                sp.soLuong -= chechLech;
                                break;
                            }
                        }
                        
                        ct.setSoLuong(soLuongMoi);
                        cout << "Da sua so luong!" << endl;
                        break;
                    }
                }
                
                if (!timThay) cout << "Khong tim thay san pham trong don!" << endl;
                break;
            }
            
            case 'c': { // Xóa sản phẩm
                string maSP;
                
                cout << "Nhap ma san pham can xoa: ";
                getline(cin, maSP);
                
                bool timThay = false;
                for (auto it = dh->getDanhSachSanPham().begin(); it != dh->getDanhSachSanPham().end(); ++it) {
                    if (it->getMaSanPham() == maSP) {
                        timThay = true;
                        
                        // Trả lại số lượng vào kho
                        for (auto& sp : sanPhamList) {
                            if (sp.ma == maSP) {
                                sp.soLuong += it->getSoLuong();
                                break;
                            }
                        }
                        
                        dh->getDanhSachSanPham().erase(it);
                        cout << "Da xoa san pham khoi don!" << endl;
                        break;
                    }
                }
                
                if (!timThay) cout << "Khong tim thay san pham trong don!" << endl;
                break;
            }
            
            case 'd':
                cout << "Thoat sua don hang!" << endl;
                break;
                
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (luaChon != 'd');
}

void Menu::xoaDonHang(vector<DonHang>& danhSach) {
    string ma;
    cout << "\n=== XOA DON HANG ===" << endl;
    cout << "Nhap ma don can xoa: ";
    cin.ignore();
    getline(cin, ma);
    
    for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (it->getMa() == ma) {
            danhSach.erase(it);
            cout << "Da xoa don hang!" << endl;
            return;
        }
    }
    cout << "Khong tim thay don hang!" << endl;
}

void Menu::xemSanPham(const vector<SanPham>& danhSach) {
    cout << "\n=== DANH SACH SAN PHAM ===" << endl;
    if (danhSach.empty()) {
        cout << "Khong co san pham nao!" << endl;
        return;
    }
    
    cout << left << setw(10) << "Ma" << setw(20) << "Ten" << setw(10) << "Gia" << setw(10) << "So luong" << endl;
    cout << string(50, '-') << endl;
    for (const auto & sp : danhSach) {
        cout << left << setw(10) << sp.ma << setw(20) << sp.ten << setw(10) << sp.gia << setw(10) << sp.soLuong << endl;
    }
}

void Menu::xemDonHang(const vector<DonHang>& danhSach, const vector<SanPham>& sanPhamList) {
    cout << "\n=== DANH SACH DON HANG ===" << endl;
    if (danhSach.empty()) {
        cout << "Khong co don hang nao!" << endl;
        return;
    }
    
    for (const auto& dh : danhSach) {
        cout << "\n" << string(60, '=') << endl;
        cout << "Ma DH: " << dh.getMa() << endl;
        cout << "Khach hang: " << dh.getTenKhachHang() << endl;
        cout << "Ngay: " << dh.getNgay() << endl;
        cout << "Danh sach san pham:" << endl;
        cout << left << setw(10) << "Ma SP" << setw(20) << "Ten" << setw(10) << "So luong" << endl;
        cout << string(60, '-') << endl;
        for (const auto& ct : dh.getDanhSachSanPham()) {
            // Tim ten san pham
            string tenSP = "---";
            for (const auto& sp : sanPhamList) {
                if (sp.ma == ct.getMaSanPham()) {
                    tenSP = sp.ten;
                    break;
                }
            }
            cout << left << setw(10) << ct.getMaSanPham() << setw(20) << tenSP << setw(10) << ct.getSoLuong() << endl;
        }
    }
}