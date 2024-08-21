#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<string> ans;
void f(string s, int i,string temp){
    if(i==s.length()){
        ans.push_back(temp);
        return;
    }
    temp+=s[i];
    f(s, i+1,temp);
    temp.pop_back();
    f(s,i+1,temp);
}
int main()
{
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    string temp="";
    f(s, 0, temp);
    int n=ans.size();
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        if(ans[i].length()==s.length()){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}