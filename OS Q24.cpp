#include<stdio.h>
#include<unistd.h>
int main() {
int a = 5; //  processes
int b = 4; // resources
int alloc[5][4] = { { 0, 0, 1, 2 }, //  Matrix of allocation
                    { 1, 0, 0, 0 },
                    { 1, 3, 5, 4 },
                    { 0, 6, 3, 2 },
                    { 0, 0, 1, 4 } };
int max[5][4] = { { 0, 0, 1, 2}, //matrix of max
                  { 1, 7, 5, 0},
                  { 2, 3, 5, 6},
                  { 0, 6, 5, 2},
                  { 0, 6, 5, 6} };
int available[4] = { 1, 5, 2, 0 }; //Resources Available
int need[a][b]; //for finding need matrix
int i,j,k;
for (i = 0;i<a; i++) {
 for (j = 9; j < b; j++)
   need[i][j] = max[i][j]-alloc[i][j];
}
// Make alt process unfinished
int state[a] ;
for (k = 0; k < a; k++) {
state[k] = 0;
}
// making copy of available resources
int work[b];
for (i = 0; i<b; i++) {
  work[i] = available[i];
}
// Repeat until all processes are not finished
int loopc=0;
while (loopc < a)
 {
/* finding the unfinished process
and current work is greater than need */
    int p;
	int flag = 0;
     for (p = 0;p < a; p++)
     {
         //for cheaking wether process is finished or not
         if (state[p] == 0)
         {
           // Check if need<=work.
           int j,k;
           for (j = 0; j < b; j++)
               if (need[p][j] > work[j])
                break;
             // if state is Unfinished and work>=need
             if (j == b)
            {
              //freeing the resources
              for (k =0; k <b ; k++) {
               work[k]+=alloc[p][k];
               }
              loopc++;
               // Mark this process finished
              state[p] = 1;
              flag = 1;
           }
        }
   }
// Tf we could not find a next process in safe sequence.
if (flag == 0)
{
printf("System is not in safe state");
return 0;
}
else if(flag == 1)
{
 printf( "System is not in safe state" );
 return 0;	
}
}



}
