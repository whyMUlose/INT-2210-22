#include <iostream>
using namespace std;


// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* otherChild;

public:
    Node() {
        this -> data = 0;
        this -> fatherNode = NULL;
        this -> firstChild = NULL;
        this -> otherChild = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node(int data) {
        this -> data = data;
        this -> fatherNode = NULL;
        this -> firstChild = NULL;
        this -> otherChild = NULL;
    }

    Node* findNode(Node *temp, int const data){
        if (temp) {
            if (temp->data == data) {
                return temp;
            }
            Node *p = findNode(temp->firstChild, data);
            if (p) {
                return p;
            }
            p = findNode(temp->otherChild, data);
            if (p) {
                return p;
            }
        }
        return NULL;
    }

    void preorder(Node* temp){
        if (temp) {
            cout << temp->data << " ";
            preorder(temp->firstChild);
            preorder(temp->otherChild);
        }
    }

    void postorder(Node* temp){
        if (temp) {
            preorder(temp->firstChild);
            preorder(temp->otherChild);
            cout << temp->data << " ";
        }
    }

    bool isBinaryTree(Node *temp){
        if (temp) {
            if (temp->firstChild && temp->firstChild->otherChild && temp->firstChild->otherChild->otherChild) {
                return false;
            }
            return (!isBinaryTree(temp->firstChild) || !isBinaryTree(temp->otherChild) ? false : true);
        }
        return true;
    }

    bool isBinarySearchTree(Node*temp){ // chua dung 100%
        if (temp) {
            if (temp->firstChild && temp->firstChild->otherChild) {
                if (temp->firstChild->data > temp->data || temp->firstChild->otherChild->data < temp->data) {
                        return false;
                    }
            }
            return (!isBinarySearchTree(temp->firstChild) || !isBinarySearchTree(temp->otherChild) ? false : true);
        }
        return true;
    }

    bool isMaxHeapTree(Node *temp) {
        if (temp) {
            if (temp->firstChild) {
                if (temp->firstChild->data > temp->data) {
                        return false;
                    }
                if (temp->firstChild->otherChild && temp->firstChild->otherChild->data > temp->data) {
                        return false;
                    }
            }
            return (!isMaxHeapTree(temp->firstChild) || !isMaxHeapTree(temp->otherChild) ? false : true);
        }

        return true;
    }

    void findMax(Node*temp, int& max){
        if (temp) {
            if (temp->data > max) {
                max = temp->data;
            }
            findMax(temp->firstChild, max);
            findMax(temp->otherChild, max);
        }
    }

    int numOfLeaves(Node* temp) {
        if (temp) {
            if (!temp->firstChild) {
                return 1 + numOfLeaves(temp->otherChild);
            }else {
                return numOfLeaves(temp->firstChild) + numOfLeaves(temp->otherChild);
            }
        }
        return 0;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        // ...
        root = new Node();
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Tree(int data) {
        root = new Node(data);
    }

    void printData()
    {
        //
    }

    Node *find(int data) {
        return root->findNode(root, data);
    }
    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data)
    {
        Node *l = root->findNode(root, father);
        if (l == NULL) {
            return false;
        }

        Node *temp = new Node(data);
        temp->fatherNode = l;
        if (l->firstChild == NULL || l->firstChild->data > temp->data) {
                temp->otherChild = l->firstChild;
                l ->firstChild = temp;
            return true;
        }

        if (l->firstChild->otherChild == NULL || l->firstChild->otherChild->data > temp->data) {
                temp->otherChild = l->firstChild->otherChild;
                l->firstChild->otherChild = temp;
            return true;
        }
        l = l->firstChild->otherChild;
        while(l->otherChild != NULL && l->otherChild->data > temp->data) {
                l = l->otherChild;
        }
        temp->otherChild = l->otherChild;
        l->otherChild = temp;
        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data);

    // Hàm in ra các Node theo thứ tự preorder
    void preorder()
    {
        root->preorder(root);
        cout << "\n";
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder()
    {
        root->postorder(root);
        cout << "\n";
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree()
    {
        return root->isBinaryTree(root);
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree()
    {
        if (!root->isBinaryTree(root)) {
            return false;
        }
        return root->isBinarySearchTree(root);
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree()
    {
        if (!root->isBinaryTree(root)) {
            return false;
        }
        return root->isMaxHeapTree(root);
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder();

    // Hàm trả về độ cao của cây
    int height();

    // Hàm trả về độ sâu của một Node
    int depth(int data);

    // Hàm đếm số lượng lá
    int numOfLeaves()
    {
        if (root) {
            return root->numOfLeaves(root);
        }
        return 0;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax()
    {
        int max = root->data;
        root->findMax(root, max);
        return max;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây
    Tree *tree1 = new Tree(3);
    tree1->insert(2, 3);
    tree1->insert(2, 4);
    tree1->insert(2, 8);
    tree1->insert(3, 12);
    tree1->insert(3, 11);
    tree1->insert(3, 7);
    tree1->insert(4, 6);
    tree1->insert(4, 5);
    tree1->insert(8, 9);
    tree1->insert(9, 13);
    tree1->insert(9, 10);
    tree1->preorder();
    tree1->postorder();
    cout << boolalpha << tree1->isBinaryTree() << "\n";
    cout << boolalpha << tree1->isBinarySearchTree() << "\n";
    cout << boolalpha << tree1->isMaxHeapTree() << "\n";
    cout << tree1->findMax() << "\n";
    cout << tree1->numOfLeaves() << "\n";
    cout << "\n";
    // Tạo ra một cây thoả mãn tính chất là Binary Tree và test lại
    Tree *tree2 = new Tree(3);
    tree2->insert(3, 1);
    tree2->insert(3, 8);
    tree2->insert(1, 12);
    tree2->insert(1, 11);
    tree2->insert(8, 9);
    tree2->insert(9, 13);
    tree2->insert(9, 10);
    tree2->preorder();
    tree2->postorder();
    cout << boolalpha << tree2->isBinaryTree() << "\n";
    cout << boolalpha << tree2->isBinarySearchTree() << "\n";
    cout << boolalpha << tree2->isMaxHeapTree() << "\n";
    cout << tree2->findMax() << "\n";
    cout << tree2->numOfLeaves() << "\n";
    cout << "\n";
    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    Tree *tree3 = new Tree(10);
    tree3->insert(10, 1);
    tree3->insert(10, 15);
    tree3->insert(1, 2);
    tree3->insert(2, 3);
    tree3->insert(15, 11);
    tree3->insert(15, 16);
    tree3->insert(11, 13);
    tree3->insert(16, 17);
    tree3->preorder();
    tree3->postorder();
    cout << boolalpha << tree3->isBinaryTree() << "\n";
    cout << boolalpha << tree3->isBinarySearchTree() << "\n";
    cout << boolalpha << tree3->isMaxHeapTree() << "\n";
    cout << tree3->findMax() << "\n";
    cout << tree3->numOfLeaves() << "\n";
    cout << "\n";
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    Tree *tree4 = new Tree(10);
    tree4->insert(10, 9);
    tree4->insert(10, 8);
    tree4->insert(9, 7);
    tree4->insert(9, 6);
    tree4->insert(8, 5);
    tree4->insert(5, 4);
    tree4->preorder();
    tree4->postorder();
    cout << boolalpha << tree4->isBinaryTree() << "\n";
    cout << boolalpha << tree4->isBinarySearchTree() << "\n";
    cout << boolalpha << tree4->isMaxHeapTree() << "\n";
    cout << tree4->findMax() << "\n";
    cout << tree4->numOfLeaves() << "\n";
    cout << "\n\n";

    return 0;
}

