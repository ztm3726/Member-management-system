#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
FILE *fp;

char sex1[3]="��",sex2[3]="Ů";

typedef struct student
{
    char num[20];//ѧ��

    char name[10000];//����

    char sex[10000];//�Ա�

    char call[10000];//�绰����

    char adress[10000];//��ַ

    struct student *next;//ָ����һ���ڵ��ָ��
} student;
void welcome()//������
{
    time_t now;//��ȡ��ǰʱ��

    struct tm *times;

    time(&now);

    times=localtime(&now);

    system("color B");

    system("cls");
    printf("\t\t   _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |  ��ӭ��ʹ��ʵ���ҳ�Ա����ϵͳ |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        %d��%d��%d��           |\n",times->tm_year+1900,times->tm_mon,times->tm_mday);
    printf("\t\t   |                             |\n");
    printf("\t\t  |        1.���ӳ�Ա��Ϣ         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        2.�޸ĳ�Ա��Ϣ         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        3.ɾ����Ա��Ϣ         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        4.��ѯ������Ϣ         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        5.��ѯȫ����Ϣ         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        6.�򿪱����ļ�         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        7.�����Ա��Ϣ         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t  |        0.�˳�����ϵͳ         |\n");
    printf("\t\t   |                             |\n");
    printf("\t\t   -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("\t\t          ������ָ��:(0-6) ");
}
void add(student *phead,student *pend)//���ӳ�Ա
{
    system("cls");

    int i,result;

    student *pnew=(student*)malloc((sizeof(student)));//����һ���½ڵ�,����������

    student *pmove=(student*)malloc(sizeof(student));
a1:
    system("cls");

    printf("\t\t     ������11λѧ��:  ");

    gets(pnew->num);

    for(i=0; i<strlen(pnew->num); i++)
    {
        if(strlen(pnew->num)==11&&pnew->num[i]>='0'&&pnew->num[i]<='9')//�ж������ѧ�ų��ȣ��Ƿ�������
        {
            for(pmove=phead->next; pmove!=pend; pmove=pmove->next) //������������ѧ���Ƿ��Ѿ�����
            {
                if(strcmp(pmove->num,pnew->num)==0)
                {
                    system("cls");

                    result =MessageBox( 0,"ѧ���Ѵ���,�Ƿ���������", "��ʾ", MB_YESNO);

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

        result =MessageBox( 0,"ѧ�Ų��Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
        printf("\t\t     ����������:  ");

        gets(pnew->name);

        for(i=0; i<strlen(pnew->name); i++)
        {
            if(strlen(pnew->name)==4||strlen(pnew->name)==6) //�ж��������������
            {
            }
            else
            {
                system("cls");

                result =MessageBox( 0,"�������Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
        printf("\t\t     �������Ա�:  ");

        gets(pnew->sex);

        for(i=0; i<strlen(pnew->sex); i++)
        {
            if(strlen(pnew->sex)==2) //�ж�������Ա��Ƿ�Ϊ�л�Ů
            {
                if(strcmp(pnew->sex,sex1)==0||strcmp(pnew->sex,sex2)==0)
                {

                }
                else
                {
                    system("cls");

                    result =MessageBox( 0,"�Ա𲻺Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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

                result =MessageBox( 0,"�Ա𲻺Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
    printf("\t\t     ������11λ�绰����:  ");

    gets(pnew->call);

    for(i=0; i<strlen(pnew->call); i++)
    {
        if(strlen(pnew->call)==11&&pnew->call[i]>='0'&&pnew->call[i]<='9') //�ж�����ĵ绰���볤�ȣ��Ƿ�������
        {
        }
        else
        {
            system("cls");

                result =MessageBox( 0,"�绰���벻�Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
    printf("\t\t     �������ͥ��ַ:  ");

    gets(pnew->adress);

    for(i=0; i<strlen(pnew->adress); i++)
    {
        if(strlen(pnew->adress)>=6&&strlen(pnew->adress)<=40) //�ж�����ĵ�ַ����
        {
        }
        else
        {
            system("cls");

                result =MessageBox( 0,"��ͥ��ַ���Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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

    printf("\t\t     ----->��ӳɹ�\n\n\a");

    system("pause");

}
void modify(student *phead,student *pend)//�޸ĳ�Ա��Ϣ
{
    system("cls");

    student *pmove=(student*)malloc((sizeof(student)));

    char mod[100];

    int i,result,n=0;
b1:
    printf("\t\t     ������Ҫ�޸ĳ�Ա��ѧ��:  ");

    gets(mod);

    for(i=0; i<strlen(mod); i++)
    {
        if(strlen(mod)==11&&mod[i]>='0'&&mod[i]<='9')//�ж������ѧ�ų��ȣ��Ƿ�������
        {
            break;
        }
        else
        {
            system("cls");

                result=MessageBox( 0,"ѧ�Ų��Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
            printf("\t\t     ��������������:  ");

            gets(pmove->name);

            for(i=0; i<strlen(pmove->name); i++)
            {
                if(strlen(pmove->name)==4||strlen(pmove->name)==6)
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"�������Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
            printf("\t\t     �����������Ա�:  ");

            gets(pmove->sex);

            for(i=0; i<strlen(pmove->sex); i++)
            {
                if(strlen(pmove->sex)==2)
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"�Ա𲻺Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
            printf("\t\t     ����������11λ�绰����:  ");

            gets(pmove->call);

            for(i=0; i<strlen(pmove->call); i++)
            {
                if(strlen(pmove->call)==11&&pmove->call[i]>='0'&&pmove->call[i]<='9')
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"�绰���벻�Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
            printf("\t\t     �����������ͥ��ַ:  ");

            gets(pmove->adress);

            for(i=0; i<strlen(pmove->adress); i++)
            {
                if(strlen(pmove->adress)>=6&&strlen(pmove->adress)<=40)
                {
                }
                else
                {
                    system("cls");

                result =MessageBox( 0,"��ͥ��ַ���Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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

            printf("\t\t     ----->�޸ĳɹ�!\a\n\n");

            break;
        }
    }
    if(n!=1)
    {
        system("cls");

        printf("\n\n\t\t     ----->û�������Ա����Ϣ!\n\n");
    }
    pmove=NULL;

    system("pause");
}
void deldate(student *phead,student *pend)//ɾ����Ա
{
    system("cls");

    student *pdel=(student*)malloc((sizeof(student)));

    student *pmove=(student*)malloc((sizeof(student)));

    char del[100];

    int n=0,i,result;
d1:
    printf("\t\t     ������Ҫɾ����Ա��ѧ��:  ");

    gets(del);

    for(i=0; i<strlen(del); i++)
    {
        if(strlen(del)==11&&del[i]>='0'&&del[i]<='9')//�ж������ѧ�ų��ȣ��Ƿ�������
        {
            break;
        }
        else
        {
            system("cls");

                result=MessageBox( 0,"ѧ�Ų��Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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
    for(pdel=phead;pdel!=pend; )// �ӽڵ㿪ʼ��������β�ڵ����
    {
        pmove=pdel;//Ȼpdel��ָ��ָ����pmove��ͬ

        pdel=pdel->next;//pdelָ����һ���ڵ�

        if(strcmp(pdel->num,del)==0)
        {
            n=1;

            pmove->next=pdel->next;//pdel����һ���ڵ�λ�ø����ϸ��ڵ㣬����pdelָ��Ľڵ����

            printf("\n\t\t     ------>ɾ���ɹ�!\n\n\a");

            free(pdel);//ɾ��pdelָ��Ľڵ�
        }
    }
    if(n!=1)
    {
        printf("\n\n\t\t     ------>û�������Ա����Ϣ!\n\n");
    }
    pmove=NULL;

    system("pause");
}
void findall(student *phead,student *pend)//�������г�Ա
{
    system("cls");

    int n=0;

    student *pmove=(student*)malloc(sizeof(student));

    printf("ѧ��:\t\t����:\t�Ա�:\t�绰����:\t��ͥ��ַ:\n");

    for(pmove=phead->next; pmove!=pend; pmove=pmove->next)
    {
        n++;

        printf("\n%s\t%s\t%s\t%s\t%s\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
    }
    pmove=NULL;

    printf("\nʵ���ҹ���%d��\n\n",n);

    system("pause");
}
void findone(student* phead,student* pend)//���Ҹ�����Ϣ
{
    system("cls");

    char find[100],number[100],clsone;

    int x,i,result,n=0;

    student *pmove=(student*)malloc(sizeof(student));

    printf("\t\t     ��1ѧ�Ų��� / ��2��������\n\n\t\t     ");

    scanf("%d",&x);

    system("cls");

    if(x==1)
    {c1:
        printf("\t\t     ��������ҳ�Ա��ѧ��:  \n\n\t\t     ");

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

                result =MessageBox( 0,"ѧ�Ų��Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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

                printf("��ѯ�������\n\nѧ��:\t\t����:\t�Ա�:\t�绰����:\t��ͥ��ַ:\n\n");

                printf("%s\t%s\t%s\t%s\t%s\n\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
            }
        }
        if(n!=1)
            {
                printf("\n\n\t\t     ------>û�������Ա����Ϣ!\n\n");
            }
    }
    else if(x==2)
    {c2:
        printf("\t\t     ��������ҳ�Ա������:  \n\n\t\t     ");

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

                    result =MessageBox( 0,"�������Ϸ�,�Ƿ���������", "��ʾ", MB_YESNO);

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

                printf("��ѯ�������\n\nѧ��:\t\t����:\t�Ա�:\t�绰����:\t��ͥ��ַ:\n\n");

                printf("%s\t%s\t%s\t%s\t%s\n\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
            }
        }

        if(n!=1)
        {
            printf("\n\n\t\t     ------>û�������Ա����Ϣ!\n\n");
        }
    }
    else
    {
        printf("\n\n\t\t     ��������!\n");
    }
    printf("\n");

    system("pause");

    pmove=NULL;
}
void openonce(FILE *fp,student *phead)//���ļ�
{
    system("cls");

    if((fp=fopen("text.txt","r"))==NULL)
    {
        printf("\n\n\t\t     ���ļ�ʧ��,�����ļ�����\n\n");//�ж��ļ��Ƿ����

        system("pause");

        return ;
    }
    while(1)
    {
        student *pmove=(student*)malloc(sizeof(student));

        if(fscanf(fp,"%s%s%s%s%s",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress)!=EOF)//ѭ�������ڵ㣬���ж��Ƿ��ļ���β�����ǽ�β��д������
        {
        pmove->next=phead->next;//ͷ�巨����

        phead->next=pmove;
        }
        else//���ļ���β���˳�
        {
            break;
        }
    }
    fclose(fp);

    printf("\n\n\t\t     ��ȡ�ļ��ɹ�\n\n");

    system("pause");
}
void save(FILE *fp,student *phead,student *pend)//�����ļ�
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

        for(pmove=phead->next; pmove!=pend; pmove=pmove->next)//��ÿ���ڵ�д���ļ�
        {
            fprintf(fp,"%s\t%s\t%s\t%s\t%s\n\n",pmove->num,pmove->name,pmove->sex,pmove->call,pmove->adress);
        }
    }
    fclose(fp);

    if(k==1)
    {
        printf("\n\n\t\t     û�г�Ա��Ϣ���Ա���\n\n");
    }
    if(k!=1)
    {
        printf("\n\n\t\t     �ļ��ɹ�����(�ɽ����Ŀ¼��ѯ)\n\n");
    }
    system("pause");
}
void passward()//����
{
     int i,k=0,n,p;

    char ch,password[20]={0};

    system("color B");
b1:
    i=0;n=0;p=0;

    printf("\t\t     �����֤\n\n");

    printf("\t\t     ����:");

    while((ch=getch())!='\r')  //������̨û������س�
        {
                if(ch!='\b')      //������̨û�������˸��
                {
                        printf("*");

                        password[i]=ch;

                        i++;

                        p=i;
                }
                else
                {
                        printf("\b \b");   //�޸ĸղ����������

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

        printf("\t\t     ������ȷ\n\n\t\t     �����������Ե�");

        Sleep(1500);
    }
    else
    {
        k++;

        if(k==1)
        {
            printf("\a");

            MessageBoxA(0,"�����֤ʧ��!����2�λ���","warning",0);

            system("cls");

            goto b1;
        }
        else if(k==2)
        {
            printf("\a");

            MessageBoxA(0,"�����֤ʧ��!����1�λ���","warning",0);

            system("cls");

            goto b1;
        }
        if(k==3)
        {
            system("cls");

            printf("\a");

            MessageBoxA(0,"��������ӵ�ħ�ɱ���������","warning",0);

            exit(0);
        }
    }
}
void esc()//�˳�
{
        system("cls");

        MessageBoxA(0,"��лʹ��!","��ʾ",0);

        system("cls");
        printf("                       .::::.\n");
        printf("                    .::::::::.\n");
        printf("                   :::::::::::         �ټ�!\n");
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
            student *phead=(student*)malloc((sizeof(student)));//ͷ�ڵ�

            student *pend=(student*)malloc((sizeof(student)));//β�ڵ�

            char x[10000];

            pend->next=0;//��ʼ��β�ڵ�

            phead->next=pend;//��ʼ��ͷ�ڵ�

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
                    break;//�˳�

                case '1':
                    add(phead,pend);
                    break;//���

                case '2':
                    modify(phead,pend);
                    break;//�޸�

                case '3':
                    deldate(phead,pend);
                    break;//ɾ��

                case '4':
                    findone(phead,pend);
                    break;//��ѯ������Ϣ;

                case '5':
                    findall(phead,pend);
                    break;//��ѯȫ����Ϣ

                case '6':
                    openonce(fp,phead);
                    break;//���ϴα����ļ�

                case '7':
                    save(fp,phead,pend);
                    break;//�����ļ�
                }
            }
            else
            {
                system("cls");

                printf("\n\n����ָ��!\n\n");

                system("pause");
            }
        }
        else
        {
            system("cls");

            printf("\n\n����ָ��!\n\n");

            system("pause");
        }
    }
    return 0;
}
