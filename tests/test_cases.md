# Test cases – P5 Similar Product Finder

Cột Input ghi lệnh chạy lại được. Cột Actual chép output thật từ lần chạy cuối (điền ở FINAL).
Cột Expected phải điền đủ trước M3 (30/11).

| ID | Scenario | Input (command) | Expected | Actual | Pass/Fail |
|---|---|---|---|---|---|
| TC01 | Normal: chạy đúng trên sample | `bin/p5 data/sample P001` | Khớp đầu ra mẫu ở mục 6 của đề | | |
| TC02 | Boundary: P040 lệch giá đúng 20%, rating lệch đúng 0.3 so với P001 | `bin/p5 data/full P001` | P040 không có `close price +2` và không có `close rating +1` | | |
| TC03 | Not found / phá hòa: P039 có rating bằng P001; mã không tồn tại | `bin/p5 data/full P001`; `bin/p5 data/full P999` | Thứ tự phá hòa đúng; P999 báo lỗi rõ, không crash | | |
| TC04 | Invalid value: giá âm, thiếu cột, rating 5.6, trùng mã | `bin/p5 data/edge/dirty P001` | Bỏ qua dòng lỗi, cảnh báo ra cerr kèm số dòng | | |
| TC05 | Empty dataset | `bin/p5 data/edge/empty P001` | Báo không tìm thấy P001, không crash | | |
| TC06 | Hết hàng ở cửa hàng này nhưng còn ở cửa hàng khác; không có dòng tồn kho | `bin/p5 data/full P001` | In đúng `in stock at`; không có dòng thì coi stock = 0 | | |
| TC07 | Giá tối đa đúng bằng mức; giá tối đa `abc`; K sai | `bin/p5 data/full P001 S002 3 4000000`; `bin/p5 data/full P001 S001 3 abc`; `bin/p5 data/full P001 S001 0` | Giữ sản phẩm giá đúng bằng mức; in `Excluded ...: 8 products`; tham số sai báo lỗi rõ | | |

> Ghi chú: đề P5 không có phép chia (so sánh 20% dùng nhân chéo). Loại "Chia cho 0" trong hướng dẫn nộp bài tương ứng trường hợp giá sản phẩm truy vấn = 0; nhóm sẽ bổ sung test riêng nếu cần.
