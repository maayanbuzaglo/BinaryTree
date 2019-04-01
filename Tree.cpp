#include <iostream>
#include <string.h>
#include "Tree.hpp"

using namespace ariel;
#define COUNT 10

/*
*An empty constructor.
*/
Tree::Tree()
{
    Tree treeRoot = nullptr;
    int size = 0;
}

/*
*A disconstructor - deletes all the tree.
*/
Tree::~Tree()
{
    Tree::delet(treeRoot);
}

/*
*This function helps the disconstructor.
*It deletes all the tree by recursive calls.
*/
void Tree::delet(node *root)
{
    if(root != nullptr)
    {
        Tree::delet(root->rightSon);
        Tree::delet(root->leftSon);
    }
    delete root;
}

/*
*This function inserts the value to the right place in the tree.
*/
void Tree::insert(int num)
{ 
    if (contains(num) == true)
    {
        throw std::invalid_argument("Your value is already in the tree.");
    }
    else
    {
        Node *buffer = treeRoot; //runs on the tree.

        while(buffer != nullptr) //if the tree is not empty.
        {
            if(num > buffer->data)
            {
                if(buffer->rightSon != nullptr)
                {
                    buffer = buffer->rightSon;
                }    
            }
            else if(num < buffer->data)
            {
                if(buffer->leftSon != nullptr)
                {
                    buffer = buffer->leftSon;
                }    
            }
        }
        buffer->data = num;
    }
    size++;
}

/*
*This function removes the number it gets from the tree.
*/
void Tree::remove(int num)
{

}

/*
*This function returns the size of the tree.
*/
int Tree::size()
{ 
    return size;
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
    if(root->data == num) return true; //Check if the the root data = num.
    else
    {
        if(num < root->data) //If the root data is smaller go to leftSon.
        {
            return contains2(num, root->leftSon)
        }
        else //If the root data is smaller go to rightSon.
        {
            return contains2(num, root->rightSon)
        }
    }
}

/*
*This function returns the data in the root of the tree.
*/
int Tree::root()
{
    if(treeRoot == nullptr)
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
    Node *parent = treeRoot;
    Node *buffer = treeRoot;
    while(buffer->data != num)
    {
        if(buffer->data > num)
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
        if(buffer->data > num)
        {
            buffer = buffer->rightSon;
        }
        else
        {
            buffer = buffer->leftSon;
        }
        if(buffer->data != num) parent = buffer;
    }
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
        if(buffer->data > num)
        {
            buffer = buffer->rightSon;
        }
        else
        {
            buffer = buffer->leftSon;
        }
        if(buffer->data != num) parent = buffer;
    }
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
void print2(Node *root, int space)  
{  
    if (root == NULL) return;

    space += COUNT;    
    print2(root->right, space);  
  
    cout << endl;  
    for(int i = COUNT; i < space; i++) cout << " ";

    cout << root->data << "\n";  
  
    print2(root->left, space);  
}   
