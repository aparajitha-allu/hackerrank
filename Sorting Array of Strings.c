
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int count_distinct(const char *s){
    int freq[26] = {0}, cnt = 0;
    for(int i = 0; s[i]; i++){
        if(!freq[s[i] - 'a']){
            freq[s[i] - 'a'] = 1;
            cnt++;
        }
    }
    return cnt;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int da = count_distinct(a);
    int db = count_distinct(b);

    if(da == db) 
        return lexicographic_sort(a, b);
    return da - db;
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) == strlen(b)) 
        return lexicographic_sort(a, b);
    return strlen(a) - strlen(b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(cmp_func(arr[i], arr[j]) > 0){
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
