#include <iostream>   // 输入输出，对应 Python 的 print
#include <string>     // 字符串，对应 Python 的 str
#include <stack>      // 栈（后进先出），Python 里常用 list 模拟
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(char c : s){
        if (c == '('){
            st.push(')');
        }
        else if(c == '['){
            st.push(']');
        }
        else if(c == '{'){
            st.push('}');
        }
        else{
            //这里必须先判断栈非空，不能在空栈情况下访问栈顶
            if(st.empty() || st.top() != c){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s1 = "()[]{}";
    string s2 = "(]";

    // 三元运算符：条件 ? 真 : 假，对应 Python 的 "true" if 条件 else "false"
    cout << (isValid(s1) ? "true" : "false") << endl;  // 期望 true
    cout << (isValid(s2) ? "true" : "false") << endl;  // 期望 false

    return 0;
}