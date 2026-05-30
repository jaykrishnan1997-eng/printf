*This project has been created as part of the 42 curriculum by [jkrishna].*

# ft_printf

## Description

`ft_printf` is a re-implementation of the standard C `printf` function from scratch, without using the original. The goal is to understand variadic functions, format string parsing, and low-level output formatting in C.

The function parses a format string and handles a set of conversion specifiers, writing formatted output to standard output and returning the total number of characters written.

### Supported conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address (hex) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hex (lowercase) |
| `%X` | Unsigned hex (uppercase) |
| `%%` | Literal percent sign |

---

## Instructions

### Compilation

The project compiles into a static library `libftprintf.a`.

```bash
make
```

This runs:
```bash
cc -Wall -Wextra -Werror -c <files>.c
ar rcs libftprintf.a <objects>.o
```

### Cleaning

```bash
make clean    # removes object files
make fclean   # removes object files and library
make re       # fclean + rebuild
```

### Usage

Link the library in your project:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

Include the header in your code:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    return (0);
}
```

---

## Algorithm and Data Structure

### Approach

`ft_printf` scans the format string character by character using a `while` loop and an index `i`. When it encounters a `%` followed by a valid specifier, it dispatches to a dedicated handler function via `ft_channel`. Otherwise it writes the character directly using `write`.

A running `count` variable tracks total characters written, which is returned at the end.

### Dispatch via ft_channel

Rather than a large nested `if-else` inside `ft_printf` itself, the specifier routing is delegated to `ft_channel(char specifier, va_list *args)`. This keeps `ft_printf` clean and makes adding new specifiers straightforward — only `ft_channel` needs to change.

Each specifier maps to its own function:

```
%c → ft_cprintf      (writes a single char)
%s → ft_sprintf      (iterates and writes each char of a string)
%p → ft_pprintf      (formats pointer as 0x + hex)
%d/%i → ft_diprintf  (handles sign, converts int to ASCII digits)
%u → ft_uprintf      (unsigned version of above)
%x → ft_xprintf      (hex with lowercase a-f)
%X → ft_cxprintf     (hex with uppercase A-F)
%% → ft_percprintf   (writes a literal %)
```

### Variadic Arguments

`va_list` from `<stdarg.h>` is used to access arguments at runtime. `va_start` initialises it, `va_arg` retrieves each argument by type, and `va_end` cleans up. The pointer to `va_list` is passed to `ft_channel` so each handler can pull its own argument.

### Data Structures

No heap allocation or complex data structures are used. The function operates entirely on the stack using the format string pointer, a counter, and the `va_list`.

---

## Resources

- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — official printf specification
- [cppreference: va_list](https://en.cppreference.com/w/c/variadic) — variadic function documentation
- [42 Docs](https://harm-smits.github.io/42docs/projects/ft_printf) — community reference for ft_printf

### AI Usage

Claude (claude.ai) was used during this project in the following ways:

- **Conceptual guidance**: Understanding how `va_list`, `va_start`, `va_arg`, and `va_end` work together for variadic functions.
- **Debugging**: Identifying edge cases in specifier handling and return value counting.
- **README writing**: This README was drafted with Claude's assistance based on the project code and 42 requirements.

Claude did not write the implementation code directly. All logic was reasoned through and written by the student, with Claude acting as a guide asking questions rather than providing answers.
