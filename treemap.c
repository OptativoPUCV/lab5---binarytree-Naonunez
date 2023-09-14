#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
  TreeMap *Mapa = (TreeMap*) malloc(sizeof(TreeMap));

  if (Mapa == NULL){
    return NULL;
  }

  Mapa->root = NULL;
  Mapa->current = NULL;
  Mapa->lower_than= lower_than;
  

    //new->lower_than = lower_than;
    return Mapa;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
  TreeNode* Nuevo = createTreeNode(key, value);
  if (tree->root == NULL){
    tree->root = Nuevo;
    tree->current = Nuevo;
  }
  else{
    tree->root = tree->current;
  }

  while(tree->current != NULL){
    if (is_equal(tree, key, tree->current->pair->key)){
      return;
  }
    if (tree-> lower_than(key, tree->current->pair->key) == 1){
      if ( tree->current->left == NULL){
        tree->current->left = Nuevo;
        Nuevo->parent=tree->current;
      }
      tree->current=tree->current->left;
    }
    else{
      if ( tree->current->right == NULL){
        tree->current->right = Nuevo;
        Nuevo->parent=tree->current;
      }
      tree->current=tree->current->right;
    }
  
}

TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
  tree->current = tree->root;
  
  while(tree->current != NULL){
    if(is_equal(tree, key, tree->current->pair->key)){
      return tree->current->pair;
    }
      
    else if (tree->lower_than(key, tree->current->pair->key)==0){
      tree->current=tree->current->right;
    }
      
    else{
      tree->current=tree->current->left;
    }
    
  }
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
