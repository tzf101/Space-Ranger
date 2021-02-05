#include<iostream>
#include<vector>
#include <utility>
#include<string.h>
#include<algorithm>
#include<fstream>
#include <string>
std::string name;
int scre;
bool compare(std::pair<std::string, int>a,std::pair<std::string, int>b)
{
    return a.second>b.second;
}
void save(std::string s, int x) {
	std::vector<std::pair<std::string, int>>score;
	std::ifstream readFile;
	readFile.open("Highscore.txt");
	score.push_back({s,x});
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			readFile >> name >> scre;
			score.push_back({name,scre});
		}
	}
	readFile.close();
	sort(score.begin(),score.end(),compare);
	std::ofstream writeFile;
	writeFile.open("Highscore.txt");
	if(writeFile.is_open()){
		for(int i=0; i<10; i++){
			writeFile << score[i].first << " " << score[i].second << "\n";
		}
	}
}