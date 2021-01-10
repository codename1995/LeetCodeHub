[TOC]

# Basic knowledge
## Hanming distance
For two arraies `nums1` and `nums2`, Hanming distance indicates how many elements in these two arraies are different.
Formally, it is the number of indices `i` for `0 <= i <= n-1` where `nums1[i] != nums2[i]`

**Examples:**
```Python
>>> a = [1,2,2]
>>> b = [1,1,2]
>>> HanmingDistance(a,b)
1

>>> a = [1,2,2]
>>> b = [2,1,4]
>>> HanmingDistance(a,b)
3
```
