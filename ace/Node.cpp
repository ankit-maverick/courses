#include<iostream>
#include<stdio.h>

using namespace std;

class Node{
public:
	Node * next;
	int value;

	Node(int x){
		value = x;
		next = NULL;
	}
};

int main(){
	
	Node a = Node(5);
	Node b = Node(8);

	a.next = &b;
	cout << a.next->value << endl;

	return 0;
}
