#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//using namespace std;
int N;

void printmatrix (int **S,int Q,int flag) ///////////////����� �� ����� ��������� �������////////////
{
    int i,j;
    printf("    ");
    for (i=0;i<Q;i+=1)
        printf("   %4d",i+1);
    printf("\n");

    for (i=0;i<Q;i+=1)
    {
        printf("%4d   ",i+1);
        for (j=0;j<Q;j+=1)
        {
            if (flag==1)
                printf("%4d   ",*((int *) S + (i * Q) + j + i));
            else
                printf("%4d   ",*((int *) S + (i * Q) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void printmatrixone(int *P, int Q)///////////////����� �� ����� ���������� �������////////////
{
    int i;
    for (i=0;i<Q;i+=1)
    {
        printf("%4d  ",i+1);
    }
    printf("\n");
    for (i=0;i<Q;i+=1)
    {
        printf("%4d  ",P[i]);
    }
    printf("\n");
}

int maxone(int *P,int Q)///////////////����� ������������� �������� � ���������� �������////////////
{
    int max=P[0];
    int i;
    for (i=1;i<Q;i+=1)
    {
        if (P[i]>max)
            max=P[i];
    }
    return(max);
}

int maxtwo(int *S,int Q, int flag)///////////////����� ������������� �������� � ��������� �������////////////
{
    int max=*((int *) S + (0 * Q) + 0);
    int i,j;
    for (i=0;i<Q;i+=1)
        for (j=0;j<Q;j+=1)
    {
        if (flag==1)
        {
            if ((*((int *) S + (i * Q) + j + i))>max)
                max=*((int *) S + (i * Q) + j + i);
        }
        else
        {
            if ((*((int *) S + (i * Q) + j))>max)
                max=*((int *) S + (i * Q) + j);
        }

    }
    return(max);
}

int zerone (int *S,int Q)
{
    int i;
    for (i=0;i<Q;i+=1)
        if (S[i]!=0) return(0);
    return(1);
}

int poiskravn (int *S,int Q,int y)
{
    int v;
    for (v=0;v<Q;v+=1)
        if (S[v]==y) return (v);
        return (0);
}
int circle (int *S,int Q)
{
    int z,y,sch,save,d,n,lastprihod,lasty;
    int color[Q];
    int prihod[Q];
    int CopyS[Q][Q];
    int put[Q];
    n=0;
    d=0;
    for (z=0;z<Q;z+=1)
        for (y=0;y<Q;y+=1)
        {
            CopyS[z][y]=*((int *) S + (z * Q) + y);
        }
    for (z=0;z<Q;z+=1)
    {
        color[z]=0;
        prihod[z]=-1;
        put[z]=-1;
    }

    prihod[0]=-1;

        for (z=0;z<Q;z+=1)
        {
            save=z;
            d=0;
            //printf("z=%d\n",z+1);
            color[z]=1;
            put[d]=z;
            d+=1;
            loop1:
            for (y=0;y<Q;y+=1)
            {
                n=0;
                if ((CopyS[z][y]!=-1)&&(prihod[z]!=y))
                {
                    if(color[y]==1)
                    {
                        //printf("!!!%d -> %d\n",z+1,y+1);
                        return(1);
                    }
                    else
                    {
                        //printf("%d -> %d\n",z+1,y+1);
                        put[d]=y;
                        d+=1;
                        //printmatrixone(put,Q);
                        prihod[y]=z;
                        color[y]=1;
                        //printmatrixone(color,Q);
                        z=y;
                        n=1;
                        goto loop1;
                    }
                }
                if((y==Q-1)&&((CopyS[z][y]==-1)||(prihod[z]==y)))
                   {
                       //printf("d = %d\n",d);
                        if(d>1)
                       {
                           z=put[poiskravn(put,Q,-1)-2];
                           CopyS[z][put[d-1]]=-1;
                           //printf("udalil [%d][%d]\n",z+1,put[d-1]+1);
                           color[put[d-1]]=0;
                           put[d-1]=-1;
                           d-=1;
                           goto loop1;
                       }
                       else
                        n=1;

                   }
                if (n==1)
                {
                    z=save;
                for (n=0;n<Q;n+=1)
                {
                    color[n]=0;
                }
                }

            }
        }

return (0);
}

int main ()
{
/*
    int tes[7][7] ={
    1,2,3,4,5,6,7,
    8,9,10,11,12,13,14,
    15,16,17,18,19,20,21,
    22,23,24,25,26,27,28,
    29,30,31,32,33,34,35,
    36,37,38,39,40,41,42,
    43,44,45,46,47,48,49};

    printmatrix(tes,7,0);
    printf("%d\n\n",maxtwo(tes,6,1));
*/
    FILE *fp= fopen("start1.txt","r");
    if (fp == NULL)
    {
        printf("\nerror file");getchar();exit(1);
    }

//////////////////////////////////////��������� ������������� ���������� � ��������////////////
    int flag,i,j,Post=0,Potr=0,nado_strelok=0,kolvo_strelok=0;
    int x=0,t=1;
    int s=0;
    j=1;
    printf("Vvedite kolichestvo vershin - ");
    //scanf("%d",&N);
    fscanf(fp,"%d",&N);////TEST
    flag=1;
    printf("%d\n",N);////TEST
    int F[N+1][N+1];
    int FS[N+1][N+1];
    int Pf[N+1];

    for (i=0;i<N+1;i+=1)
        for (j=0;j<N+1;j+=1)
        {
            F[i][j]=0;
            FS[i][j]=-1;
            Pf[i]=0;
        }
     //printmatrix(SS,N);
     //printmatrixone(P,N);
//##############################################################################################//


//////////////////////////////////////���������� ������� ���������///////////////////
    for(i=0;i<N;i+=1)
    {
        printf("S kakimi vershinami soediniaetsa vershina %d(v konce stavim '0')\n",i+1);
        do
        {
            printf(":");
            //scanf("%d", &t);
            fscanf(fp,"%d",&t);////TEST
            printf("%d\n",t);////TEST
            if (t>0)
            {
                x=t-1;
                F[i][x]=1;
                F[x][i]=1;
            }
        }while (t>0);
    }
    printf("\n");
    printmatrix(F,N,flag);
    printf("\n");
//##############################################################################################//


//////////////////////////////////////���������� ������� ��������� ���������///////////////////
    for (i=0;i<N;i+=1)
        for (j=0;j<N;j+=1)
            if ((F[i][j]==1)&&(FS[i][j]==-1)&&(FS[j][i]==-1))
            {
                printf("Stoimost perevozki (%d;%d) = ",i+1,j+1);
                //scanf("%d",&t);
                fscanf(fp,"%d",&t);////TEST
                printf("%d\n",t);////TEST
                FS[i][j]=t;
                FS[j][i]=t;
            }

    printf("\n");
    printmatrix(FS,N,flag);
    printf("\n");
//##############################################################################################//

//////////////////////////////////////���������� ������� �������� ������///////////////////
    for (i=0;i<N;i+=1)
    {
        printf("Moshnosti vershini %d = ",i+1);
        //scanf("%d",&t);
        fscanf(fp,"%d",&t);////TEST
        printf("%d\n",t);////TEST
        Pf[i]=t;
        if (t>0)
        Post+=t;
        else
        Potr+=(t*(-1));
    }
    printf("\n");
    printmatrixone(Pf,N);
    printf("\n\n");
//##############################################################################################//

printf("\n////////////////////////////////////////______OBRABOTKA______/////////////////////////////////////\n\n");
flag=0;

///////////////////////////////////�������� �� ��������/�������� ������, ���� ��������� ���������//////////////////
//////////////////////////////� �������������� ������������ �������� � ����������� �� ���������� ��������//////////
    if (Post>Potr)//���� ����������� ������ �������� ������������
    {
        printf("Model otkritaia, moshnost postavshikov > moshnosti potrebiteley\n");
        printf("Moshnost postavshikov = %d\nmoshnosti potrebiteley = %d\nraznica = %d\n", Post,Potr,Post-Potr);
        printf("Vvedem fiktivnogo potrebitelia, poluchim:\n");

        Pf[N]=((Post-Potr)*(-1));
        for (i=0;i<N+1;i+=1)
        {
            F[i][N]=0;
            F[N][i]=0;
            if (Pf[i]>0)
            {
                F[i][N]=1;
                F[N][i]=1;
            }
        }
        for (i=0;i<N+1;i+=1)
        {
            FS[i][N]=-1;
            FS[N][i]=-1;
            if (F[i][N]==1)
            {
                FS[i][N]=maxtwo(FS,N,1)*5;
                FS[N][i]=FS[i][N];
            }
        }
        N+=1;
        printf("\n");
        printmatrix(F,N,flag);
        printf("\n");
        printf("\n");
        printmatrix(FS,N,flag);
        printf("\n");
        printf("\n");
        printmatrixone(Pf,N);
        printf("\n");
    }
    else
        if (Post<Potr)//���� ������������ ������ �������� �����������
        {
            printf("Model otkritaia, moshnost potrebiteley > moshnosti postavshikov\n");
            printf("Moshnost postavshikov = %d\nmoshnosti potrebiteley = %d\nraznica = %d\n", Post,Potr,Potr-Post);
            printf("Vvedem fiktivnogo postavshika, poluchim:\n");

            Pf[N]=(Potr-Post);
            for (i=0;i<N+1;i+=1)
            {
                F[i][N]=0;
                F[N][i]=0;
                if (Pf[i]<0)
                {
                    F[i][N]=1;
                    F[N][i]=1;
                }
            }
            for (i=0;i<N+1;i+=1)
            {
                FS[i][N]=0;
                FS[N][i]=0;
                if (F[i][N]==1)
                {
                    FS[i][N]=maxtwo(FS,N,1)*5;
                    FS[N][i]=FS[i][N];
                }
            }
            N+=1;
            printf("\n");
            printmatrix(F,N,flag);
            printf("\n");
            printf("\n");
            printmatrix(FS,N,flag);
            printf("\n");
            printf("\n");
            printmatrixone(Pf,N);
            printf("\n");
        }
        else
            if (Post==Potr)//���� ������������ = �������� ����������� (������ ��������)
            {
                printf("Model zakritaya, moshnost potrebiteley = moshnosti postavshikov\n");
                printf("Moshnost postavshikov = %d\nmoshnosti potrebiteley = %d\n", Post,Potr);

                printf("\n");
                printmatrix(F,N,1);
                printf("\n");
                printf("\n");
                printmatrix(FS,N,1);
                printf("\n");
                printf("\n");
                printmatrixone(Pf,N);
                printf("\n");
            }
//##############################################################################################//

///////////////////////////////////�������������� ���� ��������/////////////////////////
    int NachPost[N][N];
    int NachPostTS[N][N];
    int Pfo[N];
    int massa;
    int save;
   // printf("%d\n\n",flag);

    nado_strelok=N-1;
    for (i=0;i<N;i+=1)
    {
        Pfo[i]=Pf[i];
        for (j=0;j<N;j+=1)
        {
            NachPost[i][j]=-1;
            NachPostTS[i][j]=-1;
        }
    }
    do
    {
	    for (i=0;i<N;i+=1)
	        for (j=0;j<N;j+=1)
	        {
	            /*//^^^^^^^^^
	            if(Pf[i]>0)
	            {
	                printf("Proverka puti iz %d v %d :\n",i+1,j+1);
	                if (F[i][j]!=1)
	                    printf("Proverka (F[%d][%d]==1) - OTKAZ  |  ",i+1,j+1);
	                else
	                {
	                        printf("Proverka (F[%d][%d]==1) - PROSHLO  |  ",i+1,j+1);
	                    if (Pfo[i]<0)
	                        printf("Proverka (Pfo[%d]>0) - OTKAZ  |  ",i+1);
	                    else
	                    {
	                            printf("Proverka (Pfo[%d]>0) - PROSHLO  |  ",i+1);
	                        if (Pfo[j]>0)
	                            printf("Proverka (Pfo[%d]<0) - OTKAZ  |  ",j+1);
	                        else
	                        {
	                                printf("Proverka (Pfo[%d]<0) - PROSHLO  |  ",j+1);
	                            if (Pf[i]<0)
	                                printf("Proverka (Pf[%d]>0) - OTKAZ  |  ",i+1);
	                            else
	                            {
	                                    printf("Proverka (Pf[%d]>0) - PROSHLO  |  ",i+1);
	                                if (Pf[j]>0)
	                                    printf("Proverka (Pf[%d]<0) - OTKAZ  |  ",j+1);
	                                else
	                                    printf("Proverka (Pf[%d]<0) - PROSHLO  |  ",j+1);
	                            }
	                        }
	                    }
	                }
	                printf("\n");
	            }
	            else
	            {
	                if (j==0)
	                {
	                    printf("Vershina %d - POTREBITEL",i+1);
	                    printf("\n");
	                    printf("\n");
	                }
	            }*/
	            //^^^^^^^^^^
	            if ((F[i][j]==1)&&(Pfo[i]>0)&&(Pfo[j]<0)&&(Pf[i]>0)&&(Pf[j]<0))
	            {
	                if (Pfo[i]>=abs(Pfo[j]))
	                massa=(abs(Pfo[j]));
	                else
	                massa=Pfo[i];

	                save=NachPost[i][j];
	                NachPost[i][j]=massa;
	                NachPostTS[i][j]=massa;
	                NachPostTS[j][i]=massa;
	                if (circle(NachPostTS,N)==1)
	                {
	                    NachPost[i][j]=save;
	                    NachPostTS[i][j]=save;
	                    NachPostTS[j][i]=save;
	                }
	                else
	                {
	                    Pfo[i]-=massa;
	                    Pfo[j]+=massa;
	                    kolvo_strelok+=1;
	                }
	            }
	        }
    }while (zerone(Pfo,N)==0);

	printf("nach post\n");
	printmatrix(NachPost,N,flag);
	printf("\n");

	for(i=0;i<N;i+=1)
	    for(j=0;j<N;j+=1)
	        if (NachPost[i][j]!=-1)
	        {
	            printf("%d -> %d = %d\n",i+1,j+1,NachPost[i][j]);
	        }

	printf("\n");
	printf("nado strelok = %d\n",nado_strelok);
	printf("kol-vo strelok = %d\n",kolvo_strelok);
	if (nado_strelok!=kolvo_strelok)
	    printf("!!!___Uslove s kol-vom strelok ne vipolniaetsa____!!!  ->  Vvodim nulevuy strelku\n");
	printf("\n");

	printf("\n");
	printmatrixone(Pfo,N);
	printf("\n");


   //NachPostTS[5][6]=3;
   //NachPostTS[6][5]=3;

    printf("poisk - %d\n",circle(NachPostTS,N));
    printf("\n");
	printmatrix(NachPostTS,N,flag);
	printf("\n");




  system("PAUSE");
}
