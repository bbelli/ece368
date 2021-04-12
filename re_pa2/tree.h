
typedef struct Tnode {
   char id; //4
   int flag; //8
   struct Tnode *left; 
   struct Tnode *right; 
} Tnode;


Tnode* createNode(char id, int flag);
Tnode *duplicate_node(const Tnode *src);
void preorder(Tnode *node);
void Destroy_tree(Tnode *node);


