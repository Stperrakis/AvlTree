#include <iostream>
#include "string.h"
#include "Avl-Nodes/Avl.h"
#include "Avl-Nodes/SuperiorAvlNode.h"
#include "Files-FileHalndler/ClassInvertedIndex.h"

using namespace std;
int main() {
   std::cout << "Hello, World!" << std::endl;
    //Avl a(0);
    string namefile ("../Commands.txt");
    FileHandler myFile(namefile);
    myFile.GetAction();
    delete myFile;

  /*
    a.insert(11,a.getRoot());

    a.insert(131,a.getRoot());

    a.insert(1,a.getRoot());

    a.insert(18,a.getRoot());
    a.insert(31,a.getRoot());
    a.insert(22,a.getRoot());
    a.insert(4,a.getRoot());
    a.insert(90,a.getRoot());
    a.insert(7,a.getRoot());



    a.insert(8,a.getRoot());

    a.insert(120,a.getRoot());
   // cout<<a.getRoot()->id<<" : THIS IS  GROOT"<<endl;
        a.PrintAvl(a.getRoot(),1);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    a.Delete(12);
    a.insert(12, a.getRoot());
    a.PrintAvl(a.getRoot(),1);


*/
    return 0;
}