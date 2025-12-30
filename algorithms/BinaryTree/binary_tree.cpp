#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

using namespace std;

template<typename T1, typename T2>
struct Node {
    T1 key;
    T2 value;

    Node<T1, T2>* left;
    Node<T1, T2>* right;

    Node(T1 key, T2 value)
        : key{ key }, value{ value } {
        left = nullptr;
        right = nullptr;
    }

    ~Node() {
        delete left;
        left = nullptr;

        delete right;
        right = nullptr;
    }

    T2 get(T1 k) {
        Node<T1, T2>* x = this;

        while (x != nullptr) {
            std::int32_t cmp = (k - x->key);
            if (cmp == 0) {
                return x->value;
            }

            if (cmp < 0) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        return nullptr;
    }

    void add(T1 k, T2 v) {
        Node<T1, T2>* x = this;
        Node<T1, T2>* y = nullptr;

        while (x != nullptr) {
            std::int32_t cmp = (k - x->key);
            if (cmp == 0) {
                x->value = v;
                return;
            }
            else {
                y = x;
                if (cmp < 0) {
                    x = x->left;
                }
                else {
                    x = x->right;
                }
            }
        }

        if (y == nullptr) {
            this->key = k;
            this->value = v;
        }
        else {
            Node<T1, T2>* newNode = new Node<T1, T2>(k, v);

            if ((k - y->key) < 0) {
                y->left = newNode;
            }
            else {
                y->right = newNode;
            }
        }
    }

    void remove(T1 k, bool& removeThis) {
        removeThis = false;

        Node<T1, T2>* x = this;
        Node<T1, T2>* y = nullptr;

        while (x != nullptr) {
            std::int32_t cmp = (k - x->key);
            if (cmp == 0) {
                break;
            }
            else {
                y = x;
                if (cmp < 0) {
                    x = x->left;
                }
                else {
                    x = x->right;
                }
            }
        }

        if (x == nullptr) {
            return;
        }

        if (x->right == nullptr) {
            if (y == nullptr) {
                if (x->left != nullptr) {
                    this->key = x->left->key;
                    this->value = x->left->value;

                    delete x->left;
                    x->left = nullptr;
                }
                else {
                    removeThis = true;
                }
            }
            else {
                if (x == y->left) {
                    y->left = x->left;
                }
                else {
                    y->right = x->left;
                }
            }
        }
        else {
            Node<T1, T2>* leftMost = x->right;
            y = nullptr;

            while (leftMost->left != nullptr) {
                y = leftMost;
                leftMost = leftMost->left;
            }

            if (y != nullptr) {
                y->left = leftMost->right;
            }
            else {
                x->right = leftMost->right;
            }

            x->key = leftMost->key;
            x->value = leftMost->value;

            delete leftMost;
            leftMost = nullptr;
        }
    }
};


int main()
{
    Node<std::int32_t, std::int32_t>* root = new Node<std::int32_t, std::int32_t>(1, 1);
    root->add(-2, 4);
    root->add(1, 8);
    root->add(3, 12);

    Node<std::int32_t, std::int32_t>* x = root;
    while (x != nullptr) {
        std::cout << x->key << " ; " << x->value << std::endl;
        x = x->right;
    }
    x = root;

    std::cout << " -------------------------------- " << std::endl;
    while (x != nullptr) {
        std::cout << x->key << " ; " << x->value << std::endl;
        x = x->left;
    }

    system("PAUSE");
    return 0;
}
