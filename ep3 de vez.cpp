#include <iostream>
#define TM 2021

using namespace std;

int ctdig(double i) {
    int ret=0;

    while (i>1){
        ret++;
        i /=10;
    }
    return ret;
}

int soma(int *a, int tamA, int *b, int tamB){
    int ref, res;

    int s[TM];
    
    if(tamA > tamB) ref = tamA;
    if(tamB > tamA) ref = tamB;
    if(tamA == tamB) ref = tamA+1;

    for (int i = 1; i <= ref; i++) {

         if( (a[i]+b[i])<10 ){
            s[i] = (a[i]+b[i]);
        }

        if( (a[i]+b[i])>=10 ){             //isso é muito mal feito pqp
            s[i] = (a[i]+b[i])%10;         //eu não sei como funciona
            s[i+1] = s[i]+1;               //e acho que se por ventura funcionar 
        }                                  //o prof vai mandar apagar
    }

    return(*s);
}

int criaNumerao(int n, int *num){
    int dig = ctdig(n);

    for(int i = dig; i>0 ; i--){                //aqui acontece as 
       num[i] = n%10;                           //as aribuições de 
                                                //de valores
       n = n/10;
   }

  return(dig);

}

void imprimeNumerao(int *num, int tamNum){

    for(int i = 1; i<=tamNum;i++){
        cout<<num[i]<<"  ";
    }

}


int main(){

    long int n, m;
    int num[TM], mum[TM];
    int dig, Dig, lote;

    //double x = 10;

    cout<<"digite o numero gigante: ";
    cin>>n;
    cout<<"digite outro numero enorme: ";
    cin>>m;

    dig = ctdig(n);
    Dig = ctdig(m);

    if(dig > Dig) lote = dig;
    if(Dig > dig) lote = Dig;
    if(dig == Dig) lote = dig+1;

    int resu[lote];

    resu = soma(num, dig, mum, Dig);

    imprimeNumerao(resu, lote);
    

    /*dig = ctdig(n);

   for(int i = dig; i>0 ; i--){                //aqui acontece as 
       num[i] = n%10;                           //as aribuições de 
                                                //de valores
       n /=10;
   }

   Dig = ctdig(m);

   for (int i = Dig; i > 0 ; i--){
       mum[i]=m%10;
       m /=10;
   }
   
   if(n<0) num[0] = -1;
   if(n>0) num[0] = 0;
   if(m<0) mum[0] = -1; 
   else mum[0]=0;*/


    //cout<<"\n\n"<<dig<<"\n\n";

    //imprimeNumerao(num, dig);

   /*int fin = ctdig(soma(num, dig, mum, Dig));

   int Soma[TM] = soma(num, dig, mum, Dig);

   imprimeNumerao(Soma, fin);*/
    
    
    
    //return 0;


}