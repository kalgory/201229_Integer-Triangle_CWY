#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> t) {
    deque<deque<int>> dp(2);
    dp[0].assign(t[0].begin(), t[0].end());
    int n = t.size();
    for(int i = 1;i<n;i++){
        dp[0].push_front(0);
        dp[0].push_back(0);
        for(int j = 0;j<t[i].size();j++){
            dp[1].push_back(max(dp[0][j], dp[0][j+1])+t[i][j]);
        }
        dp.pop_front();
        dp.push_back(deque<int>());
    }

    return *max_element(dp[0].begin(), dp[0].end());
}