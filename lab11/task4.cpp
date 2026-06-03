#include <iostream>
#include <string>
using namespace std;

class BSTNode
{
public:
    int isbn;
    string title;

    BSTNode* left;
    BSTNode* right;

    BSTNode(int i, string t)
    {
        isbn = i;
        title = t;

        left = NULL;
        right = NULL;
    }
};

class ListNode
{
public:
    int isbn;
    string title;

    ListNode* next;

    ListNode(int i, string t)
    {
        isbn = i;
        title = t;
        next = NULL;
    }
};

BSTNode* insert(BSTNode* root, int isbn, string title)
{
    if (root == NULL)
        return new BSTNode(isbn, title);

    if (isbn < root->isbn)
        root->left = insert(root->left, isbn, title);

    else if (isbn > root->isbn)
        root->right = insert(root->right, isbn, title);

    return root;
}

void convertToList(BSTNode* root,
    ListNode*& head,
    ListNode*& tail)
{
    if (root == NULL)
        return;

    convertToList(root->left, head, tail);

    ListNode* newNode =
        new ListNode(root->isbn, root->title);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    convertToList(root->right, head, tail);
}

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->isbn
            << " - "
            << head->title
            << endl;

        head = head->next;
    }
}

int main()
{
    BSTNode* root = NULL;

    int n;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int isbn;
        string title;

        cout << "\nEnter ISBN: ";
        cin >> isbn;

        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        root = insert(root, isbn, title);
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    convertToList(root, head, tail);

    cout << "\nSorted Library Catalog:\n\n";

    printList(head);

    return 0;
}