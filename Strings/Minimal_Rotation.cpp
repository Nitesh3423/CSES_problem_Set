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
    string temp=s;
    string s1=s;
    for(size_t i=0;i<s.length();i++){
        temp.push_back(s[i]);
        temp.erase(0,1);       
       if(temp < s1){
        s1=temp;
       }
    }
    cout<<s1<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
