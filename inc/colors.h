#ifndef COLORS_H
# define COLORS_H

# define RESET			"\x1B[0m"
# define BOLD			"\x1B[1m"
# define UNDERLINE		"\x1B[4m"
# define REVERSED		"\x1B[7m"

/*
** Regular colors
*/

# define BLACK			"\x1B[30m"
# define RED			"\x1B[0;31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAGENTA		"\x1B[35m"
# define CYAN			"\x1B[36m"
# define WHITE			"\x1B[37m"

/*
** Bright colors
*/

# define BBLACK			"\x1B[30;1m"
# define BRED			"\x1B[31;1m"
# define BGREEN			"\x1B[32;1m"
# define BYELLOW		"\x1B[33;1m"
# define BBLUE			"\x1B[34;1m"
# define BMAGNETA		"\x1B[35;1m"
# define BCYAN			"\x1B[36;1m"
# define BWHITE			"\x1B[37;1m"

/*
** Background regular colors
*/

# define BACK_BLACK		"\x1B[40m"
# define BACK_RED		"\x1B[41m"
# define BACK_GREEN		"\x1B[42m"
# define BACK_YEL		"\x1B[43m"
# define BACK_BLUE		"\x1B[44m"
# define BACK_MAG		"\x1B[45m"
# define BACK_CYAN		"\x1B[46m"
# define BACK_WHITE		"\x1B[47m"

/*
** Background bright colors
*/

# define BACK_BBLACK	"\x1B[40;1m"
# define BACK_BRED		"\x1B[41;1m"
# define BACK_BGREEN	"\x1B[42;1m"
# define BACK_BYEL		"\x1B[43;1m"
# define BACK_BBLUE		"\x1B[44;1m"
# define BACK_BMAG		"\x1B[45;1m"
# define BACK_BCYAN		"\x1B[46;1m"
# define BACK_BWHITE	"\x1B[47;1m"

#endif
