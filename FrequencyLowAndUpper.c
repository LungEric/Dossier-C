#include <stdio.h>
#include <string.h>

int main()
{
   char string[100];
   int c = 0, countLower[26] = {0};
   int countUpper[26] = {0};

   printf("Enter a string\n");
   fgets(string,100,stdin);
//&& (string[c] != '\n')
   while((string[c] != '\0')) {
      c++;
   }

   string[c] = '\0';
   c = 0;

   while (string[c] != '\0')
   {
      /** Considering characters from 'a' to 'z' only
          and ignoring others */

      if (string[c] >= 'a' && string[c] <= 'z')
          countLower[string[c]-'a']++;
      else if(string[c] >= 'A' && string[c]<= 'Z')
          countUpper[string[c]-'A']++;
      c++;
   }

   for (c = 0; c < 26; c++)
   {
      /** Printing only those characters
          whose count is at least 1 */

      if (countLower[c] != 0)
         printf("%c occurs %d times in the entered string.\n",c+'a',countLower[c]);
      if (countUpper[c] != 0)
         printf("%c occurs %d times in the entered string.\n",c+'A',countUpper[c]);
   }

   return 0;
}
