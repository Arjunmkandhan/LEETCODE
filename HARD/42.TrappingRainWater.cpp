#include <bits/stdc++.h>
using namespace std; 

using namespace std ; 
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int size = height.size() ; 
        int *arr= new int[size] ; 
        int *w = new int[size] ; // assign all elements to 0. initialy 
        for(int i = 0 ;i<size ; i++) w[i] = 0 ; 
        for(int i = 0; i<size ; i++) 
        {
            arr[i] = height[i] ; 
        }
        int first = 0; 
        int last = size -1 ; // points the last element ; 
        //cout<<"The last is : "<<*(last-1)<<endl; 
        for(int i = 1 ; i<size ;i++) 
        {
            if(arr[first] > arr[(first+1)])
            {
                break; 
            }
            first = first + 1; 
        }

        for(int j = size - 2; j>=0; j--) 
        {
            if(arr[last] > arr[last-1])
            {
                break ;
            }
            last = last-1 ; 
        }
        // check point done *** first and last done *** ; 

        //cout<<"The first element is : "<<first<<"and the last element is : "<<last; 
        int l_max = arr[first], r_max = arr[last] ;
        int temp_first = first ; 
        int min ;
        
        int l , f ; 
        for( l = last ; l>temp_first ; l--) 
        {
            l_max = arr[temp_first] ; 
            if(arr[l]>r_max) r_max = arr[l] ;

            for(f = temp_first ; f<l-1 ; f++) 
            {
                if(arr[f]>l_max) 
                {
                    l_max = arr[f]; 
                }
            }
            min = (l_max <= r_max)? l_max : r_max ;

            //if(arr[f] < min)     w[f] = min - arr[f] ;   
            if(arr[l-1]<min)       w[l-1] = min-arr[l-1] ; 
        }

        /* 
        while(first <= last) 
        {

            for(int k = last ; k> temp_first ; k--) 
            {
            first = temp_first ;
            min = (l_max <= r_max)? l_max : r_max ;
            first++ ; 
            
            if(arr[first] > l_max) l_max = arr[first] ; 
            if(arr[last] > r_max) r_max = arr[last] ; 

            if(arr[first] < min) w[first] = min - arr[first] ;   
            if(arr[last]<min) w[last] = min-arr[last] ; 

            if(arr[first] > l_max) l_max = arr[first] ; 
            if(arr[last] > r_max) r_max = arr[last] ; 
            }
            last-- ; 
                                                                    
        }   
 */
        int water_trapped =0; 
        for(int i = 0  ;i<size ; i++) 
        {
            //cout<<w[i]<<" "; 
            water_trapped+=w[i] ; 
        }



        delete []arr ; 
        delete []w ; 
        return water_trapped ; 
    }
};
int main() {
    Solution sol;
    return 0;
}