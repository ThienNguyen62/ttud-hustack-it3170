/*
Simulation over Set - lower bound - upper bound - insert - remove
Trung bình
Given a set S of n integers a1, a2, ..., an. Perform a sequence of operations below:
min_greater_equal v: return a minimum element of S which is greater or equal to v, and return NULL if no such element exists
min_greater v: return a minimum element of S which is greater than v, and return NULL if no such element exists
insert v: insert v into S
remove v: remove v from S

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a1, a2, ..., an (1 <= ai <= 100000)
Each subsequent line contains an operations described above.
The input is terminated with a line containing #

Output
Write the result of each operation min_greater or min_greater_equal.

Example
Input
5
3 2 4 5 9 
min_greater_equal 10
min_greater 7
min_greater_equal 7
min_greater_equal 4
insert 5
insert 5
min_greater 8
min_greater 1
min_greater_equal 6
min_greater_equal 8
#

Output 
NULL
9
9
4
9
2
9
9
*/
/*
Đọc n số nguyên ban đầu để tạo tập hợp S, rồi xử lý các lệnh cho đến khi gặp #.
Với min_greater_equal v, tìm phần tử nhỏ nhất trong S lớn hơn hoặc bằng v.
Với min_greater v, tìm phần tử nhỏ nhất trong S lớn hơn v.
In kết quả của mỗi truy vấn trên một dòng, hoặc NULL nếu không tìm thấy.
Lệnh insert v thêm v vào S và remove v xóa v khỏi S. Hai lệnh này không in kết quả.
*/

#include <iostream>
#include <set>
#include <string>

int main() {
    // tăng tốc nhập suất
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // nhập giá trị
    int n;
    if (!(std::cin >> n)) {
        return 0;
    }
    // khởi tạo tập hợp
    std::set<long long> values;
    long long value;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        values.insert(value);
    }
    // đọc tên thao tác
    std::string operation;
    while (std::cin >> operation && operation != "#" && std::cin >> value) {
        if (operation == "insert") {
            values.insert(value);
        } else if (operation == "remove") {
            values.erase(value);
        } 
        else 
        // phân tích tìm kiếm
        {
            const auto result = operation == "min_greater_equal"
                                    ? values.lower_bound(value)
                                    : values.upper_bound(value);
            if (result == values.end()) {
                std::cout << "NULL\n";
            } else {
                std::cout << *result << '\n';
            }
        }
    }
}

/*
phần phân tích tìm kiếm sử dụng cả toán tử ba ngôi, suy lận auto và lower_bound() và upper_bound của set
cú pháp toán tử 3 ngôi
condition ? expression_if_true : expression_if_false;
nếu là min_greater_equal thì dùng lower_bound ngược lại dùng upper_bound

lower_bound() trả về iterator trỏ tới phần tử đầu tiên lớn hơn hoặc bằng calue
uppper_bound() trả về phần tử đầu tiên lớn hơn hẳn value
auto tự suy luận kiểu dữ liệu dựa vào kiểu thức bên phải
*/

// giải thích pattern
/*
S= {2,3,4,5,9}
min_greater_equal 10: không có số >= 10  NULL
min_greater 7 số nhỏ nhất >7 là 9 -> 9
min_greater_equal 7 số nhỏ nhất >=7 là 9
min_greater_equal 4 là 4
insert 5 5 đã tồn tại không in
min_greater 8 nhỏ nhất >8 là 9
min_greater 1 là 2
min_greater_equal 6 nhỏ nhất >=6 là 9
min_greater_equal 8 là 9
*/