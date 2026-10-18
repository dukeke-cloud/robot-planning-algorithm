/*
leetcode21.合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。
*/

#include <iostream>
#include <queue>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode dummy; //新建dummy节点 哨兵节点
    ListNode* tail = &dummy; //新建tail指针指向dummy，用来标记链表尾部
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    while(p1 != nullptr and p2 != nullptr){
        if(p1->val >= p2->val){
            tail->next = p2;
            p2 = p2->next;
        }
        else{
            tail->next = p1;
            p1 = p1->next;
        }
        tail = tail->next;
    }
    tail->next = (p1 != nullptr) ? p1 : p2; //将tail的next指向没有遍历完的那个链表
    /*
    实体对象的指针用“.”,表示对象的成员访问, 
    指针变量用“->”，表示指针的成员访问
    */
    return dummy.next;  //哨兵节点的next就指向合并之后的有序链表
}

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* ans = mergeTwoLists(l1, l2);
    for(ListNode* p = ans; p != nullptr; p = p->next){
        cout << p->val << " ";
    }

    return 0;
}