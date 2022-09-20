#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"

struct line
{
    size_t len;
    char *ptr;
}

struct text
{
    size_t num_str;
    char *buf;
    size_t n;
    struct line *Strings;
}

int main()
{
    //-------input----------
    FILE* fpin = fopen ("Onegin.txt", "r");
    if (fpin == NULL)
    {
        printf ("Cannot open\n");
        return (EXIT_FAILURE);
    }

    size_t text_size = text_len (fpin);

    struct text *buf = (char*) calloc (text_size + 1, sizeof(char));

    if (buf == NULL)
    {
        printf ("Not enought memory\n");
        return (EXIT_FAILURE);
    }


    size_t n = fread (buf, 1, text_size, fpin);
    fclose (fpin);

    size_t num_str = number_str (buf, n, '\n');

    char **text_pointer = new char* [num_str];
    pointer (text_pointer, buf, text_size, '\n');
    //--------end of input----------


    FILE* fpout = fopen ("output.txt", "w");

    if (fpout == NULL)
    {
        printf ("Cannot open\n");
        return (EXIT_FAILURE);
    }


    Myqsort (text_pointer, 0, num_str, &Strcmp);

    fprintf (fpout, "\n-----SORTED-----\n");
    output (fpout, text_pointer, num_str);


    qsort (text_pointer, num_str, sizeof (text_pointer[0]), &rev_Strcmp);

    fprintf (fpout, "\n-----REVERSE-----\n");
    output (fpout, text_pointer, num_str);


    output_origin (fpout, buf, n);

    fclose (fpout);

    free (buf);
    free (text_pointer);

}
