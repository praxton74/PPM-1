#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);
void _getMinAtPop(stack<int>s);

stack<int> _push(int arr[],int n) {
    stack<int> s;
    for(int i = 0; i < n; i++)
        s.push(arr[i]);
    
    return s;
}

void _getMinAtPop(stack<int> s) {
    // your code here
    vector<int> arr;
    // add elements in the vector
    while(!s.empty()) {
        arr.push_back(s.top());
        s.pop();
    }
    stack<int> minStack;
    
    int n = arr.size();
    for(int i = n - 1; i >= 0; i--) {
        s.push(arr[i]);
        if(minStack.empty() || arr[i] < minStack.top())
           minStack.push(arr[i]);
        else
            minStack.push(minStack.top());
    }
    // printing the elements of minStack
    while(!minStack.empty()) {
        cout << minStack.top() << " ";
        minStack.pop();
    }
    cout << endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    
	    
	}
	return 0;
}
