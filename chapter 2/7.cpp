/*
Segment Tree Simulation - query Max
Khó
SEGMENT_TREE
Given a sequence of positive integers a[1], a[2], ..., a[n].
Perform a sequence of actions of the following types:
update i v: assign a[i] = v.
get-max i j: return the maximum of a[i], a[i + 1], ..., a[j].

Input
Line 1: contains a positive integer n (1 <= n <= 100000).
Line 2: contains a[1], a[2], ..., a[n] (1 <= a[i] <= 10000).
Line 3: contains a positive integer m (1 <= m <= 100000), the number of actions.
Line i + 3 (i = 1, ..., m): contains an action described above.

Output
Write in each line the result of the corresponding action of type get-max
Example
Input
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Output
4
8
9
20
*/

/*
Đọc dãy n số rồi xử lý m lệnh theo thứ tự, với chỉ số bắt đầu từ 1.
Lệnh update i v gán phần tử thứ i bằng v. Lệnh get-max i j in giá trị
lớn nhất từ vị trí i đến j, tính cả hai đầu đoạn.
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
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
        tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
    }

    int actions;
    std::cin >> actions;
    for (int action = 0; action < actions; ++action) {
        std::string operation;
        int i, value;
        std::cin >> operation >> i >> value;
        if (operation == "update") {
            int node = n + i - 1;
            tree[node] = value;
            for (node /= 2; node > 0; node /= 2) {
                tree[node] = std::max(tree[2 * node], tree[2 * node + 1]);
            }
        } else if (operation == "get-max") {
            int left = n + i - 1;
            int right = n + value;
            int maximum = std::numeric_limits<int>::lowest();
            while (left < right) {
                if (left % 2 == 1) {
                    maximum = std::max(maximum, tree[left++]);
                }
                if (right % 2 == 1) {
                    maximum = std::max(maximum, tree[--right]);
                }
                left /= 2;
                right /= 2;
            }
            std::cout << maximum << '\n';
        }
    }
}
