#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int data;
  struct Node *left, *right;
};

enum TraversalMethods {
  PREORDER,
  INORDER,
  POSTORDER
};

class BinaryTree {
  private:
    Node *root;

    void traversePreorderWithRecursion(Node *node) {
      if (node != nullptr) {
        cout << node->data;
        traversePreorderWithRecursion(node->left);
        traversePreorderWithRecursion(node->right);
      }
    }

    void traverseInorderWithRecursion(Node *node) {
      if (node != nullptr) {
        traverseInorderWithRecursion(node->left);
        cout << node->data;
        traverseInorderWithRecursion(node->right);
      }
    }

    void traversePostorderWithRecursion(Node *node) {
      if (node != nullptr) {
        traversePostorderWithRecursion(node->left);
        traversePostorderWithRecursion(node->right);
        cout << node->data;
      }
    }
    
    void traversePreorderWithoutRecursion(Node *node) {
      stack<Node *> s;
      Node *currentNode = node;

      while (currentNode != NULL || s.empty() == false) {
        while (currentNode != NULL) {
          cout << currentNode->data;
          s.push(currentNode);
          currentNode = currentNode->left;
        }
        
        currentNode = s.top();

        s.pop();

        currentNode = currentNode->right;
      }
    }
    
    void traverseInorderWithoutRecursion(Node *node) {
      stack<Node *> s;
      Node *currentNode = node;

      while (currentNode != NULL || s.empty() == false) {
        while (currentNode != NULL) {
          s.push(currentNode);
          currentNode = currentNode->left;
        }

        currentNode = s.top();

        s.pop();
        cout << currentNode->data;

        currentNode = currentNode->right;
      }
    }

    void traversePostorderWithoutRecursion(Node *node) {
      stack<Node *> s;
      Node *currentNode = node;

      while (currentNode != NULL || s.empty() == false) {
        while (currentNode != NULL) {
          s.push(currentNode);
          currentNode = currentNode->left;
        }

        currentNode = s.top();

        if (currentNode->right == NULL) {
          cout << currentNode->data;
          s.pop();
          currentNode = NULL;
        } else {
          Node *currentNodeRight = currentNode->right;
          currentNode->right = NULL;
          currentNode = currentNodeRight;
        }
      }
    }

  public:
    BinaryTree(int rootValue) {
      Node *newNode = new Node;
      newNode->data = rootValue;
      newNode->left = nullptr;
      newNode->right = nullptr;
      root = newNode;
    }

    void print(TraversalMethods method, bool withRecursion) {
      switch (method) {
        case 0:
          cout << "[";

          if (withRecursion == true) {
            traversePreorderWithRecursion(root);
          } else {
            traversePreorderWithoutRecursion(root);
          }
          
          cout << "]" << "\n";
          break;
        case 1:
          cout << "[";

          if (withRecursion == true) {
            traverseInorderWithoutRecursion(root);
          } else {
            traverseInorderWithRecursion(root);
          }

          cout << "]" << "\n";
          break;
        case 2:
          cout << "[";

          if (withRecursion == true) {
            traversePostorderWithRecursion(root);
          } else {
            traversePostorderWithoutRecursion(root);
          }
          
          cout << "]" << "\n";
          break;
        default:
          throw "Unknown method!";
      }
    }
};
