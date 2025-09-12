#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//{장르 재생 횟수, 장르명}
bool cmp1(pair<int, string> a, pair<int,string> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}
//{노래 재생 횟수,노래 고유 번호}
bool cmp2(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second; //재생 횟수가 같은 노래 중 고유 번호 낮은 노래 먼저 수록
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre_num;
    int n = genres.size();
    // {장르,재생 횟수} 맵 갱신
    for(int i = 0; i < n; i++)
    {
        string genre = genres[i];
        int play_num = plays[i];
        if(genre_num.find(genre) == genre_num.end())
        {
            genre_num[genre] = play_num;
        }
        else
        {
            genre_num[genre] += play_num;
        }
    }
    //장르 순서 정렬 벡터 생성 
    vector<pair<int,string>> genres_sorted; //{장르 재생횟수, 장르명}
    for(auto m : genre_num)
    {
        pair<int, string> tmp = {m.second, m.first};
        genres_sorted.push_back(tmp);
    }
    sort(genres_sorted.begin(), genres_sorted.end(), cmp1);

    //재생 수 높은 장르부터 수록곡 선정
    for(pair<int, string> p : genres_sorted)
    {
        vector<pair<int, int>> genre_song; //{재생 횟수, 고유 번호}
        string genre = p.second;
        for(int i = 0; i < n; i++)
        {
            if(genres[i] == genre) genre_song.push_back({plays[i], i});
        }
        sort(genre_song.begin(), genre_song.end(), cmp2);
        
        //노래 앨범에 담기
        if(genre_song.size() == 1)
        {
            answer.push_back(genre_song[0].second); //장르에 속한 곡이 하나라면, 하나의 곡만 선택
        }
        else
        {
            //두개의 곡 수록
            answer.push_back(genre_song[0].second);
            answer.push_back(genre_song[1].second);
        }
        
    }
    
    return answer;
}

//NlogN으로 다시 풀어보기 