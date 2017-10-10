/*

    評価値の計算を行う関数
    評価値の定義

*/

double calcFitness(vector<double> params){

    //評価値
    double fitness = 0;

    //Test用の評価関数
    for(int dim = 0;dim < DIMENTION;dim++){
        fitness += params[dim];
    }


    return fitness;

}
