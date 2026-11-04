/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int value) 将元素 value 推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。


*/
#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

class MinStack{
private:
    stack<int> st;  //主栈
    stack<int> minSt; //辅助栈 minSt 的第 i 层，存的是 st 从栈底到第 i 层这一段的最小值。
public:
    MinStack(){

    }
    void push(int x){
        st.push(x);
        if(!minSt.empty()){
            minSt.push(min(x, minSt.top()));
        }
        else{
            minSt.push(x);
        }
    }
    void pop(){
        st.pop();
        /*
        辅助栈 minSt 的第 i 层，存的是 st 从栈底到第 i 层这一段的最小值。
        当 st的栈顶元素被删除，它对应的那条"最小值记录"也就没用了，必须一起删掉，否则辅助栈会记住一个已经不存在的值。
        */
        minSt.pop();
        
    }
    int top(){
        return st.top();
    }
    int getMin(){
        return minSt.top();
    }

};


int main()
{
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;

    return 0;
}