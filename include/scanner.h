#ifndef TOKEN_ITR_H
#define TOKEN_ITR_H

#include <stdbool.h>
#include "char_itr.h"
#include "token.h"

typedef struct s_scanner {
	t_char_itr char_itr;
	char next;
} t_scanner;

t_scanner scanner_value(t_char_itr char_itr);

bool scanner_has_next(const t_scanner *self);

t_token scanner_peek(const t_scanner *self);

t_token scanner_next(t_scanner *self);

#endif