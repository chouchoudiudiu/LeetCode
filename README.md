 No  | Title           |  Solution       |  Time           | Space           | Difficulty    | Tag          | Note
-----|---------------- | --------------- | --------------- | --------------- | ------------- |--------------| -----
1 | [Two Sum](https://leetcode.com/problems/two-sum/#/description/) | [Hash Table](./src/001.Two_Sum.cpp)  |  O(n)    |  O(n)        | Easy         ||
2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/#/description/) | [LinkedList](./src/002.Add_Two_Numbers.cpp)  |  O(n)    |  O(1)        | Medium         ||
3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description/) | [Hash Table; Two Pointer](./src/003.Longest_Substring_Without_Repeating_Characters.cpp)  |  O(n)    |  O(1)        | Medium     | Y    |
4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/#/description/) | [Divide and Conquer](./src/004.Median_of_Two_Sorted_Arrays.cpp)  |  O(log(m + n))    |  O(1)        | Hard | Y |special to []||
5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/#/description/) | [String](./src/005.Longest_Palindromic_Substring.cpp)  |  O(n^2)    |  O(1)        | Medium         ||
6 | [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/#/description/) | [String](./src/006.ZigZag_Conversion.cpp)  |  O(n)    |  O(1)        |Medium |  |pattern       ||
7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/#/description/) | [Math](./src/007.Reverse_Integer.cpp)  |  O(n)    |  O(1)        |Easy |  |use long for Overflow        ||
8 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/#/description/) | [String](./src/008.String_to_Integer_(atoi).cpp)  |  O(n)    |  O(1)        |Medium |  |long long       ||
9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/#/description/) | [Math](./src/009.Palindrome_Number1.cpp) \|  [Math](./src/009.Palindrome_Number2.cpp) |  O(x) (O(1))    |  O(1)        |Easy |  |compare half, overflow      ||
10 | [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/#/description/) | [Recursion](./src/010.Regular_Expression_Matching.cpp) \|  [DP]() |  O(e?)    |  O(1)        |Hard | Y |DP      ||
11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/#/description/) | [Two Pointers](./src/011.Container_With_Most_Water.cpp) |  O(n)    |  O(1)        |Medium | Y |   ||
12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/#/description/) | [Solution](./src/012.Integer_to_Roman.cpp) |  O(n)    |  O(1)        |Medium |  |   ||
13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/#/description/) | [Solution](./src/013.Roman_to_Integer.cpp) |  O(n)    |  O(1)        |Easy |  |   ||
14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/#/description/) | [String](./src/014.Longest_Common_Prefix.cpp) |  O(n\*k)    |  O(1) |Easy |  |   ||
15 | [3Sum](https://leetcode.com/problems/3sum/#/description/) | [Two Pointers](./src/015.3Sum.cpp) |  O(n^2)    |  O(1) |Medium | Y |  use set; or skip duplicates ||
16 | [3Sum Closest](https://leetcode.com/problems/3sum-closest/#/description/) | [Two Pointers](./src/016.3Sum_Closest.cpp) |  O(n^2)    |  O(1) |Medium |  |   ||
17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description/) | [BFS](./src/017.Letter_Combinations_of_a_Phone_Number1.cpp) \| [DFS](./src/017.Letter_Combinations_of_a_Phone_Number2.cpp)  |  O(4^n)    |  O(n) |Medium | Y |   ||
18 | [4Sum](https://leetcode.com/problems/4sum/#/description/) | [Two Pointers](./src/018.4Sum.cpp) |  O(n^3)    |  O(1) |Medium |  |  use set; or skip duplicates ||
19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description/) | [Two Pointers](./src/019.Remove_Nth_Node_From_End_of_List.cpp) |  O(n)    |  O(1) |Medium | Y | delete head, tail cases  ||
20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/#/description/) | [Stack](./src/020.Valid_Parentheses.cpp) |  O(n)    |  O(n) |Easy |  |   ||
21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/#/description/) | [LinkedList](./src/021.Merge_Two_Sorted_Lists.cpp) |  O(n)    |  O(1) |Easy |  |   ||
22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/#/description/) | [DFS](./src/022.Generate_Parentheses.cpp) |  ?   |  O(1) |Medium | Y |   ||
23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/#/description/) | [Heap](./src/023.Merge_k_Sorted_Lists.cpp) |   O(n\*k)    |  O(k) | Hard | Y |   ||
24 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/#/description/) | [LinkedList](./src/024.Swap_Nodes_in_Pairs1.cpp) \| [Recursion](./src/024.Swap_Nodes_in_Pairs2.cpp)|  O(n)   |  O(1) |Medium | |   ||
25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/#/description/) | [Recursion](./src/025.Reverse_Nodes_in_k-Group.cpp) |  O(n)   |  O(1) |Hard| |   ||
26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description/) | [Two Pointer](./src/026.Remove_Duplicates_from_Sorted_Array.cpp) |  O(n)   |  O(1) | Easy |  |   ||
27 | [Remove Element](https://leetcode.com/problems/remove-element/#/description/) | [Two Pointer](./src/027.Remove_Element.cpp) |  O(n)   |  O(1) | Easy |  | rare  ||
28 | [Implement strStr()](https://leetcode.com/problems/implement-strstr/#/description/) | [Two Pointer](./src/028.Implement_strStr().cpp) |  O(n\*k)   |  O(1) | Easy |  | check KMP?   ||
29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/#/description/) | [Bit Manipulation](./src/029.Divide_Two_Integers.cpp) |  O(logn)   |  O(1) | Medium | Y  |   ||
30 | [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/#/description/) | [Hash Table](./src/030.Substring_with_Concatenation_of_All_Words.cpp) |  O(n)   |  O(n) | Hard |  |    ||
31 | [Next Permutation](https://leetcode.com/problems/next-permutation/#/description/) | [Binary Search](./src/031.Next_Permutation.cpp) |  O(n)   |  O(1) | Medium | Y | Binary Search    ||
32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/#/description/) | [Stack](./src/032.Longest_Valid_Parentheses.cpp) |  O(n)   |  O(n) | Hard |  |     ||
33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/#/description/) | [Binary Search](./src/033.Search_in_Rotated_Sorted_Array.cpp) |  O(logn)   |  O(1) | Medium | Y  |   <=  ||
34 | [Search for a Range](https://leetcode.com/problems/search-for-a-range/#/description/) | [Binary Search](./src/034.Search_for_a_Range.cpp) |  O(logn)   |  O(1) | Medium |  |     ||
35 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/#/description/) | [Binary Search](./src/035.Search_Insert_Position.cpp) |  O(logn)   |  O(1) | Easy |   |    ||
36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/#/description/) | [Hash Table](./src/036.Valid_Sudoku.cpp) |  O(9^2)   |  O(1) | Medium|   |    ||
37 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/#/description/) | [BackTracking](./src/037.Sudoku_Solver.cpp) |  O(O((9!)^9))   |  O(1) | Hard |   |    ||
38 | [Count and Say](https://leetcode.com/problems/count-and-say/#/description/) | [Solution](./src/038.Count_and_Say.cpp) |  O(n)   |  O(1) | Easy |   |     ||
39 | [Combination Sum](https://leetcode.com/problems/combination-sum/#/description/) | [DFS](./src/039.Combination_Sum.cpp) |  O(2^n)   | O(1)  | Medium |  |     ||
40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/#/description/) | [DFS](./src/040.Combination_Sum_II.cpp) | O(2^n)| O(1) | Medium  | Y  |  prev  ||
41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/#/description/) | [Array](./src/041.First_Missing_Positive.cpp) |  O(n)   |  O(1) | Hard | Y  |     ||
42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/#/description/) | [Two Pointers](./src/042.Trapping_Rain_Water.cpp) |  O(n)   | O(1)  | Hard |  |     ||
43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/#/description/) | [String](./src/043.Multiply_Strings.cpp) | O(m\*n)| O(1) | Medium  | Y  |    ||
44 | [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/#/description/) | [Greedy](./src/044.Wildcard_Matching.cpp) | O(n)| O(1) | Hard  | Y  |    ||
45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/#/description/) | [Two Pointer](./src/045.Jump_Game_II.cpp) |  O(n)   |  O(1) | Hard | Y  |     ||
46 | [Permutations](https://leetcode.com/problems/permutations/#/description/) | [DFS](./src/046.Permutations.cpp) |  O(n\*n!)   | O(n)  | Medium |  |     ||
47 | [Permutations II](https://leetcode.com/problems/permutations-ii/#/description/) | [DFS](./src/047.Permutations_II_1.cpp) \|[Hash Table](./src/047.Permutations_II_2.cpp) | O(n\*n!)| O(n) | Medium  | Y  |    ||
48 | [Rotate Image](https://leetcode.com/problems/rotate-image/#/description/) | [In Place](./src/048.Rotate_Image.cpp) |  O(n^2)   |  O(1) | Medium |   |     ||
49 | [Group Anagrams](https://leetcode.com/problems/anagrams/#/description/) | [Hash Table](./src/049.Group_Anagrams.cpp) |  O(m\*n)   | O(1)  | Medium |  |     ||
50 | [Pow(x, n)](https://leetcode.com/problems/powx-n/#/description/) | [Divide and Conquer](./src/050.Pow_x_n.cpp) | O(logn)| O(1) | Medium  | Y  |    ||
51 | [N-Queens](https://leetcode.com/problems/n-queens/#/description/) | [BackTracking](./src/051.N-Queens.cpp) |  O(exp)   | O(n)  | Hard | Y |     ||
52 | [N-Queens II](https://leetcode.com/problems/n-queens-ii/#/description/) | [Back Tracking](./src/052.N-QueensII.cpp)  | O(exp)| O(n) | Hard  |   |    ||
53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/#/description/) | [DP](./src/053.Maximum_Subarray.cpp) \| [Greedy](./src/053.Maximum_Subarray2.cpp)  |  O(n)   |  O(1) | Easy | Y |     ||
54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/#/description/) | [In Place](./src/054.Spiral_Matrix.cpp) |  O(n^2)   | O(1)  | Medium |  |     ||
55 | [Jump Game](https://leetcode.com/problems/jump-game/#/descriptionn/) | [Greedy](./src/055.Jump_Game.cpp) | O(n)| O(1) | Medium  |   |    ||
56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/#/description/) | [Sort](./src/056.Merge_Intervals.cpp) |  O(nlogn)   | O(1)  | Medium |  |     ||
57 | [Insert Interval](https://leetcode.com/problems/insert-interval/#/description/) | [Array](./src/057.Insert_Interval.cpp)  | O(n)| O(1) | Hard  | Y |    ||
58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/#/description/) | [String](./src/058.Length_of_Last_Word.cpp) |  O(n)   |  O(1) | Easy |  |     ||
59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/#/description/) | [In Place](./src/059.Spiral_Matrix_II.cpp) |  O(n^2)   | O(1)  | Medium |  |     ||
60 | [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/#/description/) | [Recursive](./src/060.Permutation_Sequence1.cpp) \| [Iterative](./src/060.Permutation_Sequence2.cpp) | O(n)| O(1) | Medium  | Y |    ||
61 | [Rotate List](https://leetcode.com/problems/rotate-list/#/description/) | [Two Pointers](./src/061.Rotate_List.cpp) |  O(n)   | O(1)  | Medium |  |     ||
62 | [Unique Paths](https://leetcode.com/problems/unique-paths/#/description/) | [DP](./src/062.Unique_Paths.cpp)  | O(m\*n)| O(m\*n) | Medium  |  |  can make space O(n)  ||
63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/#/description/) | [DP](./src/063.Unique_Paths_II.cpp) | O(m\*n)   |  O(m\*n) | Medium |  |     ||
64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/#/description/) | [DP](./src/064.Minimum_Path_Sum.cpp) |  O(m\*n)  | O(m\*n)  | Medium |  |     ||
65 | [Valid Number](https://leetcode.com/problems/valid-number/#/description/) | [String](./src/065.Valid_Number.cpp) | O(n)| O(1) | Hard | Y |    ||
66 | [Plus One](https://leetcode.com/problems/plus-one/#/description/) | [Math](./src/066.Plus_One.cpp) |  O(n)   | O(1)  | Easy |  |     ||
67 | [Add Binary](https://leetcode.com/problems/add-binary/#/description/) | [Math](./src/067.Add_Binary.cpp)  | O(n)| O(1) | Easy  |  |    ||
68 | [Text Justification](https://leetcode.com/problems/text-justification/#/description/) | [String](./src/068.Text_Justification.cpp) | O(n)   |  O(1) | Hard | Y |     ||
69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/#/description/) | [Binary Search](./src/069.Sqrt(x).cpp) |  O(logn)  | O(1)  | Easy |  Y |     ||
70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/#/description/) | [DP](./src/070.Climbing_Stairs.cpp) | O(n)| O(n); O(1) | Easy |  |  Fib  ||
71 | [Simplify Path](https://leetcode.com/problems/simplify-path/#/description/) | [Stack](./src/071.Simplify_Path.cpp) |  O(n)  | O(n)  | Medium |  | Stringstream    ||
72 | [Edit Distance](https://leetcode.com/problems/edit-distance/#/description/) | [DP](./src/072.Edit_Distance.cpp) | O(n)| O(1) | Hard | Y |    ||
73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/#/description/) | [Math](./src/073.Set_Matrix_Zeroes.cpp) |  O(n^2)   | O(1)  | Medium |  |     ||
74 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/#/description/) | [Binary Search](./src/074.Search_a_2D_Matrix.cpp)  | O(logn)| O(1) | Medium  |  |    ||
75 | [Sort Colors](https://leetcode.com/problems/sort-colors/#/description/) | [Two Pointers](./src/075.Sort_Colors.cpp) | O(n)   |  O(1) | Medium |  Y |     ||
76 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/#/description/) | [Two Pointers](./src/076.Minimum_Window_Substring.cpp) |  O(n)  | O(1)  | Hard |  Y |     ||
77 | [Combinations](https://leetcode.com/problems/combinations/#/description/) | [Back Tracking](./src/077.Combinations.cpp) |  O(n!)    | O(n)  | Medium |  |     ||
78 | [Subsets](https://leetcode.com/problems/subsets/#/description/) | [Back Tracking](./src/078.Subsets.cpp)  | O(2^n) | O(1) | Medium  |  |    ||
79 | [Word Search](https://leetcode.com/problems/word-search/#/description/) | [DFS](./src/079.Word_Search.cpp) | O(m\*n)   |  O(1) | Medium |  Y |     ||
80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/#/description/) | [Two Pointers](./src/080.Remove_Duplicates_from_Sorted_Array_II.cpp) |  O(n)  | O(1)  | Medium |   |     ||
81 | [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/#/description/) | [Binary Search](./src/081.Search_in_Rotated_Sorted_Array_II.cpp) |  O(logn)  | O(1)  | Medium |  Y | worst case O(n)    ||
82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description/) | [LinkedList](./src/082.Remove_Duplicates_from_Sorted_List_II.cpp) |  O(n)    | O(1)  | Medium | Y  |    ||
83 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description/) | [LinkedList](./src/083.Remove_Duplicates_from_Sorted_List.cpp)  | O(n) | O(1) | Easy  |  |    ||
84 | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/#/description/) | [Stack](./src/084.Largest_Rectangle_in_Histogram.cpp) | O(n)   |  O(n) | Hard |  Y |     ||
85 | [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/#/description/) | [Stack](./src/085.Maximal_Rectangle.cpp) |  O(m\*n) | O(n)  | Hard |   |     ||
86 | [Partition List ](https://leetcode.com/problems/partition-list/#/description/) | [LinkedList](./src/086.Partition_List.cpp) |  O(n)  | O(1)  | Medium |   |     ||
87 | [Scramble String](https://leetcode.com/problems/scramble-string/#/description/) | [Hash Table, DFS](./src/087.Scramble_String.cpp) |  O(exp)    | O(m\*n)  | Hard | Y  |    ||
88 | [Merge Sorted Array ](https://leetcode.com/problems/merge-sorted-array/#/description/) | [Two Pointers](./src/088.Merge_Sorted_Array.cpp)  | O(n) | O(1) | Easy  |  |    ||
89 | [Gray Code ](https://leetcode.com/problems/gray-code/#/description/) | [Math](./src/089.Gray_Code.cpp) | O(n)   |  O(1) | Medium |   |     ||
90 | [Subsets II  ](https://leetcode.com/problems/subsets-ii/#/description/) | [DFS1](./src/090.Subsets_II_1.cpp) \| [DFS2](./src/090.Subsets_II_2.cpp)|  O(2^n) | O(1)  | Medium |  Y |  sort first   ||
91 | [Decode Ways ](https://leetcode.com/problems/decode-ways/#/description/) | [DP](./src/091.Decode_Ways.cpp) |  O(n)  | O(n)  | Medium | Y |  reduce space  ||
92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/#/description) | [LinkedList](./src/092.Reverse_Linked_List_II.cpp) |  O(n)    | O(1)  | Medium	 |   |    ||
93 | [Restore IP Addresses ](https://leetcode.com/problems/restore-ip-addresses/#/description/) | [DFS](./src/093.Restore_IP_Addresses.cpp)  | O(2^n)  | O(1) | Medium	  |  |    ||
94 | [Binary Tree Inorder Traversal ](https://leetcode.com/problems/binary-tree-inorder-traversal/#/description/) | [Stack](./src/094.Binary_Tree_Inorder_Traversal.cpp) | O(n)   |  O(n) | Medium | Y  |     ||
95 | [Unique Binary Search Trees II ](https://leetcode.com/problems/unique-binary-search-trees-ii/#/description/) | [DFS](./src/095.Unique_Binary_Search_Trees_II.cpp) |  O(2^n) | O(n)  | Medium |  Y |     ||
96 | [Unique Binary Search Trees ](https://leetcode.com/problems/unique-binary-search-trees/#/description/) | [DP](./src/096.Unique_Binary_Search_Trees_1.cpp	) \| [Recursion](./src/096.Unique_Binary_Search_Trees_2.cpp	) |  O(n)  | O(n)  | Medium | Y |   ||
97 | [Interleaving String ](https://leetcode.com/problems/interleaving-string/#/description/) | [DP](./src/097.Interleaving_String.cpp	) |  O(n^2)    | O(n^2)  | Hard	 |   |    ||
98 | [Validate Binary Search Tree ](https://leetcode.com/problems/validate-binary-search-tree/#/description/) | [Inorder](./src/098.Validate_Binary_Search_Tree_1.cpp) \| [Recursion](./src/098.Validate_Binary_Search_Tree_2.cpp) | O(n)  | O(1) | Medium	  | Y |    ||
99 | [Recover Binary Search Tree ](https://leetcode.com/problems/recover-binary-search-tree/#/description/) | [Recursion](./src/099.Recover_Binary_Search_Tree.cpp) | O(n)   |  O(1) | Hard |   |     ||
100 | [Same Tree ](https://leetcode.com/problems/same-tree/#/description/) | [Recursion](./src/100.Same_Tree.cpp) |  O(n) | O(1)  | Easy |   |     ||
101 | [Symmetric Tree ](https://leetcode.com/problems/symmetric-tree/#/description/) | [Recusion](./src/101.Symmetric_Tree.cpp	)  |  O(n) | O(1)  | Easy|  |   ||
102 | [Binary Tree Level Order Traversal ](https://leetcode.com/problems/binary-tree-level-order-traversal/#/description/) | [BFS](./src/102.Binary_Tree_Level_Order_Traversal_1.cpp	) \| [DFS](./src/102.Binary_Tree_Level_Order_Traversal_2.cpp	) |  O(n) | O(n)  | Medium	 | Y  |    ||
103 | [Binary Tree Zigzag Level Order Traversal ](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/#/description/) | [Stacks](./src/103.Binary_Tree_Zigzag_Level_Order_Traversal.cpp) | O(n) | O(n) | Medium	  |  |    ||
104 | [Maximum Depth of Binary Tree ](https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description/) | [Recursion](./src/104.Maximum_Depth_of_Binary_Tree.cpp) | O(n)   |  O(1) | Easy |   |     ||
105 | [Construct Binary Tree from Preorder and Inorder Traversal ](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description/) | [Recursion](./src/105.Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp) |  O(n) | O(1)  | Medium |   |     ||
106 | [Construct Binary Tree from Inorder and Postorder Traversal ](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/#/description/) | [Recusion](./src/106.Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp 	)  |  O(n) | O(n)  | Medium|  |   ||
107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/#/description/) | [BFS](./src/107.Binary_Tree_Level_Order_Traversal_II_1.cpp	) \| [DFS](./src/107.Binary_Tree_Level_Order_Traversal_II_2.cpp	) |  O(n) | O(n)  | Easy	 | Y  |    ||
108 | [Convert Sorted Array to Binary Search Tree ](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/#/description/) | [Divide and Conquer](./src/108.Convert_Sorted_Array_to_Binary_Search_Tree.cpp) | O(logn) | O(1) | Easy  |  |    ||
109 | [Convert Sorted List to Binary Search Tree ](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/#/description/) | [Divide and Conquer](./src/109.Convert_Sorted_List_to_Binary_Search_Tree.cpp) | O(logn)   |  O(1) | Medium | Y  |     ||
110 | [Balanced Binary Tree   ](https://leetcode.com/problems/balanced-binary-tree/#/description/) | [Recursion](./src/110.Balanced_Binary_Tree.cpp) |  O(n) | O(h)  | Easy |   |     || 
111 | [Minimum Depth of Binary Tree  ](https://leetcode.com/problems/minimum-depth-of-binary-tree/#/description/) | [Recusion](./src/111.Minimum_Depth_of_Binary_Tree.cpp	)  |  O(n) | O(1)  | Easy|  |  null? ||
112 | [Path Sum](https://leetcode.com/problems/path-sum/#/description/) | [Recusion](./src/112.Path_Sum.cpp) |  O(n) | O(1)  | Easy	 | Y  |    ||
113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii/#/description/) | [Recusion](./src/113.Path_Sum_II.cpp) | O(n) | O(1) | Medium  |  |    ||
114 | [Flatten Binary Tree to Linked List ](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/#/description/) | [Recusion](./src/114.Flatten_Binary_Tree_to_Linked_List.cpp) | O(n)   |  O(1) | Medium | Y  |     ||
115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/#/description/) | [DP](./src/115.Distinct_Subsequences.cpp) |  O(m\*n)  | O(m\*n)   | Hard | Y  |     ||
116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/#/description/) | [Recusion](./src/116.Populating_Next_Right_Pointers_in_Each_Node.cpp)  |  O(n) | O(1)  | Medium |  |   ||
117 | [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/#/description/) | [Recusion](./src/117.Populating_Next_Right_Pointers_in_Each_Node_II.cpp) |  O(n) | O(1)  | Medium	 | Y  |    ||
118 | [Pascal's Triangle  ](https://leetcode.com/problems/pascals-triangle-ii/#/description/) | [Math](./src/118.Pascal's_Triangle.cpp) | O(n^2) | O(1) | Easy  |  |    ||
119 | [Pascal's Triangle II ](https://leetcode.com/problems/pascals-triangle-ii/#/description/) | [Math](./src/119.Pascal's_Triangle_II.cpp) | O(n^2)   |  O(1) | Easy | Y  |     ||
120 | [Triangle](https://leetcode.com/problems/triangle/#/description/) | [DP](./src/120.Triangle.cpp) | O(n)   |  O(n) | Medium | Y  |     ||
121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description/) | [Math](./src/121.Best_Time_to_Buy_and_Sell_Stock.cpp) |  O(n)  | O(1)   | Easy |  |     ||
122 | [Best Time to Buy and Sell Stock II  ](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description/) | [Greedy](./src/122.Best_Time_to_Buy_and_Sell_Stock_II.cpp)  |  O(n) | O(1)  | Easy |  |   ||
123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/#/description/) | [DP](./src/123.Best_Time_to_Buy_and_Sell_Stock_III_1.cpp) \| [DP](./src/123.Best_Time_to_Buy_and_Sell_Stock_III_2.cpp) |  O(n) | O(n)  | Hard	 | Y  |    ||
124 | [Binary Tree Maximum Path Sum ](https://leetcode.com/problems/binary-tree-maximum-path-sum/#/description/) | [Recusion](./src/124.Binary_Tree_Maximum_Path_Sum.cpp) | O(n) | O(n) | Hard  | Y |    ||
125 | [Valid Palindrome  ](https://leetcode.com/problems/valid-palindrome/#/description/) | [String](./src/125.Valid_Palindrome.cpp) | O(n)   |  O(1) | Easy |   |     ||
126 | [Word Ladder II ](https://leetcode.com/problems/word-ladder-ii/#/description/) | [BFS](./src/126.Word_Ladder_II.cpp	) |  O(exp)  | O(n)   | Hard | Y |     ||
127 | [Word Ladder ](https://leetcode.com/problems/word-ladder/#/description/) | [BFS](./src/127.Word_Ladder.cpp)  |  O(n) | O(n)  | Medium | Y |   ||
128 | [Longest Consecutive Sequence ](https://leetcode.com/problems/longest-consecutive-sequence/#/description/) | [Hash Table](./src/128.Longest_Consecutive_Sequence.cpp)  |  O(n) | O(n)  | Hard	 | Y  |    ||
129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/#/description/) | [DFS](./src/129.Sum_Root_to_Leaf_Numbers.cpp) | O(n) | O(n) | Medium  |  |    ||
130 | [Surrounded Regions ](https://leetcode.com/problems/surrounded-regions/#/description/) | [DFS](./src/130.Surrounded_Regions.cpp) |  O(m\*n)   |  O(1) | Medium |  Y |     ||
131 | [Palindrome Partitioning ](https://leetcode.com/problems/palindrome-partitioning/#/description/) | [DFS](./src/131.Palindrome_Partitioning.cpp	) |   O(n^2)  | O(n)   | Medium |  |     ||
132 | [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/#/description/) | [DP](./src/132.Palindrome_Partitioning_II.cpp)  |  O(n^2) | O(n^2)  |  | |   ||
133 | [Clone Graph ](https://leetcode.com/problems/clone-graph/#/description/) | [BFS, Hash Table](./src/133.Clone_Graph.cpp)  |  O(n) | O(n)  | Medium | Y  |    ||
134 | [Gas Station ](https://leetcode.com/problems/gas-station/#/description/) | [Greedy](./src/134.Gas_Station.cpp) | O(n) | O(n) | Hard  |  |    ||
135 | [Candy](https://leetcode.com/problems/candy/#/description/) | [Greedy](./src/135.Candy.cpp) | O(n) | O(n) | Hard  |  |    ||
136 | [Single Number  ](https://leetcode.com/problems/single-number/#/description/) | [Bit Manipulation](./src/136.Single_Number.cpp) |  O(n)   |  O(1) | Easy |   |     ||
137 | [Single Number II ](https://leetcode.com/problems/single-number-ii/#/description/) | [Bit Manipulation](./src/137.Single_Number_II.cpp) |   O(n)  | O(1)   | Medium |  |     ||
138 | [Copy List with Random Pointer ](https://leetcode.com/problems/copy-list-with-random-pointer/#/description/) | [Hash Table](./src/138.Copy_List_with_Random_Pointer.cpp)  |  O(n) | O(n)  |Medium  | |   ||
139 | [Word Break ](https://leetcode.com/problems/word-break/#/description/) | [DP](./src/139.Word_Break.cpp)  |  O(n) | O(n)  | Medium | Y  |    ||
140 | [Word Break II ](https://leetcode.com/problems/word-break-ii/#/description/) | [DP](./src/134.Gas_Station.cpp) | O(2^n) | O(n) | Hard  | Y |    ||
141 | [Linked List Cycle ](https://leetcode.com/problems/linked-list-cycle/#/description/) | [Two Pointers](./src/141.Linked_List_Cycle.cpp) |  O(n)   |  O(1) | Easy |   |     ||
142 | [Linked List Cycle II ](https://leetcode.com/problems/linked-list-cycle-ii/#/description/) | [Two Pointers](./src/142.Linked_List_Cycle_II.cpp) |   O(n)  | O(1)   | Medium |  |     ||
143 | [Reorder List  ](https://leetcode.com/problems/reorder-list/#/description/) | [Two Pointers](./src/143.Reorder_List.cpp)  |  O(n) | O(1)  |Medium  | |   ||
144 | [Binary Tree Preorder Traversal ](https://leetcode.com/problems/binary-tree-preorder-traversal/#/description/) | [Stack](./src/144.Binary_Tree_Preorder_Traversal.cpp)  |  O(n) | O(n)  | Medium |   |    ||
145 | [Binary Tree Postorder Traversal  ](https://leetcode.com/problems/binary-tree-postorder-traversal/#/description/) | [Stack](./src/145.Binary_Tree_Postorder_Traversal.cpp) | O(n) | O(n) | Hard  | Y |    ||
146 | [LRU Cache](https://leetcode.com/problems/lru-cache/#/description/) | [List, Hash Table](./src/146.LRU_Cache.cpp) |  O(1)   |  O(n) | Hard |  Y |     ||
147 | [Insertion Sort List  ](https://leetcode.com/problems/insertion-sort-list/#/description/) | [Sort](./src/147.Insertion_Sort_List.cpp) |   O(n^2)  | O(1)   | Medium |  |     ||
148 | [Sort List](https://leetcode.com/problems/sort-list/#/description/) | [Merge Sort](./src/148.Sort_List.cpp) |   O(nlogn)  | O(1)   | Medium |  |     ||
149 | [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/#/description/) | [Hash Table](./src/149.Max_Points_on_a_Line.cpp)  |  O(n^2) | O(n)  |Hard  | Y| gcd ||
150 | [Evaluate Reverse Polish Notation ](https://leetcode.com/problems/evaluate-reverse-polish-notation/#/description/) | [Stack](./src/150.Evaluate_Reverse_Polish_Notation.cpp)  |  O(n) | O(n)  | Medium |   |    ||
151| [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/#/description/) | [String](./src/151.Reverse_Words_in_a_String.cpp) | O(n) | O(n) | Medium   |  |    ||
152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/#/description/) | [DP](./src/152.Maximum_Product_Subarray.cpp) |  O(n)   |  O(1) | Medium  |  Y |     ||
153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/#/description/) | [Binary Search](./src/153.Find_Minimum_in_Rotated_Sorted_Array.cpp) |   O(logn)  | O(1)   | Medium | Y |     ||
154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/#/description/) | [Binary Search](./src/154.Find_Minimum_in_Rotated_Sorted_Array_II.cpp) |   O(n)  | O(1)   | Hard | Y |     ||
155 | [Min Stack](https://leetcode.com/problems/min-stack/#/description) | [Stack](./src/155.Min_Stack.cpp)  |  O(n) | O(1)  | Easy |   |    ||
156| [Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down/#/description/) | [Iterative](./src/156.Binary_Tree_Upside_Down_1.cpp)  \| [Recursive](./src/156.Binary_Tree_Upside_Down_2.cpp) | O(n) | O(1) | Medium   | |    ||
157 | [Read N Characters Given Read4](https://leetcode.com/problems/read-n-characters-given-read4/#/description) | [String](./src/157.Read_N_Characters_Given_Read4.cpp) |  O(n)   |  O(1) | Easy  |   |     ||
158 | [Read N Characters Given Read4 II - Call multiple times](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/#/description) | [String](./src/158.Read_N_Characters_Given_Read4_II_Call_multiple_times.cpp) |   O(n)  | O(1)   | Hard | Y |     ||
159 | [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/#/description/) | [Hash Table](./src/159.Longest_Substring_with_At_Most_Two_Distinct_Characters.cpp) |   O(n)  | O(1)   | Hard |  |     ||
160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/#/description/) | [Two Pointers](./src/160.Intersection_of_Two_Linked_Lists.cpp) |   O(n)  | O(1)   | Easy |  |     ||
161 | [One Edit Distance](https://leetcode.com/problems/one-edit-distance/#/description) | [String](./src/161.One_Edit_Distance.cpp)  |  O(n) | O(1)  | Medium |   |    ||
162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element/#/description/) | [Binary Search](./src/162.Find_Peak_Element.cpp)  | O(logn) | O(1) | Medium   |Y |    ||
163 | [Missing Ranges](https://leetcode.com/problems/missing-ranges/#/description) | [Array](./src/163.Missing_Ranges.cpp) |  O(n)   |  O(1) | Medium   |   |     ||
164 | [Maximum Gap](https://leetcode.com/problems/maximum-gap/#/description) | [Bucket Sort](./src/164.Maximum_Gap.cpp) |   O(n)  | O(n)   | Hard | Y |     ||
165 | [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/#/description/) | [String](./src/165.Compare_Version_Numbers.cpp) |   O(n)  | O(1)   | Medium |  | replace    ||
166 | [Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/#/description/) | [Hash Table](./src/166.Fraction_to_Recurring_Decimal.cpp) |   O(n)  | O(1)   | Medium|  |     ||
167 | [Two Sum II - Input array is sorted ](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/#/description) | [Two Pointer](./src/167.Two_Sum_II_Input_array_is_sorted.cpp)  |  O(n) | O(1)  | Easy |   |    ||
168 | [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/#/description/) | [Math](./src/168.Excel_Sheet_Column_Title.cpp)  | O(logn) | O(1) | Easy   | |    ||
169 | [Majority Element](https://leetcode.com/problems/majority-element/#/description) | [Math](./src/169.Majority_Element.cpp) |  O(n)   |  O(1) | Easy  |   |     ||
170 | [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/#/description) | [Hash Table](./src/170.Two_Sum_III_Data_structure_design.cpp) |   O(n)  | O(n)   | Easy |  |     ||
171 | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/#/description/) | [Math](./src/171.Excel_Sheet_Column_Number.cpp) |   O(n)  | O(1)   | Easy |  |     ||
172 | [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/#/description/) | [Math](./src/172.Factorial_Trailing_Zeroes.cpp) |   O(logn)  | O(1)   | Easy|  |     ||
173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/#/description) | [Stack](./src/173.Binary_Search_Tree_Iterator.cpp)  |  O(n) | O(n)  | Medium | Y  |    ||
174 | [Dungeon Game](https://leetcode.com/problems/dungeon-game/#/description/) | [DP](./src/174.Dungeon_Game.cpp)  | O(m\*n) | O(m\*n) | Hard | |    ||
179 | [Largest Number](https://leetcode.com/problems/largest-number/#/description) | [Sort](./src/179.Largest_Number.cpp) |  O(nlogn)   |  O(1) | Medium |   |  comparator   ||
186 | [Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/#/description) | [String](./src/186.Reverse_Words_in_a_String_II.cpp) |   O(n)  | O(1)   | Medium |  |     ||
187 | [Repeated DNA Sequences ](https://leetcode.com/problems/repeated-dna-sequences/#/description/) | [Hash Table](./src/187.Repeated_DNA_Sequences.cpp) |   O(n)  | O(n)   | Medium |  |     ||
188 | [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/#/description/) | [DP](./src/188.Best_Time_to_Buy_and_Sell_Stock_IV.cpp) |   O(n)  | O(n)   | Hard| Y |     ||
189 | [Rotate Array](https://leetcode.com/problems/rotate-array/#/description) | [String](./src/189.Rotate_Array.cpp)  |  O(n) | O(1)  | Easy |   |    ||
190 | [Reverse Bits ](https://leetcode.com/problems/reverse-bits/#/description) | [Bit Manipulation](./src/190.Reverse_Bits.cpp)  | O(1) | O(1) | Easy | |    ||
191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/#/description) | [Bit Manipulation](./src/191.Number_of_1_Bits.cpp) |  O(1)   |  O(1) | Easy |   |     ||
198 | [House Robber](https://leetcode.com/problems/house-robber/#/description) | [DP](./src/198.House_Robber.cpp) |   O(n)  | O(n)   | Easy |  |     ||
199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/#/description/) | [Recursion](./src/199.Binary_Tree_Right_Side_View.cpp) |   O(n)  | O(1)   | Medium |  |     ||
200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/#/description/) | [DFS](./src/200.Number_of_Islands_1.cpp) \| [BFS](./src/200.Number_of_Islands_2.cpp) |   O(n)  | O(n)   | Medium | Y |  visited   ||
201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/#/description) | [Bit Manipulation](./src/201.Bitwise_AND_of_Numbers_Range.cpp)  |  O(1) | O(1)  | Medium  |   |    ||
202 | [Happy Number](https://leetcode.com/problems/happy-number/#/description) | [Math](./src/202.Happy_Number.cpp)  | O(n) | O(1) | Easy | |    ||
203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/#/description) | [Linked List](./src/203.Remove_Linked_List_Elements.cpp) |  O(n)   |  O(1) | Easy |   |     ||
204 | [Count Primes](https://leetcode.com/problems/count-primes/#/description) | [Math](./src/204.Count_Primes.cpp) |   O(n)  | O(n)   | Easy | Y |     ||
205 | [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/#/description) | [Hash Table](./src/205.Isomorphic_Strings.cpp) |   O(n)  | O(n)   | Easy |  |     ||
206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/#/description/) | [Linked List](./src/206.Reverse_Linked_List.cpp)|   O(n)  | O(1)   | Easy |  |    ||
207 | [Course Schedule ](https://leetcode.com/problems/course-schedule/#/description) | [Topological Sort](./src/207.Course_Schedule.cpp	)  |  O(n) | O(n)  | Medium  |   |    ||
208 | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/#/description) | [Trie](./src/208.Implement_Trie_Prefix_Tree.cpp	)  | O(1) | O(1) | Medium |Y |   ||
209 | [Minimum Size Subarray Sum ](https://leetcode.com/problems/minimum-size-subarray-sum/#/description) | [Two Pointers](./src/209.Minimum_Size_Subarray_Sum.cpp) |  O(n)   |  O(1) | Medium |   |     ||
210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/#/description) | [Topological Sort](./src/210.Course_Schedule_II.cpp) |   O(n)  | O(n)   | Medium | Y |     ||
211 | [Add and Search Word - Data structure design](https://leetcode.com/problems/add-and-search-word-data-structure-design/#/description) | [Trie + BT](./src/211.Add_and_Search_Word_Data_structure_design.cpp) |   O(n)  | O(n)   | Medium |  |      ||
212 | [Word Search II](https://leetcode.com/problems/word-search-ii/#/description) | [DFS](./src/212.Word_Search_II.cpp	)  |  O(n!) | O(1)  | Hard | Y  |  !  ||
213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/#/description) | [DP](./src/213.House_Robber_II.cpp	)  | O(n) | O(n) | Medium ||   ||
214 | [Shortest Palindrome ](https://leetcode.com/problems/shortest-palindrome/#/description) | [String](./src/214.Shortest_Palindrome.cpp) |  O(n)   |  O(1) | Hard |   |     ||
215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/#/description) | [Quick Select](./src/215.Kth_Largest_Element_in_an_Array.cpp) |   O(n)  | O(1)   | Medium | Y |     ||
216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/#/description) | [Recursion](./src/216.Combination_Sum_III.cpp) |   O(n!)  | O(n)   | Medium | Y |      ||
217 | [Contains Duplicate ](https://leetcode.com/problems/contains-duplicate/#/description) | [Hash Table](./src/217.Contains_Duplicate.cpp) |   O(n)  | O(n)   | Easy |  |     ||
218 | [The Skyline Problem ](https://leetcode.com/problems/the-skyline-problem/#/description) | [Heap](./src/218.The_Skyline_Problem.cpp) |   O(nlogn)  | O(n)   | Hard| Y |      ||
219 | [Contains Duplicate II ](https://leetcode.com/problems/contains-duplicate-ii/#/description) | [Hash Table](./src/219.Contains_Duplicate_II.cpp	)  |  O(n) | O(n)  | Easy |  |    ||
220 | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/#/description) | [Hash Table](./src/220.Contains_Duplicate_III.cpp	)  | O(n) | O(n) | Medium ||   ||
221 | [Maximal Square ](https://leetcode.com/problems/maximal-square/#/description) | [DP](./src/221.Maximal_Square.cpp) |  O(n^2)   |  O(n^2) | Medium  |   |     ||
222 | [Count Complete Tree Nodes ](https://leetcode.com/problems/count-complete-tree-nodes/#/description) | [Recursion](./src/222.Count_Complete_Tree_Nodes.cpp) |   O(n)  | O(1)   | Medium | Y |     ||
223 | [Rectangle Area ](https://leetcode.com/problems/rectangle-area/#/description) | [Math](./src/223.Rectangle_Area.cpp) |   O(1)  | O(1)   | Medium |  |      ||
224 | [Basic Calculator](https://leetcode.com/problems/basic-calculator/#/description) | [Stack](./src/224.Basic_Calculator.cpp) |   O(n)  | O(1)   | Hard | Y |     ||
225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/#/description) | [Queue](./src/225.Implement_Stack_using_Queues.cpp) |   O(n)  | O(n)   | Easy|  |      ||
226 | [Invert Binary Tree ](https://leetcode.com/problems/invert-binary-tree/#/description) | [Tree](./src/226.Invert_Binary_Tree.cpp	)  |  O(n) | O(1)  | Easy |  |    ||
227 | [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/#/description) | [Stack](./src/227.Basic_Calculator_II.cpp)  | O(n) | O(1) | Medium ||   ||
228 | [Summary Ranges ](https://leetcode.com/problems/summary-ranges/#/description) | [Array](./src/228.Summary_Ranges.cpp) |  O(n)   |  O(n) | Medium  |   |     ||
229 | [Majority Element II ](https://leetcode.com/problems/majority-element-ii/#/description) | [Math](./src/229.Majority_Element_II.cpp) |   O(n)  | O(1)   | Medium |  |     ||
230 | [Kth Smallest Element in a BST ](https://leetcode.com/problems/kth-smallest-element-in-a-bst/#/description) | [Tree](./src/230.Kth_Smallest_Element_in_a_BST.cpp) |   O(n)  | O(1)   | Medium |  |      ||
231 | [Power of Two](https://leetcode.com/problems/power-of-two/#/description) | [Bit Manipulation](./src/231.Power_of_Two.cpp ) |   O(1)  | O(1)   | Easy |  |     ||
232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/#/description) | [Stack](./src/232.Implement_Queue_using_Stacks.cpp) |   O(1)  | O(1)   | Easy|  |      ||
233 | [Number of Digit One](https://leetcode.com/problems/number-of-digit-one/#/description) | [Recursion](./src/233.Number_of_Digit_One.cpp  )  |  O(n) | O(1)  | Hard |  |    ||
234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/#/description) | [Linked List](./src/234.Palindrome_Linked_List.cpp  )  | O(n) | O(1) | Easy ||   ||
235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/#/description) | [Tree](./src/235.Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp) |  O(n)   |  O(1) | Easy |   |     ||
236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/#/description) | [Tree](./src/236.Lowest_Common_Ancestor_of_a_Binary_Tree.cpp) |   O(n)  | O(1)   | Medium | Y |     ||
237 | [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/#/description) | [Linked List](./src/237.Delete_Node_in_a_Linked_List.cpp) |   O(1)  | O(1)   | Easy |  |      ||
238 | [Product of Array Except Self ](https://leetcode.com/problems/product-of-array-except-self/#/description) | [DP](./src/238.Product_of_Array_Except_Self.cpp ) |   O(n)  | O(n)   | Medium |  |     ||
239 | [Sliding Window Maximum ](https://leetcode.com/problems/sliding-window-maximum/#/description) | [Queue](./src/239.Sliding_Window_Maximum.cpp) |   O(n)  | O(n)   | Hard| Y |      ||
240 | [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/#/description) | [Search](./src/240.Search_a_2D_Matrix_II.cpp	)  |  O(n) | O(1)  | Medium |  |    ||
241 | [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/#/description) | [Recursion](./src/241.Different_Ways_to_Add_Parentheses.cpp)  | O(n^2) | O(1) | Medium |Y |  ||
242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/#/description) | [Hash Table ](./src/242.Valid_Anagram.cpp ) |  O(n)   |  O(1) | Medium |   |     ||
243 | [Shortest Word Distance ](https://leetcode.com/problems/shortest-word-distance/#/description) | [Two Pointers](./src/243.Shortest_Word_Distance.cpp) |   O(n)  | O(1)   | Medium |  |     ||
244 | [Shortest Word Distance II ](https://leetcode.com/problems/shortest-word-distance-ii/#/description) | [Hash Table](./src/244.Shortest_Word_Distance_II.cpp) |   O(n)  | O(n)   | Medium |  |      ||
245 | [Shortest Word Distance III ](https://leetcode.com/problems/shortest-word-distance-iii/#/description) | [Array](./src/245.Shortest_Word_Distance_III.cpp) |   O(n)  | O(1)   | Medium |  |     ||
246 | [Strobogrammatic Number ](https://leetcode.com/problems/strobogrammatic-number/#/description) | [Hash Table](./src/246.Strobogrammatic_Number.cpp ) |   O(n)  | O(1)   | Easy|  |      ||
247 | [Strobogrammatic Number II](https://leetcode.com/problems/strobogrammatic-number-ii/#/description) | [Recursion](./src/247.Strobogrammatic_Number_II.cpp)  |  O(n!) | O(1)  | Medium | Y  |    ||
248 | [Strobogrammatic Number III](https://leetcode.com/problems/strobogrammatic-number-iii/#/description) | [Recursion](./src/248.Strobogrammatic_Number_III.cpp)  | O(n!) | O(1) | Hard | |  ||
249 | [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/#/description) | [Hash Table ](./src/249.Group_Shifted_Strings.cpp) |  O(n)   |  O(n) | Medium |   |     ||
250 | [Count Univalue Subtrees ](https://leetcode.com/problems/count-univalue-subtrees/#/description) | [Recursion](./src/250.Count_Univalue_Subtrees.cpp) |   O(n)  | O(1)   | Medium |  |     ||
251 | [Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/#/description) | [Math](./src/251.Flatten_2D_Vector.cpp) |   O(1)  | O(1)   | Medium |  |      ||
252 | [Meeting Rooms ](https://leetcode.com/problems/meeting-rooms/#/description) | [Sort](./src/252.Meeting_Rooms.cpp) |   O(nlogn)  | O(1)   | Easy |  |     ||
253 | [Meeting Rooms II ](https://leetcode.com/problems/meeting-rooms-ii/#/description) | [Greedy + Sort](./src/253.Meeting_Rooms_II.cpp) |   O(nlogn)  | O(n)   | Medium | Y |      ||
254 | [Factor Combinations](https://leetcode.com/problems/factor-combinations/#/description) | [BackTracking](./src/254.Factor_Combinations.cpp)  |  O(n!) | O(1)  | Medium | Y  |    ||
255 | [Verify Preorder Sequence in Binary Search Tree ](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/#/description) | [Stack](./src/255.Verify_Preorder_Sequence_in_Binary_Search_Tree.cpp)  | O(n!) | O(n) | Medium  | |  ||
256 | [Paint House](https://leetcode.com/problems/paint-house/#/description) | [DP ](./src/256.Paint_House.cpp) |  O(n)   |  O(n) | Easy|   |     ||
257 | [Binary Tree Paths ](https://leetcode.com/problems/binary-tree-paths/#/description) | [BackTracking](./src/257.Binary_Tree_Paths.cpp) |   O(n)  | O(1)   | Easy |  |     ||
258 | [Add Digits](https://leetcode.com/problems/add-digits/#/description) | [Math](./src/258.Add_Digits.cpp) |   O(1)  | O(1)   | Easy |  |      ||
259 | [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/#/description) | [Sort](./src/259.3Sum_Smaller.cpp ) |   O(nlogn)  | O(1)   | Medium |  |      ||
260 | [Single Number III](https://leetcode.com/problems/single-number-iii/#/description) | [Bit Manipulation](./src/260.Single_Number_III.cpp) |   O(n)  | O(1)   | Medium |  |     ||
261 | [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/#/description) | [DFS](./src/261.Graph_Valid_Tree.cpp ) |   O(n)  | O(n)   | Medium | Y |   find cycle   ||
263 | [Ugly Number ](https://leetcode.com/problems/ugly-number/#/description) | [Math](./src/263.Ugly_Number.cpp)  |  O(1) | O(1)  | Easy |  |    ||
264 | [Ugly Number II ](https://leetcode.com/problems/ugly-number-ii/#/description) | [Math](./src/264.Ugly_Number_II.cpp)  | O(n) | O(1) | Medium  | |  ||
265 | [Paint House II](https://leetcode.com/problems/paint-house-ii/#/description) | [DP](./src/265.Paint_House_II.cpp) |  O(n)   |  O(n) | Hard|   |   ||
266 | [Palindrome Permutation ](https://leetcode.com/problems/palindrome-permutation/#/description) | [Hash Table](./src/266.Palindrome_Permutation.cpp) |   O(n)  | O(n)   | Easy |  |     ||
267 | [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/#/description) | [Back Tracking](./src/267.Palindrome_Permutation_II.cpp) |   O(n!)  | O(1)   | Medium | Y |      ||
268 | [Missing Number ](https://leetcode.com/problems/missing-number/#/description) | [Math](./src/268.Missing_Number.cpp ) |   O(n)  | O(1)   | Easy| |     ||
269 | [Alien Dictionary ](https://leetcode.com/problems/alien-dictionary/#/description)| [Topological Sort](./src/269.Alien_Dictionary.cpp )  |  O(n) | O(n)  | Hard | Y  |    ||
270 | [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/#/description)| [Tree](./src/270.Closest_Binary_Search_Tree_Value.cpp)  | O(n) | O(n) | Easy  | |  ||
271 | [Encode and Decode Strings ](https://leetcode.com/problems/encode-and-decode-strings/#/description)| [String](./src/271.Encode_and_Decode_Strings.cpp) |  O(n)   |  O(1) | Medium|   |   ||
272 | [Closest Binary Search Tree Value II ](https://leetcode.com/problems/closest-binary-search-tree-value-ii/#/description) | [Tree](./src/272.Closest_Binary_Search_Tree_Value_II.cpp) |   O(n)  | O(1)   | Hard|  |     ||
273 | [Integer to English Words ](https://leetcode.com/problems/integer-to-english-words/#/description)| [String](./src/273.Integer_to_English_Words.cpp) |   O(n)  | O(1)   | Hard |  |      ||
274 | [H-Index](https://leetcode.com/problems/h-index/#/description)| [Sort](./src/274.H-Index.cpp) |   O(nlogn)  | O(1)   | Medium |  |      ||
275 | [H-Index II](https://leetcode.com/problems/h-index-ii/#/description) | [Binary Search](./src/275.H-Index_II.cpp  ) |   O(logn)  | O(1)   | Medium| |     ||
276 | [Paint Fence](https://leetcode.com/problems/paint-fence/#/description)| [DP](./src/276.Paint_Fence.cpp )  |  O(n) | O(1)  | Easy |  |    ||
277 | [Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/#/description)| [Array](./src/277.Find_the_Celebrity.cpp)  | O(n) | O(1) | Medium  | |  ||
278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/#/description)| [Binary Search](./src/278.First_Bad_Version.cpp) |  O(logn)   |  O(1) | Easy| Y |   ||
279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares/#/description) | [DP](./src/279.Perfect_Squares.cpp ) |   O(n)  | O(n)   | Medium|  |     ||
280 | [Wiggle Sort ](https://leetcode.com/problems/wiggle-sort/#/description)| [Sort](./src/280.Wiggle_Sort.cpp) |   O(n)  | O(1)   | Medium |  |      ||
281 | [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/#/description)| [Array](./src/281.Zigzag_Iterator.cpp) |   O(1)  | O(1)   | Medium |  |      ||
282 | [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/#/description) | [Divide n Conquer ](./src/282.Expression_Add_Operators.cpp ) |   O(n!)  | O(1)   | Hard| |     ||
283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/#/description)| [Two Pointers](./src/283.Move_Zeroes.cpp  )  |  O(n) | O(1)  | Easy |  |    ||
284 | [Peeking Iterator](https://leetcode.com/problems/peeking-iterator/#/description)| [Design1](./src/284.Peeking_Iterator_1.cpp) \|[Design2](./src/284.Peeking_Iterator_2.cpp) | O(1) | O(1) | Medium  | |  ||
285 | [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/#/description)| [Tree](./src/285.Inorder_Successor_in_BST.cpp ) |  O(n)   |  O(1) | Easy| Y |   ||
286 | [Walls and Gates](https://leetcode.com/problems/walls-and-gates/#/description) | [BFS](./src/286.Walls_and_Gates.cpp  ) |   O(n)  | O(n)   | Medium| Y  |    ||
287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/#/description)| [Binary Search](./src/287.Find_the_Duplicate_Number.cpp) |   O(logn)  | O(1)   | Medium |  |      ||
288 | [Unique Word Abbreviation ](https://leetcode.com/problems/unique-word-abbreviation/#/description)| [Hash Table](./src/288.Unique_Word_Abbreviation.cpp) |   O(n)  | O(n)   | Medium |  |      ||
289 | [Game of Life ](https://leetcode.com/problems/game-of-life/#/description) | [DFS](./src/289.Game_of_Life.cpp) |   O(n!)  | O(1)   | Medium| |     ||
290 | [Word Pattern ](https://leetcode.com/problems/word-pattern/#/description)| [Hash Table](./src/290.Word_Pattern.cpp)  |  O(n) | O(n)  | Easy |  |    ||
291 | [Word Pattern II](https://leetcode.com/problems/word-pattern-ii/#/description)| [BackTracking](./src/291.Word_Pattern_II.cpp) |O(n!) | O(n) | Hard |Y |  ||
292 | [Nim Game](https://leetcode.com/problems/nim-game/#/description)| [Math](./src/292.Nim_Game.cpp) |  O(1)   |  O(1) | Easy|  |   ||
293 | [Flip Game](https://leetcode.com/problems/flip-game/#/description) | [String](./src/293.Flip_Game.cpp ) |   O(n)  | O(1)   | Easy|   |    ||
294 | [Flip Game II](https://leetcode.com/problems/flip-game-ii/#/description)| [BackTracking](./src/294.Flip_Game_II.cpp) |   O(n!)  | O(n)   | Medium |  |      ||
295 | [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/#/description)| [Heap](./src/295.Find_Median_from_Data_Stream.cpp) |   O(1)  | O(n)   | Hard| Y |      ||
296 | [Best Meeting Point ](https://leetcode.com/problems/best-meeting-point/#/description) | [Sort](./src/296.Best_Meeting_Point.cpp) |   O(nlogn)  | O(1)   | Hard| |     ||
297 | [Serialize and Deserialize Binary Tree ](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/#/description)| [BackTracking](./src/297.Serialize_and_Deserialize_Binary_Tree.cpp)  |  O(n) | O(1)  | Hard | Y |  n-ary  ||
298 | [Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/#/description)| [BackTracking](./src/298.Binary_Tree_Longest_Consecutive_Sequence.cpp) |O(n) | O(1) | Medium | |  ||
299 | [Bulls and Cows ](https://leetcode.com/problems/bulls-and-cows/#/description)| [Hash Table](./src/299.Bulls_and_Cows.cpp ) |  O(n)   |  O(1) | Medium|  |   ||
300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/#/description) | [DP](./src/300.Longest_Increasing_Subsequence.cpp) |   O(n)  | O(n)   | Medium|   |    ||
301 | [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/#/description)| [BFS](./src/301.Remove_Invalid_Parentheses.cpp ) |   O(n)  | O(n)   | Hard |  |  Y    ||
302 | [Smallest Rectangle Enclosing Black Pixels](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/#/description)| [Binary Search](./src/302.Smallest_Rectangle_Enclosing_Black_Pixels.cpp) |   O(logn)  | O(1)   | Hard| Y |      ||
303 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/#/description) | [DP](./src/303.Range_Sum_Query_Immutable.cpp) |   O(n)  | O(n)   | Easy| |     ||
304 | [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/#/description)| [DP](./src/304.Range_Sum_Query_2D_Immutable.cpp)  |  O(m\*n) | O(m\*n)  | Medium |  |    ||
305 | [Number of Islands II](https://leetcode.com/problems/number-of-islands-ii/#/description)| [Union Find](./src/305.Number_of_Islands_II.cpp) |O(n) | O(m\*n) | Hard | Y|  ||
306 | [Additive Number](https://leetcode.com/problems/additive-number/#/description)| [BackTracking](./src/306.Additive_Number.cpp	) |  O(n!)   |  O(1) | Medium|  |   ||
307 | [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/#/description) | [BIT](./src/307.Range_Sum_Query_Mutable_bit.cpp) \|[Segment Tree](./src/307.Range_Sum_Query_Mutable_ST.cpp) |   O(n)  | O(n)   | Medium| Y  |    ||
308 | [Range Sum Query 2D - Mutable ](https://leetcode.com/problems/range-sum-query-2d-mutable/#/description)| [BIT](./src/308.Range_Sum_Query_2D_Mutable_BIT.cpp) \|[Segment Tree](./src/308.Range_Sum_Query_2D_Mutable_ST.cpp) |   O(m\*n) | O(m\*n)   | Hard |  |     ||
309 | [Best Time to Buy and Sell Stock with Cooldown ](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/#/description)| [DP](./src/309.Best_Time_to_Buy_and_Sell_Stock_with_Cooldown.cpp) |   O(n)  | O(n)   | Medium| Y |      ||
310 | [Minimum Height Trees ](https://leetcode.com/problems/minimum-height-trees/#/description)| [Topological Sort](./src/310.Minimum_Height_Trees.cpp) |   O(n)  | O(n)   | Medium	| |      ||
311 | [Sparse Matrix Multiplication](https://leetcode.com/problems/sparse-matrix-multiplication/#/description) | [Hash Table](./src/311.Sparse_Matrix_Multiplication.cpp) |   O(m\*n)  | O(m\*n)   | Medium	|Y |     ||
312 | [Burst Balloons ](https://leetcode.com/problems/burst-balloons/#/description)| [DP](./src/312.Burst_Balloons.cpp)  |  O(n^2) | O(n^2)  | Hard|  |    ||
313 | [Super Ugly Number](https://leetcode.com/problems/super-ugly-number/#/description)| [Math](./src/313.Super_Ugly_Number.cpp) |O(n) | O(m\*n) | Medium	 | Y|  ||
314 | [Binary Tree Vertical Order Traversal ](https://leetcode.com/problems/binary-tree-vertical-order-traversal/#/description)| [BFS](./src/314.Binary_Tree_Vertical_Order_Traversal.cpp	) |  O(n)   |  O(n) | Medium| Y |   ||
315 | [Count of Smaller Numbers After Self ](https://leetcode.com/problems/count-of-smaller-numbers-after-self/#/description) | [Binary Search](./src/315.Count_of_Smaller_Numbers_After_Self.cpp) |   O(nlogn)  | O(n)   | Hard|   |    ||
316 | [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/#/description)| [Greedy](./src/316.Remove_Duplicate_Letters.cpp)|   O(n) | O(1)   | Hard |  |     ||
317 | [Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/#/description)| [BFS](./src/317.Shortest_Distance_from_All_Buildings.cpp) |   O(n)  | O(n)   | Hard|  |      ||
318 | [Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/#/description) | [Bit Manipulation](./src/318.Maximum_Product_of_Word_Lengths.cpp) |   O(m\*n)  | O(n)   | Medium	| |     ||
319 | [Bulb Switcher]( https://leetcode.com/problems/bulb-switcher/#/description)| [Math](./src/319.Bulb_Switcher.cpp)  |  O(1) | O(1)  | Medium	|  |    ||
320 | [Generalized Abbreviation]( https://leetcode.com/problems/generalized-abbreviation/#/description)| [BackTracking](./src/320.Generalized_Abbreviation.cpp) |O(2^n) | O(1) | Medium	 | Y|  ||
321 | [Create Maximum Number]( https://leetcode.com/problems/create-maximum-number/#/description)| [Greedy](./src/321.Create_Maximum_Number.cpp) |  O(n!)   |  O(1) | Hard| |   ||
322 | [Coin Change ]( https://leetcode.com/problems/coin-change/#/description) | [DP](./src/322.Coin_Change.cpp) |   O(n)  | O(n)   | Medium	|   |    ||
323 | [Number of Connected Components in an Undirected Graph]( https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/#/description)| [Union Find](./src/323.Number_of_Connected_Components_in_an_Undirected_Graph.cpp)|   O(n) | O(n)   | Medium	 | Y |     ||
324 | [Wiggle Sort II ]( https://leetcode.com/problems/wiggle-sort-ii/#/description)| [Sort](./src/324.Wiggle_Sort_II.cpp) |   O(nlog)  | O(n)   | Medium	|  |      ||
325 | [Maximum Size Subarray Sum Equals k]( https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/#/description) | [Hash Table](./src/325.Maximum_Size_Subarray_Sum_Equals_k.cpp) |   O(n)  | O(n)   | Medium	| Y|     ||
326 | [Power of Three  ]( https://leetcode.com/problems/power-of-three/#/description)| [Math](./src/326.Power_of_Three.cpp)  |  O(1) | O(1)  | Easy	| Y |    ||
327 | [Count of Range Sum]( https://leetcode.com/problems/count-of-range-sum/#/description)| [Hash Table](./src/327.Count_of_Range_Sum.cpp) |O(n) | O(n) | Hard	 | |  ||
328 | [Odd Even Linked List]( https://leetcode.com/problems/odd-even-linked-list/#/description)| [Linked List](./src/328.Odd_Even_Linked_List.cpp) |  O(n)   |  O(1) | Medium| |   ||
329 | [Longest Increasing Path in a Matrix]( https://leetcode.com/problems/longest-increasing-path-in-a-matrix/#/description) | [DFS](./src/329.Longest_Increasing_Path_in_a_Matrix.cpp) |   O(n!)  | O(n^2)   | Hard	|   |    ||
330 | [Patching Array]( https://leetcode.com/problems/patching-array/#/description)| [Greedy](./src/330.Patching_Array.cpp)|   O(n) | O(1)   | Hard	 |  |     ||
331 | [Verify Preorder Serialization of a Binary Tree]( https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/#/description)| [Sort](./src/331.Verify_Preorder_Serialization_of_a_Binary_Tree.cpp) |   O(n)  | O(1)   | Medium	|  |      ||
332 | [Reconstruct Itinerary]( https://leetcode.com/problems/reconstruct-itinerary/#/description) | [DFS](./src/332.Reconstruct_Itinerary.cpp) |   O(n!) | O(n)   | Medium	| Y|     ||
333 | [Largest BST Subtree]( https://leetcode.com/problems/largest-bst-subtree/#/description)| [DFS](./src/333.Largest_BST_Subtree.cpp)  |  O(n) | O(1)  | Medium	|  |    ||
334 | [Increasing Triplet Subsequence]( https://leetcode.com/problems/increasing-triplet-subsequence/#/description)| [Array](./src/334.Increasing_Triplet_Subsequence.cpp) |O(n) | O(1) | Medium	 | |  ||
335 | [Self Crossing]( https://leetcode.com/problems/self-crossing/#/description)| [Math](./src/335.Self_Crossing.cpp) |  O(n)   |  O(1) | Hard| |   ||
336 | [Palindrome Pairs]( https://leetcode.com/problems/palindrome-pairs/#/description) | [Hash Table](./src/336.Palindrome_Pairs.cpp) |   O(m\*n) | O(m)   | Hard	|   |    ||
337 | [House Robber III]( https://leetcode.com/problems/house-robber-iii/#/description)| [DFS](./src/337.House_Robber_III.cpp)|   O(n) | O(1)   | Medium	 |  |     ||
338 | [Counting Bits]( https://leetcode.com/problems/counting-bits/#/description)| [Bit Manipulation](./src/338.Counting_Bits.cpp) |   O(n)  | O(1)   | Medium	|  |      ||
339 | [Nested List Weight Sum]( https://leetcode.com/problems/nested-list-weight-sum/#/description) | [DFS](./src/339.Nested_List_Weight_Sum.cpp) |   O(2^n)| O(1)   | Easy	| |     ||
340 | [Longest Substring with At Most K Distinct Characters]( https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/#/description)| [Hash Table](./src/340.Longest_Substring_with_At_Most_K_Distinct_Characters.cpp)  |  O(n) | O(256)  | Hard	|  |    ||
341 | [Flatten Nested List Iterator]( https://leetcode.com/problems/flatten-nested-list-iterator/#/description)| [Stack](./src/341.Flatten_Nested_List_Iterator.cpp) |O(n) | O(n) | Medium	 | Y|  ||
342 | [Power of Four]( https://leetcode.com/problems/power-of-four/#/description)| [Math](./src/342.Power_of_Four.cpp) |  O(1)   |  O(1) | Easy| |   ||
343 | [Integer Break]( https://leetcode.com/problems/integer-break/#/description) | [Math](./src/343.Integer_Break.cpp) |   O(1) | O(1)   | Medium	|   |    ||
344 | [Reverse String]( https://leetcode.com/problems/reverse-string/#/description)| [String](./src/344.Reverse_String.cpp)|   O(n) | O(1)   | Easy	 |  |     ||
345 | [Reverse Vowels of a String]( https://leetcode.com/problems/reverse-vowels-of-a-string/#/description)| [String](./src/345.Reverse_Vowels_of_a_String.cpp) |   O(n)  | O(1)   | Easy	|  |      ||
346 | [Moving Average from Data Stream  ]( https://leetcode.com/problems/moving-average-from-data-stream/#/description) | [Queue](./src/346.Moving_Average_from_Data_Stream.cpp) |   O(1)| O(n)   | Easy	| |     ||
347 | [Top K Frequent Elements ]( https://leetcode.com/problems/top-k-frequent-elements/#/description)| [Heap](./src/347.Top_K_Frequent_Elements.cpp)  |  O(n) | O(n)  | Medium	|  |    ||
348 | [Design Tic-Tac-Toe]( https://leetcode.com/problems/design-tic-tac-toe/#/description)| [Design](./src/348.Design_Tic_Tac_Toe.cpp) |O(1) | O(n) | Medium	 | |  ||
349 | [Intersection of Two Arrays]( https://leetcode.com/problems/intersection-of-two-arrays/#/description)| [Hash Table](./src/349.Intersection_of_Two_Arrays.cpp) |  O(n)   |  O(n) | Easy| |   ||
350 | [Intersection of Two Arrays II ]( https://leetcode.com/problems/intersection-of-two-arrays-ii/#/description) | [Hash Table](./src/350.Intersection_of_Two_Arrays_II.cpp) |   O(n) | O(n)   | Easy	|   |    ||
351 | [Android Unlock Patterns]( https://leetcode.com/problems/android-unlock-patterns/#/description)| [DFS](./src/351.Android_Unlock_Patterns.cpp	)|   O(n!) | O(n)   | Medium	 |  |     ||
352 | [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/#/description)| [Array](./src/352.Data_Stream_as_Disjoint_Intervals.cpp) |   O(n)  | O(n)   | Hard	|  |      ||
353 | [Design Snake Game ]( https://leetcode.com/problems/design-snake-game/#/description) | [Queue](./src/353.Design_Sname_Game.cpp) |   O(n)| O(n)   | Medium	| |     ||
354 | [Russian Doll Envelopes ](https://leetcode.com/problems/russian-doll-envelopes/#/description)| [DP](./src/354.Russian_Doll_Envelopes.cpp)  |  O(n) | O(n)  | Hard	|  |    ||
355 | [Design Twitter](https://leetcode.com/problems/design-twitter/#/description)| [Hash Table + Heap](./src/355.Design_Twitter.cpp) |O(m\*n) | O(n) | Medium	 |Y |  ||
356 | [Line Reflection](https://leetcode.com/problems/line-reflection/#/description)| [Hash Table](./src/356.Line_Reflection.cpp) |  O(n)   |  O(n) | Medium| |   ||
357 | [Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/#/description) | [Math](./src/357.Count_Numbers_with_Unique_Digits.cpp) |   O(n) | O(1)   | Medium	|   |    ||
358 | [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/#/description)| [Greedy](./src/358.Rearrange_String_k_Distance_Apart.cpp)|   O(n!) | O(n)   | Hard	 |  |     ||
359 | [Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/#/description)| [Hash Table](./src/359.Logger_Rate_Limiter.cpp) |   O(1)  | O(n)   | Easy	|Y  |      ||
360 | [Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array/#/description)| [Two Pointers](./src/360.Sort_Transformed_Array.cpp) |   O(n)  | O(1)   | Medium	|  |      ||
361 | [Bomb Enemy]( https://leetcode.com/problems/bomb-enemy/#/description) | [DP](./src/361.Bomb_Enemy.cpp) |   O(m\*n) |O(m\*n)    | Medium	| |     ||
362 | [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/#/description)| [Queue](./src/362.Design_Hit_Counter_1.cpp) \| [Circular Array](./src/362.Design_Hit_Counter_2.cpp)  |  O(n) | O(n)  | Medium	| Y |    ||
363 | [Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/#/description)| [Hash Table](./src/363.Max_Sum_of_Rectangle_No_Larger_Than_K.cpp) |O(col\*col\*row) | O(row) | Hard	 | |  ||
364 | [Nested List Weight Sum II ](https://leetcode.com/problems/nested-list-weight-sum-ii/#/description)| [DFS](./src/364.Nested_List_Weight_Sum_II.cpp) |  O(2^n)   |  O(1) | Medium| |   ||
365 | [Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/#/description) | [Math](./src/365.Water_and_Jug_Problem.cpp) |   O(n) | O(1)   | Medium	|   | gcd    ||
366 | [Find Leaves of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/#/description)| [Tree](./src/366.Find_Leaves_of_Binary_Tree.cpp)|   O(n) | O(1)   | Medium	 |  |     ||
367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/#/description)| [Binary Search](./src/367.Valid_Perfect_Square.cpp) |   O(logn)  | O(1)   | Easy	| |      ||
368 | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/#/description) | [DP](./src/368.Largest_Divisible_Subset.cpp) |   O(ologn) |O(n)    | Medium	| |     ||
369 | [Plus One Linked List](https://leetcode.com/problems/plus-one-linked-list/#/description)| [Recursion](./src/369.Plus_One_Linked_List.cpp) |  O(n) | O(n)  | Medium	| Y |    ||
370 | [Range Addition ](https://leetcode.com/problems/range-addition/#/description)| [Array](./src/370.Range_Addition.cpp) |O(n) | O(1) | Medium		 | |  ||
371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/#/description)| [Bit Manipulation](./src/371.Sum_of_Two_Integers.cpp) |  O(1)   |  O(1) | Easy| |   ||
372 | [Super Pow](https://leetcode.com/problems/super-pow/#/description) | [Math](./src/372.Super_Pow.cpp) |   O(m\*n) | O(1)   | Medium	|   |     ||
373 | [Find K Pairs with Smallest Sums ](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/#/description)| [Heap](./src/373.Find_K_Pairs_with_Smallest_Sums.cpp)|   O(m\*n) | O(m\*n)  | Medium	 |  |     ||
374 | [Guess Number Higher or Lower ](https://leetcode.com/problems/guess-number-higher-or-lower/#/description)| [Binary Search](./src/374.Guess_Number_Higher_or_Lower.cpp) |   O(logn)  | O(1)   | Easy	| |      ||
375 | [Guess Number Higher or Lower II ](https://leetcode.com/problems/guess-number-higher-or-lower-ii/#/description) | [DP](./src/375.Guess_Number_Higher_or_Lower_II.cpp	) |  O(n^3) |O(n^2)   | Medium	| |     ||
376 | [Wiggle Subsequence ](https://leetcode.com/problems/wiggle-subsequence/#/description)| [Greedy](./src/376.Wiggle_Subsequence.cpp) |  O(n) | O(1)  | Medium	|  |    ||
377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/#/description)| [DP](./src/377.Combination_Sum_IV.cpp) |O(n) | O(n) | Medium		 | |  ||
378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/#/description)| [Heap](./src/378.Kth_Smallest_Element_in_a_Sorted_Matrix.cpp) |  O(n)   |  O(n) | Medium| | Y  ||
379 | [Design Phone Directory](https://leetcode.com/problems/design-phone-directory/#/description) | [Hash Table](./src/379.Design_Phone_Directory.cpp) |   O(n) | O(n)   | Medium	|   |     ||
380 | [Insert Delete GetRandom O(1) ](https://leetcode.com/problems/insert-delete-getrandom-o1/#/description)| [Hash Table](./src/380.Insert_Delete_GetRandom_O1.cpp)|   O(1) | O(n)  | Medium	 | Y |     ||
381 | [Insert Delete GetRandom O(1) - Duplicates allowed](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/#/description)| [Hash Table](./src/381.Insert_Delete_GetRandom_O1_Duplicates_allowed.cpp) |   O(1)  | O(n)   | Hard	| |      ||
382 | [Linked List Random Node ](https://leetcode.com/problems/linked-list-random-node/#/description) | [Math](./src/382.Linked_List_Random_Node.cpp) |  O(n) |O(1)  | Medium	|Y | 蓄水池采样    ||
383 | [Ransom Note](https://leetcode.com/problems/ransom-note/#/description)| [Hash Table](./src/383.Ransom_Note.cpp) |  O(n) |  O(n)  | Easy	|  |    ||
384 | [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/#/description)| [Math](./src/384.Shuffle_an_Array.cpp) |O(n) | O(1) | Medium		 | |  ||
385 | [Mini Parser ](https://leetcode.com/problems/mini-parser/#/description)| [Stack](./src/385.Mini_Parser.cpp) |  O(n)   |  O(n) | Medium| | Y  ||
386 | [Lexicographical Numbers ](https://leetcode.com/problems/lexicographical-numbers/#/description) | [String](./src/386.Lexicographical_Numbers.cpp	) |   O(n) | O(1)   | Medium	|   |     ||
387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/#/description)| [Hash Table](./src/387.First_Unique_Character_in_a_String.cpp)|   O(n) | O(256)  | Easy |  |     ||
388 | [Longest Absolute File Path](https://leetcode.com/problems/longest-absolute-file-path/#/description)| [String](./src/388.Longest_Absolute_File_Path.cpp) |   O(n)  | O(n)   |Medium| |      ||
389 | [Find the Difference](https://leetcode.com/problems/find-the-difference/#/description) | [Bit Manipulation](./src/389.Find_the_Difference.cpp) |  O(n) |O(1)  | Easy	| |     ||
390 | [Elimination Game ](https://leetcode.com/problems/elimination-game/#/description)| [Math](./src/390.Elimination_Game.cpp) |  O(n) |  O(1)  | Medium	|  |    ||
391 | [Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/#/description)| [Math](./src/391.Perfect_Rectangle.cpp) |O(n) | O(n) | Hard		 | |  ||
392 | [Is Subsequence  ](https://leetcode.com/problems/is-subsequence/#/description)| [Greedy](./src/392.Is_Subsequence.cpp) |  O(n)   |  O(n) | Medium| |   ||
393 | [UTF-8 Validation](https://leetcode.com/problems/utf-8-validation/#/description) | [Bit Manipulation](./src/393.UTF-8_Validation.cpp) |   O(n) | O(1)   | Medium	|   |     ||
394 | [Decode String ](https://leetcode.com/problems/decode-string/#/description)| [Stack](./src/394.Decode_String.cpp)|   O(n) | O(n)  | Medium |Y  |     ||
395 | [Longest Substring with At Least K Repeating Characters ](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/#/description)| [BackTracking](./src/395.Longest_Substring_with_At_Least_K_Repeating_Characters.cpp) |   O(2^n)  | O(1)   |Medium| |      ||
396 | [Rotate Function](https://leetcode.com/problems/rotate-function/#/description) | [Math](./src/396.Rotate_Function.cpp	) |  O(n) |O(1)  | Medium	| |     ||
397 | [Integer Replacement  ](https://leetcode.com/problems/integer-replacement/#/description)| [Backtracking ](./src/397.Integer_Replacement.cpp) |  O(2^n) |  O(1)  | Medium	|  |    ||
398 | [Random Pick Index](https://leetcode.com/problems/random-pick-index/#/description)| [Math](./src/398.Random_Pick_Index.cpp) |O(n) | O(1) | Medium		 | |  ||
399 | [Evaluate Division  ](https://leetcode.com/problems/evaluate-division/#/description)| [DFS](./src/399.Evaluate_Division.cpp) |  O(n!)   |  O(1) | Medium| |  Y ||
400 | [Nth Digit](https://leetcode.com/problems/nth-digit/#/description) | [Math](./src/400.Nth_Digit.cpp) |   O(n) | O(1)   | Easy|   |     ||
401 | [Binary Watch](https://leetcode.com/problems/binary-watch/#/description)| [Bit Manipulation](./src/401.Binary_Watch.cpp)|   O(720) | O(1)  | Easy |  |     ||
402 | [Remove K Digits](https://leetcode.com/problems/remove-k-digits/#/description)| [Greedy](./src/402.Remove_K_Digits.cpp) |   O(n)  | O(n)   |Medium| |      ||
403 | [Frog Jump](https://leetcode.com/problems/frog-jump/#/description) | [DP](./src/403.Frog_Jump.cpp) |  O(n) |O(n)  | Hard	| |     ||
404 | [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/#/description)| [Backtracking ](./src/404.Sum_of_Left_Leaves.cpp) |  O(n) |  O(1)  | Easy|  |    ||
405 | [Convert a Number to Hexadecimal ](https://leetcode.com/problems/convert-a-number-to-hexadecimal/#/description)| [Bit Manipulation](./src/405.Convert_a_Number_to_Hexadecimal.cpp) |O(n) | O(1) | Easy		 | |  ||
406 | [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/#/description)| [Sort](./src/406.Queue_Reconstruction_by_Height.cpp) |  O(nlogn)   |  O(1) | Medium| |   ||
407 | [Trapping Rain Water II  ](https://leetcode.com/problems/trapping-rain-water-ii/#/description) | [BFS](./src/407.Trapping_Rain_Water_II.cpp) |   O(n) | O(n)   | Hard|   |     ||
408 | [Valid Word Abbreviation  ](https://leetcode.com/problems/valid-word-abbreviation/#/description)| [String](./src/408.Valid_Word_Abbreviation.cpp)|   O(n) | O(1)  | Easy |  |     ||
409 | [Longest Palindrome ](https://leetcode.com/problems/longest-palindrome/#/description)| [Hash Table](./src/409.Longest_Palindrome.cpp) |   O(n)  | O(256)   |Easy| |      ||
410 | [Split Array Largest Sum ](https://leetcode.com/problems/split-array-largest-sum/#/description) | [Binary Search](./src/410.Split_Array_Largest_Sum.cpp) |  O(logn) |O(1)  | Hard	| |     ||
411 | [Minimum Unique Word Abbreviation](https://leetcode.com/problems/minimum-unique-word-abbreviation/#/description)| [Backtracking ](./src/411.Minimum_Unique_Word_Abbreviation.cpp) |  O(2^n) |  O(1)  | Hard|  |    ||
412 | [Fizz Buzz ](https://leetcode.com/problems/fizz-buzz/#/description)| [Array](./src/412.Fizz_Buzz.cpp) |O(n) | O(1) | Easy		 | |  ||
413 | [Arithmetic Slices ](https://leetcode.com/problems/arithmetic-slices/#/description)| [DP](./src/413.Arithmetic_Slices.cpp) |  O(n)   |  O(n) | Medium| |   ||
414 | [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/#/description) | [Array](./src/414.Third_Maximum_Number.cpp) |   O(n) | O(1)   |  Easy	|   |     ||
415 | [Add Strings](https://leetcode.com/problems/add-strings/#/description)| [Math](./src/415.Add_Strings.cpp)|   O(n) | O(n)  | Easy |  |     ||
416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/#/description)| [DP](./src/416.Partition_Equal_Subset_Sum.cpp) |   O(n)  | O(n)   |Medium| |      ||
417 | [Pacific Atlantic Water Flow ](https://leetcode.com/problems/pacific-atlantic-water-flow/#/description)| [DFS](./src/417.Pacific_Atlantic_Water_Flow.cpp) |   O(2^n)  | O(m\*n)   |Medium| |      ||
418 | [Sentence Screen Fitting](https://leetcode.com/problems/sentence-screen-fitting/#/description) | [Hash Table](./src/418.Sentence_Screen_Fitting.cpp) |  O(n) |O(n)  | Medium	| |     ||
419 | [Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/#/description)| [Math](./src/419.Battleships_in_a_Board.cpp) |  O(m\*n) |  O(1)  | Medium|  |    ||
420 | [Strong Password Checker  ](https://leetcode.com/problems/strong-password-checker/#/description)| [Hash Table](./src/420.Strong_Password_Checker.cpp) |O(n) | O(1) | Hard		 | |  ||
421 | [Maximum XOR of Two Numbers in an Array ](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/#/description)| [Bit Manipulation + Trie](./src/421.Maximum_XOR_of_Two_Numbers_in_an_Array.cpp) |  O(n)   |  O(n) | Medium| |   ||
422 | [Valid Word Square](https://leetcode.com/problems/valid-word-square/#/description) | [String](./src/422.Valid_Word_Square.cpp) |   O(n\*k) | O(1)   |  Easy	|   |     ||
423 | [Reconstruct Original Digits from English ](https://leetcode.com/problems/reconstruct-original-digits-from-english/#/description)| [Math](./src/423.Reconstruct_Original_Digits_from_English.cpp)|   O(n) | O(n)  | Medium |  |     ||
424 | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/#/description)| [String](./src/424.Longest_Repeating_Character_Replacement.cpp) |   O(n)  | O(n)   |Medium| |      ||
425 | [Word Squares ](https://leetcode.com/problems/word-squares/#/description)| [Backtracking + Trie](./src/425.Word_Squares.cpp) |   O(n!)  | O(n)   |Hard|Y |      ||
432 | [All O one Data Structure](https://leetcode.com/problems/all-oone-data-structure/#/description) | [Hash Table](./src/432.All_O_one_Data_Structure.cpp) |  O(1) |O(n)  | Hard	| Y|     ||
434 | [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string/#/description)| [String](./src/434.Number_of_Segments_in_a_String.cpp) |  O(n) |  O(1)  | Easy|  |    ||
435 | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/#/description)| [Greedy](./src/435.Non-overlapping_Intervals.cpp) |O(nlogn) | O(1) |Medium	 | |  ||
436 | [Find Right Interval](https://leetcode.com/problems/find-right-interval/#/description)| [Binary Search](./src/436.Find_Right_Interval.cpp) |  O(nlogn)   |  O(n) | Medium| |   ||
437 | [Path Sum III](https://leetcode.com/problems/path-sum-iii/#/description) | [Backtracking](./src/437.Path_Sum_III.cpp) |   O(n) | O(1)   |  Easy	|   |     ||
438 | [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description)| [Hash Table](./src/438.Find_All_Anagrams_in_a_String.cpp)|   O(n) | O(26)  |Easy	 |  |     ||
439 | [Ternary Expression Parser ](https://leetcode.com/problems/ternary-expression-parser/#/description)| [Stack ](./src/439.Ternary_Expression_Parser.cpp) |   O(n)  | O(n)   |Medium| |      ||
440 | [K-th Smallest in Lexicographical Order ](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/#/description)| [Tree](./src/440.K-th_Smallest_in_Lexicographical_Order.cpp) |   O(logn\*k)  | O(n)   |Hard| |      ||
441 | [Arranging Coins ](https://leetcode.com/problems/arranging-coins/#/description) | [Binary Search](./src/441.Arranging_Coins.cpp) |  O(logn) |O(1)  | Easy	| Y|     ||
442 | [Find All Duplicates in an Array ](https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description)| [Array](./src/442.Find_All_Duplicates_in_an_Array.cpp) |  O(n) |  O(1)  | Medium|  |    ||
444 | [Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/#/description)| [Hash Table](./src/444.Sequence_Reconstruction.cpp) |O(m\*n) | O(n) |Medium	 | |  ||
445 | [Add Two Numbers II ](https://leetcode.com/problems/add-two-numbers-ii/#/description)| [Stack](./src/445.Add_Two_Numbers_II.cpp) |  O(n)   |  O(n) | Medium| |   ||
446 | [Arithmetic Slices II - Subsequence ](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/#/description) | [DP](./src/446.Arithmetic_Slices_II_Subsequence.cpp) |   O(n) | O(n)   |  Hard|   |     ||
447 | [Number of Boomerangs  ](https://leetcode.com/problems/number-of-boomerangs/#/description)| [Hash Table](./src/447.Number_of_Boomerangs.cpp)|   O(n^2) | O(n)  |Easy	 |  |     ||
448 | [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/#/description)| [Array](./src/448.Find_All_Numbers_Disappeared_in_an_Array.cpp) |   O(n)  | O(1)   |Easy| |      ||
449 | [Serialize and Deserialize BST ](https://leetcode.com/problems/serialize-and-deserialize-bst/#/description)| [Tree](./src/449.Serialize_and_Deserialize_BST.cpp	) |   O(n)  | O(n)   |Hard| |      ||
450 | [Delete Node in a BST ](https://leetcode.com/problems/delete-node-in-a-bst/#/description) | [Tree](./src/450.Delete_Node_in_a_BST.cpp) |  O(n) |O(1)  |  Medium	| |     ||
451 | [Sort Characters By Frequency ](https://leetcode.com/problems/sort-characters-by-frequency/#/description)| [Heap](./src/451.Sort_Characters_By_Frequency.cpp) |  O(n) |  O(n)  | Medium|  |    ||
452 | [Minimum Number of Arrows to Burst Balloons ](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/#/description)| [Sort](./src/452.Minimum_Number_of_Arrows_to_Burst_Balloons.cpp) |O(nlogn) | O(1) |Medium	 | |  ||
453 | [Minimum Moves to Equal Array Elements ](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/#/description)| [Array](./src/453.Minimum_Moves_to_Equal_Array_Elements.cpp) |  O(n)   |  O(1) | Easy| |   ||
454 | [4Sum II](https://leetcode.com/problems/4sum-ii/#/description) | [Math](./src/454.4Sum_II.cpp) |   O(n^2) | O(n)   |   Medium|   |     ||
455 | [Assign Cookies ](https://leetcode.com/problems/assign-cookies/#/description)| [Greedy](./src/455.Assign_Cookies.cpp)|   O(nlogn) | O(n)  |Easy	 |  |     ||
456 | [132 Pattern ](https://leetcode.com/problems/132-pattern/#/description)| [Array](./src/456.132_Pattern.cpp) |   O(n^2)  | O(n)   | Medium| |      ||
459 | [Repeated Substring Pattern ](https://leetcode.com/problems/repeated-substring-pattern/#/description)| [String](./src/459.Repeated_Substring_Pattern.cpp	) |   O(n^2)  | O(1)   |Easy| |      ||
460 | [LFU Cache](https://leetcode.com/problems/lfu-cache/#/description)| [Design](./src/460.LFU_Cache.cpp	) |   O(n)  | O(n)   |Hard| |      ||
461 | [Hamming Distance ](https://leetcode.com/problems/hamming-distance/#/description) | [Bit Manipulation ](./src/461.Hamming_Distance.cpp) |  O(n) |O(1)  |  Easy	| |     ||
462 | [Minimum Moves to Equal Array Elements II  ](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/#/description)| [Sort](./src/462.Minimum_Moves_to_Equal_Array_Elements_II.cpp) |  O(nlogn) |  O(1)  | Medium|  |    ||
463 | [Island Perimeter ](https://leetcode.com/problems/island-perimeter/#/description)| [Math](./src/463.Island_Perimeter.cpp) |O(m\*n) | O(1) |Easy	 | |  ||
464 | [Can I Win ](https://leetcode.com/problems/can-i-win/#/description)| [BackTracking](./src/464.Can_I_Win.cpp) |  O(n!)   |  O(n) | Medium| |   ||
465 | [Optimal Account Balancing  ](https://leetcode.com/problems/optimal-account-balancing/#/description) | [BackTracking](./src/465.Optimal_Account_Balancing.cpp) |   O(n!) | O(n)   |   Hard| Y  |     ||
466 | [Count The Repetitions](https://leetcode.com/problems/count-the-repetitions/#/description)| [DP](./src/466.Count_The_Repetitions.cpp)|   O(n) | O(n)  |Hard	 |  |     ||
467 | [Unique Substrings in Wraparound String  ](https://leetcode.com/problems/unique-substrings-in-wraparound-string/#/description)| [DP](./src/467.Unique_Substrings_in_Wraparound_String.cpp) |   O(n)  | O(n)   | Medium| |      ||
468 | [Validate IP Address](https://leetcode.com/problems/validate-ip-address/#/description)| [String](./src/468.Validate_IP_Address.cpp) |   O(n)  | O(1)   |Medium	| |      ||
469 | [Convex Polygon  ](https://leetcode.com/problems/convex-polygon/#/description) | [Math](./src/469.Convex_Polygon.cpp) |  O(n) |O(1)  |  Medium	| |     ||
471 | [Encode String with Shortest Length ](https://leetcode.com/problems/encode-string-with-shortest-length/#/description)| [DP](./src/471.Encode_String_with_Shortest_Length.cpp) |  O(n^2) |  O(1)  | Hard|  |    ||
472 | [Concatenated Words ](https://leetcode.com/problems/concatenated-words/#/description)| [DP](./src/472.Concatenated_Words.cpp) |O(m\*n) | O(n) |Hard | |  ||
473 | [Matchsticks to Square ](https://leetcode.com/problems/matchsticks-to-square/#/description)| [BackTracking](./src/473.Matchsticks_to_Square.cpp) |  O(n!)   |  O(1) | Medium| |   ||
474 | [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/#/description) | [DP](./src/474.Ones_and_Zeroes.cpp	) |   O(m\*n) | O(m\*n)   |   Medium|   |     ||
475 | [Heaters ](https://leetcode.com/problems/heaters/#/description)| [Binary Search](./src/475.Heaters.cpp	)|   O(nlogn) | O(1)  |Easy	 |  |     ||
476 | [Number Complement](https://leetcode.com/problems/number-complement/#/description)| [Bit Manipulation](./src/476.Number_Complement.cpp) |   O(n)  | O(1)   | Easy| |      ||
477 | [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/#/description)| [Bit Manipulation](./src/477.Total_Hamming_Distance.cpp	) |   O(n)  | O(1)   |Medium	| |      ||
480 | [Sliding Window Median ](https://leetcode.com/problems/sliding-window-median/#/description)| [Heap](./src/480.Sliding_Window_Median.cpp) |   O(1)  | O(n)   |Hard| Y | multiset      ||
481 | [Magical String ](https://leetcode.com/problems/magical-string/#/description)| [Math](./src/481.Magical_String.cpp ) |  O(n) |  O(n)  | Medium|  |    ||
482 | [License Key Formatting](https://leetcode.com/problems/license-key-formatting/#/description)| [String](./src/482.License_Key_Formatting.cpp) |O(n) | O(1) |Medium | |  ||
483 | [Smallest Good Base ](https://leetcode.com/problems/smallest-good-base/#/description)| [Binary Search](./src/483.Smallest_Good_Base.cpp) |  O(logn)   |  O(1) | Hard| |   ||
484 | [Find Permutation ](https://leetcode.com/problems/find-permutation/#/description) | [Greedy](./src/484.Find_Permutation.cpp	) |   O(n) | O(n)   |   Medium|   |     ||
485 | [Max Consecutive Ones ](https://leetcode.com/problems/max-consecutive-ones/#/description)| [Array](./src/485.Max_Consecutive_Ones.cpp)|   O(n) | O(1)  |Easy	 |  |     ||
486 | [Predict the Winner](https://leetcode.com/problems/predict-the-winner/#/description)| [Backtracking](./src/486.Predict_the_Winner.cpp) |   O(2^n)  | O(1)   | Medium| |      ||
487 | [Max Consecutive Ones II ](https://leetcode.com/problems/max-consecutive-ones-ii/#/description)| [Array](./src/487.Max_Consecutive_Ones_II.cpp	) |   O(n)  | O(1)   |Medium	|Y | sliding window      ||
490 | [The Maze ](https://leetcode.com/problems/the-maze/#/description)| [DFS](./src/490.The_Maze_DFS.cpp) \| [BFS](./src/490.The_Maze_BFS.cpp)|   O(n)  | O(n)   |Medium| Y |      ||
491 | [Increasing Subsequences](https://leetcode.com/problems/increasing-subsequences/#/description)| [Backtracking](./src/491.Increasing_Subsequences.cpp ) |  O(n!) |  O(1)  | Medium|  |    ||
492 | [Construct the Rectangle ](https://leetcode.com/problems/construct-the-rectangle/#/description)| [Math](./src/492.Construct_the_Rectangle.cpp) |O(n^0.5) | O(1) |Easy | |  ||
494 | [Target Sum  ](https://leetcode.com/problems/target-sum/#/description)| [Backtracking](./src/494.Target_Sum.cpp) |  O(2^n)   |  O(1) | Medium| |   ||
495 | [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/#/description) | [Array](./src/495.Teemo_Attacking.cpp	) |   O(n) | O(1)   |   Medium|   |     ||
496 | [Next Greater Element I ](https://leetcode.com/problems/next-greater-element-i/#/description)| [Hash Table](./src/496.Next_Greater_Element_I.cpp)|   O(n) | O(n)  |Easy	 |  |     ||
498 | [Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/#/description)| [Solution](./src/498.Diagonal_Traverse.cpp ) |   O(m\*n)  | O(1)   | Medium| |      ||
499 | [The Maze III](https://leetcode.com/problems/the-maze-iii/#/description)| [DFS](./src/499.The_Maze_III.cpp	) |   O(n!)  | O(m\*n)   |Hard	| |       ||
500 | [Keyboard Row](https://leetcode.com/problems/keyboard-row/#/description)| [Hash Table](./src/500.Keyboard_Row.cpp) |   O(n)  | O(1)   |Easy|  |      ||



