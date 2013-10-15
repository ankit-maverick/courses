#include <iostream>

using namespace std;

class Heap{

private:
    int *elements;
    int size;
    int decrement;

public:

    Heap(int capacity){
        elements = new int[capacity];
        decrement = 0;
        size = -1;
    }


    void add(int element){
        size++;
        elements[size] = element + decrement;
        int k = size;
        while(k > 0 && elements[k] < elements[(k - 1)/2]){
            int temp = elements[(k - 1)/2];
            elements[(k - 1)/2] = elements[k];
            elements[k] = temp;
            k = (k - 1)/2;
        }

    }


    void Delete(){
        elements[0] = elements[size];
        size--;
        int k = 0;
        int temp;
        while ((elements[k] > elements[2*k + 1] || elements[k] > elements[2*k + 2]) && k <= (size - 1)/2){
            if (elements[2*k + 1] < elements[2*k + 2]){
                temp = elements[2*k + 1]; 
                elements[2*k + 1] = elements[k];
                elements[k] = temp;
                k = 2*k + 1;
            }
            else{
                temp = elements[2*k + 2];
                elements[2*k + 2] = elements[k];
                elements[k] = temp;
                k = 2*k + 2;
            }

        }
    }

    void decreaseAllKeys(int k){
        decrement = decrement + k;
    }


    void print(){
        for (int i=0; i<=size; i++){
            cout << elements[i] -  decrement << " ";
        }
        cout << endl;
        cout << endl;
    }
};



int main(){

    Heap myHeap = Heap(100);

    cout << "Initialize {5 – 18}" << endl;
    for (int i=5; i<19; i++){
        myHeap.add(i);
    }
    myHeap.print();

    cout << "DecreaseAllKeys(2)" <<endl;
    myHeap.decreaseAllKeys(2);
    myHeap.print();

    cout << "Add{19, 18}" << endl;
    myHeap.add(19);
    myHeap.add(18);
    myHeap.print();

    cout << "DecreaseAllkeys(1)" << endl;
    myHeap.decreaseAllKeys(1);
    myHeap.print();

    cout << "Delete" << endl;
    myHeap.Delete();
    myHeap.print();

    cout << "Delete" << endl;
    myHeap.Delete();
    myHeap.print();

    cout << "Delete" << endl;
    myHeap.Delete();
    myHeap.print();

    return 0;
}