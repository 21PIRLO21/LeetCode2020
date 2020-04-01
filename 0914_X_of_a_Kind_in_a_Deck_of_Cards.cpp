#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* easy */
// inline int gcd(int a,int b) {
//     return b > 0 ? gcd(b, a % b) : a;
// }

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() <= 1)
            return false;
        
        int counts[10000] = {0};
        // for(int i = 0; i < deck.size(); ++i){
        //     counts[deck[i]] += 1;
        // } // 这么写并不慢
        for(int item : deck)
            ++counts[item];
        int g = counts[0];
        for(int i = 1; i < 10000; ++i){            
            int x = gcd(g, counts[i]);
            if(x == 1) // 不能是 x <= 1
                return false;
            g = counts[i];
        }
        return true;
    }
};


/* // 最快答案
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::ios::sync_with_stdio(false);
        if(deck.size()==1){
            return false;
        }
        int arr[10001]={0};
        for(int item : deck){
            arr[item]++;
        }
        for (int i = 1; i < 10001; i++)
        {
            if(arr[i]!=arr[i-1]&&__gcd(arr[i-1],arr[i])==1){
                return false;
            }
        }
        return true;
    }
};
*/