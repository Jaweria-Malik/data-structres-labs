#include <iostream>
using namespace std;

// Node structure for BST
struct Node
{
    int data; // stores node value
    Node* left; // pointer to left child
    Node* right; // pointer to right child

    // Constructor
    Node(int value)
    {
        data = value; // assign value to node
        left = NULL; // initialize left as NULL
        right = NULL; // initialize right as NULL
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

    // If value is smaller, insert in left subtree
    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    else
    {
        // Otherwise insert in right subtree
        root->right = insertBST(root->right, value);
    }

    // Return updated root
    return root;
}

// Function to find minimum value (leftmost node)
Node* findMin(Node* root)
{
    // If there is no left child, this is minimum
    if (root->left == NULL)
    {
        return root;
    }

    // Move to left subtree
    return findMin(root->left);
}

// Function to find maximum value (rightmost node)
Node* findMax(Node* root)
{
    // If there is no right child, this is maximum
    if (root->right == NULL)
    {
        return root;
    }

    // Move to right subtree
    return findMax(root->right);
}

int main()
{
    // Root of BST initially empty
    Node* root = NULL;

    // Insert values into BST
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    // Print minimum value in BST
    cout << "Minimum Value in BST: " << findMin(root)->data << endl;

    // Print maximum value in BST
    cout << "Maximum Value in BST: " << findMax(root)->data << endl;

    return 0; // program ends successfully
}