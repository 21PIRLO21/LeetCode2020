#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Medium */
class Solution_1 {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] + 1;
            for (auto& word: dictionary) {
                if (word.size() <= i + 1) {
                    if (word == sentence.substr(i + 1 - word.size(), word.size()))
                        dp[i + 1] = min(dp[i + 1], dp[i + 1 - word.size()]);
                }
            }
        }
        return dp[n];
    }
};

// the fastest
class Solution_2 {

	int N;
	int dp[1000+7];
	vector<int> pref[1000+7];

public:
    int respace(vector<string>& dictionary, string sentence) 
	{
		if( sentence.size() == 0) return 0;

		N = sentence.size();
        fill(dp, dp+N, 1<<30), dp[0] = 0;
		sentence.insert(sentence.begin(), '\0');

		for( string& str: dictionary)
		{
			int pos = 1;

			while( (pos =sentence.find(str, pos)) > 0)  {
				pref[pos+str.size()-1].push_back(pos);
				pos += str.size();
			}
		}

		for( int i = 1; i <= N; i++)
		{
			dp[i] = dp[i-1] +1;

			if( pref[i].size() == 0) {
				dp[i] = dp[i-1]+1;
				continue;
			}
			
			for( int st: pref[i]) 
				dp[i] = min(dp[i], dp[st-1]);
		}

		return dp[N];
    }
};