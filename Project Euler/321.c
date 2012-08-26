#include "problems.h"
#include "321.h"

#include "helpers.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define M(n) ((n * n) + 2 * n)
#define T(n) (n * (n + 1) / 2)

char *desc321()
{
    return "A horizontal row comprising of 2n + 1 squares has n red counters placed at one end and n blue counters at the other end, being separated by a single empty square in the centre. For example, when n = 3.\n\n"	
	"A counter can move from one square to the next (slide) or can jump over another counter (hop) as long as the square next to that counter is unoccupied.\n\n"
	"Let M(n) represent the minimum number of moves/actions to completely reverse the positions of the coloured counters; that is, move all the red counters to the right and all the blue counters to the left.\n\n"
	"It can be verified M(3) = 15, which also happens to be a triangle number.\n\n"	
	"If we create a sequence based on the values of n for which M(n) is a triangle number then the first five terms would be:\n\n"
	"1, 3, 10, 22, and 63, and their sum would be 99.\n\n"
	"Find the sum of the first forty terms of this sequence.";
}

int run321(char *output)
{
  /*
   { 0, 1, 2 }
   { 0, 2, 1 }
   { 1, 2, 0 }
   { 2, 1, 0 }
   M(1) = 3
   
   { 0, 0, 1, 2, 2 }
   { 0, 0, 2, 1, 2 }
   { 0, 1, 2, 0, 2 }
   { 1, 0, 2, 0, 2 }
   { 2, 0, 1, 0, 2 }
   { 2, 0, 2, 0, 1 }
   { 2, 0, 2, 1, 0 }
   { 2, 1, 2, 0, 0 }
   { 2, 2, 1, 0, 0 }
   M(2) = 8
   
   { 0, 0, 0, 1, 2, 2, 2 }
   { 0, 0, 0, 2, 1, 2, 2 }
   { 0, 0, 1, 2, 0, 2, 2 }
   { 0, 1, 0, 2, 0, 2, 2 }
   { 0, 2, 0, 1, 0, 2, 2 }
   { 0, 2, 0, 2, 0, 1, 2 }
   { 0, 2, 0, 2, 0, 2, 1 }
   { 0, 2, 0, 2, 1, 2, 0 }
   { 0, 2, 1, 2, 0, 2, 0 }
   { 1, 2, 0, 2, 0, 2, 0 }
   { 2, 1, 0, 2, 0, 2, 0 }
   { 2, 2, 0, 1, 0, 2, 0 }
   { 2, 2, 0, 2, 0, 1, 0 }
   { 2, 2, 0, 2, 1, 0, 0 }
   { 2, 2, 1, 2, 0, 0, 0 }
   { 2, 2, 2, 1, 0, 0, 0 }
   M(3) = 15
   
   { 0, 0, 0, 0, 1, 2, 2, 2, 2 }
   { 0, 0, 0, 0, 2, 1, 2, 2, 2 }
   { 0, 0, 0, 1, 2, 0, 2, 2, 2 }
   { 0, 0, 1, 0, 2, 0, 2, 2, 2 }
   { 0, 0, 2, 0, 1, 0, 2, 2, 2 }
   { 0, 0, 2, 0, 2, 0, 1, 2, 2 }
   { 0, 0, 2, 0, 2, 0, 2, 1, 2 }
   { 0, 0, 2, 0, 2, 1, 2, 0, 2 }
   { 0, 0, 2, 1, 2, 0, 2, 0, 2 }
   { 0, 1, 2, 0, 2, 0, 2, 0, 2 }
   { 1, 0, 2, 0, 2, 0, 2, 0, 2 }
   { 2, 0, 1, 0, 2, 0, 2, 0, 2 }
   { 2, 0, 2, 0, 1, 0, 2, 0, 2 }
   { 2, 0, 2, 0, 2, 0, 1, 0, 2 }
   { 2, 0, 2, 0, 2, 0, 2, 0, 1 }
   { 2, 0, 2, 0, 2, 0, 2, 1, 0 }
   { 2, 0, 2, 0, 2, 1, 2, 0, 0 }
   { 2, 0, 2, 1, 2, 0, 2, 0, 0 }
   { 2, 1, 2, 0, 2, 0, 2, 0, 0 }
   { 2, 2, 1, 0, 2, 0, 2, 0, 0 }
   { 2, 2, 2, 0, 1, 0, 2, 0, 0 }
   { 2, 2, 2, 0, 2, 0, 1, 0, 0 }
   { 2, 2, 2, 0, 2, 1, 0, 0, 0 }
   { 2, 2, 2, 1, 2, 0, 0, 0, 0 }
   { 2, 2, 2, 2, 1, 0, 0, 0, 0 }
   
   M(1) = 3  +5
   M(2) = 8  +7
   M(3) = 15 +9
   M(4) = 24
   
   M(n) = ( n^2 ) + 2n
   T(m) = ( m^2 + m ) / 2
   
   (n^2) + 2n = (m^2 + m) / 2
   ((n^2) + 2n) * 2 = m^2 + m
   2n^2 + 4n = m^2 + m
   
   M(3) = 15                                                                                                                                                                                        
   M(10): 120
   M(22): 528                                                                       
   M(63): 4095
  */
  
  char buf[2000];
  
  int sum = 0, seqcount = 0, mcount = 0, tmp;
  
  while (seqcount <= 40) {
    
    // ((n * n) + 2 * n)
    /*
     int root = sqrt(n);
     if (root * root == n) {
     return 1;
     }
     return 0;
    */
    
    // 8 * ((n * n) + 2 * n) + 1
    // sqrt
    
    
    if (is_square(8 * M(mcount) + 1)) {
      sprintf(buf, "M(%d): %d\n", mcount, M(mcount));
      append_string(output, buf);
      sum += mcount;
      seqcount++;
    }
    tmp = M(mcount);
    mcount++;
    
    if (M(mcount)< tmp) {
      append_string(output, "Overflow detected.\n");
      break;
    }
    
  }
  
  return sum;}

void append_string(char *existing, char *new)
{
  char tmp[5000];
  sprintf(tmp, "%s%s", existing, new);
  sprintf(existing, "%s", tmp);
}

void swap(int *a, int *b)
{
  *a = *a ^ *b;
  *b = *b ^ *a;
  *a = *a ^ *b;
}

void sprint_row(char *output, int row[], int size)
{
  append_string(output, "{ ");
  char tmp[1] = "0";
  int i;
  for (i = 0; i < size; i++) {
    i == size - 1 ? sprintf(tmp, "%d", row[i]) : sprintf(tmp, "%d, ", row[i]); 
    append_string(output, tmp);
  }
  append_string(output, " }\n");
}