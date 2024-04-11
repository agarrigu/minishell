```
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CONTRIBUTING.md                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algarrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 10:59:16 by algarrig          #+#    #+#              #
#    Updated: 2024/03/21 11:00:04 by algarrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```

# Contributing

## Developer Guidelines

- All pushes must pass norminette
- Features should be created in seperate branches and merged to dev
- Commit often and commit sensefully
- TODOs and NOTEs in comments should have a name, e.g.:
  ```c
  /* TODO(alice): Make sure to do a thing */
  /* NOTE(alice): This thing is a thing */
  ```

## Coding style

- Whenver possible do:

  ```c
  t_my_struct ms;

  init_my_struct(&ms);
  use_mystruct(&ms)
  ```

  instead of:

  ```c
  t_my_struct *ms;

  ms = malloc(sizeof(*ms));
  init_my_struct(ms);
  use_mystruct(ms);
  free(ms);
  ```
