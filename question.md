# Problem: Divisible Triangular Sums

## Problem Statement

You are given two integers, **n** and **k**. Define the triangular number \( T(i) \) for any positive integer \( i \) as:

\[
T(i) = 1 + 2 + \dots + i = \frac{i(i+1)}{2}.
\]

Your task is to count how many indices \( i \) (where \( 1 \le i \le n \)) satisfy that \( T(i) \) is divisible by \( k \).

For example, if \( n = 5 \) and \( k = 3 \), the triangular numbers and their divisibility by 3 are:

- \( T(1) = 1 \)   → Not divisible by 3  
- \( T(2) = 3 \)   → **Divisible** by 3  
- \( T(3) = 6 \)   → **Divisible** by 3  
- \( T(4) = 10 \)  → Not divisible by 3  
- \( T(5) = 15 \)  → **Divisible** by 3  

Thus, the answer is **3** because there are 3 indices (2, 3, and 5) where \( T(i) \) is divisible by 3.

## Input Format

- The first line contains an integer \( t \) — the number of test cases.
- Each of the next \( t \) lines contains two space-separated integers, \( n \) and \( k \).

## Output Format

For each test case, output a single line containing the number of indices \( i \) (with \( 1 \le i \le n \)) for which \( T(i) \) is divisible by \( k \).

## Constraints

### Subtask 1 (Basic Tests):
- \( 1 \le t \le 10^4 \)
- \( 1 \le n \le 10^6 \)
- \( 1 \le k \le 10^5 \)

### Subtask 2 (Small Tests):
- \( 1 \le t \le 10^4 \)
- \( 1 \le n \le 10^{12} \)
- \( 1 \le k \le 10^5 \)

### Subtask 3 (Large Tests):
- \( 1 \le t \le 10^4 \)
- \( 1 \le n \le 10^{18} \)
- \( 1 \le k \le 10^5 \)

**Note:** \( k \) is always at least 1.
