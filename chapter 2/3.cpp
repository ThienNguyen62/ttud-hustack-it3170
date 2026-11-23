/*
Sum pair of sequence equal to a number
Trung bình
TWO_POINTERS
DIVIDE_CONQUER
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

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
Đọc n số nguyên đôi một khác nhau và số M.
In số cặp chỉ số i < j sao cho tổng của hai phần tử bằng M.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long target;
    std::cin >> n >> target;
    std::vector<long long> values(n);
    for (auto& value : values) {
        std::cin >> value;
    }
    std::sort(values.begin(), values.end());

    int pairs = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        const long long low = values[left];
        const long long high = values[right];
        // Nếu cả hai đều không dương, tổng không thể bằng M dương.
        if (high <= 0 || low < target - high) {
            ++left;
        } else if (low > target - high) {
            --right;
        } else {
            ++pairs;
            ++left;
            --right;
        }
    }
    std::cout << pairs << '\n';
}
