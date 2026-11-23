# Ôn tập C++ — Chương 1

## 1. Cấu trúc chương trình và thư viện chuẩn

~~~cpp
#include <iostream>

int main() {
    std::cout << "Hello" << '\n';
    return 0;
}
~~~

- `#include <...>` đưa khai báo của thư viện vào chương trình. Dùng `<iostream>` cho nhập xuất, `<string>` cho chuỗi, `<vector>` cho mảng động, `<stack>` cho ngăn xếp, `<queue>` cho hàng đợi, `<algorithm>` cho thuật toán, `<set>` cho tập hợp và `<map>` cho ánh xạ.
- `<bits/stdc++.h>` là header tiện dụng của GCC, nằm ngoài chuẩn C++. Các header cụ thể giúp mã dễ biên dịch trên nhiều trình biên dịch.
- `main()` là điểm bắt đầu. `return 0;` báo chương trình kết thúc thành công. Đi đến cuối `main()` cũng có hiệu lực như `return 0;`.
- `std::` chỉ tên thuộc không gian tên của thư viện chuẩn. `using namespace std;` cho phép viết `cin`, `vector` trực tiếp, nhưng có thể gây trùng tên.
- `//` chú thích đến cuối dòng. `/* ... */` chú thích qua nhiều dòng. `{}` bao một khối lệnh, biến khai báo trong khối chỉ có phạm vi trong khối đó.

## 2. Biến, kiểu dữ liệu và toán tử

| Cú pháp | Ý nghĩa |
|---|---|
| `int n = 0;` | Khai báo và khởi tạo số nguyên có dấu. |
| `long long count = 0;` | Số nguyên có dấu, rộng ít nhất 64 bit. |
| `unsigned long long x = 0;` | Số nguyên không âm, rộng ít nhất 64 bit. |
| `char ch = 'A';` | Một ký tự, viết bằng nháy đơn. |
| `std::string text = "ABC";` | Một chuỗi ký tự, literal viết bằng nháy kép. |
| `value = 5;` và `value == 5` | Gán giá trị và kiểm tra bằng nhau. |
| `x != y`, `x < y`, `x <= y`, `x > y`, `x >= y` | So sánh khác, nhỏ hơn, nhỏ hơn hoặc bằng, lớn hơn, lớn hơn hoặc bằng. |
| `!ok`, `a && b`, `a \|\| b` | Phủ định, và, hoặc. |
| `++i` và `i++` | Đều tăng `i` lên 1. Khi dùng trong biểu thức, tiền tố cho giá trị mới, hậu tố cho giá trị cũ. |
| `word += ch;` | Nối ký tự `ch` vào cuối chuỗi. |

Trên hệ thống dùng `int` 32 bit và `long long` 64 bit, giá trị dương lớn nhất lần lượt là `2 147 483 647`, `9 223 372 036 854 775 807` và `18 446 744 073 709 551 615` cho `int`, `long long` và `unsigned long long`. Có thể xem giới hạn của hệ thống bằng `std::numeric_limits<T>::max()` trong `<limits>`. Biểu thức được tính theo kiểu của các toán hạng, nên gán kết quả vào kiểu rộng hơn sau khi phép tính đã tràn sẽ không khôi phục kết quả. Tràn số nguyên có dấu là hành vi không xác định. Số nguyên không dấu quay vòng theo môđun của kiểu.

### Chia nguyên, chia dư và nhớ chữ số

Với số nguyên không âm, `x / 10` bỏ chữ số cuối, còn `x % 10` lấy chữ số cuối. Ví dụ `127 / 10 == 12` và `127 % 10 == 7`. Phép `/` giữa hai số nguyên cắt phần thập phân về phía 0. Ký hiệu toán học 10¹⁹ là lũy thừa. Trong C++, `^` là XOR theo bit.

Khi mỗi toán hạng có thể tới 10¹⁹ thì từng số vừa kiểu không dấu 64 bit, còn tổng có thể lên tới 2 × 10¹⁹. Có thể cộng theo cột cuối và in hai phần nối tiếp.

~~~cpp
unsigned long long lastSum = a % 10 + b % 10;
unsigned long long high = a / 10 + b / 10 + lastSum / 10;
unsigned long long last = lastSum % 10;
if (high > 0) {
    std::cout << high;
}
std::cout << last << '\n';
~~~

`lastSum / 10` là số nhớ, `lastSum % 10` là chữ số cuối của tổng. `high` vẫn nằm trong giới hạn với các toán hạng trên. Bỏ phần `high` khi bằng 0 để tránh in thêm số 0 ở đầu. Ví dụ `127 + 88` cho `lastSum = 15`, `high = 21` và `last = 5`, nên in `215`.

## 3. Nhập xuất và điều khiển luồng

~~~cpp
std::cin >> a >> b;
std::cout << a << ' ' << b << '\n';
~~~

