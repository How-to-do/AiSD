#include <iostream>
#include <queue>
#include <stack>
#include <assert.h>


using namespace std;


template <class T>
void print(T& val) {
    cout << val << " ";
}

template <class T>
class Comparator {
public:
    int operator()(const T& lhs, const T& rhs) {
        if (lhs == rhs) {
            return 0;
        }
        if (lhs < rhs) {
            return 1;
        }
        return -1;
    }
};
//struct LibraryBook {
//    unsigned int AuthorIds[3];
//    std::string title;
//};
//
//class Comparator {
//public:
//    int operator()(const struct LibraryBook& lhs, const struct LibraryBook& rhs) {
//        int l = 0;  // если больше 0, значит левый меньше
//        for (int i = 0; i < 3; ++i) {
//            if (lhs->AuthorIds[i] < rhs->AuthorIds[i]) {
//                l++;
//            }
//            else if (lhs->AuthorIds[i] > rhs->AuthorIds[i]) {
//                l--;
//            }
//        }
//
//        if (l == 0) {
//            return 0;
//        }
//        if (l > 0) {
//            return 1;
//        }
//        return -1;
//    }
//};

template <class T, class Comparator>
class Tree {
    struct Node {
        T key;
        Node* left;
        Node* right;

        Node(const T& _key): key(_key), left(nullptr), right(nullptr) {}
    };

public:
    explicit Tree(Comparator _comp): root(nullptr), comp(_comp) {}
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;
    ~Tree() {
        if (root == nullptr) {
            return;
        }
        stack<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            Node* current = nodes.top();

            if (current->left == nullptr && current->right == nullptr) {
                nodes.pop();
                delete current;
                continue;
            }

            if (current->left != nullptr) {
                nodes.push(current->left);
                current->left = nullptr;
            }
            if (current->right != nullptr) {
                nodes.push(current->right);
                current->right = nullptr;
            }
        }
    }

    void insert(const T& key) {
        Node* current = root;
        while (current != nullptr) {
            if (comp(key, current->key) == 1) {
                if (current->left == nullptr) {
                    current->left = new Node(key);
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(key);
                    return;
                }
                current = current->right;
            }
        }

        root = new Node(key);
    }
    bool find(const T& key) {
        Node* current = root;
        while (current != nullptr) {
            if (comp(key, current->key) == 1) {
                current = current->left;
            } else if (comp(key, current->key) == 0) {
                return true;
            } else {
                current = current->right;
            }
        }

        return false;
    }
    bool del(const T& key) {
        if (root == nullptr) {
            return false;
        }

        if (comp(key, root->key) == 0) {
            del_node(root);
            return true;
        }

        Node* parent = root;
        Node* current = root;
        while (current != nullptr) {
            if (comp(key, current->key) == 1) {
                parent = current;
                current = current->left;
            } else if (comp(key, current->key) == 0) {
                del_node((parent->left == current) ? parent->left : parent->right);
                return true;
            } else {
                parent = current;
                current = current->right;
            }
        }

        return false;
    }

    void TraverseBFS(void (*visit)(T&)) {
        if (root == nullptr) {
            return;
        }
        queue<Node*> row;
        row.push(root);
        while (!row.empty()) {
            Node* current = row.front();
            row.pop();
            visit(current->key);
            if (current->left != nullptr) {
                row.push(current->left);
            }
            if (current->right != nullptr) {
                row.push(current->right);
            }
        }
    }

    bool is_sames() {
        if (root == nullptr) {
            return true;
        }

        T value = root->key;

        queue<Node*> row;
        row.push(root);
        while (!row.empty()) {
            Node* current = row.front();
            row.pop();

            if (value != current->key) {
                return false;
            }

            if (current->left != nullptr) {
                row.push(current->left);
            }
            if (current->right != nullptr) {
                row.push(current->right);
            }
        }

        return true;
    }

private:
    void del_node(Node*& current) {
        if (current->left == nullptr) {
            Node* right = current->right;
            delete current;
            current = right;
        }
        else if (current->right == nullptr) {
            Node* left = current->left;
            delete current;
            current = left;
        }
        else {
            Node* min_parent = current;
            Node* min_node = current->right;
            while (min_node->left != nullptr) {
                min_parent = min_node;
                min_node = min_node->left;
            }

            current->key = min_node->key;
            ((min_parent->left == min_node) ? min_parent->left : min_parent->right) = min_node->right;
            delete min_node;
        }
    }

    Node* root;
    Comparator comp;

};


typedef void (*Tests)();

template <class T>
void pow(T& val) {
    val *= val;
}

void test1() {
    int n = 3;
    Comparator<int> comp;
    Tree<int, Comparator<int>> tree(comp);

    tree.insert(4);
    tree.insert(4);
    tree.insert(4);

    tree.TraverseBFS(print);
    cout << endl;
    cout << tree.is_sames() << endl;
//    tree.TraverseBFS(pow);
//    tree.TraverseBFS(print);
//    cout << endl;
//
//    tree.del(1);
//    tree.TraverseBFS(print);
//    cout << endl;
}

void test2() {
    Comparator<int> comp;
    Tree<int, Comparator<int>> tree(comp);

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(20);
    tree.insert(21);
    tree.insert(25);
    tree.insert(14);

    tree.TraverseBFS(print);
    cout << endl;

    tree.del(20);
    tree.TraverseBFS(print);
    cout << endl;
}

void test3() {
    Comparator<int> comp;
    Tree<int, Comparator<int>> tree(comp);

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);

    tree.TraverseBFS(print);
    cout << endl;
}

void test4() {
    Comparator<int> comp;
    Tree<int, Comparator<int>> tree(comp);

    tree.insert(3);
    tree.insert(1);
    tree.insert(2);

    tree.TraverseBFS(print);
    cout << endl;
}

void test5() {
    Comparator<int> comp;
    Tree<int, Comparator<int>> tree(comp);

    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);

    tree.TraverseBFS(print);
    cout << endl;
}

void test6() {
    Comparator<int> comp;
    Tree<int, Comparator<int>> tree(comp);

    tree.insert(1);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(4);

    tree.TraverseBFS(print);
    cout << endl;
}

int main() {
    Tests tests[] = {test1, test2, test3, test4, test5, test6};

    for (int i = 0; i < 6; ++i) {
        tests[i]();
        cout << "test" << i + 1 << " - OK" << endl;
    }

//    int n;
//    cin >> n;
//
//    Comparator<int> comp;
//    Tree<int, Comparator<int>> tree(comp);
//
//    for (int i = 0; i < n; ++i) {
//        int tmp;
//        cin >> tmp;
//        tree.insert(tmp);
//    }
//
//    tree.TraverseBFS();

    return 0;
}
