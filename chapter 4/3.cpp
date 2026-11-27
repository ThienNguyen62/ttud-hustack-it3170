/*
Max Even SubSequence
Trung bình
Given a sequence of n integers a=a[1], . . ., a[n]. A subsequence of a consists of contiguous elements of a (for example, a[i], a[i+1], . . . ,a[j]). The weight of a subsequence is defined to be the sum of its elements. A subsequence is called even-subsequnce if its weight is even. Find the even-subsequence of a having largest weight.

Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a[1], . . ., a[n] (-10^6 <= a[i] <= 10^6)

Output
The weight of the largest even-subsequence found, or write NOT_FOUND if no solution found.

Example
Input
4
1  2  -3  4
Output
4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const long long inf = numeric_limits<long long>::max();
    array<long long, 2> minPrefix{0, inf};
    long long prefix = 0;
    long long answer = numeric_limits<long long>::lowest();

    for (int i = 0; i < n; ++i) {
        long long value;
        cin >> value;
        prefix += value;
        const int parity = (prefix % 2 != 0);

        // Two prefixes of the same parity delimit an even-sum segment.
        if (minPrefix[parity] != inf) {
            answer = max(answer, prefix - minPrefix[parity]);
        }
        minPrefix[parity] = min(minPrefix[parity], prefix);
    }

    if (answer == numeric_limits<long long>::lowest()) {
        cout << "NOT_FOUND\n";
    } else {
        cout << answer << '\n';
    }
}
