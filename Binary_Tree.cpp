#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin() , v.end()
using ll = long long;

struct node {
	int data;
	node *left;
	node *right;

	node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};

node *new_node(int x) {
	node *tmp = new node;
	tmp->data = x;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

void print_inorder(node *root) {
	if (root == NULL)
		return;

	print_inorder(root->left);
	printf("%d ", root->data);
	print_inorder(root->right);

}

void invert(node *root) {
	if (root == NULL)
		return;
	invert(root->left);
	invert(root->right);
	node *tmp = root->right;
	root->right = root->left;
	root->left = tmp;
}

void remove(node *root) {
	if (root == NULL)
		return;
	remove(root->left);
	remove(root->right);
	delete root;
}
int main() {
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);

	print_inorder(root);
	printf("\n");
	invert(root);
	print_inorder(root);

	remove(root);
	root = NULL;
	return 0;

}
