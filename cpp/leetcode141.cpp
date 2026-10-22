/*
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。
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

bool hasCycle(ListNode *head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }

    return false;    
}

int main(){
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* l2 = new ListNode(1, new ListNode(2, new ListNode(3)));
    l2->next->next->next = l2->next;
    
    // ListNode* l2 = new ListNode(1, new ListNode(2, new ListNode(3, l2->next))); 这里l2还没有被定义赋值，不能使用
    bool ans = hasCycle(l2);
    cout << boolalpha << ans;
    return 0;
}