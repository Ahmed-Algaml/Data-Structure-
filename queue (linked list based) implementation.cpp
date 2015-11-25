#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin() , v.end()
using ll = long long;

struct node {
	int data;
	node *next;
};

struct Queue {
	node *head;
	node *tail;

	Queue() {
		head = NULL;
		tail = NULL;
	}
	void push(int x) {
		node *tmp = new node;
		tmp->data = x;
		tmp->next = NULL;
		if (empty()) {
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tmp;
		}
	}

	void pop() {
		if (!empty()) {
			node *tmp = head;
			head = head->next;
			delete tmp;
			if (head == NULL)
				tail = NULL;
		}
	}

	int front() {
		if (!empty())
			return head->data;
		return -1;
	}

	int back() {
		if (!empty())
			return tail->data;
		return -1;
	}
	bool empty() {
		return head == NULL;
	}
	~Queue() {
		node *tmp;
		while (head != NULL) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
};
int main() {
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Queue q;
	for (int i = 0; i < 10; ++i)
		q.push(i);

	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	return 0;

}
