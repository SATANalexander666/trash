#include<stdio.h>

int main()
{
  long num_input, num, dig_1, dig_2, cur_dig, new_num = 0;
  scanf("%ld", &num_input);
  num = num_input;
  cur_dig = 1;
  while(num > 9)
  {
    dig_1 = num % 10;
    num /= 10;
    dig_2 = num % 10;
    if (dig_1 > dig_2)
      {
      new_num += (dig_1 - dig_2) * cur_dig;
      }
      else if (dig_1 < dig_2)
      {
      new_num += (dig_2 - dig_1) * cur_dig;
      } 
    cur_dig *= 10;
  }
  printf("%ld %ld\n", new_num, num_input - new_num);
  return 0;
}
