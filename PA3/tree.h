
typedef struct Tnode {
   int id;
   int width;
   int height;
   int x;
   int y;
   int dimX;
   int dimY;
   int flag;
   struct Tnode *left;
   struct Tnode *right;
} Tnode;

//Tnode* buildTree(Tnode* root, Snode* stack);
// void Postorder(Tnode *node);
Tnode* createNode(int id, int width, int height);
void preorder(Tnode *node);
void postorder(Tnode *node);
void preorderCoordinates(Tnode *node);
int isMax(int n1, int n2);
// void Inorder(Tnode *node);
void Destroy_tree(Tnode *node);


