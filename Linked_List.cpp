#include<bits/stdc++.h>

using namespace std;

#define all(v) v.begin() , v.end()
using ll = long long;

struct node {
	int data;
	node *next;
};

struct linked_list {
	node *head;
	node *tail;
	linked_list() {
		head = NULL;
		tail = NULL;
	}

	// method to insert a new element as head and returns head.
	node *insert_head(int x) {
		node *tmp = new node;
		tmp->data = x;
		tmp->next = head;
		return head = tmp;
	}
	// method to insert a new element  after a given node and returns a pointer to the inserted node

	node *insert_after(int x, node *after_me) {
		if (after_me->next == NULL)
			return insert_tail(x);
		node *tmp = new node;
		tmp->data = x;
		tmp->next = after_me->next;
		return after_me->next = tmp;
	}
	// method to insert a new element in the end of the list and returns a pointer to the end
	node *insert_tail(int x) {
		node *tmp = new node;
		tmp->data = x;
		tmp->next = NULL;
		tail->next = tmp;
		return tail = tmp;
	}

	// method to remove the head of the list and returns pointer to the new head
	node *remove_head() {
		if (head != NULL) {
			node *tmp = head;
			head = head->next;
			delete tmp;
		}
		return head;
	}
	// method to remove a given node  passed as a pointer
	node *remove(node *tmp) {
		if (tmp->next == NULL)
			return remove(tail);
		node *tmp2 = tmp->next;
		tmp->data = tmp->next->data;
		tmp->next = tmp->next->next;
		delete tmp2;
		return tmp;

	}
	// method to remove the tail of the list and returns pointer to the new tail
	node *remove_tail() {
		if (head->next == NULL) {
			tail = NULL;
			return remove_head();
		}
		node *tmp = head;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		delete tmp->next;
		tmp->next = NULL;
		return tail = tmp;

	}

	int count(int x) {
		node *tmp = head;
		int res = 0;
		while (tmp != NULL) {
			res += tmp->data == x;
			tmp = tmp->next;
		}
		return res;
	}

	node *find(int x) {
		node *tmp = head;
		while (tmp != NULL) {
			if (tmp->data == x)
				return tmp;
			tmp = tmp->next;
		}
		return NULL;
	}

	node *print() {
		node *tmp = head;
		while (tmp != NULL) {
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
		return head;
	}

	~linked_list() {
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

	linked_list L;
	for (int i = 0; i < 5; ++i)
		L.insert_head(i);

	L.print();

	return 0;

}
