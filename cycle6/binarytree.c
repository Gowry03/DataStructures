#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* rchild;
    struct node* lchild;
};

struct node* root = NULL;

void insert(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    if (root == NULL) {
        root = newnode;
        return;
    }
    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* temp = queue[front++];

        if (temp->lchild == NULL) {
            temp->lchild = newnode;
            return;
        } else {
            queue[rear++] = temp->lchild;
        }
        if (temp->rchild == NULL) {
            temp->rchild = newnode;
            return;
        } else {
            queue[rear++] = temp->rchild;
        }
    }
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

struct node* findInorderSuccessor(struct node* node) {
    struct node* current = node->rchild;
    while (current && current->lchild != NULL) {
        current = current->lchild;
    }
    return current;
}

int searchNode(struct node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    return searchNode(root->lchild, key) || searchNode(root->rchild, key);
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return NULL;

    if (root->data == key) {
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        }
        if (root->lchild == NULL) {
            struct node* temp = root->rchild;
            free(root);
            return temp;
        } else if (root->rchild == NULL) {
            struct node* temp = root->lchild;
            free(root);
            return temp;
        }
        struct node* successor = findInorderSuccessor(root);
        root->data = successor->data;
        root->rchild = deleteNode(root->rchild, successor->data);
    } else {
        root->lchild = deleteNode(root->lchild, key);
        root->rchild = deleteNode(root->rchild, key);
    }

    return root;
}

int main() {
    int data, key;
    printf("\nMENU\n1.INSERT\n2.DELETE\n3.INORDER\n4.PREORDER\n5.POSTORDER\n6.EXIT\n");
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
                if (searchNode(root, key)) {
                    root = deleteNode(root, key);
                    printf("Node with key %d deleted successfully.\n", key);
                } else {
                    printf("Deletion failed. Key %d not found in the tree.\n", key);
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
                exit(0);
            default:
                printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
