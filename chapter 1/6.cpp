/*
Word Frequency in Text
Trung bình
Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of 
the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters 
between words. 
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in 
a lexicographic order. 

Example
Input
abc  def abc 
abc abcd def 

Output 
abc 3
abcd 1
def 2
*/
/*
Đọc toàn bộ văn bản đến hết đầu vào. Mỗi từ là một dãy liên tiếp các chữ cái
ASCII hoặc chữ số, dài tối đa 20 ký tự. Các ký tự khác là dấu phân cách.
Phân biệt chữ hoa và chữ thường. In mỗi từ khác nhau và số lần xuất hiện
trên một dòng, cách nhau một dấu cách, theo thứ tự từ điển.
*/

#include <iostream>
#include <map>
#include <string>

int main() {
    // tăng tốc nhập xuất
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // khai báo
    std::map<std::string, long long> frequencies;  
    std::string word;   
    char ch;           
    // dùng cin.get vì đọc cả khoảng trắng
    while (std::cin.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            word += ch;
        } else if (!word.empty()) {
            ++frequencies[word];
            word.clear();
        }
    }
    if (!word.empty()) {
        ++frequencies[word];
    }
    // for (auto it = frequencies.begin();it != frequencies.end();it++)
    for (const auto& entry : frequencies) {
        std::cout << entry.first << ' ' << entry.second << '\n';
    }
}

/*  note
map<string,int> a
string là key là từ cần đếm, int là số lần xuất hiện value
sử dụng map vì cần liên kết mỗi từ với tần xuất xuất hiện của nó
đồng thời in các từ đã sắp xếp

vòng lặp for cuối
auto: là tự xác định kiểu dữ liệu
&: tham chiếu tới phần tử, tránh sao chép
const: không cho phép sửa phần tử qua entry
entry: tên biên đại diện cho phần tử đang duyệt
: có đọc là trong
mỗi phần tử map là một cặp (key,value)
*/

/*
tư duy 
giả sử đề cho
abc,def abc!123
def abc

cần tạo
123 1
abc 3
def 2

b1 tách từ 
b2 đếm số lần
b3 in theo thứ tự
Nếu ký tự là chữ hoặc số:
    Thêm ký tự vào word
Ngược lại:
    Nếu word không rỗng:
        Tăng số lần xuất hiện của word
        Xóa word
*/