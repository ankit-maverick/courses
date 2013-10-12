#include<iostream>
#include<stdio.h>

using namespace std;

class Node{
public:
	int value;
	Node *next;
	bool deleted;

};

class LinkedList{
private:
    int n_deleted;
    int n_undeleted;

public:
    Node *head;
    int size;

    LinkedList(){
        n_deleted = 0;
        n_undeleted = 0;
        head = NULL;
        size = 1;
    }

    void print(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->value << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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
        n_undeleted = n_undeleted + 1;
    }

    void delete_deleted(){
    while(head->deleted==1){
        delete head;
        head = head->next;
    }
    Node *temp = head;   
    while(temp->next!=NULL){
        if(temp->next->deleted==1){
            delete temp->next;
            temp->next = temp->next->next;       
        }
        else temp=temp->next; 
    }
    n_deleted = 0;
    }

    void lazy_delete(int x){
    Node *temp = new Node;
    temp = head;
    while(temp != NULL){
        if (temp->value == x){
            temp->deleted = 1;
            n_undeleted--;
            n_deleted++;
            if (n_deleted >= n_undeleted){
                delete_deleted();
            }
        }
        temp = temp->next;
    }
}
};


int main(){
	LinkedList myLList = LinkedList();
	
    myLList.add(1);
    myLList.add(3);
    myLList.add(5);
    myLList.add(7);
    myLList.add(9);
    myLList.add(11);

    myLList.print();

    myLList.lazy_delete(3);
    myLList.lazy_delete(5);

    myLList.print();

    myLList.lazy_delete(11);

    myLList.print();
}
