#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sum(int cards[]);                                    //定义函数：求数组中各元素和
int main(void)
{
    char ccc;
    do
    {
        srand(time(NULL));                                   //重置随机数
        int poker[2][52]=                                    //用二维数组表示一副扑克牌
        {
            {
                0,2,3,4,5,6,7,8,9,10,10,10,10,
                0,2,3,4,5,6,7,8,9,10,10,10,10,
                0,2,3,4,5,6,7,8,9,10,10,10,10,
                0,2,3,4,5,6,7,8,9,10,10,10,10
            },
            {
                1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1
            }
        };
        int maker[11]= {0};                                  //构建庄家的手牌
        int player[11]= {0};                                 //构建玩家的手牌
        int card;                                            //随机所发的牌
        int p_c;
        int i=0,j=0;
        int k=0;
        int cc;

        printf("Let's start the game!Input a number to begin!\n");
        do
        {
            card=rand()%52;                                  //为庄家发一张牌
            if(poker[1][card]&&21-sum(maker)>5)              //规定庄家何时抽牌
            {
                if(card==0||card==13||card==26||card==39)    //为抽到A时所赋值进行讨论
                {
                    if(sum(maker)>10)
                        poker[0][card]=1;
                    else
                        poker[0][card]=11;
                }
                maker[i]=poker[0][card];
                poker[1][card]=0;                            //这张牌将不会再被抽到
                i++;
            }
            if(sum(maker)>21)
                break;
            card=rand()%52;
            printf("Get a new card?The first card has to be taken!\n");
            if(scanf("%d",&p_c)==1)                          //决定是否抽牌
            {
                if(card==0||card==13||card==26||card==39)    //控制抽到的A
                {
                    printf("you get A\n");
                    k++;
                }
                player[j]=poker[0][card];
                poker[1][card]=0;
                j++;
                printf("you get a %d,sum of them is %d\n",poker[0][card],sum(player));//显示抽到的牌和现有牌的总和
            }
            if(sum(player)+k>21)
                break;
            printf("Do you want to end?(a number means no)\n"); //控制游戏的结束
        } while(scanf("%d",&cc)==1);
        if(k)                                                //由玩家控制抽到的A赋值1或11
        {
            printf("You got %d Ace(s),please give it(them) 1 or 11!\n",k);
            int m;
            int plus;
            int c;
            int s_p=sum(player);
            printf("a number means 1\n");
            for(m=0; m<=k; m++)
            {
                if(scanf("%d",&c)==1)
                    plus=1;
                else
                    plus=11;
                s_p+=plus;
            }
        }
        if(sum(maker)>21&&sum(player)>21)                    //系统判断赢家
            printf("Maker win!\n");
        if(sum(maker)>21&&sum(player)<=21)
            printf("Player win!\n");
        if(sum(maker)<=21&&sum(player)>21)
            printf("Maker win!\n");
        if(sum(maker)<=21&&sum(player)<=21&&sum(maker)<sum(player))
            printf("Player win!\n");
        if(sum(maker)<=21&&sum(player)<=21&&sum(maker)>sum(player))
            printf("Maker win!\n");
        printf("Game Over,Bye!\n");
        printf("Sum of maker's cards is %d\n",sum(maker));//输出庄家牌的总和
        if(sum(player)==21)
            printf("You are a Lucky Dog!\nYou got 21 points! Congratulations!!!!!");
        printf("Would you like to start a new bureau? y means yes,n means no.\n");//询问是否开启新的一局
        while(getchar()!='\n')
            continue;
        scanf("%c",&ccc);
        if(ccc=='y')
            continue;
        else
            break;
    }while(ccc=='y');
    return 0;
}
int sum(int cards[])                                     //自定义函数的定义
{
    int i;
    int s=0;
    for(i=0; i<=10; i++)
        s+=cards[i];
    return s;
}
