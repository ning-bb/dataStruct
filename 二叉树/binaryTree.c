#include <stdio.h>
#include <stdlib.h>

#define STK_SIZE    100

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

//迭代法中序遍历二叉树
void stackInorder(bTree t)
{
    bTree *stk = malloc(sizeof(bTree)*STK_SIZE);
    int top = 0;

    while(t != NULL || top >0){
        while(t != NULL){
            stk[top++] = t;
            t = t->lchild;
        }

        printf("%d ",stk[--top]->val);
        t = stk[top]->rchild;
    }

    free(stk);
}

//迭代法前序遍历二叉树
void stackPreorder(bTree t)
{
    bTree *stk = malloc(sizeof(bTree)*STK_SIZE);
    int top = 0;

    while(t != NULL || top >0){
        while(t != NULL){
            stk[top++] = t;
            printf("%d ",t->val);
            t = t->lchild;
        }

        t = stk[--top]->rchild;
    }

    free(stk);
}

//迭代法后序遍历二叉树
void stackpostOrder(bTree t)
{
    bTree *stk = malloc(sizeof(bTree)*STK_SIZE);
    int top = 0;

    while(t != NULL || top >0){
        while(t != NULL){
            stk[top++] = t;
            t = t->lchild;
        }
        t = stk[top-1]->rchild;     
        //TODO:没有写完
        //printf("%d ",t->val);
    }

    free(stk);
}

int main()
{
    bTree t = NULL;
    createTree(&t);

    printf("\n");
    preOrder(t);

    printf("\n");
    stackPreorder(t);

    printf("\ntest ok\n");
    exit(0);
}
