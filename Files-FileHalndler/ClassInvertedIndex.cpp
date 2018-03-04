//
// Created by Jack on 5/6/2017.
//
#include <sstream>
#include "ClassInvertedIndex.h"
#include "../Avl-Nodes/Avl.h"
#include "../Avl-Nodes/SuperiorAvlNode.h"


FileHandler::FileHandler(string name) {
    ifstream in(name);
    if (in.is_open()) {
        string contents((istreambuf_iterator<char>(in)),
                        istreambuf_iterator<char>());
        size = contents.length();
        c = new char[size];
        strcpy(c, contents.c_str());
        in.close();

    } else {
        cerr << "Could not open this file: " + name << endl;
    }

}

void FileHandler::Insert(int i, int j) {
    // if This tree doesnt exist go create it and add the sub node
    if (this->myTree == NULL) {
        myTree = new SuperiorAvl(i);
    }
    SuperiorAvlNode *p = myTree->Search(i, myTree->getRoot());
    if(!p){
        p = myTree->insert(i,myTree->getRoot());
    }
    if (p->nestedAvl == nullptr) {
        p->nestedAvl = new Avl(j);
    } else {
        Node *temp = p->nestedAvl->Search(j, p->nestedAvl->getRoot());
        if (temp == NULL) {
            p->nestedAvl->insert(j, p->nestedAvl->getRoot());
        }
    }
}

void FileHandler::Delete(int i, int j) {
    if (myTree) { //does my tree exist's ?
        SuperiorAvlNode *p = myTree->Search(i, myTree->getRoot()); //search this root
        if (p) {
            p->nestedAvl->Delete(j); // if nested exist too  delete this element
        }
    } else {
        cout << "There is no Such a Link on Superior Avl" << endl;
    }
}

void FileHandler::GetAction() {
    int i = 0, a = 0, r=0;
    char s;
    while (pos != size) { //Checking if you are in the end
        s = c[i];//store it in char s
        if(r==0) { //if you didn't have been executed a command
            r=1; //make that you executed once every Command.txt starting with command
            if (s == 'I') { //if its insertion
                pos = pos + 10;
                int d1 = GetInteger(); //get two positive integers
                int d2 = GetInteger();
                Insert(d1, d2); //insert them

            } else if (s == 'D') { //if its delete
                /*pos = pos + 10;
                int d1 = GetInteger();
                int d2 = GetInteger();
                Delete(d1, d2);*/


            } else if (s == 'W') {//If its write index then do writting

                ofstream myOutPutFile("output.txt"); //open file
                if (myOutPutFile) {// if you opened it
                    if (myOutPutFile && myTree) { // and the subtrees exist defensive programming
                        SuperiorAvlNode *root = myTree->getRoot(); // then write them with in order
                        Inorder(root, myOutPutFile);
                        myOutPutFile.close();
                    }
                } else {
                    cerr << "Could not open the file" << endl;
                }
                break; // break the lupe as we dont want to read anymore !
            } else if (s == 'R') { // if its R Read index
                pos = pos + 8; //Just set the position in this file , do not itterate without reason

                FileHandler s("../input.txt"); // take the input.txt
                int numb = 1;
                while (numb > 0) { // till the last integer on the file !
                    numb = s.GetInteger(); //get two integers
                    int numb2 = s.GetInteger();
                    if (numb < 0 || numb2 < 0) { // if someone of them is 0 or bellow then break the lupe
                        break;
                    }
                    Insert(numb, numb2); // inserting
                }

            }
        }
        else{
            r=0; // if you didn't execute command then we will find a command
            while(c[pos]!='\n'){ //Just go where the line finishes
                pos++;
            }
            pos++; // when line 108 finishes it will point on \n we want the next one
        }
        i++; //itterator of the matrix we sotrred the file
    }
}

string FileHandler::Inorder2(Node *p, ofstream &myfile , string s) {
    if (p == NULL) {
        return s;
    }
    Inorder2(p->left, myfile, s);
        s+= to_string(p->id);
    Inorder2(p->right, myfile,s);
    return s;
}

void FileHandler::Inorder(SuperiorAvlNode *root, ofstream &myfile) {
    if (root == NULL)
        return;
    Inorder(root->left, myfile);
    if (root->nestedAvl) {
        string s ("");
        Node *p = root->nestedAvl->getRoot();
        Inorder2(p, myfile, s);
        myfile << "ID: " << root->id << ", "<<s.length()-1<<s <<endl;
    }
    Inorder(root->right, myfile);

}

int FileHandler::GetInteger() {
    int number = 0; // return number
    if(pos==size) //if the size ==pos that means that maybe you have finished and the other bottom it might be trashes or signature of the file
        return -1 ; //return a negative
    while (c[pos] <= '9') {
        if (c[pos] > '0' && c[pos] <= '9') {
            number += c[pos] - 48; // converting from ASCII
        }
        if (c[pos + 1] != '\t' && c[pos + 1] != '\r' && c[pos + 1] != '\0') { // if its not something of these.
            number = number * 10; //  then multiply it by
        } else {
            break;// if its something of these stop out of the interested area

        }
        pos++;
    }
    pos++;
    return number;
}

void FileHandler::setPos(int pos) {
    FileHandler::pos = pos;
}

unsigned long FileHandler::getSize() const {
    return size;
}

FileHandler::~FileHandler() {

}
