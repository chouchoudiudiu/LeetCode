

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
29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/#/description/) | [Bit Manipulation](./src/029.Divide_Two_Integers.cpp) |  O(logn)   |  O(1) | Medium |  | Y   ||
30 | [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/#/description/) | [Hash Table](./src/030.Substring_with_Concatenation_of_All_Words.cpp) |  O(n)   |  O(n) | Hard |  |    ||
530 | [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description/) | [DFS](./src/530.Minimum_Absolute_Difference_in_BST.cpp)  |      |          | Easy         ||
