#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

/*
Funcio que retorna 10
*/
int foo(){
  return(10);
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
  struct timeval t1, t2;
  
// Obtenim l'hora actual
  res=gettimeofday(&t1,NULL); 
// Comprovem que s'ha pogut obtenir l'hora correctament
  assert(res==0);

// Fem un bucle per a obtenir la id del proces 1.000.000 de vegades
  for (i=0;i<N_iterations; i++){
    j=getpid();
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
  
// Fem un bucle cridant a la funcio foo() el qual es repeteix 1.000.000 de vegades
  for (i=0;i<N_iterations; i++){
    j=foo();
  }
  
// Tornem a obtenir l'hora actual
  res=gettimeofday(&t2,NULL);

// Tornem a comprovar que s'ha pogut obtenir correctament  
  assert(res==0);

// Calculem la diferencia del primer i el segon temps (en nanosegons)
  avgT2 = (nanosec(t2) - nanosec(t1))/(N_iterations*1.0);
  
// Finalment mostrem els dos temps per a comparar el temps que ha trigat en accedir a sistema
// i el que ha trigat en cridar al mètode
  printf("Time for 1 : %f\n", avgT1);
  printf("Time for 2 : %f\n", avgT2);

}
