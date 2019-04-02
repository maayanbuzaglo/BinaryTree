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
        Node *treeRoot;
        int treeSize;
        
        void insert2(int num, Node *parent);
        bool contains2(int num, Node *root);
        void print2(Node *root, int space);
        void treeDelete(Node *root);
        Node* addNewLeaf(int num);
        void removeRoot();
        void removeNum(Node *parent, Node *node, bool left);
        void remove2(int num, Node *parent);
        int findSmallest();
        int findSmallest2(Node *parent);



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
