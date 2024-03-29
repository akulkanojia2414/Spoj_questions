/*PRANJULDB*/
#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
 int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}






int  _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
   number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;

    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;

  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }

  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];

  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}


int getInvCount(int arr[], int n)
{
  int inv_count = 0;
  int i, j;

  for(i = 0; i < n - 1; i++)
    for(j = i+1; j < n; j++)
      if(arr[i] > arr[j])
        {inv_count++;
        inv_count=(inv_count%2);
        }

  return inv_count%2;
}


int a[100100];
int main()
{
        int t,i,j,n,m,k,p,q,x,y,temp;

                scanf("%d%d",&n, &q);
                for(i=0;i<n;i++)
                {
                        scanf("%d",&a[i]);
                }
                //k=getInvCount(a,n);
                k=mergeSort(a,n)%2;
                //if(n>1){
                for(i=0;i<q;i++)
                {
                        cin>>x;
                        cin>>y;
                        m=min(x,y);
                        p=max(x,y);
                        //temp=a[x-1];
                        //a[x-1]=a[y-1];
                        //a[y-1]=temp;
                        if(a[m-1]<a[p-1])
                        {
                                k=k+1;
                                k=k%2;
                        }
                        else if(a[m-1]>a[p-1])
                        {
                                k=k-1;
                                k=(k+2)%2;
                        }
                        cout<<k<<endl;
                }
                //}
                //else
                        //cout<<"0\n";
                //cout<<(mergeSort(a,n)%2)<<"\n";

        return 0;
}
