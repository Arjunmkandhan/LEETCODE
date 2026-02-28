#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int consecutiveNumbersSum(int n) 
    {
        int count = 0 ; 
        for(int k = 1 ; ; k++) 
        {
            int sub = (k * (k-1))/2 ; 
            int r = n - sub ; 
            if(r<=0) break ; 
            if(r%k == 0) {
                count++ ;
            }
        } 
        return count ; 
    }
};

// Aproach 1 : Iterative 
/* 
    int consecutiveNumbersSum(int n) 
    {
        int i = 1 , j = 1 , count = 0,sum = 1; 
        while(j<n) 
        { 
            if(i> (n/2)+1) break ;
            if(i!=j && sum == n) 
            {
                count++; 
                sum-=i ;  
                i++; 
            } 
            else if(sum < n) 
            {
                j++; 
                sum+=j ;
            } 
            else if(sum > n) 
            {
                sum-= i ; 
                i++; 
            } 
            else 
            {
                j++ ; 
                sum+=j ;
            }
        }
        return count+1 ; 
    }

 */
int main() {
    Solution sol;
    return 0;
}