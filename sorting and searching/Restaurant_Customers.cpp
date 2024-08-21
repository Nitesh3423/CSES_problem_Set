#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,char>& a , pair<int,char>& b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,char>> events;
    for(int i=0;i<n;i++){
        int arrival,depa;
        cin>>arrival>>depa;
        events.push_back({arrival,'a'});
        events.push_back({depa,'b'});
    }
    sort(events.begin(),events.end(),comp);
    int maxi=0;
    int count=0;
    for(auto p:events){
        if(p.second=='a'){
            count++;
            maxi=max(count,maxi);
        }else{
            count--;
        }
    }
    cout<<maxi<<endl;
    return 0;
}