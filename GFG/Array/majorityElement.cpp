//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#


//METHOD 1: Moore's Voting algorithm (BEST APPROACH)
// TC=O(N) SC=O(1)
//based on cancellation principle, everytime we cancel a supposed majority ele with the next ele so the ele in maj_ele gives us 
//a possible candidate for the majority element then we verify by traversing the array again)
int findCandidate(int a[], int size)
    {
        int maj_ele=a[0], count=1;
        for(int i=1;i<size;i++)
        {
            if(a[i]==maj_ele)
            count++;
            else count--;
            
            if(count==0)
            {
                maj_ele=a[i];
                count=1;
            }
        }
        return maj_ele;
    }
    int majorityElement(int a[], int size)
    {
        // your code here
        int candidate = findCandidate(a, size);
        int c=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==candidate) c++;
            if(c>size/2)
            return candidate;
        }
        return -1;
    }

//METHOD 2: Hashmap
//TC=O(N) SC=O(N)

//METHOD 3: sorting
//TC=O(N logN) SC=O(1)
int majorityElement(int a[], int size)
    {
        // your code here
        sort(a,a+size);
        int ans=-1;
        int c=1;
        // for(int i=0;i<size;i++)
        // cout<<a[i]<<" ";
        for(int i=1;i<size;i++)
        {
            if(a[i]!=a[i-1])
            {
                if(c>size/2)
                {
                    ans=a[i-1];
                }
                c=1;
            }
            else c++;
        }
        if(c>size/2)
        ans=a[size-1];
        return ans;
    }