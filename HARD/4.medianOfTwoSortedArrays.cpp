#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector <int> ans(nums1.size() + nums2.size()) ;
        int i = 0 , j = 0 ,count =0 ; 
        while(i<nums1.size() && j<nums2.size()) 
        {
            if(nums1[i]<=nums2[j]) 
            {
                ans[count++] = nums1[i++] ; 
            }
            else
            {
                ans[count++] = nums2[j++] ; 
            }
        }
        while(i<nums1.size()) 
        {
            ans[count++] = nums1[i++] ; 
        }
        while(j<nums2.size()) 
        {
            ans[count++] = nums2[j++] ; 
        }

        //for(auto i : ans) cout<<i<<" "; 
        //cout<<endl; 


        int mid = ans.size()/2 ; 
        if(ans.size() %2==0) 
        {
            return (ans[mid-1] + ans[mid]) / 2.0 ; 
        }
        else return ans[mid] ; 
    }
};


int main() {
    Solution sol;
    

    return 0;
}