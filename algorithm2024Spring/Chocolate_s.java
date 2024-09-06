package Chocolate_1;

import java.util.Scanner;

public class Chocolate_s {
    static int n=0;//n块巧克力
    static int k=0;//k个小朋友
    static int[]width=new int[10001];
    static int[]heiht=new int[10001];
     //用函数判断此分发是否满足每个小朋友都可以吃巧克力
    public static int Sum(int length)
    {
        int sum=0;
        for(int i=1;i<n+1;i++)
        {
            sum+=(width[i]/length)*(heiht[i]/length);
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("输入巧克力个数");
        n=sc.nextInt();
        System.out.println("输入小孩个数");
        k=sc.nextInt();
        //输入每块巧克力的长宽高
        System.out.println("输入每块巧克力的长度、宽度");
        for(int i=1;i<n+1;i++)
        {
            width[i]=sc.nextInt();
            heiht[i]=sc.nextInt();
        }
        System.out.println("aaa");
        //利用二分法对最大巧克力边长进行查找
        int left=1;
        int right=20;
        while (left<right)
        {
            int mid=(left+right+1)/2;//一定要＋1，不然left与right相临的时候就会出现死循环
            if(Sum(mid)>=k)
            {
                left=mid;
            }
            else {
                right=mid-1;
            }

        }
        System.out.println("最大长度为");
        System.out.println(left);
    }
}
