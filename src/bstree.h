#ifndef BSTREE
#define BSTREE

typedef struct bstree
{
    char *key;
    int value;
    struct bstree *left;
    struct bstree *right;
} bstree;

struct bstree *bstree_create(char *key, int value);

void bstree_add(struct bstree *tree, char *key, int value);

struct bstree *bstree_lookup(struct bstree *tree, char *key);

struct bstree *bstree_min(struct bstree *tree);

struct bstree *bstree_max(struct bstree *tree);

#endif