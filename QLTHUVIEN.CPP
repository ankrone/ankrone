#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime> //Ham lay thoi gian hien tai tu may tinh
#include <conio.h>
#include <fstream>

#define MAX 100

using namespace std;

fstream file; //Khai bao file
int n = 0; //So luong sach co trong du lieu

//Khai bao struct date
struct date {
    int ng;
    int th;
    int nam;
};
//Khai bao struct ThuVien
struct ThuVien {
	int id;//Ma sach
	string tensach;
	string theloai;
	int soluong;
	int namsx;
	string tacgia;
	string ten_nm;
	int ngay, thang, nam;
    struct date ngTra;// Ngay tra
};

typedef ThuVien TV;
//Ham cho Ma sach tu dong tang dan
int idLonNhat(TV a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for (int i = 0; i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
//Ham nhap sach
void themTV(TV& tv, int id) {
    cout << "\nNhap ten sach: ";
    cin.ignore();
    getline(cin, tv.tensach);
    cout << "Nhap the loai sach: ";
    fflush(stdin);
    getline(cin, tv.theloai);
    cout << "Nhap so luong sach: ";
    cin >> tv.soluong;
    cout << "Nhap nam xuat ban: ";
    cin >> tv.namsx;
    cout << "Nhap ten tac gia: ";
    fflush(stdin);
    getline(cin, tv.tacgia);
    cout << "Nhap ten nguoi muon: ";
    getline(cin, tv.ten_nm);
    do {
        cout << "Nhap ngay muon: ";
        cin >> tv.ngay;
    } while (tv.ngay < 1 || tv.ngay > 31);
    do {
        cout << "Nhap thang muon: ";
        cin >> tv.thang;
    } while (tv.thang < 1 || tv.thang > 12);
    do {
        cout << "Nhap nam muon: ";
        cin >> tv.nam;
    } while (tv.nam < 1);
    do {
        cout << "Nhap ngay tra: ";
        cin >> tv.ngTra.ng;
    } while (tv.ngTra.ng < 1 || tv.ngTra.ng > 31);
    do {
        cout << "Nhap thang tra: ";
        cin >> tv.ngTra.th;
    } while (tv.ngTra.th < 1 || tv.ngTra.th > 12);
    do {
        cout << "Nhap nam tra: ";
        cin >> tv.ngTra.nam;	
    } while (tv.ngTra.nam < 1);
    tv.id = id;
}
//Ham them sach va in ra file 
void nhapTV(TV a[], int id, int n) {
    int i;
	cout << "\n Nhap thong tin sach thu " << n + 1;
    themTV(a[n], id);
    //
    file.open("QLTHUVIEN.DAT", ios_base::app | ios_base::out);
    file << a[i].id << " " << a[i].tensach << " " << a[i].theloai << " " << a[i].soluong << " " << a[i].namsx << " "
    	 << a[i].tacgia << " " << a[i].ten_nm << " " << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam << " "
    	 << a[i].ngTra.ng << "/" << a[i].ngTra.th << "/" << a[i].ngTra.nam << endl;	 
    file.close();
}
//Ham cap nhat so luong sach co trong file
void capnhat_file(TV& tv){
	fstream file;
	file.open("QLTHUVIEN.DAT", ios_base::in);
	file >> tv.id >> tv.tensach >> tv.theloai >> tv.soluong >> tv.namsx
    	 >> tv.tacgia >> tv.ten_nm >> tv.ngay >> tv.thang >> tv.nam
    	 >> tv.ngTra.ng >> tv.ngTra.th >> tv.ngTra.nam;	 
	while(!file.eof()) {
    	file >> tv.id >> tv.tensach >> tv.theloai >> tv.soluong >> tv.namsx
    	 	 >> tv.tacgia >> tv.ten_nm >> tv.ngay >> tv.thang >> tv.nam
    	 	 >> tv.ngTra.ng >> tv.ngTra.th >> tv.ngTra.nam;
	}
	if (tv.id != 0) {
		n = tv.id;
	}
	file.close();
}
//Ham doc file 
void doc_file(TV a[], int n){
	fstream file;
	int i;
	file.open("QLTHUVIEN.DAT", ios_base::in);
	file >> a[i].id >> a[i].tensach >> a[i].theloai >> a[i].soluong >> a[i].namsx
    	 >> a[i].tacgia >> a[i].ten_nm >> a[i].ngay >> a[i].thang >> a[i].nam
    	 >> a[i].ngTra.ng >> a[i].ngTra.th >> a[i].ngTra.nam;	 
    while(!file.eof()) {
    	file >> a[i].id >> a[i].tensach >> a[i].theloai >> a[i].soluong >> a[i].namsx
    	 	 >> a[i].tacgia >> a[i].ten_nm >> a[i].ngay >> a[i].thang >> a[i].nam
    	 	 >> a[i].ngTra.ng >> a[i].ngTra.th >> a[i].ngTra.nam;
	}
	file.close();
}
//Ham in ra danh sach 
void danhsach(TV a[], int n) {
    cout << "====================================================================================================================================================================" << endl;
	cout << setw(5) << left << "STT";
    cout << setw(20) << left << "MA SACH";
    cout << setw(20) << left << "TEN SACH";
    cout << setw(20) << left << "THE LOAI";
    cout << setw(20) << left << "SO LUONG";
    cout << setw(20) << left << "NAM XUAT BAN";
    cout << setw(20) << left << "TAC GIA";
    cout << setw(20) << left << "TEN NGUOI MUON";
    cout << setw(20) << left << "NGAY MUON";
    cout << setw(20) << left << "NGAY TRA";
    cout << endl;
    cout << "====================================================================================================================================================================" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << left << i + 1;
        cout << setw(20) << left << a[i].id;
        cout << setw(20) << left << a[i].tensach;
        cout << setw(20) << left << a[i].theloai;
        cout << setw(20) << left << a[i].soluong;
        cout << setw(20) << left << a[i].namsx;
        cout << setw(20) << left << a[i].tacgia;
        cout << setw(20) << left << a[i].ten_nm;
        cout << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam;
        cout << "\t     ";
        cout << a[i].ngTra.ng << "/" << a[i].ngTra.th << "/" << a[i].ngTra.nam;
        cout << endl;
    }
}
//Ham sap xep giam dan theo namsx va in ra file
void sapxep(TV a[], int n) {
	TV tmp;
	for (int i = 0;i < n; i++) {
		for (int j = i + 1;j < n; j++) {
			if (a[i].namsx < a[j].namsx) {
				tmp = a[i];
				a[i]= a[j];
				a[j] = tmp;
			}
		}
	}
	file.open("QLTHUVIEN.DAT", ios_base::trunc | ios_base::out);
	int i = 0;
	while(i < n) {
    	file << a[i].id << " " << a[i].tensach << " " << a[i].theloai << " " << a[i].soluong << " " << a[i].namsx << " "
    	 	 << a[i].tacgia << " " << a[i].ten_nm << " " << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam << " "
    	 	 << a[i].ngTra.ng << "/" << a[i].ngTra.th << "/" << a[i].ngTra.nam << endl;	 
			i++;
	}
	file.close();
}
//Ham in ra danh sach dang muon tinh toi ngay hien tai
void danhsachmuon(TV a[], int n) {
	int ngay,thang,nam;
	tm *today;
	time_t ltime;
	time(&ltime);
	today = localtime(&ltime);
	ngay = today->tm_mday;
	thang = today->tm_mon + 1;
	nam = today->tm_year + 1900;
	cout << "           Ngay hien tai: " << ngay << "/" << thang << "/" << nam << endl; 
	cout << "============================================================================================================================================================================" << endl;
	cout << setw(5) << left << "STT";
    cout << setw(20) << left << "MA SACH";
    cout << setw(20) << left << "TEN SACH";
    cout << setw(20) << left << "THE LOAI";
    cout << setw(20) << left << "SO LUONG";
    cout << setw(20) << left << "NAM XUAT BAN";
    cout << setw(20) << left << "TAC GIA";
    cout << setw(20) << left << "TEN NGUOI MUON";
    cout << setw(20) << left << "NGAY MUON";
    cout << setw(20) << left << "NGAY TRA";
    cout << endl;
	for (int i = 0;i < n; i++) {
		if ((ngay != a[i].ngTra.ng && ngay < a[i].ngTra.ng && thang <= a[i].ngTra.th ) || (thang != a[i].ngTra.th && thang < a[i].ngTra.th)) {
			cout << setw(5) << left << i + 1;
        	cout << setw(20) << left << a[i].id;
        	cout << setw(20) << left << a[i].tensach;
        	cout << setw(20) << left << a[i].theloai;
        	cout << setw(20) << left << a[i].soluong;
        	cout << setw(20) << left << a[i].namsx;
        	cout << setw(20) << left << a[i].tacgia;
        	cout << setw(20) << left << a[i].ten_nm;
        	cout << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam;
        	cout << "\t     ";
        	cout << a[i].ngTra.ng << "/" << a[i].ngTra.th << "/" << a[i].ngTra.nam;
        	cout << endl;
		}
	}
	for (int i = 0;i < n; i++) {
		if (ngay >= a[i].ngTra.ng && thang >= a[i].ngTra.th) {
			cout <<"Khong co sach nao dang muon tinh toi ngay hien tai." <<endl;
			break;
		}
	}
} 

void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}

