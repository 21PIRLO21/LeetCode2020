'''
请编码实现一个命令行工具，判定两个指定的字符串是否异构同质；异构同质的定义为：一个字符串的字符重新排列后，能变成另一个字符串。

输入描述:
以空格字符分隔的两个字符串；输入字符串的合法字符集为[a-zA-Z0-9 ]，大小写敏感，无需考虑异常输入场景。

示例：
输入
abc acb

输出
true
'''
# 链接：https://www.nowcoder.com/questionTerminal/e46437833ddc4c5bb79f7af7a1b77abf?orderByHotValue=1&page=1&onlyReference=false

from collections import Counter
 
str1, str2 = input().split(' ')
def Check(str1, str2):
    if len(str1) != len(str2):
        return 'false'
    # c1 = Counter(s1)
    # c2 = Counter(s2)
    # if c1 == c2:
    #     print('true')
    # else:
    #     print('false')
    dic1, dic2 = {}, {}
    for i in str1:
        if i not in dic1:
            dic1[i] = 1
        else:
            dic1[i] += 1
    for j in str2:
        if j not in dic2:
            dic2[j] = 1
        else:
            dic2[j] += 1
    keys = list(dic1.keys())
    for key in keys:
        if key in dic2 and dic1[key] == dic2[key]:
            dic1.pop(key)
            dic2.pop(key)
        else:
            return 'false'
    if dic2:
        return 'false'
    return 'true'

print(Check(str1, str2))