#ifndef CHAR_ITR_H
#define CHAR_ITR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct s_char_itr {
	const char *cursor;
	const char *sentinel;
} t_char_itr;

t_char_itr char_itr_value(const char *start, size_t length);

const char *char_itr_cursor(const t_char_itr *self);

bool char_itr_has_next(const t_char_itr *self);

char char_itr_peek(const t_char_itr *self);

char char_itr_next(t_char_itr *self);

#endif