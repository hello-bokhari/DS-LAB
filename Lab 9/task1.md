        30
       /  \
     20    40
    /        \
  10          50

Insertion order [10, 20, 30, 40, 50], then insert 15

        30
       /  \
     20    40
    / \      \
  10  15     50

The balance factor of node 20 = height(left) - height(right) = 1 - 1 = 0
All nodes remain balanced no rotation required.
        30
       /  \
     20    40
    / \      \
  10  15     50
