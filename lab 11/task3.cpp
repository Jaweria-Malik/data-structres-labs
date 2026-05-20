#include <iostream> // Input output library
using namespace std; // Standard namespace

// Node structure for Binary Search Tree
struct Node
{
    int data; // stores node value
    Node* left; // pointer to left child
    Node* right; // pointer to right child

    // Constructor to initialize node
    Node(int value)
    {
        data = value; // assign value to node
        left = NULL; // left child initially null
        right = NULL; // right child initially null
    }
};

// Function to insert values in BST
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

// Recursive search function for BST
bool searchBST(Node* root, int key)
{
    // Base case: if tree is empty
    if (root == NULL)
    {
        return false; // value not found
    }

    // If current node is the key
    if (root->data == key)
    {
        return true; // value found
    }

    // If key is smaller, search in left subtree
    if (key < root->data)
    {
        return searchBST(root->left, key);
    }

    // If key is greater, search in right subtree
    return searchBST(root->right, key);
}

int main()
{
    // Initially tree is empty
    Node* root = NULL;

    // Insert values into BST
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);

    int key; // value to search

    // Take input from user
    cout << "Enter value to search: ";
    cin >> key;

    // Call search function
    if (searchBST(root, key))
    {
        cout << "Value Found in BST"; // if found
    }
    else
    {
        cout << "Value Not Found in BST"; // if not found
    }

    return 0; // program end
}