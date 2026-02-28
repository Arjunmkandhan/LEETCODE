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
    ListNode *reverse(ListNode *head) 
    {
        ListNode *temp = new ListNode() ; 
        temp->next = head ; 
        ListNode *back = nullptr , *ptr1 = head , *ptr2 = head->next ; 
        while(ptr2!=nullptr) 
        {   
            ptr1->next = back ;
            back = ptr1; 
            ptr1 = ptr2; 
            ptr2 = ptr2->next ; 
        } 
        ptr1->next = back; 
        return ptr1 ;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == nullptr || head->next == nullptr || k == 1) return head ; // 0 or 1 node 
        head = reverse(head); 
        int count = 0 ; 
        for(ListNode *temp = head ; temp!=nullptr ; temp = temp->next)  count++;  
        cout<<count<<endl; 
        int remain = count%k ; 
        ListNode *aux = new ListNode() ; 
        aux->next = head;  
        ListNode *start , *end; 
        if(remain == 0)  { start = aux ; end = aux ; }
        else  { start = head ; end = head ; }

        for(int i = 1 ; i<remain ; i++) end = end->next; 

        ListNode *t=end->next , *t2 , *f=end->next , *abc = nullptr; 
        count = 1 ; 
        while(t!=nullptr) 
        {
            count = 1;
            while(count<k) 
            {
                t = t->next; count++; 
            } 
            if(t == nullptr) break ;
            t2 = t->next; 
            t->next = abc ; 
            abc = f ; 
            f = t2 ; t = t2 ; 
        }

        end->next = nullptr; 
        start = reverse(start); 
        for(end = abc ; end->next !=nullptr ; end = end->next) ;  
        if(remain!=0) end->next = start ;  
        else end->next = nullptr; 
        return abc; 
    }
};

// Sleek .....  
// wah modiji waaahhhhh . 
/* 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //1.check k nodes are there
        ListNode* d = head;
        for(int i=0;i<k;i++){
            if(!d) return head;
            d = d->next;
        }

        //2.reverse the k grp
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* after;
        for(int i=0;i<k;i++){
            after = curr->next;

            curr->next = prev;

            prev = curr;
            curr = after;
        }

        //3. recur prev - head - curr
        head->next = reverseKGroup(curr,k);
        return prev; 

    }
};
 */

int main() {
    Solution sol;
    

    return 0;
}