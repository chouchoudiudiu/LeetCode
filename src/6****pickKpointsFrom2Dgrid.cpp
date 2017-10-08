如果是with replacement
那就直接
for (int i = 0; i < k; i++) { 
int rnd_val = rand() % (nRow * nCol); 
int rnd_row = rnd_val / nCol; 
int rnd_col = rnd_val % nCol; 
return pair<int, int>(rnd_row, rnd_col);}

如果是without replacement
如果是数据范围很小
你可以直接生成(0, 1, 2, 3, 4, ..., nRow * nCol)这个数组
然后跑一个Fisher Yates Shuffle
取前k
如果数据范围很大
可以直接reservoir
