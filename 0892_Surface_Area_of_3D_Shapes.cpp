#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* easy */
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int cubes = 0, overlaps = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cubes += grid[i][j];
                // 垂直方向，z方向
                if(grid[i][j] != 0)
                    overlaps += grid[i][j] - 1;
                
                // 水平方向，y方向
                if(j < n - 1)
                    overlaps += min(grid[i][j], grid[i][j + 1]);
                
                // 竖直方向，z方向
                if(i < n - 1)
                    overlaps += min(grid[i][j], grid[i + 1][j]);             
            }
        }
        
        return cubes * 6 - overlaps * 2;
    }
};

/* // 速度最快的答案
class Solution {
public:
int surfaceArea(vector<vector<int>>& grid) {
	int i, j, ans = 0;
	for (i = 0; i < grid.size(); i++) {
		for (j = 0; j < grid.size(); j++) {
			if (grid[i][j] > 0) {
				ans += grid[i][j] * 4 + 2;
				if (i > 0)
					ans -= min(grid[i][j], grid[i - 1][j]) * 2;
				if (j > 0)
					ans -= min(grid[i][j], grid[i][j - 1]) * 2;
			}
		}
	}
	return ans;
}
};
*/