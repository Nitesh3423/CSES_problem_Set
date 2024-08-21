#include <bits/stdc++.h>
using namespace std;



class Solution {
	// works for multiple components
    vector<int> topoSort(vector<vector<int>>& adj , int V){
        vector<int> ans;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
private:
	
public:
	string findOrder(string dict[], int N, int K) {
		vector<vector<int>> adj(K);
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            for(int j=0;j<min(s1.length() , s2.length());j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                }
            }
        }
        vector<int> topo=topoSort(adj, K);
        string ans="";
        for(auto it:topo){
            ans+=char(it+'a');
        }
        return ans;
	}
};

int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}