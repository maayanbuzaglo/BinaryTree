#include <iostream>

namespace ariel {

using namespace std;

    struct Node {
        int data; //The value int the tree.
        Node* rightSon; //A pointer to the right son.
        Node* leftSon; //A pointer to the right son.
    };

    class Tree {

        private: //All the private functions.

        Node *treeRoot;
        int treeSize;
        
        void insert2(int num, Node *parent);
        bool contains2(int num, Node *root);
        void print2(Node *root, int space);
        void treeDelete(Node *root);
        Node* addNewLeaf(int num);
        Node* remove2(int num, Node *parent);
        Node* findSmallest(Node* root);
        Node* findSmallest2(Node *parent);

        public:  //All the public functions.

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
