#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<double,double>> v;
    vector<int> wt = {10,20,30};
    vector<int> val = {60,100,120};
    double capacity = 50;
    
    for(int i=0;i<val.size();i++){
        double ratio;
        ratio = val[i]/wt[i];
        v.push_back({ratio,i});
    }
    sort(v.begin(),v.end());
    double ans;
    for(int i=v.size()-1;i>=0;i--){
        if(wt[v[i].second]<=capacity){
             ans += val[v[i].second];
             capacity -= wt[v[i].second];
        }
        else{
            ans += val[v[i].second] * (capacity/wt[v[i].second]);
        }
    }
    cout << "the total profit is " << ans << endl;

    return 0;
}
