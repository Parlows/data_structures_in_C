#include <arrays/strings/array_strings.h>

/* Returns length of the array */
int my_strlen(const char * string)
{
    int i;

    for(i=0; string[i] != '\0'; i++);

    return i;
}

/* Returns position of s2 inside s1 */
int my_strpos(const char * s1, const char * s2)
{
    int i, j;
    int len1, len2;

    len1 = my_strlen(s1);
    len2 = my_strlen(s2);

    for(i=0;i <= len1 - len2; i++) {
        for(j=i; j-i < len2 && s1[j] == s2[j-i] && j<len1; j++);
        if(j-i == len2)
            return i;
    }

    return -1;
}

/* Concatenate two strings */
void my_strcat(char * s1, const char * s2)
{
    // Assume s1 has enough space to hold s2 inside
    int len1, len2, i;

    len1 = my_strlen(s1);
    len2 = my_strlen(s2);

    for(i = len1; i < len1 + len2; i++)
        s1[i] = s2[i-len1];

    s1[len1+len2] = '\0';
}

/* Creates a substring, with:
*      int i: position of s1 where the substring starts.
*      int j: number of characters of substring.
*/
void my_substr(const char * s1, int i, int j, char * s2)
{
    int k;
    for(k=i; k < (i+j); k++) {
        s2[k-i] = s1[k];
    }
    s2[j] = '\0';
}