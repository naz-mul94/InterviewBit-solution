string Solution::solve(string A) {
    string result = "";
    for(int i = A.length()-1; i>=0; --i)
    {
        if (A[i] != ' ')
        {
          int last = i;
          int first = i;
          while (i>=0 && A[i] != ' ')
              --i;
              
          first = i + 1;
          result.append(A.begin()+first, A.begin()+last+1);
          
          //if not last word then add a space
          if (i>0)
          {
            
            result+=' ';
          }
        }
    }
    return result;
}
