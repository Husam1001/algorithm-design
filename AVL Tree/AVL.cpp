#include <bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node
{
public:
  string data;
  Node* left;
  Node* right;
  int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get the
// height of the tree
int
height(Node* N)
{
  if (N == NULL)
    return 0;
  return N->height;
}

// A utility function to get maximum
// of two integers
int
max(int a, int b)
{
  return (a > b) ? a : b;
}

/* Helper function that allocates a
   new node with the given data and
   NULL left and right pointers. */
Node*
newNode(string data)
{
  Node* node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1; // new node is initially
  // added at leaf
  return (node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node*
rightRotate(Node* y)
{
  Node* x = y->left;
  Node* T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  // Return new root
  return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node*
leftRotate(Node* x)
{
  Node* y = x->right;
  Node* T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  // Return new root
  return y;
}

// Get Balance factor of node N
int
getBalance(Node* N)
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Recursive function to insert a data
// in the subtree rooted with node and
// returns the new root of the subtree.
Node*
insert(Node* node, string data)
{
  /* 1. Perform the normal BST insertion */
  if (node == NULL)
    return (newNode(data));

  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);
  else // Equal datas are not allowed in BST
    return node;

  /* 2. Update height of this ancestor node */
  node->height = 1 + max(height(node->left), height(node->right));

  /* 3. Get the balance factor of this ancestor
    node to check whether this node became
    unbalanced */
  int balance = getBalance(node);

  // If this node becomes unbalanced, then
  // there are 4 cases

  // Left Left Case
  if (balance > 1 && data < node->left->data)
    return rightRotate(node);

  // Right Right Case
  if (balance < -1 && data > node->right->data)
    return leftRotate(node);

  // Left Right Case
  if (balance > 1 && data > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && data < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  /* return the (unchanged) node pointer */
  return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void
preOrder(Node* root)
{
  if (root != NULL) {
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

// Function to traverse the tree in preorder
// and check if the given node exists in it
bool
ifNodeExists(Node* node, string data)
{
  if (node == NULL)
    return false;

  if (node->data == data)
    return true;

  /* then recur on left sutree */
  bool res1 = ifNodeExists(node->left, data);
  // node found, no need to look further
  if (res1)
    return true;

  /* node is not found in left,
so recur on right subtree */
  bool res2 = ifNodeExists(node->right, data);

  return res2;
}

int
main()
{
  Node* root = NULL;
  ifstream file("emailList.txt");
  string email;
  int number_Of_Email;
  int counter = 0;
  cout << "Enter Number of email to be inserted: ";
  cin >> number_Of_Email;
  auto start = chrono::system_clock::now();
  while (file >> email && counter < number_Of_Email) {
    root = insert(root, email);
    counter++;
  }
  file.close();
  auto end = chrono::system_clock::now();
  cout << endl;
  chrono::duration<double> duration = end - start;
  cout << "Duration: " << duration.count() << "s\n";
  string search_email;
  while (true) {
    cout << "Enter email to be Search: ";
    cin >> search_email;
    auto start_search = chrono::system_clock::now();
    if (ifNodeExists(root, search_email)) {
      cout << "Target found\n";
    } else
      cout << "Target not found\n";
    auto end_search = chrono::system_clock::now();
    chrono::duration<double> search_duration = end_search - start_search;
    cout << "Search Duration: " << search_duration.count() << "s\n";
  }
  // preOrder(root);

  return 0;
}
