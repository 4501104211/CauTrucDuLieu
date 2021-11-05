#include "Library.h"
#include "LinkedList.h"
#include "Graphic.h"

using namespace std;

#pragma execution_character_set("utf-8");
#pragma warning(disable:4996)
#define LIGHTBLUE textcolor(59);
#define BLUE textcolor(9);
#define GREEN textcolor(10);
#define WHITE textcolor(15);
#define RED textcolor(4);
#define YELLOW textcolor(14);
#define LISTADMIN LinkedList<Admin> listAdmin, LinkedList<DonHang> listDonHang, LinkedList<HangHoa>listHangHoa
#define CALLLIST listAdmin,listDonHang,listHangHoa
#define ClearSceen system("cls");   

using namespace std; 
// Show màn hình
void showLoginAdmin(LISTADMIN);
void showAccessAdmin(LISTADMIN);


// check login
bool checkLoginAdmin(string user, string password, LinkedList<Admin> listAdmin);


// tạo khung
void setKhung(LISTADMIN);

// Hàm tìm kiếm
void timKiemTheoTen(LinkedList<HangHoa>listHangHoa);
void timKiem(LISTADMIN);
//Hàm uppdate
void updateHH(LISTADMIN);
void updateDH(LISTADMIN);

// Hàm đặt hàng
void datHang(LISTADMIN);

// Hàm truyền dữ liệu hàng hóa
void thongTinHangHoa(LISTADMIN);

// Hàm load dữ liệu
void loadAdmin(LinkedList<Admin>& listAdmin);
void loadHangHoa(LinkedList<HangHoa>& listHangHoa);

// Ham Cua Quan Ly
void showQuanLyHangHoa(LISTADMIN);
void showQuanLy(LISTADMIN);
void themHangHoa(LISTADMIN);
void xoaHangHoa(LISTADMIN);
void xuLyDonHang(LISTADMIN);
void loadDonHang(LinkedList<DonHang>& listDonHang);
BOOL WINAPI SetConsoleOutputCP(_In_ UINT wCodePageID);
int main() {
	SetConsoleOutputCP(65001);
	resizeConsole(950,600);
	LinkedList<Admin> listAdmin;
	LinkedList<DonHang> listDonHang;
    LinkedList<HangHoa>listHangHoa;
	loadAdmin(listAdmin);
	loadHangHoa(listHangHoa);
	loadDonHang(listDonHang);
	//loadDonHang(listDonHang);
	//thongTinHangHoa(CALLLIST);
	showLoginAdmin(CALLLIST);
	showAccessAdmin(CALLLIST);
	system("pause >nul");
} 

