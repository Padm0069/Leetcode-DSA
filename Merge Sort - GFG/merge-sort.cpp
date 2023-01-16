//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int k=l;
        int i=l;
        int j=m+1;
        int B[r+1];
        while(i<=m && j<=r)
        {
            if(arr[i]<arr[j])
                B[k++] = arr[i++];
            else 
            B[k++] = arr[j++];
        }
        for(; i<=m; i++) B[k++] = arr[i];
        for(; j<=r; j++) B[k++] = arr[j];
        for(int i=l; i<=r; i++) arr[i]=B[i];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
         if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends