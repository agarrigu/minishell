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

## Building:

This should work on any POSIX-ish system but has only been tested on Debian Linux, only real dependecy is `make`.

First clone the repository, then navigate to it and:

`$ make`

or if you want simbols for debugging

`$ make debug`

## Executing:

The executable will be created at the top of the repos directory tree.

`$ ./minishell`

or for debugging

`$ ./debug_build`

## Features

Limited functionality conforming to IEEE Std 1003.1-2017 and the GNU Bash manual.

## Built from scratch

- Parser
- Expander
- Heredoc
- Enviroment variables
- The following builtins: cd, pwd, exit, echo, env, export, unset
- Pipes
