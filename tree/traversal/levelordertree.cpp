#include <iostream>
#include <stdio.h>

struct Node{
    int data;
    Node* left;
    Node* right;
};

int height(Node* root){
    
    if(root == nullptr)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return leftHeight>rightHeight ? leftHeight +1 : rightHeight + 1;
}
Node* newNode(int data)
{
    Node* node = new Node;
    node->data =data;
    node->left=nullptr;
    node->right=nullptr;

    return node;
}


void printGivenLevel(Node* node,int level){
    
    if(node== nullptr)
        return; 
    
    if(level==1)
        std::cout << " item: "<<node->data<<std::endl;
    else {
        printGivenLevel(node->left,level-1);
        printGivenLevel(node->right,level-1);
    }
}

void printLevelOrderTraversal(Node* root){

    if(root == nullptr)
        return;
    
    int h = height(root);
    for(int i=1;i<=h; i++){
        printGivenLevel(root,i);
    }
}

int main(){

    Node* root = newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left= newNode(4);
    root->left->right= newNode(5);
    root->left->left->left= newNode(6);
    std::cout << "height of tree :" << height(root)<<std::endl;
    printLevelOrderTraversal(root);
    return 0;
}