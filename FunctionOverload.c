/* Supraincarcarea functiilor */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
typedef struct Strucutra
{
    float a;
    float b;
    
}structura;

int addi(int a, int b) {
    return a + b;
}

char *adds(char *a, char *b) {
    char *res = malloc(strlen(a) + strlen(b) + 1);
    strcpy(res, a);
    strcat(res, b);
    return res;
}

float addf(float a , float b)
{
    return a + b;
}

structura addStruct(structura a, structura b)
{
     structura c;
     c.a = a.a + b.a;
     c.b = a.b + b.b;
    
    return  c;
    
}


int adunare(int nr_argumente, ...)
{
    va_list valist;
    int i = 0;
    int sum;
    
    /* initialize valist for num number of arguments */
   va_start(valist, nr_argumente);
   
   
      /* access all the arguments assigned to valist */
   for (i = 0; i < nr_argumente; i++) {
      sum += va_arg(valist, int);
      }
      
      /* clean memory reserved for valist */
   va_end(valist);

   return sum;
    
}

#define add(a, b) _Generic(a, int: addi, char*: adds, float: addf,structura: addStruct)(a, b)




int main(void) {
    int a = 1, b = 2;
    printf("%d\n", add(a,b)); // 3

    char *c = "hello ", *d = "world";
    printf("%s\n", add(c,d)); // hello world
    
    float f = 13.4; 
    float g = 12.3;
    printf("%f", add(f,g));
    
    
    structura s1,  s2, s3;
    s1.a = 5.1;
    s1.b = 6.3;
    
    s2.a = 10.1;
    s2.b = 12.12;
    
    s3 = add(s1,s2);
    
    printf("\ns3.a = %f s3.b = %f",s3.a,s3.b);
    
    int ad = adunare(14,2,3,4,5,6,12,13,15,22,13,23,13,10,10);
    
    printf("\nSuma functiei cu argumente variabile: %d",ad);

    return 0;
}
