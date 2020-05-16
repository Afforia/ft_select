#include <termcap.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <termios.h>
#include "colors.h"
#include "keys.h"

typedef struct  s_arg {
    char            *argv;
    int             len;
    struct s_arg    *prev;
    struct s_arg    *next;
}               t_arg;

typedef struct  s_select
{
    int         max_len;
    t_arg       *curr;
    t_arg       *selected;
}               t_select;


typedef struct		s_shell {
	char			*term;
	struct termios	new_param;
	struct termios	old_param;
}                   t_shell;


t_arg static     *read_arguments(char **argv, int argc, t_select *sel) {
    int i = 1;
    t_arg   *ret;
    t_arg   *tmp_prev;
    t_arg   *head;

    ret = NULL;
    sel->max_len = 0;
    if (!(ret = (t_arg *)malloc(sizeof(t_arg)))) //TODO: need to free if not first iteration
        return NULL;
    tmp_prev = NULL;
    while (i < argc) {
        ret->argv = ft_strdup(argv[i]);
        ret->len = ft_strlen(argv[i]);
        sel->max_len = sel->max_len < ret->len ? ret->len : sel->max_len; 
        ret->next = NULL;
        if (i == 1) {
            ret->prev = NULL;
            tmp_prev = ret;
            head = ret;
        }
        else {
            ret->prev = tmp_prev;
            tmp_prev = ret;
        }
        i++;
        if (i < argc)
            ret->next = (t_arg *)malloc(sizeof(t_arg));
        ret = ret->next;
    }
    ret = head;
    return (ret);
}

t_shell		*init_term(t_shell *shell)
{
	if (!(shell = (t_shell *)malloc(sizeof(t_shell))))
		return (NULL);
	shell->term = ft_strdup("xterm-256color");
	tgetent(NULL, shell->term);
    tcgetattr(0, &shell->new_param);
    tcgetattr(0, &shell->old_param);
	shell->new_param.c_lflag &= ~(ICANON | ECHO);
	shell->new_param.c_cc[VMIN] = 1;
	shell->new_param.c_cc[VTIME] = 0;
    tcsetattr(0, TCSADRAIN, &shell->new_param);
	return (shell);
}

int             putint(int i) {
    return (write(1, &i, 1));
}

int            put_spaces(int col, int ws_col, int diff) {
    if (diff == 0 || (diff + col) >= ws_col)
        return (1);
    while (diff >= 0) {
        ft_putchar(' ');
        diff--;
    }
    return (0);
}

void            print_arg(struct winsize ws, t_arg *arg, t_select *sel) {
    int     col;

    col = 0;
    while (arg) {
        col += arg->len;
        //ft_putnbr(col);
        if (col >= ws.ws_col - 5) {
            //ft_putnbr(col);
            col = arg->len;
            ft_putendl("");
        }
        //if (ft_strequ(arg->argv, "dsfj2"))
        //    ft_putnbr(col);
        ft_putstr(arg->argv);
        if (!(put_spaces(col, ws.ws_col, (sel->max_len - arg->len) + 1)))
            col += (sel->max_len - arg->len) + 1;
        else {
            ft_putendl("");
            col = 0;
        }
        arg = arg->next;
    }
}

void            loop(struct winsize ws, t_arg *arg, t_select *sel) {
    t_arg   *head = arg;
    char    *buf;

    buf = ft_strnew(10);
    ft_putendl("ft_select: ");
    print_arg(ws, arg, sel);
    ft_putstr("\n");
    while (1) {
        read(STDIN_FILENO, buf, 10);
        if (buf[0] == ENTER)
            return ;
    }
}

int             main(int argc, char **argv) {
    t_arg       *arg_list;
    struct winsize  ws;
    t_shell     *shell;
    t_select    *sel;
    
    shell = NULL;
    arg_list = NULL;
    sel = (t_select *)malloc(sizeof(t_select));
    shell = init_term(shell);
    if (argc > 1) {
        if (!(arg_list = read_arguments(argv, argc, sel)))
            return (1);
        ioctl(0, TIOCGWINSZ, &ws); //TODO: err check
        tputs(tgetstr("cl", NULL), 1, putint);
        tputs(tgetstr("vi", NULL), 1, putint);
        loop(ws, arg_list, sel);
    } else {
        ft_putendl("ft_select usage: ");
    }
    tcsetattr(0, TCSADRAIN, &shell->old_param);
    tputs(tgetstr("ve", NULL), 1, putint);
    return (0);
}