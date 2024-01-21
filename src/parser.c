#include "parser.h"
#include "token.h"
#include "parser.h"

static t_node *parse_pair(t_scanner *scanner);
static t_node *parse_char(t_scanner *scanner);

t_node *parse(t_scanner *scanner)
{
	t_token next = scanner_peek(scanner);
	switch (next.type) {
		case CHAR_TOKEN:
			return parse_char(scanner);
		case LPAREN_TOKEN:
			return parse_pair(scanner);
		default:
			return error_node_new("Expected (or a Char");
	}
}

static t_node *parse_char(t_scanner *scanner)
{
	t_token next = scanner_next(scanner);
	return char_node_new(next.lexeme);
}

static t_node *parse_pair(t_scanner *scanner)
{
	t_token next = scanner_next(scanner);
	t_node *left = parse(scanner); 
	next = scanner_next(scanner);
	t_node *right = parse(scanner);
	next = scanner_next(scanner);
	return pair_node_new(left, right);
}