#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insertInBST(node *root, int val)
{

    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertInBST(root->left, val);
    }
    else
    {
        // val>root->data
        root->right = insertInBST(root->right, val);
    }
}

// Non Recursive code to insert
// node *insertInBST(node *root, int val)
// {
//     node *newNode = new node(val);
//     if (root == NULL)
//     {
//         return newNode;
//     }

//     node *current = root;
//     node *parent = NULL;
//     while (current != NULL)
//     {
//         parent = current;
//         if (val < current->data)
//         {
//             current = current->left;
//         }
//         else
//         {
//             current = current->right;
//         }
//     }

//     if (val < parent->data)
//     {
//         parent->left = newNode;
//     }
//     else
//     {
//         parent->right = newNode;
//     }

//     return root;
// }

node *searchInBST(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    if (root->data > key)
        return searchInBST(root->left, key);

    return searchInBST(root->right, key);
}

int findHeight(node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int minValue(node *root)
{
    if (root == NULL)
        return INT_MAX;
    int minLeft = minValue(root->left);
    int minRight = minValue(root->right);
    return min(root->data, min(minLeft, minRight));
}

void swapChildren(node *root)
{
    if (root == NULL)
        return;
    swap(root->left, root->right);
    swapChildren(root->left);
    swapChildren(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = NULL;
    root = insertInBST(root, 5);
    insertInBST(root, 1);
    insertInBST(root, 3);
    insertInBST(root, 4);
    insertInBST(root, 2);
    insertInBST(root, 7);

    cout << "inorder after creating tree: " << endl;
    inorder(root);
    cout << endl;

    // i. Insert new node
    int newValue = 6;
    insertInBST(root, newValue);
    cout << "\nInserted value " << newValue << ", Inorder after insertion: ";
    inorder(root);

    // ii. Find number of nodes in the longest path from root
    cout << "\nNumber of nodes in the longest path from root: " << findHeight(root);

    // iii. Minimum data value found in the tree
    cout << "\nMinimum data value in the tree: " << minValue(root);

    // iv. Change the tree so that the roles of the left and right pointers are swapped at every node
    swapChildren(root);
    cout << "\nInorder traversal after swapping children: ";
    inorder(root);

    // v. Search a value
    int searchValue = 5;
    if (searchInBST(root, searchValue) == NULL)
    {
        cout << "\nValue " << searchValue << " doesn't exist in the tree!";
    }
    else
    {
        cout << "\nValue " << searchValue << " exists in the tree!";
    }

    return 0;
}