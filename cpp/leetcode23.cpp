/*
leetcode23:合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

#include<iostream>
#include<vector>
#include<queue>
#include <functional>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    //自定义比较器
    auto cmp = [](ListNode* p1, ListNode* p2){
        return p1->val > p2->val;
    };

    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);

    for(ListNode* head : lists){
        if(head->next != nullptr){
            heap.push(head);
        }
    }

    ListNode dummy;
    ListNode* tail;
    tail = &dummy;
    while (
        !heap.empty()
    )
    {
        ListNode* minNode = heap.top();
        heap.pop();
        tail->next = minNode;
        tail = minNode;
        if(minNode->next != nullptr){
            heap.push(minNode->next);
        }
    }
    return dummy.next;
}

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* res = mergeKLists(lists);

    for(ListNode* p =res; p != nullptr; p= p->next){
        cout << p->val << " ";
    }
    cout << endl;

    return 0;
}