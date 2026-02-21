#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* rchild;
    struct node* lchild;
};

struct node* root = NULL;

struct node* succ(struct node* ptr) {
    struct node* ptr1 = ptr->rchild;
    while (ptr1 && ptr1->lchild != NULL) {
        ptr1 = ptr1->lchild;
    }
    return ptr1;
}

void insert(int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if (root == NULL) {
        root = temp;
        return;
    }

    struct node* ptr = root;
    struct node* ptr1;
    while (ptr != NULL) {
        ptr1 = ptr;
        if (data < ptr->data) {
            ptr = ptr->lchild;
        } else if (data > ptr->data) {
            ptr = ptr->rchild;
        } else {
            free(temp); 
            return;
        }
    }
    if (ptr1->data > data) {
        ptr1->lchild = temp;
    } else {
        ptr1->rchild = temp;
    }
}

int delete(int data) {
    struct node* ptr = root;
    struct node* ptr1 = NULL;
    int flag = 0;

    while (ptr != NULL && flag == 0) {
        if (data < ptr->data) {
            ptr1 = ptr;
            ptr = ptr->lchild;
        } else if (data > ptr->data) {
            ptr1 = ptr;
            ptr = ptr->rchild;
        } else {
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("Key not found!\n");
        return -1;
    }

    if (ptr->lchild == NULL && ptr->rchild == NULL) {
        if (ptr1 == NULL) {
            root = NULL;
        } else if (ptr1->lchild == ptr) {
            ptr1->lchild = NULL;
        } else {
            ptr1->rchild = NULL;
        }
        free(ptr);
    } else if (ptr->lchild != NULL && ptr->rchild != NULL) {
        struct node* ptr3 = succ(ptr);
        int item1 = ptr3->data;
        delete(item1);
        ptr->data = item1;
    } else {
        struct node* child = (ptr->lchild != NULL) ? ptr->lchild : ptr->rchild;
        if (ptr1 == NULL) {
            root = child;
        } else if (ptr1->lchild == ptr) {
            ptr1->lchild = child;
        } else {
            ptr1->rchild = child;
        }
        free(ptr);
    }

    return data;
}

void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

int countLeafNodes(struct node* root) {
    if (root == NULL) return 0;
    if (root->lchild == NULL && root->rchild == NULL) return 1;
    return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
}

void sort() {
    inorder(root);
}

int main() {
    int data, d, key, k;
    printf("\nMENU\n1.INSERT\n2.DELETE\n3.INORDER\n4.PREORDER\n5.POSTORDER\n6.COUNT LEAF NODES\n7.SORT\n8.EXIT\n");
    while (1) {
        int ch;
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                d = delete(key);
                if (d != -1) {
                    printf("Node with data %d is deleted\n", d);
                }
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                k = countLeafNodes(root);
                printf("Number of leaf nodes: %d\n", k);
                break;
            case 7:
                sort();
                printf("\n");
                break;
            case 8:
                exit(0);
            default:
                printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
