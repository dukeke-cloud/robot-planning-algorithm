/*
栈是一种先进后出的数据结构
头文件#include<stack>
*/

#include<stack>
using namespace std;

// 一个存int的栈
stack<int> s;

/*核心操作
s.push(x);   //把x压到栈顶
s.pop();     //弹出栈顶
s.top();     //查看栈顶元素
s.empty();   //判断栈是否为空（true/false）
s.size()     //栈里面的元素个数
*/

//遍历栈
/*
while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
}
*/
