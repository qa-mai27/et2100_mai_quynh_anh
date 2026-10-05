# GIẢI THUẬT THÁP HÀ NỘI KHÔNG ĐỆ QUY

## 1. Mô tả bài toán

Chương trình giải bài toán **Tháp Hà Nội** bằng phương pháp lặp, không
sử dụng đệ quy.
Quy ước ba cột theo thứ tự:
-`A`: cột nguồn
-`B`: cột đích
-`C`: cột phụ
Ban đầu, toàn bộ `n` đĩa nằm trên cột `A`. Mục tiêu là chuyển toàn bộ
các đĩa từ cột `A` sang cột `B`, sử dụng `C` làm cột trung gian.
Các quy tắc:
-Mỗi lần chỉ được chuyển một đĩa.
-Chỉ được chuyển đĩa nằm trên cùng của một cột.
-Không được đặt đĩa lớn lên trên đĩa nhỏ.

## 2. Mô phỏng các cột
Ba mảng `A`, `B`, `C` được sử dụng để biểu diễn ba cột của Tháp Hà Nội:
``` c
int A[n + 5], B[n + 5], C[n + 5];
```
Các đĩa được đánh trọng số từ `1` đến `n`, tăng dần từ trên xuống dưới.
Đĩa `1` là đĩa nhỏ nhất ở trên cùng, đĩa `n` là đĩa lớn nhất ở dưới
cùng.
Do cách lưu trong mảng, đĩa ở dưới có chỉ số nhỏ hơn. Ví dụ với `n = 4`:

``` text
A[1] = 4
A[2] = 3
A[3] = 2
A[4] = 1
```
Các vị trí không chứa đĩa được gán giá trị `n + 1`. Vì `n + 1` lớn hơn
trọng số của mọi đĩa nên giá trị này được dùng để đánh dấu vị trí trống.

## 3. Khởi tạo
Ban đầu:
``` c
A[0] = B[0] = C[0] = 0;
```
Các vị trí còn lại được gán `n + 1`
``` c
for (int i = 1; i <= n + 1; i++) {
    A[i] = n + 1;
    B[i] = n + 1;
    C[i] = n + 1;
}
```
Sau đó đưa toàn bộ `n` đĩa vào cột nguồn `A`:

``` c
for (int i = 1; i <= n; i++) {
    A[i] = n - i + 1;
}
```
Ví dụ với `n = 3`:
``` text
A: 3 2 1
B: rỗng
C: rỗng
```
## 4. Hàm `findtop()`
``` c
int findtop(int A[], int n)
```
Hàm `findtop()` dùng để tìm vị trí của **đĩa nằm trên cùng** của một
cột.
``` c
int i = 0;
while (i < n && A[i + 1] <= n) {
    i++;
}
return i;
```
Do vị trí trống có giá trị `n + 1`, điều kiện `A[i + 1] <= n` cho biết
vị trí tiếp theo vẫn đang chứa một đĩa.
Giá trị trả về là chỉ số của đĩa trên cùng. Nếu hàm trả về `0` thì cột
đang xét không chứa đĩa nào.

## 5. Hàm `check()`

``` c
int check(int B[], int n)
```

Hàm `check()` kiểm tra xem toàn bộ `n` đĩa đã được chuyển sang cột đích
`B` hay chưa.
Nếu tồn tại vị trí:

``` c
B[i] > n
```
thì vị trí đó vẫn trống, nghĩa là cột `B` chưa chứa đủ `n` đĩa và hàm
trả về `0`.
Nếu tất cả các vị trí từ `B[1]` đến `B[n]` đều chứa đĩa, hàm trả về `1`,
tức là đã xếp xong.

## 6. Hàm `swap()`

``` c
void swap(int X[], int Y[], int n, char tenx, char teny)
```
Hàm `swap()` thực hiện **một lần chuyển đĩa hợp lệ giữa hai cột**.
Đầu tiên, chương trình tìm vị trí đĩa trên cùng của hai cột:
``` c
int a = findtop(X, n);
int b = findtop(Y, n);
```
Sau đó xét các trường hợp:
-Nếu `X` rỗng, chuyển đĩa trên cùng từ `Y` sang `X`.
-Nếu `Y` rỗng, chuyển đĩa trên cùng từ `X` sang `Y`.
-Nếu cả hai cột đều có đĩa, so sánh hai đĩa trên cùng, đĩa có trọng số nhỏ 
hơn được chuyển sang cột có đĩa trên cùng lớn hơn.
Nhờ đó, chương trình luôn thực hiện phép chuyển hợp lệ và không đặt đĩa
lớn lên trên đĩa nhỏ.

