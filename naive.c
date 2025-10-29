#include <stdio.h> 
#include <string.h> 
 
int main() { 
    char text[1000], pattern[100]; 
    int textLen, patLen, i, j; 
    int found = 0; 
 
    printf("Enter the text: "); 
    fgets(text, sizeof(text), stdin); 
 
    printf("Enter the pattern to search: "); 
    fgets(pattern, sizeof(pattern), stdin); 
 
    text[strcspn(text, "\n")] = '\0'; 
    pattern[strcspn(pattern, "\n")] = '\0'; 
 
    textLen = strlen(text); 
    patLen = strlen(pattern); 
 
    printf("\nPattern found at indices: "); 
 
    for (i = 0; i <= textLen - patLen; i++) { 
        for (j = 0; j < patLen; j++) { 
            if (text[i + j] != pattern[j]) { 
                break; 
            } 
        }  if (j == patLen) { 
            printf("%d ", i); 
            found = 1; 
        } 
    } 
 
    if (!found) { 
        printf("No occurrences found."); 
    } 
 
    return 0; 
}