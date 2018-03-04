//
// Created by Jack on 9/5/2017.
//

#include "Avl.h"
#include <iostream>
#include "Node.h"

using namespace std;

//Node *root;

Avl::Avl(Node *root){
    this->root = root;
}

void Avl::setRoot(Node *root) {
    Avl::root = root;
}

Avl::Avl(int id ) {
    root = new Node(id);

}

void Avl::PrintAvl(Node *root, int level) {
    int i;
    if (root != NULL) {
        PrintAvl(root->right, level + 1);
        printf("\n");
        if (root == this->root)
            cout << "Root -> ";
        for (i = 0; i < level && root != this->root; i++)
            cout << "        ";
        cout << root->id;
        PrintAvl(root->left, level + 1);
    }

}


Node *Avl::getRoot() const {
    return root;
}

Node *Avl::insert(int id, Node *root) {

    if (root == NULL) {
        root = new Node;
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

void *Avl::Delete(int i) {
    Node *target = Search(i,root);
    Node  *temp = FindMax(target->left);

    PreDelete(target,temp->id);
    target->id = temp->id;
    delete temp;
    Balance(target);
}

Node *Avl::FindMax(Node *node) {
    Node *it = node;
    while (it->right != NULL) {
        it = it->right;
    }
    return it;

}

Node *Avl::FindMin(Node *node) {
    Node *it = node;
    while (it->left != NULL && it->right == NULL) {

        it = it->left ? it->left : it->right;
    }

    return it;

}

int Avl::BalanceFactor(Node *node) {
    int lh = 0, rh = 0;
    if (node->right != NULL)
        rh = node->right->getHeight();
    if (node->left != NULL)
        lh = node->left->getHeight();

    return (rh - lh);
}

void Avl::fixheight(Node *p) {
    int hl = 0, hr = 0;
    if (p->left)
        int hl = p->left->getHeight();

    if (p->right)
        hr = p->right->getHeight();
    p->height = max(hl, hr) + 1;
}

//OK
Node *Avl::Search(int x, Node *node) {
    if (node == NULL) {
        return NULL;
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
Node *Avl::Left(Node *root) {
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    fixheight(root);
    fixheight(temp);
    return temp;
}

Node *Avl::Right(Node *root) {
    Node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    fixheight(root);
    fixheight(tmp);
    return tmp;
}

Node *Avl::Balance(Node *node) {
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

void Avl::PreDelete(Node *p, int i) {
    while(p){

        if(i<p->id){
            if(p&&p->left->id==i){
                p->left =NULL;
                break;
            }

            p=p->left;
        } else{
            if(p&&p->right->id==i){
                p->right =NULL;
                break;
            }
            p=p->right;
        }

    }


}

Avl::~Avl() {

}


