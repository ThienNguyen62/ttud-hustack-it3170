/*
 Simulation Stack
Trung bình
STACK
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type 
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5
*/
/*
cho một ngăn xếp ban đầu rỗng, chứa các phần tử số nguyên
thực hiền lần lượt các lệnh 
push v thêm số nguyên v vào đỉnh ngăn xếp
pop lấy phần tử ở đỉnh ngăn xếp ra và in phần tử đó, rỗng thì in null
# kết thúc danh sách lệnh
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    string s;

    while (cin >> s) {
        if (s == "#") {
            break;
        }

        if (s == "PUSH") {
            int v;
            cin >> v;
            st.push(v);
        }
        else if (s == "POP") {
            if (st.empty()) {
                cout << "NULL" << '\n';
            }
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
    }

    return 0;
}
/*
đọc lần lượt từng lệnh, gặp # thì break
gặp push thì đọc thêm số v và gọi push
gặp pop thì kiểm tra có st.empty không, rồi gọi top lấy giá trị đem in, sau đó pop để xóa

thành thạo 4 thao tác push(),top(),pop(),empty()
*/