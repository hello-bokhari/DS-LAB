#Task 0
AVL trees maintain height balance after every insertion and deletion, ensuring O(log n) search, insertion, and deletion times.They prevent skewed BSTs by performing rotations when imbalance occurs.

#Explanation
-   The inorder traversal collects elements in sorted order (since BST is sorted).
-   Then the middle element becomes the root (balanced division).
-   Recursive calls build left and right subtrees, ensuring balance.
-   At the end, the root node of the balanced AVL is returned.