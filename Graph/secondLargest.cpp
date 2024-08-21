#include <bits/stdc++.h> 
using namespace std;
void secondLargest(vector<int> arr)
{
    vector<int> array = {1, 2, 4, 7, 7, 5};
    int maxi = INT_MIN;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array[i] > maxi)
        {
            maxi = array[i];
        }
    }
    // second largest
    int maxi2 = INT_MIN;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array[i] > maxi2 and array[i] != maxi)
        {
            maxi2 = array[i];
        }
    }
    cout << maxi2 << endl;
}
vector<int> moveZerosToEnd(vector<int> array , int n){
    vector<int> temp; 
    for(int i=0;i<n;i++){
        if(array[i]!=0){
            temp.push_back(array[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(array[i]==0){
            temp.push_back(array[i]);
        }
    }
}
vector<int> leftRoate(vector<int> arr , int n){
    vector<int> temp(n);
    for(int i=1;i<n;i++){
        temp[i-1]=arr[i];    
    }
    temp[n-1]=arr[0];
    //print the temp array
    return temp;
}
void rightRoate(vector<int> arr , int n){
    vector<int> temp(n);
    for(int i=n-2;i>=0;i--){
        temp[i+1]=arr[i];
    }
    temp[0]=arr[n-1];
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}
int main()
{
    // rotate an array:- 1 2 3 4 5 6 7 8   //left roate and right rotate
    //left roatate the array by 2 places {1 2 3 4 5 6 7 8} => {2 3 4 5 6 7 8 1}=>{3 4 5 6 7 8 1 2}
    //right roatate the array by 2 places {1 2 3 4 5 6 7 8} => {8 1 2 3 4 5 6 7}=> {7 8 1 2 3 4 5 6}
    vector<int> array={1,2,3,4,5,6,7,8};

    //leftRoate(array , 8);
    rightRoate(array , 8);    
    return 0;
}