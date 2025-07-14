#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* next;
};

void init(Node*& head) {
	head = nullptr;
}

Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

void insOdered(Node*& head, const int x) {
	Node*p = createNode(x);
	if (head == NULL) {
		head = p;
		return;
	}
	if (p->info < head->info) {
		p->next = head;
		head = p;
		return;
	}
	Node* tmp = head;
	while (tmp->next != NULL) {
		if (tmp->info < p->info && tmp->next->info > p->info) {
			p->next = tmp->next;
			tmp->next = p;
			return;
		}
		tmp = tmp->next;
	}

	tmp->next = p;

}

Node* search(Node* head, const int key) {
	if (head != NULL) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->info!=key) {
			tmp = tmp->next;
		}
		return tmp;
	}
	
}

void delNode(Node*& head, const int key) {
	if (head != nullptr) {
		//chi 1 phan tu
		if (head->next == nullptr) {
			head = nullptr;
			return;
		}
		//1 phan tu tro len
		Node* tmp = head;
		if (key == head->info) {
			head = tmp->next;
			tmp->next = nullptr;
			delete tmp;
			return;
		}
		Node* pre = nullptr;
		while (tmp->next != nullptr) {
			if (tmp->info == key) {
				pre->next = tmp->next;
				tmp->next = nullptr;
				delete tmp;
				return;
			}
			pre = tmp;
			tmp = tmp->next;
		}

		pre->next = nullptr;
		delete tmp;
		return;


	}
}




void clearNode(Node*& head) {
	while (head != NULL) {
		Node* tmp = head;
		head = head->next;
		tmp->next = NULL;
		delete tmp;
	}
}

void printList(Node* head) {
	if (head == NULL) {
		cout << "ds rong\n";
		return;
	}
	Node* tmp = head;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int main() {
	Node* head;
	init(head);

	insOdered(head, 5);
	insOdered(head, 2);
	insOdered(head,6);
	insOdered(head,9);
	insOdered(head,10);

	printList(head);

	Node* res = search(head, 10);
	delNode(head, res->info);
	printList(head);


	clearNode(head);
	if (head == NULL) {
		cout << "Ds rong\n";
	}

}