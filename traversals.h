#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <iostream>
#include "node.h"

void printInorder(node *root, ofstream& fp);

void printPreorder(node *root,  ofstream& fp);

void printPostorder(node *root,  ofstream& fp);

#endif
