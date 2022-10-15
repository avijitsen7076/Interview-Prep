//Job Sequencing Problem
//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1


//Method-1 (Greedy Approach)
// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool myCmp(Job j1, Job j2){
        return j1.profit > j2.profit;   //arranges in descending order
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,myCmp);
        
        int slot_max=-1;
        for(int i=0;i<n;i++)
            if(arr[i].dead>slot_max)
                slot_max=arr[i].dead;
                
        int slot_size= min(n,slot_max);
        int count=0,sum=0;
        vector<int> time_slot(slot_size,-1);
        
        //O(N^2)
        for(int i=0;i<n;i++){
            int m = min(n, arr[i].dead);
            //for finding the slot availabe and assigning the job
            while(m){
                if(time_slot[m-1]==-1){
                    time_slot[m-1]=arr[i].id;
                    sum+=arr[i].profit;
                    count++;
                    break;
                }
                m--;
            }
        }
        
        vector<int> jobs={count,sum};
        return jobs;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}