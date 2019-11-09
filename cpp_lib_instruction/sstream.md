**头文件**
```cpp
#include<sstream>
```
其中常用的类有三种：
```cpp
istringstream is; // 输入流
ostringstream os; // 输出流
stringstream  ss; // 输入输出流
```

由于输入输出流用得比较多，下文以stringstream为例

**常用操作**
```cpp
stringstream ss(string s);  // 初始化
cout << ss;                 // 输出
cin  >> ss;                 // 输入
```

**缺点**
* stringstream 的构造和析构非常花时间

**优点**
* 自动根据空格和换行符对string进行切分

**注意**
如果需要多次转换string，必须在每次转换前使用stream.clear()
```cpp
stringstream ss;
ss.clear();
```
