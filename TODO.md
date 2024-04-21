```
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    TODO.md                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algarrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:24:19 by algarrig          #+#    #+#              #
#    Updated: 2024/03/21 11:24:19 by algarrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```

# PROJECT WIDE TODOs

## General

- Add liscence if made public

## Subject

- [x] Display **prompt**
- [x] Working **history**
- [ ] Search and launch executable based on PATH, rel or abs path
- [/] Implement `<`, `>`, `<<`, `>>`
- [ ] Implement pipes
- [x] Handle enviroment vars
- [ ] Handle $?
- [x] Handle C-C C-D C-\
- [ ] Implement builtins (no opts unless stated otherwise):
  - [x] echo (with opt -n)
  - [x] cd (only rel and abs paths)
  - [x] pwd
  - [x] export
  - [x] unset
  - [x] env (no args)
  - [ ] exit

## Restrictions

- No more than 1 global variable, if any
- Don't interpret unclosed quotes or unmenttioned special chars (eg. `\`, `;`)

## Builtins

- Possibly change `return (0);` to `exit(EXIT_SUCCESS)`?
  though it seems more verbose in a good way I do remember that exit doesn't
  play well with threads? But we're not using threads we're using forks soooo...
