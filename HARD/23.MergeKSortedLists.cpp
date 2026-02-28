#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode *head = new ListNode() ;
        ListNode *temp = head ;  
        vector<ListNode*> ptr(lists.size()) ; 
        for(int i = 0 ; i<lists.size() ;i++) 
        {
            ptr[i] = lists[i] ; 
            if(ptr[i]!=nullptr) cout<<ptr[i]->val<<endl; 
        }
        bool flag = true ; 
        int min = INT_MAX ; 
        while(flag) 
        {
            flag = false ;
            int ind =-1; 
            for(int i = 0 ; i<lists.size() ; i++) 
            {
                if(ptr[i]!=nullptr) 
                {
                    min = ptr[i]->val ; 
                    ind = i ; 
                }
            } 
            for(int i = 0 ; i<lists.size() ; i++) 
            {
                if(ptr[i]!=nullptr) 
                {
                    flag = true ; 
                    if(ptr[i]->val <= min) 
                    {
                        ind = i ; 
                        min = ptr[i]->val ; 
                    }
                }
            }
            if(ind == -1) break ;
            else 
            {
                temp->next = ptr[ind] ; 
                temp = ptr[ind] ; 
                ptr[ind] = ptr[ind]->next ; 
            }
        }
        
        return head->next ; 
        
    }
};
int main() {
    Solution sol;
    

    return 0;
}