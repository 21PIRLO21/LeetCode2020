#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

/* medium */
int data[10000] = {0};
int top = 0;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(), 0);
        for(int i = 0, n = seq.size(); i < n; i++) {
            if(seq[i] == '(') {
                ::data[top++] = i;
            } else {
                if(((--top)&1) == 1) {
                    res[i] = 1;
                    res[::data[top]] = 1; 
                }
            }
        }
        return res;
    }
};