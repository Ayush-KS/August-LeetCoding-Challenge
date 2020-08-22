// Reorder List

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next)
            return;
        stack<ListNode*> st;
        st.push(head);
        ListNode* middle = head;
        ListNode* fast = head;
        
        while(fast && fast -> next) {
            middle = middle -> next;
            fast = fast -> next -> next;
            st.push(middle);
        }
        
        middle = middle -> next;
        ListNode* currHead;
        if(!(fast)) {
            ListNode* temp = st.top();
            st.pop();
            currHead = st.top();
            st.pop();
            currHead -> next = temp;
            temp -> next = NULL;
        } else {
            currHead = st.top();
            currHead -> next = NULL;
            st.pop();
        }
        //cout << currHead -> val << " ";
        
        while(middle) {
            //cout << middle -> val << " ";
            ListNode* newMiddle = middle -> next;
            // if(!newMiddle) {
            //     cout << "hahah";
            // }
            middle -> next = currHead;
            currHead = st.top();
            st.pop();
            currHead -> next = middle;
            middle = newMiddle;
        }
        head = currHead;
    }
};