#include <bits/stdc++.h>
using namespace std;
ifstream fin("lightson.in");
ofstream fout("lightson.out");

const int MXN = 101;
int n,m;
map<pair<int,int>, vector<pair<int,int>>> lights;
bool on[MXN][MXN];
bool visited[MXN][MXN];
int ans = 0;
const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};

bool adjVis(int x, int y){
  for(int i=0; i<4; i++){
    if(on[x+xd[i]][y+yd[i]] && visited[x+xd[i]][y+yd[i]]) return true;
  }
  return false;
}

void ff(int x, int y){
  if(x<0 || x>=n || y<0 || y>=n || !on[x][y] || visited[x][y]) return;
  visited[x][y] = true;
  for(auto elem: lights[{x,y}]){
    on[elem.first][elem.second] = true;
    if(adjVis(elem.first, elem.second)) ff(elem.first, elem.second);
  }
  for(int i=0; i<4; i++){
    ff(x+xd[i],y+yd[i]);
  }
}

int main(){
  fin>>n>>m;
  for(int i=0; i<m; i++){
    int x,y,a,b;
    fin>>x>>y>>a>>b;
    x--, y--, a--,b--;
    lights[{x,y}];
    lights[{x,y}].push_back({a,b});
  }
  for(int i=0; i<=n; i++) for(int j=0; j<=n; j++){ on[i][j] = false; visited[i][j] = false;}
  on[0][0] = true;
  ff(0,0);
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      if(on[i][j]) ans++;
    }
  }
  fout<<ans;
}
