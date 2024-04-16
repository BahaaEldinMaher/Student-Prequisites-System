/*The used libraries */
#include <iostream>


using namespace std;

/* Declare BST node*/
struct node
{
	string info;
	struct node* left;
	struct node* right;
};

/* To Make A new leaf*/
 node* newNode(string idata)
{
	struct node* node = new struct node;
	node->info = idata;
	node->left = NULL;
	node->right = NULL;
	return node;
}
 /* The search function*/
 bool searching(node* root, string idata) {
	 if (root == NULL)
		 return false;
	 else if (root->info == idata) return true;
	 else if (idata == root->left->info)
		 return searching(root->left, idata);
	 
     else if (idata == root->left->left->info)
		 return searching(root->left, idata);
	
	
	 
	 else if (idata == root->right->left->info)
		 return searching(root->right->left, idata);

	 else if (idata == root->right->info)
		 return searching(root->right, idata);
	 
	 else 
		 return false;
	 
 }



 int main()
 {


	 string CourseName;

	 int choice;
	 /*The Prerequisites Courses*/
	 struct node* root = newNode("101Introduction_to_Programming");
	 root->left = newNode("207Fundamental_of_Data_Structures_&_Algorithms");
	 root->right = newNode("311Computer_Architecture");
	 root->right->left = newNode("217Advanced_Computer_Programming_&_Concepts");
	 root->left->left = newNode("313Software_Engineering");
	 

	
	 while (1)
	 {                  /*The Menu*/
		 cout << "====|||||Your Courses Registration Menu|||||====" << endl;
		 cout << "1. Enter 1 to go to courses: " << endl;


		 cout << "\n2.Quit" << endl;

		 cin>> choice;

		 switch (choice)

		 {
		 case 1:
			 cout << "\n The Prerequisites Courses:\n101Introduction_to_Programming\n207Fundamental_of_Data_Structures_&_Algorithms\n311Computer_Architecture\n217Advanced_Computer_Programming_&_Concepts\n313Software_Engineering  " << endl;
			 cout << "\nPlease Enter The Last CS prerequisite course that you have taken: " << endl;
			 cin>>CourseName;
			 /*if statments to see the matched prerequisites courses and show the courses that he/she can register next */
			 if (searching(root, CourseName) == true) {
				 if (CourseName == "101Introduction_to_Programming")
					 cout << "\nThe Courses that you can take:\n ---------------------------------------------------\n|                                                  |\n| 207Fundamental of Data Structures & Algorithms   |\n| 311Computer Architecture                         |\n|                                                  |\n --------------------------------------------------- " << endl;
				 if (CourseName == "207Fundamental_of_Data_Structures_&_Algorithms")
					 cout << "\nThe Course that you can take:\n ---------------------------------------------------\n| 217Advanced Computer Programming & Concepts      |\n|                                                  |\n --------------------------------------------------- "<< endl;
				 if (CourseName == "311Computer_Architecture")
					 cout << "\nThe Courses that you can take:\n ---------------------------------------------------\n| 313Software Engineering                          |\n| 415Compiler Design                               |\n ---------------------------------------------------" << endl;
				 if (CourseName == "217Advanced_Computer_Programming_&_Concepts")
					 cout << "\nThe Courses that you can take:\n ---------------------------------------------------\n| 304Analysis and Design of Algorithms              |\n| 419Theory of Computing                            |\n ---------------------------------------------------" << endl;
				 if (CourseName == "313Software_Engineering")
					 cout << "\nThe Courses that you can take:\n ---------------------------------------------------\n| 315Operating Systems                              |\n| 404Database Systems                               |\n ---------------------------------------------------" << endl;
			 }
			 else if (searching(root, CourseName) == false) {
				 cout << "Please Write the correct Course name: " << endl;
			 }
		 case 2:
			 exit(1);
		 default:
			 cout << "Wrong choice" << endl;

			 
		 } break;
	 }
	 return 0;
 }