- `>>` đọc theo kiểu của biến đích và thường bỏ qua khoảng trắng trước dữ liệu. Khi đọc vào `std::string`, nó đọc một token đến khoảng trắng tiếp theo.
- `std::cin.get(ch)` đọc đúng một ký tự, kể cả dấu cách, tab và xuống dòng. Dùng khi cần tự quyết định ký tự nào phân cách dữ liệu.
- `<<` đưa từng giá trị ra luồng xuất. Hai giá trị được in liên tiếp sẽ dính nhau nếu không chèn dấu cách. `'\n'` xuống dòng. Chuỗi `"NULL"` là văn bản có thể in ra, còn `nullptr` là giá trị con trỏ rỗng.
- Phép đọc trả về tham chiếu đến luồng. Trong điều kiện như `while (std::cin >> cmd)`, luồng được kiểm tra xem phép đọc có hợp lệ hay không. `if (!(std::cin >> n)) { return 0; }` kết thúc sớm nếu không đọc được `n`.
- `std::ios::sync_with_stdio(false);` có thể tăng tốc bằng cách tắt đồng bộ luồng C++ với C stdio. Đặt trước khi nhập xuất và dùng nhất quán `cin`/`cout`. `std::cin.tie(nullptr);` bỏ việc tự đẩy dữ liệu đang chờ của `cout` trước khi đọc.

~~~cpp
std::string cmd;
while (std::cin >> cmd && cmd != "#") {
    if (cmd == "PUSH") {
        int value;
        std::cin >> value;
    } else if (cmd == "POP") {
        // Xử lý thao tác POP.
    }
}
~~~

`while` lặp khi điều kiện đúng. `if`, `else if`, `else` chọn nhánh đầu tiên thỏa điều kiện, hoặc nhánh cuối nếu các điều kiện đều sai. `break;` thoát khỏi vòng lặp gần nhất. `&&` đánh giá từ trái sang phải và dừng khi gặp vế sai. Vì vậy `std::cin >> cmd && cmd != "#" && std::cin >> value` dừng khi đọc lỗi hoặc gặp `#` trước khi đọc `value`. Với `||`, việc đánh giá dừng khi gặp vế đúng.

~~~cpp
for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
}
~~~

Cú pháp `for (khởi_tạo; điều_kiện; cập_nhật)` chạy khởi tạo một lần, kiểm tra điều kiện trước mỗi lượt và cập nhật sau thân vòng lặp. Mẫu trên duyệt các chỉ số từ 0 đến `n - 1`.

## 4. Ngăn xếp và hàng đợi

| Thao tác | `std::stack<int> st;` | `std::queue<int> q;` |
|---|---|---|
| Thứ tự lấy | LIFO, vào sau ra trước | FIFO, vào trước ra trước |
| Thêm | `st.push(v)` vào đỉnh | `q.push(v)` vào cuối |
| Xem phần tử sắp bị lấy | `st.top()` | `q.front()` |
| Xóa phần tử sắp bị lấy | `st.pop()` | `q.pop()` |
| Kiểm tra rỗng | `st.empty()` | `q.empty()` |

Thêm lần lượt `1, 2, 3` thì ngăn xếp lấy `3` trước, hàng đợi lấy `1` trước. `top()` và `front()` cho phép truy cập giá trị. `pop()` chỉ xóa và trả về `void`. Kiểm tra `empty()` trước khi xem hoặc xóa. Các thao tác trong bảng có độ phức tạp O(1) với container mặc định.

~~~cpp
if (st.empty()) {
    std::cout << "NULL\n";
} else {
    std::cout << st.top() << '\n';
    st.pop();
}
~~~

Với hàng đợi, dùng `q.front()` và `q.pop()` theo cùng thứ tự xem rồi xóa.

## 5. Vector, iterator và tìm kiếm nhị phân

- `std::vector<int> a(n);` tạo vector có `n` phần tử kiểu `int` với giá trị ban đầu bằng 0. Kích thước có thể xác định lúc chạy. Vector lưu phần tử liên tiếp và cho phép trùng giá trị.
- `a[i]` truy cập phần tử tại chỉ số `i` trong O(1) và không kiểm tra phạm vi. Với `n` phần tử, chỉ số hợp lệ là `0 ... n - 1`.
- Iterator biểu diễn vị trí khi duyệt container. `a.begin()` là vị trí bắt đầu, `a.end()` là vị trí ngay sau phần tử cuối. Khoảng `[begin, end)` chứa đầu và loại cuối. Vector rỗng có `begin() == end()`.
- `*it` lấy phần tử tại iterator, `++it` tiến sang phần tử kế tiếp. Luôn kiểm tra `it != a.end()` trước khi dùng `*it` với kết quả tìm kiếm.
- `auto it = biểu_thức;` để trình biên dịch suy ra kiểu từ biểu thức khởi tạo. `const auto it = ...;` giữ biến iterator đó cố định.

~~~cpp
std::sort(a.begin(), a.end());
auto lower = std::lower_bound(a.begin(), a.end(), k);
auto upper = std::upper_bound(a.begin(), a.end(), k);

if (upper != a.end()) {
    std::cout << *upper << '\n';
}
~~~

