Using min heap tree sort to solve frational knapsack problem

first line input two inregers

N is the number of items

W is weight

second line input 2*N integers denoting Values and weight respectively

首先進入min_heap_sort做排序

把排序好的資料的weight依序加到curWeight直到超過總重量W

如果我們加到已經無法再加目前的item，就先計算剩下多少重量我們可以加

再把目前的item乘上比例加到curWeight

最後的curWeight就是我們要的答案