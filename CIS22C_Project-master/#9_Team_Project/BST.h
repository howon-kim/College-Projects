/*************************************************************************************************************
 * Class: CIS 22C
 * Name:Jiarong Feng, Sunjun Anh
 * Program name: De Anza courses
 * File name: BST.h
 *************************************************************************************************************
 * Description of program purpose and function:
 * This program is using binary search trees as
 * an algorithms to stroe the De Anza courses'data to
 * a binary search trees. We are making CRN as our
 * unique key so that we can search and return the data
 * from that CRN.
 *************************************************************************************************************
 * Variables used are: CRN, course, status, professor
 *************************************************************************************************************
 * Program inputs are: 42519
 * Program outputs are:
 * 42519	CIS D022C 02Y	DATA ABSTRACT & STRUCTURES	Full	TTh	01:30PM-03:20PM	AT312	DA	4.5	Parrish	0	0	15
 * 42519	CIS D022C 02Y	DATA ABSTRACT & STRUCTURES	Full	TBA	TBA	ONLINE	DA	4.5	Parrish	0	0	15
 ************************************************************************************************************/


#ifndef BST_h
#define BST_h
#include <cstddef>
#include <string>
#include <iostream>
#include "Class.h"
#include <cstdlib>
using namespace std;


template <class bstdata>
class BST
{
private:
    struct Node
    {
        bstdata data;
        Node* left;
        Node* right;
        
        Node(): left(NULL), right(NULL){}
        Node(bstdata newdata): left(NULL), right(NULL), data(newdata){}
    };
    
    typedef struct Node* Nodeptr;
    
    Nodeptr root;
    int size;
    
    /**Private helper functions*/
    
    void copyTree(Nodeptr &copyToRoot, Nodeptr root);
    
    // Unique Function for Project //
    void _addCRN(Nodeptr root, bstdata value);
    void _addCourse(Nodeptr root, bstdata value);
    
    bool containsValue(Nodeptr root, bstdata value);
    
    
    void _inOrderPrint(Nodeptr root) const;
    void _preOrderPrint(Nodeptr root) const;
    void _postOrderPrint(Nodeptr root) const;
    
    
    void deleteTree(Nodeptr root);
    void _getSize(Nodeptr root);
    
    int _getHeight(Nodeptr root);
    bool _isBST(Nodeptr root);
    
    bstdata findMin(Nodeptr root);
    bstdata findMax(Nodeptr root);
    
    
    Nodeptr _removeCRN(Nodeptr root, bstdata value);
    Nodeptr _removeCourse(Nodeptr root, bstdata value);
    
    
    bool _findCRN(Nodeptr root, bstdata value);
    bool _findCourse(Nodeptr root, bstdata value);
    
    void _countStatus(Nodeptr root, int &open, int &waitlist, int &full);
    void _countInstructor(Nodeptr root, int &count, bstdata professor);
    void _countCourse(Nodeptr root, int &count, bstdata course);
    
    
public:
    BST();
    ~BST();
    BST(const BST<bstdata> &tree);
    
    bool isEmpty();
    int getSize();
    
    // Unique Function for Project //
    void addCRN(bstdata value);
    void addCourse(bstdata value);
    
    bstdata getRoot();
    
    
    bool contains(bstdata value);
    
    void inOrderPrint() const;
    void preOrderPrint() const;
    void postOrderPrint() const;
    
    bstdata minimum();
    bstdata maximum();
    
    int getHeight();
    
    bool search(bstdata value);
    bool isBST();
    
    
    void removeCRN(bstdata value);
    void removeCourse(bstdata value);
    
    bool findCRN(bstdata value);
    bool findCourse(bstdata value);
    
    void countStatus();
    void countInstructor(bstdata professor);
    void countCourse(bstdata course);
    
    
};

/*************************************************************************************************************
 * Function name: countCourse                                                                                *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to count how many times the course has been added                                        *
 *************************************************************************************************************
 * Program inputs are: D022C                                                                                 *
 * Program outputs are:                                                                                      *
 * "D022C is found"                                                                                          *
 ************************************************************************************************************/

template <class bstdata>
void BST<bstdata>::_countCourse(Nodeptr root, int &count, bstdata course)
{
    
    if(root)
    {
        _countCourse(root->left, count, course);
        _countCourse(root->right, count, course);
        if(root->data.getCourse() == course.getCourse())
        {
            root->data.print();
            count++;
        }
    }
    
    
    
}

