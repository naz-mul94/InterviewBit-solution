int Solution::solve(vector<int> &A, int B) {
    int low = 0, high =A.size()-1, mid=-1, lastLessOrEq=-1;
    while(high>=low)
    {
        mid = low + (high - low)/2;
        if(A[mid]==B || A[mid] < B)
        {
            lastLessOrEq = mid;
            low = mid +1;
        }
        else 
            high = mid - 1;
    }
    if (lastLessOrEq == -1) return 0;
    else return lastLessOrEq + 1;
}
