//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++
class Solution{
  public:
    // Function to find the missing number in the array
    int missingNumber(vector<int>& array, int n) {
        // Calculating the sum of numbers from 1 to n using the formula
        // total = (n + 1) * n / 2
        long N=n;
        long long total = (N + 1) * (N) / 2;
        
        // Subtracting each element of the array from the total sum
        // to find the missing number
        for (int i = 0; i < n-1; i++)
            total -= array[i];
        
        // Returning the missing number as the total
        return (int)total;
  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends