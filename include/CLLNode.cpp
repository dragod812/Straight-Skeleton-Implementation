#include "CLLNode.h"
#include "Vertex.h"
#include "CLL.h"

CLLNode::CLLNode(){
}
CLLNode::CLLNode(Vertex* value){
    cout << "inside Clln" <<this<< endl;
    cout << value->coord.toString() << endl;
	item = value;

    value->cllNode = (this);
	forward =(this);
    back= (this);
    value->processed = false;

}
CLLNode::CLLNode(CLL* cont, Vertex* value){
	item = value;
    value->cllNode = (this);
	container = cont;
	forward = (this);
	back= (this);
    value->processed = false;
}
CLLNode::CLLNode(CLL* cont, Vertex* value, CLLNode* f,CLLNode* b){
	item = value;
    cout << item->coord.toString() << endl;
    cout << "F: " << f->item->coord.toString() << endl;
    cout << "B: " << b->item->coord.toString() << endl;

    value->cllNode = (this);
	container = cont;
	forward = f;
	back= b;
	b->forward = (this);
	f->back= (this);
    value->processed = false;
    cout << "Done with new addition!" << endl;
}
void CLLNode::detach(){
	back->forward = forward;
	forward->back = back;

	forward = back= NULL;
	container = NULL;
}
void CLLNode::insertBetween( CLL* cont, CLLNode* prev,CLLNode* next ){

	prev->forward = (this);
	this->forward = next;
	next->back = (this);
	this->back = prev;
	this->container;
}
