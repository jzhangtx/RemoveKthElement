// RemoveKthElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

ListNode* RemoveKthElement(ListNode** list, int k)
{
    if (*list == nullptr || k == 0)
        return nullptr;

    ListNode* pNode = *list;
    if (k == 1)
    {
        *list = pNode->next;
        return pNode;
    }

    for (int i = 2; i < k; ++i)
    {
        pNode = pNode->next;
    }
    ListNode* pResult = pNode->next;
    pNode->next = pResult->next;
    pResult->next = nullptr;
    return pResult;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count <= 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "The index of the element to be removed: ";
        int index = -1;
        std::cin >> index;

        ListNode* pNode = RemoveKthElement(&pHead, index);
        delete pNode;

        std::cout << "The list after the " << index << "th element removed: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}
