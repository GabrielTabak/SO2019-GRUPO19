#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<unistd.h> 
#include<gmp.h>


int main(){

//coloca a precisao
mpf_set_default_prec(100000);


mpf_t pi, aux, Um, aux1, aux2, ds, Quatro, Dois;

mpf_init(pi); mpf_init(Um);
mpf_init(aux);
mpf_init(ds); mpf_init(aux1); 
mpf_init(aux2); mpf_init(Quatro);
mpf_init(Dois);

long long int i;

//inicializa 
mpf_set_ui(pi,0);
mpf_set_ui(ds,16);
mpf_set_ui(Um,1);
mpf_set_ui(Dois,2);
mpf_set_ui(Quatro,4);

for(i=0;i<100000;i++){

    mpf_pow_ui(aux, ds , i);
    mpf_div(aux,Um,aux);
    
    mpf_div_ui(aux1, Quatro, 8*i + 1);
    mpf_div_ui(aux2, Dois, 8*i + 4);
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 5);	
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 6);
    mpf_sub(aux1, aux1, aux2);
    

/*
aux = 1/pow(16,n);

printf("\n aux = %.13lf \n",aux);


pi += aux*(4/(8*n + 1) - 2/(8*n + 4) - 1/(8*n + 5) - 1/(8*n + 6));

printf("\n pi = %.13lf \n\n\n",pi);
*/

    mpf_mul(aux1, aux, aux1);
    mpf_add(pi, pi, aux1);

}



    printf("\n pi = ");
    mpf_out_str(stdout,10,0,pi);
    printf("\n\n");



mpf_clear(pi); mpf_clear(aux); mpf_clear(Um);mpf_clear(ds); mpf_clear(aux1); mpf_clear(aux2); mpf_clear(Quatro);mpf_clear(Dois);


return 0;

}
