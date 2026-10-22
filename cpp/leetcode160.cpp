/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* PA = headA;
    ListNode* PB = headB;
    while(PA != PB){
        if(PA != nullptr){
            PA = PA->next;
        }
        else{
            PA = headB;
        } 
        if(PB != nullptr){
            PB = PB->next;
        }
        else{
            PB = headA;
        } 
    }
    return PA;
}

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node5->next = node6;
    node6->next = node7;
    // node7->next = node3;
    ListNode* ans = getIntersectionNode(node1, node5);

    cout << ans->val << endl;
    
    return 0;
}
