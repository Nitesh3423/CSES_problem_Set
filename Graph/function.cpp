#include<bits/stdc++.h>
using namespace std;

/*
function:-  return type(wo kya return karega ) , argument/parameters(what value it will take) , working
*/
// calculator
int calcultor(int x , int y , char c ){
    int ans=0;
    if(c=='+'){
        ans=x+y;
    }else if(c=='-'){
        ans=x-y;
    }else if(c=='*'){
        ans=x*y;
    }else if(c=='/'){
        ans=x/y;
    }
    return ans;
}
int main(){
    int x,y;
    char c;
    cin>>x>>y>>c;
    int answer=calcultor(x,y,c);
    cout<<answer<<endl;
    
    return 0;
}