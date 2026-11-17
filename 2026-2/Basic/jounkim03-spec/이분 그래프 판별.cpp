#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
   int k;
   cin >> k;
   for(int i = 0; i < k; i++){
      int v,e;
      cin >> v >> e;
      vector<int> adj[v+1];
      for(int j = 0; j < e; j++){
         int u,w;
   	     cin >> u >> w;
         adj[u].push_back(w);
         adj[w].push_back(u);
      }
      int vis[v+1] = {0};
      int col[v+1] = {0};
      int flag = 1;
      for(int s = 1; s <= v; s++){ //비연결 그래프일경우 필요
         if(vis[s]) continue;
   	     queue<int> q;
         q.push(s);
         vis[s] = 1;
         col[s] = 1;
         while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int k = 0; k < adj[cur].size(); k++){
               int nxt = adj[cur][k];
               if(!vis[nxt]){
                  vis[nxt] = 1;
                  q.push(nxt);
                  col[nxt] = -col[cur];
               }
               else{
                  if(col[nxt] == col[cur]){
                     flag = 0;
                  }
               }
            }
         }
      }
      if(flag) cout << "YES\n";
      else cout << "NO\n";
   }
}