#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
//vector型を使用するため
#include <vector>
#include <iostream>
#include <complex>
//乱数生成のため
#include <random>
using namespace std;


/*
    GA パラメーター設定
*/
    //次元数 (遺伝子のパラメーター数)
    int DIMENTION = 5;
    //個体数 (解候補の量,1世代の定員)
    int X = 10;
    //世代数 (何回交叉,選択を繰り返すか)
    int GENERATION = 300;

/*
    MGG パラメーター設定
*/
    //子供の数
    int N = 20;

/*
    BLX-α　パラメーター設定
*/
    //BLX-αのパラメータα
    double alpha = 0.5;




/*
    グローバル変数たち
*/

//解候補となる個体の遺伝子
vector< vector<double> > candidate(X,vector<double>(DIMENTION));

//解候補たちの評価値
vector<double> candidatesFitness(X);

//解候補となる個体の遺伝子の初期状態
vector< vector<double> > candidate_first(X,vector<double>(DIMENTION));

//解候補たちの評価値の初期状態
vector<double> candidatesFitness_first(X);

//乱数生成に使用
random_device rnd;     // 非決定的な乱数生成器でシード生成機を生成
mt19937 mt(rnd()); //  メルセンヌツイスターの32ビット版、引数は初期シード


//プロトタイプ宣言
vector<double> blxAlpha(vector<double> parent1,vector<double> parent2);
double calcFitness(vector<double> params);
void initializeCandidate();
void displayAnswer();
void mgg();
