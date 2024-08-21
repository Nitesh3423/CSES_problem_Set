#include<bits/stdc++.h>
using namespace std;

int  main(){
    long long  n,m,k;
    cin>>n>>m>>k;
    vector<long long > desired(n);
    vector<long long > apartments(m);
    for(long long  i=0;i<n;i++){
        cin>>desired[i];
    }
    for(long long  i=0;i<m;i++){
        cin>>apartments[i];
    }
    long long  count=0;
    sort(desired.begin(),desired.end());
    sort(apartments.begin(),apartments.end());
    long long  i=0,j=0;
    while(i<n and j<m){
        if(desired[i] >= apartments[j] - k && desired[i] <= apartments[j] + k){
            count++;
            i++;
            j++;
        }else if(desired[i]<(apartments[j]-k)){
            i++;
        }else{
            j++;
        }
    }
    cout<<count<<endl;
    return 0;
}