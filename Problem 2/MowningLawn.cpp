#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	ifstream fin("angry.in");
	ofstream fout("angry.out");
	int N;
	fin>>N;
	char direction;
	int steps=0;
	for(int i=0;i<N;i++){
		fin>>direction;
		if(direction=='N'){
			fin>>steps;
		}
	}

}



