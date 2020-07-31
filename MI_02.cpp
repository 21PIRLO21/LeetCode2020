#include <iostream>
#include<vector>
#include <algorithm>
 
using namespace std;

/*
输入两个整数 n 和 m，从数列 1，2，3.......n 中随意取几个数,使其和等于 m ,
要求将其中所有的可能组合列出来。

输入描述:
每个测试输入包含2个整数, n 和 m

输出描述:
按每个组合的字典序排列输出,每行输出一种组合
*/

/*
思路：获取所有组合，再进行求和，判断是否等于m

实现步骤：
1.获取所有组合
求 1-n 的n个数的组合等价于 求n位二进制数哪几位等于1
即对于 i（i为某个n位二进制数），要知道 i 的哪些位等于1，用一个知道某位上为 1 的数
与 i 相与，若结果为 1，则证明i在该位上为 1，输出对应位数
2.存储组合
本文使用 vector<vector<int>> 存储 ，方便求和
*/

int main() {
    int n,m;
    vector<vector<int>> a;  //存储所有组合
    vector<int> b;    //存储某一个组合
    cin>>n;
    cin>>m;
    int stateCount = 1 << n;  
    for (int i = 0; i < stateCount; ++i)  //对i 循环，目的让 1-n 位从000 .. 000 到 111...111，取值范围
    {
        for (int j = 0; j < n; ++j)    //目的 用于移位，知道移位的大小，从而知道移位后的数哪一位为 1
            if ((1 << j) & i)  //判断 i的 j+1位是否为1
                b.push_back(j + 1);
        if(! b.empty())
        {
            a.push_back(b);
        }
        b.clear();
    }
    sort(a.begin(), a.end());
    for (auto path : a) { // 利用 范围for循环 替代下方 iterator 操作
        int sum = 0;
        for (int i = 0; i < path.size(); ++i) {
            sum += path[i];
        }

        if (sum == m) {
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] << ' ';
            }
            cout << endl;
        }
    }

    // vector<vector<int>>::iterator it1=a.begin();
    // vector<vector<int>>::iterator it2=a.end();
    // for(;it1 !=it2;it1++)
    // {
    //     int sum=0;
    //     for(int i = 0;i<(*it1).size();++i)
    //     {
    //         sum +=(*it1)[i] ;
    //     }
    //     if (sum==m)
    //     {
    //         for(int i = 0;i<(*it1).size();++i)
    //         {
    //             cout<<(*it1)[i]<<' ';
    //         }
    //         cout<<endl;
    //     }
    // }

    return 0;
}