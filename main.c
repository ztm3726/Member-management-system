#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
FILE *fp;

char sex1[3]="男",sex2[3]="女";

typedef struct student
{
    char num[20];//学号

    char name[10000];//姓名

    char sex[10000];//性别

    char call[10000];//电话号码

    char adress[10000];//地址

    struct student *next;//指向下一个节点的指针
} student;
void welcome()//主界面
{
    time_t now;//获取当前时间

    struct tm *times;

    time(&now);

    times=localtime(&now);

    system("color B");

    system("cls");
    printf("\t\t   _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |  欢迎您使用实验室成员管理系统 |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        %d年%d月%d日           |\n",times->tm_year+1900,times->tm_mon,times->tm_mday);
    printf("\t\t   |                             |\n");
    printf("\t\t  |        1.增加成员信息         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        2.修改成员信息         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        3.删除成员信息         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        4.查询本人信息         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        5.查询全部信息         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        6.打开保存文件         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        7.保存成员信息         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        0.退出管理系统         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t   -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("\t\t          请输入指令:(0-6) ");
}
void add(student *phead,student *pend)//增加成员
{
    system("cls");

    int i,result;

    student *pnew=(student*)malloc((sizeof(student)));//创建一个新节点,用来存数据

    student *pmove=(student*)malloc(sizeof(student));
a1:
    system("cls");

    printf("\t\t     请输入11位学号:  ");

    gets(pnew->num);

    for(i=0; i<strlen(pnew->num); i++)
    {
        if(strlen(pnew->num)==11&&pnew->num[i]>='0'&&pnew->num[i]<='9')//判断输入的学号长度，是否是数字
        {
            for(pmove=phead->next; pmove!=pend; pmove=pmove->next) //遍历链表，查找学号是否已经存在
            {
                if(strcmp(pmove->num,pnew->num)==0)
                {
                    system("cls");

                    result =MessageBox( 0,"学号已存在,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto a1;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
                }
            }
        }
        else
            {
        system("cls");

        result =MessageBox( 0,"学号不合法,是否重新输入", "提示", MB_YESNO);

        switch(result)
        {
        case IDYES:

            goto a1;

            break;

        case IDNO:

            return ;

            break;
        }
            }
    }
        printf("\n");
a2:
        printf("\t\t     请输入姓名:  ");

        gets(pnew->name);

        for(i=0; i<strlen(pnew->name); i++)
        {
            if(strlen(pnew->name)==4||strlen(pnew->name)==6) //判断输入的姓名长度
            {
            }
            else
            {
                system("cls");

                result =MessageBox( 0,"姓名不合法,是否重新输入", "提示", MB_YESNO);

                switch(result)
                {
                case IDYES:

                    goto a2;

                    break;

                case IDNO:

                    return ;

                    break;
                }
            }

        }

        printf("\n");
a3:
        printf("\t\t     请输入性别:  ");

        gets(pnew->sex);

        for(i=0; i<strlen(pnew->sex); i++)
        {
            if(strlen(pnew->sex)==2) //判断输入的性别是否为男或女
            {
                if(strcmp(pnew->sex,sex1)==0||strcmp(pnew->sex,sex2)==0)
                {

                }
                else
                {
                    system("cls");

                    result =MessageBox( 0,"性别不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto a3;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
                }
            }
        else
        {
            system("cls");

                result =MessageBox( 0,"性别不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto a3;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
        }

    }
    printf("\n");
a4:
    printf("\t\t     请输入11位电话号码:  ");

    gets(pnew->call);

    for(i=0; i<strlen(pnew->call); i++)
    {
        if(strlen(pnew->call)==11&&pnew->call[i]>='0'&&pnew->call[i]<='9') //判断输入的电话号码长度，是否是数字
        {
        }
        else
        {
            system("cls");

                result =MessageBox( 0,"电话号码不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto a4;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
        }

    }
    printf("\n");
a5:
    printf("\t\t     请输入家庭地址:  ");

    gets(pnew->adress);

    for(i=0; i<strlen(pnew->adress); i++)
    {
        if(strlen(pnew->adress)>=6&&strlen(pnew->adress)<=40) //判断输入的地址长度
        {
        }
        else
        {
            system("cls");

                result =MessageBox( 0,"家庭地址不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto a5;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
        }

    }
    printf("\n");

    pnew->next=phead->next;

    phead->next=pnew;

    printf("\t\t     ----->添加成功\n\n\a");

    system("pause");

}
void modify(student *phead,student *pend)//修改成员信息
{
    system("cls");

    student *pmove=(student*)malloc((sizeof(student)));

    char mod[100];

    int i,result,n=0;
b1:
    printf("\t\t     请输入要修改成员的学号:  ");

    gets(mod);

    for(i=0; i<strlen(mod); i++)
    {
        if(strlen(mod)==11&&mod[i]>='0'&&mod[i]<='9')//判断输入的学号长度，是否是数字
        {
            break;
        }
        else
        {
            system("cls");

                result=MessageBox( 0,"学号不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto b1;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
        }
    }
    for(pmove=phead->next; pmove!=pend; pmove=pmove->next)
    {
        if(strcmp(pmove->num,mod)==0)
        {
            n=1;

            system("cls");
b2:
            printf("\t\t     请重新输入姓名:  ");

            gets(pmove->name);

            for(i=0; i<strlen(pmove->name); i++)
            {
                if(strlen(pmove->name)==4||strlen(pmove->name)==6)
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"姓名不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto b2;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
                }

            }
            printf("\n");
b3:
            printf("\t\t     请重新输入性别:  ");

            gets(pmove->sex);

            for(i=0; i<strlen(pmove->sex); i++)
            {
                if(strlen(pmove->sex)==2)
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"性别不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto b3;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
                }

            }

            printf("\n");
b4:
            printf("\t\t     请重新输入11位电话号码:  ");

            gets(pmove->call);

            for(i=0; i<strlen(pmove->call); i++)
            {
                if(strlen(pmove->call)==11&&pmove->call[i]>='0'&&pmove->call[i]<='9')
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"电话号码不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto b4;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
                }

            }

            printf("\n");
b5:
            printf("\t\t     请重新输入家庭地址:  ");

            gets(pmove->adress);

            for(i=0; i<strlen(pmove->adress); i++)
            {
                if(strlen(pmove->adress)>=6&&strlen(pmove->adress)<=40)
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"家庭地址不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto b5;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
                }
            }
            printf("\n");

            printf("\t\t     ----->修改成功!\a\n\n");

            break;
        }
    }
    if(n!=1)
    {
        system("cls");

        printf("\n\n\t\t     ----->没有这个成员的信息!\n\n");
    }
    pmove=NULL;

    system("pause");
}
void deldate(student *phead,student *pend)//删除成员
{
    system("cls");

    student *pdel=(student*)malloc((sizeof(student)));

    student *pmove=(student*)malloc((sizeof(student)));

    char del[100];

    int n=0,i,result;
d1:
    printf("\t\t     请输入要删除成员的学号:  ");

    gets(del);

    for(i=0; i<strlen(del); i++)
    {
        if(strlen(del)==11&&del[i]>='0'&&del[i]<='9')//判断输入的学号长度，是否是数字
        {
            break;
        }
        else
        {
            system("cls");

                result=MessageBox( 0,"学号不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto d1;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
        }
    }
    for(pdel=phead;pdel!=pend; )// 从节点开始遍历，到尾节点结束
    {
        pmove=pdel;//然pdel的指针指向与pmove相同

        pdel=pdel->next;//pdel指向下一个节点

        if(strcmp(pdel->num,del)==0)
        {
            n=1;

            pmove->next=pdel->next;//pdel的下一个节点位置赋个上个节点，即将pdel指向的节点忽略

            printf("\n\t\t     ------>删除成功!\n\n\a");

            free(pdel);//删除pdel指向的节点
        }
    }
    if(n!=1)
    {
        printf("\n\n\t\t     ------>没有这个成员的信息!\n\n");
    }
    pmove=NULL;

    system("pause");
}
void findall(student *phead,student *pend)//查找所有成员
{
    system("cls");

    int n=0;

    student *pmove=(student*)malloc(sizeof(student));

    printf("学号:\t\t姓名:\t性别:\t电话号码:\t家庭地址:\n");

    for(pmove=phead->next; pmove!=pend; pmove=pmove->next)
    {
        n++;

        printf("\n%s\t%s\t%s\t%s\t%s\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
    }
    pmove=NULL;

    printf("\n实验室共有%d人\n\n",n);

    system("pause");
}
void findone(student* phead,student* pend)//查找个人信息
{
    system("cls");

    char find[100],number[100],clsone;

    int x,i,result,n=0;

    student *pmove=(student*)malloc(sizeof(student));

    printf("\t\t     按1学号查找 / 按2姓名查找\n\n\t\t     ");

    scanf("%d",&x);

    system("cls");

    if(x==1)
    {c1:
        printf("\t\t     请输入查找成员的学号:  \n\n\t\t     ");

        clsone=getchar();

        gets(number);

        for(i=0; i<strlen(number); i++)
        {
            if(strlen(number)==11&&number[i]>='0'&&number[i]<='9')
            {
                system("cls");

                break;
            }
            else
            {
                system("cls");

                result =MessageBox( 0,"学号不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto c1;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
            }
        }

    system("cls");

        for(pmove=phead->next; pmove!=pend; pmove=pmove->next)
        {
            if(strcmp(pmove->num,number)==0)
            {
                n=1;

                printf("查询结果如下\n\n学号:\t\t姓名:\t性别:\t电话号码:\t家庭地址:\n\n");

                printf("%s\t%s\t%s\t%s\t%s\n\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
            }
        }
        if(n!=1)
            {
                printf("\n\n\t\t     ------>没有这个成员的信息!\n\n");
            }
    }
    else if(x==2)
    {c2:
        printf("\t\t     请输入查找成员的姓名:  \n\n\t\t     ");

        clsone=getchar();

        gets(find);

        for(i=0; i<strlen(find); i++)
            {
                if(strlen(find)==4||strlen(find)==6)
                {
                    break;
                }
                else
                {
                    system("cls");

                    result =MessageBox( 0,"姓名不合法,是否重新输入", "提示", MB_YESNO);

                    switch(result)
                    {
                    case IDYES:

                        goto c2;

                        break;

                    case IDNO:

                        return ;

                        break;
                    }
                }

            }
        system("cls");

        for(pmove=phead->next; pmove!=pend; pmove=pmove->next)
        {
            if(strcmp(pmove->name,find)==0)
            {
                n=1;

                printf("查询结果如下\n\n学号:\t\t姓名:\t性别:\t电话号码:\t家庭地址:\n\n");

                printf("%s\t%s\t%s\t%s\t%s\n\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
            }
        }

        if(n!=1)
        {
            printf("\n\n\t\t     ------>没有这个成员的信息!\n\n");
        }
    }
    else
    {
        printf("\n\n\t\t     错误输入!\n");
    }
    printf("\n");

    system("pause");

    pmove=NULL;
}
void openonce(FILE *fp,student *phead)//打开文件
{
    system("cls");

    if((fp=fopen("text.txt","r"))==NULL)
    {
        printf("\n\n\t\t     打开文件失败,请检查文件存在\n\n");//判断文件是否存在

        system("pause");

        return ;
    }
    while(1)
    {
        student *pmove=(student*)malloc(sizeof(student));

        if(fscanf(fp,"%s%s%s%s%s",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress)!=EOF)//循环创建节点，并判断是否到文件结尾，不是结尾就写入链表
        {
        pmove->next=phead->next;//头插法插入

        phead->next=pmove;
        }
        else//到文件结尾就退出
        {
            break;
        }
    }
    fclose(fp);

    printf("\n\n\t\t     读取文件成功\n\n");

    system("pause");
}
void save(FILE *fp,student *phead,student *pend)//保存文件
{
    system("cls");

    int k=0,n=0;

    student *pmove=(student*)malloc(sizeof(student));

    for(pmove=phead->next; pmove!=pend; pmove=pmove->next)
    {
        n++;
    }
     if(n==0)
        {
            k=1;
        }
    else
    {
        fp=fopen("text.txt","w+");

        for(pmove=phead->next; pmove!=pend; pmove=pmove->next)//将每个节点写入文件
        {
            fprintf(fp,"%s\t%s\t%s\t%s\t%s\n\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
        }
    }
    fclose(fp);

    if(k==1)
    {
        printf("\n\n\t\t     没有成员信息可以保存\n\n");
    }
    if(k!=1)
    {
        printf("\n\n\t\t     文件成功保存(可进入根目录查询)\n\n");
    }
    system("pause");
}
void passward()//密码
{
     int i,k=0,n,p;

    char ch,password[20]={0};

    system("color B");
b1:
    i=0;n=0;p=0;

    printf("\t\t     身份验证\n\n");

    printf("\t\t     密码:");

    while((ch=getch())!='\r')  //当控制台没有敲入回车
        {
                if(ch!='\b')      //当控制台没有敲入退格键
                {
                        printf("*");

                        password[i]=ch;

                        i++;

                        p=i;
                }
                else
                {
                        printf("\b \b");   //修改刚才输入的密码

                        n++;

                        i--;

                        if(i<=0)
                        {
                            i=0;
                        }
                        if(n>=p)
                        {
                            system("cls");

                            goto b1;
                        }
                }
        }
        password[i]='\0';

    if(password[0]=='1'&&password[1]=='2'&&password[2]=='3'&&password[3]=='4'&&password[4]=='5'&&password[5]=='6'&&strlen(password)==6)
    {
        system("cls");

        printf("\t\t     密码正确\n\n\t\t     即将进入请稍等");

        Sleep(1500);
    }
    else
    {
        k++;

        if(k==1)
        {
            printf("\a");

            MessageBoxA(0,"身份验证失败!还有2次机会","warning",0);

            system("cls");

            goto b1;
        }
        else if(k==2)
        {
            printf("\a");

            MessageBoxA(0,"身份验证失败!还有1次机会","warning",0);

            system("cls");

            goto b1;
        }
        if(k==3)
        {
            system("cls");

            printf("\a");

            MessageBoxA(0,"快滚出老子的魔仙堡！！！！","warning",0);

            exit(0);
        }
    }
}
void esc()//退出
{
        system("cls");

        MessageBoxA(0,"感谢使用!","提示",0);

        system("cls");
        printf("                       .::::.\n");
        printf("                    .::::::::.\n");
        printf("                   :::::::::::         再见!\n");
        printf("               ..:::::::::::'\n");
        printf("             '::::::::::::'\n");
        printf("               .::::::::::\n");
        printf("          '::::::::::::::..\n");
        printf("               ..::::::::::::.\n");
        printf("             ``::::::::::::::::\n");
        printf("              ::::``:::::::::'        .:::.\n");
        printf("             ::::'   ':::::'       .::::::::.\n");
        printf("           .::::'      ::::     .:::::::'::::.\n");
        printf("          .:::'       :::::  .:::::::::' ':::::.\n");
        printf("         .::'        :::::.:::::::::'      ':::::.\n");
        printf("        .::'         ::::::::::::::'         ``::::.\n");
        printf("    ...:::           ::::::::::::'              ``::.\n");
        printf("   ````':.          ':::::::::'                  ::::..\n");
        printf("                      '.:::::'                    ':'````..\n");
        exit(0);
}
int main()
{
            student *phead=(student*)malloc((sizeof(student)));//头节点

            student *pend=(student*)malloc((sizeof(student)));//尾节点

            char x[10000];

            pend->next=0;//初始化尾节点

            phead->next=pend;//初始化头节点

            system("color B");

             passward();

    while(1)
    {
        welcome();

        gets(x);

        if(x[0]=='0'||x[0]=='1'||x[0]=='2'||x[0]=='3'||x[0]=='4'||x[0]=='5'||x[0]=='6'||x[0]=='7')
        {
            if(strlen(x)==1)
            {
                switch(x[0])
                {
                case '0':
                    esc();
                    break;//退出

                case '1':
                    add(phead,pend);
                    break;//添加

                case '2':
                    modify(phead,pend);
                    break;//修改

                case '3':
                    deldate(phead,pend);
                    break;//删除

                case '4':
                    findone(phead,pend);
                    break;//查询个人信息;

                case '5':
                    findall(phead,pend);
                    break;//查询全部信息

                case '6':
                    openonce(fp,phead);
                    break;//打开上次保存文件

                case '7':
                    save(fp,phead,pend);
                    break;//保存文件
                }
            }
            else
            {
                system("cls");

                printf("\n\n错误指令!\n\n");

                system("pause");
            }
        }
        else
        {
            system("cls");

            printf("\n\n错误指令!\n\n");

            system("pause");
        }
    }
    return 0;
}
