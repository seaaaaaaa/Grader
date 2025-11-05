#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }
    bool isSameBinaryTree(Tree& t) {
        // Insert your code here
        return isSameNode(this->mRoot, t.mRoot);
    }
    // You can also put your code here
    bool isSameNode(Node* node1, Node* node2) {
        
        // Base Case 1: ถ้าทั้งสองโหนดเป็น NULL (ว่าง)
        // แสดงว่ามันเหมือนกัน (ตามโจทย์ข้อ 5)
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }

        // Base Case 2: ถ้าโหนดใดโหนดหนึ่งว่าง แต่อีกโหนดไม่ว่าง
        // แสดงว่าโครงสร้างไม่เหมือนกัน
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        // Recursive Step (ตามโจทย์ข้อ 6)
        // ตรวจสอบ 3 เงื่อนไข:
        // a. data เหมือนกัน
        // b. ลูกซ้ายเหมือนกัน (เรียก isSameNode กับลูกซ้าย)
        // c. ลูกขวาเหมือนกัน (เรียก isSameNode กับลูกขวา)
        return (node1->data == node2->data) &&
               isSameNode(node1->left, node2->left) &&
               isSameNode(node1->right, node2->right);
    }

protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
           r = new Node(x, NULL, NULL);
           mSize++;
           return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
