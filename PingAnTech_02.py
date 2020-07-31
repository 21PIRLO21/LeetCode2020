'''
请编码实现一个命令行工具，找出指定的2个字符串的最长公共子串。 

输入描述:
命令行工具接收两个字符串参数。输入字符串的合法字符集为[a-zA-Z0-9]，
大小写敏感，无需考虑异常输入场景。

输出描述:
所找到的公共子串；如果存在多个等长的公共子串，则请按字母序排序，依次打印出所有公共子串，每行一个。

示例：
输入
1234567 12893457
输出
345
'''
# 链接：https://www.nowcoder.com/questionTerminal/f0114dbcbf8e4180a4787eb159ee744c?orderByHotValue=1&page=1&onlyReference=false
# 来源：牛客网
'''
方法一
'''
def find_lcsubstr(s1, s2):
    res = [] # 存储所有匹配的子串
    m = [[0 for i in range(len(s2)+1)]
         for j in range(len(s1)+1)]  # 生成0矩阵，为方便后续计算，比字符串长度多了一列
    mmax = 0  # 最长匹配的长度
    p = 0  # 最长匹配对应在s1中的最后一位
    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i] == s2[j]:
                m[i+1][j+1] = m[i][j]+1
                if m[i+1][j+1] > mmax:
                    res = []
                    mmax = m[i+1][j+1]
                    p = i+1
                    res.append(s1[p-mmax:p])
                elif m[i+1][j+1] == mmax:
                    p = i+1
                    res.append(s1[p-mmax:p])
    return res  # 返回结果
 
 
s1, s2 = input().split()
for i in sorted(find_lcsubstr(s1, s2)):
    print(i)


'''
方法二
'''
str1, str2 = input().split(' ')
def find_longest_common_substring(str1, str2):
    '''
    return type: List[str]
    '''
    length = min(len(str1), len(str2))
    # 默认str1 比str2 短
    if len(str2) < len(str1):
        str1, str2 = str2, str1
    ans = []
    for window in range(length - 1, -1, -1):
        left, right = 0, window
        while right < length:
            if str1[left: right + 1] in str2:
                ans.append(str1[left: right + 1])
            left += 1
            right += 1
        if ans:
            break # ans为空终止外循环
    ans.sort()
    return ans
res = find_longest_common_substring(str1, str2)
for s in res:
    print(s)