#ifdef _WIN32
#include <windows.h>
#endif

#include<iostream>
using namespace std;

#include<vector>

#ifdef _WIN32
int initConsole()
{
    SetConsoleOutputCP(65001);
    return 0;
}
int _ = initConsole();
#endif

struct ListNode{
    int val; //当前节点的值
    ListNode* next;//指向下一个节点的指针

    //构造函数：可以用以下三种形式构造这个节点
    ListNode() : val(0), next(nullptr) {}; //无参构造
    ListNode(int x) : val(x), next(nullptr) {}; //单参数构造
    ListNode(int x, ListNode* next): val(x), next(next) {}; //双参数构造，包含值和下一个指针
};


//头插入构造链表
ListNode* creat_linked_list(vector<int>& nums){
    ListNode* head = nullptr;
    for(auto& x: nums){
        ListNode* new_node = new ListNode(x);
        new_node->next = head;
        head = new_node;
    }

    return head;
}

//往原有的链表尾部加入节点
ListNode* addnode(ListNode* head, int newval){
    //哨兵节点
    ListNode* dummy = new ListNode(0); //尾部指针指向哨兵节点
    dummy->next = head; //哨兵不动
    ListNode* tail = dummy;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = new ListNode(newval);
    ListNode* res = dummy->next;  //保存头节点
    delete dummy;  //释放哨兵
    return res; //返回头节点
}

//删除指定节点
ListNode* deletenode(ListNode* head, int target){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;
    while(cur->next != nullptr){
        if(cur->next->val == target){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else{
            cur = cur->next;
        }
    }
    return dummy->next;
}

int main(){
    //建链表（尾插）
    ListNode* head = new ListNode(1); //new:在堆内存开辟一块空间，用来存放ListNode结构体，并且将该内存的地址赋值给head
    head->next = new ListNode(2); //head->next即表示ListNode(1)的next指针
    head->next->next = new ListNode(3);
    
    // //建链表（头插）
    // vector<int> nums = {1,2,3};
    // ListNode* head = creat_linked_list(nums);
    
    //遍历链表
    cout << "原链表：";
    for(ListNode* cur = head; cur != nullptr; cur = cur -> next){
        cout << cur->val << " ";
    }
    cout << endl;

    //尾部插入节点
    ListNode* new_head = addnode(head, 4);
    cout << "插入新节点后的链表：";
    for(ListNode* cur = new_head; cur != nullptr; cur = cur -> next){
        cout << cur->val << " ";
    }
    cout << endl;

    //删除链表
    ListNode* new_head2 = deletenode(new_head, 2);
    cout << "删除节点后的链表：";
    for(ListNode* cur = new_head2; cur != nullptr; cur = cur -> next){
        cout << cur->val << " ";
    }
    
    //释放内存
    ListNode* cur = new_head2;
    while(cur != nullptr){
        ListNode* tmp = cur;
        cur = cur -> next;
        delete tmp;
    }

    return 0;
}