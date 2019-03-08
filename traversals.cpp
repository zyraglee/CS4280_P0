#include "traversals.h"
#include <fstream>

void printInorder(node *root, ofstream& fp) {

	if(root == NULL) {
        	return;
    	} else {
        	printInorder(root->left,fp);
        	printInorder(root->middle,fp);
        	for (int i = 0; i < root->level; i++){
			fp << " ";
        	}
		fp << root ->letter << ":\t";

        	for (int i = 0; i < (int) root->words.size(); i++) {
			fp << root->words[i] << " ";
        	}
		fp << "\n";

        	printInorder(root->right, fp);
    	}
}

void printPreorder(node *root, ofstream& fp) {
   
    	if (root == NULL) {
        	return;
    	} else {
        	for (int i = 0; i < root->level; i++) {
            	fp << " ";
        	}

        	fp << root->letter << ":\t";

        	for (int i = 0; i < (int) root->words.size(); i++) {
            		fp << root->words[i] << " ";
        	}

        	fp << "\n";

       		printInorder(root->left,fp);
        	printInorder(root->middle,fp);
        	printInorder(root->right,fp);
    	}
}

void printPostorder(node *root,  ofstream& fp) {

    	if (root == NULL) {
        	return;
    	} else {
        	printInorder(root->left, fp);
        	printInorder(root->middle, fp);
        	printInorder(root->right, fp);
        	for (int i = 0; i < root->level; i++) {
			fp << " ";
            	//	cout << " ";
        	}
		fp << root->letter << ":\t";
        	
        	for (int i = 0; i < (int) root->words.size(); i++) {
			fp << root->words[i]<< " ";
        	}
		fp<<endl;
        
    	}

}
