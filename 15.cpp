#include <iostream>
#include <string>
void BFS(std::string x [][])
{
	//lol its just 40!/20!*20! yolo stats
}
int main()
{
	std::string x [21][21];
	for(int i = 0; i<21; i++)
		for(int j = 0; j<21; j++)
		{
			x[i][j] = "x";
		}
	x[20][20] = "g";
	BFS(x);
	return 0;
}

