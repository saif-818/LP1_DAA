#include <bits/stdc++.h> 
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u]!=1e9 && (dist[u] + wt < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist[dest];
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges;
   
    for(int i=0;i<m;i++){
        vector<int> temp;
        int v1,v2,wt;
        cin >> v1 >> v2 >> wt;
        temp.push_back(v1);
        temp.push_back(v2);
        temp.push_back(wt);
        edges.push_back(temp);
    }
    cout << endl;
   
    int src = 0;
    cout << "Vertex\t" << "Distance from source" << endl;
    for(int i=0;i<n;i++){
        int ans;
        ans = bellmonFord(n,m,src,i,edges);
        cout << i << "\t\t" << ans << endl;
    }
}