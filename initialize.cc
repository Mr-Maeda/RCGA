/*

    解候補candidateの初期値の設定を行う関数

*/

void initializeCandidate(){
    //遺伝子の初期化
    for(int x = 0;x < X;x++){

        std::uniform_real_distribution<> random_double(0, 100);     // [0, 99] 範囲の一様乱数

        for(int dim = 0; dim < DIMENTION;dim++){
            candidate[x][dim] = random_double(mt);

            //printfデバッグ用
            // cout << "candidate["<< x<< "]["<<dim<<"]="<<candidate[x][dim]<<endl;

        }
    }
}
