#include<bits/stdc++.h>
using namespace std;
class Dsu{
    
    int nodes,
    vector<int> ranks,
    vector<int> parent
    public:
    Dsu(int n){
        for(int i=0;i<n;i++){
            parent[i]=i+1;
        }
    }
    int find(int i,vector<int> parent){
        if(i==parent[i]){
            return i;
        }
        return parent[i]=find(parent[i],parent); //path compression
    }
    void Union(int x,int y, vector<int> parent,vector<int> rank){
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
};

int main(){

    return 0;
}

