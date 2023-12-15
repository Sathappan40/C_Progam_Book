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
 printf("Celsius to Fahrenheit Conversion\n");
 while (celsius <= upper) 
 {
  fahr = celsius*(9.0/5)+32;
  printf("%3.0f %6.1f\n", celsius, fahr);
  celsius = celsius + step;
 }
}
