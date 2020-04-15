#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        for(int x = 0; x < board.size(); ++x){
            for(int y = 0; y < board[0].size(); ++y){
                int live_cnt = 0;
                for(int i = 0; i < 8; ++i){
                    int x_temp = x + dx[i];
                    int y_temp = y + dy[i];
                    if(x_temp >= 0 && x_temp < board.size() && y_temp >= 0 && y_temp < board[0].size())
                        live_cnt += (board[x_temp][y_temp] & 1); // 只累加最低位
                }
                if(board[x][y] == 1){
                    if(live_cnt == 2 || live_cnt == 3)
                        board[x][y] |= 2; // 使用第二个bit标记是否存活
                }
                else{
                    if(live_cnt == 3)
                        board[x][y] |= 2; // 使用第二个bit标记是否存活
                }
            }
        }
        
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                board[i][j] >>= 1; //右移1位，用右起第二个bit覆盖右起第一个bit。
    }
};