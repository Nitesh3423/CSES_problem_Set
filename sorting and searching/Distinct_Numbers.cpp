#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    
    unordered_set<long long> st;
    st.reserve(n); 

    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        st.insert(temp);
    }
    
    cout << st.size() << endl;

    return 0;
}
