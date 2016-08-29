#include <cstdlib>
#include <iostream>
#include <random>
#include <cassert>
#include <ccomplex>
#include "lwe.h"
#include "lweparams.h"
#include "lwekey.h"
#include "lwesamples.h"
#include "ringlwe.h"
#include "ringgsw.h"
#include "polynomials.h"
#include "lwebootstrappingkey.h"

using namespace std;

#ifndef NDEBUG
extern const RingLWEKey* debug_accum_key;
extern const LWEKey* debug_extract_key;
extern const LWEKey* debug_in_key;
#endif


EXPORT void ringLweToFFTConvert(RingLWESampleFFT* result, const RingLWESample* source, const RingLWEParams* params){
    const int k = params->k;
    
    for (int i = 0; i <= k; ++i)
	TorusPolynomial_ifft(result->a+i,source->a+i);
}

EXPORT void ringLweFromFFTConvert(RingLWESample* result, const RingLWESampleFFT* source, const RingLWEParams* params){
    const int k = params->k;
    
    for (int i = 0; i <= k; ++i)
	TorusPolynomial_fft(result->a+i,source->a+i);
}



//Arithmetic operations on RingLWE samples
/** result = (0,0) */
EXPORT void ringLweFFTClear(RingLWESampleFFT* result, const RingLWEParams* params){
    int k = params->k;

    for (int i = 0; i <= k; ++i) LagrangeHalfCPolynomial_clear(&result->a[i]);
    result->current_variance = 0.;
}

/** result = (0,mu) */
EXPORT void ringLweFFTNoiselessTrivial(RingLWESampleFFT* result, const TorusPolynomial* mu, const RingLWEParams* params){
    int k = params->k;

    for (int i = 0; i < k; ++i) LagrangeHalfCPolynomial_clear(&result->a[i]);
    TorusPolynomial_ifft(result->b, mu);
    result->current_variance = 0.;
}

/** result = (0,mu) where mu is constant*/
EXPORT void ringLweFFTNoiselessTrivialT(RingLWESampleFFT* result, const Torus32 mu, const RingLWEParams* params){
    const int k = params->k;
    
    for (int i = 0; i < k; ++i) 
	LagrangeHalfCPolynomial_clear(&result->a[i]);
    LagrangeHalfCPolynomial_setTorusConstant(result->b,mu);
    result->current_variance = 0.;
}

/** result = result + sample */
EXPORT void ringLweFFTAddTo(RingLWESampleFFT* result, const RingLWESampleFFT* sample, const RingLWEParams* params);
//Let's postpone this to make sure we actually need it
//{
//    int k = params->k;
//
//    for (int i = 0; i < k; ++i) 
//	AddToLagrangeHalfCPolynomial(&result->a[i], &sample->a[i]);
//    AddToLagrangeHalfCPolynomial(result->b, sample->b);
//    result->current_variance += sample->current_variance; //à revoir//OK si c'est la variance
//}

/** result = result - sample */
EXPORT void ringLweFFTSubTo(RingLWESampleFFT* result, const RingLWESampleFFT* sample, const RingLWEParams* params);

/** result = result + p.sample */
EXPORT void ringLweFFTAddMulZTo(RingLWESampleFFT* result, int p, const RingLWESampleFFT* sample, const RingLWEParams* params);
//Let's postpone this to make sure we actually need it
//{
//    int k = params->k;
//
//    for (int i = 0; i < k; ++i) 
//	torusPolynomialAddMulZTo(&result->a[i], p, &sample->a[i]);
//    torusPolynomialAddMulZTo(result->b, p, sample->b);
//    result->current_variance += (p*p)*sample->current_variance;
//}

/** result = result - p.sample */
EXPORT void ringLweFFTSubMulZTo(RingLWESampleFFT* result, int p, const RingLWESampleFFT* sample, const RingLWEParams* params);


EXPORT void ringLweFFTAddMulRTo(RingLWESampleFFT* result, const LagrangeHalfCPolynomial* p, const RingLWESampleFFT* sample, const RingLWEParams* params) {
    const int k = params->k;
    
    for (int i=0; i<=k; i++)
	LagrangeHalfCPolynomial_addmul(result->a+i,p,sample->a+i);
}

EXPORT void ringLweFFTMulR(RingLWESampleFFT* result, const LagrangeHalfCPolynomial* p, const RingLWESampleFFT* sample, const RingLWEParams* params) {
    const int k = params->k;
    
    for (int i=0; i<=k; i++)
	LagrangeHalfCPolynomial_mul(result->a+i,p,sample->a+i);
}

