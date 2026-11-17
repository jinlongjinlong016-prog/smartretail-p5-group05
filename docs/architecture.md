# Architecture – P5 Similar Product Finder

> Bản nháp hoàn thiện trước M2 (26/11). Tên hàm và tên struct phải khớp với `src/main.cpp`.

## 1. Luồng chương trình tổng thể
_(flowchart: đọc tệp → kiểm tra dữ liệu → xử lý → in báo cáo, gồm nhánh tệp không mở được)_

## 2. Hàm lõi
- `similarity(q, c, reasons)`: xem [docs/flowcharts/T06-similarity.md](flowcharts/T06-similarity.md)

## 3. Sơ đồ hàm và dữ liệu
_(cây hàm main gọi; bảng struct)_

## 4. Dữ liệu vào/ra
- Đọc: `products.csv`, `inventory.csv`
- Ghi: tệp CSV của `--export` (Extension)

### Project này KHÔNG làm gì
- Không phân loại cảnh báo tồn kho, không tính đặt hàng (Ranh giới của đề P5).

## 5. Thuật toán
_(bubble/selection sort tự viết, tìm kiếm nhị phân đệ quy theo product_id, vì sao)_
