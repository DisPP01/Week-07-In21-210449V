#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key <<" ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL){
        struct node *newNode = new struct node;
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL)
        return root;
 
    // if the selected key is smaller than the root's key then derecting the search towards left sub tree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // if the selected key is greater than the root's key then derecting the search towards right sub tree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;
 
        // node with only one child or no child
        else if (root->left == NULL) {   //if the left child is empty
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {  //if the right child is empty
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        //deleting a node with two children
        struct node* current = root -> right;
         
            //finding the left most child
            while (current && current->left != NULL)
                current = current->left;
        struct node* temp = current;
        //getting inorder successor's key to the temp -> key
        root->key = temp->key;
 
        // Deleting the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}