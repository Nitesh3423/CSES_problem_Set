#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    multiset<int> ticketPrices;
    vector<int> customers(m);

    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        ticketPrices.insert(price);
    }

    for (int i = 0; i < m; ++i) {
        cin >> customers[i];
    }

    for (int i = 0; i < m; ++i) {
        int maxPrice = customers[i];
        auto it = ticketPrices.upper_bound(maxPrice);

        if (it == ticketPrices.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            ticketPrices.erase(it);
        }
    }

    return 0;
}
