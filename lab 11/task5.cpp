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
        left = NULL; // initialize left pointer
        right = NULL; // initialize right pointer
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

// Function to find minimum node (used in deletion)
Node* findMin(Node* root)
{
    // Move left until last node
    if (root->left == NULL)
    {
        return root;
    }

    return findMin(root->left);
}

// In-order traversal (to display BST)
void inorder(Node* root)
{
    // Base condition
    if (root == NULL)
    {
        return;
    }

    inorder(root->left); // visit left subtree
    cout << root->data << " "; // visit root
    inorder(root->right); // visit right subtree
}

// Recursive deletion function
Node* deleteNode(Node* root, int value)
{
    // If tree is empty
    if (root == NULL)
    {
        return NULL;
    }

    // Search in left subtree if value is smaller
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }

    // Search in right subtree if value is greater
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    // Node found
    else
    {
        // Case 1: Node has no child (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // free memory
            return NULL;
        }

        // Case 2: Node has one child (right child)
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Node has one child (left child)
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        Node* temp = findMin(root->right); // find inorder successor

        root->data = temp->data; // replace value

        root->right = deleteNode(root->right, temp->data); // delete successor
    }

    return root; // return updated tree
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

    // Print BST before deletion
    cout << "BST Before Deletion: ";
    inorder(root);

    cout << endl;

    int value; // value to delete

    // Input from user
    cout << "Enter value to delete: ";
    cin >> value;

    // Delete node
    root = deleteNode(root, value);

    // Print BST after deletion
    cout << "BST After Deletion: ";
    inorder(root);

    return 0; // program ends successfully
}