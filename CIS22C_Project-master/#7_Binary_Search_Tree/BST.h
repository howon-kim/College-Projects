//
//  BST.h
//  Binary_Search_Tree
//
//  Created by HOWON KIM on 2/10/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#ifndef BST_h
#define BST_h
#include <cstddef>
#include <string>
#include <iostream>
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
    
    void addValue(Nodeptr root, bstdata value);
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

    Nodeptr removeValue(Nodeptr root, bstdata value);

    
public:
    BST();
    ~BST();
    BST(const BST<bstdata> &tree);

    bool isEmpty();
    int getSize();
    void add(bstdata value);
    bstdata getRoot();
    
    //more functions to be added here!
    
    bool contains(bstdata value);
    
    void inOrderPrint() const;
    void preOrderPrint() const;
    void postOrderPrint() const;
    
    bstdata minimum();
    bstdata maximum();
    
    int getHeight();
    
    bool search(bstdata value);
    bool isBST();
    
    void remove(bstdata value);

    
};



/*---------------------------------------------------------------------
 Constructor
 --------------------------------------------------------------------*/
template <class bstdata>
BST<bstdata>::BST():root(NULL),size(0){}


/*---------------------------------------------------------------------
 Copy Constructor
 --------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------
 Destructor
 --------------------------------------------------------------------*/

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


/*---------------------------------------------------------------------
 Check the tree is empty or not
 --------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------
 Return the size of the tree
 --------------------------------------------------------------------*/


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

/*---------------------------------------------------------------------
 Add Function
 --------------------------------------------------------------------*/

/* Private Helper Function */
template <class bstdata>
void BST<bstdata>::addValue(Nodeptr root, bstdata value)
{
    if (value == root->data)
        return;
    
    else if (value < root->data)
    {
        if (root -> left == NULL)
        {
            root -> left = new Node(value);
            //size++;
        }
        else
            addValue(root->left, value);
    }
    
    else
    {
        if (root -> right == NULL)
        {
            root -> right = new Node(value);
            //size++;
        }
        else
            addValue(root->right, value);
    }
    
    
}


/* Public Wrapper Function */

template <class bstdata>
void BST<bstdata>::add(bstdata value)
{
    if (root == NULL)
        
    {
        root = new Node(value); //if the tree is empty insert the value at the root
        //size++;
        getSize();
        
    }
    else
    {
        addValue(root, value); //otherwise call the helper function, passing it the root
        getSize();
    }
    
}


/*---------------------------------------------------------------------
 Returns the data contained at the root node
 --------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------
 Recursively finds the height of the tree and returns it
 --------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------
 Search Function
 --------------------------------------------------------------------*/

/* Private Helper Function */

template <class bstdata>
bool BST<bstdata>::containsValue(Nodeptr root, bstdata value)
{
    if (value == root->data)
        return true;
    
    else if (value < root->data)
    {
        if (root -> left == NULL)
            return false;
        
        else
            return containsValue(root->left, value);
    }
    
    else if (value > root->data)
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

/*---------------------------------------------------------------------
 Inorder Traversal of the Binary Tree:
 Left-Root-Right
 --------------------------------------------------------------------*/

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
        cout << root->data << " ";
        _inOrderPrint(root->right);
    }
}


/*---------------------------------------------------------------------
 Preorder Traversal of the Binary Tree:
 Root-Left-Right
 --------------------------------------------------------------------*/

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
        cout << root->data << " ";
        _preOrderPrint(root->left);
        _preOrderPrint(root->right);
    }
}

/*---------------------------------------------------------------------
 PostOrder Traversal of the Binary Tree:
 Left-Right-Root
 --------------------------------------------------------------------*/

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
        cout << root->data << " ";
        
    }
}

/*---------------------------------------------------------------------
 Finds the minimum value in the BST and returns it
 --------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------
 Finds the maximum value in the BST and returns it
 --------------------------------------------------------------------*/


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


/*---------------------------------------------------------------------
 Finds the maximum value in the BST and returns it
 --------------------------------------------------------------------*/

/* Private Helper Function */

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::removeValue(Nodeptr root, bstdata value)
{
    if(root == NULL)
        return root;
    else if(value < root->data)
        root->left = removeValue(root->left, value);
    else if(value > root->data)
        root->right = removeValue(root->right, value);
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
            int min = findMin(root->right);
            root -> data = min;
            root -> right = removeValue(root->right,min);
        }
    }
    return root;
}




/* Public Wrapper Function */
template <class bstdata>
void BST<bstdata>::remove(bstdata value)
{
    if(root == NULL)
        return;
    else
    {
        root = removeValue(root, value);
        //size--;
        getSize();
    }
}





/*---------------------------------------------------------------------
 Determines whether the tree is BST
 --------------------------------------------------------------------*/
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
