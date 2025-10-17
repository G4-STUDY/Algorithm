#include <iostream>
#include <vector>
#include <string>
using namespace std;
int half_size;
int start_idx = 0;

vector<int> tmp;
vector<int> solve(vector<int> cards, string cmd){
    
    if(cmd == "shuffle"){
        for(int i=0;i<half_size;i++){
            tmp[i+half_size] = cards[i];
            tmp[i] = cards[i+half_size];
        }
    } else {
        for(int i=0;i<half_size;i++){
            tmp[i*2] = cards[i];
            tmp[i*2+1] = cards[half_size+i];
        }
        
    }
    return tmp;
}
vector<int> solution(vector<int> cards, int n, vector<string> command){
    
    vector<int> current = vector<int>(cards.size());
    tmp = vector<int>(cards.size());
    half_size = cards.size()/2;
    
    for(int i = 0; i<cards.size();i++){
        current[i] = cards[i];
    }
    
    for(string cmd : command) {
        solve(current, cmd);
    }
    
}


int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}



