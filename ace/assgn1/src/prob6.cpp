#include<iostream>
#include<stdio.h>

using namespace std;

class Node{
public:
	Node *next;
	int value;

	Node(){
		//value = x;
		next = NULL;
	}
};


class LinkedList{
public:
	Node *head;

	LinkedList(){
		head = NULL;
	}

	void add(int x){
		Node *newNode;
		newNode = new Node;
		newNode->value = x;
		Node *temp;
		if (head == NULL){
			head = newNode;
		}
		else{
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void print(){
		Node *temp = head;
		while(temp != NULL){
			cout << temp->value << " --> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	void reverse(){

			Node *node1, *node2, *node3;
			node3 = NULL; 
			node1 = head;
			while(node1 != NULL){
				node2 = node1;
				node1 = node1->next;
				node2->next=node3;
				node3 = node2;
			}
			head = node2;
	}
};


int main(){

	cout << "1"<<endl;
	LinkedList myLList = LinkedList();
	cout << "2"<<endl;
	myLList.add(1);
	cout << "3"<<endl;
	myLList.add(3);
	myLList.add(5);
	myLList.add(7);
	myLList.print();
	myLList.reverse();
	myLList.print();

	return 0;
}

