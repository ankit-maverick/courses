#include <iostream>

using namespace std;

class BinaryTreeNode{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    //BinaryTreeNode *parent;

    BinaryTreeNode(int value){
        data = value;
        left = NULL;
        right = NULL;
        //parent = NULL;
    }

};



class BinaryTree{

public:
    BinaryTreeNode* root;

    BinaryTree(BinaryTreeNode rootNode){
        root = &rootNode;
    }

};


void preOrderTraversal(BinaryTreeNode* rootNode){
    if (rootNode != NULL){
        cout << rootNode->data << endl;
        preOrderTraversal(rootNode->left);
        preOrderTraversal(rootNode->right);
    }
    
}


void inOrderTraversal(BinaryTreeNode* rootNode){
    if (rootNode != NULL){
        inOrderTraversal(rootNode->left);
        cout << rootNode->data << endl;
        inOrderTraversal(rootNode->right);
    }
    
}


void postOrderTraversal(BinaryTreeNode* rootNode){
    if (rootNode != NULL){
        postOrderTraversal(rootNode->left);
        postOrderTraversal(rootNode->right);
        cout << rootNode->data << endl;
    }
    
}


int main(){
    BinaryTreeNode a = BinaryTreeNode(1);
    BinaryTreeNode b = BinaryTreeNode(2);
    BinaryTreeNode c = BinaryTreeNode(3);
    BinaryTreeNode d = BinaryTreeNode(4);
    BinaryTreeNode e = BinaryTreeNode(5);
    BinaryTreeNode f = BinaryTreeNode(6);
    BinaryTreeNode g = BinaryTreeNode(7);

    a.left = &b;
    //b.parent = &a;
    a.right = &c;
    //c.parent = &a;
    b.left = &d;
    //d.parent = &b;
    b.right = &e;
    //e.parent = &b;
    c.left = &f;
    //f.parent = &c;
    c.right = &g;
    //g.parent = &c;

    cout << "Pre : " << endl;
    preOrderTraversal(&a);

    cout << "In : " << endl;
    inOrderTraversal(&a);

    cout << "Post : " << endl;
    postOrderTraversal(&a);

    return 0;

}