#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin() , v.end()
using ll = long long;

struct Queue {
	int front;
	int sz;
	int mxsz;
	int *items;

	Queue(int n) {
		front = 0;
		sz = 0;
		mxsz = n;
		items = new int[mxsz];
	}

	void push(int x) {
		if (!full()) {
			items[(front + sz) % mxsz] = x;
			++sz;
		}
	}

	void pop() {
		if (!empty()) {
			front = (front + 1) % mxsz;
			--sz;
		}
	}

	int back() {
		if (!empty())
			return items[(front + sz - 1) % mxsz];
		return -1;
	}

	int top() {
		if (!empty())
			return items[front];
		return -1;
	}
	bool full() {
		return sz == mxsz;
	}

	bool empty() {
		return sz == 0;
	}

	~Queue() {
		delete items;
	}
};
int main() {
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	Queue q(10);
	for (int i = 0; i < 10; ++i)
		q.push(i);

	while (!q.empty()) {
		printf("%d ", q.top());
		q.pop();
	}
	return 0;

}
