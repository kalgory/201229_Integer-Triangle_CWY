#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> t) {
    int n = t.size();
    for(int i = 1;i<n;i++){
        for(int j = 0;j<t[i].size();j++){
            if(j==0){
                t[i][j] += t[i-1][j];
            }
            else if(j == t[i].size()-1){
                t[i][j] += t[i-1][j-1];
            }
            else{
                t[i][j] += max(t[i-1][j-1], t[i-1][j]);
            }
        }
    }
    return *max_element(t[n-1].begin(), t[n-1].end());
}