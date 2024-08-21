#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    stack<char> charStack;
    cout<<"Nitesh Kumar"<<endl;
    cout<<"Roll no - 22115062"<<endl;
    cout<<"Enter no of  elements you want to generate"<<endl;
    int numChars;
    cin>>numChars; 
    for (int i = 0; i < numChars; ++i) {
        char randomChar = 'A' + rand() % 26;  
        charStack.push(randomChar);
    }
    while (!charStack.empty()) {
        cout << charStack.top() << " ";  
        charStack.pop();                 
    }
    cout << endl;
    return 0;
}
