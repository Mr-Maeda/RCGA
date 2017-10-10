/*

    選択,交叉を行う
    世代交代モデルMGGを参考に作成

    突然変異は行わない
    交叉率の設定は未実装

*/

void mgg(){
    /*
            1.親2個体を個体群からランダム抜きとる
            2.親から子をn個体作る
            3.親と子を含めた2+n個体から一番評価の高い個体を選ぶ
            4.親と子を含めた2+n個体からルーレット選択で１個体選ぶ
            5. 3,4の個体を親個体が入っていた個体群に入れる
    */

    //1.親の選択
        std::uniform_int_distribution<> rand_X(0, X-1);
        int p1 = rand_X(mt); //親1
        int p2 = rand_X(mt); //親2

    //2.子供の作成
        //親2人,子供N人の遺伝子データ
        vector< vector<double> > child(N + 2,vector<double>(DIMENTION));
        //子供作成
        for(int n = 0;n < N;n++){
            //子の作成はBLX-αで作成
            child[n] = blxAlpha(candidate[p1], candidate[p2]);
        }
        //親,代入
        child[N] = candidate[p1];
        child[N+1] = candidate[p2];



    //3.評価の高いものを選択
        //選択され,candidateと交代する個体 (工程4でも使用するため2つ分用意)
        vector< vector<double> > changeCandidate(2,vector<double>(DIMENTION));
        //評価値
        vector<double> fitness(N + 2);

        //評価
        for(int n = 0;n < N;n++){
            fitness[n] = calcFitness(child[n]);
        }
        fitness[N] = candidatesFitness[p1];
        fitness[N+1] = candidatesFitness[p2];

        //最高評価値を検索
        //サーチに使用
        int temp = 0;
        //選択された子供の配列番号
        int select_maxfitness = 0;

        //最高評価値の検索開始
        for(int n = 0;n < N+2;n++){
            if(temp < fitness[n]){
                temp = fitness[n];
                select_maxfitness = n;
            }
        }

        //選択された子供を解候補と交代するリストへ
        changeCandidate[0] = child[select_maxfitness];

    //4.ルーレット選択で選択
    /*
        ある個体が選択される確率 = その個体の評価値/全個体の評価値の合計
    */

        //全個体の評価値の合計
        double total = 0;
        //total初期化
        for(int n = 0; n < N+2;n++){
            total += fitness[n];
        }
        std::uniform_real_distribution<> random_roulette(0, total);

        //選択された子供の配列番号
        int select_roulette = 0;

        double arrow = random_roulette(mt);
        double sum = 0;
        for(int n = 0;n < N+2;n++){
            sum += fitness[n];
            if(sum > arrow){
                select_roulette = n;
                break;
            }
        }

        //選択された子供を解候補と交代するリストへ
        changeCandidate[1] = child[select_roulette];

    //5.個体群と選択した個体を交代
        //遺伝子データの交代
        candidate[p1] = changeCandidate[0];
        candidate[p2] = changeCandidate[1];
        //評価値の交代
        candidatesFitness[p1] = fitness[select_maxfitness];
        candidatesFitness[p2] = fitness[select_roulette];
}
