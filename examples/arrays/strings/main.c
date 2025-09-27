#include <array_strings.h>
#include <stdio.h>

int main(int argc, char ** argv)
{

    char s1[50] = "This is my array";
    printf("Original string: %s\n", s1);

    // Get array length
    int s1_len = my_strlen(s1);
    printf("Length of s1 is: %d\n", s1_len);

    char s2[20] = "array";
    printf("Second string: %s\n", s2);

    // Return substring position
    int s2_pos = my_strpos(s1, s2);
    printf("Position of s2: %d\n", s2_pos);

    // Concatenate strings
    my_strcat(s1, s2);
    printf("Concatenated string: %s\n", s1);

    // Create a substring
    char s3[50];
    my_substr(s1, s2_pos, 5, s3);
    printf("Substring: %s\n", s3);

    return 0;
}
