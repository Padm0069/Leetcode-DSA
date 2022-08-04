class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); int n=nums.size();
		int ans=INT_MAX; int op=0;	

		for(int i=0;i<n-2;i++)   //check for all ith element + their next2 elems 
		{
			int j=i+1; int k=n-1;  //these 2 should sum with ith elem to give the closest sum

			while(j<k)
			{
				int sum=nums[i]+nums[j]+nums[k];  //getting the sum and checking the conditions

				 //if sum==target then no need to check futher this will be the closest with diff=0
				if(sum==target) 
				{
					op=sum; break;
				}
				//if sum is less than target then store the min diff and the corresponding sum we get
				else if(sum<target)  
				{
					if(abs(sum-target)<ans) 
					{
						ans=abs(sum-target); op=sum;
					}
					j++;
				}
				//if sum is greate than target then also do the same, store the min diff and the corresponding sum 
				else   
				{
					if(abs(sum-target)<ans) 
					{
						ans=abs(sum-target); op=sum;
					}
					k--;
				}      
			}
		}
		return op;
    }
};