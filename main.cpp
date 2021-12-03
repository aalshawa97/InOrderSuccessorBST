// InOrderSuccessorBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/*
* A binary tree node has data,
* the pointer to left child and
* a pointer to the right child
*/

struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* minValue(struct node* node);

struct node* inOrderSuccessor(struct node* root, struct node* n)
{
    //Step 1 of the above algorithm
    if (n->right != NULL)
    {
        return minValue(n->right);
    }

    struct node* succ = NULL;

    //Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return succ;
}

/*
* Given a non-empty binary search tree,
* return the minimum data value found in that
* tree. Note that the entire tree does not need to be searched.
*/
struct node* minValue(struct node* node)
{
    struct node* current = node;

    //Loop down to find the leftmost leaf
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/*
* Helper function that allocates a new node with
* the given data and NULL left and right pointers.
*/
struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return (node);
}

/*
* Give a binary search tree and a number, inserts
* a new node with the given number in the correct place
* in the tree. Returns the new root pointer which the caller should then use
* (the standard trick to avoid using reference parameters).
*/
struct node* insert(struct node* node, int data)
{
    /*
    * 1. If the tree is empty, return a new, single node
    */
    if (node == NULL)
    {
        return (newNode(data));
    }
    else
    {
        struct node* temp;
        //Otherwise, recurse down the tree
        if (data <= node->data)
        {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else
        {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }

        //Return the (unchanged) node pointer
        return node;
    }
}

int main()
{
    struct node* root = NULL, * temp, * succ, * min;
    //Creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;

    //Function call
    succ = inOrderSuccessor(root, temp);
    if (succ != NULL)
    {
        cout << "\n Inorder Successor of " << temp->data << " is " << succ->data;
    }
    else
    {
        cout << "\n Inorder Successor doesn't exit";
    }
    getchar();
    std::cout << "Hello World!\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
