#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        if(ratings.size()==1) return 1 ;
        vector<int> ans(ratings.size(),1);   
        int size = ratings.size() ; 
        for(int i = 1 ; i<ratings.size() ; i++) 
        {
            if(ratings[i]>ratings[i-1]) ans[i] = ans[i-1] + 1 ; 
        } 
        for(int j = size-2 ; j>0 ; j-- ) 
        {
            if(ratings[j] > ratings[j+1] && (ans[j]<= ans[j+1]))   {
                ans[j] = ans[j+1] + 1; 
            }
        }
        if((ratings[0] > ratings[1]) && (ans[0] <= ans[1])) ans[0] = ans[1] + 1;  
        int sum = 0 ; 
        for(int i = 0 ; i<size ; i++) {
            cout<<ans[i]<<" ";   
            sum+= ans[i] ; 
        }
        return sum ; 
    }
};

int main() {
    Solution sol;
    return 0;
}