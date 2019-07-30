#include <iostream>
#include <queue>
using namespace std;

int N;
queue<char> Q;
struct Node {
	Node(char data, Node* left = NULL, Node * right = NULL) : data(data), left(left), right(right) { }
	Node * left;
	Node * right;
	char data;
};
class Tree {
public:
	Tree() { root = NULL; }
	void add(char data, char leftdata, char rightdata) {
		if (root == NULL) {
			if (data == 'A') {
				root = new Node(data);
				if (leftdata != '.') root->left = new Node(leftdata);
				if (rightdata != '.') root->right = new Node(rightdata);
			}
			else {
				Q.push(data); Q.push(leftdata); Q.push(rightdata);
			}
		}
		else
			search(root, data, leftdata, rightdata);
	}
	void search(Node* &root, char data, char leftdata, char rightdata) {
		if (root == NULL) return;
		else if (root->data == data) {
			if (leftdata != '.') root->left = new Node(leftdata);
			if (rightdata != '.') root->right = new Node(rightdata);
		}
		else {
			search(root->left, data, leftdata, rightdata);
			search(root->right, data, leftdata, rightdata);
		}
	}
	void preOrder(Node* root) {
		cout << root->data;
		if(root->left != NULL) preOrder(root->left);
		if (root->right != NULL) preOrder(root->right);
	}
	void inOrder(Node* root) {
		if (root->left != NULL) inOrder(root->left);
		cout << root->data;
		if (root->right != NULL) inOrder(root->right);
	}
	void postOrder(Node* root) {
		if (root->left != NULL) postOrder(root->left);
		if (root->right != NULL) postOrder(root->right);
		cout << root->data;
	}
	Node * root;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	char a, b, c;
	Tree tree;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		tree.add(a, b, c);
	}
	while (!Q.empty()) {
		a = Q.front(); Q.pop();
		b = Q.front(); Q.pop();
		c = Q.front(); Q.pop();
		tree.add(a, b, c);
	}
	tree.preOrder(tree.root);
	cout << '\n';
	tree.inOrder(tree.root);
	cout << '\n';
	tree.postOrder(tree.root);
	cout << '\n';
	return 0;
}