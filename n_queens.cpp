#include <bits/stdc++.h>
using namespace std;

bool inbound(int r,int c,int n){
    if(r<0 || c<0 || r>=n || c>=n) return false;
    return true;
}
bool isSafe(int r,int c,vector<string> temp,int n){
    for(int k=0;k<n;k++){
        if(temp[k][c] == 'Q' || temp[r][k] == 'Q') return false;
    }
    for(int k=0;k<n;k++){
        if(inbound(r-k,c-k,n) && temp[r-k][c-k] == 'Q') return false;
        if(inbound(r-k,c+k,n) && temp[r-k][c+k] == 'Q') return false;
        if(inbound(r+k,c+k,n) && temp[r+k][c+k] == 'Q') return false;
        if(inbound(r+k,c-k,n) && temp[r+k][c-k] == 'Q') return false;
    }
    return true;
}
void fnc(vector<vector<string>>& ans,vector<string> temp,int n,int row){
    if(row==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(row,i,temp,n))
        {
            temp[row][i] = 'Q';
            fnc(ans,temp,n,row+1);
            temp[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
  
    vector<vector<string>> ans;
    vector<string> temp(n,"");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i].push_back('.');
        }
    }
    fnc(ans,temp,n,0);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<vector<string>> ans;
    ans = solveNQueens(n);
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        
        for(int j=0;j<ans[i].size();j++){
            string temp = ans[i][j];
            cout << temp << endl;
        }
        cout << endl;
        cout << endl;
    }
}