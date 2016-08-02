#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int    value;
  struct _node* left;
  struct _node* right;
}Node; 

Node* makeNode(int n){
  Node* newnode;
  newnode = (Node*)malloc(sizeof(Node));  
  newnode->value = n;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

Node* addNode(Node* node, int n){
  if (node != NULL)  {
    if(node->value < n){
      if(node->right) {
	return  addNode(node->right,  n);
      }else{
	node->right = makeNode(n);
	return 	node->right;
      }
    }else{
      if(node->left){
	return addNode(node->left,  n);
      }else{
	node->left = makeNode(n);
	return 	node->left;
      }
    }
  }else{
    return makeNode(n);
  }
} 

int get_min(Node* node){
  int ret;
  if(node->left){
    return get_min(node->left);
  }else{
    return node->value;
  }
}

int get_max(Node* node){
  int ret;
  if(node->right){
    return get_max(node->right);
  }else{
    return node->value;
  }
}

void walk(Node* node){
  if(node){
    walk(node->left);
    printf("%d\n", node->value);
    walk(node->right);
  }
}    


void ikigake(Node* node){
  if(node){
    walk(node->left);
    printf("%d\n", node->value);
    walk(node->right);
  }
}    


void kaerigake(Node* node){
  if(node){
    walk(node->left);
    printf("%d\n", node->value);
    walk(node->right);
  }
}    


int main(void){

  int n;
  Node* root;
  Node* tmp;

  root = addNode(NULL, 5);
  tmp = addNode(root, 3);
  tmp = addNode(root, 4);
  tmp = addNode(root, 8);
  tmp = addNode(root, 15);
  tmp = addNode(root, 2);


  printf("どの順番で表示しますか。（数字だけ入力してください。）\n１、行きがけ順\n２、通りがけ順\n３、帰りがけ順\n");
  scanf("%d", &n);
 

  if(n=2){
  walk(root);
  };
 
  return 0;
}     
