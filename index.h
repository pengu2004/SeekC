typedef struct Word {
    char *text;
    int count;
    struct Word *next;
} Word;


Word *add_word(Word *head,const char *word);
void print_words(Word *head);
void free_words(Word *head);
