#include <iostream>
#include <iomanip>
#define MAX 20
using namespace std;

struct DaThuc {
	float heSo;
	float soMu;
};

struct DS {
	DaThuc a[MAX];
	int n;
};

void init(DS& a) {
	a.n = -1;
}


void nhap1DaThuc(DaThuc& a) {
	cout << "Nhap he so: ";
	cin >> a.heSo;
	cout << "Nhap so mu: ";
	cin >> a.soMu;
}


void xuat1DaThuc(const DaThuc& a) {
	if (a.heSo == 0) {
		cout << "0";
		return;
	}

	if (a.soMu == 0) {
		cout << a.heSo;
		return;
	}
	if (a.soMu == 1) {
		cout << a.heSo << "x";
		return;
	}
	cout << a.heSo << "x^" << a.soMu;

	
}

void nhapDS(DS& a) {
	do{
		cout << "Nhap so luong da thuc (1 - " << MAX << "): ";
		cin >> a.n;
	} while (a.n < 1 || a.n > MAX); //a.n - 1 la bac cua da thuc cuoi n=6 mu = 5
	for (int i = 0; i < a.n; i++) {
		do {
			cout << "Nhap da thuc thu " << i + 1 << ": " << endl;
			nhap1DaThuc(a.a[i]);
		} while (a.a[i].soMu >= a.n);
	}
}


//danh sach da thuc co thu tu tu lon -> nho
void congDaThuc(DS a, DS b, DS& c) {
	if (a.a[0].soMu >= b.a[0].soMu) {
		c.n = a.n;
		for (int i = 0; i < a.n; i++) {
			for (int j = 0; j < b.n; j++) {
				if (a.a[i].soMu == b.a[j].soMu) {
					a.a[i].heSo = a.a[i].heSo + b.a[j].heSo;
				}

			}
			c.a[i] = a.a[i];
		}
	}
	else {
		c.n = b.n;
		for (int i = 0; i < b.n; i++) {
			for (int j = 0; j < a.n; j++) {
				if ( b.a[i].soMu == a.a[j].soMu  ) {
					b.a[i].heSo = b.a[i].heSo + a.a[j].heSo;
				}
				
			}
			c.a[i] = b.a[i];
		}
	}
	

}



void xuatDS(const DS& a,const char op) {
	
	for (int i = 0; i < a.n; i++) {
		
		xuat1DaThuc(a.a[i]);
		if(i<a.n-1 ) {
			cout << " " << op << " ";
		}
		

	}
	cout << endl;
}



int main() {
	DS a,b,c;
	init(a);
	init(b);
	init(c);
	cout << "Nhap da thuc a:" << endl;
	nhapDS(a);
	
	cout << "Nhap da thuc b:" << endl;
	nhapDS(b);


	char op1;
	cout << "Nhap phep tinh: ";
	cin >> op1;
	cout << "=============== DA THUC A===============\n" << endl;
	xuatDS(a,op1);

	char op2;
	cout << "Nhap phep tinh: ";
	cin >> op2;
	cout << "=============== DA THUC B===============\n" << endl;
	xuatDS(b, op2);


	cout << "============== CONG 2 DA THUC ===================\n" << endl;
	congDaThuc(a, b, c);
	xuatDS(c, '+');

	return 0;
}