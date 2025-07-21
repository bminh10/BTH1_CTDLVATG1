#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

struct Node {
	int info;
	Node* left,*right;
};
void init(Node*& root) {
	root = nullptr;
}

Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->left = nullptr;
	p->right = nullptr;
	return p;
}


void recursiveAddNode(Node*& root, const int x) {
	if (root == nullptr) {
		Node* p = createNode(x);
		root = p;
		return;
	}

	else {
		if (root->info < x) {
			recursiveAddNode(root->right, x);
		}
		else {
			recursiveAddNode(root->left, x);
		}
		
	}
	
}
//void recursiveDelNode(Node*& root, const int x) {
//	if (root != nullptr) {
//		if (root->info < x) {
//			recursiveDelNode(root->right, x);
//		}
//		else if( root->info >x) {
//			recursiveDelNode(root->left, x);
//		}
//		else {
//			//neu nut can xoa la nut la
//			if (root->left == nullptr && root->right == nullptr) {
//				Node* p = root;
//				root = root->left;
//				delete p;
//				return;
//			}
//
//			//neu nut can xoa co 1 con trai hoac phai
//			else if (root->left != nullptr && root->right == nullptr || root->left == nullptr && root->right != nullptr) {
//				Node* p = root;
//				if (root->left == nullptr) {
//					root = root->right;
//				}
//				else if(root->right==nullptr) {
//					root = root->left;
//				}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
//				delete p;
//				
//			}
//			else if (root->left != nullptr && root->right != nullptr) {
//				Node* min = root->right;
//				while (min->left != nullptr) {
//					
//					min = min->left;
//				}
//				//sau khi tim duoc nut the mang
//				root->info = min->info;
//				recursiveDelNode(root->right, min->info); // kiem thang so 60
//			}
//			
//
//		}
//	}
//
//
//
//}


/*Xoa Node: B1 tim node can xoa 
			B2 xet node can xoa:
			+ la not la ( neu la root thi root= nullptr )
			+ la not co 1 con trai hoac 1 con phai ( neu la root thi doi root qua con tuong ung)
			+ la not co 2 con ( tim nut the mang co the la con trai nho nhat cua ben phai hoac con phai lon nhat cua ben trai)
			de dam bao node duoc the phai nho hon not ben phai va lon hon not ben trai 
			*/

void recursiveDelNode(Node*& root, const int key) {
	if (root != nullptr) {
		if (root->info < key) {
			recursiveDelNode(root->right, key);
		}
		else if(root->info > key) {
			recursiveDelNode(root->left, key);
		}
		//tim thay node can xoa
		else {
			//nut can xoa la nut la
			if (root->left == nullptr && root->right == nullptr) {
				Node* p = root;
				root = root->left;//doi node root sang null
				delete p;
			}
			else if (root->left == nullptr && root->right != nullptr || root->right == nullptr && root->left != nullptr) {
				Node* p = root;
				if (root->right != nullptr) {
					root = root->right;
				}
				else {
					root = root->left;
				}
				delete p;
			}
			//nut can xoa co 2 con
			else {
				Node* min = root->right;
				while (min->left != nullptr) {
					min = min->left;
				}
				root->info = min->info;
				recursiveDelNode(root->right, min->info);
			}

		}

	}
}

//dem phan tu trong cay

