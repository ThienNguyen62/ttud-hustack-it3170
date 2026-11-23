/*
 Range Minimum Query
Khó
Given a sequence of n integers a
0
,. . .,a
n-1
. We denote rmq(i,j) the minimum element of the sequence a
i
, a
i+1
, . . .,a
j
. Given m pairs (i
1
, j
1
),. . .,(i
m
, j
m
), compute the sum Q = rmq(i
1
,j
1
) + . . . + rmq(i
m
, j
m
)
Input
Line 1: n (1 <=  n <= 10
6
)
Line 2: a
0
, . . . ,a
n-1
 ( 1  <=  ai <= 10
6
)
line 3: m (1  <= m <= 10
6
)
Line k+3 (k=1, . . ., m): i
k
, j
k 
 (0  <=  i
k
 < j
k
 < n)
Output
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6
*/

/*
Đọc dãy n số và m truy vấn đoạn [i, j], đánh số từ 0.
Với mỗi truy vấn, lấy giá trị nhỏ nhất trong đoạn. In một số duy nhất
là tổng các giá trị nhỏ nhất của tất cả truy vấn.
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> tree(2 * n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tree[n + i];
    }
    for (int node = n - 1; node > 0; --node) {
        tree[node] = std::min(tree[2 * node], tree[2 * node + 1]);
    }

    int queries;
    std::cin >> queries;
    long long total = 0;
    for (int query = 0; query < queries; ++query) {
        int left, right;
        std::cin >> left >> right;
        left += n;
        right += n + 1;
        int minimum = std::numeric_limits<int>::max();
        while (left < right) {
            if (left % 2 == 1) {
                minimum = std::min(minimum, tree[left++]);
            }
            if (right % 2 == 1) {
                minimum = std::min(minimum, tree[--right]);
            }
            left /= 2;
            right /= 2;
        }
        total += minimum;
    }
    std::cout << total << '\n';
}
