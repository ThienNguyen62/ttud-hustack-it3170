# Chương 2 · Lý thuyết từ 7 bài tập

| Bài | Yêu cầu | Kỹ thuật | Thời gian | Bộ nhớ |
| --- | --- | --- | --- | --- |
| [1.cpp](1.cpp) | Tổng đoạn trong mảng | Tổng tiền tố 1D | `O(n + q)` | `O(n)` |
| [2.cpp](2.cpp) | Tổng hình chữ nhật trong bảng | Tổng tiền tố 2D | `O(nm + q)` | `O(nm)` |
| [3.cpp](3.cpp) | Đếm cặp có tổng bằng `M` | Sắp xếp và hai con trỏ | `O(n log n)` | `O(n)` để lưu mảng |
| [4.cpp](4.cpp) | Đoạn liên tiếp dài nhất có tổng ≤ `Q` | Cửa sổ trượt | `O(n)` | `O(n)` |
| [5.cpp](5.cpp) | Chia khách cho các xe và tối ưu tuyến | Quy hoạch động bitmask | `O(n²·2ⁿ + K·3ⁿ)` | `O(n·2ⁿ)` |
| [6.cpp](6.cpp) | Cộng các giá trị nhỏ nhất của các truy vấn đoạn | Cây đoạn lấy min | `O(n + q log n)` | `O(n)` |
| [7.cpp](7.cpp) | Gán giá trị tại một vị trí và truy vấn max | Cây đoạn lấy max | `O(n + q log n)` | `O(n)` |

Trong bảng, `q` là số truy vấn hoặc thao tác, `m` là số cột ở bài 2 và `K` là số xe ở bài 5.

## 1. Tổng tiền tố một chiều

Khi mảng cố định và có nhiều truy vấn tổng đoạn, lưu `P[i]` là tổng các phần tử từ vị trí 1 đến `i`. Với chỉ số bắt đầu từ 1, thêm `P[0] = 0`.

```text
P[i] = P[i - 1] + a[i]
sum(l, r) = P[r] - P[l - 1]
```

Trừ `P[l - 1]` để bỏ các phần tử đứng trước `l` và giữ cả hai đầu đoạn. Chẳng hạn, với `[5, 8, 7, 1, 9]`, tổng đoạn `[3, 5]` là `30 - 13 = 17`. Tiền xử lý một lần trong `O(n)`, rồi trả lời mỗi truy vấn trong `O(1)`. Công thức cũng áp dụng khi mảng có số âm.

## 2. Tổng tiền tố hai chiều

`P[r][c]` lưu tổng hình chữ nhật từ `(1, 1)` đến `(r, c)`. Đặt hàng 0 và cột 0 bằng 0 để dùng cùng công thức ở các biên.

```text
P[r][c] = a[r][c] + P[r - 1][c] + P[r][c - 1] - P[r - 1][c - 1]

sum(r1, c1, r2, c2) = P[r2][c2] - P[r1 - 1][c2]
                     - P[r2][c1 - 1] + P[r1 - 1][c1 - 1]
```

Khi xây bảng, vùng giao phía trên bên trái được cộng hai lần nên cần trừ một lần. Khi truy vấn, vùng giao của dải trên và dải trái bị trừ hai lần nên cần cộng lại một lần. Xây bảng mất `O(nm)`, mỗi truy vấn mất `O(1)`. Cả hai bài tổng tiền tố đều dùng `long long` để lưu tổng.

## 3. Hai con trỏ đếm cặp có tổng bằng M

Sắp xếp mảng tăng dần. Đặt `left` và `right` ở hai đầu, duyệt khi `left < right`.

- Nếu tổng nhỏ hơn `M`, tăng `left`. Ghép phần tử bên trái với bất kỳ phần tử nào còn lại cũng cho tổng nhỏ hơn hoặc bằng tổng hiện tại.
- Nếu tổng lớn hơn `M`, giảm `right`. Ghép phần tử bên phải với bất kỳ phần tử nào còn lại cũng cho tổng lớn hơn hoặc bằng tổng hiện tại.
- Nếu tổng bằng `M`, đếm một cặp rồi dịch cả hai đầu. Các giá trị đôi một khác nhau nên mỗi giá trị chỉ có tối đa một giá trị bù.