`std::sort` sắp xếp tăng dần mặc định trong O(n log n). Trên dãy đã sắp xếp, `std::lower_bound` tìm phần tử đầu tiên `>= k`, còn `std::upper_bound` tìm phần tử đầu tiên `> k`. Cả hai trả về `end()` nếu không có kết quả. Với vector `{2, 4, 4, 7}` và `k = 4`, kết quả lần lượt trỏ tới số `4` đầu tiên và số `7`.

Tìm kiếm nhị phân thu hẹp vùng cần xét sau mỗi lần so sánh. Trên vector, mỗi truy vấn mất O(log n). Nếu dữ liệu cố định và có nhiều truy vấn, sắp xếp một lần rồi tra cứu tốn O(n log n + q log n) cho `q` truy vấn. Cách duyệt tuyến tính là xét từng số và giữ giá trị nhỏ nhất trong các số thỏa điều kiện, mất O(n) mỗi truy vấn. Có thể dùng `-1` để báo chưa tìm thấy khi đề bảo đảm mọi phần tử đều dương.

## 6. Set và toán tử ba ngôi

~~~cpp
std::set<long long> values;
values.insert(5);
values.insert(5);
values.insert(9);
values.erase(100);
~~~

`std::set<T>` lưu các giá trị duy nhất và duyệt theo thứ tự tăng dần mặc định. Thêm một giá trị đã có giữ nguyên tập. `erase(v)` xóa theo giá trị, trả về số phần tử bị xóa, bằng 0 nếu `v` vắng mặt. Các thao tác `insert(v)`, `erase(v)`, `lower_bound(v)` và `upper_bound(v)` mất O(log m) với `m` là kích thước của tập có từ hai phần tử trở lên. Với tập có thể rỗng, có thể viết O(log(m + 2)).

~~~cpp
const auto it = includeEqual ? values.lower_bound(v) : values.upper_bound(v);
if (it == values.end()) {
    std::cout << "NULL\n";
} else {
    std::cout << *it << '\n';
}
~~~

Mẫu `điều_kiện ? biểu_thức_khi_đúng : biểu_thức_khi_sai` chọn và chỉ tính một trong hai biểu thức. Nếu `includeEqual` đúng, tìm số nhỏ nhất `>= v`. Nếu sai, tìm số nhỏ nhất `> v`. Dùng hàm thành viên của `set` để tra cứu theo cấu trúc của tập trong thời gian logarit.

## 7. Chuỗi, tách từ và map

`std::string` lưu chuỗi có thể thay đổi. `word += ch` thêm ký tự, `word.empty()` kiểm tra chuỗi rỗng và `word.clear()` đưa chuỗi về rỗng.

~~~cpp
std::map<std::string, long long> counts;
std::string word;
char ch;

while (std::cin.get(ch)) {
    const bool isWordChar = (ch >= 'a' && ch <= 'z') ||
                            (ch >= 'A' && ch <= 'Z') ||
                            (ch >= '0' && ch <= '9');
    if (isWordChar) {
        word += ch;
    } else if (!word.empty()) {
        ++counts[word];
        word.clear();
    }
}
if (!word.empty()) {
    ++counts[word];
}
~~~

Các so sánh trên nhận chữ cái và chữ số ASCII. Mỗi ký tự ngoài ba khoảng là một dấu phân cách. Chỉ ghi nhận khi `word` có nội dung để bỏ qua các dấu phân cách liên tiếp. Kiểm tra lần nữa sau vòng lặp để giữ từ cuối nếu dữ liệu kết thúc ngay sau một chữ hoặc số.

- `std::map<Key, Value>` lưu mỗi khóa cùng một giá trị. Ví dụ khóa là từ và giá trị là số lần xuất hiện.
- `counts[word]` trả về tham chiếu đến bộ đếm. Nếu khóa chưa có, toán tử `[]` tạo khóa với giá trị số ban đầu là 0. `++counts[word]` vì thế xử lý được cả lần gặp đầu tiên và các lần sau.
- Map duyệt theo thứ tự khóa. Với khóa là chuỗi, thứ tự từ điển được xác định bằng ký tự khác nhau đầu tiên. Nếu một chuỗi là tiền tố của chuỗi kia, chuỗi ngắn đứng trước. So sánh mặc định phân biệt hoa thường, ví dụ theo ASCII `"2" < "A" < "a" < "ab"`.
- Tra cứu hoặc tạo một khóa cần O(log(d + 2)) phép so sánh khóa, với `d` là số từ khác nhau đang lưu. So sánh hai chuỗi có thể xét nhiều ký tự. Khi độ dài từ bị chặn bởi một hằng số, mỗi lần cập nhật có thể tính là O(log(d + 2)).

~~~cpp
for (const auto& entry : counts) {
    std::cout << entry.first << ' ' << entry.second << '\n';
}
~~~

Đây là vòng lặp theo phạm vi. `entry` đại diện cho cặp đang duyệt, `auto` suy ra kiểu cặp, `&` tạo tham chiếu để tránh sao chép và `const` cho phép đọc qua tham chiếu đó. `entry.first` là khóa và `entry.second` là giá trị. Mỗi cặp được duyệt đúng một lần theo thứ tự khóa.
