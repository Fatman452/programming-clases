#include <stdio.h>
#include <stdlib.h>

typedef struct Country
{
	char *name;
	int weight;
	int id;
	int visited;
} Country;

int **countries_distances;
Country **countries_list;
int countries_size;

typedef struct Route
{
	int total_weight;
	int total_distance;
	Country *country;
	struct Route *next;
} Route;

typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
	int height;
	Route *route;
} Node;

int max(int a, int b)
{
	return a > b ? a : b;
}

int get_height(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}

	return node->height;
}

Node *rightRotate(Node *node)
{
	Node *left_node = node->left;
	Node *left_right_node = left_node->right;

	left_node->right = node;
	node->left = left_right_node;

	node->height = max(get_height(node->left), get_height(node->right)) + 1;
	left_node->height = max(get_height(left_node->left), get_height(left_node->right)) + 1;

	return left_node;
}

Node *leftRotate(Node *node)
{
	Node *right_node = node->right;
	Node *right_left_node = right_node->left;

	right_node->left = node;
	node->right = right_left_node;

	node->height = max(get_height(node->left), get_height(node->right)) + 1;
	right_node->height = max(get_height(right_node->left), get_height(right_node->right)) + 1;

	return right_node;
}

int get_balance(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}

	return get_height(node->left) - get_height(node->right);
}

void traverse_inorder(Node *root)
{
	if (root != NULL)
	{
		traverse_inorder(root->left);

		printf("Distancia Total: %d\n", root->route->total_distance);
		printf("Peso Total: %d\n", root->route->total_weight);
		Route *route = root->route;

		while (route != NULL)
		{
			printf("Pais: %s -> ", route->country->name);
			route = route->next;
		}

		printf("Fin\n\n");

		traverse_inorder(root->right);
	}
}

Node *initialize_node(Route *route)
{
	Node *node = malloc(sizeof(Node));

	node->route = route;
	node->value = route->total_distance + route->total_weight;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

	return node;
}

Node *insert(Node *node, Route *route)
{
	if (node == NULL)
	{
		return initialize_node(route);
	}

	int val = route->total_distance + route->total_weight;

	if (val < node->value)
	{
		node->left = insert(node->left, route);
	}
	else if (val > node->value)
	{
		node->right = insert(node->right, route);
	}
	else
	{
		return node;
	}

	node->height = 1 + max(get_height(node->left), get_height(node->right));

	int balance = get_balance(node);

	if (balance > 1 && val < node->left->value)
	{
		return rightRotate(node);
	}

	if (balance < -1 && val > node->right->value)
	{
		return leftRotate(node);
	}

	if (balance > 1 && val > node->left->value)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && val < node->right->value)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Country *initialize_country(char *name, int weight)
{
	Country *new_country = malloc(sizeof(Country));

	new_country->name = name;
	new_country->weight = weight;
	new_country->id = countries_size + 1;
	new_country->visited = 0;

	return new_country;
}

void add_country_to_list(Country *country)
{
	if (countries_size == 0)
	{
		countries_list = malloc(sizeof(Country));
	}
	else
	{
		countries_list = realloc(countries_list, (countries_size + 1) * (sizeof(Country)));
	}

	countries_list[countries_size] = country;
	countries_size++;
}

void initialize_countries_distances()
{
	countries_distances = malloc(sizeof(int) * countries_size);

	for (int i = 0; i < countries_size; i++)
	{
		countries_distances[i] = malloc(sizeof(int) * countries_size);

		for (int j = 0; j < countries_size; j++)
		{
			countries_distances[i][j] = -1;
		}
	}
}

void set_distances_between_countries(Country *origin, Country *destiny, int distance)
{
	countries_distances[origin->id - 1][destiny->id - 1] = distance;
	countries_distances[destiny->id - 1][origin->id - 1] = distance;
}

Route *initialize_route(Country *country)
{
	Route *route = malloc(sizeof(Route));

	route->country = country;
	route->total_distance = 0;
	route->total_weight = country->weight;
	route->next = NULL;

	return route;
}

Route *clone_route(Route *route)
{
	Route *cloned_route = initialize_route(route->country);

	cloned_route->total_weight = route->total_weight;
	cloned_route->total_distance = route->total_distance;

	if (route->next != NULL)
	{
		Route *new_clone = clone_route(route->next);
		cloned_route->next = new_clone;
	}
	return cloned_route;
}

void rewind_route(Route *route)
{
	Route *next_route = route->next;

	next_route->country->visited = 0;
	route->next = NULL;
}

Node *build_routes(Country *destiny, Route *initial_route, Route *current_route, Node *root)
{
	int index_country = current_route->country->id - 1;

	for (int i = 0; i < countries_size; i++)
	{
		int distance = countries_distances[index_country][i];

		if (distance > -1)
		{
			if (countries_list[i]->visited == 0)
			{
				Route *next_route = initialize_route(countries_list[i]);

				initial_route->total_distance = initial_route->total_distance + distance;
				initial_route->total_weight = initial_route->total_weight + countries_list[i]->weight;
				current_route->next = next_route;
				current_route->country->visited = 1;

				if (countries_list[i]->id == destiny->id)
				{
					Route *cloned_route = clone_route(initial_route);
					root = insert(root, cloned_route);
				}
				else
				{
					root = build_routes(destiny, initial_route, next_route, root);
				}
				rewind_route(current_route);
				initial_route->total_distance = initial_route->total_distance - distance;
				initial_route->total_weight = initial_route->total_weight - countries_list[i]->weight;
			}
			else
			{
				continue;
			}
		}
	}
	return root;
}

int main(int argc, char *argv[])
{
	Country *peru = initialize_country("peru", 100);
	add_country_to_list(peru);

	Country *cuba = initialize_country("cuba", 120);
	add_country_to_list(cuba);

	Country *argentina = initialize_country("argentina", 40);
	add_country_to_list(argentina);

	Country *rusia = initialize_country("rusia", 80);
	add_country_to_list(rusia);

	initialize_countries_distances();

	set_distances_between_countries(peru, cuba, 400);
	set_distances_between_countries(peru, argentina, 700);
	set_distances_between_countries(cuba, rusia, 1500);
	set_distances_between_countries(argentina, rusia, 2000);
	set_distances_between_countries(argentina, cuba, 600);

	Route *route = initialize_route(peru);

	Node *root = NULL;

	root = build_routes(rusia, route, route, root);

	traverse_inorder(root);

	return 0;
}
