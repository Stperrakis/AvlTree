//
// Created by Jack on 17/6/2017.
//

#include "SuperiorAvl.h"
#include "SuperiorAvlNode.h"
#include "Node.h"
//Node *root;
#include <iostream>


void SuperiorAvl::setRoot(SuperiorAvlNode *root) {
    SuperiorAvl::root = root;
}

SuperiorAvl::SuperiorAvl(int id ) {
    root = new SuperiorAvlNode(id);

}
SuperiorAvlNode *SuperiorAvl::getRoot() const {
    return root;
}
SuperiorAvlNode *SuperiorAvl::insert(int id,SuperiorAvlNode *root) {

    if (root == nullptr) {
        root = new SuperiorAvlNode();
        root->id = id;
        return Balance(root);
    } else {
        if (root->id > id) {
            root->left = insert(id, root->left);
            return Balance(root);
        } else if (root->id < id){
            root->right = insert(id, root->right);
            return Balance(root);
        } else{
            return root;
        }
    }
}
SuperiorAvlNode *SuperiorAvl::insertSuperiorNode(SuperiorAvlNode *superiorNode, SuperiorAvlNode *root) {

    if (root == nullptr) {
        root = superiorNode;
        return Balance(root);
    } else {
        if (root->id > superiorNode->id) {
            root->left = insertSuperiorNode(superiorNode, root->left);
            return Balance(root);
        } else if (root->id < superiorNode->id){
            root->right = insertSuperiorNode(superiorNode, root->right);
            return Balance(root);
        } else{
            return superiorNode;
        }
    }
}


SuperiorAvlNode *SuperiorAvl::FindMax(SuperiorAvlNode *node) {
    SuperiorAvlNode *it = node;
    while (it->right != nullptr) {
        it = it->right;
    }
    return it;

}
SuperiorAvlNode *SuperiorAvl::FindMin(SuperiorAvlNode *node) {
    SuperiorAvlNode *it = node;
    while (it->left != nullptr && it->right == nullptr) {

        it = it->left ? it->left : it->right;
    }

    return it;

}
int SuperiorAvl::BalanceFactor(SuperiorAvlNode *node) {
    int lh = 0, rh = 0;
    if (node->right != nullptr)
        rh = node->right->getHeight();
    if (node->left != nullptr)
        lh = node->left->getHeight();

    return (rh - lh);
}
void SuperiorAvl::fixheight(SuperiorAvlNode *p) {
    int hl = 0, hr = 0;
    if (p->left)
        int hl = p->left->getHeight();

    if (p->right)
        hr = p->right->getHeight();
    p->height = hl+1?hl>hr:hr+1;
}
//OK
SuperiorAvlNode *SuperiorAvl::Search(int x, SuperiorAvlNode *node) {
    if (node ==nullptr) {
        return nullptr;
    }

    if (x == node->id) {
        //  cout<<node<<endl;
        return node;
    }

    if (x > node->id) {

        return Search(x, node->right);
    } else {
        return Search(x, node->left);
    }
}
//OK!
SuperiorAvlNode *SuperiorAvl::Left(SuperiorAvlNode *root) {
    SuperiorAvlNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    fixheight(root);
    fixheight(temp);
    return temp;
}
SuperiorAvlNode *SuperiorAvl::Right(SuperiorAvlNode *root) {
    SuperiorAvlNode *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    fixheight(root);
    fixheight(tmp);
    return tmp;
}
SuperiorAvlNode *SuperiorAvl::Balance(SuperiorAvlNode *node) {
    fixheight(node);
    int d = BalanceFactor(node);
    if (d == 2) {
        if (BalanceFactor(node->right) < 0)
            node->right = Right(node->right);
        return Left(node);
    } else if (d == -2) {
        if (BalanceFactor(node->left) > 0)
            node->left = Left(node->left);
        return Right(node);

    }
    return node;
}
void SuperiorAvl::PreDelete(SuperiorAvlNode *p, int i) {
    while(p){

        if(i<p->id){
            if(p&&p->left->id==i){
                p->left = nullptr;
                break;
            }

            p=p->left;
        } else{
            if(p&&p->right->id==i){
                p->right =nullptr;
                break;
            }
            p=p->right;
        }

    }
}

SuperiorAvl::~SuperiorAvl() {

}




