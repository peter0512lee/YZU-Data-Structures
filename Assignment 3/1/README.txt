[1]. Insert a key : O(h), h is the height
先用一個指標去尋找在目前的樹中藥插入新的node的適合位置
找到之後在把要插入的node接上BST

[2]. Delete a key : O(h)
先確認BST中是否有具有要刪除的key的node
把真正會被釋放記憶體的pointer調整成「至多只有一個child」的node
把真正會被釋放記憶體的node的child指向新的parent
把真正會被釋放記憶體的node的parent指向新的child

[3]. Find the minimum key in current binary tree : O(h)
往左子樹找找到最左邊的node就是答案

[4]. Find the maximum key in current binary tree : O(h)
往右子樹找找到最右邊的node就是答案

[5]. Print out current binary tree : O(h)
我是把整個樹翻轉90度印出來
最左邊就是level1 以此類推

[6]. Perform a pre-order traversal of the tree : O(n)
V：Visiting，對當前所在的node進行print、assign或其他操作
L：移動到left child
R：移動到right child
pre-order就是VLR

[7]. Perform a post-order traversal of the tree : O(n)
post-order就是LRV

[8]. Swap the left child and right child of every node of the binary search tree : O(h)
從level1開始，把每個level的leftchild與rightchild交換
