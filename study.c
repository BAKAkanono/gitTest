#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target)
{
    static int a[2]={0};


	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i+1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				a[0] = i;
				a[1] = j;
				return a;
			}
		}
	}
	return 0;
}
int main()
{
    int nums[5];
    int target;
    int arr[2];
    printf("请输入一个数组和目标值");
    scanf("%d",&nums[0]);
    scanf("%d",&target);
    void *twosums(nums,5,target);
    arr[]=*twosums;
    printf("[%d,%d]",arr[0],arr[1]);
    return 0;
}