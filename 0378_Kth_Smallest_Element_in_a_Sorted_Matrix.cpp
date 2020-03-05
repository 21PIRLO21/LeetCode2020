#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix.back().back(), mid=0;
        
        /*最外层while循环控制二分查找范围的收缩，使得每次循环都将high-low的值缩小，
        low和high两端向内缩进的选择由内层for循环掌控所得count值与k值比较后决定*/
        while(low != high){// != or < ??? 答：都可以;但是 '<' 语义更明确
            int count = 0;
            mid = low + (high - low) / 2;
            // 计数装置，折半查找不仅可以利用mid大小来判断，也可以用count来判断
            for(int i = 0; i < n; i++){
                // matrix[i]中一定是严格升序？答：不需要
                count += BSearch(matrix[i], mid);
            }   
            // if(count > k) 不对
            if(count >= k)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    
    // 标准 upperbound 模板。查找第一个 > target 的元素的位置。
    // 查找每行中 小于等于(<=)target 的元素个数，也是利用二分查找
    int BSearch(vector<int> &row, int target){
        // high为什么是row.size(),因为>target的元素的个数范围是0~n,共n+1个
        int low = 0, high = row.size();
        // row中一定是严格升序？答：不需要
        while(low < high){ // 能否是 <= ?? 答：不能，否则找不出第一个>target的元素位置；!= 也可以
            int mid = low + (high - low) / 2;
            if(row[mid] > target)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};


// class Solution {
// public:
//     // O(nlogn)
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int lo = matrix[0][0], hi = matrix.back().back();
//         // O(log(max_val - min_val)) = O(1)，32 位整型最多 32 次
//         while (lo < hi) {
//             int mid = lo + (hi - lo >> 1);
//             int count = 0;
//             // O(n)
//             for (int i = 0; i < matrix.size(); ++i) {
//                 // O(logn)
//                 count += search(matrix[i], mid); // <= mid 的元素个数
//             }
//             if (k <= count) {
//                 hi = mid;
//             } else {
//                 lo = mid + 1;
//             }
//         }
//         return lo;
//     }
    
//     // 标准 upperbound 模板。查找第一个 > target 的元素的位置。
//     // 也就是 <= target 的元素的个数。
//     int search(vector<int>& row, int target) {
//         int lo = 0, hi = row.size();
//         while (lo < hi) {
//             int mid = lo + (hi - lo >> 1);
//             if (row[mid] > target) {
//                 hi = mid;
//             } else {
//                 lo = mid + 1;
//             }
//         }
//         return lo;
//     }
// };