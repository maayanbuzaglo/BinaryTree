#include <iostream>

namespace ariel {

using namespace std;

    struct Node {
        int data; //change.
        Node* rightSon;
        Node* leftSon;
    };

    class Tree {

        private:
        Node* treeRoot;

        public:
        Tree();
        ~Tree();
        void insert(int num);
        void remove(int num);
        int size();
        bool contains(int num);
        int root();
        int parent(int num);
        int left(int num);
        int right(int num);
        void print();
    };
}
