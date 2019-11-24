#!/usr/bin/env python
# coding=utf-8
# Python使用的是3.4.3，缩进可以使用tab、4个空格或2个空格，但是只能任选其中一种，不能多种混用


class Solution:
    def suggestedProducts(self, products, searchWord):
        products.sort()

        new_products = []
        res = []
        i = 0
        while (i<len(searchWord)):
            res_updated = False
            for p in products:
                if i<len(p) and searchWord[i] == p[i]:
                    new_products.append(p)
                if (not res_updated) and len(new_products) == 3:
                    res_updated = True
                    res.append(list(tuple(new_products)))
            if (not res_updated):
                res.append(list(tuple(new_products)))
            products = new_products
            new_products = []
            i += 1
        return res

import time
start = time.clock()

nums = ["mobile","mouse","moneypot","monitor","mousepad"]
searchWord = "mouse"
ExpectOutput = [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]

solu = Solution()  # 先对类初始化，才能进行调用
# temp = solu.removeSubfolders(s)
temp = solu.suggestedProducts(nums, searchWord)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)