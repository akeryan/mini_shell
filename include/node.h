#ifndef NODE_H
#define NODE_H

typedef enum e_node_type {
	ERROR_NODE = -1,
	CHAR_NODE = 0,
	PAIR_NODE = 1
} t_node_type;

typedef struct s_node t_node;
typedef char t_char_value;
typedef const char* t_error_value;

typedef struct s_pair_value {
	t_node *left;
	t_node *right;
} t_pair_value;

typedef union u_node_value {
	t_pair_value pair;
	t_char_value value;
	t_error_value error;
} t_node_value;

struct s_node {
	t_node_type type;
	t_node_value data;
};

t_node *char_node_new(char c);

t_node *pair_node_new(t_node *left, t_node *right);

t_node *error_node_new(const char *msg);

void *node_drop(t_node *self);

#endif
