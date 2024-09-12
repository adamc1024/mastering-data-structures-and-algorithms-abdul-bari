#include <stdio.h>
#include <stdlib.h>

int str_len(char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i ++) {
    }
    return i;
}

void print_str_el(char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i ++) {
        printf("%c: %d\n", str[i], str[i]);
    }
}

void upper(char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] >= 91 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
}

void lower(char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
}

void toggle(char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
        else if (str[i] >= 91 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
}

void capitalize(char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i ++) {
        if (i == 0 && str[i] >= 91 && str[i] <= 122)
            str[i] -= 32;
        else if (i > 0 && str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
}

int vowel_count(char * str) {
    int result = 0;
    int temp = 0;
    for (int i = 0; str[i] != '\0'; i ++) {
        temp = str[i];
        if (str[i] >= 91 && str[i] <= 122) {
            temp -= 32;
        }
        switch (temp) {
        case 65:
            result++;
            break;
        case 69:
            result++;
            break;
        case 73:
            result++;
            break;
        case 79:
            result++;
            break;
        case 85:
            result++;
            break;    
        default:
            break;
        }
    }
    return result;
}

int consonant_count(char * str) {
    int result = 0;
    int temp = 0;
    for (int i = 0; str[i] != '\0'; i ++) {
        temp = str[i];
        if (temp >= 91 && temp <= 122) {
            temp -= 32;
        }
        if (temp >= 65 && temp <= 90) {
            switch (temp) {
            case 65:
                break;
            case 69:
                break;
            case 73:
                break;
            case 79:
                break;
            case 85:
                break;    
            default:
                result++;
                break;
            }
        }
    }
    return result;
}

int word_count(char * str) {
    int word = 0;
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 32 && ! word) {
            word = 1;
            result++;
        }
        else if (str[i] == 32 && word) {
            word = 0;
        } 
    }
    return result;
}

int is_valid_str(char * str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (! (str[i] >= 65 && str[i] <= 90) || ! (str[i] >= 97 && str[i] <= 122)) {
            return 0;
        }
    }
    return 1;
}

int is_valid_char(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return 1;
    }
    return 0;
}

int is_upper(char c) {
    if (c >= 65 && c <= 90) {
        return 1;
    }
    return 0;
}

char char_upper(char x) {
    return ! is_upper(x) ? x - 32 : x;
}

void char_swap(char * str, int x, int y) {
    char temp;
    temp = str[x];
    str[x] = str[y];
    str[y] = temp;
}

void reverse_str(char * str) {
    int n = str_len(str);
    int i = 0, j = n - 1;
    while (i < j) {
        char_swap(str, i, j);
        i++;
        j--;
    }
}

int is_palindrome(char * str) {
    int n = str_len(str);
    int i = 0, j = n - 1;
    char temp_a, temp_b;
    while (i < j) {
        if (is_valid_char(str[i]) && is_valid_char(str[j])) {
            temp_a = (str[i] >= 91 && str[i] <= 122) ? str[i] - 32 : str[i];
            temp_b = (str[j] >= 91 && str[j] <= 122) ? str[j] - 32 : str[j];
            if (temp_a != temp_b) {
                return 0;
            }
            i++; 
            j--;
        }
        else {
            i = ! is_valid_char(str[i]) ? i + 1 : i;
            j = ! is_valid_char(str[j]) ? j - 1 : j; 
        }
    }
    return 1;
}

int str_comparison(char * str_a, char * str_b) {
    int i = 0, j = 0;
    int temp_a, temp_b;
    while (str_a[i] != '\0' || str_b[j] != '\0') {
        temp_a = is_upper(str_a[i]) ? str_a[i] + 32 : str_a[i];
        temp_b = is_upper(str_b[j]) ? str_b[j] + 32 : str_b[j];
        if (temp_a < temp_b) {
            return 0;
        }
        else if (temp_a > temp_b) {
            return 2;
        }
        i = str_a[i] != '\0' ? i + 1 : i;
        j = str_b[j] != '\0' ? j + 1 : j;
    }
    return 1;
}

