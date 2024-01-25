#include <stack>
#include <vector>

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct Trunk {
  Trunk *prev;
  string str;

  Trunk(Trunk *prev, string str) {
    this->prev = prev;
    this->str = str;
  }
};

class btree {
public:
  TreeNode *root;

  btree();
  ~btree();

  void insert(int key);
  TreeNode *search(int key);
  void destroy_tree();
  void inorder_print();
  void postorder_print();
  void preorder_print();
  void print();

private:
  void destroy_tree(TreeNode *leaf);
  void insert(int key, TreeNode *leaf);
  TreeNode *search(int key, TreeNode *leaf);
  void inorder_print(TreeNode *leaf);
  void postorder_print(TreeNode *leaf);
  void preorder_print(TreeNode *leaf);

  void printTree(TreeNode *root, Trunk *prev, bool isLeft);
};

btree::btree() { root = NULL; }

btree::~btree() { destroy_tree(); }

void btree::destroy_tree(TreeNode *leaf) {
  if (leaf != NULL) {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, TreeNode *leaf) {

  if (key < leaf->val) {
    if (leaf->left != NULL) {
      insert(key, leaf->left);
    } else {
      leaf->left = new TreeNode(key, NULL, NULL);
    }
  } else if (key >= leaf->val) {
    if (leaf->right != NULL) {
      insert(key, leaf->right);
    } else {
      leaf->right = new TreeNode(key, NULL, NULL);
    }
  }
}

void btree::insert(int key) {
  if (root != NULL) {
    insert(key, root);
  } else {
    root = new TreeNode;
    root->val = key;
    root->left = NULL;
    root->right = NULL;
  }
}

TreeNode *btree::search(int key, TreeNode *leaf) {
  if (leaf != NULL) {
    if (key == leaf->val) {
      return leaf;
    }
    if (key < leaf->val) {
      return search(key, leaf->left);
    } else {
      return search(key, leaf->right);
    }
  } else {
    return NULL;
  }
}

TreeNode *btree::search(int key) { return search(key, root); }

void btree::destroy_tree() { destroy_tree(root); }

void btree::inorder_print() {
  inorder_print(root);
  cout << "\n";
}

void btree::inorder_print(TreeNode *leaf) {
  if (leaf != NULL) {
    inorder_print(leaf->left);
    cout << leaf->val << ",";
    inorder_print(leaf->right);
  }
}

void btree::postorder_print() {
  postorder_print(root);
  cout << "\n";
}

void btree::postorder_print(TreeNode *leaf) {
  if (leaf != NULL) {
    inorder_print(leaf->left);
    inorder_print(leaf->right);
    cout << leaf->val << ",";
  }
}

void btree::preorder_print() {
  preorder_print(root);
  cout << "\n";
}

void btree::preorder_print(TreeNode *leaf) {
  if (leaf != NULL) {
    cout << leaf->val << ",";
    inorder_print(leaf->left);
    inorder_print(leaf->right);
  }
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p) {
  if (p == nullptr) {
    return;
  }

  showTrunks(p->prev);
  cout << p->str;
}

void btree::printTree(TreeNode *root, Trunk *prev, bool isLeft) {
  if (root == nullptr) {
    return;
  }

  string prev_str = "    ";
  Trunk *trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev) {
    trunk->str = "———";
  } else if (isLeft) {
    trunk->str = ".———";
    prev_str = "   |";
  } else {
    trunk->str = "`———";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << " " << root->val << endl;

  if (prev) {
    prev->str = prev_str;
  }
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}

void btree::print() { printTree(root, 0, false); }

int pseudoPalindromicPaths(TreeNode *root);

int main() {

  // btree tree;
  btree *tree = new btree();
  int arr[] = {2, 3, 1, 3, 1, 1};

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    tree->insert(arr[i]);

  tree->print();
  int ret = pseudoPalindromicPaths(tree->root);

  cout << "ret : " << ret << endl;
  delete tree;
}

using namespace std;

bool isPalindromePath(vector<int> &occurence) {
  int odds = 0;

  for (int i = 0; i < occurence.size(); i++) {
    if (occurence[i] % 2) {
      odds++;
      if (odds > 1)
        return false;
    }
  }
  return true;
}

TreeNode *inorderSuccessor(TreeNode *node, stack<TreeNode *> &path,
                           vector<int> &occurence) {
  TreeNode *ret;

  // the smallest key that is larger than x

  ret = 0;
  // left most child of its right suNode
  if (node->right) {
    ret = node->right;
    path.push(ret);
    occurence[ret->val - 1]++;
    while (ret->left) {
      ret = ret->left;
      path.push(ret);
      occurence[ret->val - 1]++;
    }
  }
  // first parent where the most recent child is not its right child
  else {
    occurence[path.top()->val - 1]--;
    path.pop();
    ret = path.empty() ? 0 : path.top();
    while (ret && ret->right == node) {
      node = ret;
      occurence[path.top()->val - 1]--;
      path.pop();
      ret = path.empty() ? 0 : path.top();
    }
  }
  return ret;
}

TreeNode *beginTree(TreeNode *root, stack<TreeNode *> &path,
                    vector<int> &occurence) {
  TreeNode *ret;

  ret = root;
  path.push(ret);
  occurence[ret->val - 1]++;
  while (ret->left) {
    ret = ret->left;
    path.push(ret);
    occurence[ret->val - 1]++;
  }
  return ret;
}

int pseudoPalindromicPaths(TreeNode *root) {
  int ret = 0;
  TreeNode *head;
  vector<int> occurence(9, 0);
  stack<TreeNode *> path;

  head = beginTree(root, path, occurence);

  while (head && !path.empty()) {
    if (!head->left && !head->right) {
      ret += isPalindromePath(occurence);
      cout << endl << "--------------------------------------" << endl;
      cout << endl << "leaf : " << head->val << endl;
      for (int i = 0; i < occurence.size(); i++)
        cout << occurence[i] << " ";
      cout << endl << "--------------------------------------" << endl;
    }
    head = inorderSuccessor(head, path, occurence);
  }
  return ret;
}