Sắp xếp mất `O(n log n)`, quét hai con trỏ mất `O(n)). Nếu đề cho phép giá trị trùng và đếm theo cặp chỉ số, cần tính thêm số lần xuất hiện của từng giá trị.

## 4. Cửa sổ trượt tìm đoạn liên tiếp dài nhất

Giữ tổng của cửa sổ `[left, right]`. Mỗi bước thêm `a[right]` vào tổng. Trong khi tổng vượt `Q`, bỏ `a[left]` rồi tăng `left`. Sau đó cập nhật độ dài lớn nhất bằng `right - left + 1`.

Vì các phần tử dương, mở rộng sang phải làm tổng tăng và bỏ phần tử ở đầu làm tổng giảm. Với mỗi `right`, vị trí `left` đầu tiên cho tổng hợp lệ tạo ra đoạn dài nhất kết thúc tại `right`. Quy tắc này có thể bỏ sót nghiệm nếu mảng có số âm. Mỗi phần tử vào cửa sổ một lần và ra tối đa một lần, nên cả vòng quét mất `O(n)`. Nếu mọi cửa sổ hợp lệ đều rỗng, in `-1`.

## 5. Quy hoạch động bitmask cho bài giao hàng

Mỗi tuyến xuất phát từ kho 0 rồi quay về kho. Mỗi khách được phục vụ đúng một lần, tổng nhu cầu trên mỗi tuyến không vượt tải trọng `Q` và có thể dùng ít hơn `K` xe.

**Biểu diễn tập khách.** Bit `i` ứng với khách `i + 1` trong ma trận khoảng cách. Kiểm tra khách có thuộc tập bằng `mask & (1 << i)`. Bỏ một bit đang bật bằng XOR. Biểu thức `mask & (mask - 1)` xóa bit bật thấp nhất, giúp tính tải của tập từ tải của một tập nhỏ hơn và nhu cầu của khách vừa bỏ.

**Tính tuyến tối ưu cho một xe.** Bỏ qua các tập vượt tải. Gọi `path[S][v]` là chi phí nhỏ nhất để đi từ kho, thăm đúng tập `S` rồi dừng ở khách `v`. Với tập chỉ chứa `v`, chi phí là `c[0][v]`. Với tập lớn hơn, thử mọi khách `u` đứng ngay trước `v`.

```text
path[S][v] = min(path[S bỏ v][u] + c[u][v]) với u thuộc S bỏ v
routeCost[S] = min(path[S][v] + c[v][0]) với v thuộc S
```

Đây là quy hoạch động kiểu Held–Karp, mất `O(n²·2ⁿ)` thời gian. `routeCost[S]` đã tính cả đường về kho. Giữ nguyên chiều của từng cạnh vì chi phí từ `u` đến `v` có thể khác chiều ngược lại.

**Chia tập khách thành các tuyến.** Gọi `best[k][S]` là chi phí nhỏ nhất để phục vụ tập `S` bằng tối đa `k` xe. Khởi tạo `best[0][∅] = 0`, các tập khác có chi phí vô cực.

```text
best[k][S] = min(best[k - 1][S],
                 best[k - 1][S bỏ T] + routeCost[T])
```

Xét các tập con khác rỗng `T` đủ tải và chứa khách có bit bật thấp nhất của `S`. Mỗi cách chia hợp lệ đều có đúng một tuyến chứa khách này, nên có thể chọn tuyến đó trước mà vẫn xét đủ các cách chia. Hạng `best[k - 1][S]` cho phép để xe trống. Để duyệt tập con của `others`, bắt đầu từ `others`, lặp `subset = (subset - 1) & others` và dừng sau khi xử lý `subset = 0`.

Tổng số cặp tập và tập con là `O(3ⁿ)` vì mỗi khách có ba khả năng: ngoài `S`, thuộc `S` nhưng ngoài `T`, hoặc thuộc `T`. Bước chia tuyến mất `O(K·3ⁿ)`. Mã chỉ giữ hai lớp theo số xe, lấy kết quả ở tập đầy đủ và in `-1` nếu trạng thái đó vẫn vô cực.

## 6–7. Cây đoạn dạng lặp

Cây đoạn lưu giá trị tổng hợp của các nhóm phần tử. Hai bài dùng phép `min` và `max`, đều có tính kết hợp. Mã cấp phát `2n` ô, đặt phần tử vị trí 0-based `i` ở lá `tree[n + i]`. Xây từ nút `n - 1` về nút 1 bằng cách gộp hai con `2p` và `2p + 1`. Cha của nút `p` là `p / 2` (chia nguyên). Xây cây mất `O(n)` và dùng `O(n)` bộ nhớ.

**Truy vấn đoạn.** Đổi đoạn đóng sang đoạn nửa mở `[L, R)` trên tầng lá. Khi `L < R`, nếu `L` lẻ thì lấy nút `L` rồi tăng `L`. Nếu `R` lẻ thì giảm `R` rồi lấy nút đó. Các nút còn lại ghép được thành cặp con cùng cha, nên chia cả hai biên cho 2 để đi lên tầng tiếp theo. Mỗi truy vấn mất `O(log n)`.

| Bài | Chỉ số đầu vào | Đoạn nửa mở trên tầng lá | Giá trị khởi tạo | Kết quả |
| --- | --- | --- | --- | --- |
| [6.cpp](6.cpp) | `[i, j]` từ 0 | `[n + i, n + j + 1)` | `INT_MAX` cho min | Cộng các min và in tổng một lần |
| [7.cpp](7.cpp) | `[i, j]` từ 1 | `[n + i - 1, n + j)` | `INT_MIN` cho max | In max sau mỗi lệnh `get-max` |

Ở bài 6, tổng có thể đạt `10¹²`, nên biến cộng kết quả phải dùng `long long`. Ở bài 7, lệnh `update i v` gán `tree[n + i - 1] = v` rồi tính lại max trên đường từ lá lên gốc. Mỗi lần cập nhật mất `O(log n)` vì chỉ các nút tổ tiên của lá đó bị ảnh hưởng.
