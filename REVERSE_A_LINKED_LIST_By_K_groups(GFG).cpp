
class Solution
{
    public:
    int getLen(node * head){
    node * temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
    node* solve(node* &head, int k){
        //
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        int n=getLen(head);
        if(k>n){
        node *prev=NULL;
        node* curr=head;
        node* forward=head->next;
            int cnt=0;
            while(cnt<k && forward !=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            
            cnt++;
        }
        return prev;
        }
        //LL having grtr than 2 nodes
        node *prev=NULL;
        node* curr=head;
        node* forward=head->next;
        int cnt=0;
        while(cnt<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            
            cnt++;
        }
        if(forward!=NULL){
        //still some nodes is left for reverse
            head->next=solve(forward,k);//YE LINE MAI BHULUNGA
        }
        return prev;

    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* a=solve(head,k);
        return a;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends
