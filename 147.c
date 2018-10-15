#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int N;
    printf("请输入习题数量：");
    scanf("%d",&N);
    N=N-1;
    int num1, num2, num3, count=0, result,resultTrue,flag;
    char op1, op2;
    srand(time(NULL)); //启动随机数生成器
    do
    {
        count++;
        num1 = rand() % 10+1;
        num2 = rand() % 10+1;
        num3 = rand() % 10+1;
        switch (num1 % 4)
        {
        case 0:
            op1 = '+';
            break;
        case 1:
            op1 = '-';
            break;
        case 2:
            op1 = '*';
            break;
        case 3:
            op1 = '/';
            break;
        default:
            break;
        }
        switch (num2 % 4)
        {
        case 0:
            op2 = '+';
            flag = 0;
            break;
        case 1:
            op2 = '-';
            flag = 0;
            break;
        case 2:
            op2 = '*';
            if((op1=='*')||(op1=='/')) flag = 0;
            else flag = 1;
            break;
        case 3:
            op2 = '/';
            if((op1=='*')||(op1=='/')) flag = 0;
            else flag = 1;
            break;
        default:
            break;
        }
        printf("%d %c %d %c %d = ",num1,op1,num2,op2,num3);
        if(flag==0)
        {
            resultTrue = 0;
            switch (op1)
            {
            case '+':
                resultTrue = num1+num2;
                break;
            case '-':
                resultTrue = num1-num2;
                break;
            case '*':
                resultTrue = num1*num2;
                break;
            case '/':
                resultTrue = num1/num2;
                break;
            default:
                break;
            }
            switch (op2)
            {
            case '+':
                resultTrue += num3;
                break;
            case '-':
                resultTrue -= num3;
                break;
            case '*':
                resultTrue *= num3;
                break;
            case '/':
                resultTrue /= num3;
                break;
            default:
                break;
            }
        }
        else
        {
            resultTrue = 0;
            switch (op2)
            {
            case '+':
                resultTrue = num2+num3;
                break;
            case '-':
                resultTrue = num2-num3;
                break;
            case '*':
                resultTrue = num2*num3;
                break;
            case '/':
                resultTrue = num2/num3;
                break;
            default:
                break;
            }
            switch (op1)
            {
            case '+':
                resultTrue = num1 + resultTrue;
                break;
            case '-':
                resultTrue = num1 - resultTrue;
                break;
            case '*':
                resultTrue = num1 * resultTrue;
                break;
            case '/':
                resultTrue = num1 / resultTrue;
                break;
            default:
                break;
            }
        }
        scanf("%d",&result);
        if (result == resultTrue)
            printf("结果正确!\n");
        else
            printf("结果错误!正确答案为:%d \n",resultTrue);

    }
    while(count<=N);
    return 0;
}
