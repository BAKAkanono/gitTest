#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct tongxinlu
{   int xuehao[10];
    char xinming[40];
    char xinbie[5];
    int dianhua[11];
    char dizhi[200];
} txl[100];
int n = 0;
FILE*fp;
void zhucaidan();
void zengjia();
void duru();
void xieru();
void chaozao();
void chaozao_xuehao();
void chaozao_dianhuamowei();
void shanchu();
void shanchu_quanbu();
void xianshi();
void shanchu_dange();
void shanchu_xuehao();
void shanchu_dianhua();
void duqu();
int main()
{
    duru();
    while(1)
    {
        zhucaidan();
            }
    return 0;

}
void duru()
{
    if((fp=fopen("txl.txt","r"))==NULL)
    {
        printf("\n\t\t  通讯录文件不存在");
        if ((fp=fopen("txl.txt","w"))==NULL)
        {
            printf("\n\t建立失败");
            exit(0);
        }
        else
        {
            printf("\n\t----------------欢迎使用通讯录管理系统------------------\n");
            printf("\n\t   通讯录文件已建立  ");
            printf("\n\t    按任意键进入主菜单");
            getch();
            return;
        }
        exit(0);
    }
    fseek(fp,0,2);
    if(ftell(fp)>0)
    {
        rewind(fp);
        for (n = 0;!feof(fp)&&fread(&txl[n],sizeof(struct tongxinlu),1,fp);n++);
        printf("\n\t欢迎使用第0代通讯录");
        printf("\n\t   文件导入成功");
        printf("\n\t    按任意键返回菜单");
        getch();
        return;
    }
    printf("\n\t      欢迎使用第0代通讯录");
    printf("\n\t     文件导入成功");
    printf("\n\t     文件内无任何记录");
    printf("\n\t     按任意键返回主菜单");
    getch();
    return;
}
void zhucaidan()
{
    char c;
    system("cls");
    printf("\n\t\t|------- 欢迎使用第0代通讯录 -----|");
    printf("\n\t\t|         1-添加联系人    2-查询和显示联系人     |");
    printf("\n\t\t|         3-删除联系人    5-读取联系人");
    printf("\n\t\t|         4-保存退出      0-不保存退出           |");
    printf("\n\t\t|------------------------------------------------|");
    printf("\n\t\t请选择您所所要的服务：");
    c=getch();
    switch(c)
    {
    case'1':
        zengjia();
        break;
    case'2':
        chaozao();
        break;
    case'3':
        shanchu();
        break;
    case'4':
        xieru();
        break;
    case'5':
        duqu();
    case'0':
        exit(0);
    default:
        zhucaidan();
    }
}
void zengjia()
{
    printf("\n\t请输入联系人信息");
    printf("\n\t请输入联系人姓名");
    scanf("%s",txl[n].xinming);
    printf("\n\t请输入联系人学号");
    scanf("%s",txl[n].xuehao);
    printf("\n\t 请输入联系人性别");
    scanf("%s",txl[n].xinbie);
    printf("\n\t 请输入联系人电话");
    scanf("%s",txl[n].dianhua);
    printf("\n\t 请输入联系人地址");
    scanf("%s",txl[n].dizhi);
    n++;
    printf("\n\t\t是否继续添加联系人?(Y/N):");
    if (getch()=='y')
        zengjia();
    return;
}
void xieru()
{
    int i;
    if ((fp=fopen("txl.txt","w"))==NULL)
    {
        printf("\n\t\t文件打开失败");
    }
    for (i = 0;i<n;i++)
    {
         if (fwrite(&txl[i],sizeof(struct tongxinlu),1,fp)!=1)
        {
            printf("\n\t\t写入文件错误!\n");
        }
    }
      fclose(fp);
      printf("\n\t------------------------------------------------------"); /*输出提示信息*/
    printf("\n\t\t通讯录文件已保存");
    printf("\n\t\t谢谢使用，欢迎再次使用!\n");
    printf("如果对本软件有疑问,请给我们提出您的问题,我们将为您解答.\n");
    printf("我们的软件有不足之处,请与我们反映，我们将努力改正!");
    printf("\n\t\t按任意键退出程序\n\t\t");
    exit(0);
}
void chaozao()
{
    char c;
    system("cls");
    printf("\n\t\t------------------- 显示和查询联系人 ------------------");
    printf("\n\t\t|        1-逐个显示所有          2-按学号查询         |");
    printf("\n\t\t|        3-按电话末尾查询            4-返回主菜单         |");
    printf("\n\t\t|------------------------------------------------------");
    printf("\n\t\t请选择您所所要的服务：");
    c=getch();
    switch (c)
    {
     case '1':
        xianshi();
        break;
     case '2':
        chaozao_xuehao();
        break;
    case '3':
        chaozao_dianhuamowei();
        break;
    case '4':
        zhucaidan();
        break;
    }
}

