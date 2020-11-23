/*
* Title: Weighted Graph
* Author: Edgar Podvezko
* Date: 2020
* Software: Visual Studio 2019
*/

#include <iostream>
#include <vector>

void AddPair(std::vector <std::pair<int, int>> adj[], int x, int y, int weight)
{
	adj[x].push_back(std::make_pair(y, weight));
	adj[y].push_back(std::make_pair(x, weight));
}

void DisplayGraph(std::vector <std::pair<int, int> > adj[], int weight)
{
	int x, y;
	for (int i = 0; i < weight; i++)
	{
		std::cout << "Node " << i << " connected with: \n\n";
		for (auto j = adj[i].begin(); j != adj[i].end(); j++)
		{
			x = j->first;
			y = j->second;
			if (i != x) {
				std::cout << "Node " << x << " with weight "
					<< y << "\n";
			}
		}
		std::cout << "-----------------------\n";
	}
}
/* TODO: Deletion Function */
void Deletion(std::vector <std::pair<int, int> > adj[], int x, int y, int weight)
{
	std::cout << "Deletion is in progress :/\n";

}

int main()
{
	const int Nodes = 200;
	int n, node_one, node_two, max = 5, weight;
	bool choice = false;
	std::vector<std::pair<int, int > > adj[Nodes]; // creates vector of integer pairs
	AddPair(adj, 0, 1, 10);
	AddPair(adj, 0, 4, 20);
	AddPair(adj, 1, 2, 30);
	AddPair(adj, 1, 3, 40);
	AddPair(adj, 1, 4, 50);
	AddPair(adj, 2, 3, 60);
	AddPair(adj, 3, 4, 70);
	//AddNode(adj, 5, 4, 80);

	/* Program Menu*/
	do {
		std::cout << "-----------------------------------\nTo display - input 1;\nto insert input 2; \nTo delete, input 3; \nTo finish, input 4: ";
		std::cin >> n;
		std::cout << "-----------------------------------\n";
		switch (n)
		{
		case 1:
			DisplayGraph(adj, max);
			break;
		case 2:
			std::cout << "You picked Insertion. Pick 2 nodes to connect and their weight: " << std::endl;
			std::cin >> node_one >> node_two >> weight;
			AddPair(adj, node_one, node_two, weight);


			if (node_one + 1 > max) max = node_one + 1;
			if (node_two + 1 > max) max = node_two + 1;
			break;
		case 3:
			std::cout << "Deletion is in development\n " << std::endl;
			break;
		case 4:
			choice = true;
		default:
			std::cout << "Wrong choice\n";
			break;
		}
	} while (!choice);

}