template <class bstdata>
void BST<bstdata>::countCourse(bstdata course)
{
    int count = 0;
    cout << "**** Course Statstics ****" << endl;
    
    _countCourse(root, count, course);
    
    if(count == 0)
        cout << course.getCourse() << " is not exist" << endl;
    else
    {
        course.displayCategory();
        cout  << course.getCourse() << " : "<< count << " is founded" << endl;
    }
}





/*************************************************************************************************************
 * Function name: countInstructor                                                                            *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to count how many times the professor has been added                                     *
 *************************************************************************************************************
 * Program inputs are: Parrish                                                                               *
 * Program outputs are:                                                                                      *
 * "Parrish teach 4 classes"                                                                                 *
 ************************************************************************************************************/


template <class bstdata>
void BST<bstdata>::_countInstructor(Nodeptr root, int &count, bstdata professor)
{
    
    if(root)
    {
        _countInstructor(root->left, count, professor);
        _countInstructor(root->right, count, professor);
        if(root->data.getInstructor() == professor.getInstructor())
        {
            root->data.print();
            count++;
        }
    }
    
    
    
}

template <class bstdata>
void BST<bstdata>::countInstructor(bstdata professor)
{
    int count = 0;
    
    cout << "**** Professor Statstics ****" << endl;
    
    _countInstructor(root, count, professor);
    
    if(count == 0)
        cout << professor.getInstructor() << " does not teach any classes" << endl;
    else
    {
        professor.displayCategory();
        cout << professor.getInstructor() << " teach " << count << " classes" << endl;
    }
}



/*************************************************************************************************************
 * Function name: countStatus                                                                                *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to count how many times the status has been added                                        *
 *************************************************************************************************************
 * Program inputs are: Open                                                                                  *
 * Program outputs are:                                                                                      *
 * " " - Open : 5"                                                                                           *
 ************************************************************************************************************/


template <class bstdata>
void BST<bstdata>::_countStatus(Nodeptr root, int &open, int &waitlist, int &full)
{
    
    if(root)
    {
        _countStatus(root->left, full, waitlist, open);
        _countStatus(root->right, full, waitlist, open);
        if(root->data.getStatus() == "Open")
            open++;
        if(root->data.getStatus() == "Waitlist")
            waitlist++;
        if(root->data.getStatus() == "Full")
            full++;
    }
    
    
    
}

template <class bstdata>
void BST<bstdata>::countStatus()
{
    int open = 0;
    int full = 0;
    int waitlist = 0;
    
    _countStatus(root, full, waitlist, open);
    
    cout << "**** Status Statstics ****" << endl;
    cout << " - Open : " << open << endl;
    cout << " - Waitlist : " << waitlist << endl;
    cout << " - Full : " << full << endl;
    cout << endl;
}



/*************************************************************************************************************
 * Function name: findCourse                                                                                 *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to find the course that store in the tree and return the data                            *
 *************************************************************************************************************
 * Program inputs are: D022C                                                                                 *
 * Program outputs are:                                                                                      *
 * 44159	CIS D022C 01Y	DATA ABSTRACT & STRUCTURES	Waitlist	TBA	TBA	ONLINE	DA	4.5	Goel	0	10	15         *
 ************************************************************************************************************/

template <class bstdata>
bool BST<bstdata>::_findCourse(Nodeptr root, bstdata value)
{
    
    if (value.getCourse() == root->data.getCourse())
    {
        value.displayCategory();
        root->data.print();
        
        if(root -> left == NULL)
            return true;
        
        
        return _findCourse(root->left, value);
    }
    
    else if (value.getCourse() < root->data.getCourse())
    {
        if (root -> left == NULL)
        {
            cout << "findCourse : Course is not stored in the BST" << endl;
            return false;
        }
        
        else
            return _findCourse(root->left, value);
    }
    
    else if (value.getCourse() > root->data.getCourse())
    {
        if (root -> right == NULL)
        {
            cout << "findCourse : Course is not stored in the BST" << endl;
            return false;
        }
        
        else
            return _findCourse(root->right, value);
    }
    
    cout << "findCourse : Course is not stored in the BST" << endl;
    return false;
}


template <class bstdata>
bool BST<bstdata>::findCourse(bstdata value)
{
    if (root == NULL)
    {
        cout << "findCourse : Root is empty" << endl;
        return false;
    }
    else
        return _findCourse(root, value);
}



/*************************************************************************************************************
 * Function name: findCRN                                                                                    *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to find the CRN that store in the tree and return the data                               *
 *************************************************************************************************************
 * Program inputs are: 44159                                                                                 *
 * Program outputs are:                                                                                      *
 * 44159	CIS D022C 01Y	DATA ABSTRACT & STRUCTURES	Waitlist	TBA	TBA	ONLINE	DA	4.5	Goel	0	10	15         *
 ************************************************************************************************************/

