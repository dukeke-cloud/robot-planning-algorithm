/*
leetcode206:反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* cur = head;

    while(cur != nullptr){
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* newl = reverseList(l1);
    for(ListNode* p =newl; p != nullptr; p= p->next){
        cout << p->val << " ";
    }
    cout << endl;
    return 0;
}