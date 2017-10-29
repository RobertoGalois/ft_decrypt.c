#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    "ft_perso.h"

t_perso     **ft_decrypt(char *str);
char**      ft_split(char* str, char limiter);


void    ft_showinfos(t_perso* perso)
{
        printf("Personnage informations:\n");
        printf("Name: %s\n", perso->name);
        printf("Age: %d\n", perso->age);
}

t_perso*    ft_init_perso(char* p_name, int p_age)
{
        t_perso*    ret;

        ret = (t_perso*)(malloc(sizeof (t_perso)));
        ret->name = strdup(p_name);
        ret->age = p_age;
        return (ret);
}

void    ft_showarr(t_perso** p_arr)
{
        int     count;

        count = 0;
        while (p_arr[count] != 0)
        {
            ft_showinfos(p_arr[count]);
            count++;
        }
}

void    ft_printfarr(char** p_arr)
{
        int     count;

        count = 0;
        while (p_arr[count] != 0)
        {
            printf("%s\n", p_arr[count]);
            count++;
        }
}

int     main(int argc, char** argv)
{
        if (argc == 2)
            ft_showarr(ft_decrypt(argv[1]));

        return (0);
}