template <class bstdata>
bool BST<bstdata>::_findCRN(Nodeptr root, bstdata value)
{
    
    if (value.getCRN() == root->data.getCRN())
    {
        value.displayCategory();
        root->data.print();
        return true;
    }
    
    else if (value.getCRN() < root->data.getCRN())
    {
        if (root -> left == NULL)
        {
            cout << "findCRN : CRN is not stored in the BST" << endl;
            return false;
        }
        
        else
            return _findCRN(root->left, value);
    }
    
    else if (value.getCRN() > root->data.getCRN())
    {
        if (root -> right == NULL)
        {
            cout << "findCRN : CRN is not stored in the BST" << endl;
            return false;
        }
        
        else
            return _findCRN(root->right, value);
    }
    
    cout << "findCRN : CRN is not stored in the BST" << endl;
    return false;
}


template <class bstdata>
bool BST<bstdata>::findCRN(bstdata value)
{
    if (root == NULL)
    {
        cout << "findCRN : Root is empty" << endl;
        return false;
    }
    else
    {
        return _findCRN(root, value);
    }
}


/*************************************************************************************************************
 * Function name: constructor                                                                                *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to construct the data                                                                    *
 ************************************************************************************************************/
template <class bstdata>
BST<bstdata>::BST():root(NULL),size(0){}


/*************************************************************************************************************
 * Function name: Copy constructor                                                                           *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to make a copy of the data                                                               *
 ************************************************************************************************************/
template <class bstdata>
BST<bstdata>::BST(const BST<bstdata> &tree)
{
    if(tree.root == NULL)
        root = NULL;
    else
        copyTree(root, tree.root);
}

template <class bstdata>
void BST<bstdata>::copyTree(Nodeptr &copyToRoot, Nodeptr root)
{
    if(root == NULL)
        copyToRoot = NULL;
    else
    {
        copyToRoot = new Node;
        copyToRoot -> data = root -> data;
        copyTree(copyToRoot -> left, root -> left);
        copyTree(copyToRoot -> right, root -> right);
    }
}

/*************************************************************************************************************
 * Function name: destructor                                                                                 *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * This function is to delete the data from the tree                                                         *
 ************************************************************************************************************/

