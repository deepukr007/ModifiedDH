#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{
char str[100] ="";
char polytemp[100]="";
int p = 5;

int a[10] = {0,0,0,0,0,1,1,0,1,0};
int alice_len=0;
int alice[10] ;
int alice_freq = 8 ;
double Xa=0;
double Ka=0;
double alice_m =0;

char poly[100]="";



int b[10] = {0,0,0,1,0,0,1,1,1,0};
int bob_len=0;
int bob[10] ;
int bob_freq = 9 ;
double Xb=0;
double Kb=0;
double bob_n =0;


for (int i =10 ; i>0; i--)
{
   if(a[i]==1)
   {
     alice[alice_len] = (9-i);
     alice_len++;

   }
   
}


for (int i =10 ; i>0; i--)
{
   if(b[i]==1)
   {

     bob[bob_len] = (9-i);
     bob_len++;
     
   }
   
}

for ( int j = alice_len-1; j >=0 ; j--)
{

  alice_m = alice_m + pow(alice_freq , alice[j]);
  sprintf(str , "%d" , alice[j]); 
  strcat(polytemp , "x^");
  strcat(polytemp , str);
  strcat(polytemp, "+");

}

strncpy(poly, polytemp , (strlen(polytemp)-1));
printf("Alice\nPolynomial m=%s\n" , poly);
strcpy(polytemp,""); 
strcpy(poly,""); 



for ( int k =bob_len-1; k >= 0; k--)
{
  bob_n = bob_n + pow(bob_freq , bob[k]);
  sprintf(str , "%d" , bob[k]); 
  strcat(polytemp , "x^");
  strcat(polytemp , str);
  strcat(polytemp, "+");

}

strncpy(poly, polytemp , (strlen(polytemp)-1));
printf("Bob\nPolynomial n=%s\n" , poly);
strcpy(polytemp,""); 
strcpy(poly,""); 
printf("--------------------------\n");

printf("Alice Agrees to Pulic key %d\n" , p);
printf("Bob Agrees to Pulic key %d\n" , p);

printf("\nAlice extracts a random frequency %d\n" , alice_freq);
printf("Bob extracts a random frequency %d\n" , bob_freq);
printf("--------------------------\n");

Xa = alice_m * p; 
printf("Alice:\nm=");
printf("%.0lf\t\t" , alice_m);
printf("Xa=%.0lf\n\n" , Xa);

Xb = bob_n * p; 
printf("BOB:\nn=");
printf("%.0lf\t" , bob_n);
printf("Xb=%.0lf\n\n" , Xb);

printf("\nKeys are exchanged\n\n");


Ka = Xb * alice_m * log10(p-1);
Kb = Xa * bob_n * log10(p-1);
printf("Ka=%.0lf\n" , Ka); 
printf("Kb=%.0lf\n" , Kb); 



}
