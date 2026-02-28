#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int helper(vector<int> &nums, int low , int high,int min) 
    {
        int mid = (low + high)/2 ; 
        
        if(low == high) 
        {
            if(nums[low] < min) return nums[low] ;  
            else return min ; 
        }  
        else if(low > high) return min ;
        else 
        {
            int a = helper(nums,mid+1,high,min); 
            int b = helper(nums,low,mid,min) ;  
            return ((a>=b)?b : a) ; 
        } 
    } 
    int findMin(vector<int>& nums) 
    {
        return helper(nums,0,nums.size()-1,nums[0]); 
    }
};
// if you use nu
// Fails (since duplicates are present !!!)
/* 

class Solution {
public: 
    int helper(vector<int> nums, int low , int high,int min) 
    {
        int mid = (low + high)/2 ;
        if(low == high) 
        {
            if(nums[low] < min) return nums[low] ;  
            else return min ; 
        }  
        else if(nums[low] <= nums[mid])  // left sorted 
        {
            if(nums[low] < min) min = nums[low] ; 
            return helper(nums,mid+1,high,min) ;
        } 
        else if(nums[mid] <= nums[high])  // right sorted 
        {
            if(nums[mid] < min) min = nums[mid] ; 
            return helper(nums,low,mid-1,min); 
        } 
        else return min ; 
    } 
    int findMin(vector<int>& nums) 
    {
        return helper(nums,0,nums.size()-1,nums[0]); 
    }
};


 */
int main() {
    Solution sol;
    return 0;
}

