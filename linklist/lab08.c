/*#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;
#endif

typedef struct q_node {
    tree_t *data;
    struct q_node *next;
} q_node_t;

typedef struct queue { 
    int size;
    struct q_node *front;
    struct q_node *rear;
} queue_t;

q_node_t *create_q_node(tree_t *t) {
    q_node_t *new_node = (q_node_t *)malloc(sizeof(q_node_t));
    new_node->data = t;
    new_node->next = NULL;
    return new_node;
}

queue_t *create_queue() {
    queue_t *new_queue = (queue_t *)malloc(sizeof(queue_t));
    new_queue->size = 0;
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

void enqueue(queue_t **q, tree_t *t) {
    q_node_t *new_node = create_q_node(t);
    if ((*q)->front == NULL && (*q)->rear == NULL) {
        (*q)->front = new_node;
        (*q)->rear = new_node;
    } else {
        (*q)->rear->next = new_node;
        (*q)->rear = new_node;
    }
    (*q)->size++;
}

void dequeue(queue_t **q) {
    q_node_t *temp_node = NULL;
    if ((*q)->front != NULL && (*q)->rear != NULL) {
        if ((*q)->front == (*q)->rear) {
            free((*q)->front);
            (*q)->front = NULL;
            (*q)->rear = NULL;
        } else {
            temp_node = (*q)->front;
            (*q)->front = (*q)->front->next;
            free(temp_node);
        }
        (*q)->size--;
    }
}

int queue_empty(queue_t *q) {
    if (q->front == NULL)
        return 1;
    return 0;
}

int is_root(tree_t *t) {
    if (t->nb == 1)
        return 1;
    return 0;
}

int is_full(tree_t *t) {
    if (t == NULL)
        return 0;

    int tmp_left = 0, tmp_right = 0;

    if (t->left != NULL || t->right != NULL) {
        if (t->left != NULL)
            tmp_left = is_full(t->left);
        if (t->right != NULL)
            tmp_right = is_full(t->right);
        return tmp_left && tmp_right;
    }
    return 1;
}

int is_perfect(tree_t *t) {
    if (t == NULL)
        return 0;

    queue_t *q = create_queue();
    tree_t *temp_t_node = NULL;

    int result = 1;
    int total_level_node = 1, count_node, temp_size;
    enqueue(&q, t);
    while (!queue_empty(q)) {
        count_node = 0;
        temp_size = q->size;
        for (int i = 0; i < temp_size; i++) {
            temp_t_node = q->front->data;
            dequeue(&q);

            if (temp_t_node->left != NULL)
                enqueue(&q, temp_t_node->left);
            if (temp_t_node->right != NULL)
                enqueue(&q, temp_t_node->right);
            count_node++;
        }
        if (count_node != total_level_node) {
            result = 0;
            break;
        }
        total_level_node = total_level_node * 2;
    }
    while (!queue_empty(q))
        dequeue(&q);
    return result;
}

int is_complete(tree_t *t) {
    if (t == NULL)
        return 0;

    queue_t *q = create_queue();
    tree_t *temp_t_node = NULL;

    int result = 1, state = 0;  
    enqueue(&q, t);
    while (!queue_empty(q)) {
        temp_t_node = q->front->data;
        dequeue(&q);

        if (!state) {
            if (temp_t_node != NULL) {
                enqueue(&q, temp_t_node->left);
                enqueue(&q, temp_t_node->right);
            } else 
                state = 1;
        } else {
            if (temp_t_node != NULL) 
                result = 0;   
        }
    }
    return result;
}


int is_degenerate(tree_t *t) {
    if (t == NULL)
        return 0;

    if (t->left != NULL && t->right != NULL)
        return 0;
    
    if (t->left != NULL)
        return is_degenerate(t->left);
    if (t->right != NULL)
        return is_degenerate(t->right);

    return 1;
}

int go_left(tree_t *t) {
    if (t == NULL)
        return 1;

    if (t->right != NULL)
        return 0;
    
    int left = go_left(t->left);
    return left;
}

int go_right(tree_t *t) {
    if (t == NULL)
        return 1;

    if (t->left != NULL)
        return 0;
    
    int right = go_right(t->right);
    return right;
}


int is_skewed(tree_t *t) {
    if (t == NULL)
        return 0;

    int left, right;
    left = go_left(t);
    right = go_right(t);
    if ((left == 0 && right == 1) || (left == 1 && right == 0))
        return 1;
    return 0;
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }
    printf("%d %d %d %d %d\n", is_full(t),
    is_perfect(t), is_complete(t),
    is_degenerate(t), is_skewed(t));
    return 0;
}
*/




