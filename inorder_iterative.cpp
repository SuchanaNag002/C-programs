#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
typedef struct Node Node;
void create(Node *root)
{
    char ans;
    Node *ptr;
    cout << "\nDo you want to create the left child of " << root->data << "? ";
    cin >> ans;
    if (ans == 'Y' || ans == 'y')
    {
        ptr = new Node();
        cout << "\nEnter the information for the left child: ";
        cin >> ptr->data;
        ptr->left = ptr->right = NULL;
        root->left = ptr;
        create(root->left);
    }
    else
        root->left = NULL;
    cout << "\nDo you want to create the right child of " << root->data << "? ";
    cin >> ans;
    if (ans == 'Y' || ans == 'y')
    {
        ptr = new Node();
        cout << "\nEnter the information for the right child: ";
        cin >> ptr->data;
        ptr->left = ptr->right = NULL;
        root->right = ptr;
        create(root->right);
    }
    else
        root->right = NULL;
}
void inorder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
int main()
{
    Node *root = NULL, *ptr;
    int ans = 1, x;
    cout << "\nEnter the information for the root: ";
    ptr = new Node();
    cin >> ptr->data;
    ptr->left = ptr->right = NULL;
    root = ptr;
    create(root);
    inorder(root);
}