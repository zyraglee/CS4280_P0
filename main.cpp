//Zyra De Los Reyes
//CS4280_P0

#include <iostream>
#include <fstream>
#include "buildtree.h"
#include "traversals.h"
#include "helpers.h"

using namespace std;

int main(int argc, char *argv[]) {
    string fileInput, in,post,pre;
    //fileInput = argv[1];
    string fileExtension (".input1");
  
    //If a filename was given
    if (argc == 2) {
        fileInput = argv[1];

	//remove file extension in order to use command ./P0 xxx.input1 || xxx
	if(fileInput.find(fileExtension) != string::npos){
		fileInput.erase(fileInput.find_last_of('.')); 
        }
	in = fileInput + ".inorder";	
	post = fileInput + ".postorder";
	pre = fileInput + ".preorder";
        fileInput.append(".input1");
	
    } else if (argc == 1) { //read from keyboard and put in temp file "keyboard.input"
        string input;
        ofstream commandInput;

        fileInput = "keyboard.input1";
        commandInput.open(fileInput.c_str());

        while (cin >> input) { //read input from keyboard
	    caseToLower(input);
            //Add word to file
            commandInput << input << " ";
        }
	cout << "Input accepted.\nSaving this to a file named keyboard.input1 \n";
	commandInput.close();

	fileInput.erase(fileInput.find_last_of('.'));
	in = fileInput + ".inorder";
        post = fileInput + ".postorder";
        pre = fileInput + ".preorder";
	fileInput.append(".input1");

     } else {
        cerr << "You entered an invalid string, letters only!\nUsage:  " << "./P0" << "\n\t" << "./P0" <<" <file>\n\t" << "./P0"<<" <type string from the keyboard>\n";
        return 1;
    }

    //Take file input and send to root
    node *root = buildTree(fileInput);

    //if something went wrong terminate program, already have proper exit message.
    if(root == NULL) {
        return 1;
    }
	//write to file
    ofstream inorder,postOrder, preOrder;
    inorder.open(in.c_str());
    	inorder << "In Order Traversal\n";
     	printInorder(root, inorder);
    inorder.close();
		
    preOrder.open(pre.c_str());
        preOrder << "In Pre-order Traversal\n";
        printPreorder(root, preOrder);
     preOrder.close();
    
    postOrder.open(post.c_str());
       postOrder << "In Post-order Traversal\n";
       printPostorder(root, postOrder);
    postOrder.close();
	
    cout <<"Successful: " << in << ", " << pre << ", " << post << " created for " << fileInput << "\n";
    return 0;
}

