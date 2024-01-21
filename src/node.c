#include <stdlib.h>
#include <stdio.h>

#include "node.h"

t_node* char_node_new(char c)
{
	t_node* node = malloc(sizeof(t_node));
	node->type = CHAR_NODE;
	node->data.value = c;
	return node;
};

t_node* pair_node_new(t_node *left, t_node *right)
{
	t_node* node = malloc(sizeof(t_node));
	node->type = PAIR_NODE;
	node->data.pair.left = left;
	node->data.pair.right = right;
	return node;
}

t_node* error_node_new(const char *msg)
{
	t_node* node = malloc(sizeof(t_node));
	node->type = ERROR_NODE;
	node->data.error = msg;
	return node;
}

void *node_drop(t_node *self)
{
	switch (self->type)
	{
		case PAIR_NODE:
			node_drop(self->data.pair.left);
			node_drop(self->data.pair.right);
			break;
		case CHAR_NODE:
			free(self);
			break;
		case ERROR_NODE:
			break;
	}
	return (self);
}


