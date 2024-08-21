#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (ll )a.size()
#define          sti                   size_t
 
void generateLsp(string& s, int n,vector<int>& lsp){
    int len=0;
    lsp[0]=0;
    int i=1;
    while(i<n){
        if(s[len]==s[i]){
            len++;
            lsp[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lsp[len-1];
            }else{
                lsp[i]=0;
                i++;
            }
        }
    }
}

void solve() {
    string s;
    cin>>s;
    //pi table or lsp(n) in kmp , lsp[i] gives longest prefix till index i which is also a sufix
    int n=s.length();
    vector<int> lsp(n);
    generateLsp(s, n,lsp);
    vector<int> ans;
    int j=lsp[n-1];
    while(j>0){
        ans.push_back(j);
        j=lsp[j-1];
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
