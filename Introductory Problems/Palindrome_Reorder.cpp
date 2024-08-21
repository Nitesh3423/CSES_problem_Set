#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
string isPallindrome(string s ){
    int n= s.length();
    unordered_map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    string ans="";
    int countOdd=0;
    char oddChar;
    for(auto p:m){
        if(p.second%2==1) {
            countOdd++;
            oddChar=p.first;
        }
    }
    if(countOdd>1) return "NO SOLUTION";
    string pallindrome;
    for(auto &p:m){
        if(p.second%2==0){
            pallindrome+=string(p.second/2, p.first);
        }
    }
    string reversePallindrome= pallindrome;
    reverse(reversePallindrome.begin(),reversePallindrome.end());
    if(countOdd==1){
        pallindrome+=oddChar;
    }
    pallindrome+=reversePallindrome;
    return pallindrome;
}
int main()
{
    string s;
    cin>>s;
    string  ans=isPallindrome( s);
    cout<<ans<<endl;
    return 0;
}