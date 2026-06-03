#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isIdentical(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->data != root2->data)
        return false;

    return isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right);
}

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;

    int n1, n2, value;

    cout << "Enter nodes for Tree 1: ";
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        cin >> value;
        root1 = insert(root1, value);
    }

    cout << "Enter nodes for Tree 2: ";
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        cin >> value;
        root2 = insert(root2, value);
    }

    cout << "\nTree 1 Inorder: ";
    inorder(root1);

    cout << "\nTree 2 Inorder: ";
    inorder(root2);

    if (isIdentical(root1, root2))
        cout << "\n\nBSTs are Identical";
    else
        cout << "\n\nBSTs are NOT Identical";

    return 0;
}