#include "binaryTree.cpp"

int main() {
  BinaryTree tree(1);

  cout << "========== Pre-order Traversal (With Recursion) ==============\n";
  tree.print(PREORDER, false);
  cout << "========== In-order Traversal (With Recursion) ===============\n";
  tree.print(INORDER, false);
  cout << "========== Post-order Traversal (With Recursion) =============\n";
  tree.print(POSTORDER, false);
  cout << "========== Pre-order Traversal (Without Recursion) ===========\n";
  tree.print(PREORDER, true);
  cout << "========== In-order Traversal (Without Recursion) ============\n";
  tree.print(INORDER, true);
  cout << "========== Post-order Traversal (Without Recursion) ==========\n";
  tree.print(POSTORDER, true);

  return 0;
}
