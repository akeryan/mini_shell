#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "char_itr.h"
#include "scanner.h"
#include "node.h"
#include "parser.h"
#include "libft.h"

void visit(const t_node *node, size_t spaces);
void indent(size_t n_spaces);

int main() {
	char *line;
	int fd;

	fd = open("infile", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	t_char_itr itr = char_itr_value(line, strlen(line));
	t_scanner scanner = scanner_value(itr);
	t_node *node = parse(&scanner);
	visit(node, 0);
	node_drop(node);
}

void visit(const t_node *node, size_t spaces)
{
	indent(spaces);
	switch (node->type) {
		case PAIR_NODE:
			printf("Pair(\n");
			visit(node->data.pair.left, spaces + 2);
			visit(node->data.pair.right, spaces + 2);
			indent(spaces);
			printf(")\n");
			break;
		case CHAR_NODE:
			printf("Char('%c')\n", node->data.value);
			break;
		case ERROR_NODE:
			fprintf(stderr, "Error: %s\n", node->data.error);
			break;
	}
}

void indent(size_t spaces)
{
	size_t i = 0;
	
	while (i++ < spaces)
		putchar(' ');
}