[TOC]

## Basic knowledge
## deep copy
```python
c = [1,1,2]
s = c       # s refer to c, s是c的引用
d = c[::]   # d=copy.deepcopy(c), d是一个新数组，与c有相同的值
e = c[::-1] # e = [2, 1, 1] 将c逆转后深度拷贝给e
```
### Math
#### 'inf'
```python
a = float('inf')
b = float('-inf')
```
### Subfunction
Two method to define a subfunction, especially in Leetcode
```python
# Method 1
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        ...
        #########  definition start  ########### 
        # all var in 'searchRange' and before the 'foo' can be directly used in 'foo'
        def foo(a, b):
            ...
        ##########  definition end  ############ 

        foo(a,b)   # directly use

# Method 2
class Solution:
    #########  definition start  ########### 
    # only var that are sent into 'foo' can be used in 'foo'
    def foo(self, a, b):
        ...
    ##########  definition end  ############ 

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        self.foo(a,b)   # self.foo()!!
        ...
```


## List
### Basic operation
```python{.line-numbers}
aList.append(obj)
aList.clear()
aList.count(obj)        # count the number of 'obj'
aList.copy()            # shallow copy, namely it is just a pointer
aList.extend(sequence)  # similar to 'append()', but append a sequence
aList.index(obj)        # return the index of 'obj', or ValueError
aList.insert(index, obj)# If index>=0, it is same as aList[index:index] = [obj]; otherwise
                        # aList[0:0] = [obj], namely add obj to the start
aList.pop([index])      # delete and return the the index-th element
aList.remove(obj)       # == del aList[aList.index(obj)]
aList.reverse()         # inplace, reverse the list
aList.sort([cmp][,key][,reverse])   # sort the list (stably);

```
## Dict
### Basic operation
```python{.line-numbers}
aDict.clear()
aDict.copy()
aDict.get(key[,default])        # IMPORTANT, if 'key' exists then return it, otherwise return 'default'
aDict.items()
aDict.keys()
aDict.values()
aDict.pop(key[,d])              # delete and return the aDict[key], if key doesn't exist then return d
```
### Other useful operation
#### Sort the dict
```python
sorted(dict) # key, ascending order
sorted(dict.items(), key=lambda kv:(kv[1], kv[0])) # 1. value, 2. key
```
Advanced sort
```python
lis = [
{ "name" : "Taobao" ,    "age" : 100 },  
{ "name" : "Runoob" ,    "age" : 7   }, 
{ "name" : "Google" ,    "age" : 100 }, 
{ "name" : "Wiki"   ,    "age" : 200 }
] 
  
# 'age', ascending
print (sorted(lis, key = lambda i: i['age']) )
  
print ("\r") 
  
# 'age' & 'name', ascending
print (sorted(lis, key = lambda i: (i['age'], i['name'])) )

# 'age', descending
print (sorted(lis, key = lambda i: i['age'], reverse=True) )
```
```python
# results

[{'name': 'Runoob', 'age': 7}, {'name': 'Taobao', 'age': 100}, {'name': 'Google', 'age': 100}, {'name': 'Wiki', 'age': 200}]

[{'name': 'Runoob', 'age': 7}, {'name': 'Google', 'age': 100}, {'name': 'Taobao', 'age': 100}, {'name': 'Wiki', 'age': 200}]

[{'name': 'Wiki', 'age': 200}, {'name': 'Taobao', 'age': 100}, {'name': 'Google', 'age': 100}, {'name': 'Runoob', 'age': 7}]
```

#### Traverse the dict
Key
``` for key in d: ``` **or** ``` for v in d: ```

Value
``` for v in d.values(): ```

Key+Value
```python{.line-numbers}
# 1
for k, v in d.items():
    ...

# 2
for k in d:
    v = d[k]
    ...
```


## Collections
### `collections.Counter(list)` 
**OUTPUT**  a dict `element:count`
**USAGE**   Count how many times an element appears in a list