void duplicates(char * str) {
    char max_ch, min_ch, temp;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (is_valid_char(str[i])) {
            temp = char_upper(str[i]);
            max_ch = temp;
            min_ch = temp;
            break;
        }
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (is_valid_char(str[i])) {
            temp = char_upper(str[i]);
            if (temp > max_ch) {
                max_ch = temp;
            }
            if (temp < min_ch) {
                min_ch = temp;
            }
        }
    }
    int * H = (int *) malloc((max_ch - min_ch + 1)*sizeof(int));
    for (int i = 0; i < max_ch + 1; i++) {
        H[i] = 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_valid_char(str[i])) {
            temp = char_upper(str[i]);
            H[temp - min_ch]++;
        }
    }
    for (int i = 0; i < max_ch + 1; i++) {
        if (H[i] > 0) {
            printf("%c appears %d time(s)\n", i + min_ch, H[i]);
        }
    }
    free(H);
}

void duplicates_2(char * str) {
    int h = 0, x = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        x = 1;
        x = x<<(str[i] - 97);
        if ((x & h) > 0) {
            printf("%c is duplicate\n", str[i]);
        }
        else{
            h = x | h;
        }
    }
}

int is_anagram(char * str_a, char * str_b) {
    if (str_len(str_a) == str_len(str_b)) {
        int i;
        int H[26] = {0};
        for (i = 0; str_a[i] != '\0'; i++) {
            H[str_a[i] - 97]++;
        }
        for (i = 0; str_b[i] != '\0'; i++) {
            H[str_b[i] - 97]--;
            if (H[str_b[i] - 97] < 0) {
                return 0;
            }
        }
        for (i = 0; i < 26; i ++) {
            if (H[i] != 0) {
                return 0;
            }
        }
        return 1;
    }
    else {
        return 0;
    }
}

void rotate(char * str) {
    char head = str[0];
    int n = str_len(str);
    for (int i = 0; i < n - 1; i++) {
        str[i] = str[i + 1];
    }
    str[n - 1] = head;
}

int count = 0;

void perm(char * str, int low, int high) {
    count++;
    printf("%d\n", count);
    int i;
    if (low == high) {
        printf("%s\n", str);
    }
    else {
        for (i = low; i <= high; i++) {
            char_swap(str, low, i);
            perm(str, low + 1, high);
            char_swap(str, low, i);
        }
    }
}

int main () {
    // char S[8] = {'w', 'E', 'l', 'C', 'o', 'M', 'e', '\0'};
    // same result --> char S[] = "welcome";
    // printf("Length of '%s' is %d.\n", S, str_len(S));
    // toggle(S);
    // printf("%s\n", S);
    // capitalize(S);
    // printf("%s\n", S);
    // upper(S);
    // printf("%s\n", S);
    // lower(S);
    // printf("%s\n", S);
    // reverse_str(S);
    // printf("%s\n", S);

    // char A[] = "How are   u?";
    // printf("%s\n", A);
    // print_str_el(A);
    // printf("Vowels: %d\n", vowel_count(A));
    // printf("Consonants: %d\n", consonant_count(A));
    // printf("Words: %d\n", word_count(A));
    // printf("%d\n", is_valid_str(A));

    // char B[] = "painting"; 
    // char C[] = "painter";
    // printf("%d\n", str_comparison(B, C));

    // char P[] = "Madam, I'm Adam.";
    // printf("%d\n", is_palindrome(P));
    // printf("%d\n", is_palindrome(A));

    // char D[] = "the quick brown fox jumps over the lazy dog";
    // duplicates_2(D);

    // char E[] = "verbose";
    // char F[] = "observe";
    // printf("%d\n", is_anagram(E, F));
    // rotate(F);
    // printf("%s\n", F);

    char G[] = "ABC";
    perm(G, 0, str_len(G) - 1);
    return 0;
}