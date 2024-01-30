#include <iostream>
#include <cstdlib>
//#include <conio.h>
#include <cstdio>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};
void insert(Node* &root, int value) {
    if (root == NULL ) {
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (value < root->data) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }
}
bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}
Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node*& root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}



// Node structure and BST algorithm functions go here (as provided in the previous response).

int main() {
    Node* root = NULL; // Initialize an empty BST

    // Insert some values into the BST
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the inorder traversal of the BST
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search for a value in the BST
    int searchValue = 40;
    if (search(root, searchValue)) {
        cout << searchValue << " is found in the BST." << endl;
    } else {
        cout << searchValue << " is not found in the BST." << endl;
    }

    // Delete a value from the BST
    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    cout << "After deleting " << deleteValue << ": ";
    inorder(root);
    cout << endl;

    return 0;
}

