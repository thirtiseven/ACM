/*  2017/2018 Regional
    ACM International Collegiate Programming Contest

    Problem ?
    Latin Squares
    M. K. Furon.                    2017-10-18.                       */




#include  <stdio.h>
#include  <stdlib.h>
#include  <ctype.h>




int i, islatin, isreduced, j, size, value;
char *iostatus, *result;
char lineimage[40];
char square[36][36];




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




void checkrange (int value, int minvalue, int maxvalue, char *fault)
{
if ((value < minvalue)  ||  (value > maxvalue))
   {
   (void) fputs (fault, stderr);
   (void) fputs (":  ", stderr);
   abend ("Input value out of range!");
   }
return;
}




int validcheck (char array[][36], int byrow, int size)
{
int i;
int result = 1;
char set[size];

/*  Scan the array by row or by column depending on the value of
    "byrow".  Return 1 if all rows or columns meet the criteria for
    a Latin Square, 0 otherwise.                                       */
for (i = 0; result && (i < size); i++)
   {
   for (j = 0; j < size; j++)
      set[j] = (char) 0;
   for (j = 0; j < size; j++)
      {
      value = byrow ? (int) square[i][j] : (int) square[j][i];
      if (!set[value])              /*  If value not yet seen         */
         set[value] = (char) 1;
      else
	 {
	 /*  A value appeared more than once in the same row or
	     column.  This cannot be a Latin Square.                  */
	 result = 0;
	 break;
	 }
      }
   }

return (result);
}




int main (int argc, char *argv[], char *envp[])
{
while (fgets (lineimage, 38, stdin) != NULL)
   {
   size = atoi (lineimage);
   checkrange (size, 2, 36, "Square size");

   /*  Load a square into memory, checking for valid values.          */
   for (i = 0; i < size; i++)
      {
      iostatus = fgets (lineimage, 38, stdin);
      if (iostatus == NULL)
         abend ("Bad I/O status.");
      for (j = 0; j < size; j++)
         {
	 if (isdigit (lineimage[j]))
	    square[i][j] = lineimage[j] - '0';
	 else if (isupper (lineimage[j]))
            square[i][j] = lineimage[j] - 'A' + ((char) 10);
	 else
	    abend ("Incorrect character in input square.");
         checkrange (((int) square[i][j]), 0, (size - 1),
	    "Value range");
	 }
      }

   /*  Check the status of the loaded square.                         */
   isreduced = 1;
   /*  Check for possible reduced Latin Square by examining the first
       row and first column to determine if the values are in order.  */
   for (i = 0; i < size; i++)
      if ((square[0][i] != ((char) i)) || (square[i][0] != ((char) i)))
         {
         isreduced = 0;
	 break;
	 }

   /*  Call the validcheck function to check all of the rows.  If
       all the rows are valid, check all the columns.                 */
   islatin = validcheck (square, 1, size);
   if (islatin)
      islatin = validcheck (square, 0, size);

   /*  Print the result of the tests.                                 */
   result = "No";
   if (islatin)
      {
      result = "Not Reduced";
      if (isreduced)
         result = "Reduced";
      }
   (void) puts (result);
   }
	 
return (0);
}
