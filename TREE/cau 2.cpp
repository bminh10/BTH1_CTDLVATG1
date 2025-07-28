#include <iostream>
#define MAX 100
using namespace std;
//khai bao cau truc
struct Node {
	int key;
	Node* left, * right;
};

//khoi tao rong
void init(Node*& root) {
	root = nullptr;
}

Node* createNode(const int key) {
	Node* p = new Node();
	p->key = key;
	p->left = nullptr;
	p->right = nullptr;
	return p;
}


struct Stack {
	Node* top;
	Stack* next;
};
void init(Stack*& a) {
	a = nullptr;
}
Stack* createStack(Node* key) {
	Stack* p = new Stack();
	p->top = key;
	p->next = nullptr;
	return p;
}
void push(Stack*& a, Node*x) {
	Stack* p = createStack(x);
	if (a == nullptr) {
		a = p;
		return;
	}
	Stack* pre = a;
	while (pre->next != nullptr) {
		pre = pre->next;
	}
	pre->next= p;

}
void pop(Stack*& a) {
	if (a != nullptr) {
		Stack* tmp = a;
		Stack* pre = nullptr;
		while (tmp->next != nullptr) {
			pre = tmp;
			tmp = tmp->next;
		}
		if (pre == nullptr) {
			a = nullptr;
			
		}
		else {
			pre->next = nullptr;
		}
		delete tmp;
	}

}
Node* get(Stack* a) {
	Stack* tmp = a;
	
	while (tmp->next != nullptr) {
		
		tmp = tmp->next;
	}
	return tmp->top;
}

bool isEmpty(Stack* a) {
	return a == nullptr;
}


//them phan tu vao cay khong dung de quy
void addNode(Node*& root, const int key) {
	Node* p = createNode(key);
	if (root == nullptr) {
		root = p;
		return;
	}
	Node* tmp = root;
	Node* parent = nullptr;
	while (tmp != nullptr) {
		parent = tmp;
		if (tmp->key < key) {
			tmp = tmp->right;
		}
		else {
			tmp = tmp->left;
		}
	}
	//sau khi tim thay vi tri nut can them
	
	if (parent->key < key) {
		parent->right = p;
	}
	else {
		parent->left = p;
	}
	
	
}
//tim phan tu trong cay
Node* findKey(Node* root, const int key) {
	Node* tmp = root;
	while (tmp != nullptr && tmp->key != key) {
		if (tmp->key < key) {
			tmp = tmp->right;
		}
		else {
			tmp = tmp->left;
		}
	}
	return tmp;
}
//xoa node
//cach 1 khong de quy
void delNode(Node*& root, const int key) {
	if (root != nullptr) {
		Node* p = root;
		Node* parent = nullptr;
		while (p != nullptr && p->key !=key) {
			parent = p;
			if (p->key < key) {
				p = p->right;
			}
			else {
				p = p->left;
			}
		}
		//sau khi tim thay vi tri can xoa
		if (p != nullptr) {
			//nut can xoa la nut la
			if (p->left == nullptr && p->right == nullptr) {
				if (parent==nullptr) {
					root = nullptr;
				}
				else {
					if (parent->left == nullptr) {
						parent->right = nullptr;
					}
					else {
						parent->left = nullptr;
					}
				}
				
				delete p;
			}
			//nut can xoa la nut co 1 con trai hoac 1 con phai
			else if (p->left != nullptr && p->right == nullptr || p->right != nullptr && p->left == nullptr) {
				Node* tmp = p;
				if(tmp->left==nullptr){
					tmp = tmp->right;
				}
				else {
					tmp = tmp->left;
				}
				//neu phan tu can xoa la root
				if (parent == nullptr) {
					root = tmp;
					delete p;
					return;
				}
				if (parent->key > p->key) {
					parent->left = tmp;
				}
				else {
					parent->right = tmp;
				}
				delete p;


			}
			//nut can xoa co 2 con
			//tim con trai nho nhat ben phai hoac con phai lon nhat ben trai
			else {
				Node* q = p->right;
				parent = p;
				while (q->left != nullptr) {
					parent = q;
					q = q->left;
				}
				//sau khi tim thay nut the mang
				p->key = q->key;
				p = q;

				//chinh lien ket
				Node* tmp2 = nullptr;
				if (p->left == nullptr) {
					tmp2 = p->right;
				}
				else {
					tmp2 = p->left;
				}

				if (parent->key > p->key) {
					parent->left = tmp2;
				}
				else {
					parent->right = tmp2;
				}



			}


		}

	}
}
//cach 2 dung de quy
void recursivedelNode(Node*& root, const int key) {
	if (root != nullptr) {
		if (root->key < key) {
			recursivedelNode(root->right,key);
		}
		else if( root->key > key) {
			recursivedelNode(root->left, key);
		}
		//sau khi tim duoc nut can xoa
		else {
			//nut can xoa la nut la
			if (root->left == nullptr && root->right == nullptr) {
				Node* p = root;
				root = nullptr;
				delete p;
			}
			//nut can xoa co 1 con trai hoac 1 con phai
			else if (root->left == nullptr && root->right != nullptr || root->right == nullptr && root->left != nullptr) {
				Node* p = root;
				Node* tmp = nullptr;
				if (root->left == nullptr) {
					tmp = root->right;
				}
				else {
					tmp = root->left;
				}

				root = tmp;
				delete p;
			}
			else {
				Node* q = root->right;
				while (q->left != nullptr) {
					q = q->left;
				}
				//sau khi tim thay nut the mang
				root->key = q->key;
				recursivedelNode(root->right, q->key);
			}
		}
		
	}
}





