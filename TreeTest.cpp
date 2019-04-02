/**
 *  Automatic tests for the exercise on binary trees.
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {

  ariel::Tree treeTest;
  ariel::Tree threetree;

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (treeTest.size(), 0)
  .CHECK_OK    (treeTest.insert(5))
  .CHECK_EQUAL (treeTest.size(), 1)
  .CHECK_EQUAL (treeTest.contains(5), true)
  .CHECK_OK    (treeTest.remove(5))
  .CHECK_EQUAL (treeTest.contains(5), false)
  .CHECK_THROWS(treeTest.remove(5))
  .CHECK_EQUAL (treeTest.size() ,0)
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  .CHECK_EQUAL (treeTest.size(), 0) //Checks if the tree is empty (the size is 0). 
  .CHECK_EQUAL (treeTest.contains(10), false)
  .CHECK_OK (treeTest.insert(10)) //Checks if inserts 10 to the tree.
  .CHECK_EQUAL (treeTest.contains(10), true) //Checks if the tree contains 10 after insert.
  .CHECK_EQUAL (treeTest.size(), 1) //Checks if the size of the tree is 1.
  .CHECK_EQUAL (treeTest.contains(12), false)
  .CHECK_OK (treeTest.insert(12)) //Checks if inserts 12.
  .CHECK_EQUAL (treeTest.contains(12), true)
  .CHECK_EQUAL (treeTest.contains(7), false)
  .CHECK_OK (treeTest.insert(7)) //Checks if inserts 7.
  .CHECK_EQUAL (treeTest.contains(7), true)
  .CHECK_THROWS(treeTest.remove(5)) //Checks if throws exception cause there is no 5 in the tree. 
  .CHECK_THROWS(treeTest.insert(10)) //Checks if throws exception cause there is already 10 in the tree.
  .CHECK_EQUAL (treeTest.size() ,3) //Checks if the size of the tree is 3.
  .CHECK_EQUAL (treeTest.root(), 10) //Checks if the root of the tree is 10.
  .CHECK_EQUAL (treeTest.parent(7), 10) //Checks if 10 is the parent of 7.
  .CHECK_EQUAL (treeTest.parent(12), 10) //Checks if 10 is the parent of 12.
  .CHECK_EQUAL (treeTest.left(10), 7) //Checks if 7 is the left son of 10.
  .CHECK_EQUAL (treeTest.right(10), 12) //Checks if 12 is the right son of 10.
  .CHECK_EQUAL (treeTest.contains(3), false)
  .CHECK_OK (treeTest.insert(3)) //Checks if inserts 3 .
  .CHECK_EQUAL (treeTest.contains(3), true)
  .CHECK_EQUAL (treeTest.contains(2), false)
  .CHECK_OK (treeTest.insert(2)) //Checks if inserts 2.
  .CHECK_EQUAL (treeTest.contains(2), true)
  .CHECK_EQUAL (treeTest.contains(6), false)
  .CHECK_OK (treeTest.insert(6)) //Checks if inserts 7.
  .CHECK_EQUAL (treeTest.contains(6), true)
  .CHECK_THROWS(treeTest.insert(6)) //Checks if throws exception cause there is already 6 in the tree.
  .CHECK_EQUAL (treeTest.size() ,6) //Checks if the size of the tree is 6.
  .CHECK_EQUAL (treeTest.parent(6), 3) //Checks if 3 is the parent of 6.
  .CHECK_EQUAL (treeTest.left(3), 2) //Checks if 2 is the left son of 3.
  .CHECK_OK(treeTest.remove(3)) //Checks if removes 3 good.
  .CHECK_EQUAL (treeTest.contains(3), false)
  .CHECK_EQUAL (treeTest.size() ,5) //Checks if the size of the tree is 5.
  .CHECK_EQUAL (treeTest.parent(6), 2) //Checks if 2 is the parent of 6.
  .CHECK_EQUAL (treeTest.left(7), 2) //Checks if 2 is the left son of 7.
  .CHECK_EQUAL (treeTest.right(2), 6) //Checks if 6 is the right son of 2.
  .CHECK_THROWS(treeTest.left(2)) //Checks if throws exception cause 2 doesn't have a left son.
  .CHECK_OK(treeTest.remove(10)) //Check if removes 10.
  .CHECK_EQUAL (treeTest.contains(10), false)
  .CHECK_EQUAL (treeTest.root(), 12) //Checks if the root of the tree is 7.
  .CHECK_EQUAL (treeTest.size() ,4) //Checks if the size of the tree is 4.
  .CHECK_THROWS (treeTest.parent(12)) //Checks if 7 is the parent of 12.
  .CHECK_OK (treeTest.print()) //Checks if it prints well.
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ".     Great!" << endl;
}
