/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/08 13:29:17 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main() {
    char *input;

	 add_history("Dastan");

    while ((input = readline("Enter command: ")) != NULL) {
        if (*input) {  // Only add non-empty strings to the history
            add_history(input);
        }

        printf("You entered: %s\n", input);
        free(input);
    }

    return 0;
}
