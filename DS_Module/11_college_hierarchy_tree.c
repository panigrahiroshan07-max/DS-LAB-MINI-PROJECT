#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    char name[50];

    struct TreeNode *child;
    struct TreeNode *sibling;
};

// Create Node
struct TreeNode* createNode(char name[])
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    strcpy(newNode->name, name);

    newNode->child = NULL;
    newNode->sibling = NULL;

    return newNode;
}

// Display Tree
void displayTree(struct TreeNode *root, int level)
{
    if(root == NULL)
        return;

    for(int i = 0; i < level; i++)
    {
        printf("   ");
    }

    printf("|-- %s\n", root->name);

    displayTree(root->child, level + 1);

    displayTree(root->sibling, level);
}

int main()
{
    // College
    struct TreeNode *college =
        createNode("AIKTC");

    // Department
    struct TreeNode *department =
        createNode("Computer Engineering");

    college->child = department;

    // Classes
    struct TreeNode *classA =
        createNode("SECO-A");

    struct TreeNode *classB =
        createNode("SECO-B");

    department->child = classA;

    classA->sibling = classB;

    // Subjects of Class A
    struct TreeNode *ds =
        createNode("Data Structures");

    struct TreeNode *dbms =
        createNode("DBMS");

    classA->child = ds;

    ds->sibling = dbms;

    // Subjects of Class B
    struct TreeNode *java =
        createNode("Java");

    struct TreeNode *python =
        createNode("Python");

    classB->child = java;

    java->sibling = python;

    printf("\n");
    printf("====================================\n");
    printf(" COLLEGE HIERARCHY TREE\n");
    printf("====================================\n\n");

    displayTree(college, 0);

    return 0;
}