#ifndef TOKEN_H
#define TOKEN_H

typedef enum e_token_type {
	END_TOKEN = 0,
	CHAR_TOKEN = 1,
	SPACE_TOKEN = 2,
	LPAREN_TOKEN = 3,
	RPAREN_TOKEN = 4
} t_token_type;

typedef struct s_token {
	t_token_type type;
	char lexeme;
} t_token;

#endif