#include<iostream>
#include<stdio.h>

using namespace std;

class DoubleStack{
private:
	int capacity;
	int *elements;
	int index1;
	int index2;

public:
	DoubleStack(int size){
		capacity = size;
		elements = new int[capacity];
		index1 = -1;
		index2 = capacity;
	}

	bool isStack1Empty(){
		return (index1 < 0);
	}

	bool isStack2Empty(){
		return (index2 > capacity - 1);
	}

	void push_on_stack1(int x){
		if (index2 - index1 > 1){
			elements[++index1] = x;
		}
		else{
			cout << "DoubleStack OverFlow!! The array is full." << endl;
		}
	}

	void push_on_stack2(int x){
		if (index2 - index1 > 1){
			elements[--index2] = x;
		}
		else{
			cout << "DoubleStack OverFlow!! The array is full." << endl;
		}

	}

	int pop_from_stack1(){
		if (index1 >= 0){
			return elements[index1--];
		}
		else{
			cout << "Stack1 Underflow!! Stack1 is empty." << endl;
			return 0;
		}
	}

	int pop_from_stack2(){
		if (index2 < capacity){
			return elements[index1++];
		}
		else{
			cout << "Stack2 Underflow!! Stack2 is empty." << endl;
			return 0;
		}

	}

	int size_Stack1(){
		return (index1 + 1);
	}	

	int size_Stack2(){
		return (capacity - index2);
	}

	void print(){
		for (int i = 0; i <= index1; ++i)
		{
			cout << elements[i] << " ";
		}

		for (int i = index1 + 1; i < index2; ++i)
		{
			cout << " _ ";
		}

		for (int i = index2; i < capacity; ++i)
		{
			cout << elements[i] << " ";
		}
		cout << endl;

	}
};

int main(){

	DoubleStack myDS = DoubleStack(4);
	myDS.push_on_stack1(1);
	myDS.print();
	myDS.push_on_stack2(8);
	myDS.print();
	myDS.push_on_stack1(3);
	myDS.print();
	myDS.push_on_stack2(5);
	myDS.print();
	myDS.push_on_stack2(4);
	myDS.print();
	myDS.pop_from_stack1();
	myDS.print();
	myDS.pop_from_stack1();
	myDS.print();
	myDS.pop_from_stack1();
	myDS.print();
	return 0;
}