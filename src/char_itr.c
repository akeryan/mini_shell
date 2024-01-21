#include "char_itr.h"

t_char_itr char_itr_value(const char *start, size_t length)
{
	t_char_itr char_itr;

	char_itr.cursor = start;
	char_itr.sentinel = start + length;	
	return char_itr;
}

const char *char_itr_cursor(const t_char_itr *self)
{
	return self->cursor;
}

char char_itr_peek(const t_char_itr *self)
{
	return *(self->cursor);
}

bool char_itr_has_next(const t_char_itr *self)
{
	if (self->cursor < self->sentinel)
		return (true);
	else
		return (false);
}

char char_itr_next(t_char_itr *self)
{
	if (char_itr_has_next(self))
		self->cursor++;
	return (*self->cursor);
}