int countLeaf(Node* root) { //dem so nut la
	if (root == nullptr) {
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	return countLeaf(root->left) + countLeaf(root->right);
}

//dem cay
//cach 1 dung ham duyet cay
void countTree(Node* root,int &count) {
	if (root != nullptr) {
		count++;
		countTree(root->left,count );
		countTree(root->right, count);
	}
	

}
//cach 2: cong tong so not ben trai va ben phai
int countTree2(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return (countTree2(root->right) + countTree2(root->left)) + 1;
}

//tinh trung binh cong cac node trong cay
//cach 1: cong gia tri not con trai va con phai + gia tri not cha
//vd 0 + 0 + 70 ( 0 la con trai tro toi null -> gan = 0 tuong tu voi con phai)

int sumTree(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return sumTree(root->left) + sumTree(root->right) + root->info;
}

//cach 2: dung ham duyet Node cua cay
void sumTree2(Node*root,int &sum){
	if (root != nullptr) {
		sum = sum + root->info;
		sumTree2(root->left, sum);
		sumTree2(root->right, sum);
	}
}

//tim gia tri lon nhat cua cay
int findMaxTree(Node* root) {
	
	if (root == nullptr) {
		return INT_MAX;
	}
	int max = findMaxTree(root->right);
	if (root->info < max) {
		max = root->info;
	}
	return max;
	
}

//dem so nguyen to trong cay
bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int countPrime(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	if (isPrime(root->info)==true) {
		return (countPrime(root->left) + countPrime(root->right)) + 1;
	}
	return (countPrime(root->left) + countPrime(root->right));

}

//dem so nut bac 2
int countLevel(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	if (root->left != nullptr && root->right != nullptr) {
		return (countLevel(root->left) + countLevel(root->right)) + 1;
	}
	return countLevel(root->left) + countLevel(root->right);
}

//dem cac not la muc 2
int countLeafLv(Node* root,int level ,int i = 0) {
	if (root == nullptr) {
		return 0;
	}
	
	if (root->left == nullptr && root->right == nullptr && i==level) {
		return 1;
	}
	i++;
	return (countLeafLv(root->left,level,i) + countLeafLv(root->right,level,i));
}

int findAtoB(Node* root,int a,int b) {
	if (root == nullptr) {
		return 0;
	}
	////
	//if(root->info>a && root->info > b){
	//	return AToB(root->left,a,b);
	//}

	//if (root->info >= a && root->info < b) {
	//	return AToB(root->right,a,b)+1;
	//}

	//if (root->info >= a && root->info == b) {
	//	return AToB(root->right, a, b);
	//}
	////
	//if (root->info <= a && root->info > b) {
	//	return AToB(root->left, a, b)+1;
	//}

	//if (root->info < a && root->info < b) {
	//	return AToB(root->right, a, b)+1;
	//}

	//if (root->info == b) {
	//	return AToB(root->right,a,b);
	//}
	if (root->info > a) {
		return findAtoB(root->left,a,b);
	}
	if (root->info == a && root->info < b) {
		return findAtoB(root->right,a,b)+1;
	}
	if (root->info != a && root->info < b) {
		return findAtoB(root->right, a, b) + 1;
	}
	if (root->info == b && root->info < root->right -> info) {
		return findAtoB(root->right, a, b);
	}
	if (root->info == b && root->info > root->right->info) {
		return findAtoB(root->left, a, b);
	}
}



void LNR(Node* root) {
	if (root != nullptr) {
		LNR(root->left);
		cout << root->info << " ";
		LNR(root->right);
	}
	
}
void NLR(Node* root) {
	if (root != nullptr) {
		cout << root->info << " ";
		LNR(root->left);
		LNR(root->right);
	}

}
void LRN(Node* root) {
	if (root != nullptr) {
		LNR(root->left);
		LNR(root->right);
		cout << root->info << " ";
	}

}


int main() {
	Node* root;
	init(root);
	recursiveAddNode(root, 50);
	recursiveAddNode(root, 30);
	recursiveAddNode(root, 80);
	recursiveAddNode(root, 20);
	recursiveAddNode(root, 40);
	recursiveAddNode(root, 60);
	recursiveAddNode(root, 90);
	recursiveAddNode(root, 70);
	recursiveAddNode(root, 10);
	recursiveAddNode(root, 45);
	


	LNR(root);
	cout << endl;
	////dem nut la va so nutt trong cay
	//int count = 0;
	//countTree(root, count);
	//cout << count << endl;
	////trung binh cong
	//int sum=0;
	//sumTree2(root, sum);
	//cout << sum << endl;
	//
	//cout << "Trung binh cong: " << sumTree(root) / countTree2(root) << endl;

	//cout << findMaxTree(root) << endl;

	/*cout << countPrime(root) << endl;*/
	/*cout << countLevel(root) << endl;*/
	cout << countLeafLv(root,2) << endl;

	/*int a, b;
	cout << "Nhap gia tri node a: ";
	cin >> a;
	cout << "Nhap gia tri node b: ";
	cin >> b;
	cout << findAtoB(root, a, b) << endl;*/


	return 0;
}