//xuat tree bang de quy
void LNR(Node* root) {
	if (root != nullptr) {
		LNR(root->left);
		cout << root->key << " ";
		LNR(root->right);
		
	}
	
}
//dung stack khu de quy LNR
void stackLNR(Node* root) {
	Stack* a;
	init(a);
	Node* tmp = root;
	while ( tmp != nullptr || !isEmpty(a)) {
		while (tmp != nullptr) {
			push(a, tmp);
			tmp = tmp->left;
		}

		tmp = get(a);
		cout << tmp->key << " ";
		pop(a);
		tmp = tmp->right;
	}


}

//dem so node la
int countLeaf(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	return (countLeaf(root->left) + countLeaf(root->right));

}
//dem nut co gia tri lon hon x
int countIf(Node* root,int x) {
	if (root == nullptr) {
		return 0;
	}
	if (root->key > x) {
		return  (countIf(root->left, x) + countIf(root->right, x))+1;
	}
	return countIf(root->left, x) + countIf(root->right, x);
}
//tinh chieu cao
int tinhHeight(Node* root) {

	int max1 = 0;
	int max2 = 0;
	Node* tmp = root;
	while (tmp != nullptr) {
		max1++;
		tmp = tmp->left;
	}
	tmp = root;
	while (tmp != nullptr) {
		max2++;
		tmp = tmp->right;
	}
	if (max1 > max2) {
		return max1;
	}
	else {
		return max2;
	}
}
//xuat nut muc k chi dinh
void xuatMuc(Node* root, int level,int i = 0) {
	if (root == nullptr) {
		return;
	}
	if (i == level) {
		cout << root->key << " ";
		
		xuatMuc(root->left, level, i+1);
		xuatMuc(root->right, level, i+1);
	}
	
	xuatMuc(root->left,level, i+1);
	xuatMuc(root->right, level, i+1);

}


int main() {
	Node* root;

	init(root);
	//them 
	addNode(root, 50);
	addNode(root, 30);
	addNode(root, 80);
	addNode(root, 20);
	addNode(root,40);
	addNode(root,60);
	addNode(root,90);
	addNode(root,70);
	

	/*LNR(root);
	cout << endl;*/
	//tim kiem
	/*cout << findKey(root, 2)->key << endl;*/

	
	/*recursivedelNode(root, 50);
	LNR(root);
	cout << endl;*/
	Stack* a;
	init(a);
	
	stackLNR(root);
	cout << endl;
	/*cout << countLeaf(root) << endl;
	cout << countIf(root,30) << endl;*/
	cout << tinhHeight(root) << endl;
	
	xuatMuc(root, 1);
	


	return 0;
}