/*

    子1体分の遺伝子データを作成する関数

*/

vector<double> blxAlpha(vector<double> parent1,vector<double> parent2){

    //交叉方法はBLX-α
    //子供の遺伝子データ
    vector<double> child(DIMENTION);

    //子供の作成 各パラメーターごとに数値を決定,次元数分ループ
    for(int dim = 0;dim < DIMENTION;dim++){

        //dの計算
        double d = abs(parent1[dim] - parent2[dim]);

        //範囲設定のため使用
        double rangeMin = min(parent1[dim],parent2[dim]);
        double rangeMax = max(parent1[dim],parent2[dim]);

        //[Min, Max] 範囲の一様乱数
        std::uniform_real_distribution<> random_BLX(rangeMin - d * alpha, rangeMax + d * alpha);
        //子供の遺伝子データを作成
        child[dim] = random_BLX(mt);
    }

    return child;

}
