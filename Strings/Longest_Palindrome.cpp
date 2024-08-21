#include "bits/stdc++.h"
using namespace std;

#define ll long long

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pb push_back
#define sz(a) (ll) a.size()
#define sti size_t

void solve()
{
    string s;
    cin>>s;
    string s1=s;
    string ans="";
    reverse(all(s1));
    int n=s.length();
    int t[n+1][n+1];
    ll res=0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 or j==0){
                t[i][j]=0;
            }else if(s[i-1]==s1[j-1]){
                t[i][j]=t[i-1][j-1]+1;
                if(res<t[i][j]){
                    string temp= s.substr(i-t[i][j], t[i][j]);
                    string temp2=temp;
                    reverse(all(temp2));
                    if(temp==temp2){
                        res=t[i][j];
                        ans=temp;
                    }
                }
            }else{
                t[i][j]=0;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
