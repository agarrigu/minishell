```
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algarrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:22:03 by algarrig          #+#    #+#              #
#    Updated: 2024/03/21 11:22:03 by algarrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```

# MINISHELL

Travel through time and come back to problems people faced when _Windows_ didn't
exist.

## General aproach:

```
[Lexer] => [Parser] => [execer] => [cleaner?]
[Signal handling]

```
According to the bash manual, roughly speaking the sequence could be:

1. Read input
1. Divide into words and operators
1. Expand $vars
1. redirect in
1. exec left to right inc. pipes
1. redirect out
