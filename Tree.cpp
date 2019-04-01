#include <iostream>
#include <string.h>
#include "Tree.hpp"

using namespace ariel;
#define COUNT 10
Node *treeRoot;
int treeSize;

/*
*An empty constructor.
*/
Tree::Tree()
{
    treeRoot = nullptr;
    treeSize = 0;
}

/*
*A disconstructor - deletes all the tree.
*/
Tree::~Tree()
{
    treeDelete(treeRoot);
}

/*
*This function helps the disconstructor.
*It deletes all the tree by recursive calls.
*/
void Tree::treeDelete(Node *root)
{
    if(root != nullptr)
    {
        treeDelete(root->rightSon);
        treeDelete(root->leftSon);
        delete root;
    }
}

/*
*This function inserts the value to the right place in the tree.
*/

void Tree::insert(int num)
{
    if(contains(num)) __throw_invalid_argument("The value is already in the tree."); // Throw an exeption if the value is already in the tree.
    else
    {
        insert2(num, treeRoot);
    }
}

/*
*This function help the inserts function to insert the value to the right place in the tree.
*/

void Tree::insert2(int num, Node *parent)
{
    if(treeRoot == NULL) // Checkin if the tree is empty.
    {
        treeRoot = addNewLeaf(num);
    }
    else if(num < parent->data) //If the parent data is biger go to left son.
    {
        if(parent->leftSon != NULL) 
        {
            insert2(num, parent->leftSon);
        }
        else
        {
            parent->leftSon = addNewLeaf(num);
        }
    }
    else //If the parent data is smaller go to right son.
    {
        if(parent->rightSon != NULL)
        {
            insert2(num, parent->rightSon);
        }
         else
        {
            parent->rightSon = addNewLeaf(num);
        }
    }
    treeSize++;
}

/*
This function creat a new leaf.
*/

Node* Tree::addNewLeaf(int num)
{
    Node* newLeaf = new Node;
    newLeaf->data = num;
    newLeaf->leftSon = NULL;
    newLeaf->rightSon = NULL;
    return newLeaf;
}

/*
*This function removes the number it gets from the tree.
*/
void Tree::remove(int num)
{
    if (contains(num))
    {
        remove2(num, treeRoot);
    }
    else
    {
        __throw_invalid_argument("The number is not in the tree.");
    }
}

/*
*This function helps the remove function.
*/
void Tree::remove2(int num, Node *parent)
{

    if(treeRoot->data == num)
    {
        removeRoot(); //If the number = root - delete the root.
    }
    else
    {
        if(num < parent->data && parent->leftSon != NULL) //Checks if the value needs to be on the left side.
        {
            parent->leftSon->data == num ?
            removeNum(parent, parent->leftSon, true):
            remove2(num, parent->leftSon); //Gets down untill we find the value.
        }
        else if(num > parent->data && parent->rightSon != NULL) //Checks if the value needs to be on the right side.
        {
            parent->rightSon->data == num ?
            removeNum(parent, parent->rightSon, true):
            remove2(num, parent->rightSon); //Gets down untill we find the value.
        }
        else
        {
            cout << "The number is not in the tree." << endl;
        }
            
    }
}

/*
*This function helps the remove function.
*/

void Tree::removeNum(Node *parent, Node *node, bool left)
{
    if(treeRoot != NULL)
    {
        Node *delPtr;
        int numKey = node->data;
        int smallInRight;

        //If no children:
        if(node->leftSon == NULL && node->rightSon == NULL)
        {
            delPtr = node;
            left == true ?
            parent->leftSon = nullptr:
            parent->rightSon = nullptr;
            delete delPtr;
            cout << "The number was removed." << endl;
            treeSize--;
        }
        //If 1 child:
        else if(node->leftSon == NULL && node->rightSon != NULL)
        {
            left = true ?
            parent->leftSon = node->rightSon:
            parent->rightSon = node->rightSon;
            node->rightSon = nullptr;
            delPtr = node;
            delete delPtr;
            cout << "The number was removed." << endl;
            treeSize--;
        }
        else if(node->leftSon != NULL && node->rightSon == NULL)
        {
            left = true ?
            parent->leftSon = node->leftSon:
            parent->rightSon = node->leftSon;
            node->leftSon = NULL;
            delPtr = node;
            delete delPtr;
            cout << "The number was removed." << endl;
            treeSize--;
        }
        //If 2 children:
        else
        {
            smallInRight = findSmallest2(node->rightSon);
            remove2(smallInRight, node);
            node->data = smallInRight;
        }
    }
    else
    {
        cout << "The tree is empty." << endl;
    }   
}

/*
*This function helps the remove function.
*/

