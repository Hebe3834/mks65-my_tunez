struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * create_song(char *a, char *n);

void print_node(struct song_node *s);

struct song_node * insert_front(struct song_node *s, char *a, char *n);

int songcmp(struct song_node *s1, struct song_node *s2);

struct song_node * insert_order(struct song_node *s, char *a, char *n);

void print_list(struct song_node *front);

struct song_node * find_node(struct song_node *s, char *a, char *n);

struct song_node * find_artist(struct song_node *s, char *a);

int list_size(struct song_node *s);

struct song_node * random_song(struct song_node *s);

struct song_node * remove_song(struct song_node *front, char *a, char *n);

struct song_node * free_list(struct song_node *s);
