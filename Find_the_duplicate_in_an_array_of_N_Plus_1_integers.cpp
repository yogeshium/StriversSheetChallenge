//Solution: (There are many approaches for this Question)

//Approach 1 : (Using linked list - cycle detection)
 class Node
    {
        public:
        int data;
        Node* next;

        Node(int t)
        {
            data =t;
            next = NULL;
        }
    };

    int findDuplicate(vector<int>& nums) 
    {
        int n=nums.size();

        //Making Linked List
        vector<Node*> mp(n);
        for(int i=0;i<n;i++)
            mp[i]= new Node(i);
        
        Node* head=mp[0];
        Node* root=head;
        while(n--)
        {
            root->next = mp[nums[root->data]];
            root = root->next;
        }
        
        //Applying fast and slow pointer
        int ans=-1;
        Node* fp = head, *sp = head;
        while(fp && fp->next)
        {
            sp=sp->next;
            fp=fp->next->next;
            if(fp==sp)
                break;
        }
        if(fp==sp)
        {
            sp=head;
            while(sp!=fp)
            {
                fp=fp->next;
                sp=sp->next;
            }
            ans=fp->data;
        }

        return ans;
    }

//Other Approaches are:
/*
  ->Using Two Loop
  ->Using SET
  ->Using Binary Search
  ->Using Bit Manipulation
  ->Using Index Sort
  ->By marking visited in the given array

*/
