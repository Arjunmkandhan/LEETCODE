#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    vector<int>columns;  
    vector<vector<string>> ans ; 
    vector<string> board;   
    int num_of_sol ;   
    string str1 = ""; 
    string ascii(int ind , int len)  
    {
        string s = "" ; 
        for(int i =0 ; i<len ;i++) 
        {
            if(i == ind) s = s + "Q"; 
            else s = s + "."; 
        } 
        return s; 
    }
    bool isSafe(int row , int col) 
    {
        for(int i = 0 ;i<row ; i++) 
        {
            int prev_row = i ; 
            int prev_col = columns[i] ; 
            if(prev_col == col) return false; 
            if(abs(prev_row - row) == abs(prev_col - col)) return false; 

        }
        return true; 
    }
    bool eachrow(int row, int n)   
    {
        if(row >= n )  
        {
            ans.push_back(board) ; 
            return true; 
        }
        for(int col = 0 ; col <n ; col++) 
        {
            if(isSafe(row,col)) 
            {
                str1 = ascii(col,n) ;  
                board.push_back(str1);  
                columns[row] = col ; 
                if(eachrow(row+1,n)) 
                {
                    num_of_sol++; 
                }  
                columns[row] = -1; 
                board.pop_back(); 
            }
        } 
        return false; 
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        columns.resize(n,-1);   
        num_of_sol = 0 ; 
        bool flag = eachrow(0,n);  
        return ans; 
    }
};
int main() {
    Solution sol;
    return 0;
}