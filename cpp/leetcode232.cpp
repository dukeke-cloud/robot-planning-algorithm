/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
说明：

你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
*/

#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    MyQueue() {}

    void push(int x){
        inStack.push(x);
    }

    int pop(){
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek(){
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty(){
        if(inStack.empty() && outStack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;   // 1
    cout << q.pop() << endl;    // 1
    cout << q.pop() << endl;    // 2
    cout << boolalpha << q.empty() << endl;  // false
    cout << q.pop() << endl;    // 3
    cout << boolalpha << q.empty() << endl;  // true
    return 0;

}