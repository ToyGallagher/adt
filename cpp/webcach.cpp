/*#include <iostream>
#include <deque>
#include <unordered_set>
using namespace std;

int main()
{
    int n, m, webpage_id, count_miss = 0;
    cin >> n >> m;
    deque<int> cache;
    unordered_set<int> check_id;

    for (int i = 0; i < m; i++) {
        cin >> webpage_id;
        if (check_id.find(webpage_id) == check_id.end()) {
            count_miss++;
            cache.push_back(webpage_id);
            check_id.insert(webpage_id);
            if (cache.size() == (n+1)) {
                check_id.erase(cache.front());
                cache.pop_front();
            }
        }
    }
    cout << count_miss;
}
*/
/*#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>

using namespace std; 

 
void merge(long long arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
   
    long long L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
       {
       	 L[i] = arr[l + i];
	   }
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(long long arr[], int l, int r)
{
    if (l < r)
    {
  
        int m = l+(r-l)/2;
 
       
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 
 
 
void printArray(long long A[], int size)
{
    int i;
    for (i=0; i < size; i++)
         {
         	cout<<A[i];
         	if(i<size-1) cout<<" ";
		 }
    
    cout<<endl;
}

int main()
{
	 int n;
	while(cin>>n && n!=0)
	{
		long long a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		 mergeSort(a, 0,n-1);
		  printArray(a,n);
		 
	}
}*/

#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    long long inversionCount = 0;
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    while (i < n1)
        arr[k++] = leftArr[i++];

    while (j < n2)
        arr[k++] = rightArr[j++];

    return inversionCount;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    long long inversionCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversionCount += mergeSortAndCount(arr, left, mid);
        inversionCount += mergeSortAndCount(arr, mid + 1, right);

        inversionCount += mergeAndCount(arr, left, mid, right);
    }
    return inversionCount;
}

long long countInversions(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr ;
    int n,k ;
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cin >> k ;
        arr.push_back(k);
    }
    long long inversions = countInversions(arr);

    cout << inversions << endl;

    return 0;
}





