#include<stdio.h>
#include<string.h>
int stren(int len,char s[]);
void random(int len);
int sum;
int l1,l2,flag=0;
int n=0,i=0;
char a='%',b='^',c='&',d='*',r1,r2;//with their ascii value 37 94 and 38 respectively.

int main()
{
     for(int i=0;i<139;i++){
        printf("*");
    }
    printf("\n");
    printf("\t\t\t\t\t\tW E L C O M E   T O   P A S S W O R D   G E N E R A T O R\n");
    for(int i=0;i<139;i++){
        printf("*");
    }
    printf("\n");
    printf("Please follow the instructions while entering  password :\n");
    printf("\t1. Password must be minimum 8 characters long.\n");
    printf("\t2. Password should only contain alphabets(lowercase or uppercase), digits (0 to 9)\n");
    printf("\t   and special symbols (!,@,#,%c,%c,%c).\n",a,b,c);
    char s[50];
    printf("Please enter the password :\n");
    do{
        i+=l1;
        
    
    scanf("%s",s);
    int len=strlen(s);
    
    if(len<8)
    {
        printf("Password length is below 8\n");
        printf("if you want to try a new password press 1 else press 0\n");
        scanf("%d",&n);
        if(n==0)
        flag=1;
       
    }
    else{
     flag=0;
    
    int strength=stren(len,s);
   
    if(strength>=85)
    {
         printf("Strength of the password you have entered is %d%c\n",strength,a);
        printf("Password accepted\n");
        break ;
    }
    else if(strength>0) {
         printf("Strength of the password you have entered is %d%c\n",strength,a);
       
         random(len);
        printf("if you want your current password to be accepted press 0\n");
        printf("if you want use suggested password press 2\n");
        printf("if you want to try a new password press 1\n");
        scanf("%d",&n);
        
    }
        
    }
    if(n==0&&flag==0)
        printf("Current password accepted\n");
        else if(n==0&&flag==1)
        printf("Program exitted\n");
        else if(n==2)
        printf("Password set to suggested one\n");
        else
        printf("\nEnter a new password:\n");
    }while(n==1);

    return 0;
}
/* a function used for calculating strength of password based on given criteria by traversing through string*/
int stren(int len,char s[])
{
   
    sum=0;
    int p;
  int a[4]={0,0,0,0};
    for(int i=0;i<len;i++)
    {
        sum+=s[i];//storing ascii of characters
        if(s[i]>='a'&&s[i]<='z')
        a[1]++;
        else if(s[i]>='A'&&s[i]<='Z')
        a[0]++;
        else if(s[i]>='0'&&s[i]<='9')
        a[2]++;
        else if(s[i] == 33 || s[i] == 64 || s[i] == 35 || s[i] == 36 ||s[i] == 37||s[i] == 94||s[i] == 38 ||s[i]==42)
        a[3]++;
        else 
        {
            printf("Invalid character into password\n");
            printf("If you want to try again enter 1 else 0 :\n");
            scanf("%d",&n);
            if(n==0)
            flag=1;
            p=0;
            return p;

        }
    }
     if(a[1]==len|| a[0]==len||a[2]==len){
        p=55;
    }
    else if((a[0]!=0 && a[1]!=0&& a[2]==0&& a[3]==0) || (a[0]==0 && a[1]!=0&& a[2]!=0&& a[3]==0) || (a[0]!=0 && a[1]==0&& a[2]==0&& a[3]==0)){
        p=65;
    }
    else if((a[0]!=0&& a[1]!=0&& a[2]!=0 && a[3]==0) || (a[0]==0&& a[1]!=0&& a[2]!=0 && a[3]!=0) || (a[0]!=0&& a[1]==0&& a[2]!=0 && a[3]!=0) || (a[0]!=0&& a[1]!=0&& a[2]==0 && a[3]!=0)){
        p=75;
    }
    else if(a[0]>=3&&a[1]>=3&&a[2]>=3&&a[3]>=3){
        p=100;
    }
    else if(a[0]!=0&& a[1]!=0&& a[2]!=0&& a[3]!=0){
        p=85;
    }
     l1=r1+11;// used for randomization
    l2=r2+sum*i;// used for randomization

   

    return p;
}
/* function for generating random password using concept of choosing random boxes and filling in random elements in each box.
dividing a random number by no. of elements in array will always genrate remainders ranging from  0 to (length of array -1) which is nothing 
but index of elements of arrays*/
void random(int len)
{
    char a[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char b[]="abcdefghijklmnopqrstuvwxyz";
    char c[]="0123456789";
    char d[]="!@#$%^&*";
    char fi[len+1];
    fi[len]='\0';
    int p=l2;
   
    for(int j=l1;j<l1+len;j++)
    {
        l2+=j;
        p=p+3;
        
        if(p%4==0)
        fi[j%len]=a[l2%26];
        else if(p%4==1)
        fi[j%len]=b[l2%26];
        else if(p%4==2)
        fi[j%len]=c[l2%10];
        else
        fi[j%len]=d[l2%8];
    }
    printf("The new suggested password is %s\n",fi);
    printf("Strength of suggested password is %d %c\n",stren(len,fi),'%');

}
