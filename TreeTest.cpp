/**
 *  Automatic tests for the exercise on binary trees.
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (emptytree.size(), 0) // checks if the tree is empty (the size is 0). 
  .CHECK_EQUAL (emptytree.contains(10), false)
  .CHECK_OK (emptytree.insert(10)) // checks if it insert 10 good.
  .CHECK_EQUAL (emptytree.contains(10), true)
  .CHECK_EQUAL (emptytree.size(), 1) // checks if the size of the tree is 1.
  .CHECK_EQUAL (emptytree.contains(12), false)
  .CHECK_OK (emptytree.insert(12)) //checks if it insert 12 good.
  .CHECK_EQUAL (emptytree.contains(12), true)
  .CHECK_EQUAL (emptytree.contains(7), false)
  .CHECK_OK (emptytree.insert(7)) //checks if it insert 7 good.
  .CHECK_EQUAL (emptytree.contains(7), true)
  .CHECK_THROWS(emptytree.remove(5)) //checks if it throws exeption because there is no 5 in the tree. 
  .CHECK_THROWS(emptytree.insert(10)) // checks if it throws exeption because there is already 10 in the tree.
  .CHECK_EQUAL (emptytree.size() ,3) // checks if the size of the tree is 3.
  .CHECK_EQUAL (emptytree.root(), 10) // checks if the root of the tree is 10.

  .CHECK_EQUAL (emptytree.parent(7), 10)
  .CHECK_EQUAL (emptytree.parent(12), 10)
  .CHECK_EQUAL (emptytree.left(10), 7)
  .CHECK_EQUAL (emptytree.right(10), 12)
  .CHECK_EQUAL (emptytree.contains(3), false)
  .CHECK_OK (emptytree.insert(3))
  .CHECK_EQUAL (emptytree.contains(3), true)
  .CHECK_EQUAL (emptytree.contains(2), false)
  .CHECK_OK (emptytree.insert(2))
  .CHECK_EQUAL (emptytree.contains(2), true)
  .CHECK_EQUAL (emptytree.contains(6), false)
  .CHECK_OK (emptytree.insert(6))
  .CHECK_EQUAL (emptytree.contains(6), true)
  .CHECK_EQUAL (emptytree.size() ,6)
  .CHECK_EQUAL (emptytree.parent(6), 3)
  .CHECK_EQUAL (emptytree.left(3), 2)
  .CHECK_OK(emptytree.remove(3))
  .CHECK_EQUAL (emptytree.contains(3), false)
  .CHECK_EQUAL (emptytree.size() ,5)
  .CHECK_EQUAL (emptytree.parent(6), 2)
  .CHECK_EQUAL (emptytree.left(7), 2)
  .CHECK_EQUAL (emptytree.right(2), 6)
  .CHECK_THROWS(emptytree.left(2)) // checks if it throws exeption because 2 doesn't have a left son.
  .CHECK_OK(emptytree.remove(10))
  .CHECK_EQUAL (emptytree.contains(10), false)
  .CHECK_EQUAL (emptytree.root(), 7) 
  .CHECK_EQUAL (emptytree.size() ,4)
  .CHECK_EQUAL (emptytree.parent(12), 7)
  .CHECK_THROWS(emptytree.parent(7)) // checks if it throws exeption because 7 is the root so he don't have a parent.









  .CHECK_THROWS(emptytree.parent(10))

  .CHECK_OK (emptytree.print())

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}