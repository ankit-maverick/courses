#include<iostream>
#include<stdio.h>

using namespace std;

class Deque{

private:
	int capacity;
	int *elements;
	int rear_index,front_index, size;
	
public:
	
	
	Deque(int deque_capacity){
		capacity = deque_capacity;
		elements = new int[capacity];
		rear_index=0;
		front_index=0;
		size=0;
	}
	
	void Push(int x){
		elements[front_index]=x;
		front_index = (front_index-1)%capacity;
		size++;	
	}
	
	int Pop(){
		front_index = (front_index+1)%capacity;
		size--;
		return elements[front_index];
	}	
	
	void Inject(int x){
		rear_index = (rear_index+1)%capacity;
		elements[rear_index]=x;
		size++;
	}
	
	int Eject(){
		rear_index = (rear_index-1)%capacity;
		size--;
		return elements[(rear_index+1)%capacity];
	}

	void print(){
		for(int i=0;i<size;i++){
			cout<<elements[(i+front_index+1)%capacity]<<" ";
		}
		cout<<endl;
	}
};

int main(){

	Deque myDeque = Deque(10);
	myDeque.Push(1);
	myDeque.Push(3);
	myDeque.Push(5);
	myDeque.Push(7);
	myDeque.Pop();
	myDeque.Inject(9);
	myDeque.Inject(11);
	myDeque.print();
	myDeque.Eject();
	myDeque.Pop();
	myDeque.Inject(13);
	myDeque.print();

return 0;
}
