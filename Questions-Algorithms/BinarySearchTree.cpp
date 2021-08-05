#include <iostream>
using namespace std;

class BST {

    struct node {
        int data = 0;

        node *Left;
        node *Right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL) {
            return NULL;
        }
        else {
            makeEmpty(t->Left);
            makeEmpty(t->Right);
            delete t;
        }
        
        return NULL;
    }

    node *insert(node *t, int x) {

        if(t == NULL) {
            t = new node;
            t->data = x;
            t->Left = t->Right = NULL;
        }
        else if(x < t->data) {
            t->Left = insert(t->Left, x);
        }
        else if(x > t->data) {
            t->Right = insert(t->Right, x);
        }

        return t;
    }

    void postOrder(node *t) {
        if (t == NULL) {
            return;
        }

        postOrder(t->Left);
        postOrder(t->Right);

        cout << t->data << "\n";
    }
    
public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(root, x);
    }

    void display() {
        postOrder(root);
    }
};

int main() {
    BST t;
    int var;

    while (cin >> var && !cin.eof()) {
        t.insert(var);
    }
    t.display();
    return 0;
}