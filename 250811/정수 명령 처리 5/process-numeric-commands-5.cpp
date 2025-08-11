#include <iostream>
#include <vector>

using namespace std;

int N;
string command[10000];
int num[10000];

int main() {
    vector<int> V;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_back" || command[i] == "get") {
            cin >> num[i];
        }
    }

    for(int i = 0 ; i < N ; i++){
        if(command[i] == "push_back"){
            V.push_back(num[i]);
        }else if(command[i] == "get"){
            cout<<V[num[i] - 1]<<endl;
        }
        else if(command[i] == "size"){
            cout<<V.size()<<endl;
        }else if(command[i] == "pop_back"){
            V.pop_back();
        }
    }


    return 0;
}
