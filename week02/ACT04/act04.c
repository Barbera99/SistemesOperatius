#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct {
float x;
float y;
} point ;

typedef struct {
point inici;
point fi;
} line ;
 
float dist( line linia) {
return(sqrt((linia.inici.x - linia.fi.x)*(linia.inici.x - linia.fi.x) + (linia.inici.y - linia.fi.y)*(linia.inici.y - linia.fi.y)));
}
 
int main(){
 
float d;
line linia;
 

printf("The coordinates of the first point is: ");
scanf("%f %f",&linia.inici.x,&linia.inici.y);
 

printf("\nThe coordinates of the second point is: ");
scanf("%f %f",&linia.fi.x,&linia.fi.y);
 

printf("\nThe length of the line is %f\n", dist(linia));
 
exit (0);
}