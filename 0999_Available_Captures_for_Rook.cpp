#include <ostream>
#include <vector>

using namespace std;

/* easy */
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        int x, y; // 储存白车的坐标
        // int dx[4] = {0, 1, 0, -1};
        // int dy[4] = {1, 0, -1, 0};
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(board[i][j] == 'R'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        for(int i = 0; i < 4; ++i){
            for(int step = 0; ;++step){
                // int tx = x + step * dx[i];
                // int ty = y + step * dx[i];
                int tx = x + step * dx[i];
                int ty = y + step * dy[i];
                // if(board[tx][ty] == 'B' || tx >= 8 || ty >= 8 || tx < 0 || ty < 0)
                // 上面注释中的if语句中的判断条件只是和下面的顺序不同，但就是不能AC，原因未知
                if(tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B')
                    break;
                // if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') break;
                if(board[tx][ty] == 'p'){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};



/* // 不用方向数组的做法
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        int i, j;
        for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
                if(board[x][y] == 'R'){
                    i = x;
                    j = y;
                    break;
                }
            }
        }
        for(int up = i;up >= 0; up--){
            if(board[up][j] == 'p'){
                res ++;
                break;
            }
            if(board[up][j] == 'B'){
                break;
            }
        }
        for(int down = i;down < 8; down++){
            if(board[down][j] == 'p'){
                res ++;
                break;
            }
            if(board[down][j] == 'B'){
                break;
            }
        }
        for(int left = j; left >= 0; left--){
            if(board[i][left] == 'p'){
                res ++;
                break;
            }
            if(board[i][left] == 'B'){
                break;
            }
        }
        for(int right = j; right < 8; right++){
            if(board[i][right] == 'p'){
                res ++;
                break;
            }
            if(board[i][right] == 'B'){
                break;
            }
        }
        return res;
    }
};
*/