EXPORT void ringLweFFTSubMulRTo(RingLWESampleFFT* result, const LagrangeHalfCPolynomial* p, const RingLWESampleFFT* sample, const RingLWEParams* params) {
    const int k = params->k;
    
    for (int i=0; i<=k; i++)
	LagrangeHalfCPolynomial_submul(result->a+i,p,sample->a+i);
}

    
EXPORT void ringGswToFFTConvert(RingGSWSampleFFT* result, const RingGSWSample* source, const RingGSWParams* params) {
    const int kpl = params->kpl;
    
    for (int p=0; p<kpl; p++)
	ringLweToFFTConvert(result->all_samples+p, source->all_sample+p, params->ringlwe_params);
}

EXPORT void ringGswFromFFTConvert(RingGSWSample* result, const RingGSWSampleFFT* source, const RingGSWParams* params){
    const int kpl = params->kpl;
    
    for (int p=0; p<kpl; p++)
	ringLweFromFFTConvert(result->all_sample+p, source->all_samples+p, params->ringlwe_params);
}

EXPORT void ringGswFFTAddH(RingGSWSampleFFT* result, const RingGSWParams* params) {
    const int k = params->ringlwe_params->k;
    const int l = params->l;

    for (int j=0; j<l; j++) {
    	Torus32 hj = params->h[j];
    	for (int i=0; i<=k; i++)
	   LagrangeHalfCPolynomial_addTorusConstant(&result->sample[i][j].a[i],hj); 
    }

}

EXPORT void ringGswFFTClear(RingGSWSampleFFT* result, const RingGSWParams* params) {
    const int kpl = params->kpl;

    for (int p=0; p<kpl; p++)
	ringLweFFTClear(result->all_samples+p, params->ringlwe_params);
}    

EXPORT void LagrangeHalfCPolynomial_decompH(LagrangeHalfCPolynomial* reps, const LagrangeHalfCPolynomial* pol, const RingGSWParams* params) {
    const int l = params->l;
    const int N = params->ringlwe_params->N;
    //TODO attention, this prevents parallelization...
    static TorusPolynomial* a = new_TorusPolynomial(N);
    static IntPolynomial* deca = new_IntPolynomial_array(l,N);

    TorusPolynomial_fft(a,pol);
    Torus32PolynomialDecompH(deca, a, params);
    for (int j=0; j<l; j++) {
	IntPolynomial_ifft(reps+j,deca+j);
    }
}

EXPORT void ringLweFFTExternMulGSWTo(RingLWESampleFFT* accum, RingGSWSampleFFT* gsw, const RingGSWParams* params) {
    const RingLWEParams* ringlwe_params=params->ringlwe_params;
    const int k = ringlwe_params->k;
    const int l = params->l;
    const int kpl = params->kpl;
    const int N = ringlwe_params->N;
    //TODO attention, this prevents parallelization...
    static LagrangeHalfCPolynomial* decomps=new_LagrangeHalfCPolynomial_array(kpl,N);

    for (int i=0; i<=k; i++)
	LagrangeHalfCPolynomial_decompH(decomps+i*l,accum->a+i, params);
    ringLweFFTClear(accum, ringlwe_params);
    for (int p=0; p<kpl; p++)
	ringLweFFTAddMulRTo(accum, decomps+p, gsw->all_samples+p, ringlwe_params);
}

EXPORT void ringGSWFFTMulByXaiMinusOne(RingGSWSampleFFT* result, const int ai, const RingGSWSampleFFT* bki, const RingGSWParams* params) {
    const RingLWEParams* ringlwe_params=params->ringlwe_params;
    const int k = ringlwe_params->k;
    //const int l = params->l;
    const int kpl = params->kpl;
    const int N = ringlwe_params->N;
    //on calcule x^ai-1 en fft
    //TODO attention, this prevents parallelization...
    static LagrangeHalfCPolynomial* xaim1=new_LagrangeHalfCPolynomial(N);
    LagrangeHalfCPolynomial_setXaiMinusOne(xaim1,ai);
    for (int p=0; p<kpl; p++) {
        const LagrangeHalfCPolynomial* in_s = bki->all_samples[p].a;
        LagrangeHalfCPolynomial* out_s = result->all_samples[p].a;
        for (int j=0; j<=k; j++)
            LagrangeHalfCPolynomial_mul(&out_s[j], xaim1, &in_s[j]); 
    }
}

