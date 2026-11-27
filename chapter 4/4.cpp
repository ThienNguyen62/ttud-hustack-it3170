/*
Max-Distance Sub-Sequence
Khó
Given N elements (2 ≤ N ≤ 100,000) on a straight line at positions x[1],…, x[N] (0 ≤ x[i] ≤ 1,000,000,000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.

Input
The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases.
Subsequent lines are T test cases with the following format:
Line 1: Two space-separated integers: N and C
Lines 2: contains  x[1], x[2], . . . , x[N]

Output
For each test case output one integer: the distance of the subset found.

Example
input
1
5 3
1 2 8 4 9
output
3

Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
*/

#include <bits/stdc++.h>
using namespace std;

bool canSelect(const vector<long long>& positions, int required, long long gap) {
    int selected = 1;
    long long last = positions.front();
    for (size_t i = 1; i < positions.size() && selected < required; ++i) {
        if (positions[i] - last >= gap) {
            last = positions[i];
            ++selected;
        }
    }
    return selected >= required;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n, required;
        cin >> n >> required;
        vector<long long> positions(n);
        for (long long& position : positions) {
            cin >> position;
        }
        sort(positions.begin(), positions.end());

        if (required <= 1) {
            cout << 0 << '\n';
            continue;
        }
        long long low = 0;
        long long high = (positions.back() - positions.front()) / (required - 1);
        while (low < high) {
            const long long mid = low + (high - low + 1) / 2;
            if (canSelect(positions, required, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        cout << low << '\n';
    }
}
