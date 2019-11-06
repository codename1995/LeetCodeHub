# 

[TOC]

## Math

## Data Structure

## Method
### DP

### Sliding windows
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
// Input Parameter
// Template
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


