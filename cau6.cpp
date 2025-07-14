#include<iostream>
#include<climits>
using namespace std;

struct Node {
	int info;
	Node* next;
	Node* prev;
};
struct DoublyLinkedList {
	Node* head;
	Node* tail;
};

void init(DoublyLinkedList& l) {
	l.head = nullptr;
	l.tail = nullptr;
}

Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	p->prev = nullptr;
	return p;
}

void insFirst(DoublyLinkedList& l, const int x) {
	Node* p = createNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
		return;
	}
	p->next = l.head;
	l.head->prev = p;
	l.head = p;
	return;
}
void insLast(DoublyLinkedList& l, const int x) {
	Node* p = createNode(x);
	if (l.head == NULL) {
		l.head = l.tail = p;
		return;
	}
	l.tail->next = p;
	p->prev = l.tail;
	l.tail = p;
	

}

void delFirst(DoublyLinkedList& l) {
	if (l.head != NULL) {
		//chi co 1 phan tu
		if (l.head->next == nullptr) {
			l.head = l.tail = nullptr;
			return;
		}
		Node* tmp = l.head;
		l.head = tmp->next;
		tmp->next = nullptr;
		l.head->prev = nullptr;
		delete tmp;
	}
}

void delLast(DoublyLinkedList& l) {
	if (l.head != NULL) {
		//chi co 1 phan tu
		if (l.head->next == nullptr) {
			l.head = l.tail = nullptr;
			return;
		}
		Node* tmp = l.tail;
		l.tail = tmp->prev;
		l.tail->next = nullptr;
		tmp->prev = nullptr;
		delete tmp;
	}
}
//tim 
Node* search(DoublyLinkedList l, const int key) {
	Node* tmp = l.head;
	while (tmp != nullptr && tmp->info !=key) {
		tmp = tmp->next;
	}
	return tmp;
}

int delNode(DoublyLinkedList& l, const int key) {
	if (l.head != nullptr) {
		Node* q = search(l, key);
		if (q == l.head) {
			delFirst(l);
			return 1;
		}
		if (q == l.tail) {
			delLast(l);
			return 1;
		}
		Node* qNext = q->next;
		Node* qPre = q->prev;
		qPre->next = qNext;
		qNext->prev = qPre;
		q->next = nullptr;
		q->prev = nullptr;
		delete q;
		return 1;
	}
	return -1;
	
}


//neu tim thay x tra ve x neu khong tim thay thi tra ve gia tri lon hon x ma gan x nhat
Node* searchIf(DoublyLinkedList& l,const int key) {
	
		Node* tmp = l.head;
		Node* res = nullptr;
		int min = INT_MAX;
		while (tmp != NULL && tmp->info != key) {
			if (tmp->info-key < 0) {
				tmp = tmp->next;
				continue;
			}
			else {
				
				
				if (min > tmp->info - key) {
					min = tmp->info - key; 
					res = tmp;
				}
			}
			tmp = tmp->next;
		}
		return res;//phan tu lon hon key co gia tri gan key nhat
	
	
}

void insBefore(DoublyLinkedList& l, const int x,const int key) {
	Node* q = search(l, key);
	
	if (q == l.head) {
		insFirst(l,x);
		return;
	}
	Node* p = createNode(x);
	Node* qPre = q->prev;
	p->next = q;
	p->prev = qPre;
	qPre->next = p;
	qPre = p;
	

}


//duyet tu trai
void printList(const DoublyLinkedList& l) {
	if (l.head == nullptr) {
		cout << "danh sach rong\n";
		return;
	}
	Node* tmp = l.head;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void clearNode(DoublyLinkedList& l) {
	while (l.head != nullptr) {
		delFirst(l);
	}
}

int main() {
	DoublyLinkedList a;
	init(a);
	insLast(a, 2);
	insLast(a, 4);
	insLast(a, 6);
	insLast(a,1);
	printList(a);


	Node* res = searchIf(a, 5);
	insBefore(a, 9, res->info);
	
	printList(a);

	
	/*if (res == NULL) {
		cout << "FAIL";
	}*/

	//giai phong
	clearNode(a);
	if (a.head == nullptr) {
		cout << "Da xoa sach \n";
	}
	return 0;
}