#include <iostream>

namespace ariel {

using namespace std;

    struct Node {
        int data;
        Node* rightSon;
        Node* leftSon;
    };

    class Tree {

        private:
        Node* treeRoot;

        public:
        Tree();
        ~Tree();
        void treeDelete(Node *root);
        void insert(int num);
        void remove(int num);
        int size();
        bool contains(int num);
        bool contains2(int num, Node *root);
        int root();
        int parent(int num);
        int left(int num);
        int right(int num);
        void print();
        void print2(Node *root, int space); 
    };
}
