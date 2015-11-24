#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin() , v.end()
using ll = long long;

struct Stack {
	int top;
	int mxsz;
	int *items;

	Stack(int sz) {
		mxsz = sz;
		items = new int[sz];
		top = -1;
	}

	bool IsEmpty() {
		return top == -1;
	}
	bool IsFull() {
		return top == mxsz - 1;
	}

	void push(int x) {
		if (!this->IsFull())
			items[++top] = x;
	}
	int pop() {
		if (!this->IsEmpty())
			return items[top--];
		return -1;
	}

	int peek() {
		if (!this->IsEmpty())
			return items[top];
		return -1;
	}
	~Stack() {
		delete items;
	}
};

int main() {
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	Stack st(10);
	for (int i = 0; i < 10; ++i)
		st.push(i);
	while (!st.IsEmpty()) {
		cout << st.pop() << " ";
	}

	return 0;

}
