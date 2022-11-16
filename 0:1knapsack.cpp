#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& val,vector<int>& wt,int capacity,int n,vector<vector<int>>& dp){
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<capacity+1;j++)
        {
          
            if (wt[i-1] <= j) dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][capacity];
}

int main(){
    vector<int> val;
    vector<int> wt;
    int n,capacity;
    cout << "Enter the total number of items: ";
    cin >> n;
    for(int i=0;i<n;i++){
        int num,res;
        cout << "Enter the price of " << i << "th item: ";
        cin >> num;
        cout << "Enter the weight of " << i << "th item: ";
        cin >> res;
        val.push_back(num);
        wt.push_back(res);
    }
    cout << endl;
    cout << "Enter the total capacity of the knapsack: ";
    cin >> capacity;
    cout << endl;
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
    int ans = knapsack(val,wt,capacity,n,dp);
    cout << "Maximum total value in the knapsack is " << ans << endl;
}