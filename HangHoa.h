#pragma once
#include <iostream>
using namespace std;
class HangHoa {
	string _strMaHangHoa;
	string _strTenHangHoa;
	string _strNoiSanXuat;
	string _strMauSac;
	string _strGiaBan;
	string _strType;
	string _strNgayNhapKho;
	string _strSoLuong;
public:
	HangHoa() {};

	HangHoa(string _MaHangHoa, string _TenHangHoa, string _NoiSanXuat, string _MauSac, string _GiaBan, string _NgayNhapKho, string _SoLuong, string _Type = "VND") {
		_strMaHangHoa = _MaHangHoa;
		_strTenHangHoa = _TenHangHoa;
		_strNoiSanXuat = _NoiSanXuat;
		_strMauSac = _MauSac;
		_strGiaBan = _GiaBan;
		_strType = _Type;
		_strNgayNhapKho = _NgayNhapKho;
		_strSoLuong = _SoLuong;
	};
	friend ostream& operator<<(ostream& os, HangHoa a) {
		os << a._strMaHangHoa << " " << a._strTenHangHoa << " " << a._strNoiSanXuat << " " << a._strMauSac << " " << a._strGiaBan << " " << a._strType << " " << a._strNgayNhapKho << " " << a._strSoLuong;
		return os;
	}
	string getMaHangHoa() {
		return _strMaHangHoa;
	}
	string getTen() {
		return _strTenHangHoa;
	}
	string getNoiSanXuat() {
		return _strNoiSanXuat;
	}
	string getMauSac() {
		return _strMauSac;
	}
	string getGiaBan() {
		return _strGiaBan;
	}
	string getType() {
		return _strType;
	}
	string getNgayNhapKho() {
		return _strNgayNhapKho;
	}
	string getSoLuong() {
		return _strSoLuong;
	}

	friend bool operator*(HangHoa a, HangHoa b) {
		return (a.getMaHangHoa() == b.getMaHangHoa());
	}
	void operator*=(HangHoa a) {
		_strMaHangHoa = a._strMaHangHoa;
		_strTenHangHoa = a._strTenHangHoa;
		_strNoiSanXuat = a._strNoiSanXuat;
		_strMauSac = a._strMauSac;
		_strGiaBan = a._strGiaBan;
		_strType = a._strType;
		_strNgayNhapKho = a._strNgayNhapKho;
		_strSoLuong = a._strSoLuong;
	}
	friend bool operator==(HangHoa a, HangHoa b) {
		return (a.getTen() == b.getTen());
	}
	friend bool operator!=(HangHoa a, HangHoa b) {
		return (a.getMaHangHoa() != b.getMaHangHoa());
	}
	/*for (Node<DataType>* pWalker = _pHead; pWalker; pWalker = pWalker->_pNext) {
		if (pWalker->_data * data) {
			pWalker->_data = data;
			return;
		}
	}*/
};

