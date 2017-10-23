#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <complex>
#include <fstream>
#include <random>
using namespace std;


/*
    GA パラメーター設定
*/
    //次元数 (遺伝子のパラメーター数)
    int DIMENTION = 4;
    //個体数 (解候補の量,1世代の定員)
    int X = 10;
    //世代数 (何回交叉,選択を繰り返すか)
    int GENERATION = 30;

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
    ファイルのパス
*/

//全評価値を保存しておくファイル
string allFitnessFileName = "Data/allfitness.csv";
//全候補者の遺伝子データを保存しておくファイル
string allCandidateFileName = "Data/allcandidate.csv";
//遺伝子データを出力する外部ファイル
string outPutFileName = "Data/params.csv";
//エージェントが計算した評価値を格納する外部ファイル
string fitnessValueFileName = "Data/result.csv";
//エージェントの実行を行うShellの実行スクリプト
string agentStartScript = "./experiment.sh";


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
//blxalpha.cc
vector<double> blxAlpha(vector<double> parent1,vector<double> parent2);
//fitness.cc
double calcFitness(vector<double> params);
void outPut(vector<double> params);
double readResultFile();
//initialize.cc
void initializeCandidate();
void initializeFile(string path);
//display.cc
void displayAnswer();
//mgg.cc
void mgg();
