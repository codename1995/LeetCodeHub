[TOC]

## Dict
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
