/* 2151928 唐芊竹 信12 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
int count=1;
void hanoi(int n, char src, char tmp, char dst)
{
    if (n >= 1) {
        hanoi(n - 1, src, dst, tmp);
        printf("%5d:%3d# %c-->%c\n", count++, n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int n,ret;
    char src, tmp, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-16)\n");
        ret=scanf("%d", &n);
        if (ret!=0) {
            if (n >= 1 && n <= 16) {
                setbuf(stdin, NULL);
                break;
            }
            else {

                setbuf(stdin, NULL);
                continue;
            }
        }
        else {
            clearerr(stdin);
            setbuf(stdin, NULL);
            continue;
        }
    }
    while (1) {
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &src);
        setbuf(stdin, NULL);
        if (src == 'a' || src == 'b' || src == 'c' || src == 'A' || src == 'B' || src == 'C') {
            break;
        }
        else {
            continue;
        }
    }
   
    while (1) {
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &dst);
        setbuf(stdin, NULL);
        if (dst == 'a' || dst == 'b' || dst == 'c' || dst == 'A' || dst == 'B' || dst == 'C') {    //在范围内
            if (dst == src || ((int)src - (int)dst == 32)|| ((int)src - (int)dst == -32)) {       //重合
                if (src == 'a' || src == 'A') {
                    printf("目标柱(A)不能与起始柱(A)相同\n");
                    continue;
                }
                if (src == 'b' || src == 'B') {
                    printf("目标柱(B)不能与起始柱(B)相同\n");
                    continue;
                }
                if (src == 'c' || src == 'C') {
                    printf("目标柱(C)不能与起始柱(C)相同\n");
                    continue;
                }
            }
            else {              //不重合
                break;
            }
        }
        else {                 //输入的目标柱不在范围
            continue;
        }
    }
    if (src == 'a')
        src = 'A';
    if (src == 'b')
        src = 'B';
    if (src == 'c')
        src = 'C';
    if (dst == 'a')
        dst = 'A';
    if (dst == 'b')
        dst = 'B';
    if (dst == 'c')
        dst = 'C';
    if (src != 'A' && dst != 'A')
        tmp = 'A';
    if (src != 'B' && dst != 'B')
        tmp = 'B';
    if (src != 'C' && dst != 'C')
        tmp = 'C';
    printf("移动步数为:\n");
    hanoi(n, src, tmp, dst);
    return 0;
}