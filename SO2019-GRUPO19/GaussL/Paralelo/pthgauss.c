#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<pthread.h>
#include<gmp.h>
#define limite 10000

mpf_t a, b, t, p, pi, an, bn, tn, pn, aux;

pthread_t t1, t2, t3, t4;

long long int n = 1;
int fim = 0;


void * thread1(void * k){//faz o calculo do an

    long long int n1 = 0;

    while(1){
	
	if(n1 != n){

	    mpf_add(an, a, b);
	    mpf_div_ui(an, an,2);///an = (a+b)/2;

	    mpf_sub(tn,a,an);
	    mpf_pow_ui(tn,tn,2);
	    mpf_mul(tn,p,tn);
	    mpf_sub(tn,t,tn);
	    //tn = t - p*pow(a-an,2);
	    fim++;		
	    n1 = n;
	}
    if(n1 == limite)
	pthread_exit(NULL);

    }

}



void * thread2(void * k){//faz o calculo do bn

    long long int n1 = 0;

    while(1){

	if(n1 != n){
	
	    mpf_mul(bn,a,b);
	    mpf_sqrt(bn, bn);//bn = sqrt(a*b);
	    n1 = n;
	    fim++;
	}
        if(n1 == limite)
	pthread_exit(NULL);
    }
}


void * thread3(void * k){//faz o calculo do pn

    long long int n1 = 0;

    while(1){	

	if(n1 != n){
	    mpf_mul_ui(pn,p,2);//pn = 2*p;
	    n1 = n;
	    fim++;

	}
    if(n1 == limite)
	pthread_exit(NULL);
    }

}



void * thread4(void * k){//atualiza os a, b, t, p

    while(1){
	    if(fim == 3){
	        mpf_set(a,an); mpf_set(b,bn); mpf_set(t,tn); mpf_set(p,pn);
	        //a = an; b = bn; t = tn; p = pn;
	        fim = 0;
	        n++;
	    }
    if(n == limite)
	pthread_exit(NULL);
    }

}


int main(){

//setando a precisao
mpf_set_default_prec(100000);

//inicia as variaveis para big numbers
mpf_init(a); mpf_init(b); mpf_init(t); mpf_init(p); mpf_init(pi); mpf_init(an);
mpf_init(bn); mpf_init(tn); mpf_init(pn);mpf_init(aux);

 
//da os valores para as variaveis iniciais
mpf_set_ui(a,1); mpf_set_d(t,0.25); mpf_set_ui(p,1); 
mpf_set_d(b,1);

//b = 1/sqrt(2)
mpf_sqrt_ui(b,2);
mpf_div(b,a,b);


pthread_create(&t1,NULL,thread1,NULL);
pthread_create(&t2,NULL,thread2,NULL);
pthread_create(&t3,NULL,thread3,NULL);
pthread_create(&t4,NULL,thread4,NULL);



pthread_join(t4,NULL);


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











