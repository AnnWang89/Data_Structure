###### tags: `Data Structure`
## Two Polynomial Addition
* **輸入**: 兩個多項式
* **輸出**: 兩多項式相加
* ex: 

    input: 
    > x^6^+3x^5^+x^3^
    > 2x^5^+x
    > 
    output:
    > x^6^+5x^5^+x^3^+x
            
## Matrix Multiplication
* **輸入**: 兩個矩陣(先輸入矩陣大小再輸入矩陣的值)
* **輸出**: 兩矩陣相加
* ex: 
    
    input: 
    > 3 3 
    > 1 2 3
    > 1 2 1
    > 1 0 4
    > 3 2
    > 2 2
    > 1 1
    > 1 0
    
    output:
    > 7 4
    > 5 4
    > 6 2
            
## Maze
* **輸入**: 迷宮大小及路徑(以0表示)
* **輸出**: 走迷宮路線的座標
* ex: 
    
    input: 
    > 5 5
    > 0 1 1 1 1
    > 1 0 1 1 1
    > 1 1 0 1 1
    > 1 0 1 1 1
    > 1 1 0 0 0
    
    output:
    > 1 1
    > 2 2
    > 3 3
    > 4 2
    > 5 3
    > 5 4
    > 5 5

## Infix to Postfix
* **輸入**: Infix
* **輸出**: Postfix
* ex: 
    
    input: 
    > 1+3*2+6+(1-2)
    
    output:
    > 132*+6+12-+

## Infix to Postfix
* **輸入**: Infix
* **輸出**: Postfix
* ex: 
    
    input: 
    > 1+3*2+6+(1-2)
    
    output:
    > 132*+6+12-+

## Tree Traversals
* **輸入**: 樹的大小與每個node的值
* **輸出**: Tree Postorder/Preorder Traversal
* ex: 
   
    input: 
    > 3
    > 1 2 3
    
    output:
    > 2 3 1 (Post) / 1 2 3 (pre)

## Leafnode
* **輸入**: 樹的大小與Inorder及Preorder
* **輸出**: 該樹的Leaves
* ex: 
    
    input: 
    > 3
    > 2 1 3
    > 1 2 3
    
    output:
    > 1 3
    
## Connected Tree
* **輸入**: edge 數量及所有的edge
* **輸出**: 是否Connected
* ex: 
    
    input: 
    > 2
    > 1 2
    > 2 3
    
    output:
    > Connected!!

## Minimum Spanning Tree
* **輸入**: edge 數量及所有的edge上weights
* **輸出**: Minimum Spanning Tree 的 weight
* ex: 
    
    input: 
    > 4
    > 1 2 1
    > 2 3 2
    > 3 4 3
    > 1 4 4

    
    output:
    > 6
## Quicksort
* **輸入**: a list
* **輸出**: a sorted list
* ex: 
    
    input: 
    > 2 5 4 1 3
    
    output:
    > 1 2 3 4 5
