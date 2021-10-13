#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct {
float x;
float y;
} point ;

typedef struct {
float x1, y1, x2, y2;
} line ;
 
float dist( line linia) {
return(sqrt((linia.x1 - linia.x2)*(linia.x1 - linia.x2) + (linia.y1 - linia.y2)*(linia.y1 - linia.y2)));
}
 
int main(){
 
float d;
line linia;
 

printf("The coordinates of the first point is: ");
scanf("%f %f",&linia.x1,&linia.y1);
 

printf("\nThe coordinates of the second point is: ");
scanf("%f %f",&linia.x2,&linia.y2);
 

printf("\nThe length of the line is %f\n", dist(linia));
 
exit (0);
}