void xianshi()
{
    int i;
    system("cls");
    if(n!=0)
    {
        printf("\n\t\t----------欢迎您查询通讯录所有联系人信息-------------");
        for (i=0;i<n;i++)
        {
            printf("\n\t\t姓名： %s",txl[i].xinming);
            printf("\n\t\t学号： %s",txl[i].xuehao);
            printf("\n\t\t性别： %s",txl[i].xinbie);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址   %s",txl[i].dizhi);
            if(i+1<n)
            {
                printf("wrong");
                system("pause");
            }
        }
        printf("\n\t\t-----------------------------------");
    }
     else                                  /*无联系人*/
        printf("\n\t\t通讯录中无任何纪录");
    printf("\n\t\t按任意键返回主菜单：");
    getch();
    return;
}
void chaozao_dianhuamowei()
{
    int mark = 0;
    int i;
    char phonemowei[20];
    printf("\n\t\t------------------- 按电话末尾查找 -------------------------");
    printf("\n\t\t请输入电话号码末尾:");
    scanf("%s",phonemowei);
    for(i=0;i<n;i++)
    {
        if(strcmp(txl[i].dianhua,phonemowei)==0)
        {
            printf("\n\t\t------------ 以下是您查找的学生信息 ------------");
            printf("\n\t\t姓名： %s",txl[i].xinming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t性别： %s",txl[i].xinbie);
            printf("\n\t\t学号:  %s",txl[i].xuehao);
            printf("\n\t\t------------------------------------------------");
            printf("\n\t\t按任意键返回主菜单：");
            mark++;
            getch();
            return;
        }
    }
    if (mark==0)
    {
        printf("\n\t 没有找到联系人");
        printf("\n\t  按任意键返回主菜单");
        getch();
        return;
    }
}
void chaozao_xuehao()
{
    int mark = 0;
    int i ;
    char xuehao[20];
    printf("\n\t\t----------------按学号查找 --------------------");
    printf("\n\t\t请输入您要查找的学号:");
    scanf("%s",xuehao);
    for(i= 0;i<n;i++)
    {
        if(strcmp(txl[i].xuehao,xuehao)==0)
        {
          printf("\n\t\t------------ 以下是您查找的学生信息 ------------");
            printf("\n\t\t姓名： %s",txl[i].xinming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t性别： %s",txl[i].xinbie);
            printf("\n\t\t学号:  %s",txl[i].xuehao);
            printf("\n\t\t------------------------------------------------");
            printf("\n\t\t按任意键返回主菜单：");
            mark++;
            getch();
            return;
        }
    }
    if (mark==0)
    {
        printf("\n\t 没有找到联系人");
        printf("\n\t  按任意键返回主菜单");
        getch();
        return;
    }
}
void shanchu()
{
    char c;
    if(n==0)
    {
        printf("\n\t\t对不起，文件中无任何纪录");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        return;
    }
    system("cls");
    printf("\n\t\t-----------------  删除菜单 ----------------------");
    printf("\n\t\t|           1-删除所有 2-删除单个                |");
    printf("\n\t\t|                3-返回主菜单                    |");
    printf("\n\t\t|-------------------------------------------------");
    printf("\n\t\t请选择您所所要的服务：");
    c=getch();
    switch (c)
    {
    case '1':
        shanchu_quanbu();
        break;
    case '2':
        shanchu_dange();
        break;
    case '3':
        zhucaidan();
        break;
    default:
        zhucaidan();
        break;
    }
}
void shanchu_quanbu()
{
    printf("\n\t\t确认删除?(y/n)");
    if (getch()=='y')
    {
        fclose(fp);
        if ((fp=fopen("txl.txt","w"))==NULL)
        {
            printf("\n\t\t不能打开文件，删除失败");
            duru();
        }
        n=0;
        printf("\n\t\t纪录已删除，按任意键返回主菜单");
        getch();
        return;
    }
    else
        return;
}
void shanchu_dange()
{
    char c;
    printf("\n\t----------------------------------------------------------");
    printf("\n\t\t   1-按学号删除    2-按电话删除");
    printf("\n\t\t请选择您所所要的服务：");
    printf("\n\t----------------------------------------------------------");
    c=getch();
    switch (c)
    {
    case '1':
        shanchu_xuehao();
        break;
    case '2':
        shanchu_dianhua();
        break;
    }
}
void shanchu_dianhua()
{
    int i,m,mark=0;
    char phone[20];
    printf("\n\t\t请输入要删除联系人电话号码：");
    scanf("%s",phone);
    if(n==0)
    {
        printf("\n\t\t对不起，文件中无任何纪录");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        return;
    }
    for (i=0; i<n; i++)
    {
        if (strcmp(txl[i].dianhua,phone)==0)
        {
            printf("\n\t\t以下是您要删除的联系人纪录：");
            printf("\n\t\t--------------------------------");
            printf("\n\t\t姓名： %s",txl[i].xinming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t学号：  %s",txl[i].xuehao);
            printf("\n\t\t性别：  %s",txl[i].xinbie);
            printf("\n\t\t--------------------------------");
            printf("\n\t\t是否删除?(y/n)");
            if (getch()=='y')
            {
                for (m=i; m<n-1; m++)
                    txl[m]=txl[m+1];
                n--;
                mark++;
                printf("\n\t\t删除成功");
                printf("\n\t\t是否继续删除?(y/n)");
                if (getch()=='y')
                    shanchu_dianhua();
                return;
            }
            else
                return;
        }
        continue;

    }
    if (mark==0)
    {
        printf("\n\t\t没有该联系人的纪录");
        printf("\n\t\t是否继续删除?(y/n)");
        if (getch()=='y')
            return ;
    }
}
void shanchu_xuehao()
{
    int i,m,mark=0,a=0;
    char xuehao[20];
    printf("\n\t\t请输入要删除联系人学号：");
    scanf("%s",xuehao);
    for (i=a; i<n; i++)
    {
        if (strcmp(txl[i].xuehao,xuehao) == 0)
        {
            printf("\n\t\t以下是您要删除的联系人纪录：");
            printf("\n\t\t--------------------------------");
            printf("\n\t\t姓名： %s",txl[i].xinming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t学号：  %s",txl[i].xuehao);
            printf("\n\t\t性别：  %s",txl[i].xinbie);
            printf("\n\t\t--------------------------------");
            printf("\n\t\t是否删除?(y/n)");
            if (getch()=='y')
            {
                for (m=i; m<n-1; m++)
                    txl[m]=txl[m+1];
                n--;
                mark++;
                printf("\n\t\t删除成功");
                printf("\n\t\t是否继续删除?(y/n)");
                if (getch()=='y')
                    shanchu_xuehao();
                return;
            }
            else
                return;
        }
        continue;
    }
    if (mark==0)
    {
        printf("\n\t\t没有该联系人的纪录");
        printf("\n\t\t是否继续删除?(y/n)");
        if (getch()=='y')
            shanchu_xuehao();
        return;
    }
  void duqu()
{
    struct tongxinlu txl1[100];
    fp=fopen("txl.txt","w+");
    rewind(fp);
    fread(&txl1,sizeof(txl1),2,fp);
    printf("\n\t\t------------ 以下是您查找的学生信息 ------------");
            printf("\n\t\t姓名： %s",txl[i].xinming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t性别： %s",txl[i].xinbie);
            printf("\n\t\t学号:  %s",txl[i].xuehao);
            printf("\n\t\t------------------------------------------------");
            fclose(fp);
            return;
}
}
