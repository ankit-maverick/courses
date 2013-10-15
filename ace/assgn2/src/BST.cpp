
class BSTNode{

public:
    int key;
    int data;
    BSTNode* left;
    BSTNode* right;
    // added because of its need in _replace_deleted
    BSTNode *parent;
    BSTNode(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};


class BST{

public:
    BSTNode* root;

    BST(BSTNode rootNode){
        root = *rootNode;
    }

    void insertNode(BSTNode *newNode){
        BSTNode* prevNode = root;
        BSTNode* currNode = root;
        while (currNode != NULL){
            if (newNode->key == currNode->key){
                cout << "A Node with key " << newNode.key << "already exists in the BST." << endl;
            }
            else if (newNode->key < currNode->key){
                prevNode = currNode;
                currNode = currNode->left;
            }
            else{
                prevNode = currNode;
                currNode = currNode->right;
            }

        if (newNode->key < prevNode->key)
            prevNode->left = newNode;
        else
            prevNode->right = newNode;
        }
    }

    void searchNode(int searchKey){
        BSTNode *currNode = root;
        while(currNode != NULL){
            if (currNode->key == searchKey)
                cout << searchKey << endl;
                cout << "A Node with key " << searchKey << " exists in the BST." << endl;
            else if (searchKey < currNode->key){
                cout << currNode->key << " -L- ";
                currNode = currNode->left;
            }
            else{
                cout << currNode->key << " -R- ";
                currNode = currNode->right;
            }
        }   
    }


    void replace_deleted(BSTNode *deleteNode){
        // deleteNode is a leaf node
        if (deleteNode->left == NULL && deleteNode->right == NULL){
            // Dirty hack. DRY should be folowed.
            if (deleteNode->parent->left == deleteNode)
                deleteNode->parent->left = NULL;
            else
                deleteNode->parent->right = NULL;
        }
        // deleteNode has only right child
        else if (deleteNode->left == NULL){
            if (deleteNode->parent->left == deleteNode)
                deleteNode->parent->left = deleteNode->right;
            else
                deleteNode->parent->right = deleteNode->right;   
        }
        // deleteNode has only left child
        else if (deleteNode->right == NULL){
            if (deleteNode->parent->left == deleteNode)
                deleteNode->parent->left = deleteNode->left;
            else
                deleteNode->parent->right = deleteNode->left;   
        }
        // deleteNode has two children
        else{
            BSTNode *currNode = deleteNode->left;
            while(currNode->right != NULL){
                currNode = currNode->right;
            }
            if (deleteNode->parent->left == deleteNode)
                deleteNode->parent->left = currNode;
            else
                deleteNode->parent->right = currNode;   
            currNode->left = deleteNode->left;
            currNode->right = deleteNode->right;
        }
    }


    void deleteNode(int deleteKey){
        BSTNode *currNode = root;
        int flag = 0;
        while(currNode != NULL){
            if (currNode->key == deleteKey){
                flag = 1;
                replace_deleted(currNode);
            }
            else if (searchKey < currNode->key){
                currNode = currNode->left;
            }
            else{
                currNode = currNode->right;
            }
        }
        if (flag == 0)
            cout << " No node with the key " << deleteKey << " found in this BST." << endl;   
        else
    }

};

