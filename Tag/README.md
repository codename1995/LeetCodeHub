# Abstract
A summary for problems with different tag.

[TOC]

# Math

# Data Structure

# Method
## DP

## Hash Table

### Alphabet Hash Table
Here is a typical application for "saving time by space".
Use a simple alphabet hash table so that we can check whether a character exist in string s
or the first/last position of the character in string s.
#### Template

```C++
/* Alphabet Hash Table Template
 *@method 
 *@for 
 *@param
    string s;                // The string
 *@return 
    none
*/

int cnt[26] = {0}; // Initialize the INT array in C++ is very important. Otherwise, the value will be unknown.
// if not only a character but maybe a symbol like '#', '$' , ...
// we can use cnt[256] to cover ASCII
for (auto c : s){
    cnt[c - 'a']++;
}
for (int i=0;i!=s.size();i++){
    if (cnt[s[i] - 'a'])
        balabala...
}
```

#### Problems
387 [First Unique Character in A String](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)
1218 [Longest Arithemetic Subsequence of Given Difference ](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/) (A Special Hast Table)

## Sliding windows
#### Template

```C++
/* Sliding Windows Template
 *@method 
 *@for 
 *@param
    string s;                // The string
 *@return 
    int max_length;          // max substring length
*/

int l = 0, r = 0;
for (;r<s.size();r++){
    if (condition1)         // extand substring
        r++
    else if (condition2)    // shorten substring
        l++
}
```
#### Problems
3 [Longest Substring without Repeating Characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
340 [Longest Substring with At Most two Distinct Characters](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/)


