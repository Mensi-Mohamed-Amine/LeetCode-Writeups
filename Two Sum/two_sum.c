/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b)
{
    return (*(int (*)[2])a)[0] - (*(int (*)[2])b)[0];
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int newNums[numsSize][2];
    for (int i = 0; i < numsSize; i++)
    {
        newNums[i][0] = nums[i];
        newNums[i][1] = i;
    }
    qsort(newNums, numsSize, sizeof(newNums[0]), compare);

    int left = 0, right = numsSize - 1;

    int *arr = malloc(2 * sizeof(int));
    *returnSize = 2;

    while (left < right)
    {
        if (newNums[left][0] + newNums[right][0] == target)
        {
            arr[0] = newNums[left][1];
            arr[1] = newNums[right][1];
            return arr;
        }
        else if (newNums[left][0] + newNums[right][0] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return arr;
}