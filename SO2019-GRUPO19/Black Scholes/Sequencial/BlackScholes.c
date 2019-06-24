#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double max(double a){

    if(a>0)
	return a;
    else
	return 0;

}



int main(){

FILE *f;
f = fopen("entrada_blackscholes.txt", "r");
srand(time(NULL));

double S, E, r, sigma, T, t, * trials, media=0, variancia = 0, stddev, intervalo, minimo, maximo;
int M,i;

fscanf(f,"%lf", &S);
fscanf(f,"%lf", &E);
fscanf(f,"%lf", &r);
fscanf(f,"%lf", &sigma);
fscanf(f,"%lf", &T);
fscanf(f,"%d", &M);

trials = malloc(sizeof(double)*M);

fclose(f);


for(i=0;i<M;i++){
    t = S*pow(M_E,(r - sigma*sigma/2)*T + sigma*sqrt(T)*rand()/(double)RAND_MAX);
    trials[i] = pow(M_E,(-r)*T)*max(t-E);
    media = media + trials[i];
}

media = media/(double)M;
    printf("\nmedia = %lf\n",media);

for(i = 0 ; i < M; i++){
    variancia = variancia + ((trials[i]-media)*(trials[i]-media));
}

variancia = variancia/(double)M;
stddev = sqrt(variancia);

intervalo = (1.96*stddev)/(double)(sqrt(M));
minimo = media - intervalo;
maximo = media + intervalo;

	printf("S        %0.lf\n",S);
	printf("E        %0.lf\n",E);
	printf("r        %0.lf\n",r);
	printf("sigma    %0.lf\n",sigma);
	printf("T        %0.lf\n",T);
	printf("M        %d\n",M);

	
	printf("Intervalo: (%lf,%lf)\n", minimo,maximo);
free(trials);

return 0;

}
