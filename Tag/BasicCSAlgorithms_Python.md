# Abstract
A collection of basic computer science algorithms.
Best viewed in **VS Code** with the plugin **Markdown Perview Enhanced**.

[TOC]

# Search
## Binary search
Actually, binary search has many variants, namely, 
* find target number 
* find first target number 
* find last target number 
* find last number less/not larger than target number
* find first number larger/not less than target number,
etc.

I just present a basic version and two variants here. Other variants are easy to get based on these versions.
### Basic framework
```Python{.line-numbers}
def binarySearch(nums, target):
    l = 0               # left pointer
    r = len(nums) - 1   # right pointer

    while (...):
        m = (r+l)//2
        if (nums[m] == target):
            ...
        elif (nums[m] < target):
            ...
        elif (nums[m] > target):
            ...
    
    return ...
# NOTICE THAT: it is recommended to use 'm = l + (r+l)//2' to avoid overflow
```

### Find first target number
Find first target number and return its index. 
```python{.line-numbers}
# INPUT:    nums: List[int], target: int
# OUTPUT:   the position of first target number.
def leftBound(nums, target):
    # The eventual 'l' represent the number of elements that less than target
    l = 0
    r = len(nums) # right open interval

    while (l < r):
        m = l + (r-l)//2
        if (nums[m] == target):
            r = m   # tighten the right border
        elif (nums[m] < target):
            l = m + 1
        elif (nums[m] > target):
            r = m
    
    return l        # ix == the number
    # Use following code to return -1 when target does NOT exist
    # if (l==len(nums)): return -1
    # return l if nums[l]==target else -1
```

### Find last target number
Find last target number and return its index. 
```python{.line-numbers}
# INPUT:    nums: List[int], target: int
# OUTPUT:   the position of last target number.
def rightBound(nums, target):
    # The eventual 'l' represent the number of elements that <= target
    l = 0
    r = len(nums) # right open interval

    while (l < r):
        m = l + (r-l)//2
        if (nums[m] == target):
            l = m + 1  # tighten the left border
        elif (nums[m] < target):
            l = m + 1
        elif (nums[m] > target):
            r = m
    
    return l-1         # ix == the number -1
    # Use following code to return -1 when target does NOT exist
    # if (l==0): return -1
    # return l-1 if nums[l-1]==target else -1
    
```



### Problems
34 [Find First and Last Position of Element in Sorted Array](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)