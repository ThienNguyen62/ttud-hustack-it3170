/*
CBUS
Khó
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0. 
Input
Line 1 contains n and k (1≤n≤11,1≤k≤10)
 Line i+1 (i=1,2,…,2n+1) contains the (i−1)
th
 line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
Unique line contains the length of the shortest route.
Example
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
    int n, capacity;
    if (!(std::cin >> n >> capacity)) {
        return 0;
    }

    const int pointCount = 2 * n + 1;
    std::vector<std::vector<long long>> distance(pointCount,
                                                 std::vector<long long>(pointCount));
    for (auto& row : distance) {
        for (auto& cost : row) {
            std::cin >> cost;
        }
    }

    std::vector<int> powerOfThree(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        powerOfThree[i + 1] = 3 * powerOfThree[i];
    }
    const int stateCount = powerOfThree[n];
    std::vector<long long> memo(stateCount * pointCount, -1);

    auto minRemaining = [&](auto&& self, int state, int position, int onboard) -> long long {
        if (state == stateCount - 1) {
            return distance[position][0];
        }

        auto& best = memo[state * pointCount + position];
        if (best != -1) {
            return best;
        }
        best = std::numeric_limits<long long>::max();

        // Each ternary digit tracks one passenger: waiting, onboard, or dropped off.
        for (int i = 0, digits = state; i < n; ++i, digits /= 3) {
            const int status = digits % 3;
            const int nextState = state + powerOfThree[i];
            if (status == 0 && onboard < capacity) {
                const int pickup = i + 1;
                best = std::min(best, distance[position][pickup] +
                                          self(self, nextState, pickup, onboard + 1));
            } else if (status == 1) {
                const int dropoff = i + 1 + n;
                best = std::min(best, distance[position][dropoff] +
                                          self(self, nextState, dropoff, onboard - 1));
            }
        }
        return best;
    };

    std::cout << minRemaining(minRemaining, 0, 0, 0) << '\n';
}
