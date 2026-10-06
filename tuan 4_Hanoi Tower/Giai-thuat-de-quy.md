# GIẢI THUẬT "THÁP HÀ NỘI" SỬ DỤNG ĐỆ QUY

## 1. Mô tả bài toán

Chương trình giải bài toán **Tháp Hà Nội** bằng phương pháp đệ quy.<br>

Có 3 cột:<br>
`A`: cột nguồn<br>
`C`: cột phụ<br>
`B`: cột đích<br>

Ban đầu có `n` đĩa được đặt tại cột nguồn `A`, các đĩa được xếp theo thứ tự từ lớn đến nhỏ từ dưới lên trên.<br>
Mục tiêu là chuyển toàn bộ `n` đĩa từ cột `A` sang cột `B`, sử dụng cột `C` làm cột trung gian.<br>

Các quy tắc:<br>
Mỗi lần chỉ được di chuyển một đĩa.<br>
Chỉ được di chuyển đĩa nằm trên cùng của một cột.<br>
Không được đặt đĩa lớn lên trên đĩa nhỏ.

## 2. Ý tưởng giải thuật

Hàm đệ quy được khai báo:

```c
void sapxep(int n, char nguon, char phu, char dich)
```

Trong đó:<br>
`n`: số đĩa cần chuyển.<br>
`nguon`: cột đang chứa các đĩa cần chuyển.<br>
`phu`: cột được sử dụng làm trung gian.<br>
`dich`: cột cần chuyển các đĩa tới.<br>

Để chuyển `n` đĩa từ cột nguồn sang cột đích, bài toán được chia thành 3 bước:

### Bước 1: Chuyển `n - 1` đĩa từ nguồn sang phụ

```c
sapxep(n - 1, nguon, dich, phu);
```

Lúc này cột đích được sử dụng làm cột trung gian.

### Bước 2: Chuyển đĩa thứ `n` từ nguồn sang đích

```c
printf("Chuyen dia %d tu cot %c sang cot %c\n", n, nguon, dich);
```

Sau khi `n - 1` đĩa phía trên đã được chuyển đi, đĩa thứ `n` có thể được chuyển trực tiếp sang cột đích.

### Bước 3: Chuyển `n - 1` đĩa từ phụ sang đích

```c
sapxep(n - 1, phu, nguon, dich);
```

Lúc này cột nguồn ban đầu được sử dụng làm cột trung gian.<br>
Như vậy, bài toán chuyển `n` đĩa được đưa về hai bài toán nhỏ hơn có cùng dạng là chuyển `n - 1` đĩa.

## 3. Điều kiện dừng

Khi chỉ còn một đĩa:

```c
if (n == 1) {
    printf("Chuyen dia 1 tu cot %c sang cot %c\n", nguon, dich);
    return;
}
```

Đĩa này có thể được chuyển trực tiếp từ cột nguồn sang cột đích.

## 4. Mã giả của giải thuật

```text
sapxep(n, nguồn, phụ, đích):

    Nếu n = 1:
        Chuyển đĩa 1 từ nguồn sang đích
        Kết thúc

    Chuyển n - 1 đĩa từ nguồn sang phụ
        sapxep(n - 1, nguồn, đích, phụ)

    Chuyển đĩa n từ nguồn sang đích

    Chuyển n - 1 đĩa từ phụ sang đích
        sapxep(n - 1, phụ, nguồn, đích)
```

## 5. Lời gọi ban đầu

Trong hàm `main()`:

```c
sapxep(n, 'A', 'C', 'B');
```

Theo thứ tự tham số `nguon - phu - dich`:<br>
`A` là cột nguồn.<br>
`C` là cột phụ.<br>
`B` là cột đích.<br>

Vì vậy chương trình sẽ chuyển toàn bộ `n` đĩa từ `A` sang `B`, sử dụng `C` làm cột trung gian.

## 6. Test case `n = 3`

Lời gọi ban đầu:

```c
sapxep(3, 'A', 'C', 'B');
```

Quá trình thực hiện:

```text
Chuyen dia 1 tu cot A sang cot B
Chuyen dia 2 tu cot A sang cot C
Chuyen dia 1 tu cot B sang cot C
Chuyen dia 3 tu cot A sang cot B
Chuyen dia 1 tu cot C sang cot A
Chuyen dia 2 tu cot C sang cot B
Chuyen dia 1 tu cot A sang cot B
```

Sau khi kết thúc, toàn bộ 3 đĩa đã được chuyển từ cột `A` sang cột `B`.

## 7. Công thức đệ quy

Gọi `T(n)` là số lần di chuyển cần thực hiện để chuyển `n` đĩa.<br>

Để giải bài toán với `n` đĩa, chương trình cần:<br>
Chuyển `n - 1` đĩa lần thứ nhất.<br>
Chuyển đĩa thứ `n` một lần.<br>
Chuyển `n - 1` đĩa lần thứ hai.<br>

Do đó:

```text
T(n) = 2T(n - 1) + 1
```

với:

```text
T(1) = 1
```

Suy ra:

```text
T(n) = 2^n - 1
```

## 8. Độ phức tạp

Số lần di chuyển cần thực hiện là:

```text
2^n - 1
```

Do đó độ phức tạp thời gian là:

```text
O(2^n)
```

Độ sâu tối đa của ngăn xếp đệ quy là `n`, vì vậy độ phức tạp bộ nhớ phụ trợ là:

```text
O(n)
```

## 9. Kết luận

Chương trình sử dụng **đệ quy** để giải bài toán Tháp Hà Nội.<br>

Ý tưởng chính là muốn chuyển `n` đĩa từ cột nguồn sang cột đích thì:

```text
1. Chuyển n - 1 đĩa từ nguồn sang phụ.
2. Chuyển đĩa thứ n từ nguồn sang đích.
3. Chuyển n - 1 đĩa từ phụ sang đích.
```

Mỗi bài toán chuyển `n - 1` đĩa tiếp tục được giải theo cùng một quy tắc cho đến khi chỉ còn một đĩa.<br>
Nhờ đó, bài toán lớn được chia thành các bài toán con có cùng cấu trúc nhưng kích thước nhỏ hơn.
