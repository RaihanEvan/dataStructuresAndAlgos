#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(Node* root) {
    if (root == nullptr)
        return;
        
    stack<Node*> stack;
    stack.push(nullptr);
    int top = 1;
    Node* ptr = root;

    while (ptr != nullptr) {
        cout << ptr->data << " ";

        if (ptr->right != nullptr) {
            stack.push(ptr->right);
            top++;
        }

        if (ptr->left != nullptr) {
            ptr = ptr->left;
        } else {
            ptr = stack.top();
            stack.pop();
            top--;
        }
    }
}
void inOrder(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> stack;
    stack.push(nullptr);
    int top = 1;
    Node* ptr = root;

    while (ptr != nullptr) {
        stack.push(ptr);
        top++;
        ptr = ptr->left;
    }

    ptr = stack.top();
    stack.pop();
    top--;

    while (ptr != nullptr) {
        cout << ptr->data << " ";

        if (ptr->right != nullptr) {
            ptr = ptr->right;
            while (ptr != nullptr) {
                stack.push(ptr);
                top++;
                ptr = ptr->left;
            }
        }

        ptr = stack.top();
        stack.pop();
        top--;
    }
}
void postOrder(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> stack;
    stack.push(root);
    stack.push(root);

    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();

        if (!stack.empty() && current == stack.top()) {
            if (current->right) {
                stack.push(current->right);
                stack.push(current->right);
            }
            if (current->left) {
                stack.push(current->left);
                stack.push(current->left);
            }
        } else {
            cout << current->data << " ";
        }
    }
}

int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->right = new Node('G');

    cout << "Preorder traversal: ";
    preOrder(root);
    cout << "\nInorder traversal: ";
    inOrder(root);
    cout << "\nPostorder traversal: ";
    postOrder(root);
    

    return 0;
}
