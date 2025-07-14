#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* next;
};
struct CircularLinkedList {
	Node* head;
	Node* tail;
};
void init(CircularLinkedList& l) {
	l.head = nullptr;
	l.tail = nullptr;
}
Node*createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

//them dau
void insFirst(CircularLinkedList& l, const int x) {
	Node* p = createNode(x);
	if (l.head == nullptr) {
		l.head = l.tail = p;
		l.tail->next = l.head;
		return;
	}
	l.tail->next = p;
	p->next = l.head;
	l.head = p;
		

}
//xoa dau
void delFirst(CircularLinkedList& l) {
	if (l.head != nullptr) {
		if (l.head->next == l.head) {
			l.head = l.tail = nullptr;
			return;
		}
		Node* tmp = l.head;
		l.head = l.head->next;
		l.tail->next = l.head;
		tmp->next = nullptr;
		delete tmp;
	}
}
void insLast(CircularLinkedList& l, const int x) {
	Node* p = createNode(x);
	if (l.head == nullptr) {
		l.head = l.tail = p;
		return;
	}
	l.tail->next = p;
	l.tail = p;
	l.tail->next = l.head;
}
void delLast(CircularLinkedList& l) {
	if (l.head != nullptr) {
		//chi co 1 phan tu
		if (l.head->next == l.head) {
			l.head = l.tail = nullptr;
			return;
		}
		Node* tmp = l.tail;
		Node* pre = l.head;
		while (pre->next != l.tail) {
			pre = pre->next;
		}
		l.tail = pre;
		l.tail->next = l.head;
		tmp->next = nullptr;
		delete tmp;
	}
}
Node* search(CircularLinkedList& l, const int key) {
	if (l.head != nullptr) {
		Node* tmp = l.head;
		while (tmp != nullptr && tmp->info != key) {
			tmp = tmp->next;
		}
		return tmp;
	}
}
void delNode(CircularLinkedList& l, const int key) {
	if (l.head != nullptr) {
		Node* q = search(l, key);
		if (q == l.head) {
			delFirst(l);
			return;
		}
		if (q == l.tail) {
			delLast(l);
			return;
		}
		Node* tmp = l.head;
		while (tmp->next != q) {
			tmp = tmp->next;
		}
		tmp->next = q->next;
		q->next = nullptr;
		delete q;

	}
}


void clearNode(CircularLinkedList& l) {
	while (l.head != nullptr) {
		delFirst(l);
	}
}


void printList(const CircularLinkedList& l) {
	if (l.head == nullptr) {
		cout << "List is empty." << endl;
		return;
	}
	Node* tmp = l.head;
	do {
		cout << tmp->info << " ";
		tmp = tmp->next;
	} while (tmp != l.head);
	cout << endl;
}


int main() {
	CircularLinkedList l;
	init(l);

	insLast(l, 2);
	insLast(l, 3);
	insLast(l, 4);
	insLast(l, 5);
	printList(l);
	delNode(l,3);
	
	printList(l);
	

	//giai phong
	clearNode(l);

	return 0;
}