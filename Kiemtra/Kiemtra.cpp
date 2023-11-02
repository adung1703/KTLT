#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	typedef struct {
		int sothedv;
		string tendangvien;
		int Ngayvaodang;
		int Thangvaodang;
		int Namvaodang;
		string chucvudang;
		float Luong;
		float Dangphi;
		float tienphucap;
		float phaidong;
		
	} DangVien ;
	typedef struct {
		string TenCB;
		string Diachi;
		int sodangvien;
		float TongLuong;
		float TongDangPhiThu;
		float Chibogiulai;
		float Nopcaptren;
		float Tongtrocap;
		DangVien dv[];
		
	} Chibo;
	
	cout << "Nguyen Huu Dung - 20215545 - 727639 - 2022.2 - IT3040:**	CHUONG TRINH QUAN LY Chi bo - Dang Vien **" << endl;
	cout << "**1. Nhap cac chi bo				**" << endl;
	cout << "**2. In ket qua ds Chi bo Dang vien**" << endl;
	cout << "**0. Thoat 						**" << endl;
	cout << "*************************************" << endl;
	
	int t;
	do {
		cout << "**		Nhap lua chon cua ban		**" << endl;
		Chibo cb[n];
		cin >> t;
		if (t==1) {
			cout << "Ban da chon nhap danh sach chi bo" << endl;
			cout << "Nhap so chi bo: " ;
			cin >> n;
			for (int i = 0 ; i < n ; i++) {
				cout << "Nhap thong tin chi bo thu " << i+1 << endl;
				
				cout << "\nTen Chi Bo: " ;
				cin.ignore();
				getline(cin, cb[i].TenCB);
				
				cout << "\nSo dang vien: ";
				cin >> cb[i].sodangvien;
				
				cb[i].TongLuong = 0;
				cb[i].Tongtrocap = 0;
				cout << "\nNhap danh sach dang vien:";
				
				for (int j = 0; j < cb[i].sodangvien; j++) {
					cout << "\nDang vien thu " << j+1;
					
					cout << "\n\tSo the: ";
					cin >> cb[i].dv[j].sothedv;
					
					cout << "\n\tTen Dang Vien: ";
					cin.ignore();
					getline (cin, cb[i].dv[j].tendangvien);
					
					cout << "\n\tNgay vao dang: ";
					cout << "\n\tNgay: ";
					cin >> cb[i].dv[j].Ngayvaodang;
					cout << "\tThang: ";
					cin >> cb[i].dv[j].Thangvaodang;
					cout << "\tNam: ";
					cin >> cb[i].dv[j].Namvaodang;
					
					cout << "\n\tLuong: ";
					cin >> cb[i].dv[j].Luong;
					cb[i].TongLuong += cb[i].dv[j].Luong;
					cb[i].dv[j].Dangphi = 0.01*cb[i].dv[j].Luong;
					
					cout << "\n\tChuc vu: ";
					cin.ignore();
					getline (cin, cb[i].dv[j].chucvudang);
				
					if (cb[i].dv[j].chucvudang == "BiThu") cb[i].dv[j].tienphucap = 0.05*cb[i].dv[j].Luong;					
					else if (cb[i].dv[j].chucvudang == "PBThu" ) cb[i].dv[j].tienphucap = 0.025*cb[i].dv[j].Luong;
					else if (cb[i].dv[j].chucvudang == "Uyvien") cb[i].dv[j].tienphucap = 0.015*cb[i].dv[j].Luong;
					else cb[i].dv[j].tienphucap = 0;
					cb[i].Tongtrocap += cb[i].dv[j].tienphucap;
				}
				cb[i].TongDangPhiThu = 0.01*cb[i].TongLuong;
				cb[i].Chibogiulai = 0.7*cb[i].TongDangPhiThu;
				cb[i].Nopcaptren = 0.3*cb[i].TongDangPhiThu;
			}
		cout << "Bam phim bat ki de tiep tuc!" << endl;
		}
		else if (t==2) {
			cout << "Ban da chon xuat danh sach chi bo" << endl;
			cout << "__________________________________________________________________________________________________________________________" << endl;
			float TongLuong = 0 , Dangphithu = 0, Nopcaptren = 0;
			for (int i = 0 ; i < n ; i++) {
				cout << "Ten Chi Bo: " << cb[i].TenCB << endl;
				
				cout << "So dang vien: " << cb[i].sodangvien << endl;
				
				cout << "Tong Luong: " << cb[i].TongLuong << endl;
				
				cout << "Tong Thu Dang Phi: " << cb[i].TongDangPhiThu << endl;
				
				cout << "Tong nop DP Cap tren: " << cb[i].Nopcaptren << endl;
				
				cout << "Tong tro cap chuc vu: " << cb[i].Tongtrocap << endl;
				
				cout << "Bang thu Dang phi: " << endl;
				
				cout << " Sothe \tHotenDV \tNgayvaodang \tTuoidang \tChucvu \tTrocap \tLuong \tDangPhi" << endl;
				
				for (int j = 0; j < cb[i].sodangvien; j++) {
					cout << cb[i].dv[j].sothedv << " \t" << cb[i].dv[j].tendangvien << " \t" << cb[i].dv[j].Ngayvaodang << "-" << cb[i].dv[j].Thangvaodang <<
					"-" << cb[i].dv[j].Namvaodang << " \t" << 2022 - cb[i].dv[j].Namvaodang << " \t" << cb[i].dv[j].chucvudang << " \t" << cb[i].dv[j].tienphucap <<
					" \t" << cb[i].dv[j].Luong << " \t" << cb[i].dv[j].Dangphi;
				}
				cout << "__________________________________________________________________________________________________________________________" << endl;
			TongLuong += cb[i].TongLuong;
			Dangphithu += cb[i].TongDangPhiThu;
			Nopcaptren += cb[i].Nopcaptren;	
			}
			cout << "Tong Luong cac chi bo: " << TongLuong << endl;
			cout << "Tong Dang phi thu duoc: " << Dangphithu << endl;
			cout << "Tong nop cap tren: " << Nopcaptren << endl;
			cout << "__________________________________________________________________________________________________________________________" << endl;
			cout << "Bam phim bat ki de tiep tuc!" << endl;
		}
		else if (t == 0) {
			cout << "Ban da thoat chuong trinh!" << endl;
		}
	} while (t != 0);

	return 0;
} 


