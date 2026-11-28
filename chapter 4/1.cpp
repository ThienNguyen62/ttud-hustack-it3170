/*
Inversion
Khó
Given a sequence of integers a[1], a[2], ..., a[n]. A pair (i, j) is call an inversion if i < j and a[i] > a[j]. Compute the number Q of inversions

Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a[1], a[2], ..., a[n] (0 <= a[i] <= 10^6)

Output
Write the value Q modulo 10^9 + 7

Example
Input
6
3 2 4 5 6 1
Output
6
*/
/* cho mảng a, đếm số cặp (i,j) thỏa mãn i <j và a[i]> a[j]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int maxValue = 1000000; // số lựng phần tử
    const int mod = 1000000007;
    vector<int> fenwick(maxValue + 2);
    long long inversions = 0;

    for (int i = 0; i < n; ++i) {
        // dùng giá trị làm chỉ số
        int value;
        cin >> value;  // tương đương a[i] nếu sử dụng mảng
        const int index = value + 1;  // vì fenwick tree sử dụng vị trí bắt đầu từ 1. trong khi giá trị của đề bài có thể bằng 0

        // Count earlier values <= value. Equal values are not inversions.
        int notGreater = 0;
        for (int p = index; p > 0; p -= p & -p) {
            notGreater += fenwick[p];
        }
        inversions += i - notGreater;

        for (int p = index; p <= maxValue + 1; p += p & -p) {
            ++fenwick[p];
        }
    }

    cout << inversions % mod << '\n';
}


/*
cách tư duy
brute force
long long ans = 0;
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j])
            ans++;
    }
}
    
với mỗi cặp (i,j) chúng có tạo thành nghịch thế không
khi gặp phần tử x,có bao nhiêu phần tử đã xuất hiện trước đó lớn hơn x
từ duy là biến bài toán đếm cặp thành bài toán truy vấn số lượng phần tử đã xuất hiện

Mục tiêu: đếm số cặp i < j và a[i] > a[j].
Duyệt hai vòng for mất \(O(n^2)\) → quá chậm.
Đọc từng phần tử value từ trái sang phải.
i là số phần tử đã đọc trước đó.
Dùng fenwick quản lý tần suất các giá trị đã đọc.
Đếm số phần tử trước đó nhỏ hơn hoặc bằng value (notGreater).
Suy ra số nghịch thế mới: i - notGreater.
Cập nhật fenwick để ghi nhận value vừa xuất hiện.











*/