#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sum(int cards[]);                                    //���庯�����������и�Ԫ�غ�
int main(void)
{
    char ccc;
    do
    {
        srand(time(NULL));                                   //���������
        int poker[2][52]=                                    //�ö�ά�����ʾһ���˿���
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
        int maker[11]= {0};                                  //����ׯ�ҵ�����
        int player[11]= {0};                                 //������ҵ�����
        int card;                                            //�����������
        int p_c;
        int i=0,j=0;
        int k=0;
        int cc;

        printf("Let's start the game!Input a number to begin!\n");
        do
        {
            card=rand()%52;                                  //Ϊׯ�ҷ�һ����
            if(poker[1][card]&&21-sum(maker)>5)              //�涨ׯ�Һ�ʱ����
            {
                if(card==0||card==13||card==26||card==39)    //Ϊ�鵽Aʱ����ֵ��������
                {
                    if(sum(maker)>10)
                        poker[0][card]=1;
                    else
                        poker[0][card]=11;
                }
                maker[i]=poker[0][card];
                poker[1][card]=0;                            //�����ƽ������ٱ��鵽
                i++;
            }
            if(sum(maker)>21)
                break;
            card=rand()%52;
            printf("Get a new card?The first card has to be taken!\n");
            if(scanf("%d",&p_c)==1)                          //�����Ƿ����
            {
                if(card==0||card==13||card==26||card==39)    //���Ƴ鵽��A
                {
                    printf("you get A\n");
                    k++;
                }
                player[j]=poker[0][card];
                poker[1][card]=0;
                j++;
                printf("you get a %d,sum of them is %d\n",poker[0][card],sum(player));//��ʾ�鵽���ƺ������Ƶ��ܺ�
            }
            if(sum(player)+k>21)
                break;
            printf("Do you want to end?(a number means no)\n"); //������Ϸ�Ľ���
        } while(scanf("%d",&cc)==1);
        if(k)                                                //����ҿ��Ƴ鵽��A��ֵ1��11
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
        if(sum(maker)>21&&sum(player)>21)                    //ϵͳ�ж�Ӯ��
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
        printf("Sum of maker's cards is %d\n",sum(maker));//���ׯ���Ƶ��ܺ�
        if(sum(player)==21)
            printf("You are a Lucky Dog!\nYou got 21 points! Congratulations!!!!!");
        printf("Would you like to start a new bureau? y means yes,n means no.\n");//ѯ���Ƿ����µ�һ��
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
int sum(int cards[])                                     //�Զ��庯���Ķ���
{
    int i;
    int s=0;
    for(i=0; i<=10; i++)
        s+=cards[i];
    return s;
}
