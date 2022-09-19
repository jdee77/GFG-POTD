/*
Given an array a of integers of length n, find the nearest smaller number for every element 
such that the smaller element is on left side.
If no small element present on the left print -1.
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> res;
        int smaller = a[0], size = n;
        res.push_back(-1);
        
        for(int i = 1; i< size; i++)
        {
            if(a[i]<= smaller)
            {
                res.push_back(-1);
            }
            else
            {
                int j = i-1;
                while(j>= 0 && a[j]>= smaller)
                {
                    if(a[j]< a[i])
                    {
                        res.push_back(a[j]);
                        break;
                    }
                    j--;
                }
            }
            smaller = min(a[i], smaller);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
