#define MAX(x,y) (x) > (y) ? (x) : (y)

int maxSubArray(int* nums, int numsSize){
    int local_best = 0, global_best = INT_MIN;
    for(int i = 0; i < numsSize; i++){
        local_best = MAX(nums[i], local_best + nums[i]);
        global_best = MAX(local_best, global_best);
    }
    return global_best;
}