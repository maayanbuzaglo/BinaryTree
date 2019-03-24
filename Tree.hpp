#include <iostream>

namespace ariel {

using namespace std;

    struct Node {
        int val;
        Node* left;
        Node* right;
    };

    class Tree {
        private:
        Node* rootTree;

        public:
        Tree();
        ~Tree();
        Tree insert(int num);
        void  remove(int num);
        int size();
        bool contains(int num);
        int root();
        int parent(int num);
        int left(int num);
        int right(int num);
        void print();
    };
}
