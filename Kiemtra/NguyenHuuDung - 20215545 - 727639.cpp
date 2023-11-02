#include <bits/stdc++.h>
using namespace std;

 

#define MAX 1000
#define CURRENT_YEAR 2023

 

typedef struct {
    int day;
    int month;
    int year;
} ngayvaodang;

 

typedef struct {
    string TenCB;
    string Diachi;
    int sodangvien;
    int tongluong;
    float tongdangphithu;
    float chibogiulai;
    float nopcaptren;
    float tongtrocap;
} chibo;

 

typedef struct {
    string sothedv;
    string tendangvien;
    ngayvaodang ngayDang;
    string chucvudang;
    int luong;
    float dangphi;
    float tienphucap;
    int phaidong;
} dangvien;

 

int sochibo;
int tongluong;
float tongdangphi;
float tongnop;

 

chibo CB[MAX];
dangvien DV[MAX][MAX];

 

void input() {
    cout << "Ban da chon nhap danh sach Chi bo - Dang vien!" << endl;
    for (int i = 0; i < sochibo; i++) {
        cout << endl;
        cout << "Nhap thong tin chi bo thu " << i+1 << ":" << endl;
        cout << endl;
        cout << "Ten chi bo: ";
        cin >> CB[i].TenCB;
        cout << endl;
        cout << "So dang vien: ";
        cin >> CB[i].sodangvien;
        cout << endl;
        cout << "Nhap danh sach Dang vien:" << endl;
        for (int j = 0; j < CB[i].sodangvien; j++) {
            cout << endl;
            cout << "Dang vien thu " << j+1 << ":" << endl;
            cout << endl;
            cout << "\t So the: ";
            cin >> DV[i][j].sothedv;
            cout << "\t Ten Dang vien: ";
            cin.ignore();
            getline(cin, DV[i][j].tendangvien);
            cout << "\t Ngay vao Dang: " << endl;
            cout << "\t \t Ngay: ";
            cin >> DV[i][j].ngayDang.day; 
            cout << "\t \t Thang: ";
            cin >> DV[i][j].ngayDang.month;
            cout << "\t \t Nam: ";
            cin >> DV[i][j].ngayDang.year;
            cout << "\t \t Luong: ";
            cin >> DV[i][j].luong;
            cout << "\t \t Chuc vu: ";
            cin >> DV[i][j].chucvudang;

            DV[i][j].dangphi = DV[i][j].luong * 0.01;

            if (DV[i][j].chucvudang == "BiThu") {
                DV[i][j].tienphucap = DV[i][j].luong * 0.05;
            }
            else if (DV[i][j].chucvudang == "PBThu") {
                DV[i][j].tienphucap = DV[i][j].luong * 0.025;
            }
            else if (DV[i][j].chucvudang == "Uyvien") {
                DV[i][j].tienphucap = DV[i][j].luong * 0.015;
            }
            else DV[i][j].tienphucap = 0;
        }
        for (int j = 0; j < CB[i].sodangvien; j++) {
            CB[i].tongluong += DV[i][j].luong;
            CB[i].tongdangphithu += DV[i][j].dangphi;
            CB[i].tongtrocap += DV[i][j].tienphucap;
        }

        CB[i].nopcaptren = CB[i].tongdangphithu * 0.3;
        CB[i].chibogiulai = CB[i].tongdangphithu * 0.7;

        tongluong += CB[i].tongluong;
        tongdangphi += CB[i].tongdangphithu;
        tongnop += CB[i].nopcaptren;
    }
    cout << endl;
    cout << "Da nhap xong! Bam phim bat ky de tiep tuc!" << endl;
}

 

void print() {
    cout << "Ban da chon xuat chi bo!" << endl;

    for (int i = 0; i < sochibo; i++) {
        cout << "Ten Chi bo: " << CB[i].TenCB << endl;
        cout << "So Dang vien: " << CB[i].sodangvien << endl;
        cout << "Tong luong: " << CB[i].tongluong << endl;
        cout << "Tong thu Dang phi: " << CB[i].tongdangphithu << endl;
        cout << "Tong nop DP cap tren: " << CB[i].nopcaptren << endl;
        cout << "Tong tro cap chuc vu: " << CB[i].tongtrocap << endl;
        cout << endl;
        cout << "Bang thu Dang phi: " << endl;
        cout << endl;
        cout << setw(5) << left << "Sothe" << "  |  " 
<< setw(15) << left << "HotenDV" << "  |  " 
<< setw(15) << left << "Ngayvaodang" << "  |  "
<< setw(8) << left << "Tuoidang" << "  |  "
<< setw(10) << left << "Chucvu" << "  |  "
<< setw(8) << left << "Trocap" << "  |  "
<< setw(10) << left << "Luong" << "  |  "
<< setw(10) << left << "Dang phi" << endl;

 

        for (int j = 0; j < CB[i].sodangvien; j++) {
            cout << setw(5) << left << DV[i][j].sothedv << "  |  " 
<< setw(15) << left << DV[i][j].tendangvien << "  |  " 
<< setw(1) << left << DV[i][j].ngayDang.day << "-" << setw(1) << left << DV[i][j].ngayDang.month << "-" << setw(3) << left << DV[i][j].ngayDang.year << "       |  "
<< setw(8) << left << CURRENT_YEAR - DV[i][j].ngayDang.year << "  |  "
<< setw(10) << left << DV[i][j].chucvudang << "  |  "
<< setw(8) << left << DV[i][j].tienphucap << "  |  "
<< setw(10) << left << DV[i][j].luong << "  |  "
<< setw(10) << left << DV[i][j].dangphi << endl;
        }
        cout << endl;    
    }

 

    cout << endl << endl;

    cout << "Tong luong cac chi bo: " << tongluong << endl;
    cout << "Tong dang phi thu duoc: " << tongdangphi << endl;
    cout << "Tong nop cap tren: " << tongnop << endl;
    cout << "------------------------------------------" << endl;
    cout << "Da xuat xong! Bam phim bat ky de tiep tuc!" << endl;
}

 

int main () {
    cout << "Nguyen Huu Dung - 20215545 - 727639 - 2022.2 - IT3040" << endl;
    cout << "**CHUONG TRINH QUAN LY CHI BO - DANG VIEN**" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Nhap so chi bo: ";
    cin >> sochibo;
    cout << "---------------------------------------" << endl;

    int option;

    do {
        cout << "**1. Nhap cac chi bo." << endl;
        cout << "**2. In ket qua danh sach cac chi bo - dang vien." << endl;
        cout << "**0. Thoat" << endl;
        cout << "---------------------------------------" << endl;
        cout << "**       Nhap lua chon cua ban       **" << endl;

 

        cin >> option;

        if (option == 1) {
            input();
        }
        if (option == 2) {
            print();
        }
        if (option == 0) {
            cout << "Ban da chon thoat chuong trinh! Chao tam biet" << endl;
            exit(0);
        }
    } while (1);

    return 0;
}
