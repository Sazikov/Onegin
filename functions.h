#include <string.h>
#include <stdio.h>

/**
@brief Compares two strings from left to right
@param[out] ptr1 Pointer to a first string to compare
@param[out] ptr2 Pointer to a second string to compare
@return Negative value if the first string appears before the second string in lexicographical order, Zero if the first string and the second string compare equal, Positive value if the first string appears after the second string in lexicographical order.
*/
int Strcmp (const void *ptr1, const void *ptr2);

/**
@brief Compares two strings from right to left
@param[out] ptr1 Pointer to a first string to compare
@param[out] ptr2 Pointer to a second string to compare
@return Negative value if the first string appears before the second string in lexicographical order, Zero if the first string and the second string compare equal, Positive value if the first string appears after the second string in lexicographical order.
*/
int rev_Strcmp (const void *ptr1, const void *ptr2);

/**
@brief Swap two strings from the array
@param[out] Pointer to the array
@param[in] Number of the first string in array
@param[in] Number of the second string in array
*/
void Swap (char *v[], int i, int j);


/**
@brief Used to print sorted array
@param[out] Pointer to the file
@param[out] Pointer to the pointer array
@param[in] Number of lines in file
*/
void output (FILE *fp, char *text_pointer[], size_t num_str);

/**
@brief Used to print original text
@param[out] Pointer to the file
@param[in] Array with all text
@param[in] Number of symbols in file without '\r'
*/
void output_origin (FILE *fp, char buf[], size_t n);

/**
@brief Fills an array of pointers
@param[out] Pointer to the empty pointer array
@param[in] Array with all text
@param[in] Number of all symbols in file
@param[in] Symbol of end of line
*/
void pointer (char *text_pointer[], char buf[], size_t text_size, char ch);

/**
@brief Used to determine the number of symbols in a file
@param[out] Pointer to the file
@return Number of lines in file
*/
size_t text_len (FILE *fp);


/**
@brief Sort array of the pointer using an algorithm of quick sort
@param[out] Pointer to the array
@param[in] Left border
@param[in] Right border
@param[out] Pointer to the comparison function
*/
void Myqsort (char *text_pointer[], int left, int right, int (*comp) (const void *ptr1, const void *ptr2));

size_t number_str (char buf[], size_t n, char ch);
