/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* dummy = new ListNode(0, head);

    // 指针必须从dummy出发
    ListNode* fast = dummy;
    ListNode* low = dummy;
    for(int i = 0; i< n; i++){
        fast = fast->next;
    }

    while(fast->next != nullptr){   //条件是fast->next != null 而不是fast != null
        fast = fast->next;
        low = low->next;
    }
    low->next = low->next->next;
    return dummy->next;
}

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* ans = removeNthFromEnd(l1, 3);
    for(ListNode* p = ans; p != nullptr; p= p->next){
        cout << p->val << " ";
    }
    return 0;
}