/* Private Helper Function */
// Traverse the binary tree in postorder and deletes every node
template<class bstdata>
void BST<bstdata>::deleteTree(Nodeptr root)
{
    if(root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

/* Public Wrapper Function */
template <class bstdata>
BST<bstdata>::~BST()
{
    deleteTree(root);
    
}

/*************************************************************************************************************
 * Function name: isEmpty                                                                                    *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Check the tree is empty or not                                                                            *
 ************************************************************************************************************/
template <class bstdata>
bool BST<bstdata>::isEmpty()
{
    /*
     if(size == 0)
     return true;
     else
     return false;
     */
    
    if(getSize() == 0)
        return true;
    else
        return false;
}


/*************************************************************************************************************
 * Function name: getSize                                                                                    *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Return the size of the tree                                                                               *
 ************************************************************************************************************/
/* Private Helper Function */
// Traverse the binary tree in postorder and deletes every node
template<class bstdata>
void BST<bstdata>::_getSize(Nodeptr root)
{
    
    if(root)
    {
        _getSize(root->left);
        _getSize(root->right);
        size++;
        
    }
    
}


/* Public Wrapper Function */
template <class bstdata>
int BST<bstdata>::getSize()
{
    size = 0;
    _getSize(root);
    
    return size;
}


/*************************************************************************************************************
 * Function name: addCRN                                                                                     *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Add the CRN to the tree                                                                                   *
 ************************************************************************************************************/
/* Private Helper Function */
template <class bstdata>
void BST<bstdata>::_addCRN(Nodeptr root, bstdata value)
{
    if (value.getCRN() == root->data.getCRN())
        return;
    
    else if (value.getCRN() < root->data.getCRN())
    {
        if (root -> left == NULL)
        {
            root -> left = new Node(value);
            //size++;
        }
        else
            _addCRN(root->left, value);
    }
    
    else
    {
        if (root -> right == NULL)
        {
            root -> right = new Node(value);
            //size++;
        }
        else
            _addCRN(root->right, value);
    }
    
    
}


/* Public Wrapper Function */

template <class bstdata>
void BST<bstdata>::addCRN(bstdata value)
{
    if (root == NULL)
        
    {
        root = new Node(value); //if the tree is empty insert the value at the root
        //size++;
        getSize();
        
    }
    else
    {
        _addCRN(root, value); //otherwise call the helper function, passing it the root
        getSize();
    }
    
}


/*************************************************************************************************************
 * Function name: addCourse                                                                                  *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Add the course to the tree                                                                                *
 ************************************************************************************************************/
/* Private Helper Function */
template <class bstdata>
void BST<bstdata>::_addCourse(Nodeptr root, bstdata value)
{
    
    if (value.getCourse() <= root->data.getCourse())
    {
        if (root -> left == NULL)
        {
            root -> left = new Node(value);
            //size++;
        }
        else
            _addCourse(root->left, value);
    }
    
    else
    {
        if (root -> right == NULL)
        {
            root -> right = new Node(value);
            //size++;
        }
        else
            _addCourse(root->right, value);
    }
    
    
}


/* Public Wrapper Function */

template <class bstdata>
void BST<bstdata>::addCourse(bstdata value)
{
    if (root == NULL)
        
    {
        root = new Node(value); //if the tree is empty insert the value at the root
        //size++;
        getSize();
        
    }
    else
    {
        _addCourse(root, value); //otherwise call the helper function, passing it the root
        getSize();
    }
    
}


/*************************************************************************************************************
 * Function name: getRoot                                                                                    *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Returns the data contained at the root node                                                               *
 ************************************************************************************************************/
template <class bstdata>
bstdata BST<bstdata>::getRoot()
{
    if (root == NULL)
    {
        cout << "getRoot() : There is no data in the root" << endl;
        exit(333);
    }
    else
        return root->data;
}



/*************************************************************************************************************
 * Function name: getHeight                                                                                  *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Recursively finds the height of the tree and returns it                                                   *
 ************************************************************************************************************/
/* Private Helper Function */

template <class bstdata>
int BST<bstdata>::_getHeight(Nodeptr root)
{
    if(root == NULL)
        return -1;
    return max(_getHeight(root->left),_getHeight(root->right))+1;
}


/* Public Wrapper Function */

template <class bstdata>
int BST<bstdata>::getHeight()
{
    if(root == NULL)
        return 0;
    else
        return _getHeight(root);
    
}


/*************************************************************************************************************
 * Function name: search                                                                                     *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Search Function to see if the value is in the tree or not                                                 *
 ************************************************************************************************************/
/* Private Helper Function */

template <class bstdata>
bool BST<bstdata>::containsValue(Nodeptr root, bstdata value)
{
    if (value.getCRN() == root->data.getCRN())
        return true;
    
    else if (value.getCRN() < root->data.getCRN())
    {
        if (root -> left == NULL)
            return false;
        
        else
            return containsValue(root->left, value);
    }
    
    else if (value.getCRN() > root->data.getCRN())
    {
        if (root -> right == NULL)
            return false;
        
        else
            return containsValue(root->right, value);
    }
    return false;
}



/* Public Wrapper Function */ // Search Function #1

template <class bstdata>
bool BST<bstdata>::contains(bstdata value)
{
    if (root == NULL)
        return false;
    else
        return containsValue(root, value);
    
}


/* Public Wrapper Function */ // Search Function #2

template <class bstdata>
bool BST<bstdata>::search(bstdata value)
{
    if (root == NULL)
        return false;
    else
        return containsValue(root, value);
    
}


/*************************************************************************************************************
 * Function name: inOrderPrint                                                                               *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Inorder Traversal of the Binary Tree:                                                                     *
 * Left-Root-Right                                                                                           *
 ************************************************************************************************************/
/* Public Wrapper Function */
template <class bstdata>
void BST<bstdata>::inOrderPrint() const
{
    _inOrderPrint(root);
    cout << endl;
}

/* Private Helper Function */
template <class bstdata>
void BST<bstdata>::_inOrderPrint(Nodeptr root) const
{
    if (root)
    {
        _inOrderPrint(root->left);
        root->data.print();
        _inOrderPrint(root->right);
    }
}


/*************************************************************************************************************
 * Function name: preOrderPrint                                                                              *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Preorder Traversal of the Binary Tree:                                                                    *
 * Root-Left-Right                                                                                           *
 ************************************************************************************************************/
/* Public Wrapper Function */
template <class bstdata>
void BST<bstdata>::preOrderPrint() const
{
    _preOrderPrint(root);
    cout << endl;
}

/* Private Helper Function */
template <class bstdata>
void BST<bstdata>::_preOrderPrint(Nodeptr root) const
{
    if (root)
    {
        root->data.print();
        _preOrderPrint(root->left);
        _preOrderPrint(root->right);
    }
}


/*************************************************************************************************************
 * Function name: postOrderPrint                                                                             *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * PostOrder Traversal of the Binary Tree:                                                                   *
 * Left-Right-Root                                                                                           *
 ************************************************************************************************************/
/* Public Wrapper Function */
template <class bstdata>
void BST<bstdata>::postOrderPrint() const
{
    _postOrderPrint(root);
    cout << endl;
}

/* Private Helper Function */
template <class bstdata>
void BST<bstdata>::_postOrderPrint(Nodeptr root) const
{
    if (root)
    {
        _postOrderPrint(root->left);
        _postOrderPrint(root->right);
        root->data.print();
        
    }
}


/*************************************************************************************************************
 * Function name: minimum                                                                                    *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Finds the minimum value in the BST and returns it                                                         *
 ************************************************************************************************************/
/* Private Helper Function */

template <class bstdata>
bstdata BST<bstdata>::findMin(Nodeptr root)
{
    if(root->left)
        return findMin(root->left);
    else
        return root->data;
}


/* Public Wrapper Function */

template <class bstdata>
bstdata BST<bstdata>::minimum()
{
    if (root == NULL)
    {
        cout << "Minimum: Tree is empty" << endl;
        exit(-1);
    }
    else
    {
        return findMin(root);
    }
}



/*************************************************************************************************************
 * Function name: maximum                                                                                    *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * Finds the maximum value in the BST and returns it                                                         *
 ************************************************************************************************************/
/* Private Helper Function */

template <class bstdata>
bstdata BST<bstdata>::findMax(Nodeptr root)
{
    if(root->left)
        return findMin(root->right);
    else
        return root->data;
}


/* Public Wrapper Function */

template <class bstdata>
bstdata BST<bstdata>::maximum()
{
    if (root == NULL)
    {
        cout << "Maximum: Tree is empty" << endl;
        exit(-1);
    }
    else
    {
        return findMax(root);
    }
}


/*************************************************************************************************************
 * Function name: removeCRN                                                                                  *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * To remove crn from the tree                                                                               *
 ************************************************************************************************************/
/* Private Helper Function */
template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::_removeCRN(Nodeptr root, bstdata value)
{
    if(root == NULL)
        return root;
    else if(value.getCRN() < root->data.getCRN())
        root->left = _removeCRN(root->left, value);
    else if(value.getCRN() > root->data.getCRN())
        root->right = _removeCRN(root->right, value);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            Nodeptr temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            value = findMin(root->right);
            root -> data = value;
            root -> right = _removeCRN(root->right,value);
        }
    }
    return root;
}




