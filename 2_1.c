#include <stdio.h>
#include <limits.h>
int main()
{
   int c_min, c_max;
   int uc_min, uc_max;

   int i_min, i_max;
   int ui_min, ui_max;


   c_min = (char)(1 << (sizeof(char) * 8 - 1));
   c_max = ((char)(~0 & ~c_min));

   printf("char MIN is %d, char MAX is %d\n", c_min, c_max);
   printf("CHAR_MIN is %d, CHAR_MAX is %d\n", CHAR_MIN, CHAR_MAX);

   uc_min = (unsigned char)0;
   uc_max = (unsigned char)~0;

   printf("unsigned char MIN is %d, unsigned char MAX is %d\n", uc_min, uc_max);
   printf("UCHAR_MIN is %d, UCHAR_MAX is %d\n", 0, UCHAR_MAX);

   i_min = (int)(1 << (sizeof(int) * 8 - 1));
   i_max = ((int)(~0 & ~i_min));

   printf("int MIN is %d, int MAX is %d\n", i_min, i_max);
   printf("INT_MIN is %d, INT_MAX is %d\n", INT_MIN, INT_MAX);

   ui_min = (unsigned int)0;
   ui_max = (unsigned int)~0;

   printf("unsigned int MIN is %d, unsigned int MAX is %d\n", ui_min, ui_max);
   printf("UINT_MIN is %u, UINT_MAX is %u\n", 0, UINT_MAX);

   return 0;
}
