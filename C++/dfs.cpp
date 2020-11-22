/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include <vector>

using namespace std;

int numOfDominantCities;

int dfs(int, int, int, int, vector<vector<int>>&);

int main()
{
	int R, C;
	int tmp;
	int numOfCodingBelts = 0;
	int numOfDomCitiesInLargestBelt = 0;

	cin >> R;
	cin >> C;

	vector<vector<int>> cities(R, vector<int> (C,0));

	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
			cin >> tmp;
			cities[i][j] = tmp;
		}
	}

	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
			if(cities[i][j] == 1)
				numOfCodingBelts += 1;
				numOfDominantCities = 0;
				numOfDominantCities += dfs(i, j, R, C, cities);
				if(numOfDominantCities > numOfDomCitiesInLargestBelt)
					numOfDomCitiesInLargestBelt = numOfDominantCities;
		}
	}

	cout << numOfDomCitiesInLargestBelt;
}

int dfs(int i, int j, int R, int C, vector<vector<int>>& cities){
	int domCityCount = 0;
	
	if(i >=0 && j >=0 && i<R && j<C && cities[i][j]==1){
		cities[i][j] = 2;
		domCityCount += 1;

		//left
		numOfDominantCities += dfs(i,j-1,R,C,cities);
		//right
		numOfDominantCities += dfs(i,j+1,R,C,cities);
		//top
		numOfDominantCities += dfs(i-1,j,R,C,cities);
		//bottom
		numOfDominantCities += dfs(i+1,j,R,C,cities);
		//top-left
		numOfDominantCities += dfs(i-1,j-1,R,C,cities);
		//top-right
		numOfDominantCities += dfs(i-1,j+1,R,C,cities);
		//bottom-left
		numOfDominantCities += dfs(i+1,j-1,R,C,cities);
		//bottom-right
		numOfDominantCities += dfs(i+1,j+1,R,C,cities);
	}

	return domCityCount;
}
