#include <bits/stdc++.h>
using namespace std;

int main(){
  set<int> pos;
  int x,n;
  cin>>x>>n;
  int ps[n];
  pos.insert(x), pos.insert(0);
  for(int i=0; i<n; i++){
    int p;
    cin>>p;
    ps[i] = p;
    pos.insert(p);
  }
  int maxRange=0;
  for(auto it=pos.begin(); it!=pos.end(); ++it){
    maxRange = max(*next(it)-*it, maxRange);
  }
  vector<int> ans;
  ans.push_back(maxRange);
  for(int i=n-1; i>=1; i--){
    auto it = pos.find(ps[i]);
    int dist = *next(it)-*prev(it);
    maxRange = max(maxRange, dist);
    ans.push_back(maxRange);
    pos.erase(ps[i]);
  }
  cout<<ans[n-1];
  for(int i=n-2; i>=0; i--){
    cout<<" "<<ans[i];
  }
}
