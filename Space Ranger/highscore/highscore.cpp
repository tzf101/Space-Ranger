#include<iostream>
#include<vector>
#include <utility>
#include<string.h>
#include<algorithm>

using namespace std;
bool compare(pair<string, int>a,pair<string, int>b)
{
    return a.second>b.second;
}
int main()
{
    FILE *fp=NULL;
    vector<pair<string, int>>score;
    int cnt=0,i,j,scr,x,temp_scr;
    char name[100],temp_name[10];
    scanf(" %s %d", name,&scr);
    score.push_back({name,scr});
    if((fp=fopen("Highscore.txt", "r"))==NULL)
    {
        cout<<"Error opeing file."<<endl;
        exit(1);
    }
    while(!feof(fp))
    {
        fscanf(fp, " %s", temp_name);
        fscanf(fp, "%d", &temp_scr);
        score.push_back({temp_name,temp_scr});
        cout<<temp_name<<" "<<temp_scr<<endl;
    }
    fclose(fp);
    sort(score.begin(),score.end(),compare);
    score.pop_back();
    if((fp=fopen("Highscore.txt", "w"))==NULL)
    {
        cout<<"Error opeing file."<<endl;
        exit(1);
    }
   for(i=0; i<10; i++)
    {
        fprintf(fp, "%s %d\n",score[i].first.c_str(), score[i].second);
    } for(i=0; i<10; i++)
    {
        fprintf(fp, "%s %d\n",score[i].first.c_str(), score[i].second);
    }
    fclose(fp);
}
