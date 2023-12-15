#include <stdio.h>
/* print Fahrenheit-Celsius table
for celsius = 0, 20, ..., 300 */
main()
{
 float fahr, celsius;
 float lower, upper, step;
 lower = 0;
 upper = 300;
 step = 20;
 celsius = lower;
 while (celsius <= upper) 
 {
  fahr = celsius*(9.0/5)+32;
  printf("%f\t%f\n", celsius, fahr);
  celsius = celsius + step;
 }
}
