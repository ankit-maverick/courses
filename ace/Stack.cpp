#include<iostream>
#include<stdio.h>

using namespace std;

class Stack{

private:
	int capacity;
	int *elements;
	int top_index;

public:
	Stack(int size){
		capacity = size;
		elements = new int[capacity];
		top_index = -1;
	}

	bool isEmpty(){
		return (top_index < 0);
	}

	int num_elements(){
		return top_index + 1;
	}

	int push(int x){
		if (top_index == capacity - 1){
			cout << "Stack Overflow!! The stack is full." << endl;
			return 0;
		}
		elements[++top_index] = x;
		return 0;
	}

	int pop(){
		if (top_index < 0){
			cout << "Stack UnderFlow !! The stack is empty." << endl;
			return 0;
		}
		return elements[top_index--];
	}

	void print(){
		for (int i = 0; i < top_index + 1; ++i)
		{
			cout << elements[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	Stack myStack = Stack(3);
	int a = myStack.pop();
	cout << myStack.num_elements() << endl;
	myStack.push(5);
	int b = myStack.pop();
	cout << a << "  " << b << endl;
	myStack.pop();
	myStack.push(3);
	myStack.push(2);
	myStack.push(1);
	myStack.print();
	myStack.push(4);
	myStack.print();
	cout << myStack.num_elements() << endl;
}
