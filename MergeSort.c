#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int l, int mid, int r)
{
	int l_sz = mid-l+1, r_sz = r-mid;
	int left[l_sz], right[r_sz];
	int i, j, k;

	for(i=0;i<l_sz;i++)
	{
		left[i] = a[l+i];
	}
	for(i=0;i<r_sz;i++)
	{
		right[i] = a[mid+1+i];
	}
	
	i = 0, j = 0, k = l;
	while(i<l_sz && j<r_sz)
	{
		if(left[i]<=right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	
	while(i<l_sz)
	{
		a[k] = left[i];
		i++;
		k++;
	}
	
	while(j<r_sz)
	{
		a[k] = right[j];
		j++;
		k++;
	}
}

void  mergeSort(int a[], int l, int r)
{
	if(l < r)
	{
		int mid = (l+r)/2;

		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);

		merge(a,l,mid,r);
	}
}

void printArray(int a[],int size)
{
	int i = 0;
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	// Array before sorting
	printArray(arr,size);

	mergeSort(arr,0,size-1);
	printf("\nSorted Array\n");
	// Array after sorting
	printArray(arr,size);

}
