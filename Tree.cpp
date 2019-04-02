#include <iostream>
#include <string.h>
#include "Tree.hpp"

using namespace ariel;
#define COUNT 10

/*
An empty constructor.
*/
Tree::Tree()
{
    treeRoot = nullptr;
    treeSize = 0;
}

/*
A disconstructor - deletes all the tree.
*/
Tree::~Tree()
{
    treeDelete(treeRoot);
}

/*
*This function helps the disconstructor.
It deletes all the tree by recursive calls.
*/
void Tree::treeDelete(Node *root)
{
    if(root != nullptr)
    {
        if (root->leftSon != nullptr) //If there is a left son - delete it.
        {
            treeDelete(root->leftSon);
        }
        if (root->rightSon != nullptr) //If there is a right son - delete it.
        {
            treeDelete(root->rightSon);
        }
        delete root;
    }
}

/*
This function inserts the value to the right place in the tree.
*/
void Tree::insert(int num)
{
    if(contains(num)) //Avoid duplicates.
    {
        __throw_invalid_argument("The number is already in the tree."); //Throw an exeption if the value is already in the tree.
        return;
    }
    else
    {
        treeSize++;
        insert2(num, treeRoot);
    }
}

/*
This function helps the insert function to insert the value to the right place in the tree.
*/
void Tree::insert2(int num, Node *parent)
{
    if(treeRoot == nullptr) //Checks if the tree is empty.
    {
        treeRoot = addNewLeaf(num);
    }
    else if(num < parent->data) //If the parent data is bigger go to left son.
    {
        if(parent->leftSon != nullptr) 
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
        if(parent->rightSon != nullptr)
        {
            insert2(num, parent->rightSon);
        }
        else
        {
            parent->rightSon = addNewLeaf(num);
        }
    }
}

/*
This function creates a new leaf.
*/
Node* Tree::addNewLeaf(int num)
{
    Node *newLeaf = new Node;
    newLeaf->data = num;
    newLeaf->leftSon = nullptr;
    newLeaf->rightSon = nullptr;
    return newLeaf;
}

/*
This function helps the remove function - it recursively finds the number which needs to be removed.
I got help by a website for this function.
*/
Node* Tree::remove2(int num, Node *root)
    {
        Node *temp;
        if(root == nullptr) //If the root is empty - exit.
        {
            treeSize++;
            return nullptr;
        }
        else if(num < root->data) //If the number is smaller go to left Son.
            root->leftSon = remove2(num, root->leftSon);
        else if(num > root->data) //If the number is bigger go to right son.
            root->rightSon = remove2(num, root->rightSon);
        else if(root->leftSon && root->rightSon)
        {
            temp = findSmallest(root->rightSon);
            root->data = temp->data;
            root->rightSon = remove2(root->data, root->rightSon);
        }
        else
        {
            temp = root;
            if(root->leftSon == nullptr)
                root = root->rightSon;
            else if(root->rightSon == nullptr)
                root = root->leftSon;
            delete temp;
        }
        return root;
}

/*
This function removes the number it gets from the tree.
*/
void Tree::remove(int num)
{
    if (contains(num))
    {
        treeRoot = remove2(num, treeRoot);
        treeSize--;
    }
    else //If the number is not in the tree - exit.
    {
        __throw_invalid_argument("The number is not in the tree.");
    }
}

/*
This function finds the smallest number in the right subtree.
*/
Node* Tree::findSmallest(Node *root)
{
    return findSmallest2(root);
}

/*
This function helps the findSmallest function.
It recursively go to its smallest left child.
*/
Node* Tree::findSmallest2(Node *parent)
{
    if (parent == NULL)
    {
        return NULL;
    }
    else if (parent->leftSon != NULL) 
    {
        return findSmallest2(parent->leftSon);
    }
    else 
    {
        return parent;
    }
}


/*
This function returns the size of the tree.
*/
int Tree::size()
{ 
    return treeSize;
}

/*
This function checks if the tree contains the number it gets.
*/
bool Tree::contains(int num)
{
    return contains2(num, treeRoot);
}

/*
This function helps to contain function.
It checks recursively if the tree contains the number
by passing the tree.
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
        if(num < root->data ) //If the root data is biger go to left son.
        {
            return contains2(num, root->leftSon);
        }
        else //If the root data is smaller go to right son.
        {
            return contains2(num, root->rightSon);
        }
    }
    return false;
}

/*
This function returns the data in the root of the tree.
*/
int Tree::root()
{
    if(treeRoot == NULL) //If the tree is empty - exit.
    {
        throw std::invalid_argument("The tree is empty.");
    }
    return treeRoot->data;
}

/*
This function checks what value is the parent of the value it gets.
*/
int Tree::parent(int num)
{
    if(!contains(num)) //If number is not in the tree.
    __throw_invalid_argument("The number is not in the tree.");

    if (num == treeRoot->data) //If the number is the root of the tree.
    __throw_invalid_argument("The number is the root of the tree.");

    Node *parent = treeRoot; //The parent of the value.
    Node *buffer = treeRoot; //Runs on the tree.
    while(buffer->data != num)
    {
        if(buffer->data < num) //If the number is bigger go to the right son.
        {
            buffer = buffer->rightSon;
        }
        else //If the number is smaller go to the left son.
        {
            buffer = buffer->leftSon;
        }
        if(buffer->data != num) //If dont find a match - keeps moving on the tree.
        parent = buffer;
    }
    return parent->data;
}

/*
This function checks what value is the left son of the value it gets.
*/
int Tree::left(int num)
{
    if(!contains(num)) //If the value is not in the tree.
    __throw_invalid_argument("The value is not in the tree.");

    Node *buffer = treeRoot; //Runs on the tree.
    while(buffer->data != num)
    {
        if(buffer->data < num) //If the number is bigger go to the right son.
        {
            buffer = buffer->rightSon;
        }
        else //If the number is smaller go to the left son.
        {
            buffer = buffer->leftSon;
        }
    }
    if (buffer->leftSon == nullptr) //If the value dosn't have a left son.
    __throw_invalid_argument("The value dosn't have a left son.");

    return buffer->leftSon->data;
}

/*
This function checks what value is the right son of the value it gets.
*/
int Tree::right(int num)
{
    if(!contains(num)) //If the value is not in the tree.
    __throw_invalid_argument("The value is not in the tree.");

    Node *buffer = treeRoot; //Runs on the tree.
    while(buffer->data != num)
    {
        if(buffer->data < num) //If the number is bigger go to the right son.
        {
            buffer = buffer->rightSon;
        }
        else //If the number is smaller go to the left son.
        {
            buffer = buffer->leftSon;
        }
    }
    if (buffer->rightSon == nullptr) //If the value dosn't have a left son.
    __throw_invalid_argument("The value dosn't have a right son.");

    return buffer->rightSon->data;
}

/*
This function prints all the tree.
*/
void Tree::print()
{
    print2(treeRoot, 0); 
}

/*
This function helps the print function.
I got help by a website for this function.
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