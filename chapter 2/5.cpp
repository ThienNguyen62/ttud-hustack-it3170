/*
Capacitaed Vehicle Routing
Khó
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
Each client is visited exactly by one route
Total number of packages requested by clients of each truck cannot exceed its capacity
Goal
Find a solution having minimal total travel distance
Note that: 
There might be the case that a truck does not visit any client (empty route)
The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
Input
Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
Line 2: d[1],...,d[n](1≤d[i]≤10)
Line i+3 (i=0,…,n): the i
th
 row of the distance matrix c (1≤c[i,j]≤30)
Output
Minimal total travel distance
Example
Input
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0

Output
70*/

/*
Đọc số khách n, số xe K, tải trọng Q, nhu cầu từng khách và ma trận khoảng cách.
Mỗi xe được dùng phải xuất phát từ kho 0 rồi quay về kho. Mỗi khách được phục vụ
đúng một lần, tổng nhu cầu trên mỗi xe không quá Q và có thể để xe trống.
In tổng quãng đường nhỏ nhất.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, trucks, capacity;
    std::cin >> n >> trucks >> capacity;
    std::vector<int> demand(n);
    for (int& value : demand) {
        std::cin >> value;
    }
    std::vector<std::vector<int>> distance(n + 1, std::vector<int>(n + 1));
    for (auto& row : distance) {
        for (int& value : row) {
            std::cin >> value;
        }
    }

    const int states = 1 << n;
    const int inf = 1000000000;
    std::vector<int> load(states);
    std::vector<int> routeCost(states, inf);
    std::vector<std::vector<int>> path(states, std::vector<int>(n, inf));

    // path[mask][last] là chi phí từ kho qua nhóm khách mask và kết thúc tại last.
    for (int mask = 1; mask < states; ++mask) {
        const int first = __builtin_ctz(static_cast<unsigned>(mask));
        load[mask] = load[mask & (mask - 1)] + demand[first];
        if (load[mask] > capacity) {
            continue;
        }
        for (int last = 0; last < n; ++last) {
            const int bit = 1 << last;
            if ((mask & bit) == 0) {
                continue;
            }
            const int previous = mask ^ bit;
            if (previous == 0) {
                path[mask][last] = distance[0][last + 1];
            } else {
                for (int from = 0; from < n; ++from) {
                    if (previous & (1 << from)) {
                        path[mask][last] = std::min(path[mask][last],
                                                   path[previous][from] + distance[from + 1][last + 1]);
                    }
                }
            }
            routeCost[mask] = std::min(routeCost[mask],
                                       path[mask][last] + distance[last + 1][0]);
        }
    }

    std::vector<int> best(states, inf);
    best[0] = 0;
    for (int used = 0; used < trucks; ++used) {
        std::vector<int> next = best;
        for (int mask = 1; mask < states; ++mask) {
            // Xét tuyến chứa khách có bit thấp nhất để tránh hoán vị các xe.
            const int anchor = mask & -mask;
            const int others = mask ^ anchor;
            for (int subset = others;; subset = (subset - 1) & others) {
                const int route = subset | anchor;
                if (routeCost[route] != inf) {
                    next[mask] = std::min(next[mask], best[mask ^ route] + routeCost[route]);
                }
                if (subset == 0) {
                    break;
                }
            }
        }
        best.swap(next);
    }

    std::cout << (best.back() == inf ? -1 : best.back()) << '\n';
}
