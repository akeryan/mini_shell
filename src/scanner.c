#include "scanner.h"

t_scanner scanner_value(t_char_itr char_itr)
{
	t_scanner scanner;
	scanner.char_itr = char_itr;	
	scanner.next = char_itr_peek(&scanner.char_itr);
	return (scanner);
}

bool scanner_has_next(const t_scanner *self)
{
	if (self->next)
		return (true);
	else
		return (false);
}

t_token scanner_peek(const t_scanner *self)
{
	t_token	token;
	char	lex;	

	if (scanner_has_next(self))
	{
		lex = char_itr_peek(&self->char_itr); 
		if ( lex == ' ')
		{
			token.type = SPACE_TOKEN;
			token.lexeme = lex;
		}
		else if (lex == '(')
		{
			token.type = LPAREN_TOKEN;
			token.lexeme = lex;
		}
		else if (lex == ')')
		{
			token.type = RPAREN_TOKEN;
			token.lexeme = lex;
		}
		else if (lex == '\0')
		{
			token.type = END_TOKEN;
			token.lexeme = lex;
		}
		else 
		{
			token.type = CHAR_TOKEN;
			token.lexeme = lex;
		}
	}
	else
	{
		token.type = END_TOKEN;
		token.lexeme = '\0';
	}
	return (token);
}

t_token scanner_next(t_scanner *self)
{
	t_token token;

	token = scanner_peek(self);
	char_itr_next(&self->char_itr);
	return (token);
}