#include<iostream>
#include<stdio.h>

#define space ' '
#define indent '\n'

int form_5(int cur_num, int cur_dig)
{
  cur_num = cur_num * 10 + cur_dig;
  return cur_num;
}

int to_10(int num_5)
{
  int dig = 1, res = 0;
  while (num_5 != 0)
  {
    res += (num_5 % 10) * dig;
    dig *= 5;
    num_5 /= 10;
  }
  return res;
}

int main()
{
  int i, dig_5, num_5, result, counter = 0;
  bool is_5, is_3 = 1;
  printf("\n");
  while ((i = getchar()) != EOF)
  {
    if ((i == space) || (i == indent))
    {
      if ((is_5 == 1) && (is_3 == 0))
      {
        result = to_10(num_5);
        printf("%d\n", result);
        counter++; 
      }
      num_5 = 0;
      is_5 = 1;
      is_3 = 1;
    }
    else
    {
      dig_5 = i -'0';
      num_5 = form_5(num_5, dig_5);
      if (dig_5 > 2)
      {
        is_3 = 0;
      }
      if (dig_5 > 4)
      {
        is_5 = 0;
      }
    }
  }
printf("%d\n", counter);
return 0;
}
