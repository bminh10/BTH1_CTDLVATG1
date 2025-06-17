#include<iostream>
using namespace std;



//DS LIEN KET DON VI SO PHAN TU BIEN DONG KHONG XAC DINH DUOC
struct Node {
	//thong tin
	int info;
	//con tro den nut tiep theo
	Node* next;

};

//khoi dong danh sach
void init(Node*& head) {
	head = NULL;
}

//ham tao nut 
Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

//ham duyet danh sach
void print(Node* head) {
	if (head == nullptr) {
		cout << "Danh sach rong ! \n";
		return;
	}

	Node* tmp = head;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << endl;

}

void addLast(Node*& head,const int x) {
	Node* p = createNode(x);
	//neu head rong thi p chinh la head
	if (head == NULL) {
		head = p;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = p;
	}

}
//tim phan tu trong danh sach
Node* findX(Node* head, const int elm) {
	Node* tmp = head;

	while (tmp != NULL) {
		if (tmp->info == elm) {
			//tao note p luu phan tu vua duoc tim thay
			Node* p = createNode(tmp->info);
			return p;
		}
		tmp = tmp->next;
	}
	return NULL;

}
//them dau danh sach
void addFirst(Node* &head, const int x) {
	Node* p = createNode(x);
	if (head == NULL) {
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}

}
//xoa dau danh sach
//option 1: theo int
int delFirst(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		head = tmp->next;
		delete tmp;//giai phong sau khi chuyen head
		return 1;//xoa thanh cong

	}
	return -1; //khong xoa duoc 

}
//option 2: theo Node
Node* delFirst2(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		head = tmp->next;
		delete tmp;//giai phong sau khi chuyen head
		
		return head;//xoa thanh cong
		
		
	}
	return NULL; //khong xoa duoc 

}

//xoa cuoi 
//option 1: theo int
int delLast(Node*&head){

	if (head != NULL) {
		Node* tmp = head;
		Node* tail = NULL;
		while (tmp->next != NULL) {
			tail = tmp;
			tmp = tmp->next;
		}
		
		if (tail == NULL) {
			head = NULL;
		}
		else {
			tail->next = NULL;

			
		}
		delete tmp;
		return 1;//xoa thanh cong
	}
	return -1;//xoa ko thanh cong
}

//option 2: theo Node
Node* delLast2(Node*& head) {

	if (head != NULL) {
		Node* tmp = head;
		Node* tail = NULL;
		while (tmp->next != NULL) {
			tail = tmp;
			tmp = tmp->next;
		}

		if (tail == NULL) {
			head = NULL;
		}
		else {
			tail->next = NULL;


		}
		delete tmp;
		return head;//xoa thanh cong
	}
	return NULL;//xoa ko thanh cong
}
void delX(Node*& head, const int x) {
	Node* tmp = head;
	Node* prev = NULL;
	while (tmp != NULL && tmp->info != x) {
		prev = tmp;
		tmp = tmp->next;
	}

	//khi tim thay
	if (tmp != NULL) {
		if (prev == nullptr) { //th x la head(phan tu can xoa o dau ds)
			head = tmp->next;
		}
		else {
			prev->next = tmp->next;
		}
		delete tmp;
	}


}
//sap xep danh sach co thu tu

int compare(int a, int b) {
	if (a > b) {
		return 1;
	}
	if (a < b) {
		return -1;
	}
	return 0;//a==b
}


void Sort(Node*& head,int compare(int,int)) {
	
	for (Node* i = head; i->next != nullptr; i = i->next) {
		for (Node* j = i->next; j != NULL; j = j->next){
			if (compare(i->info, j->info)>0) { //-1 de sap xep giam dan, 1 de sap xep tang dan
				swap(i->info, j->info);
			}
		}
	}

}

//xoa tat ca
void clearNode(Node*& head) {
	if (head != NULL) {
		while (head != NULL) {
			delFirst(head);
		}
	}
}



int main() {
	Node* head;
	//khoi tao rong ( khoi dong danh sach)
	init(head);

	if (head == nullptr) {
		cout << "NULL" << endl;
	}
	addLast(head, 6);
	addLast(head, 3);
	addLast(head, 9);
	

	print(head);

	//Node* res = findX(head, 3);
	//
	//if (res != NULL) {
	//	cout << "Tim thanh cong \n";
	//	print(res);
	//	delete res; // tim thanh cong thi moi delete 
	//}
	//else {
	//	cout << "That bai\n";
	//}
	//
	//addFirst(head,2);
	//print(head);

	//Node*p = delFirst2(head);
	//print(p);

	/*Node*res=delLast2(head);
	print(res);*/

	/*cout << "========TIM VA XOA===========\n";
	int x;
	cout << "Nhap phan tu can xoa: ";
	cin >> x;
	if (findX(head, x) != NULL) {
		delX(head, x);
		cout << "tim va xoa thanh cong !\n";
		print(head);
	}*/

	cout << "================KQ SAU KHI SAP XEP===============\n";
	Sort(head,compare);
	print(head);

	clearNode(head); //bat buoc phai co de tranh tinh trang memory leak
	return 0;
}