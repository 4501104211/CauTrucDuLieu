#pragma once
#include <iostream>
class DonHang {
	string _strSTT;
	string _strMaHangHoa;
	string _strSoLuong;
	string _strTongTien;
	string _strTenKhachHang;
	string _strDiaChi;
	string _strSDT;
	string _strNgayDat;
	string _strType;
public:
	DonHang() {};
	DonHang(const DonHang& a) {
		_strSTT = a._strSTT;
		_strMaHangHoa = a._strMaHangHoa;
		_strSoLuong = a._strSoLuong;
		_strTongTien = a._strTongTien;
		_strTenKhachHang = a._strTenKhachHang;
		_strDiaChi = a._strDiaChi;
		_strSDT = a._strSDT;
		_strNgayDat = a._strNgayDat;
		_strType = a._strType;
	}
	DonHang(string _STT, string _MaHangHoa, string _SoLuong, string _TongTien, string _TenKhachHang, string _DiaChi, string _SDT, string _NgayDat, string _Type = "VND") {
		_strSTT = _STT;
		_strMaHangHoa = _MaHangHoa;
		_strSoLuong = _SoLuong;
		_strTongTien = _TongTien;
		_strTenKhachHang = _TenKhachHang;
		_strDiaChi = _DiaChi;
		_strSDT = _SDT;
		_strNgayDat = _NgayDat;
		_strType = _Type;
	};

	friend ostream& operator<<(ostream& os, DonHang a) {
		os << a._strSTT<<" "<< a._strMaHangHoa << " " << a._strSoLuong << " " << a._strTongTien << " " << a._strType << " " << a._strTenKhachHang << " " << a._strDiaChi << " " << a._strSDT << " " << a._strNgayDat  ;
		return os;
	}
	string getSTT() {
		return _strSTT;
	}
	string getMaHangHoa() {
		return _strMaHangHoa;
	}
	string getSoLuong() {
		return _strSoLuong;
	}
	string getTongTien() {
		return _strTongTien;
	}
	string getTenKhachHang() {
		return _strTenKhachHang;
	}
	string getDiaChi() {
		return _strDiaChi;
	}
	string getType() {
		return _strType;
	}
	string getSDT() {
		return _strSDT;
	}
	string getNgayDat() {
		return _strNgayDat;
	}

	friend bool operator*(DonHang a, DonHang b) {
		return (a.getMaHangHoa() == b.getMaHangHoa());
	}
	friend bool operator==(DonHang a, DonHang b) {
		return (a.getMaHangHoa() == b.getMaHangHoa());
	}
	friend bool operator!=(DonHang a, DonHang b) {
		return (a.getMaHangHoa() != b.getMaHangHoa());
	}
};