#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin() , v.end()
using ll = long long;

struct node {
	int data;
	node *next;
};

struct Stack {
	node *head;

	Stack() {
		head = NULL;
	}

	node *push(int x) {
		node *tmp = new node;
		tmp->data = x;
		tmp->next = head;
		return head = tmp;
	}

	int pop() {
		if (this->empty())
			return -1;
		int poped = head->data;
		node *tmp = head;
		head = head->next;
		delete tmp;
		return poped;
	}

	bool empty() {
		return head == NULL;
	}

	~Stack() {
		node *tmp = head;
		while (head != NULL) {
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
};
int main() {
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Stack st;
	for (int i = 0; i < 5; ++i)
		st.push(i);

	while (!st.empty())
		cout << st.pop() << " ";

	return 0;

}
