#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node *left;
	node *right;

	node(int x) :
			val(x), left(NULL), right(NULL) {

	}
};

void insert(node *&root, int x) {
	if (!root)
		root = new node(x);
	else if (root->val < x)
		insert(root->right, x);
	else
		insert(root->left, x);
}

node *search(node *root, int x) {
	if (!root || root->val == x)
		return root;
	if (root->val < x)
		search(root->right, x);
	else
		search(root->left, x);
	return root;
}

node *&most_right(node *&root) {
	if (!root->right)
		return root;
	return most_right(root->right);
}
void remove(node *&root, int x) {
	if (!root)
		return;

	if (root->val < x)
		remove(root->right, x);

	else if (root->val > x)
		remove(root->left, x);
	else {
		if (!root->left && !root->right) {
			delete root;
			root = NULL;
		} else if (!root->right) {
			node *tmp = root->left;
			delete root;
			root = tmp;
		} else if (!root->left) {
			node *tmp = root->right;
			delete root;
			root = tmp;
		} else {
			node *&update = most_right(root->left);
			root->val = update->val;

			if (update->left) {
				node *tmp = update->left;
				delete update;
				update = tmp;
			} else {
				delete update;
				update = NULL;
			}
		}

	}

}
void in_order(node *root) {
	if (!root)
		return;
	in_order(root->left);
	printf("%d ", root->val);
	in_order(root->right);
}
int main() {
	node *root;
	for (int i = 0; i < 10; ++i)
		insert(root, i);

	remove(root, 5);
	remove(root, 0);
	remove(root, 9);
	insert(root, 9);

	in_order(root);
	return 0;
}
