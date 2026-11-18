# SmartRetail P5 – Similar Product Finder

Project cuối kỳ môn **Fundamentals of Programming (C++)** – MiiN-SmartRetail.

## Thành viên

| Họ tên | GitHub | Vai trò |
|---|---|---|
| Gou Jin Long | @jinlongjinlong016-prog | Team leader |
| Nguyễn Tố Châu | @ttochau520 | Thành viên |
| Phạm Quang Linh | @LION-ai1706 | Thành viên |

Giảng viên: @vvvanthe

> Repo public: không ghi MSSV, số điện thoại, ngày sinh.

## Bài toán (đặc tả)

**Input**
- `products.csv`: `product_id,name,category,brand,price,rating` (giá là số nguyên VND, rating có 1 chữ số thập phân)
- `inventory.csv`: `store_id,product_id,stock` (không có dòng tồn kho tại cửa hàng đang xét thì stock = 0)
- Dòng lệnh: `p5 <data_folder> <product_id> [store_id] [K] [max_price] [--brand <brand>] [--export <file.csv>]`
  - Mặc định `store_id = S001`, `K = 3`, không có `max_price` thì không giới hạn giá.

**Xử lý**
1. Lọc trước khi chấm: loại sản phẩm đắt hơn `max_price` (in số sản phẩm bị loại); `--brand` chỉ giữ cùng brand.
2. Điểm tương tự (tối đa 10) với mọi sản phẩm khác: cùng category +4, cùng brand +3, chênh giá < 20% giá sản phẩm truy vấn +2, chênh rating < 0.3 +1.
3. Điều chỉnh tồn kho: stock 0 → −5 (vẫn hiển thị), 1–2 → 0, ≥ 3 → +1. Final = Sim + Adj.
4. Sắp xếp: Final giảm → Sim giảm → rating giảm → product_id tăng.

**Output**
- Bảng đầy đủ (Sim, Stock, Adj, Final), đánh dấu hết hàng.
- Top-K kèm nhãn tồn kho, dòng lý do, cửa hàng khác còn hàng; ghi chú khi sản phẩm giống nhất bị tụt hạng vì hết hàng.
- Bảng BEST SUBSTITUTE BY STORE.

## Build và chạy

```bash
mkdir -p bin
g++ -std=c++17 -Wall -Wextra src/main.cpp -o bin/p5
bin/p5 data/sample P001
bin/p5 data/full P001 S002 3 4000000
bin/p5 data/full P001 S001 3 --brand Nike
```

## Giả định và giới hạn
- Giá lưu bằng `long long`; rating lưu dạng số nguyên "phần mười" (4.7 → 47) để tránh sai số làm tròn.
- So sánh 20% bằng nhân chéo: `|c.price − q.price| * 100 < 20 * q.price`.
- Trùng `product_id` thì giữ dòng đầu tiên.
- _(bổ sung trong quá trình làm)_

## Project KHÔNG làm gì (Ranh giới)
- P5 chỉ đọc tồn kho để xếp hạng. Không phân loại cảnh báo tồn kho, không tính đặt hàng.

## Task assignment table

| ID | Task | Function / file | Assignee | Reviewer | Flowchart | PR |
|---|---|---|---|---|---|---|
| T01 | Repo skeleton + README | `.gitignore`, PR template, `README.md` | Jin Long | Tố Châu | not needed | #1 |
| T02 | Struct + đọc rating | `struct Product`, `struct StockItem`, `toTenths()` | Tố Châu | Quang Linh | yes | |
| T03 | Đọc products.csv | `loadProducts()` | Jin Long | Tố Châu | yes | |
| T04 | Đọc inventory.csv + tra tồn kho | `loadInventory()`, `stockOf()` | Quang Linh | Jin Long | yes | |
| T05 | Tìm sản phẩm (đệ quy) | `sortProductsById()`, `findProduct()` – binary search | Quang Linh | Jin Long | yes | |
| T06 | Điểm tương tự (hàm lõi) | `similarity()` | Tố Châu | Quang Linh | yes | |
| T07 | Điều chỉnh tồn kho | `availabilityAdjustment()`, `availableElsewhere()` | Tố Châu | Quang Linh | yes | |
| T08 | Đọc tham số dòng lệnh | `parseArgs()` (K, max_price, --brand) | Quang Linh | Jin Long | yes | |
| T09 | Xếp hạng | `comesBefore()`, bubble sort, `rankMatches()` | Jin Long | Tố Châu | yes | |
| T10 | In báo cáo | `printReport()` | Quang Linh | Jin Long | yes | |
| T11 | Best substitute by store | `bestSubstituteByStore()` | Jin Long | Tố Châu | yes | |
| T12 | Extension: --export | `exportTopK()` | Jin Long | Quang Linh | yes | |
| T13 | Test case | `tests/test_cases.md`, `tests/run_tests.sh` | Tố Châu | Quang Linh | not needed | |
| T14 | Architecture | `docs/architecture.md` | Quang Linh | Jin Long | not needed | |
| T15 | Slides | `docs/slides.pdf` | Jin Long | Tố Châu | not needed | |

Quy tắc: mỗi thành viên ≥ 2 task code và ≥ 1 task khác; reviewer khác người làm; tiêu đề PR bắt đầu bằng mã task.

## Khai báo AI và nguồn tham khảo

| Công cụ | Dùng cho việc gì | Phần nào |
|---|---|---|
| Claude (Anthropic) | Hỗ trợ dựng khung thư mục và README theo hướng dẫn môn học. Code các task do thành viên tự viết | T01 |

Nguồn tham khảo: đề P5, hướng dẫn nộp bài và hướng dẫn GitHub của môn học.
