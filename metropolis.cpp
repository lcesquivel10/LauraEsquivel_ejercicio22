#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <random>

using namespace std;

const int size =100000 ; // entero cte tamaño 100 = N=100
float x[size]={} ; // lista vacia de tamaño size

const float xmax=10;

float f(float t)
{
  if (0<t && xmax>t )
  {
    return exp(t);
  }
  else 
  {
    return 0.0;
  }

}

default_random_engine semilla( time (0)); // defini la semilla como random
normal_distribution<float> normal(0.0,1.0); // define tipo distribucion normal de un flotante entre 0 y 1


int main ( ) // funcion que se corre
{
srand48(time(0));
x[0]= drand48()*xmax; // drand48 es un numero aleatorio de 0 a 1

  float xnew,r,alpha;// dice que r alpha y xnew son flotantes
  

  for ( int i =1; i<size; i++ )
{
  xnew= x[i]+ normal(semilla); // metropolis
    r= f(xnew)/f(x[i]);// r = f xnew/ xold
    alpha=drand48();
 if (alpha<r)
 {
x[i+1]= xnew;
 }
 else
 {
   x[i+1]=x[i];
 }
}
 for( int i = 0; i < size; i++)
 {
   cout << x[i] << " " << endl;
   }
  return 0;
}