void Tree::removeRoot()
{
    Node* deleteLeaf = treeRoot;
    int rootData  = treeRoot->data;
    int smallRightRoot;

    if(treeRoot->leftSon == NULL && treeRoot->rightSon == NULL) // If the root don't have childrens.
    {
        treeRoot = NULL;
        delete deleteLeaf;
        treeSize--;
    }
    else if (treeRoot->leftSon == NULL && treeRoot->rightSon !=NULL) // If the root have only a right child.
    {
        treeRoot = treeRoot->rightSon;
        deleteLeaf->rightSon = NULL;
        delete deleteLeaf;
        treeSize--;
    }
    else if (treeRoot->rightSon == NULL && treeRoot->leftSon !=NULL) // If the root have only a left child.
    {
        treeRoot = treeRoot->leftSon;
        deleteLeaf->leftSon = NULL;
        delete deleteLeaf;
        treeSize--;
    }
    else //If the root have 2 childrens.
    {
        smallRightRoot = findSmallest2(treeRoot->rightSon);
        remove2(smallRightRoot, treeRoot); // removing the smallest value in the right subtree.
        treeRoot->data = smallRightRoot;

    }
}

/*
This function finds the smallest number in the right subtree.
*/

int Tree::findSmallest()
{
    return findSmallest2(treeRoot);
}

int Tree::findSmallest2(Node *parent)
{
    if (parent->leftSon != NULL) 
    {
        return findSmallest2(parent->leftSon);
    }
    else 
    {
        return parent->data;
    }
}


/*
*This function returns the size of the tree.
*/
int Tree::size()
{ 
    return treeSize;
}

/*
*This function checks if the tree contains the number it gets.
*/
bool Tree::contains(int num)
{
    return contains2(num, treeRoot);
}

/*
*This function helps to contain function.
*It checks recursively if the tree contains the number
*by passing the tree.
*/
bool Tree::contains2(int num, Node *root)
{
    if(root == nullptr) //If the tree is empty.
    {
        return false;
    }
    if(root->data == num) return true; //Check if the root data = num.
    else
    {
        if(num < root->data) //If the root data is biger go to left son.
        {
            return contains2(num, root->leftSon);
        }
        else //If the root data is smaller go to right son.
        {
            return contains2(num, root->rightSon);
        }
    }
}

/*
*This function returns the data in the root of the tree.
*/
int Tree::root()
{
    if(treeRoot == NULL)
    {
        throw std::invalid_argument("The tree is empty.");
    }
    return treeRoot->data;
}

/*
*This function checks what value is the parent of the value it gets.
*/
int Tree::parent(int num)
{
    if(!contains(num)) __throw_invalid_argument("The value is not in the tree.");
    if (num == treeRoot->data) __throw_invalid_argument("The value is the root of the tree.");
    Node *parent = treeRoot;
    Node *buffer = treeRoot;
    while(buffer->data != num)
    {
        if(buffer->data < num)
        {
            buffer = buffer->rightSon;
        }
        else
        {
            buffer = buffer->leftSon;
        }
        if(buffer->data != num) parent = buffer;
    }
    return parent->data;
}

/*
*This function checks what value is the left son of the value it gets.
*/
int Tree::left(int num)
{
    if(!contains(num)) __throw_invalid_argument("The value is not in the tree.");
    Node *buffer = treeRoot;
    while(buffer->data != num)
    {
        if(buffer->data < num)
        {
            buffer = buffer->rightSon;
        }
        else
        {
            buffer = buffer->leftSon;
        }
    }
    if (buffer->leftSon == nullptr) __throw_invalid_argument("The value dosn't have a left son.");
    return buffer->leftSon->data;
}

/*
*This function checks what value is the right son of the value it gets.
*/
int Tree::right(int num)
{
    if(!contains(num)) __throw_invalid_argument("The value is not in the tree.");
    Node *buffer = treeRoot;
    while(buffer->data != num)
    {
        if(buffer->data < num)
        {
            buffer = buffer->rightSon;
        }
        else
        {
            buffer = buffer->leftSon;
        }
    }
    if (buffer->rightSon == nullptr) __throw_invalid_argument("The value dosn't have a right son.");
    return buffer->rightSon->data;
}

/*
*This function prints all the tree.
*/
void Tree::print()
{
    print2(treeRoot, 0); 
}

/*
*This function helps the print function.
*/
void Tree::print2(Node *root, int space)  
{  
    if (root == NULL) return;

    space += COUNT;    
    print2(root->rightSon, space);  
  
    cout << endl;  
    for(int i = COUNT; i < space; i++) cout << " ";

    cout << root->data << "\n";  
  
    print2(root->leftSon, space); 
}