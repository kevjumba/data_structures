/*
 * MowLawn.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: kevin
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int grid[1000][1000]; //arbitrarily large grid
int N; //input for number of moves total
int startx=500;
int starty=500;
int t=0; //timer for each move
int minTime=10000000;
ifstream fin("mowing.in");
ofstream fout("mowing.out");


void move(char direction, int steps){
	for(int i=0;i<steps;i++){
		t++; //increment time interval
		if(direction=='N'){ //north
			if(grid[startx][starty+1]!=0){
				minTime=min(abs(grid[startx][starty+1]-t), minTime); //see if already visited and compare time originally to time now
			}
			else
				grid[startx][starty+1]=t;
			starty++;

		}
		else if(direction=='W'){ //west
					if(grid[startx-1][starty]!=0){
						minTime=min(abs(grid[startx-1][starty]-t), minTime); //see if already visited and compare time originally to time now

					}
					else
					grid[startx-1][starty]=t;
					startx--;
			}
		else if(direction=='E'){ //east
					if(grid[startx+1][starty]!=0){
						minTime=min(abs(grid[startx+1][starty]-t), minTime); //see if already visited and compare time originally to time now
					}
					else
					grid[startx+1][starty]=t;

					startx++;
				}
		else if(direction=='S'){ //south
					if(grid[startx][starty-1]!=0){
						minTime=min(abs(grid[startx][starty-1]-t), minTime); //see if already visited and compare time originally to time now
					}
					else
					grid[startx][starty-1]=t;
					starty--;
		}
	}
}
int main(void){
	fin>>N;
	char direction;
	int numSteps;
	for(int i=0;i<N;i++){
		fin>>direction;
		fin>>numSteps;
		move(direction, numSteps);

	}
	if(minTime==10000000) fout<<-1;
	else fout<<minTime;
}

