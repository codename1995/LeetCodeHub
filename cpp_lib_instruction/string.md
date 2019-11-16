**头文件**
```cpp{.line-numbers}
#include<string>
```

**常用操作**
```cpp{.line-numbers}
string s;

// 初始化

// 子字符串/substr
string s2 = s.substr(pos, n);   // 返回字符串s中，自pos起，长度为n的子字符串
string s3 = s.substr(pos);      // 自pos起，至s末尾
// 若pos超出s的长度，则返回out_of_range异常

// 比较/compare 相等返回0，s1<s2返回负数，s1>s2返回正数
// 1. s与s2
s.compare(s2)
s.compare(pos1,n1,s2)
s.compare(pos1,n1,s2,pos2,n2)
// 2. s与字符数组cp
s.compare(cp)                   // 比较s与cp指向的以空字符结尾的字符数组
s.compare(pos1,n1,cp)
s.compare(pos1,n1,cp,n2)        // s[pos1:pos1+n1] 与 cp[0:n2]
```