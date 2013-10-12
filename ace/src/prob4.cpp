#include<iostream>
#include<stdio.h>
using namespace std;

class Queue{
private:
	int capacity;
	int *elements;
	int rear_index,front_index;

public:

	Queue(int size){
	capacity = size;
	elements = new int[capacity];
	rear_index=-1;
	front_index=0;
	}

	void enqueue(int x){
		rear_index++;
       if(rear_index==capacity)
       	{rear_index=0;}
       elements[rear_index] = x;

	}

	int dequeue(){
	int prev_front_index;	
	prev_front_index=front_index++;
	if(front_index==capacity)
		{front_index=0;}	
    return elements[prev_front_index];
	}
};

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

	int item, x;
	int size = 20;

	Queue myQueue = Queue(size);
	Stack myStack = Stack(size);

	for(int i=0;i<size;i++){
		cout<<"Enter element : ";
		cin>>item;
		myQueue.enqueue(item);
	}
	
	for(int i=0;i<size;i++){
		x=myQueue.dequeue();
		myStack.push(x);
	}
	
	for(int i=0;i<size;i++){
		x=myStack.pop();
		myQueue.enqueue(x);
	}
	
	for(int i=0;i<size;i++){
		x=myQueue.dequeue();
		myStack.push(x);
	}
	
	myStack.print();
	
	return 0;
		
}
	

		



	
