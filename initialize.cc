/*

    解候補candidateの初期値の設定を行う関数

*/
//
// #include <fstream>
//
// vector< vector<double> > initParams(X,vector<double>(DIMENTION));


void initializeCandidate(){
    //遺伝子の初期化
    for(int x = 0;x < X;x++){

        std::uniform_real_distribution<> random_double(0, 5);     // [min, max] 範囲の一様乱数

        for(int dim = 0; dim < DIMENTION;dim++){
            candidate[x][dim] = random_double(mt);

            //printfデバッグ用
            // cout << "candidate["<< x<< "]["<<dim<<"]="<<candidate[x][dim]<<endl;

        }
    }
}
//
// void readInitParamsFromCSV(string path){
//
//     ifstream ifs;
//
//     ifs.open(path);
//       if(!ifs){
//         cerr << "CSVFileOpenError:" << path << endl;
//         exit(-1);
//       }else{
//         string str;
//         int row = 0,col = 0;
//         while (getline(ifs, str))
//         {
//               string token;
//               istringstream stream(str);
//
//               while (getline(stream, token, ','))
//               {
//                 initParams[row][col] = stod(token);
//                 col++;
//               }
//               row++;col = 0;
//         }
//
//         if(row + 1 != DIMENTION){
//             cerr << "CSVFileFormatError:" << path << endl;
//             exit(-1);
//         }
//
//       }ifs.close();
//
//
// }
