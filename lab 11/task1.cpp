#include <iostream> // Input output library
using namespace std; // Standard namespace

// Node structure for Binary Tree
struct Node
{
    int data; // stores node value
    Node* left; // pointer to left child
    Node* right; // pointer to right child

    // Constructor to initialize node
    Node(int value)
    {
        data = value; // assign value to node
        left = NULL; // left child is empty initially
        right = NULL; // right child is empty initially
    }
};

// In-order traversal (Left -> Root -> Right)
void inorder(Node* root)
{
    if (root == NULL) return; // base condition

    inorder(root->left); // visit left subtree
    cout << root->data << " "; // print root
    inorder(root->right); // visit right subtree
}

// Pre-order traversal (Root -> Left -> Right)
void preorder(Node* root)
{
    if (root == NULL) return; // base condition

    cout << root->data << " "; // print root first
    preorder(root->left); // visit left subtree
    preorder(root->right); // visit right subtree
}

// Post-order traversal (Left -> Right -> Root)
void postorder(Node* root)
{
    if (root == NULL) return; // base condition

    postorder(root->left); // visit left subtree
    postorder(root->right); // visit right subtree
    cout << root->data << " "; // print root at end
}

int main()
{
    // Manually creating binary tree
    Node* root = new Node(1); // root node
    root->left = new Node(2); // left child
    root->right = new Node(3); // right child
    root->left->left = new Node(4); // left-left node
    root->left->right = new Node(5); // left-right node

    cout << "In-order: ";
    inorder(root); // call in-order traversal

    cout << "\nPre-order: ";
    preorder(root); // call pre-order traversal

    cout << "\nPost-order: ";
    postorder(root); // call post-order traversal

    return 0; // program end
}