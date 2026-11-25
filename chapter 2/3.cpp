/*
Sum pair of sequence equal to a number
Trung bình
TWO_POINTERS
DIVIDE_CONQUER
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. 
Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

/*
Đọc n số nguyên đôi một khác nhau và số nguyên dương M.
In số cặp chỉ số i < j sao cho thỏa mãn đồng thời hai điều kiện
 1<=i<=j<=n
 a[i]+a[j] =M .
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long M;
    cin >> n >> M;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left < right) {
        long long sum = a[left] + a[right];

        if (sum < M) {
            left++;
        }
        else if (sum > M) {
            right--;
        }
        else {
            count++;
            left++;
            right--;
        }
    }

    cout << count << '\n';

    return 0;
}



/*
cách 1 brute force thử tất cả các cặp
vd
a = [5, 2, 1, 4, 3]
M = 6
chọn số đầu rồi cộng thử từng số đứng sau
từ tư duy đó ta có 
int count = 0;

for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (a[i] + a[j] == M) {
            count++;
        }
    }
}
nhược điểm
n phần tử số cặp cần kiểm tra là n(n-1)/2
n =10^6 thì số cặp gần 500 tỷ

tư duy two pointer. sau khi sort thì số nhỏ nhất bên trái, số lớn nhất bên phải
đặt hai con trỏ left và right
nếu tổng không bằng M , phải di chuyển con trỏ nào
TH1 tổng nhỏ hơn M thì ta phải tăng tổng, loại left cũ left ++
TH2 tổng lớn hơn M thì ta phải giảm tổng, loại right cũ, right --
nếu tổng bằng thì di chuyển cả 2 con trỏ tìm cặp khác
left ++
right --
count++*/