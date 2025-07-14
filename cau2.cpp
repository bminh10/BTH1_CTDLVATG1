#include<iostream>
#define MAX 100
using namespace std;

struct DS {
	int a[MAX];
	int n;

};

void init(DS &a){
	a.n = -1;
}

//add phan tu
int insList(DS& a, int x,int index=0) {
	//them lien neu danh sach rong
	if (a.n == -1) {
		a.a[a.n + 1] = x;
		a.n+=2;
		return 1;
	}


	//them cuoi
	if (index == a.n && a.n <MAX) {
		a.a[a.n] = x;
		a.n++;
		return 1;
	}
	//them bat ky
	if (a.n < MAX && index < a.n) {
		for (int i = a.n; i > index; i--) {
			a.a[i] = a.a[i - 1];
		}
		a.a[index] = x;
		a.n++;
		return 1;
	}
	return -1;
}

//tim kiem tuan tu
int search(DS a, const int key) {
	for (int i = 0; i < a.n; i++) {
		if (a.a[i] == key) {
			return i;
		}
	}
	return -1;
}







//ham Min danh cho truong hop danh sach tang dan
//ham Max danh cho truong hop danh sach giam dan

//tim kiem nhi phan
bool isMax(int a, int  b) {
	return a > b;
}
bool isMin(int a, int b) {
	return a < b;
}

bool isOrdered(DS a, bool func(int, int)) {
	for (int i = 0; i < a.n - 1; i++) {
		int j = i + 1;
		if (func(a.a[i], a.a[j])) {
			return false;
		}
	}
	return true;
}
//danh sach tang dan
int BinarySearch(DS a, const int key, bool func(int, int)) {
	if (isOrdered(a, isMax) || isOrdered(a, isMin)) {
		int left = 0, right = a.n - 1, p;
		while (left <= right) {
			p = (left + right) / 2;
			if (key == a.a[p]) {
				return p;
			}
			else if (func(key,a.a[p])) {
				right = p - 1;
			}
			else {
				left = p + 1;
			}

		}
	}
	return -1;
}
////danh sach giam dan
//int BinarySearch(DS a, const int key, bool func(int, int)) {
//	if (isOrdered(a, isMax) || isOrdered(a, isMin)) {
//		int left = 0, right = a.n - 1, p;
//		while (left <= right) {
//			p = (left + right) / 2;
//			if (key == a.a[p]) {
//				return p;
//			}
//			else if (key > a.a[p]) {
//				left = p + 1;
//			}
//			else {
//				
//				right = p - 1;
//			}
//
//		}
//	}
//	return -1;
//}

//xoa phan tu
int del(DS& a, int index) {
	//xoa cuoi
	if (a.n != -1) {
		if (index == a.n-1 && index < a.n) {
			a.n--;
			return 1;
		}
		for (int i = 0; i < a.n-1; i++) {
			if (i == index) {
				for (int j = i; j < a.n - 1; j++) {
					a.a[j] = a.a[j + 1];
				}
				a.n--;
				return 1;
			}
		}

	}
	return -1;
}

void plusList(DS a, DS b, DS& c) {
	c.n = a.n + b.n;
	for (int i = 0; i < a.n; i++) {
		c.a[i] = a.a[i];
		
	}
	for (int j = a.n; j < c.n; j++) {
		c.a[j] = b.a[j - b.n];
	}
}




//xuat danh sach
void printList(DS a) {
	for (int i = 0; i < a.n; i++) {
		cout << a.a[i] << " ";
	}
	cout << endl;
}


int main() {
	DS a,b,c;
	init(a);
	init(b);
	init(c);
	insList(a, 1);
	insList(a, 2, 1);
	insList(a, 3, 2);
	
	insList(b, 4);
	insList(b, 5,1);
	insList(b, 6,2);
	
	
	
	
	
	
	
	
	
	
	
	
	
	

		
	

	printList(a);
	printList(b);

	/*int res = BinarySearch(a, 12, isMax);
	if(res != -1) {
		cout << res << endl;
	} 
	else {
		cout << " not found." << endl;
	}*/


	/*cout << "=============TIM KIEM XONG XOA==================\n";
	int res = search(a, 0);
	if (res != -1) {
		del(a, res);

		printList(a);
	}*/
	plusList(a, b, c);

	printList(c);


	return 1;
}