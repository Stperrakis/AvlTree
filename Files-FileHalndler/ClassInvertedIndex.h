//
// Created by Jack on 5/6/2017.
//
#include <iostream>
#include <fstream>
#include <string.h>
#include "../Avl-Nodes/Avl.h"
#include "../Avl-Nodes/SuperiorAvlNode.h"
#include "../Avl-Nodes/SuperiorAvl.h"

#ifndef AVLTREE_COPY_READWRITE_H
#define AVLTREE_COPY_READWRITE_H
using namespace std;

class FileHandler {
private :
    char *c;
    int pos=0;
    unsigned long size;
    SuperiorAvl *myTree = nullptr; // here is our tree!
public:
    virtual ~FileHandler();

public:
    unsigned long getSize() const;
    FileHandler(string name);
    void GetAction();
    int GetInteger();
    void Insert(int i, int j);
    void Delete(int i, int j);
    void setPos(int pos);
    void Inorder( SuperiorAvlNode *Tree,ofstream& myfile);

    string Inorder2(Node *p,ofstream& myfile, string s);
};


#endif //AVLTREE_COPY_READWRITE_H
