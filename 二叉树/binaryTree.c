#include <stdio.h>
#include <stdlib.h>

typedef int tree_t;

//使用二叉链表实现二叉树节点
typedef struct treeNode{
    tree_t val;
    struct treeNode *lchild;
    struct treeNode *rchild;
}*bTree;

void createTree(bTree *T)  //传入一个btree的指针的地址
{
    tree_t data;
    scanf("%d", &data);

    if(data == -1) {    //-1代表终端节点值
        *T = NULL;
    } else {
        *T = (bTree)malloc(sizeof(struct treeNode));  
        (*T)->val = data;
        printf("请输入%d的左孩子节点：", data);
        createTree(&((*T)->lchild));
        printf("请输入%d的右孩子节点：", data);
        createTree(&((*T)->rchild));
    }
}

//递归先根遍历二叉树
void preOrder(bTree T)
{
    if(T != NULL){
        /***对结点做相关操作******/
        fprintf(stdout,"%d ",T->val);
        /*********************/ 
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}


int main()
{
    bTree t = NULL;
    createTree(&t);

    preOrder(t);
    printf("\ntest ok\n");
    exit(0);
}
