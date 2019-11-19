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
*/
[image](https://github.com/naz-mul94/InterviewBit-solution/blob/master/arrangeII.jpg)
