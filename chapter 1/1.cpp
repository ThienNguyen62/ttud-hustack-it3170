/*
Compute the sum of two integers a and b.
Input
Line 1 contains two integers a and b (0 <= a, b <= 10^19)
Ouput
Write the sum of a and b
Example
Input
3 5
Output
8
*/


/*
cho hai số nguyên âm a và b . hãy tính tổng hai số này
input là dòng chứa hai số nguyên a và b cách nhau bằng dấu cách
ouput in ra tổng a+B
10^19 là số 1 có 19 chữ số 0 phía sau đây là số có phạm vi của một số kiểu dữ liệu thông thường
int	Khoảng 2,1 × 10⁹
long long	Khoảng 9,22 × 10¹⁸
unsigned long long	Khoảng 1,84 × 10¹⁹
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long a, b, a1, b1, a2, b2;
    cin >> a >> b;

    a1 = a / 10; // bỏ chữ số cuối lấy phần trên
    b1 = b / 10;

    a2 = a % 10; // lấy chữ số cuối
    b2 = b % 10;

    unsigned long long c1 = a1 + b1 + (a2 + b2) / 10;  // phần dầu kết quả
    unsigned long long c2 = (a2 + b2) % 10; // chữ số cuối của kết quả

    if (c1 > 0)
        cout << c1 << c2;
    else
        cout << c2;

    return 0;
}
// input 9999999999999999997 9999999999999999998
// output 19999999999999999995