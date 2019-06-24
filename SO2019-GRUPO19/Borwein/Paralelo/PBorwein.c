#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<pthread.h>
#include<gmp.h>
#define limite 100000

pthread_t t1, t2, t3, t4;// aux1, aux2, aux,
mpf_t  n, Um, ds, Quatro, Dois;
mpf_t pi1, pi2, pi3, pi4;

void * thread1(void * k){//faz o calculo da primeira parte da soma

long long int i;
    mpf_t aux, aux1, aux2;    
    mpf_init(aux);mpf_init(aux1);mpf_init(aux2);

for(i=0*limite;i<0.25*limite - 1;i++){

    mpf_pow_ui(aux, ds , i);
    mpf_div(aux,Um,aux);//aux = 1/pow(16,n);
    
    mpf_div_ui(aux1, Quatro, 8*i + 1);//pi += aux*(4/(8*n + 1) - 2/(8*n + 4) - 1/(8*n + 5) - 1/(8*n + 6));
    mpf_div_ui(aux2, Dois, 8*i + 4);
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 5);	
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 6);
    mpf_sub(aux1, aux1, aux2);

    mpf_mul(aux1, aux, aux1);
    mpf_add(pi1, pi1, aux1);
}

mpf_clear(aux); mpf_clear(aux1); mpf_clear(aux2);
	pthread_exit(NULL);

}

void * thread2(void * k){//faz o calculo da segunda parte da soma

    mpf_t aux, aux1, aux2;
    mpf_init(aux);mpf_init(aux1);mpf_init(aux2);

long long int i;

for(i=0.25*limite;i<0.5*limite - 1;i++){

    mpf_pow_ui(aux, ds , i);
    mpf_div(aux,Um,aux);//aux = 1/pow(16,n);
    
    mpf_div_ui(aux1, Quatro, 8*i + 1);//pi += aux*(4/(8*n + 1) - 2/(8*n + 4) - 1/(8*n + 5) - 1/(8*n + 6));
    mpf_div_ui(aux2, Dois, 8*i + 4);
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 5);	
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 6);
    mpf_sub(aux1, aux1, aux2);

    mpf_mul(aux1, aux, aux1);
    mpf_add(pi2, pi2, aux1);
}

mpf_clear(aux); mpf_clear(aux1); mpf_clear(aux2);
	pthread_exit(NULL);

}

void * thread3(void * k){//faz o calculo da terceira parte da soma

long long int i;
    mpf_t aux, aux1, aux2;
    mpf_init(aux);mpf_init(aux1);mpf_init(aux2);


for(i=0.5*limite;i<0.75*limite - 1;i++){

    mpf_pow_ui(aux, ds , i);
    mpf_div(aux,Um,aux);//aux = 1/pow(16,n);
    
    mpf_div_ui(aux1, Quatro, 8*i + 1);//pi += aux*(4/(8*n + 1) - 2/(8*n + 4) - 1/(8*n + 5) - 1/(8*n + 6));
    mpf_div_ui(aux2, Dois, 8*i + 4);
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 5);	
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 6);
    mpf_sub(aux1, aux1, aux2);

    mpf_mul(aux1, aux, aux1);
    mpf_add(pi3, pi3, aux1);
}

mpf_clear(aux); mpf_clear(aux1); mpf_clear(aux2);
	pthread_exit(NULL);

}

void * thread4(void * k){//faz o calculo da quarta parte da soma

long long int i;
    mpf_t aux, aux1, aux2;
    mpf_init(aux);mpf_init(aux1);mpf_init(aux2);


for(i=0.75*limite;i<limite;i++){

    mpf_pow_ui(aux, ds , i);
    mpf_div(aux,Um,aux);//aux = 1/pow(16,n);
    
    mpf_div_ui(aux1, Quatro, 8*i + 1);//pi += aux*(4/(8*n + 1) - 2/(8*n + 4) - 1/(8*n + 5) - 1/(8*n + 6));
    mpf_div_ui(aux2, Dois, 8*i + 4);
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 5);	
    mpf_sub(aux1, aux1, aux2);
    mpf_div_ui(aux2, Um, 8*i + 6);
    mpf_sub(aux1, aux1, aux2);

    mpf_mul(aux1, aux, aux1);
    mpf_add(pi4, pi4, aux1);


}

mpf_clear(aux); mpf_clear(aux1); mpf_clear(aux2);
	pthread_exit(NULL);

}


int main(){


mpf_set_default_prec(100000);


mpf_init(pi1);mpf_init(pi2);mpf_init(pi3);mpf_init(pi4);
mpf_init(Um); mpf_init(n);
mpf_init(ds); mpf_init(Quatro);
mpf_init(Dois);


//inicializa 
mpf_set_ui(ds,16);
mpf_set_ui(Um,1);
mpf_set_ui(Dois,2);
mpf_set_ui(Quatro,4);


pthread_create(&t1,NULL,thread1,NULL);
pthread_create(&t2,NULL,thread2,NULL);
pthread_create(&t3,NULL,thread3,NULL);
pthread_create(&t4,NULL,thread4,NULL);


pthread_join(t4,NULL);

    mpf_add(pi1, pi1, pi2);
    mpf_add(pi1, pi1, pi3);
    mpf_add(pi1, pi1, pi4);


    printf("\n pi = ");
    mpf_out_str(stdout,10,0,pi1);
    printf("\n\n");


mpf_clear(pi1);mpf_clear(pi2);mpf_clear(pi3);mpf_clear(pi4);

mpf_clear(Um);mpf_clear(ds); mpf_clear(Quatro);mpf_clear(Dois);


return 0;
}




