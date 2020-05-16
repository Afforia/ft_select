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

typedef struct  s_arg {
    char            *argv;
    struct s_arg    *prev;
    struct s_arg    *next;
}               t_arg;

typedef struct		s_shell {
	char			*term;
	struct termios	new_param;
	struct termios	old_param;
}                   t_shell;


t_arg static     *read_arguments(char **argv, int argc) {
    int i = 1;
    t_arg   *ret;
    t_arg   *tmp_prev;
    t_arg   *head;

    ret = NULL;
    if (!(ret = (t_arg *)malloc(sizeof(t_arg)))) //need to free if not first iteration
        return NULL;
    tmp_prev = NULL;
    while (i < argc) {
        ret->argv = ft_strdup(argv[i]);
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

void            loop(struct winsize ws, t_arg *arg) {
    t_arg   *head = arg;
    ft_putendl("ft_select: ");
    while (arg) {
        ft_putstr(arg->argv);
        ft_putstr("  ");
        arg = arg->next;
    }
    ft_putstr("\n");
    while (1) {

    }
}

int             main(int argc, char **argv) {
    t_arg       *arg_list;
    struct winsize  ws;
    t_shell     *shell;
    
    shell = NULL;
    arg_list = NULL;
    shell = init_term(shell);
    if (argc > 1) {
        if (!(arg_list = read_arguments(argv, argc)))
            return (1);
        ioctl(0, TIOCGWINSZ, &ws); //TODO: err check
        tputs(tgetstr("us", NULL), 1, putint);
        tputs(tgetstr("cl", NULL), 1, putint);
        loop(ws, arg_list);
    } else {
        ft_putendl("ft_select usage: ");
    }
    tputs(tgetstr("ue", NULL), 1, putint);
    tcsetattr(0, TCSADRAIN, &shell->old_param);
    return (0);
}