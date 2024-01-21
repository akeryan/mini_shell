/*
	The CharPairs Language Grammar:

	Node -> Char | Pair
	Char -> Any character axcept '(' ')' or ' '
	Pair -> '(' Node ' ' Node ')'
*/

#ifndef PARSER_H
#define PARSER_H

#include "node.h"
#include "scanner.h"

t_node* parse(t_scanner *scanner);

#endif