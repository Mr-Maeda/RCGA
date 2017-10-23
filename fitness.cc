/*

    評価値の計算を行う関数
    評価値の定義
    遺伝子データのをエージェントとやり取りする場合のファイル操作など

*/

double calcFitness(vector<double> params){

    //評価値
    double fitness = 0;

    //Test用の評価関数
    // for(int dim = 0;dim < DIMENTION;dim++){
    //     fitness += params[dim];
    // }

    //遺伝子データを外部ファイルへ出力
    outPut(params);

    //エージェントの起動,評価値の算出
    system(agentStartScript.c_str());

    fitness = readResultFile();

    return fitness;

}

//エージェントが書き出す結果をファイルから回収
double readResultFile(){

    ifstream ifs;

    double result = 0;

    ifs.open(fitnessValueFileName.c_str());

      if(!ifs){
        cerr << "FileOpenError:" << fitnessValueFileName << endl;
        exit(-1);
      }else{
        string str;
        while (getline(ifs, str))
        {
          string token;
          istringstream stream(str);
          while (getline(stream, token, ','))
          {
            result = stod(token);
          }
        }
      }ifs.close();

      return result;

}

//エージェントが使用する遺伝子データを外部ファイルへ出力
void outPut(vector<double> params){

    ofstream ofs;

    ofs.open(outPutFileName.c_str());

    if(!ofs){
        cout << "FileNotFound:" << outPutFileName << endl;
        exit(-1);
    }
    for(int x = 0;x < params.size();x++){
        ofs << params[x] << ",";
    }
    ofs.close();


}
