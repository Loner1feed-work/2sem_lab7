#include <stack>
#include <iostream>
#include <Windows.h>
using namespace std;

void task1Base() {

	cout << "Задание 1 легкий уровень\n" << endl;

	stack <int> steck;
	int a;
	int avg = 1;
	cout << "Элементы стека: ";

	for (int i = 0; i < 6; i++)
	{
		a = rand() / 1000 + 1;
		steck.push(a);
		cout << a << " ";
		if (a % 2 != 0) {
			avg *= a;
		}
	}

	cout << endl;

	cout << "Произведение нечетных элементов стека: " << avg << endl;
}

void task2Base() {

	cout << "Задание 2 легкий уровень\n" << endl;

	stack <int> steck;
	int a;
	int count = 0;

	cout << "Элементы стека: ";
	for (int i = 0; i < 6; i++)
	{
		a = rand() / 1000 - 1;
		steck.push(a);
		cout << a << " ";
		if (a > 0) {
			count++;
		}
	}
	cout << endl;

	cout << "Колличество положительных элементов стека: " << count << endl;
}




struct Node {
	float val;
	Node* next;

	Node(float _val) : val(_val), next(nullptr) {}
};

struct list {
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}

	void push(float _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void pop() {
		if (is_empty()) return;
		Node* p = first;
		first = p->next;
		delete p;
	}

	void search_min() {
		float item = 0;
		float min = 10e10;
		Node* p = first;
		while (p) {
			item = p->val;
			p = p->next;
			if (min > item) {
				//cout << "less" << endl;
				min = item;
			}
		}

		cout << "min: " << min << endl;
	}

	void summary() {
		float summ = 1;
		float item;

		Node* p = first;
		while (p) {
			item = p->val;
			p = p->next;
			
			summ *= item;
		}

		cout << "summ: " << summ << endl;
	}
};

void task1Med() {
	list list;
	list.push(4);
	list.push(3);
	list.push(1);
	list.push(2);
	list.push(4);
	list.print();
	list.pop();
	list.print();
	list.search_min();
	
}


void task2Med() {
	list list;
	
	list.push(-2.2);
	list.push(2.3);
	list.push(2.2);
	list.push(5.1);
	list.push(6.7);
	list.print();
	list.pop();
	list.pop();
	list.pop();
	list.push(1.9);
	list.print();
	list.summary();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	task1Base();
	cout << endl;
	task2Base();
	cout << endl;
	task1Med();
	cout << endl;
	task2Med();
}
