#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


ifstream fin("angry.in");
ofstream fout("angry.out");

bool touched[100];
int position[100];
int N;
int maxStreak=0;


int dist(int pos1, int pos2){
	return abs(position[pos1]-position[pos2]);
}

int blast(int pos, int radius){
	int destroyed[100]={0};
	int blastr=radius;
	int numCows=0;
	for(int i=0;i<N;i++){
		if(dist(pos, i)<=blastr&&touched[i]!=1){
			destroyed[i]=1;
			touched[i]=1;
			numCows++;
		}
	}
	for(int i=0;i<N;i++){
		if(destroyed[i]==1){
			numCows+=blast(i, blastr+1);
		}
	}
	return numCows;


}

void resetAll(){
	for(int i=0;i<N;i++){
		touched[i]=0;
	}
}

int main(void) {
	fin>>N;
	int maxStreak=0;
	for(int i=0;i<N;i++){
		fin>>position[i];
	}
	for(int i=0;i<N;i++){
		touched[i]=1;
		maxStreak=max(blast(i, 1), maxStreak);
		resetAll();
	}
	fout<<maxStreak+1;
}




