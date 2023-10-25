Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: In this example the largest area would be 12 of height 4 and width 3. We can achieve this 
area by choosing 3rd, 4th and 5th bars.


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
0 ≤ arr[i] ≤ 1012

!!!HERE IS SOLUTION!!!

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // Function to find the largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long* ps = prevsmaller(arr, n);
        long long* ns = nextsmaller(arr, n);
        long long maxAns = 0;
        for(int i = 0; i < n; i++)
        {
            long long cur = (ns[i] - ps[i] - 1) * arr[i];
            maxAns = std::max(maxAns, cur);
        }
       // delete[] ps; // Deallocate memory for ps[]
        //delete[] ns; // Deallocate memory for ns[]
        return maxAns;
    }

    long long* prevsmaller(long long arr[], int n)
    {
        long long* ps = new long long[n];
        std::stack<long long> s;
        for(int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                ps[i] = -1;
            }
            else
            {
                ps[i] = s.top();
            }
            s.push(i);
        }
        return ps;
    }

    long long* nextsmaller(long long arr[], int n)
    {
        long long* ns = new long long[n];
        std::stack<long long> s;
        for(int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                ns[i] = n;
            }
            else
            {
                ns[i] = s.top();
            }
            s.push(i);
        }
        return ns;
    }
};
