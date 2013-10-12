#include<iostream>
#include<stdio.h>

using namespace std;

class SelfAdjustingListusingArray{

private:
	int *elements;
	int capacity;
	int front_index;

public:
	SelfAdjustingListusingArray(int size){
		capacity = size;
		elements = new int[capacity];
		front_index = -1;
	}

	bool isEmpty(){
		return (front_index < 0);
	}

	void insert(int x){
		elements[++front_index] = x;
	}

	void get(int x){
		int count = 0;
		for(int i=front_index; i >= 0; i--){
			if (elements[i] == x){
				for (int j=i; j<front_index; j++){
					elements[j] = elements[j + 1];
				}
				elements[front_index] = x;
				count = 1;
				break;
			}
		}
		if (count == 0){
			cout << "Element " << x << " not found in the list." << endl;
		}

	}

	void print(){
		cout << "Front --> ";
		for (int i = front_index; i >= 0; i--)
		{
			cout << elements[i] << " ";
		}
		cout << endl;
	}
};


int main(){
	SelfAdjustingListusingArray mySAList = SelfAdjustingListusingArray(10);
	mySAList.insert(1);
	mySAList.insert(3);
	mySAList.insert(5);
	mySAList.insert(7);
	mySAList.print();
	mySAList.get(4);
	mySAList.print();
	mySAList.get(3);
	mySAList.print();

}