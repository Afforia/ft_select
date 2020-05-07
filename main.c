//#include <termcap.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

typedef struct  s_arg {
    char            *argv;
    struct s_arg    *prev;
    struct s_arg    *next;
}               t_arg;

t_arg static     *read_arguments(char **argv, int argc) {
    int i = 1;
    t_arg   *ret;
    t_arg   *tmp_prev;
    t_arg   *head;

    ret = NULL;
    //if (!(ret = (t_arg *)malloc(sizeof(t_arg))))
    //    return NULL;
    //ret->next = NULL;
    //ret->prev = NULL;
    if (!(ret = (t_arg *)malloc(sizeof(t_arg)))) //need to free if not first iteration
        return NULL;
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

int             main(int argc, char **argv) {
    t_arg       *arg_list;

    arg_list = NULL;
    if (argc > 1) {
        if (!(arg_list = read_arguments(argv, argc)))
        {
            return (1);
        }
        while (arg_list) {
            ft_putendl(arg_list->argv);
            arg_list = arg_list->next;
        }
    }
    return (0);
}