# Euro Serial Check (C++) 💶

A console program that checks whether a **euro banknote serial number** is valid, using its check digit.
Exercise from a C++ course at **TU Braunschweig**.

## How it works

1. You enter a serial number. Type `fertig` to quit.
2. The program detects the **banknote series** from the format:

| Series | Format | Example |
|---|---|---|
| 2002 (first series) | 1 letter + 11 digits | `S00000000007` |
| 2013 (Europa series) | 2 letters + 10 digits | `SA0000000005` |

3. It **calculates the check digit** (the last digit):
   - Each letter is replaced by its position in the alphabet (A = 1, B = 2, …)
   - The cross sum of the letters and all digits except the last one is taken modulo 9
   - Check digit = 8 − rest (2002 series) or 7 − rest (2013 series). A result of 0 counts as 9, and −1 as 8
4. If the calculated check digit matches the last digit, the serial number is **valid** (`Gueltig`). Otherwise it's **invalid** (`Ungueltig`).

## Example

```
Geben sie eine Seriennummer ein:S00000000007
Gueltig
Geben sie eine Seriennummer ein:SA0000000006
Ungueltig
Geben sie eine Seriennummer ein:12345
Oops Ungueltige Seriennummer
Geben sie eine Seriennummer ein:fertig
```

## Files

| File | Purpose |
|---|---|
| `main.cpp` | Input loop, detects the series with `switch` and prints the result |
| `euroCheck.h` / `euroCheck.cpp` | Series detection and the check-digit calculation for both series |

## Concepts

Header and source files · string processing · ASCII arithmetic · modulo / check digits · `switch` · `do`–`while` loops · CMake

## Build & run

```bash
cmake -S . -B build
cmake --build build
./build/blatt2
```

The console output is in German.