int main() {
    int i;
	int key;
    TV arr[MAX], tv;
    int n = 0;
    int idCount = 0;
	idCount = idLonNhat(arr, n);
	capnhat_file(tv);
    doc_file(arr, n);
    while (true) {
        cout << "        CHUONG TRINH QUAN LY THU VIEN\n";
        cout <<  " ||-=-=-=-=-=-=-=-=-=-MENU-=-=-=-=-=-=-=-=-||\n";
        cout << "||        1.Them sach                       ||\n";
    	cout << "||        2.In danh sach tu file.           ||\n";
        cout << "||        3.Danh sach.                      ||\n";
        cout << "||        4.Sap xep.                        ||\n";
        cout << "||        5.Danh sach muon sach.            ||\n";
        cout << "||        0.Thoat chuong trinh.             ||\n";
        cout <<  " ||-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=||\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
            case 1:
                cout << "\n1. Them sach va ghi vao file." << endl;
                idCount++;
                nhapTV(arr, idCount, n);
                n++;
                cout << "\nIn danh sach tu file thanh cong!!!";
                pressAnyKey();
                break;
            case 2:
            	if (n > 0) {
            		cout << "\n2.In danh sach tu file." << endl;
            		danhsach(arr, n);
            		cout << "\nIn danh sach tu file thanh cong!!!";
				}
				else {
					cout << "Danh sach trong!";
				}
				pressAnyKey();
				break;
            case 3:
                if (n > 0) {
                    cout << "\n3. Danh sach." << endl;
                    danhsach(arr, n);
                }
                else {
                    cout << "Danh sach trong!";
                }
                pressAnyKey();
                break;
            case 4:
            	if (n > 0) {
            		cout << "\n4. Sap xep giam dan theo nam." << endl;
            		sapxep(arr, n);
            		danhsach(arr, n);
				}else{
					cout << "Danh sach trong!";
				}
				pressAnyKey();
				break;
			case 5:
				if (n > 0) {
					cout << "\n5. Danh sach muon sach tinh den ngay hien tai: " << endl;
					danhsachmuon(arr, n);
				}else{
					cout << "Danh sach trong!";
				}
				pressAnyKey();
				break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nVui long chon chuc nang trong hop thoai!";
                pressAnyKey();
                break;
        }
    }
    system("pause");
    return 0;
}


