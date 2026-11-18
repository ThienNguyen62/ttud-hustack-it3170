/*
Simulation Queue
Trung bình
QUEUE
Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
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
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4
*/

/*Cho một hàng đợi (Queue) ban đầu rỗng, chứa các số nguyên.

Thực hiện lần lượt các lệnh sau:
- PUSH v: Thêm số nguyên v vào cuối hàng đợi.
- POP: Lấy phần tử ở đầu hàng đợi ra và in giá trị đó.
- Nếu hàng đợi rỗng mà gặp lệnh POP, in NULL.
- #: Kết thúc các lệnh (theo ví dụ đề bài).
Yêu cầu: Mỗi lệnh POP phải in kết quả trên một dòng riêng.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    string s;

    while (cin >> s) {
        if (s == "#") {
            break;
        }

        if (s == "PUSH") {
            int v;
            cin >> v;
            q.push(v);
        }
        else if (s == "POP") {
            if (q.empty()) {
                cout << "NULL" << '\n';
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
    }

    return 0;
}
