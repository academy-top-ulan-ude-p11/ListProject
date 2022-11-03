#include "List.h"

std::ostream& operator<<(std::ostream& out, const List& list)
{
    List::Node* nodeCurr{ list.begin };
    while (nodeCurr)
    {
        out << nodeCurr->value << "\n";
        nodeCurr = nodeCurr->next;
    }
    return out;
}

List::Node* List::IndexPtr(int index)
{
    int steps;
    Node* nodePtr;

    if (index < size / 2)
    {
        steps = index;
        nodePtr = begin;
    }
    else
    {
        steps = size - 1 - index;
        nodePtr = end;
    }

    for (int i = 0; i < steps; i++)
    {
        if (index < size / 2)
            nodePtr = nodePtr->next;
        else
            nodePtr = nodePtr->prev;
    }

    return nodePtr;
}

int List::Size()
{
    return size;
}

int& List::At(int index)
{
    return IndexPtr(index)->value;
}

int& List::operator[](int index)
{
    return IndexPtr(index)->value;
}

void List::PushBegin(int value)
{
    Node* nodeNew = new Node();
    nodeNew->value = value;
    nodeNew->prev = nullptr;
    nodeNew->next = begin;

    if (!size)
        end = nodeNew;
    else
        begin->prev = nodeNew;

    begin = nodeNew;
    
    size++;
}

void List::PushEnd(int value)
{
    Node* nodeNew = new Node();
    nodeNew->value = value;
    nodeNew->next = nullptr;
    nodeNew->prev = end;

    if (!size)
        begin = nodeNew;
    else
        end->next = nodeNew;

    end = nodeNew;
    size++;
}

void List::Insert(int index, int value)
{
    if (!index || !size)
    {
        PushBegin(value);
        return;
    }
        
    if (index > size - 1)
    {
        PushEnd(value);
        return;
    }

    
    Node* nodeCurr = IndexPtr(index - 1);

    Node* nodeNew = new Node();
    nodeNew->value = value;
    nodeNew->prev = nodeCurr;
    nodeNew->next = nodeCurr->next;

    nodeCurr->next->prev = nodeNew;
    nodeCurr->next = nodeNew;

    size++;
}

int List::PopBegin()
{
    int value = begin->value;
    Node* nodeDel{ begin };

    begin = begin->next;

    if (size > 1)
        begin->prev = nullptr;
    else
        end = nullptr;

    delete nodeDel;
    size--;
    return value;
}

int List::PopEnd()
{
    int value = end->value;
    Node* nodeDel{ end };

    end = end->prev;

    if (size > 1)
        end->next = nullptr;
    else
        begin = nullptr;

    delete nodeDel;
    size--;
    return value;
}

int List::Remove(int index)
{
    if (index <= 0)
        return PopBegin();
    if (index >= size - 1)
        return PopEnd();

    Node* nodeDel = IndexPtr(index);

    int value = nodeDel->value;
    nodeDel->prev->next = nodeDel->next;
    nodeDel->next->prev = nodeDel->prev;

    delete nodeDel;
    size--;
    return value;
}

int List::Contain(int key)
{
    Node* nodeCurr{ begin };
    int index = -1;

    int nodeIndex{ 0 };
    while (nodeCurr)
    {
        if (nodeCurr->value == key)
        {
            index = nodeIndex;
            break;
        }
        nodeCurr = nodeCurr->next;
        nodeIndex++;
    }

    return index;
}
