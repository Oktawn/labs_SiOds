#include "LST.h"
#include "LST.cpp"

int main()
{
    ray<int>* head = NULL;
    ray<int>* head_second = NULL;
    ray<int>* list=NULL;

    cout << "\n";
    head =addHead(head, 11);
    head = addHead(head, 1365);
    head = addTail(head, 57);
        showList(head);

    head_second = addHead(head_second, 157);
    head_second = addHead(head_second, 137);
    head_second = addHead(head_second, 147);

    showList(head_second);
    disjunct(head, head_second, list);
    showList(list);

    delete head;
    delete head_second;
    delete list;

    return 0;
    
}


