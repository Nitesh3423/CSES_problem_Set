#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(vector<int>& arr ){
    int n=arr.size();
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]!=arr[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    vector<int> v1 ={1,1,2,2,1,1}; //pallindrome
    vector<int> v2 ={1,3,2,2,1,1};
    bool ans1=isPallindrome(v1);
    bool ans2=isPallindrome(v2);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}