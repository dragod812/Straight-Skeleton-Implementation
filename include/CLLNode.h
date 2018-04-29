#ifndef CLLNODE_H
#define CLLNODE_H
class CLLNode;
#include<memory>
#include "Vertex.h"
#include "CLL.h"
class CLLNode{
public:
    Vertex* item;
    CLL* container;
    CLLNode* forward;
    CLLNode* back;
    CLLNode();
    CLLNode(Vertex* value);
    CLLNode(CLL* cont, Vertex* value);
    CLLNode(CLL* cont, Vertex* value, CLLNode* f,CLLNode* b);
    void detach();
    void insertBetween( CLL* cont, CLLNode* prev,CLLNode* next );
};
#endif
