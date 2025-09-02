#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string,bool> genrevisit;
unordered_map<string,int> genremap;
pair<int,int> genre[101]; //총재생횟수,장르
vector<pair<int,int>> song[101]; //[장르] {재생횟수,idx}l

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int ng=0;
    for(int i=0;i<genres.size();i++){
        string gens=genres[i];
        int play=plays[i];
        if(!genrevisit[gens])//처음나온장르면
        {   //장르 string to int
            genrevisit[gens]=true;
            genremap[gens]=ng;
            ng++;
        }
        int gen=genremap[gens];//gen = 장르int
        song[gen].push_back({play,i});//노래추가
        genre[gen].first+=play;
        genre[gen].second=gen;
    }
    cout<<ng;
    sort(genre,genre+ng,cmp);
    for(int i=0;i<ng;i++){
        int gen=genre[i].second;
        sort(song[gen].begin(),song[gen].end(),cmp);//gen 장르의 노래 정렬 play순
        bool two=false;
        for(int j=0;j<song[gen].size();j++){//size까지 해야되는이유 1개짜리도 있으니까 ㅇㅇ.;;
            answer.push_back(song[gen][j].second);
            if(two)break;//이미 두개출력했으면 break;
            two=true;
        }
    }
    return answer;
}

/*
장르 두개의 재생횟수가 같으면 어쩌지 상관없나.. 일단 빨리나온장르부터..
*/