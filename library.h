struct song_node ** make_library();

int find_ind(char *a);

struct song_node ** add_song(struct song_node **lib, char *a, char *n);

struct song_node * find_song_lib(struct song_node **lib, char *a, char *n);

struct song_node * find_artist_lib(struct song_node **lib, char *a);

void print_letter(struct song_node **lib, char c);

void print_artist(struct song_node **lib, char *a);

void print_library(struct song_node **lib);

void shuffle(struct song_node **lib);

struct song_node ** remove_song_lib(struct song_node **lib, char *a, char *n);

struct song_node ** clear_library(struct song_node **lib);