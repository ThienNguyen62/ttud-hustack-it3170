/*
Simulation Upper Bound of an element in a sequence
Trung bình
Given a sequence of n positive integers a1, a2, ..., an. Perform a sequence of queries of type:
next k: return the smallest element of the given sequence that is greater than k. Return -1 if no such element is found.

Input
Line 1: contains n (1 <= n <= 100000)
Line 2: contains a1, a2, ..., an (1 <= ai <= 1000000)
Each subsequent line contains a query of format above. The input is terminated with a line containing #

Output
Write in each line the result of the corresponding query.
 
Example
Input
5
4 8 2 3 7 
next 2
next 7
next 9
next 6
next 1
#

Output 
3
8
-1
7
2
*/


/* nhập n và n phần tử của mảng
sắp xếp mảng tăng dần bằng sort()
đọc từng truy vấn next k và tìm phần tử bằng upper_bound()
nếu tìm thấy , in giá trị đó, nếu không tìm thấy in -1
*/

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    vector<int>a(n); // mảng động vector
    for (int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    // sắp xếp tăng dần
    sort(a.begin(),a.end());
    string s;
    while (cin>> s && s!="#")
    {
        int k;
        cin>>k;
        // tìm phần tử đầu tiên lớn hơn k
        auto it = upper_bound(a.begin(),a.end(), k);  // auto gips c++ tự suy ra kiểu dữ liệu biến it
        if (it == a.end())
        {
            cout<<-1<<'\n';
        }
        else{
            cout<< *it<<'\n';
        }
    }
    return 0;
}



// code trong trường hợp ko biết hàm sẵn
/*

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100005];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;

    while (cin >> s && s != "#") {
        int k;
        cin >> k;

        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] > k) {
                if (ans == -1 || a[i] < ans) {
                    ans = a[i];
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

}
*/