Sau khi xác định nguồn và đích:

``` c
nguon[dcNguon] = n + 1;
dich[dcDich + 1] = dia;
```
Vị trí cũ được đánh dấu là trống và đĩa được thêm vào vị trí trên cùng
của cột đích.

## 7. Quy luật di chuyển
Quy luật được rút ra từ quy nạp, có thể chứng minh:
Thứ tự xét các cặp cột phụ thuộc vào `n` là số lẻ hay số chẵn.
### Khi `n` lẻ
Sử dụng hàm:

``` c
chuyenle(A, B, C, n);
```
Thứ tự các cặp cột:

``` text
AB → AC → BC → AB → AC → BC → ...
```
Tại mỗi cặp, hàm `swap()` tự xác định chiều chuyển hợp lệ.

### Khi `n` chẵn
Sử dụng hàm:
``` c
chuyenchan(A, B, C, n);
```
Thứ tự các cặp cột:
``` text
AC → AB → BC → AC → AB → BC → ...
```
Tại mỗi cặp, hàm `swap()` tự xác định chiều chuyển hợp lệ.

## 8. Điều kiện kết thúc
Sau mỗi lần chuyển, chương trình gọi:
``` c
check(B, n)
```
Khi `check(B, n) == 1`, cột `B` đã chứa đủ `n` đĩa và quá trình chuyển
kết thúc.

## 9. Mã giả của giải thuật
``` text
Nhập n
Khởi tạo ba cột A, B, C
Đưa toàn bộ n đĩa vào A
B và C ban đầu rỗng

Nếu n lẻ:
    Trong khi B chưa chứa đủ n đĩa:
        Chuyển hợp lệ giữa A và B
        Kiểm tra B
        Chuyển hợp lệ giữa A và C
        Kiểm tra B
        Chuyển hợp lệ giữa B và C
        Kiểm tra B

Nếu n chẵn:
    Trong khi B chưa chứa đủ n đĩa:
        Chuyển hợp lệ giữa A và C
        Kiểm tra B
        Chuyển hợp lệ giữa A và B
        Kiểm tra B
        Chuyển hợp lệ giữa B và C
        Kiểm tra B
```

## 10. Test case `n = 3`
Ban đầu:
``` text
A: 3 2 1
B: rỗng
C: rỗng
```
Vì `n = 3` là số lẻ nên thứ tự xét là:
``` text
AB → AC → BC
```
Các bước:
``` text
Chuyen dia thu 1 tu A sang B
Chuyen dia thu 2 tu A sang C
Chuyen dia thu 1 tu B sang C
Chuyen dia thu 3 tu A sang B
Chuyen dia thu 1 tu C sang A
Chuyen dia thu 2 tu C sang B
Chuyen dia thu 1 tu A sang B
```
Kết quả:
``` text
A: rỗng
B: 3 2 1
C: rỗng
```

## 11. Độ phức tạp
-Bài toán Tháp Hà Nội với `n` đĩa cần tối thiểu:
``` text
2^n - 1
```
lần di chuyển. Vì vậy số bước chuyển tăng theo hàm mũ. Ngoài ra, trong chương 
trình hiện tại, `findtop()` và `check()` đều có thể duyệt qua tối đa `n` phần
tử, nên độ phức tạp có thể được coi là **O(n·2\^n)**.

## 12. Kết luận
Chương trình giải bài toán Tháp Hà Nội theo phương pháp **không đệ
quy**.
**Quy luật chính**:
``` text
n lẻ:   AB → AC → BC
n chẵn: AC → AB → BC
```
-Ba mảng `A`, `B`, `C` được dùng để mô phỏng ba cột. Hàm `findtop()` xác
định đĩa trên cùng của một cột, hàm `swap()` xác định và thực hiện phép
chuyển hợp lệ giữa hai cột, còn hàm `check()` kiểm tra điều kiện hoàn
thành.
-Bằng cách lặp lại thứ tự trên và luôn thực hiện phép chuyển hợp lệ giữa
hai cột, chương trình chuyển toàn bộ đĩa từ cột `A` sang cột `B` mà
không cần sử dụng đệ quy.
