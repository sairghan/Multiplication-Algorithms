#include<stdio.h>

#include<string.h> 

#define M 260

int N;

struct multiplyTab{
    int upper;
    int lower;
};

struct multiplyTab node[M][M];
static char string1[M];
static char string2[M];
 
static char string1new[M];
static char string2new[M];
 
int sum;
int m;

 int recursiveAdd(int i, int j) {
 
if(j < 0 || i >= N)
    return sum;
    int val;
       if( m % 2 ){
        val = node[i][j].upper;
        j = j - 1;
    }
 else{
        val = node[i][j].lower;
        i = i + 1;
     }
  ++m;

 sum = sum + val;
 recursiveAdd(i,j);
 return sum;

   }


int main() {

 int len1 = 0;
 int len2 = 0;
 
 int f1 = 0, f2 = 0; //flags

while (gets(string1)) {
            gets(string2);
  
 if(string1[0] == '-')
  {
   
   f1 = 1;
   len1 = strlen(string1) - 1;
  
   for ( int i = 1; i <= len1; i++ )
       
        string1new[i-1]= string1[i];
}

        
 if (string1[0]!='-')
 {
    
   len1 = strlen(string1);
   for ( int i = 0; i <= len1; i++ )
   string1new[i] = string1[i];
}

 if(string2[0]== '-')
  {
   f2 = 1;
   len2 = strlen(string2)-1;
   for ( int i = 1; i <= len2; i++ )
       
       string2new[i-1]= string2[i]; 
       
}
          
  if (string2[0]!='-')
  {
  	
  len2 = strlen(string2);
   for ( int i = 0; i < len2; i++ )
  string2new[i]=string2[i]; 
}
  
if (len1 > len2) {

     N = len1;

    int shift = len1 - len2;

     for( int i = len1 - 1; i >= 0; --i ) 

          string2new[i + shift] = string2new[i];

      for(int j = 0; j < shift; ++j) 

          string2new[j] = '0';

}

else if (len2 > len1) {

   N = len2;

   int shift = len2 - len1;
 
            for (int i = len2-1; i>=0; --i) 

             string1new[i+shift]= string1new[i];

             for (int j=0; j < shift; ++j) 

              string1new[j] = '0';

 }

else 

N = len1;



int k = N-1;

 

for(int i=0; string2new[i];i++) {

      for(int j=0; string2new[j];++j) {

            int num1 = string1new[k] - '0';

            int num2 = string2new[j] - '0';

           

            int multiply = num1 * num2;

            node[j][k].upper = multiply/10;

            node[j][k].lower =multiply%10;

       }

 --k;

  }

 

int upperResult[N];

 int i=N-1;

for (; i>=0; --i) {

       sum=0;

        m=1;

       upperResult[i] = recursiveAdd( 0, i);

 }

 

 int lowerResult[N];

i=0; 

 for(; i<N; ++i) {

      sum =0;

      m=0;

      lowerResult[i] = recursiveAdd(i, N-1);

  }


  int finalResult[N + N];
  i = 0;

  for(; i < N; ++i) 

         finalResult[i]=upperResult[i];

 
 for(k=0; i < N + N; ++i, ++k) 

      finalResult[i]=lowerResult[k];

  

 

  for(int i = N + N -1; i>=0; --i) {

     if(finalResult[i]>9) {

         finalResult[i-1]= finalResult[i-1]+ finalResult[i]/10;

          finalResult[i] = finalResult[i]%10;

     }
 

  }

   for(i=0; i < N + N; ++i) 


         if(finalResult[i])  break;
   
  
bool zero = true;
   if (f1==0 && f2==0)
   for(; i< N + N; ++i) {
     
     printf("%d", finalResult[i]);
     zero = false;

    }
    
    if (f1==1 && f2==1)
   for(; i< N + N; ++i) {
     ;
     printf("%d", finalResult[i]);
     zero = false;

    }
    if (f1 !=f2){
    
    printf("-");
   for(; i< N+N; ++i) {
     
     printf("%d",finalResult[i]);
     zero = false;
}
    }
if( zero)
  printf("0");
  printf("\n");
}
return 0;
}


