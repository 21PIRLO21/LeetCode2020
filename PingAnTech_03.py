'''
## 分糖果 ##
n 个小朋友坐在一排，每个小朋友拥有 ai 个糖果，现在你要在他们之间转移糖果，
使得最后所有小朋友拥有的糖果数都相同，每一次，你只能从一个小朋友身上拿走
恰好两个糖果到另一个小朋友上，问最少需要移动多少次可以平分糖果，
如果方案不存在输出 -1。

输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含一个整数n（1 <= n <= 100），
接下来的一行包含n个整数ai（1 <= ai <= 100）。

输出描述:
输出一行表示最少需要移动多少次可以平分，如果方案不存在则输出-1。

示例：
输入
4
7 15 9 5

输出
3
'''

# 链接：https://www.nowcoder.com/questionTerminal/f5279b2047a24c7d97ff6e73bebde3b7?orderByHotValue=1&page=1&onlyReference=false
# 来源：牛客网
n = int(input())
read_list = list(map(int, input().split()))
ava = sum(read_list) / n
count = 0
for num in read_list:
    if ava % 2 != 0 and num % 2 == 0:
        count = -1
        break
    elif ava % 2 == 0 and num % 2 != 0:
        count = -1
        break
    if num > ava: #如果上述条件都不满足，则必存在解
        while num != ava:
            num -= 2
            count += 1
print(count)

'''
1.若糖果不能均分给小朋友，则方案不存在。返回-1
2.将每个小朋友手里的糖果数减去平均值，若存在有单数的情况，则方案不存在。
例如:
若平均值为9颗，即每个小朋友最终手里要有9颗糖，假设小朋友a现在手里有12颗，
减去9颗后，剩3颗，而每次有且只能转移两颗糖，则不存在使得小朋友手里多的糖都转移掉的方案。
返回-1
3.排除不存在的情况后，接下来，只需要将小朋友手里多的（即需要转移出去的）糖果总和/2即可
'''
n = int(input())
s = list(map(int, input().split()))
if sum(s) % n != 0:
    print(-1)
else:
    k = sum(s) / n # k是平均值
    s1=[(c - k) % 2 for c in s]
    if(sum(s1) != 0):
        print(-1)
    else:
        s2 = [c - k for c in s]
        s3 = [c for c in s2 if c > 0] # 取正数，只取负数也一样
        print(int(sum(s3) / 2))