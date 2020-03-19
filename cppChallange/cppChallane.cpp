#include <iostream>
#include <vector>
#include<fstream>
#include <sstream>
using namespace std;

int pathLength = 0;
int rows=0;
int cols=0;


bool DFS(int x,int y,vector<vector<int>> &visited,int n,int m,vector<vector<char>> mat, int dest_x, int dest_y){
	
	if(x==dest_x && y==dest_y)
		//visited[x][y] = pathLength;
		return true;
	
	if(x>=n || y>=m)
		return false;
	
	if(x<0 || y<0)
		return false;

	if(visited[x][y]>=0)
		return false;
	
	if(mat[x][y]=='#')
		return false;
	
	visited[x][y] = pathLength;
	pathLength+=1;

	if(DFS(x+1, y, visited,n,m,mat,dest_x,dest_y) == true)
		return true;
	
	if(DFS(x, y+1, visited,n,m,mat,dest_x,dest_y) == true)
		return true;
	
	if(DFS(x-1, y, visited,n,m,mat,dest_x,dest_y) == true)
		return true;
	
	if(DFS(x, y-1, visited,n,m,mat,dest_x,dest_y) == true)
		return true;
	
	return false;
}

void printGrid(vector<vector<int>> finalVisited, vector<vector<char>> arr){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(finalVisited[i][j] >= 0){
				cout << (finalVisited[i][j]);
			}
			else{
				cout << arr[i][j];
			}
		}cout << "\n";
	}
}

int main(int argc, char** argv) {
	if(argc!=2){
		cout << "Give the Input file along also.\n";
		cout << "Example: ./a.out testCpp.txt\n";
		return 0;
	}
	int k,l;
	int i=0;
	int j=0;
	int n=0;
	vector<vector<char>> arr;
	vector<vector<int>> visited;
	vector<vector<int>> finalVisited;
	fstream f;
    string line;

	f.open(argv[1], ios::in);
	for (;;){
		getline(f, line);
		if(!f) break;
		rows++;
		arr.push_back(vector<char>());
		visited.push_back(vector<int>());
		finalVisited.push_back(vector<int>());
		istringstream fline(line);
		j = 0;
		for(;;){
			char val;
			fline >> val;
			if(!fline) break;
			arr[i].push_back(val);
			visited[i].push_back(-1);
			finalVisited[i].push_back(-1);
			j++;
		}
		cols = j;
		i++;

	}
 	int holes[rows*cols][2];
 	int numberOfHoles = 0;

 	for(i=0;i<rows;i++){
 		for(j=0;j<cols;j++){
 			if(arr[i][j] == '.'){
 				holes[numberOfHoles][0] = i;
 				holes[numberOfHoles][1] = j;
 				numberOfHoles+=1;
 			}
 		}
	}

	int maxDist = 0;
	for(k=0;k<numberOfHoles;k++){
		for(l=k+1;l<numberOfHoles;l++){
			int src_x = holes[k][0];
			int src_y = holes[k][1];
			int dest_x = holes[l][0];
			int dest_y = holes[l][1];
			for(i=0;i<rows;i++){
				for(j=0;j<cols;j++){
					visited[i][j] = -1;
				}
			}
			//cout << "here ";
			bool ans = (DFS(src_x,src_y,visited,rows,cols,arr,dest_x,dest_y));
			visited[dest_x][dest_y] = pathLength;
			if(ans){
				if(pathLength > maxDist){
					maxDist = pathLength;
					//copy the FinalMatrix;
					for(i=0;i<rows;i++){
						for(j=0;j<cols;j++){
							finalVisited[i][j] = visited[i][j];
						}
					}
				}
			}
			pathLength = 0;
		}
	}
	cout << maxDist+1 << "\n";
	printGrid(finalVisited,arr);
    return 0;
}