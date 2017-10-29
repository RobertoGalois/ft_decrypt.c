#include    <stdlib.h>
#include    "ft_perso.h"

int     ft_isnumber(char c)
{
        if ((c > 47) && (c < 58))
            return (1);

        else
            return (0);
}

char*   ft_strdup(char *src)
{
        char*   ret_str;
        int     size_src;
        int     count;

        ret_str = NULL;
        size_src = 0;
        count = 0;

        /* get the size of src */
        while (src[size_src++] != '\0');

        /* create a space memory to put the copy of src  */
        ret_str = (char*)malloc(sizeof (*src) * size_src);
        if (ret_str == NULL)
            return (NULL);

        /* copy each char of src in ret_str */
        while (count < size_src)
        {
            ret_str[count] = src[count];
            count++;
        }

        return (ret_str);
}

unsigned    int ft_getsize(char* str, char limiter)
{
            unsigned int    ret;
            int             count;

            ret = 2;    /* first data + 0 */
            count = 0;
            while (str[count] != '\0')
            {
                if (str[count] == limiter)
                    ret++;

                count++;
            }

            return (ret);
}

char**      ft_split(char* str, char limiter)
{
            char**          ret_arr;
            unsigned int    size_ret_arr;
            int             count;
            char            buf[1000];
            int             indx[2] = {0, 0};

            size_ret_arr = ft_getsize(str, limiter);
            ret_arr = (char**)(malloc(sizeof (char*) * size_ret_arr));
            count = -1;
            while (1)
            {
                if ((str[++count] != limiter) && (str[count] != '\0'))
                    buf[indx[1]++] = str[count];

                else
                {
                    buf[indx[1]] = '\0';
                    ret_arr[indx[0]++] = ft_strdup(buf);
                    indx[1] = 0;
                    if (str[count] == '\0')
                        break;
                }
            }

            return (ret_arr);
}

t_perso     **ft_decrypt(char *str)
{
            int         count;
            char**      datas_allstruc;
            char**      datas_struc;
            t_perso**   ret;

            datas_allstruc = ft_split(str, ';');
            ret = (t_perso**)(malloc(sizeof (t_perso*) * ft_getsize(str, ';')));
            count = 0;
            while (datas_allstruc[count] != 0)
            {
                ret[count] = (t_perso*)(malloc(sizeof (t_perso)));
                datas_struc = ft_split(datas_allstruc[count], '|');
                if (datas_struc[0] != '\0')
                    ret[count]->age = ft_strdup(datas_struc[0]);

                if (datas_struc[1] != '\0')
                    ret[count]->name = ft_strdup(datas_struc[1]);

                count++;
            }

            return (ret);
}
