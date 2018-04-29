#include "CLL.h"
#include "CLLNode.h"
CLL::CLL(){
    first = nullptr;
}

CLL::CLL(CLLNode* first){
    this->first = first;
}
bool CLL::verifyNode(CLLNode* node){
    return (node->container == (this));
}
void CLL::print(){
    if(first != nullptr){
        cout << "CLL: " << endl;
        cout << "first: " << first->item->coord.toString() << endl;
        CLLNode* x = first;
        do{
        cout << x->item->coord.toString() << "->";
        x = x->forward;
        }while(x != first);
    }
    cout << endl;
}

void CLL::addLast(Vertex* node){
    cout << "//newNode to be returned" << endl;
    if(first == nullptr){
        cout << 1 << endl;
        CLLNode* clln(new CLLNode(node));
        cout << "inside al" << clln->item->coord.toString() << clln<<endl;
        //node->cllNode = clln;
        first = clln;
        cout << "first: " << first->item->coord.toString()<<"stb"<<  clln->item->coord.toString() << endl;
    }
    else{
        cout << 2 << node->coord.toString() << endl;

        cout << "first: " << first->item->coord.toString() << endl;
        cout << "first->back: " << first->back->item->coord.toString() << endl;
        CLLNode* clln(new CLLNode((this), node, first, first->back));
        cout << "first: " << first->item->coord.toString() << endl;
        print();
        node->cllNode = clln;
    }
}

