#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum,sumsd,sumgm=A[0],sumhm;
    for (int i=0;i<N;i++){
        sum+=A[i];
    }
    B[0]=sum/N;
    
    for (int i=0;i<N;i++){
        sumsd+=pow(A[i]-B[0],2);
    }
    B[1]=sqrt(sumsd/N);
    
    for (int i=1;i<N;i++){
        sumgm*=A[i];
    }
    B[2]=pow(sumgm,1.0/N);
    
    for (int i=0;i<N;i++){
        sumhm+=1/A[i];
    }
    B[3]=N/sumhm;
    
    B[4]=A[0];B[5]=A[0];
    for (int i=1;i<N;i++){
        if(A[i]>B[4]) B[4]=A[i];
        if(A[i]<B[5]) B[5]=A[i];
    }
}