#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRAPH_VERTICES 7
#define MAX_EDGES 5
#define WEIGHT_CAP 8000

struct Vertex;
struct Edge;

struct Vertex
{
	char value;
        struct Edge* edges;
} typedef Vertex;

struct Edge
{
	unsigned int weight;
	struct Vertex* vertex;
} typedef Edge;

char* Dijkstra(Vertex start, Vertex end, unsigned int size)
{
	char* result = malloc(size+1);
	char* path = malloc(size+1);
	unsigned int* estimates = malloc(size*sizeof(unsigned int));
	char* source = malloc(size);
	bool* visited = malloc(size);
	unsigned int distance = 0;
	Vertex current = start;
	for(int i = 0; i < size; i++)
	{
		estimates[i] = WEIGHT_CAP;
		visited[i] = false;
	}
	for(int i = 0; i < size; i++) source[i] = 'A';
	visited[start.value-65] = true;
	estimates[start.value-65] = 0;

	unsigned int min, pathSize = 0;
	char traversal;

	//Calculate path
	while(current.value != end.value)
	{
		//Update estimates
		for(int i = 0; i < MAX_EDGES; i++)
		{
			if(current.edges[i].weight == 0) break;
			if(estimates[current.edges[i].vertex->value-65] >
			(distance+current.edges[i].weight))
			{
				estimates[current.edges[i].vertex->value - 65] = 
                        	distance+current.edges[i].weight;
				source[current.edges[i].vertex->value-65] =
				current.value;
			}
		}
		//Display estimates
		printf("Estimated distances with estimation sources: ");
		for(int i = 0; i < size; i++)
		{
			if(estimates[i] < 8000) printf("%u ", estimates[i]);
			else printf("NaN ");
			printf("%c ", source[i]);
		}
		putchar('\n');
		//Pick new vertex
		for(int i = 0; i < MAX_EDGES; i++)
		{
			if(!visited[current.edges[i].vertex->value-65])
			{
				min = i;
				break;
			}
		}
		for(int i = min+1; i < MAX_EDGES; i++)
		{
			if(current.edges[i].weight == 0) break;
			if( (estimates[current.edges[i].vertex->value-65] <
			estimates[current.edges[min].vertex->value-65])
			&& (!visited[current.edges[i].vertex->value-65]) )
			{
				min = i;
			}
		}
		current = *current.edges[min].vertex;
		distance = estimates[current.value-65];
		visited[current.value-65] = true;
		//Display vertex choice
		printf("Vertex choice: %c\n", current.value);
		//Display distance travelled
		printf("Distance: %u\n\n", distance);
	}
	//Traverse the path back
	traversal = current.value;
	while(traversal != start.value)
	{
		path[pathSize] = traversal;
		traversal = source[traversal-65];
		pathSize++;
	}
	path[pathSize] = traversal;
	//Reverse traversed path
	for(int i = 0; i < pathSize+1; i++)
	{
		result[i] = path[pathSize-i];
	}
	result[pathSize+1] = 0;
	//Free memory
	free(path);
	free(estimates);
	free(source);
	free(visited);
	//Return path from the starting vertex
	return result;
}

int main()
{
	//Initialize vertices
	Vertex a, b, c, d, e, f, g;
	a.value = 'A'; b.value = 'B';
	c.value = 'C'; d.value = 'D';
	e.value = 'E'; f.value = 'F';
	g.value = 'G';

	//Initialize edges
	Edge ac; ac.weight = 3; ac.vertex = &c; Edge ca; ca.weight = 3; ca.vertex = &a;
	Edge fa; fa.weight = 2; fa.vertex = &a; Edge af; af.weight = 2; af.vertex = &f;
	Edge cf; cf.weight = 2; cf.vertex = &f; Edge fc; fc.weight = 2; fc.vertex = &c;
	Edge ce; ce.weight = 1; ce.vertex = &e; Edge ec; ec.weight = 1; ec.vertex = &c;
	Edge fe; fe.weight = 3; fe.vertex = &e; Edge ef; ef.weight = 3; ef.vertex = &f;
	Edge fb; fb.weight = 6; fb.vertex = &b; Edge bf; bf.weight = 6; bf.vertex = &f;
	Edge fg; fg.weight = 5; fg.vertex = &g; Edge gf; gf.weight = 5; gf.vertex = &f;
	Edge cd; cd.weight = 4; cd.vertex = &d; Edge dc; dc.weight = 4; dc.vertex = &c;
	Edge db; db.weight = 1; db.vertex = &b; Edge bd; bd.weight = 1; bd.vertex = &d;
	Edge gb; gb.weight = 2; gb.vertex = &b; Edge bg; bg.weight = 2; bg.vertex = &g;
	Edge eb; eb.weight = 2; eb.vertex = &b; Edge be; be.weight = 2; be.vertex = &e;
	Edge empty; empty.weight = 0; empty.vertex = 0;	

	//Assign edges
	a.edges = malloc(sizeof(Edge)*MAX_EDGES+1);
	b.edges = malloc(sizeof(Edge)*MAX_EDGES+1);
	c.edges = malloc(sizeof(Edge)*MAX_EDGES+1);
	d.edges = malloc(sizeof(Edge)*MAX_EDGES+1);
	e.edges = malloc(sizeof(Edge)*MAX_EDGES+1);
	f.edges = malloc(sizeof(Edge)*MAX_EDGES+1);
	g.edges = malloc(sizeof(Edge)*MAX_EDGES+1);
	a.edges[0] = ac; a.edges[1] = af; a.edges[2] = empty;
	b.edges[0] = bd; b.edges[1] = be; b.edges[2] = bg; b.edges[3] = bf;
	b.edges[4] = empty;
	c.edges[0] = cd; c.edges[1] = ce; c.edges[2] = cf; c.edges[3] = ca;
	c.edges[4] = empty;
	d.edges[0] = dc; d.edges[1] = db; d.edges[2] = empty;
	e.edges[0] = eb; e.edges[1] = ef; e.edges[2] = ec; e.edges[3] = empty;
	f.edges[0] = fa; f.edges[1] = fc; f.edges[2] = fe; f.edges[3] = fb;
	f.edges[4] = fg; f.edges[5] = empty;
	g.edges[0] = gf; g.edges[1] = gb; g.edges[2] = empty;	

	//Get and display path from A to B
	char* pathAB = Dijkstra(a, b, GRAPH_VERTICES);	

	printf("Shortest path from A to B: ");
	while(*pathAB)
	{
		printf("%c ", *pathAB);
		pathAB++;
	}
	putchar('\n');

	return 0;
}
