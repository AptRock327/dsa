#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BTNode
{
	int value;
	struct BTNode* left;
	struct BTNode* right;
} typedef BTNode;

bool dfs(BTNode* root, int val)
{
	bool l, r;
	printf("%d ", root->value);
	if(root->value == val) return true;
	if(root->left) l = dfs(root->left, val);
	if(root->right) r = dfs(root->right, val);
	return l | r;
}

bool bfs(BTNode* root, int val)
{
	BTNode** toVisit = malloc(256*sizeof(BTNode*));
	BTNode* tmp;
	int visitLength = 2;
	bool exists;
	for(int i = 0; i < 256; i++)
	{
		toVisit[i] = malloc(sizeof(BTNode*));
		toVisit[i] = 0;
	}
	toVisit[0] = root;
	while(exists)
	{
		exists = false;
		for(int i = 0; i < visitLength; i++)
		{
			if(toVisit[i])
			{
				printf("%d ", toVisit[i]->value);
				if(toVisit[i]->value == val) return true;
				tmp = toVisit[i];
				if(toVisit[i]->left)
				{
					exists = true;
					tmp = toVisit[i]->left;
				}
				else tmp = 0;
				if(toVisit[i]->right)
				{
					exists = true;
					toVisit[visitLength+1] = toVisit[i]->right;
				}
				else if(!toVisit[i]->left) tmp = 0;
				toVisit[i] = tmp;
			}
		}
		visitLength*=2;
		printf("\n");
	}
	return false;
}

int main()
{
	BTNode root, a, b, c, d, e, f;
	root.value = 5; root.left = &a; root.right = &b;
	a.value = 7; a.left = &c; a.right = &d;
	b.value = 2; b.left = &e; b.right = 0;
	c.value = 8; c.left = 0; c.right = &f;
	d.value = 3; d.left = 0; d.right = 0;
	e.value = 9; e.left = 0; e.right = 0;
	f.value = 4; f.left = 0; f.right = 0;

	printf("Path taken (DFS): ");
	if(dfs(&root, 9)) printf("\nFound\n");
	else printf("\nNot found\n");
	
	printf("Path taken (BFS):\n");
	if(bfs(&root, 4)) printf("\nFound\n");
	else printf("\nNot found\n");

	return 0;
}