/* Public Wrapper Function */

template <class bstdata>
void BST<bstdata>::removeCRN(bstdata value)
{
    if(root == NULL){}
    else
    {
        root = _removeCRN(root, value);
        //size--;
        getSize();
    }
}



/*************************************************************************************************************
 * Function name: removeCourse                                                                               *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * To remove course from the tree                                                                            *
 ************************************************************************************************************/
/* Private Helper Function */
template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::_removeCourse(Nodeptr root, bstdata value)
{
    if(root == NULL)
        return root;
    else if(value.getCourse() < root->data.getCourse())
        root->left = _removeCourse(root->left, value);
    else if(value.getCourse() > root->data.getCourse())
        root->right = _removeCourse(root->right, value);
    else if(value.getCourse() == root->data.getCourse() && value.getCRN() == root->data.getCRN())
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            Nodeptr temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            value = findMin(root->right);
            root -> data = value;
            root -> right = _removeCourse(root->right,value);
        }
    }
    return root;
}




/* Public Wrapper Function */

template <class bstdata>
void BST<bstdata>::removeCourse(bstdata value)
{
    if(root == NULL){}
    else
    {
        root = _removeCourse(root, value);
        //size--;
        getSize();
    }
}


/*************************************************************************************************************
 * Function name: isBST                                                                                      *
 *************************************************************************************************************
 * Description of function:                                                                                  *
 * To Determines whether the tree is BST                                                                     *
 ************************************************************************************************************/
template <class bstdata>
bool BST<bstdata>::_isBST(Nodeptr root)
{
    Nodeptr temp = NULL;
    
    if(root)
    {
        if(!_isBST(root->left))
            return false;
        
        if(temp != NULL && root->data <= temp->data)
            return false;
        
        temp = root;
        return _isBST(root->right);
    }
    
    return true;
}


template <class bstdata>
bool BST<bstdata>::isBST()
{
    if(root == NULL)
        return false;
    else
        return _isBST(root);
    
}
#endif /* BST_h */
