# 黑盒光线反射

得到答案其实并不困难，直接模拟光线的照射方向，找到下一个被照射到的小孔下标，当小孔标志为打开时，返回小孔下标即可。

然而提交超时了。直接模拟的思路显然并不可取。

考虑小孔下标的出现必然是循环的，如果可以为循环编号，然后记录每个打开的小孔对应的权值，组成循环链表。

该权值的后驱对应的小孔下标即为最终结果。这样可以规避中间未开启的小孔遍历，达到加速效果，然而还是超时。

耗时的原因是每次将节点加入循环链表时，需要依次查找位置，时间复杂度为`O(N)`，效率较低。

为了更快的定位到循环节点的位置，在链表上建立二叉平衡树，一步到位将查找速度优化到`O(logN)`。
