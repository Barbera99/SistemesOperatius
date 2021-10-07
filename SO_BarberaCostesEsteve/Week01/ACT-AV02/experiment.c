#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

/*
Funcio que retorna la area d'un cuadrat de costat 20.0
*/
double calcul_area(){
	double c = 20.0;
	double area = c * c;
  return(area);
}

/*
Aquesta funcio retorna el temps en nanosegons
*/
long nanosec(struct timeval t){
  return((t.tv_sec*1000000+t.tv_usec)*1000);
}

int main(){
  int i,j,res;
  long N_iterations=1000000;
  float avgT1, avgT2;
  struct timeval t1, t2, hora;
  
// Obtenim l'hora actual
  res=gettimeofday(&t1,NULL); 
// Comprovem que s'ha pogut obtenir l'hora correctament
  assert(res==0);

// Fem un bucle per a obtenir la hora 1.000.000 de vegades
  for (i=0;i<N_iterations; i++){
	res=gettimeofday(&hora,NULL);
	assert(res==0);
  }
// Tornem a obtenir l'hora actual
  res=gettimeofday(&t2,NULL);   
// Tornem a comprovar que s'ha pogut obtenir correctament
  assert(res==0);

// Calculem la diferencia entre el primer i el segon temps (en nanosegons)
  avgT1 = (nanosec(t2) - nanosec(t1))/(N_iterations*1.0);
  
// Tornem a obtenir la hora actual
  res=gettimeofday(&t1,NULL);  
  
// Tornem a comprovar que s'ha pogut obtenir correctament
  assert(res==0);
  
// Fem un bucle cridant a la funcio calcul_area()
  for (i=0;i<N_iterations; i++){
    j=calcul_area(i);
  }
  
  res=gettimeofday(&t2,NULL);
  assert(res==0);

  avgT2 = (nanosec(t2) - nanosec(t1))/(N_iterations*1.0);
  
  printf("Temps per a obtenir l'hora: %f\n", avgT1);
  printf("Temps per a fer operacions %f\n", avgT2);

}
