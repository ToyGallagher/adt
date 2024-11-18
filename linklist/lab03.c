/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 101
int main(){
    int arr[SIZE];
    int arrcount[SIZE];
    int n,temp,max = 0 ;
    int i,j,a;
    
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        //arr = (int *)malloc(sizeof(int)*SIZE);
        arr[i] = temp;
        //for (int j = 0 ; j < arr)
        //printf("%d \n",arr[i]);
    }
    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j){
            if (arr[i] > arr[j]){
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count += 1;
            }
            else{
                arrcount[i] = count;
            }       
        }
        
    }
    printf("------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arrcount[i]); 
    }
    
     
    //printf("%d",arr[1]);
}   */


#include <stdio.h>
#include <stdlib.h>
void findStats(int *nums,int n,double *avg,int *maxi,int *mini) {
    *maxi = nums[0];
    *mini = nums[0];
    double sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > *maxi)
        {
            *maxi = nums[i];
        }if (nums[i]<*mini)
        {
            *mini = nums[i];
        }
        sum+=nums[i];
    }
    *avg = sum / n;
    


}
int main() {
int n, i, maxi, mini;
double avg;
int *nums;
scanf("%d", &n);
nums = (int *)malloc(sizeof (int) *n);
for (i=0; i<n; i++)
{
    scanf("%d", nums+i);
}
findStats(nums,n,&avg,&maxi,&mini);
printf("%.2f %d %d", avg, maxi, mini);
return 0;
}