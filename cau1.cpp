#include <iostream>
#define MAX 100
using namespace std;


//DS DAC CO SO LUONG TOI DA 100 PHAN TU


struct DanhSach {
	int a[MAX];
	int soluong;
};

//khoi dong danh sach dac
void init(DanhSach &list) {
	list.soluong = -1;
}

//duyet danh sach
void xuatDS(DanhSach list) {

	for (int i = 0; i < list.soluong; i++) {
		cout << list.a[i] << " ";

	}
	cout << endl;

}

//nhap du lieu
//void nhapDS(DanhSach list) {
//	cout << "Nhap so luong: ";
//	cin >> list.soluong;
//	for (int i = 0; i < list.soluong; i++) {
//		cout << "a[" << i << "]=";
//		cin >> list.a[i];
//	}
//	xuatDS(list);  /*Neu khong truyen tham chieu khi nhap danh sach ham chi luu du lieu trong than ham khong luu trong main
//					 Nhu vay trong ham se co mot ban sao cua danh sach*/
//	
//
//}
//cau hoi: tham chieu hoat dong nhu the nao trong bien danh sach ?



//nhap du lieu danh sach
void nhapDS(DanhSach &list) {
	do {
		cout << "Nhap so luong(1-100): ";
		cin >> list.soluong;
	} while (list.soluong<=0 || list.soluong>MAX);
	for (int i = 0; i < list.soluong; i++) {
		cout << "a[" << i << "]=";
		cin >> list.a[i];
	}
}

//tim phan tu trong danh sach
int findKey(DanhSach l,const int key) {
	for (int i = 0; i < l.soluong; i++) {
		if (l.a[i] == key) {
			return i;
		}
	}
	return -1; //do phuc tap cua thuat toan la O(n)
}

//them cuoi danh sachj
void addLast(DanhSach&l,const int x) {
	l.a[l.soluong] = x;
	l.soluong++; //do phuc tap O(1)
}

int delLast(DanhSach& l) {
	if (l.soluong >0) {
		l.soluong--;
		return 1;
	}
	return -1;//xoa khong thanh cong
}

//xoa tat ca X
int delX(DanhSach& l, const int index) {
	if (l.soluong > 0) {
		for (int i = 0; i < l.soluong; i++) {
			if (i == index) {
				for (int j = i; j < l.soluong - 1; j++) {
					l.a[j] = l.a[j + 1];
				}
				l.soluong--;
				
			}
		}
		return 1;//xoa thanh cong
	}
	return -1; //xoa khong thanh cong
	//do phuc tap O(n^2)
}

void addX(DanhSach& l, const int index,const int x) {
	for (int i = 0; i < l.soluong; i++) {
		if (i == index) {
			for (int j = l.soluong; j > i; j--) {
				l.a[j] = l.a[j - 1];
			}
			l.a[i] = index;
			l.soluong++;
			return;
		}
		
	}
}

//Danh sach dac thuong hieu qua trong truy cap nhanh 1 phan tu voi do phuc tap O(1) va thao tac them/xoa o cuoi danh sach hieu qua voi do phuc tap O(1)
//Neu them/xoa o First hay Middle thi se phuc tap do phai chuyen doi du lieu voi do phuc tap O(n)


int main() {
	DanhSach a;
	init(a);

	nhapDS(a);
	xuatDS(a);
	
	if (findKey(a, 2) != -1) {
		cout << "Tim thanh cong !\n";

	}
	else {
		cout << "Tim that bai ! \n";
	}

	addLast(a, 5);
	xuatDS(a);

	//delLast(a);
	//xuatDS(a);

	delX(a, 1);
	xuatDS(a);

	addX(a, 1,1);
	xuatDS(a);


	cout << "===============TIM VA XOA=================\n";
	int value;
	cout << "Nhap phan tu can xoa : ";
	cin >> value;
	if (findKey(a, value) != -1) {
		delX(a, findKey(a, value));
		cout << "Tim va xoa thanh cong !\n";
		xuatDS(a);
	}

	return 0;
}