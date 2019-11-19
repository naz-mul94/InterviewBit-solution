/*
Let's assume there are six horses BBWBWB where B represents black horses and W represents white horses. And there are three stables.
This problem is alike to matrix multication problem. We have to decide where should we put parenthesis. 
Let's loot at the all possibilities.
**Constrains: 
(i)   You fill the horses into the stables preserving the relative order of horses. 
      For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. 
      You have to preserve the ordering of the horses.
(ii)  No stable should be empty and no horse should be left unaccommodated.
(iii) Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. 
      This value should be the minimum among all possible accommodation arrangements

1. (B)(B)(WBWB)  **So, first, we have to make sure that every stables gets atleast one horse. 
2. (B)(BW)(BWB)    So we shall put first one horse in each stables serially(because of (i) constraint.)  
3. (B)(BWB)(WB)    Then we put rest of horses in last stables. And then we start manipulate parenthesis. 
4. (B)(BWBW)(B)                          ___     _   
-----------------   Recurrence Equation:|       |
5. (BB)(W)(BWB)     sumOfProduct(i, j)= |   min | sumOfProduct(i+1, j+1) + (no 0f white horses* no of black horses)
6. (BB)(WB)(WB)                         |       |_ 
7. (BB)(WBW)(B)                         |      i=current horse no to no of horses
-----------------                       |      j=current stables to no stables         
8. (BBW)(B)(WB)                         |___ 
9. (BBW)(BW)(B)                          
----------------
10. (BBWB)(W)(B)
[image](https://github.com/naz-mul94/InterviewBit-solution/blob/master/arrangeII.jpg)
*/

int helper(string A, int no, int B, int idx, vector<vector<int>> &dp)
{
    //printf("sum=%d\n",sum );
    int len=A.size()-idx;
    int n=A.size();
    //if(n<B)return -1;
    int black=0, white=0, temp, ans=INT_MAX;
    if(dp[idx][no]!=-1)return dp[idx][no];
    if(no==B-1)
    {
        
        for(int i=idx;i<n;i++)
        {
            (A[i]=='B')?black++:white++;
        }
        temp=black*white;//printf("temp=%d, sum=%d, ans1=%d\n",temp, sum, ans1 );
        dp[idx][no]=temp;
        return dp[idx][no];
    }
    int x=INT_MAX;
    for(int i=idx;i<n-(B-no-1);i++)
    {
        (A[i]=='B')?black++:white++;
        temp=black*white;
        x=min(x,temp+helper(A, no+1, B, i+1, dp));
    }
    return dp[idx][no]=x;
}

int Solution::arrange(string A, int B) {
    int n=A.size();
    if(n<B)return -1;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int black=0, white=0, temp, ans1=INT_MAX, x=INT_MAX;
    if(B==1)
    {
        
        for(int i=0;i<n;i++)
        {
            (A[i]=='B')?black++:white++;
        }
        temp=black*white;
        return temp;
    }
    for(int i=0;i<n-(B-1);i++)
    {
        (A[i]=='B')?black++:white++;
        temp=black*white;
        x=min(x, temp+helper(A, 1, B, i+1, dp));
    }
    dp[0][0]=x;
    if(x==INT_MAX)return -1;
    return x;
}
