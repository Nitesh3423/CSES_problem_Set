#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (ll )a.size()
#define          sti                   size_t
 
void calculateLSP(string& pat , int m , vector<int>& lsp){
    int len=0;
    lsp[0]=0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
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
vector<int> Kmp(string& s ,string& pat, int n, int m){
    vector<int> lsp(m);
    calculateLSP(pat , m , lsp);
    int i=0,j=0;
    vector<int> result;
    while((n-i)>=(m-j)){
        if(s[i]==pat[j]){
            i++;
            j++;
        }else if(j==m){
            result.push_back(i-j+1);
            j=lsp[j-1]; 
        }
        else if(i<n and s[i]!=pat[j]){
            if(j!=0){
                j=lsp[j-1];
            }else{
                i++;    
            }
        }
    }
    return result;
}
int kmp(string& s ,string& pat, int n, int m){
    vector<int> lsp(m);
    calculateLSP(pat , m , lsp);
    int i=0,j=0;
    int count=0;
    while((n-i)>=(m-j)){
        if(s[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            count++;
            j=lsp[j-1]; 
        }
        else if(i<n and s[i]!=pat[j]){
            if(j!=0){
                j=lsp[j-1];
            }else{
                i++;    
            }
        }
    }
    return count;
}

void solve() {
    string s;
    cin>>s;
    string pat;
    cin>>pat;
    int n=s.length();
    int m=pat.length();
    int ans=kmp(s , pat , n, m);
    cout<<ans<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