void inputPassword(string& pw) {
	char cPass[32];
	int i = 0;
	char _cA;
	for (i = 0;;) {
		_cA = _getch();
		if ((_cA >= 'a' && _cA <= 'z') || (_cA >= 'A' && _cA <= 'Z') || (_cA >= '0' && _cA <= '9')) {
			cPass[i] = _cA;
			++i;
			cout << "*";
		}
		if (_cA == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		if (_cA == '\r') {
			cPass[i] = '\0';
			break;
		}
	}
	for (int z = 0; z < i; z++) {
		pw.push_back(cPass[z]);
	}
}

void showLoginAdmin(LISTADMIN) {
	setKhung(CALLLIST);
	bool _bA = false;
	while (!_bA) {
		GREEN
			gotoxy(42, 15); cout << "** ** ** ** ** ** ** ** ** ** ";
		gotoxy(42, 16); cout << "** "; WHITE cout << "   Đăng nhập hệ thống   "; GREEN cout << "**" << endl;
		gotoxy(42, 17);  cout << "** ** ** ** ** ** ** ** ** **";
		gotoxy(42, 18); BLUE cout << "User     :";
		gotoxy(42, 19); BLUE cout << "Password :";
		gotoxy(53, 18); WHITE string user = ""; cin >> user;
		gotoxy(53, 19); WHITE string password; inputPassword(password);
		gotoxy(41, 20);
		if (checkLoginAdmin(user, password, listAdmin)) {
			BLUE cout << "Đăng nhập thành công"; _bA = true;
			Sleep(1000);
			ClearSceen
				setKhung(CALLLIST);
			showAccessAdmin(CALLLIST);
		}
		else {
			RED
				cout << "===>Vui lòng nhập lại <===";
			Sleep(1000);
			ClearSceen
				setKhung(CALLLIST);
		}
	}
}
void showAccessAdmin(LISTADMIN) {
	setKhung(CALLLIST);
	ToMau(32, 13, " * * * * * * * * *MENU* * * * * * * * * *", 14);
	ToMau(40, 14, "1. Hiện thị thông tin hàng hóa", 202);
	ToMau(40, 15, "2. Tìm kiếm thông tin hàng hóa", 14);
	ToMau(40, 16, "3. Đặt hàng", 14);
	ToMau(40, 17, "4. Quản lý", 14);
	ToMau(40, 18, "5. thoát", 14);
	ToMau(30, 19, "	* * * * * * * * * * * * * * * * * * * * *", 14);
	int _iChoose = 0;
	int _iToaDo = 14;
	do {
		char _cA = _getch();
		if (_cA == 80) _iChoose = 1; //bắt sự kiện nút lên 
		else if (_cA == 72) _iChoose = 2;//bắt sự kiện nút enter  
		else if (_cA == 13) _iChoose = 3; // //bắt sự kiện nút xuống
		else _iChoose = 0;
		if (_iChoose == 1 && _iToaDo < 19) _iToaDo++;
		else if (_iChoose == 2 && _iToaDo > 13) _iToaDo--;
		if (_iToaDo == 14) {
			ToMau(40, 14, "1. Hiện thị thông tin hàng hóa", 202);
			ToMau(40, 15, "2. Tìm kiếm thông tin hàng hóa", 14);
			ToMau(40, 16, "3. Đặt hàng", 14);
			ToMau(40, 17, "4. Quản lý", 14);
			ToMau(40, 18, "5. thoát", 14);
		}
		if (_iToaDo == 15) {
			ToMau(40, 14, "1. Hiện thị thông tin hàng hóa", 14);
			ToMau(40, 15, "2. Tìm kiếm thông tin hàng hóa", 202);
			ToMau(40, 16, "3. Đặt hàng", 14);
			ToMau(40, 17, "4. Quản lý", 14);
			ToMau(40, 18, "5. thoát", 14);
		}
		if (_iToaDo == 16) {
			ToMau(40, 14, "1. Hiện thị thông tin hàng hóa", 14);
			ToMau(40, 15, "2. Tìm kiếm thông tin hàng hóa", 14);
			ToMau(40, 16, "3. Đặt hàng", 202);
			ToMau(40, 17, "4. Quản lý", 14);
			ToMau(40, 18, "5. thoát", 14);
		}
		if (_iToaDo == 17) {
			ToMau(40, 14, "1. Hiện thị thông tin hàng hóa", 14);
			ToMau(40, 15, "2. Tìm kiếm thông tin hàng hóa", 14);
			ToMau(40, 16, "3. Đặt hàng", 14);
			ToMau(40, 17, "4. Quản lý", 202);
			ToMau(40, 18, "5. thoát", 14);
		}
		if (_iToaDo == 18) {
			ToMau(40, 14, "1. Hiện thị thông tin hàng hóa", 14);
			ToMau(40, 15, "2. Tìm kiếm thông tin hàng hóa", 14);
			ToMau(40, 16, "3. Đặt hàng", 14);
			ToMau(40, 17, "4. Quản lý", 14);
			ToMau(40, 18, "5. thoát", 202);
		}
	} while (_iChoose != 3);
	ClearSceen
		if (_iToaDo == 14) {  ClearSceen thongTinHangHoa(CALLLIST); }
		else if (_iToaDo == 15) {ClearSceen timKiem(CALLLIST);}
				
		else if (_iToaDo == 16) { ClearSceen datHang(CALLLIST); }
		else if (_iToaDo == 17)  { ClearSceen showQuanLy(CALLLIST); }
		else if (_iToaDo == 18) { showLoginAdmin(CALLLIST); }
}

bool checkLoginAdmin(string user, string password, LinkedList<Admin> listAdmin) {
	Admin z(user, password);
	return (listAdmin.checkAdmin(z));
}

void setKhung(LISTADMIN) {

	int iSampleFrame = 14;
	ToMau(1, 1 , "==================================================================================================================", iSampleFrame);
	int _iX = 2;
	for (int i = 0; i < 34; i++) {
		ToMau(1, _iX, "=", iSampleFrame);
		ToMau(114, _iX, "=", iSampleFrame);
		_iX++;
	}
	ToMau(1, 35, "==================================================================================================================", iSampleFrame);
	gotoxy(1, 1);
}
// Hàm tìm kiếm
void timKiemTheoTen(LinkedList<HangHoa>listHangHoa) {
	string tenHang;
	cin >> tenHang;
	HangHoa a("", tenHang,"","","","","","");
	listHangHoa.setValue(a);
	
}
void timKiem(LISTADMIN){
	ClearSceen
	ToMau(32, 11, "                TÌM HÀNG HÓA         ", 15);
	gotoxy(40, 12);  YELLOW cout << "      -------------------       ";
	ToMau(33, 14, "Tên hàng cần tìm   : ", 11);
	string tenHang;
	cin >> tenHang;
	string maHangHoa, tenHangHoa, noiSanXuat, giBan, mauSac, ngayNhapKho, soLuong;
	HangHoa a("", tenHang, "", "", "", "", "", "");
	listHangHoa.setValue(a);
	ClearSceen
	if (listHangHoa.search5(a)){
		int iNumberLines = 4;
		int iColorTitle = 11;
		int iQuantity = listHangHoa.getSize();
		ToMau(52, 2, "Nơi sản xuất", iColorTitle);
		ToMau(74, 2, "Giá bán", iColorTitle);
		int sColorInformations = 0;
		ToMau(1, 1, "||==============================================================================================================================================||", 9);
		ToMau(1, 2, "||               ||                            ||               ||                     ||          ||                         ||                ||", 9);
		ToMau(5, 2, "Mã hàng hóa", iColorTitle);
		ToMau(23, 2, "Tên hàng hóa", iColorTitle);
		ToMau(90, 2, "Màu sắc", iColorTitle);
		ToMau(110, 2, "Ngày nhập kho", iColorTitle);
		ToMau(133, 2, "Số lượng", iColorTitle);
		ToMau(1, 3, "||==============================================================================================================================================||", 9);
		for (int i = 0; i < iQuantity; i++) {
			listHangHoa.setValue(a);
			ToMau(5, iNumberLines, a.getMaHangHoa(), 12);
			ToMau(23, iNumberLines, a.getTen(), 12);
			ToMau(52, iNumberLines, a.getNoiSanXuat(), 12);
			ToMau(74, iNumberLines, a.getGiaBan(), 12);
			ToMau(90, iNumberLines, a.getMauSac(), 12);
			ToMau(110, iNumberLines, a.getNgayNhapKho(), 12);
			ToMau(133, iNumberLines, a.getSoLuong(), 12);
			iNumberLines++;
		}
	}
	else
	{
		ToMau(32, 18, "# Hàng hóa không tồn tại!", 12);
		Sleep(1000);
		ClearSceen
		showAccessAdmin(CALLLIST);
	}
}
// Hàm truyền dữ liệu hàng hóa
void thongTinHangHoa(LISTADMIN) {
	ClearSceen
		resizeConsole(1202, 700);
		int iNumberLines = 4;
	int iColorTitle = 11;
	int iQuantity = listHangHoa.getSize();
	int sColorInformations = 0;
	ToMau(1, 1, "||==============================================================================================================================================||", 9);
	ToMau(1, 2, "||               ||                            ||               ||                     ||          ||                         ||                ||", 9);
	ToMau(5, 2, "Ma hang hoa", iColorTitle);
	ToMau(23, 2, "Ten hang hoa", iColorTitle);
	ToMau(52, 2, "Noi san xuat", iColorTitle);
	ToMau(74, 2, "Gia Ban", iColorTitle);
	ToMau(90, 2, "Mau sac", iColorTitle); 
	ToMau(110, 2, "Ngay nhap kho", iColorTitle);
	ToMau(133, 2, "So luong", iColorTitle);
	ToMau(1, 3, "||==============================================================================================================================================||", 9);
	for (int i = 0; i < iQuantity; i++) {
		HangHoa tmp;
		tmp = listHangHoa[i];
		ToMau(5, iNumberLines, tmp.getMaHangHoa(), 12);
		ToMau(23, iNumberLines, tmp.getTen(), 12);
		ToMau(52, iNumberLines, tmp.getNoiSanXuat(), 12);
		ToMau(74, iNumberLines, tmp.getGiaBan(), iColorTitle);
		ToMau(90, iNumberLines, tmp.getMauSac(), iColorTitle);
		ToMau(110, iNumberLines, tmp.getNgayNhapKho(), 12);
		ToMau(133, iNumberLines, tmp.getSoLuong(), 12);
	ToMau(1, iNumberLines, "||", 9);
	ToMau(18, iNumberLines, "||", 9);
	ToMau(48, iNumberLines, "||", 9);
	ToMau(65, iNumberLines, "||", 9);
	ToMau(88, iNumberLines, "||", 9);
	ToMau(100, iNumberLines, "||", 9);
	ToMau(127, iNumberLines, "||", 9);
	ToMau(145, iNumberLines, "||", 9);
		iNumberLines++;
	}
	ToMau(1, iNumberLines, "||==============================================================================================================================================||", 9);
	char _cA = _getch();
	if (_cA != '+') { ClearSceen showAccessAdmin(CALLLIST); }
}

// Hàm load dữ liệu
void loadAdmin(LinkedList<Admin>& listAdmin)
{
	ifstream f;
	f.open("Admin.txt");
	while (!f.eof()) {
		bool _bA = false;
		string sU, sP, stmp;
		getline(f, stmp);
		for (int i = 0; i < stmp.size(); i++) {
			if (stmp[i] == ' ') _bA = true;
			else if (_bA == false) sU.push_back(stmp[i]);
			else sP.push_back(stmp[i]);
		}
		Admin ttmp(sU, sP);
		listAdmin.addTail(ttmp);
	}
	f.close();
}
void loadDonHang(LinkedList<DonHang>& listDonHang) {
	fstream f;
	f.open("./DonHang.txt");
	string STT, MaHangHoa, SoLuong, TongTien, TenKhachHang, DiaChi, SDT, NgayDat, HH;
	while (!f.eof()) {
		HH = "";  
		MaHangHoa = "";
		SoLuong = "";
		TongTien = "";
		TenKhachHang = "";
		DiaChi = "";
		SDT = "";
		NgayDat = "";
		getline(f, HH);
		int x = 7; 
		for (int i = 0; i < HH.length(); i++) {
			if (HH[i] == ' ') {
				x--;
				continue;
			}
			if (x == 6) MaHangHoa += HH[i];
			if (x == 5) SoLuong += HH[i];
			if (x == 4) TongTien += HH[i];
			if (x == 3) TenKhachHang += HH[i];
			if (x == 2) DiaChi += HH[i];
			if (x == 1) SDT += HH[i];
			if (x == 0) NgayDat += HH[i];
		}
		DonHang tmp(STT, MaHangHoa, SoLuong, TongTien, TenKhachHang, DiaChi, SDT, NgayDat);
		listDonHang.addTail(tmp);
		f.ignore();
	}
	f.close();
}

void loadHangHoa(LinkedList<HangHoa>& listHangHoa) {
	ifstream f;
	f.open("HangHoa.txt");
	string MaHangHoa, TenHangHoa, NoiSanXuat, GiaBan, MauSac, NgayNhapKho, SoLuong, HH;
	while (!f.eof()) {
		HH = ""; //doc toan bo dong 
		MaHangHoa = "";
		TenHangHoa = "";
		NoiSanXuat = "";
		GiaBan = "";
		MauSac = "";
		NgayNhapKho = "";
		SoLuong = "";
		getline(f, HH);
		int x = 6; // soos daau cach 
		for (int i = 0; i < HH.length(); i++) {
			if (HH[i] == ' ') {
				x--;
				continue;
			}
			if (x == 6) MaHangHoa += HH[i];
			if (x == 5) TenHangHoa += HH[i];
			if (x == 4) NoiSanXuat += HH[i];
			if (x == 3) GiaBan += HH[i];
			if (x == 2) MauSac += HH[i];
			if (x == 1) NgayNhapKho += HH[i];
			if (x == 0) SoLuong += HH[i];
		}
		HangHoa tmp(MaHangHoa, TenHangHoa, NoiSanXuat, MauSac, GiaBan, NgayNhapKho, SoLuong);
		listHangHoa.addTail(tmp);

		f.ignore();
	}
	f.close();
}

// Hàm Quản lý
void showQuanLy(LISTADMIN){
	setKhung(CALLLIST);
	ToMau(40, 13, "* * * * * * * * * * * * * * * * * * *", 14);
	ToMau(40, 14, "*                                   *", 14);
	ToMau(40, 15, "*        1. Xữ lý đơn hàng          *", 202);
	ToMau(40, 16, "*        2. Quản lý hàng hóa        *", 14);
	ToMau(40, 17, "*                                   *", 14);
	ToMau(40, 18, "* * * * * * * * * * * * * * * * * * *", 14);
	int _iChoose = 0;
	int _iToaDo = 15;
	do {
		char _cA = _getch();
		if (_cA == 80) _iChoose = 1; //bắt sự kiện nút lên 
		else if (_cA == 72) _iChoose = 2;//bắt sự kiện nút enter  
		else if (_cA == 13) _iChoose = 3; // //bắt sự kiện nút xuống
		else _iChoose = 0;
		if (_iChoose == 1 && _iToaDo < 19) _iToaDo++;
		else if (_iChoose == 2 && _iToaDo > 13) _iToaDo--;
		if (_iToaDo == 15) {
			ToMau(40, 15, "*        1. Xữ lý đơn hàng          *", 202);
			ToMau(40, 16, "*        2. Quản lý hàng hóa        *", 14);
		}
		if (_iToaDo == 16) {
			ToMau(40, 15, "*        1. Xữ lý đơn hàng          *", 14);
			ToMau(40, 16, "*        2. Quản lý hàng hóa        *", 202);
		}
	} while (_iChoose != 3);
		ClearSceen
			if (_iToaDo == 15) {ClearSceen xuLyDonHang(CALLLIST);}
			else if (_iToaDo == 16) { ClearSceen showQuanLyHangHoa(CALLLIST);}
	
}
void showQuanLyHangHoa(LISTADMIN) {
	setKhung(CALLLIST);
	ToMau(40, 13, "* * * * * * * * * * * * * * * * * * * *", 14);
	ToMau(40, 14, "*                                     *", 14);
	ToMau(40, 15, "*           1. Thêm hàng hóa          *", 202);
	ToMau(40, 16, "*           2. Xóa hàng hóa           *", 14);
	ToMau(40, 17, "*           3. Cập nhật hàng hóa      *", 14);
	ToMau(40, 18, "*                                     *", 14);
	ToMau(40, 19, "* * * * * * * * * * * * * * * * * * * *", 14);
	int _iChoose = 0;
	int _iToaDo = 15;
	do {
		char _cA = _getch();
		if (_cA == 80) _iChoose = 1; //bắt sự kiện nút lên 
		else if (_cA == 72) _iChoose = 2;//bắt sự kiện nút enter  
		else if (_cA == 13) _iChoose = 3; // //bắt sự kiện nút xuống
		else _iChoose = 0;
		if (_iChoose == 1 && _iToaDo < 19) _iToaDo++;
		else if (_iChoose == 2 && _iToaDo > 14) _iToaDo--;
		if (_iToaDo == 15) {
			ToMau(40, 15, "*           1. Thêm hàng hóa          *", 202);
			ToMau(40, 16, "*           2. Xóa hàng hóa           *", 14);
			ToMau(40, 17, "*           3. Cập nhật hàng hóa      *", 14);
		}
		if (_iToaDo == 16) {
			ToMau(40, 15, "*           1. Thêm hàng hóa          *", 14);
			ToMau(40, 16, "*           2. Xóa hàng hóa           *", 202);
			ToMau(40, 17, "*           3. Cập nhật hàng hóa      *", 14);
		}
		if (_iToaDo == 17) {
			ToMau(40, 15, "*           1. Thêm hàng hóa          *", 14);
			ToMau(40, 16, "*           2. Xóa hàng hóa           *", 14);
			ToMau(40, 17, "*           3. Cập nhật hàng hóa      *", 202);
		}
	} while (_iChoose != 3);
		ClearSceen
			if (_iToaDo == 15) { ClearSceen themHangHoa(CALLLIST); }
			else if (_iToaDo == 16) { ClearSceen xoaHangHoa(CALLLIST); }
			else if (_iToaDo == 17) { ClearSceen updateHH(CALLLIST); }
}

void themHangHoa(LISTADMIN) {
	setKhung(CALLLIST);
	string maHangHoa;
	string tenHangHoa;
	string noiSanXuat;
	string mauSac;
	string giaBan;
	string ngayNhapKho;
	string soLuong;
	cin.ignore();

	ToMau(40, 11, "            THÊM HÀNG HÓA         ", 13);
	gotoxy(35, 12);  RED cout << "              -------------------      ";
	ToMau(40, 14, "   1. Mã hàng hóa          :", 3);
	ToMau(40, 16, "   2. Tên hàng hóa         :", 3);
	ToMau(40, 18, "   3. Nơi sản xuất         :", 3);
	ToMau(40, 20, "   4. Giá bán              :", 3);
	ToMau(40, 22, "   5. Màu Sắc              :", 3);
	ToMau(40, 24, "   6. Ngày nhập kho        :", 3);
	ToMau(40, 26, "   7. Số lượng             :", 3);


	gotoxy(68, 14); getline(cin, maHangHoa);
	gotoxy(68, 16); getline(cin, tenHangHoa);
	gotoxy(68, 18); getline(cin, noiSanXuat);
	gotoxy(68, 20); getline(cin, giaBan);
	gotoxy(68, 22); getline(cin, mauSac);
	gotoxy(68, 24); getline(cin, ngayNhapKho);
	gotoxy(68, 26); getline(cin, soLuong);

	if (maHangHoa.length() < 4 || maHangHoa.length() > 4)
	{
		gotoxy(72, 24); RED cout << "# Mã hàng hóa phải 4 ký tự!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (tenHangHoa.length() == 0)
	{
		gotoxy(72, 24); RED cout << "# Chưa nhập tên hàng hóa!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (noiSanXuat.length() == 0)
	{
		gotoxy(72, 24); RED cout << "# Chưa nhập nơi sản xuất!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (mauSac.length() == 0)
	{
		gotoxy(72, 24); RED cout << "# Chưa nhập màu sắc!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (ngayNhapKho.length() == 0)
	{
		gotoxy(70, 24); RED cout << "# Chưa nhập ngày nhập kho!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}

	/*HangHoa tmp(maHangHoa, tenHangHoa, noiSanXuat, mauSac, giaBan, ngayNhapKho, soLuong);
	if (listHangHoa.search1(tmp.getMaHangHoa()))
	{
		gotoxy(40, 24); RED cout << "# Mã hàng hóa đã tồn tại!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}*/
	else
	{
		HangHoa tmp1(maHangHoa, tenHangHoa, noiSanXuat,mauSac,giaBan,ngayNhapKho,soLuong);
		listHangHoa.addTail(tmp1);
		string noti = " [" + tmp1.getMaHangHoa() + "]  - [" + tmp1.getTen() + "] - [" + tmp1.getNoiSanXuat() + "] - [" + tmp1.getMauSac() + "] - [" + tmp1.getGiaBan() + "]- [" + tmp1.getNgayNhapKho() + "] - [" + tmp1.getSoLuong() + "]được tạo bởi ADMIN ";
		updateHH(CALLLIST);
		ToMau(40, 24, "Tạo thành công!!!!", 10);
		Sleep(2000);
		ClearSceen
		showAccessAdmin(CALLLIST);
		cin.ignore();
	}
}
void xoaHangHoa(LISTADMIN) {
	ToMau(32, 11, "                 XÓA HÀNG HÓA          ", 13);
	gotoxy(40, 12);  RED cout << "        ---------------       ";

	ToMau(36, 14, "Hàng hóa cần xóa  : ", 3);

	string tenHangHoa;
	gotoxy(60, 14); cin >> tenHangHoa;
	HangHoa tmp1("",tenHangHoa, "", "", "","","");
	if (listHangHoa.search5(tmp1))
	{
		listHangHoa.remove(tmp1);
		updateHH(CALLLIST);
		Sleep(500);
		ToMau(32, 18, "Đã xóa " + tenHangHoa + " thành công!", 10);
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	else
	{
		ToMau(32, 18, "# Hàng hóa này không có!", 12);
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
} //
void updateHH(LISTADMIN) {
	listHangHoa.displayHangHoa();
}
void updateDH(LISTADMIN){
	listDonHang.displayDonHang();
}
/*void xuLyDonHang(LISTADMIN){
	ifstream f;
	f.open("DonHang.txt");
	f.close;
}*/

// Ham dat hang
void datHang(LISTADMIN) {
	setKhung(CALLLIST);
	string STT, maHang, soLuong, tongTien, tenKhachHang, diaChi, SDT, ngayDatHang;
	cin.ignore();
	

	ToMau(40, 11, "            ĐẶT ĐƠN HÀNG         ", 13);
	gotoxy(35, 12);  RED cout << "              -------------------      ";
	ToMau(40, 14, "   1. STT                  :", 3);
	ToMau(40, 16, "   1. Mã hàng hóa          :", 3);
	ToMau(40, 18, "   2. Số lượng             :", 3);
	ToMau(40, 20, "   3. Tổng tiền            :", 3);
	ToMau(40, 22, "   4. Tên Khách hàng       :", 3);
	ToMau(40, 24, "   5. Địa chỉ              :", 3);
	ToMau(40, 26, "   6. SĐT                  :", 3);
	ToMau(40, 28, "   7. Ngày đặt hàng        :", 3);


	gotoxy(68, 14); getline(cin, maHang);
	gotoxy(68, 16); getline(cin, soLuong);
	gotoxy(68, 18); getline(cin, tongTien);
	gotoxy(68, 20); getline(cin, tenKhachHang);
	gotoxy(68, 22); getline(cin, diaChi);
	gotoxy(68, 24); getline(cin, SDT);
	gotoxy(68, 26); getline(cin, ngayDatHang);

	if (maHang.length() == 0)
	{
		gotoxy(72, 24); RED cout << " Chưa nhập mã đơn hàng!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (soLuong.length() == 0)
	{
		gotoxy(72, 24); RED cout << " Chưa nhập mã đơn hàng!";
		Sleep(1000);
	}
	else if(soLuong.length() < 0){
		gotoxy(72, 24); RED cout << " Số lượng phải lớn hơn 0!";
	    Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (tenKhachHang.length() == 0)
	{
		gotoxy(72, 24); RED cout << " Chưa nhập tên khách hàng!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (diaChi.length() == 0)
	{
		gotoxy(72, 24); RED cout << " Chưa nhập đỉa chỉ người nhận hàng!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (tongTien.length() == 0)
	{
		gotoxy(72, 24); RED cout << " Chưa nhập tổng tiền!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (SDT.length() == 0)
	{
		gotoxy(70, 24); RED cout << " Chưa nhập số điện thoại người mua hàng!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	if (ngayDatHang.length() == 0)
	{
		gotoxy(70, 24); RED cout << " Chưa nhập ngày đặt hàng!";
		Sleep(1000);
		ClearSceen
			showAccessAdmin(CALLLIST);
	}
	else
	{
		DonHang tmp1(STT, maHang, soLuong, tongTien, tenKhachHang, diaChi, SDT, ngayDatHang);
		listDonHang.addTail(tmp1);
		string noti = " [" + tmp1.getSTT() + "]  - [" + tmp1.getMaHangHoa() + "] - [" + tmp1.getSoLuong() + "] - [" + tmp1.getTongTien() + "] - [" + tmp1.getTenKhachHang() + "]- [" + tmp1.getDiaChi() + "] - [" + tmp1.getSDT() + "] - [" + tmp1.getNgayDat() + "]được tạo bởi ADMIN ";
		updateDH(CALLLIST);
		ToMau(40, 24, "Đơn hàng đang chờ xữ lý!!!!", 10);
		Sleep(2000);
		ClearSceen
			showAccessAdmin(CALLLIST);
		cin.ignore();
	}
}
void xuLyDonHang(LISTADMIN) {
	ClearSceen
		resizeConsole(1202, 700);
	int iNumberLines = 4;
	int iColorTitle = 11;
	int iQuantity = listDonHang.getSize();
	int sColorInformations = 0;
	ToMau(1, 1, "||==============================================================================================================================================||", 9);
	ToMau(1, 2, "||       ||             ||              ||                ||                          ||                      ||               ||               ||", 9);
	ToMau(5, 2, "STT", iColorTitle);
	ToMau(15, 2, "Mã hàng", iColorTitle);
	ToMau(30, 2, "Số lượng", iColorTitle);
	ToMau(46, 2, "Tổng tiền", iColorTitle);
	ToMau(67, 2, "Tên khách hàng", iColorTitle);
	ToMau(98, 2, "Địa chỉ", iColorTitle);
	ToMau(119, 2, "SDT", iColorTitle);
	ToMau(131, 2, "Ngày đặt hàng", iColorTitle);
	ToMau(1, 3, "||==============================================================================================================================================||", 9);
	for (int i = 0; i < iQuantity; i++) {
		DonHang tmp;
		tmp = listDonHang[i];
		ToMau(5, iNumberLines, tmp.getMaHangHoa(), 12);
		ToMau(23, iNumberLines, tmp.getSoLuong(), 12);
		ToMau(52, iNumberLines, tmp.getTongTien(), 12);
		ToMau(74, iNumberLines, tmp.getTenKhachHang(), 12);
		ToMau(90, iNumberLines, tmp.getDiaChi(), 12);
		ToMau(110, iNumberLines, tmp.getSDT(), 12);
		ToMau(133, iNumberLines, tmp.getNgayDat(), 12);
		ToMau(1, iNumberLines, "||", 9);
		ToMau(10, iNumberLines, "||", 9);
		ToMau(25, iNumberLines, "||", 9);
		ToMau(41, iNumberLines, "||", 9);
		ToMau(59, iNumberLines, "||", 9);
		ToMau(87, iNumberLines, "||", 9);
		ToMau(111, iNumberLines, "||", 9);
		ToMau(128, iNumberLines, "||", 9);
		ToMau(145, iNumberLines, "||", 9);
		iNumberLines++;
		ToMau(1, iNumberLines, "||==============================================================================================================================================||", 9);
		iNumberLines++; 
		}
		char _cA = _getch();
		if (_cA != '+') {
			ClearSceen showAccessAdmin(CALLLIST);
	}

}
