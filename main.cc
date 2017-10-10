
/*

    実数値GAのプログラム

*/

#include "header.h"
#include "display.cc"
#include "initialize.cc"
#include "mgg.cc"
#include "fitness.cc"
#include "blxalpha.cc"

using namespace std;

int main(){

    //初期遺伝子を設定
    initializeCandidate();


    //解候補たちの評価値を計算
    for(int x = 0;x < X;x++){
        candidatesFitness[x] = calcFitness(candidate[x]);
    }

    //初期状態を記憶
    candidatesFitness_first = candidatesFitness;
    candidate_first = candidate;

    //実数値GA 開始
    for(int gen = 0;gen < GENERATION;gen++){
        //世代を出力
        cout << "~~~~世代数"<<gen<<"~~~~"<<endl;

        //解候補者を出力
        // for(int x = 0; x < X;x++){
        //     cout << "candidate["<<x<<"] -> fitness:"<<candidatesFitness[x]<<endl;
        //     cout << "candidate[" << x << "]'s params -> ";
        //     for(int dim = 0;dim < DIMENTION;dim ++){
        //         cout << candidate[x][dim] << " ";
        //     }cout << endl;
        // }

        //選択,交叉　MGG(Minimal Generation Gap)
        mgg();
    }
    //GA終了

    cout << endl <<"GA 終了" << endl;

    //解の表示
    displayAnswer();

    return 0;
}