EXPORT void createBootstrappingKeyFFT(
	LWEBootstrappingKeyFFT* bk, 
	const LWEKey* key_in, 
	const RingGSWKey* rgsw_key) {
    assert(bk->bk_params==rgsw_key->params);
    assert(bk->in_out_params==key_in->params);

    const LWEParams* in_out_params = bk->in_out_params; 
    const RingGSWParams* bk_params = bk->bk_params;
    const RingLWEParams* accum_params = bk_params->ringlwe_params;
    const LWEParams* extract_params = &accum_params->extracted_lweparams;
    
    //LWEKeySwitchKey* ks; ///< the keyswitch key (s'->s)
    const RingLWEKey* accum_key = &rgsw_key->ringlwe_key;
    LWEKey* extracted_key = new_LWEKey(extract_params);
    ringLweExtractKey(extracted_key, accum_key);
    lweCreateKeySwitchKey(bk->ks, extracted_key, key_in);
    delete_LWEKey(extracted_key);
    
    //RingGSWSample* bk; ///< the bootstrapping key (s->s")
    RingGSWSample* tmpsample = new_RingGSWSample(bk_params);
    int* kin = key_in->key;
    const double alpha = accum_params->alpha_min;
    const int n = in_out_params->n;
    for (int i=0; i<n; i++) {
	ringGswSymEncryptInt(tmpsample, kin[i], alpha, rgsw_key);
	ringGswToFFTConvert(&bk->bk[i], tmpsample, bk_params);
    }
    delete_RingGSWSample(tmpsample);
}


EXPORT void bootstrapFFT(LWESample* result, const LWEBootstrappingKeyFFT* bk, Torus32 mu1, Torus32 mu0, const LWESample* x){
    const Torus32 ab=(mu1+mu0)/2;
    const Torus32 aa = mu0-ab; // aa=(mu1-mu0)/2;
    const RingGSWParams* bk_params = bk->bk_params;
    const RingLWEParams* accum_params = bk_params->ringlwe_params;
    const LWEParams* extract_params = &accum_params->extracted_lweparams;
    const LWEParams* in_out_params = bk->in_out_params;
    const int n=in_out_params->n;
    const int N=accum_params->N;
    const int Ns2=N/2;
    const int Nx2= 2*N;
    
    
    TorusPolynomial* testvect=new_TorusPolynomial(N);
    TorusPolynomial* testvectbis=new_TorusPolynomial(N);


    int barb=modSwitchFromTorus32(x->b,Nx2);
    //je definis le test vector (multiplié par a inclus !
    for (int i=0;i<Ns2;i++)
       testvect->coefsT[i]=aa;
    for (int i=Ns2;i<N;i++)
       testvect->coefsT[i]=-aa;
    TorusPolynomialMulByXai(testvectbis, barb, testvect);

    // Accumulateur 
    RingLWESample* acc = new_RingLWESample(accum_params);
    RingLWESampleFFT* accFFT = new_RingLWESampleFFT(accum_params);

    // acc and accFFt will be used for bootstrapFFT, acc1=acc will be used for bootstrap
    ringLweNoiselessTrivial(acc, testvectbis, accum_params);
    ringLweToFFTConvert(accFFT, acc, accum_params);

    RingGSWSample* temp = new_RingGSWSample(bk_params);
    RingGSWSampleFFT* tempFFT = new_RingGSWSampleFFT(bk_params);

//NICOLAS: j'ai ajouté ce bloc
#ifndef NDEBUG
    TorusPolynomial* phase = new_TorusPolynomial(N);
    int correctOffset = barb;
    cout << "starting the test..." << endl;
#endif
    // the index 1 is given when we don't use the fft
    for (int i=0; i<n; i++) {
        int bara=modSwitchFromTorus32(-x->a[i],Nx2);
        
        if (bara!=0) {
            ringGSWFFTMulByXaiMinusOne(tempFFT, bara, bk->bk+i, bk_params);
            ringGswFFTAddH(tempFFT, bk_params);
            ringLweFFTExternMulGSWTo(accFFT, tempFFT, bk_params);
        }

//NICOLAS: et surtout, j'ai ajouté celui-ci!
#ifndef NDEBUG
            ringLweFromFFTConvert(acc, accFFT, accum_params);
        ringLwePhase(phase,acc,debug_accum_key);  //celui-ci, c'est la phase de acc (FFT)
	if (debug_in_key->key[i]==1) correctOffset = (correctOffset+bara)%Nx2; 
        TorusPolynomialMulByXai(testvectbis, correctOffset, testvect); //celui-ci, c'est la phase idéale (calculée sans bruit avec la clé privée)
	for (int j=0; j<N; j++) {
	       printf("Iteration %d, index %d: phase %d vs noiseless %d\n",i,j,phase->coefsT[j], testvectbis->coefsT[j]);
	}
#endif

    }
    ringLweFromFFTConvert(acc, accFFT, accum_params);


    LWESample* u = new_LWESample(extract_params);
    sampleExtract(u, acc, extract_params, accum_params);
    u->b += ab;
    
    lweKeySwitch(result, bk->ks, u);
    


    delete_LWESample(u);
    delete_RingGSWSampleFFT(tempFFT); 
    delete_RingGSWSample(temp);
    delete_RingLWESampleFFT(accFFT);
    delete_RingLWESample(acc);
    delete_TorusPolynomial(testvectbis);
    delete_TorusPolynomial(testvect);
}
