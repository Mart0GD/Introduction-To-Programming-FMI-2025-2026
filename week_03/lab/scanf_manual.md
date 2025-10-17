# 🧮 Understanding Whitespace Behavior in `scanf()` (C)

The `scanf()` function in C reads formatted input, but its behavior with **whitespace** can vary depending on the format specifier.
In most cases, it **skips whitespace before reading input**, except for a few special cases.

---

## 🧩 General Rule

`scanf()` automatically **skips spaces, tabs, and newlines** before reading most input types —
but **not** before reading characters (`%c`) or the `%n` specifier.

---

## 📘 Behavior by Specifier

### 1️⃣ Numeric Input (`%d`, `%f`, `%lf`, `%u`, `%x`, etc.)

These specifiers **ignore any leading whitespace** (spaces, tabs, or newlines) and read numbers normally.

```c
int x;
scanf("%d", &x);
```

**Input:**

```
    42
```

**Result:**

```
x = 42
```

✅ Works — all leading whitespace is ignored.

---

### 2️⃣ Character Input (`%c`)

Unlike numeric input, `%c` **does not skip whitespace**.
It reads **exactly the next character**, even if that character is a space, tab, or newline.

```c
char ch;
scanf("%c", &ch);
```

**Input:**

```
 A
```

**Result:**

```
ch = ' '    // space character stored
```

✅ To skip whitespace before reading a character, add a space before `%c` in the format string:

```c
scanf(" %c", &ch); // space before %c tells scanf to skip whitespace
```

---

### 3️⃣ `%n` (Characters Read So Far)

`%n` **does not read any input** and **does not skip whitespace**.
It simply stores the number of characters successfully read so far.

```c
int num, count;
scanf("%d%n", &num, &count);
```

---

## ✅ Summary Table

| Specifier                     | Skips Leading Whitespace? | Stops at Whitespace? | Notes                      |
| ----------------------------- | ------------------------- | -------------------- | -------------------------- |
| `%d`, `%f`, `%lf`, `%u`, `%x` | ✅ Yes                     | ❌ No                 | Numeric input              |
| `%c`                          | ❌ No                      | ❌ No                 | Reads next exact character |
| `%n`                          | ❌ No                      | ❌ N/A                | Counts characters read     |

---

### 🧠 Pro Tips

✅ Add a space before `%c` to skip leftover `'\n'` or spaces
✅ Numeric inputs automatically skip whitespace
✅ Be mindful that `%c` reads *whatever comes next*, including tabs or newlines

---

### 🧪 Example: Common Pitfall

```c
int age;
char initial;

scanf("%d", &age);
scanf("%c", &initial); // reads leftover '\n' from previous input
```

**Fix:**

```c
scanf("%d", &age);
scanf(" %c", &initial); // space before %c skips newline
```
