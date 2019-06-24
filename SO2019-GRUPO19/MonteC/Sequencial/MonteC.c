#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<gmp.h>
#include<time.h>


int main(){

long long int i, limite = 100000000;

mpf_set_default_prec(100000);
mpf_t dentro, total;

mpf_init(dentro);mpf_init(total);

mpf_set_ui(total,limite);

srand(time(NULL));

double X, Y;

for(i=0;i<limite;i++){

    X = ((double)rand()/(double)RAND_MAX);;
    Y = ((double)rand()/(double)RAND_MAX);;
    //printf("\n%lf   %lf\n",X,Y);
 
    if( X*X + Y*Y <= 1)
	mpf_add_ui(dentro,dentro,1);

}


mpf_mul_ui(dentro,dentro,4);
mpf_div(dentro,dentro,total);

printf("\n pi = ");
mpf_out_str(stdout,10,0,dentro);
printf("\n\n");


mpf_clear(total); mpf_clear(dentro);

return 0;

}
