/*
Job Selection & Planning
Trung bình
GREEDY
Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished
 before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1.
  It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.

Input
Line 1: contains a positive integer n (1 <= n <= 10^5)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10^5)

Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300
*/
/*
có n công việc, mỗi công việc có deadline: thời hạn và progit : lợi nhuận nếu hoàn thành đúng hạn
mỗi công việc mất đúng 1 đơn vị thời gian
mỗi thời điểm chỉ thực hiện được một công việc
mục tiêu là sắp xếp các công việc sao cho tổng lợi nhuận lớn nhất
j1 deadline 3 profit 10
j2 deadline 2 profit 40
in ra lợi nhuật lớn nhất là 300
*/
#include <bits/stdc++.h>
using namespace std;
// tìm ô trống muộn nhất mà việc này vẫn kịp hạn
int findSlot(vector<int>& parent, int slot) {
    while (parent[slot] != slot) {
        parent[slot] = parent[parent[slot]];
        slot = parent[slot];
    }
    return slot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> jobs(n); // tạo danh sách n phần tử là cặp 2 số nguyên
    for (auto& [profit, deadline] : jobs) {
        cin >> deadline >> profit; // đọc vào theo đề bài
    }
    sort(jobs.rbegin(), jobs.rend());  // so sánh số thứ nhất của cặp trước

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    long long totalProfit = 0;
    for (const auto& [profit, deadline] : jobs) {
        // Use the latest available slot to leave earlier slots free.
        const int slot = findSlot(parent, min(n, deadline));
        if (slot > 0) {
            totalProfit += profit;
            parent[slot] = findSlot(parent, slot - 1);
        }
    }

    cout << totalProfit << '\n';
}
/*
hình dung bạn có một dãy ô lịch, đánh số 1,2,3.... mỗi việc chiếm đúng một ô, nếu việc có hạn chốt là 3
bạn có thể làm ở ô 1,2,hoặc 3 . làm xong thì nhận tiền, còn bỏ qua thì nhận 0
ưu tiên công việc lợi nhuận cao
ta xét những profit lớn nhất trước
1. Tự nghĩ ra cách xếp lịch
Giả sử có hai việc:
Việc	Hạn chót	Tiền nhận được
A	2	100
B	1	80


Bạn muốn giữ việc A vì nó trả nhiều tiền hơn. Nhưng đặt A vào ô nào?
- Đặt A ở ô 1 thì B hết chỗ. Bạn kiếm được 100.
- Đặt A ở ô 2 thì B vẫn làm được ở ô 1. Bạn kiếm được 180.
Từ ví dụ này, ta có hai quyết định trong lời giải:
1. Xét việc trả nhiều tiền trước.
2. Đặt việc đó vào ô trống muộn nhất mà hạn chót cho phép. Như vậy, các ô sớm còn dành được cho những việc có hạn chót gấp hơn.

nếu mọi ô từ 1 đến hạn chót đều đã kính, bỏ qua việc đang xét, đây là cách làm tham làm, xử lý từng việc theo một quy tắc đã chọn

nếu lịch tối ưu đã có A ở một ô sớm hơn, ta có thể chuyển A sang ô s
nếu ô s đang có việc khác, chuyển việc đó về ô cũ của A, làm sớm hơn thì việc đó vẫn kịp hạn
nếu lịch tối ưu chưa có A, ta có thể đặt vào ô s

*/