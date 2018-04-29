#ifndef CLL_H
#define CLL_H
class CLL;
#include "CLLNode.h"
class CLL{
    public:
	CLLNode* first;
	CLL();

	CLL(CLLNode* first);
    void print();
	bool verifyNode(CLLNode* node);
    void addLast(Vertex* node);
};
#endif
