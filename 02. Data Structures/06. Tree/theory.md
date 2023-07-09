# 1. Definitions

A **tree** is a frequently-used data structure to simulate a hierarchical tree structure.
Each node of the tree will have a root value and a list of references to other nodes which are called child nodes.

![Tree](https://algorithmtutor.com/images/tree.png)

# 2. Binary Tree

A **binary tree** is one of the most typical tree structure. As the name suggests, a binary tree is a data structure in which each node has at most two children, which are referred to as the left child and the right child.
The above image is an example of a binary tree.

## Traverse a Binary Tree

Now let's see the different traversal methods used in a binary tree.

* **Pre-order Traversal**: Pre-order traversal is to visit the root first. Then traverse the left subtree. Finally, traverse the right subtree.

![Pre-order Traversal](https://lh5.googleusercontent.com/b9g2tL87bG9rK2JIMBbZUIVTev9yOmfeJlx8Y_pmUiVDSjpmeof97B6d6ok4p6qrwq8TX2NaRqJKo1uXcqxNGzuHhq4H3uSaICyJcb4ERwsxyF-YVy0Sakb2EjEqlGn__FG_Ml4k)

* **In-order Traversal**: In-order traversal is to traverse the left subtree first. Then visit the root. Finally, traverse the right subtree.

![In-order Traversal](https://lh3.googleusercontent.com/QRTgAbTK-54jPLU87RN4OAXWlBu1WR36LyaANNQ_Pg0N2gKmM0k_30h5S68Dwm_2qledVGQd5Byltj16KO3J5ufZs1ipixS4DKpHTRITXDiHajiLXEjf_sY7Id7e8G7r4mhBbANn)

* **Post-order Traversal**: Post-order traversal is to traverse the left subtree first. Then traverse the right subtree. Finally, visit the root.

![Post-order Traversal](https://lh6.googleusercontent.com/dyKoxSFKtdnpEVpNOV1_460ovzzLqcIe7rRplr6YrUheWqVJgtk9GztN-QHkvbxtJlDCo8_Y5NzLevE0dNxsitYjV0o3hUruNwcxYDteBGTzNg9knB0kfOMMmtY5B7Xrie2tnd86)