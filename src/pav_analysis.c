#include <math.h>
#include "pav_analysis.h"
#include <stdlib.h>

float compute_power(const float *x, unsigned int N) {
    float pot=1e-12;
    for(unsigned int i=0; i<N; i++){
        pot+=x[i]*x[i];
    }
    return 10*log10(pot/N);
}

float compute_am(const float *x, unsigned int N) {
    float amp=1e-12;
    for(unsigned int i=0; i<N; i++){
        amp+=sqrt(x[i]*x[i]);
    }
    return amp/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float zcr = 1e-12;
    int sign;
    if (x[0]>0)
        sign = 1;
    else
        sign = -1;
    for(unsigned int i=1; i<N; i++){
        if (x[i]*sign<0){ 
        zcr++;
        sign=sign*-1;
        }
    }
    return zcr*fm/(2*(N-1));
}
