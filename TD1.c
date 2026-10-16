#include <stdio.h>
#include <math.h>

int Fibn(int n){
    if(n==0 || n==1){return n;}
    return (Fibn(n-1)+Fibn(n-2));
}



unsigned long long DPF(int n, unsigned long long memo[]){
    if (memo[n] != -1){return memo[n];}
    if (n<=1){memo[n]=n;}
    else{memo[n]=DPF(n-1,memo)+DPF(n-2,memo);}
    return memo[n];
}


int prems_n(int n) {
    if (n < 2) {
        return 0;
    }
    int premier[n];
    int count = 0;
    for (int i = 2; i <= n; i++) {
        int racine = (int)sqrt(i);
        int prem =1;

        for (int j = 0; j < count && premier[j] <= racine; j++) {
            if (i % premier[j] == 0) {
                prem = 0;
                break;
            }
        }

        if (prem == 1) {
            premier[count++] = i;
        }
    }

    return count;
}


int prems_dyn(int n) {
    if (n < 2) {
        return 0;
    }
    int premiers[n+1];
    for (int i = 0; i <= n; i++) {
        premiers[i] = 1;
    }
    int compt = 0;
    for (int i = 2; i <= n; i++) {
        if (premiers[i]!=0) {
            compt++;
            int k=i;
            while(i*k<=n){
                premiers[i*k]=0;
                k++;
            }
        }
    }

    return compt;
}

int main(){
    prems_n(10);
    printf("%i",prems_dyn(100));
}