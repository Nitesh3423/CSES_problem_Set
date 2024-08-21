#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
#define          sti                   size_t
 

void solve() {
    ll n;
    cin >> n;
    queue<ll> q;
    for (size_t i = 1; i <= n; i++)
    {
        q.push(i);
    }
    bool flag=false;
    while(!q.empty()){      
        ll element=q.front();
        q.pop();
        if(flag){
            cout<<element<<" ";
        }else{
            q.push(element);
        }
        flag=!flag;
    }
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
