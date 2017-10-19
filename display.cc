/*

    GA 終了時に解を出力する関数
    
*/

using namespace std;


void displayAnswer(){
    //初期状態の表示
    cout << "~~~~~初期状態~~~~~"<< endl;
    for(int x = 0; x < X;x++){
        cout << "candidate["<<x<<"] -> fitness:"<<candidatesFitness_first[x]<<endl;
        cout << "candidate[" << x << "]'s params -> ";
        for(int dim = 0;dim < DIMENTION;dim ++){
            cout << candidate_first[x][dim] << " ";
        }cout << endl;
    }

    //最終状態の表示
    cout << "~~~~~最終状態~~~~~"<< endl;
    for(int x = 0; x < X;x++){
        cout << "candidate["<<x<<"] -> fitness:"<<candidatesFitness[x]<<endl;
        cout << "candidate[" << x << "]'s params -> ";
        for(int dim = 0;dim < DIMENTION;dim ++){
            cout << candidate[x][dim] << " ";
        }cout << endl;
    }

    //解の表示
    int temp = 0;
    int ans = 0;
    for(int x=0;x<X;x++){
        if(temp < candidatesFitness[x]){
            temp = candidatesFitness[x];
            ans = x;
        }
    }
    cout <<"BestSolution::"<<candidatesFitness[ans] << endl;
    cout << "params::";
    for(int dim = 0;dim < DIMENTION;dim++){
        cout <<candidate[ans][dim] << " ";
    }cout << endl;
}
