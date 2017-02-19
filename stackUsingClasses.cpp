#include <iostream>
#include <climits>
using namespace std;	

class Stack {
	int top;
	int size;
	public:
		int* stk;
		Stack(int n) {
			top = -1;
			size = n;
			stk = new int[size];
		}
		void push(int data);
		void pop();
		bool isEmpty();
		int getTop();
};

void Stack::push(int data) {
	if(top == size - 1) {
		cout<<"overflow\n";
		return;
	}
	stk[++top] = data;
}

void Stack::pop() {
	if(top == -1) {
		cout<<"underflow\n";
		return;
	}
	cout<<"Popped "<<stk[top--]<<endl;
}

bool Stack::isEmpty() {
	return top==-1;
}

int Stack::getTop() {
	if(top == -1) {
		return INT_MAX;
	}
	return stk[top];
}

// void lol(Stack &S) {
// 	cout<<S.stk[0]<<endl;
// 	cout<<S.top;
// }

int main() {
	Stack S(10);
	S.push(2);
	S.push(3);
	S.push(1);
	cout<<S.isEmpty()<<endl;
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	S.push(5);
	cout<<S.getTop()<<endl;
	//lol(S);
	return 0;
}
