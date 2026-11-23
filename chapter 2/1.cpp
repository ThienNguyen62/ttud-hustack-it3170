/*
 Simulation prefix sum 1-array
Trung bình
PREFIX_SUM
Given a sequence of integers a
1
, a
2
, . . ., a
n
. Perform a sequence of Q queries q(i,j) that returns the sum of a
i
, a
i+1
, . . ., a
j
.

Input
Line 1: contains a positive integer n (2 <= n <= 100000)
Line 2: contains a
1
, a
2
, ..., a
n
. (1 <= a
i 
<= 1000)
Line 3: contains a positive integer Q (1 <= Q <= 100000)
Line 3 + k (k = 1, 2, ..., Q): contains 2 positive integers i and j (1 <= i < j <= n) of the k
th
 query
 
Output
Write in each line, the result of the corresponding query read from the input

Example
Input
5
5 8 7 1 9 
4
1 2
1 5
1 3
4 5

Output 
13
30
20
10 
*/

/*
Đọc dãy n số và Q truy vấn. Với mỗi cặp chỉ số i, j (đánh số từ 1),
in tổng các phần tử từ i đến j trên một dòng.
*/

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        int value;
        std::cin >> value;
        prefix[i] = prefix[i - 1] + value;
    }

    int queries;
    std::cin >> queries;
    for (int query = 0; query < queries; ++query) {
        int left, right;
        std::cin >> left >> right;
        std::cout << prefix[right] - prefix[left - 1] << '\n';
    }
}
