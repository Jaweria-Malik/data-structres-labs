#include <iostream> // Input output library
using namespace std; // Standard namespace

// Node structure for BST
struct Node
{
    int data; // stores node value
    Node* left; // pointer to left child
    Node* right; // pointer to right child

    // Constructor to initialize node
    Node(int value)
    {
        data = value; // assign value
        left = NULL; // left child is null initially
        right = NULL; // right child is null initially
    }
};

// BST insertion function
Node* insertBST(Node* root, int value)
{
    // If tree is empty, create new node
    if (root == NULL)
    {
        return new Node(value);
    }

    // If value is smaller, go to left subtree
    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    else
    {
        // If value is greater, go to right subtree
        root->right = insertBST(root->right, value);
    }

    // Return updated root
    return root;
}

// In-order traversal (Left -> Root -> Right)
void inorder(Node* root)
{
    if (root == NULL) return; // base condition

    inorder(root->left); // visit left subtree
    cout << root->data << " "; // print root
    inorder(root->right); // visit right subtree
}

int main()
{
    Node* root = NULL; // BST initially empty

    // Insert values into BST
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);

    cout << "BST In-order: ";
    inorder(root); // prints sorted order

    return 0; // program end
}