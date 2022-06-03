#include<iostream>
using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if (t == NULL) {
            cout << "\nNO SUCH VALUE\n";
            return NULL;
        }
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void Inorder(node* t)
    {
        if (t == NULL)
            return;

        Inorder(t->left);
        cout << t->data << " ";
        Inorder(t->right);
    }


    void Postorder(Node* u)
    {
        if (u == NULL)
            return;

        // first recur on left subtree
        Postorder(u->left);

        // then recur on right subtree
        Postorder(u->right);

        // now deal with the node
        cout << u->data << " ";
    }


    void Preorder(struct Node* v)
    {
        if (v == NULL)
            return;

        /* first print data of node */
        cout << v->data << " ";

        /* then recur on left subtree */
        Preorder(v->left);

        /* now recur on right subtree */
        Preorder(v->right);
    }


public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display_inorder() {
        Inorder(root);
    }
    void display_postorder() {
        Postorder(root);
    }
    void display_preorder() {
        Preorder(root);
    }


};






int main() {
    BST t;
    bool loop = true;
    bool start = false;
    int root{};
    int menu, val;
    while (loop) {
        cout << "\n1. Insertion"
            << "\n2. Deletion"
            << "\n3. Searching"
            << "\n4. Printing"
            << "\n5. Minimum"
            << "\n6. Maximum"
            << "\n7. Exit\n";
        cin >> menu;
        if (menu == 7) {
            return 0;
            break;
        }
        if (start == false && menu != 1) {
            cout << "Enter Value First!!!";
        }
        else {
            switch (menu) {
            case 1: {
                cout << "\nEnter Value: \n";
                cin >> val;
                t.insert(val);
                start = true;
                break;
            }
            case 2: {
                int del_val;
                cout << "\nEnter Number to delete:";
                cin >> del_val;
                t.remove(del_val);
                break;
            }
            case 3: {
                int search_val;
                cout << "Enter Value to search: ";
                cin >> search_val;
                t.search(search_val);
                break;
            }
            case 4: {
                cout << "\nValues in Inorder: ";
                t.display_inorder();
                cout << "\nValues in Post Order: ";
                t.display_preorder();
                cout << "\nValues in Pre Order: ";
                t.display_postorder();
                break; }
            case 5: {
                cout << "\nMinimun Value is: ";//----------------------------------------------------
                t.find_min();
                break;
            }
            case 6: {
                cout << "\nMaximum Value is: ";//---------------------------------------------------
                t.find_max();
                break;
            }
            case 7: {
                return 0;
                break;
            }
            default: {
                cout << "\nIncorrect Option Selected!!!";
                break;
            }
            }
        }
    }
}