#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#define TRUE	1
#define FALSE	0

#ifndef __bin_tree__

typedef struct	node
{
	int		data;
	struct node	*left;
	struct node	*right;
}node_t;

typedef node_t tree_t;

#endif

int	size(tree_t *t)
{
	if (!t)
		return (FALSE);
	return (size(t -> left) + size(t -> right) + 1);
}
int	height(tree_t *t)
{
	int	hl;
	int	hr;

	if (!t)
		return (-1);
	hl = height(t -> left);
	hr = height(t -> right);
	return ((hl > hr) ? (hl + 1) : (hr + 1));
}

int	check_perfect(tree_t *t, int height, int level)
{
	if (!t)
		return (TRUE);
	if ((!t -> left && t -> right) || (t -> left && !t -> right))
		return (FALSE);
	if (!t -> left && !t -> right)
		return (level == height);
	return (check_perfect(t -> left, height, level + 1) && check_perfect(t -> right, height, level + 1));
}

int	check_complete(tree_t *t, int size, int index)
{
	if (!t)
		return (TRUE);
	if (size <= index)
		return (FALSE);
	return (check_complete(t -> left, size, 2 * index + 1) && check_complete(t -> right, size, 2 * index + 2));
}

int	is_oneNode(tree_t *t)
{
	if (!t)
		return (TRUE);
	if (t -> left && t -> right)
		return (FALSE);
	return ((t -> left) ? (is_oneNode(t -> left)) : is_oneNode(t -> right));
}

int	is_left(tree_t *t)
{
	if (!t)
		return (TRUE);
	if (t -> right)
		return (FALSE);
	return (is_left(t -> left));
}

int	is_right(tree_t *t)
{
	if (!t)
		return (TRUE);
	if (t -> left)
		return (FALSE);
	return (is_right(t -> right));
}

int	is_full(tree_t *t)
{
	int	left;
	int	right;

	if (!t)
		return (FALSE);
	if (!t -> left && !t -> right)
		return (TRUE);
	left = is_full(t -> left);
	right = is_full(t -> right);
	return (left && right);
}

int	is_perfect(tree_t *t)
{
	int	h;

	h = height(t);
	return (check_perfect(t, h, 0));
}

int	is_complete(tree_t *t)
{
	int	s;

	s = size(t);
	return (check_complete(t, s, 0));
}

int	is_degenerate(tree_t *t)
{
	if (!t)
		return (FALSE);
	return (is_oneNode(t));
}

int	is_skewed(tree_t *t)
{
	return ((t -> left) ? (is_left(t)) : (is_right(t)));
}

int	main(void)
{
	tree_t	*t = NULL;
	int	n, i;
	int	parent, child;
	int	branch; // 0 root, 1 left, 2 right

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &parent, &child, &branch);
		t = attach(t, parent, child, branch);
	}
	printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));
	return (0);
}*/



/*#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;
#endif

void print_preorder(tree_t *t) {
    if (t != NULL) {
        printf("%d ", t->data);
        print_preorder(t->left);
        print_preorder(t->right);
    }
}

void print_postorder(tree_t *t) {
    if (t != NULL) {
        print_postorder(t->left);
        print_postorder(t->right);
        printf("%d ", t->data);
    }
}

void print_inorder(tree_t *t) {
    if (t != NULL) {
        print_inorder(t->left);
        printf("%d ", t->data);
        print_inorder(t->right);
    }
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }
    print_preorder(t);
    print_postorder(t);
    print_inorder(t);
    return 0;
}*/