#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <sys\stat.h>

#include "functions.h"


int Strcmp (const void *ptr1, const void *ptr2)
{
    assert (ptr1 != NULL);
    assert (ptr2 != NULL);

    const char *str1 = (const char*) ptr1;
    const char *str2 = (const char*) ptr2;


    while (*str1 != '\0' || *str2 != '\0')
    {
        if (ispunct (*str1) != 0)
        {
            str1++;
            continue;
        }
        if (ispunct (*str2) != 0)
        {
            str2++;
            continue;
        }

        if (tolower (*str1) != tolower (*str2))
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }

    return 0;

}


int rev_Strcmp (const void *ptr1, const void *ptr2)
{
    assert (ptr1 != NULL);
    assert (ptr2 != NULL);

    const char *str1 = *(const char**) ptr1;
    const char *str2 = *(const char**) ptr2;

    int len1 = strlen (str1);
    int len2 = strlen (str2);

    str1 += len1;
    str2 += len2;

    while (len1 != 0 && len2 != 0)
    {
        if (ispunct (*str1) != 0)
        {
            str1--;
            len1--;
            continue;
        }
        if (ispunct (*str2) != 0)
        {
            str2--;
            len2--;
            continue;
        }

        if (tolower (*str1) != tolower (*str2))
        {
            return *str1 - *str2;
        }
        str1--;
        str2--;
        len1--;
        len2--;
    }

    return 0;
}



void Swap (char *text_pointer[], int i, int j)
{
    assert (text_pointer[i] != NULL);
    assert (text_pointer[j] != NULL);

    char *temp = text_pointer[i];
    text_pointer[i] = text_pointer[j];
    text_pointer[j] = temp;
}


void output (FILE *fp, char *text_pointer[], size_t num_str)
{
    assert (fp != NULL);
    assert (text_pointer != NULL);

    for (size_t i = 0; i < num_str; i++)
    {
        if (!*text_pointer[i])
            continue;

        fprintf (fp, "%s\n", text_pointer[i]);
    }
}


void output_origin (FILE *fp, char buf[], size_t n)
{
    assert (fp != NULL);
    assert (buf != NULL);

    fprintf (fp, "\n-----ORIGINAL-----\n");
    for (size_t i = 0; i < n; i++)
    {
        if (buf[i] == '\0')
                fprintf (fp, "\n");
        else
            fprintf (fp, "%c", buf[i]);
    }
}


size_t text_len (FILE *fp)
{
    assert (fp != NULL);

    struct stat buff;
    fstat (fileno (fp), &buff);

    return buff.st_size;
}


void pointer (char *text_pointer[], char buf[], size_t text_size, char ch)
{
    assert (text_pointer != NULL);
    assert (buf != NULL);

    text_pointer[0] = &buf[0];

    size_t nline = 1;
    for (size_t i = 0; i < text_size - 1; ++i)
    {
        if (buf[i] == ch)
        {
            text_pointer[nline] = &buf[i + 1];
            if (buf[i] == ch)
            {
                buf[i] = '\0';
            }
            ++nline;
        }
    }
}


void Myqsort (char *text_pointer[], int left, int right, int (*comp) (const void *ptr1, const void *ptr2))
{
    assert (text_pointer != NULL);
    assert (comp != NULL);

    if (left >= right)
        return;

    Swap (text_pointer, left, (left+ right) / 2);

    int last = left;
    for (int i = left + 1; i <= right; i++)
        if ((*comp) (text_pointer[i], text_pointer[left]) < 0)
            Swap (text_pointer, ++last, i);

    Swap (text_pointer, left, last);

    Myqsort (text_pointer, left, last - 1, comp);
    Myqsort (text_pointer, last + 1, right, comp);
}


size_t number_str (char buf[], size_t n, char ch)
{
    assert (buf != NULL);

    size_t num = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (buf[i] == ch)
            ++num;
    }
    return num;
}
