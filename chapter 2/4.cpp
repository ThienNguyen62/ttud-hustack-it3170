/*
Longest Bounded SubSequence
Khó
TWO_POINTERS
Given a sequence of positive integers a[1], a[2], ..., a[n].
A subsequence here consists of consecutive elements a[i], a[i + 1], ..., a[j]
(1 <= i <= j <= n). Its weight is the sum of its elements.
Given a positive integer Q, find the longest such subsequence with weight
less than or equal to Q.

Input
Line 1: contains two positive integers n and Q (1 <= n <= 10^6, 1 <= Q <= 100000).
Line 2: contains a[1], a[2], ..., a[n] (1 <= a[i] <= 10000).

Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.
Example
Input
10 40
19 2 7 6 9 1 17 19 8 4 
Output
5

*/

/*
Đọc dãy n số nguyên dương và giới hạn Q. In độ dài lớn nhất của đoạn
liên tiếp có tổng không vượt quá Q. In -1 nếu không có đoạn nào thỏa mãn.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, limit;
    std::cin >> n >> limit;
    std::vector<int> values(n);

    int left = 0;
    int sum = 0;
    int best = 0;
    for (int right = 0; right < n; ++right) {
        std::cin >> values[right];
        sum += values[right];
        while (sum > limit) {
            sum -= values[left++];
        }
        best = std::max(best, right - left + 1);
    }
    std::cout << (best == 0 ? -1 : best) << '\n';
}
