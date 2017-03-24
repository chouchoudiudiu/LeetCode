

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
16 | [3Sum Closest](https://leetcode.com/problems/3sum-closest/#/description/) | [Two Pointers](./src/015.3Sum_Closest.cpp) |  O(n^2)    |  O(1) |Medium |  |   ||
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
38 | [Count and Say](https://leetcode.com/problems/count-and-say/#/description/) | [Solution](./src/038.Count_and_Say.cpp) |  O(n)   |  O(1) | Easy |   |     ||
39 | [Combination Sum](https://leetcode.com/problems/combination-sum/#/description/) | [DFS](./src/039.Combination_Sum.cpp) |  O(2^n)   | O(1)  | Medium |  |     ||
40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/#/description/) | [DFS](./src/040.Combination_Sum_II.cpp) | O(2^n)| O(1) | Medium  | Y  |  prev  ||
41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/#/description/) | [Array](./src/041.First_Missing_Positive.cpp) |  O(n)   |  O(1) | Hard | Y  |     ||
42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/#/description/) | [Two Pointers](./src/042.Trapping_Rain_Water.cpp) |  O(n)   | O(1)  | Hard |  |     ||
43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/#/description/) | [String](./src/043.Multiply_Strings.cpp) | O(m\*n)| O(1) | Medium  | Y  |    ||
45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/#/description/) | [Two Pointer](./src/045.Jump_Game_II.cpp) |  O(n)   |  O(1) | Hard | Y  |     ||
46 | [Permutations](https://leetcode.com/problems/permutations/#/description/) | [DFS](./src/046.Permutations.cpp) |  O(n\*n!)   | O(n)  | Medium |  |     ||
47 | [Permutations II](https://leetcode.com/problems/permutations-ii/#/description/) | [DFS](./src/047.Permutations_II_1.cpp) \|[Hash Table](./src/047.Permutations_II_2.cpp) | O(n\*n!)| O(n) | Medium  | Y  |    ||
48 | [Rotate Image](https://leetcode.com/problems/rotate-image/#/description/) | [In Place](./src/048.Rotate_Image.cpp) |  O(n^2)   |  O(1) | Medium |   |     ||
49 | [Group Anagrams](https://leetcode.com/problems/anagrams/#/description/) | [Hash Table](./src/049.Group_Anagrams.cpp) |  O(m\*n)   | O(1)  | Medium |  |     ||
50 | [Pow(x, n)](https://leetcode.com/problems/powx-n/#/description/) | [Divide and Conquer](./src/050.Pow_x_n.cpp) | O(logn)| O(1) | Medium  | Y  |    ||
51 | [N-Queens](https://leetcode.com/problems/n-queens/#/description/) | [Back Tracking](./src/051.N-Queens.cpp) |  O(exp)   | O(n)  | Hard | Y |     ||
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

