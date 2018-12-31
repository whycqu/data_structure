#include <iostream>

using namespace std;

template <typename E>
void preOrder(BinNode<E>* root) {
	if(root == NULL) return;
	visit(root);
	preOrder(root->left());
	preOrder(root->right());
}

template <typename E> 
void inOrder(BinNode<E>* root) {
	if(root == NULL) return;
	preOrder(root->left());
	visit(root);
	preOrder(root->right());
}

template <typename E>
void postOrder(BinNode<E>* root) {
	if(root == NULL) return;
	postOrder(root->left());
	postOrder(root->right());
	visit(root);
}

int main() {

	return 0;
}