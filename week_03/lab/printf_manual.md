# 🧮 Using the Width Sub-Specifier in `printf()` (C)

The **width sub-specifier** in C’s `printf()` function controls the **minimum number of characters** printed for a value.
It’s useful for aligning numbers and text into neat columns, padding with spaces or zeros, or formatting tables.

---

## 🧩 Syntax

```
%[flags][width][.precision][length]specifier
```

* **`width`** → sets the minimum field width (number of printed characters)
* If the output is shorter than the width, it’s padded (by default, with spaces)

---

## 📘 Examples

### 1️⃣ Right-Aligned (Default)

```c
printf("'%5d'\n", 42);
printf("'%5d'\n", 1234);
printf("'%5d'\n", 12345);
```

**Output:**

```
'   42'
' 1234'
'12345'
```

Right-aligned by default — each takes up **5 spaces**.

---

### 2️⃣ Left-Aligned (`-` Flag)

```c
printf("'%-5d'\n", 42);
```

**Output:**

```
'42   '
```

---

### 3️⃣ Floating-Point with Width and Precision

```c
printf("'%8.2f'\n", 3.14159);
```

**Output:**

```
'    3.14'
```

* `8` → total field width
* `.2` → digits after the decimal point

---

### 4️⃣ Zero-Padding (`0` Flag)

```c
printf("'%08d'\n", 42);
```

**Output:**

```
'00000042'
```

---

### 5️⃣ Dynamic Width (`*`)

```c
int w = 6;
printf("'%*d'\n", w, 42);
```

**Output:**

```
'    42'
```

Width comes from the variable `w`.

---

## ✅ Summary Table

| Example                    | Format                   | Output       | Description        |
| -------------------------- | ------------------------ | ------------ | ------------------ |
| `printf("'%5d'", 42);`     | width = 5                | `'   42'`    | Right-aligned      |
| `printf("'%-5d'", 42);`    | width = 5                | `'42   '`    | Left-aligned       |
| `printf("'%08d'", 42);`    | width = 8                | `'00000042'` | Zero-padded        |
| `printf("'%8.2f'", 3.14);` | width = 8, precision = 2 | `'    3.14'` | Float with padding |
| `printf("'%*d'", 6, 42);`  | width = variable         | `'    42'`   | Dynamic width      |

---

### 🧠 Pro Tip

You can combine width and alignment tricks to print clean tables or reports — for example:

```c
printf("%-10s | %5d\n", "Apples", 42);
printf("%-10s | %5d\n", "Oranges", 123);
```

**Output:**

```
Apples     |    42
Oranges    |   123
```
