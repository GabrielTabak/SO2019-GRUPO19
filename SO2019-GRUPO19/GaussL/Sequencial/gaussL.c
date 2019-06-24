#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h> 
#include<gmp.h>


//10 a 9 iteracoes

int main(){

//setando a precisao
mpf_set_default_prec(100000);

mpf_t a, b, t, p, pi, an, bn, tn, pn, aux;

//inicia as variaveis para big numbers
mpf_init(a); mpf_init(b); mpf_init(t); mpf_init(p); mpf_init(pi); mpf_init(an);
mpf_init(bn); mpf_init(tn); mpf_init(pn);mpf_init(aux);

//da os valores para as variaveis iniciais
mpf_set_ui(a,1); mpf_set_d(t,0.25); mpf_set_ui(p,1); 
mpf_set_d(b,1);

//b = 1/sqrt(2)
mpf_sqrt_ui(b,2);
mpf_div(b,a,b);


long long int n;

for(n=1;n<10000;n++){

    mpf_add(an, a, b);
    mpf_div_ui(an, an,2);///an = (a+b)/2;

    mpf_mul(bn,a,b);
    mpf_sqrt(bn, bn);//bn = sqrt(a*b);
    
    mpf_sub(tn,a,an);
    mpf_pow_ui(tn,tn,2);
    mpf_mul(tn,p,tn);
    mpf_sub(tn,t,tn);
    //tn = t - p*pow(a-an,2);

    mpf_mul_ui(pn,p,2);//pn = 2*p;

    mpf_set(a,an); mpf_set(b,bn); mpf_set(t,tn); mpf_set(p,pn);
    //a = an; b = bn; t = tn; p = pn;
    


}


    mpf_mul_ui(aux, tn, 4);
    mpf_add(pi,an,bn);
    mpf_pow_ui(pi,pi,2);
    mpf_div(pi,pi,aux);
    //pi = pow((an+bn),2)/(4*tn);

    printf("\n pi = ");
    mpf_out_str(stdout,10,0,pi);
    printf("\n\n");

    mpf_clear(a); mpf_clear(an);mpf_clear(b);mpf_clear(bn);mpf_clear(t);mpf_clear(tn);
    mpf_clear(pi); mpf_clear(p); mpf_clear(pn);

return 0;
}
