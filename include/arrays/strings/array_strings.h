#ifndef ARRAY_STRINGS_H
#define ARRAY_STRINGS_H

/* Returns length of the array */
int my_strlen(const char * string);

/* Returns position of s2 inside s1 */
int my_strpos(const char * s1, const char * s2);

/* Concatenate two strings */
void my_strcat(char * s1, const char * s2);

/* Creates a substring */
void my_substr(const char * s1, int i, int j, char * s2);

#endif
