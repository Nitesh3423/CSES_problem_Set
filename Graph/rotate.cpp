#include <bits/stdc++.h> 
using namespace std;
// pass by refrence, pass by value
void Reverse(vector<int>& arr, int start , int end){
    while(start<=end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
}
void print(vector<int> array){
    for(auto it:array) cout<<it<<" ";
    cout<<endl;
}

int main()
{
    vector<int> array={1,2,3,4,5,6,7};  //{1,2,3,4,5,6,7} k(3) places=> {4,5,6,7,1,2,3}
                                        //{3,2,1,7,6,5,4}=>{4,5,6,7,1,2,3} 

                                        
    int n=array.size();
    cout<<"Without rotation"<<endl;
    print(array);
    int k=3;
    Reverse(array, 0, k-1); //{3,2,1,4,5,6,7}
    Reverse(array, k, n-1); //{3,2,1,7,6,5,4}
    Reverse(array, 0,n-1); //{4,5,6,7,1,2,3}
    cout<<"with rotation by 3 places"<<endl;
    print(array);
    return 0;
    // k=10 ,n=4
    //   Talent < hardwork < consistency
    // diffrence btw skill and talent
}