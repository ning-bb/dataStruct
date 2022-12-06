#include <stdio.h>
#include <stdlib.h>

typedef int tree_t;

//使用二叉链表实现二叉树节点
typedef struct treeNode{
    tree_t val;
    struct treeNode *lchild;
    struct treeNode *rchild;
}*bTree;

void createTree(bTree *t)  //传入一个btree的指针的地址
{
    tree_t data;
    scanf("%d", &data);

    if(data == -1) {    //-1代表终端节点值
        *t = NULL;
    } else {
        *t = (bTree)malloc(sizeof(struct treeNode));  
        (*t)->val = data;
        printf("请输入%d的左孩子节点：", data);
        createTree(&((*t)->lchild));
        printf("请输入%d的右孩子节点：", data);
        createTree(&((*t)->rchild));
    }
}

//递归先根遍历二叉树,DLR
void preOrder(bTree t)
{
    if(t != NULL){
        /***对结点做相关操作******/
        fprintf(stdout,"%d ",t->val);
        /*********************/ 
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

//递归中根（中序）遍历二叉树,LDR
void inOrder(bTree t)
{
    if(t != NULL){
        inOrder(t->lchild);
        /***对结点做相关操作******/
        fprintf(stdout,"%d ",t->val);
        /*********************/ 
        inOrder(t->rchild); 
    }
}

//递归后根（后序）遍历二叉树,LRD
void postOrder(bTree t)
{
    if(t != NULL){
        postOrder(t->lchild);
        postOrder(t->rchild); 
        /***对结点做相关操作******/
        fprintf(stdout,"%d ",t->val);
        /*********************/ 
    }
}

//使用迭代的方式前序遍历
//相当于自己维护一个栈区
void stack_preOrder(bTree t)
{
    bTree *stack = malloc(sizeof(bTree)*100);
    int top = 0;

    while(t != NULL || top > 0){
        while(t->lchild != NULL){
            
        }

    }
    if(t != NULL){
        /***对结点做相关操作******/
        
        /*********************/ 
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}


int main()
{
    bTree t = NULL;
    createTree(&t);

    preOrder(t);
    printf("\n");
    inOrder(t);
    printf("\n");
    postOrder(t);
    printf("\ntest ok\n");
    exit(0);
}
