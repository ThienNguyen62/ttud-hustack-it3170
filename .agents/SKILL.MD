---
name: giai-bai-cpp
description: Đọc đề lập trình người dùng gửi trong chat, tóm tắt bằng tiếng Việt và viết lời giải C++ vào file người dùng chỉ định.
---

# Giải bài C++ trong file được chỉ định

1. Khi người dùng chỉ định file để giải bài, mở đúng file đó và đọc đề bài trong cuộc trò chuyện. Nếu đề trong file khác đề trong chat, hỏi người dùng cần giải đề nào trước khi sửa file.
2. Giữ nguyên đề bài gốc đã có trong file. Nếu file chưa có đề, chép nguyên văn đề từ chat vào comment khối ở đầu file.
3. Ngay dưới đề bài gốc, đặt một comment riêng dạng `/* ... */` bằng tiếng Việt. Tóm tắt ngắn gọn yêu cầu, định dạng đầu vào và đầu ra, cùng các điều kiện quan trọng. Nếu đã có comment tóm tắt cho bài đó, cập nhật comment hiện tại.
4. Ngay sau comment tóm tắt, viết chương trình C++ hoàn chỉnh. Chọn thuật toán phù hợp với giới hạn đề bài và đọc, in đúng định dạng yêu cầu. Dùng mã hiện có nếu phù hợp. Khi có trình biên dịch, biên dịch và kiểm tra bằng ví dụ trong đề.
