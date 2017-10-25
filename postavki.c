#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//using namespace std;
int N;
 Probel=" ";

void printmatrix (int **S,int Q,int flag) ///////////////Вывод на экран двумерной матрицы////////////
{
    int i,j;

    printf("     |                                    ");
    for (i=0;i<Q;i+=1)
        printf("  %5d",i+1);
    printf("\n");

    for (i=0;i<Q;i+=1)
    {
        if (i==Q-1)
        printf("     ------------------------------>   %4d  ",i+1);
        else
        printf("     |                                 %4d  ",i+1);
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
void printmatrixone(int *P, int Q)///////////////Вывод на экран одномерной матрицы////////////
{
    int i;

    printf("     |                                ");
    for (i=0;i<Q;i+=1)
    {
        printf("%4d  ",i+1);
    }

    printf("\n");
    printf("     ------------------------------>  ");

    for (i=0;i<Q;i+=1)
    {
        printf("%4d  ",P[i]);
    }
    printf("\n");
}
int maxone(int *P,int Q)///////////////Поиск максимального значения в одномерной матрице////////////
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
int maxtwo(int *S,int Q, int flag)///////////////Поиск максимального значения в двумерной матрице////////////
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
int mmax(int a,int b)
{
    if (a>=b)
        return(a);
    else return(b);
}
int mmin(int a,int b)
{
    if (a<b)
        return(a);
    else return(b);
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
        return (-1);
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
            //printf("z=%d\n",z+1);//
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
                        //printf("!!!%d -> %d\n",z+1,y+1);//
                        return(1);
                    }
                    else
                    {
                        //printf("%d -> %d\n",z+1,y+1);//
                        put[d]=y;
                        d+=1;
                        //printmatrixone(put,Q);//
                        prihod[y]=z;
                        color[y]=1;
                        //printmatrixone(color,Q);//
                        z=y;
                        n=1;
                        goto loop1;
                    }
                }
                if((y==Q-1)&&((CopyS[z][y]==-1)||(prihod[z]==y)))
                   {
                      //printf("d = %d\n",d);//
                        if(d>1)
                       {
                           z=poiskravn(put,Q,-1);
                           if (z==-1){z=Q-1;}else{z=z-2;}
                           z=put[z];
                           CopyS[z][put[d-1]]=-1;
                           //printf("udalil [%d][%d]\n",z+1,put[d-1]+1);//
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
//printf("\ncircle - ok\n");
return (0);
}
void vadimtupoi()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("      *****************************************************\n");
    printf("      *                   Vadim is stupid.                *\n");
    printf("      *                                                   *\n");
    printf("      *                                                   *\n");
    printf("      *       I am a program can't do this exercise(      *\n");
    printf("      *                                                   *\n");
    printf("      *                                                   *\n");
    printf("      *  During operation, the program is looping route   *\n");
    printf("      *****************************************************\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
}
void vadimtupoistrelki()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("      *****************************************************\n");
    printf("      *                   Vadim is stupid.                *\n");
    printf("      *                                                   *\n");
    printf("      *                                                   *\n");
    printf("      *       I am a program can't do this exercise(      *\n");
    printf("      *                                                   *\n");
    printf("      *                                                   *\n");
    printf("      * During operation, the number of arrows more then  *\n");
    printf("      *    it should be. I can't do anything about it.    *\n");
    printf("      *****************************************************\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
}
void vadimtupoipotenc()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("      *****************************************************\n");
    printf("      *                   Vadim is stupid.                *\n");
    printf("      *                                                   *\n");
    printf("      *                                                   *\n");
    printf("      *       I am a program can't do this exercise(      *\n");
    printf("      *                                                   *\n");
    printf("      *                                                   *\n");
    printf("      *         Failed to calculate the potentials        *\n");
    printf("      *                  of the vertices                  *\n");
    printf("      *****************************************************\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
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
    FILE *fp= fopen("start.txt","r");
    if (fp == NULL)
    {
        printf("\nerror file");getchar();exit(1);
    }
//////////////////////////////////////Начальная инициализация переменных и массивов////////////
    int flag,i,j,y,sh,Post=0,Potr=0,nado_strelok=0,kolvo_strelok=0;
    int x=0,t=1;
    int s=0;
    int NOut=0;
    j=1;
    printf("Enter the number of vertices - ");
    //scanf("%d",&N);
    fscanf(fp,"%d",&N);////TEST
    flag=1;
    printf("%d\n",N);////TEST
    NOut=N;
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

//////////////////////////////////////Заполнение массива смежности///////////////////
    for(i=0;i<N;i+=1)
    {
        printf("With some vertices connected vertex %d(At the end of the input press '0')\n",i+1);
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
    printf("\n\n");
    printf("[The matrix of connections:]\n");
    printmatrix(F,N,flag);
    printf("\n");
//##############################################################################################//


//////////////////////////////////////Заполнение массива стоимости перевозок///////////////////
    for (i=0;i<N;i+=1)
        for (j=0;j<N;j+=1)
            if ((F[i][j]==1)&&(FS[i][j]==-1)&&(FS[j][i]==-1))
            {
                printf("The cost of transportation (%d;%d) = ",i+1,j+1);
                //scanf("%d",&t);
                fscanf(fp,"%d",&t);////TEST
                printf("%d\n",t);////TEST
                FS[i][j]=t;
                FS[j][i]=t;
            }

    printf("\n\n");
    printf("[The matrix of transportation costs:]\n");
    printmatrix(FS,N,flag);
    printf("\n");
//##############################################################################################//

//////////////////////////////////////Заполнение массива мощности вершин///////////////////
    for (i=0;i<N;i+=1)
    {
        printf("The power of a vertex %d = ",i+1);
        //scanf("%d",&t);
        fscanf(fp,"%d",&t);////TEST
        printf("%d\n",t);////TEST
        Pf[i]=t;
        if (t>0)
        Post+=t;
        else
        Potr+=(t*(-1));
    }
    printf("\n\n");
    printf("[The matrix of power:]\n");
    printmatrixone(Pf,N);
    printf("\n\n");
//##############################################################################################//
// printf("N=%d\n",N);
printf("\n\n              ////////////////////////////////////////______DATA PROCESSING______/////////////////////////////////////\n\n");
flag=0;

///////////////////////////////////Проверка на открытую/закрытую модель, ввод фиктивных элементов//////////////////
//////////////////////////////и преобразование получившихся массивов в зависимости от фиктивного элемента//////////
    if (Post>Potr)//мощь поставщиков больше мощности потребителей
    {
        printf("The model is open, the power of suppliers > power of consumers\n");
        printf("Power of suppliers = %d\nPower of consumers = %d\nInequality = %d\n", Post,Potr,Post-Potr);
        printf("Enter fictitious consumer, turn:\n");

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
        printf("\n\n");
        printf("[The matrix of connections:]\n");
        printmatrix(F,N,flag);
        printf("\n");
        printf("\n\n");
        printf("[The matrix of transportation costs:]\n");
        printmatrix(FS,N,flag);
        printf("\n");
        printf("\n\n");
        printf("[The matrix of power:]\n");
        printmatrixone(Pf,N);
        printf("\n");
    }
    else
        if (Post<Potr)//мощь потребителей больше мощности поставщиков
        {
            printf("The model is open, the power of suppliers < power of consumers\n");
            printf("Power of suppliers = %d\nPower of consumers = %d\nInequality = %d\n", Post,Potr,Potr-Post);
            printf("Enter fictitious supplier, turn:\n");

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
            printf("\n\n");
            printf("[The matrix of connections:]\n");
            printmatrix(F,N,flag);
            printf("\n");
            printf("\n\n");
            printf("[The matrix of transportation costs:]\n");
            printmatrix(FS,N,flag);
            printf("\n");
            printf("\n\n");
            printf("[The matrix of power:]\n");
            printmatrixone(Pf,N);
            printf("\n");
        }
        else
            if (Post==Potr)//мощь потребителей = мощности поставщиков (модель закрытая)
            {
                printf("The model is closed, the power of suppliers = power of consumers\n");
                printf("Power of suppliers = %d\nPower of consumers = %d\n", Post,Potr);

                printf("\n\n");
                printf("[The matrix of connections:]\n");
                printmatrix(F,N,1);
                printf("\n");
                printf("\n\n");
                printf("[The matrix of transportation costs:]\n");
                printmatrix(FS,N,1);
                printf("\n");
                printf("\n\n");
                printf("[The matrix of power:]\n");
                printmatrixone(Pf,N);
                printf("\n");
            }
//##############################################################################################//

///////////////////////////////////Первоначальный план поставок/////////////////////////
    int NachPost[N][N];
    int NachPostTS[N][N];
    int Pfo[N];
    int massa;
    int save;
    int mintomax[N];
    int kolvocontactov[N];
    sh=0;
   // printf("%d\n\n",flag);

    nado_strelok=N-1;
    for (i=0;i<N;i+=1)
    {
        Pfo[i]=Pf[i];
        mintomax[i]=i;
        kolvocontactov[i]=0;
        for (j=0;j<N;j+=1)
        {
            NachPost[i][j]=-1;
            NachPostTS[i][j]=-1;
        }
    }
   // printf("N=%d\n",N);

    for(j=0;j<N;j+=1)
        for (i=0;i<N;i+=1)
        {
            if(F[i][j]==1)
            {
                kolvocontactov[i]+=1;
            }
        }
printmatrixone(kolvocontactov,N);
    for(j=0;j<N;j+=1)
        for (i=0;i<N-1;i+=1)
        {
            if(kolvocontactov[mintomax[i]]>kolvocontactov[mintomax[i+1]])
            {
                save=mintomax[i];
                mintomax[i]=mintomax[i+1];
                mintomax[i+1]=save;
            }
        }

    printf("\n\n\n                        ///////////////////////______INITIAL SUPPLY PLAN______///////////////////////\n");
///////////////////////////////////Прокладываем первоначальный план поставок/////////////////////////
    do
    {
	    for (i=0;i<N;i+=1)
	        for (j=0;j<N;j+=1)
	        {
	            save=j;
	            j=mintomax[save];
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
	                    printf("_______Ne pustil %d->%d",i+1,j+1);
	                }
	                else
	                {
	                    Pfo[i]-=massa;
	                    Pfo[j]+=massa;
	                    kolvo_strelok+=1;
	                }
	            }
	            j=save;
	        }

    }while (zerone(Pfo,N)==0);
//##############################################################################################//
	printf("\n\n");
    printf("[The matrix of the initial supply plan:]\n");
	printmatrix(NachPost,N,flag);
	printf("\n");

	for(i=0;i<N;i+=1)
	    for(j=0;j<N;j+=1)
	        if (NachPost[i][j]!=-1)
	        {
	            printf("%d -> %d = %d\n",i+1,j+1,NachPost[i][j]);
	        }

	printf("\n\n");
    printf("[The matrix of left power:]\n");
	printmatrixone(Pfo,N);
	printf("\n");


	printf("\n");
	printf("the required number of arrows = %d\n",nado_strelok);
	printf("the number of arrows = %d\n",kolvo_strelok);
	if (nado_strelok>kolvo_strelok)
	    printf("!!!___Rule the number of pointers is not performed____!!!  ->  Enter zero arrow\n");
	printf("\n");
	if (nado_strelok<kolvo_strelok)
	    {
	        vadimtupoistrelki();
	        return(0);
	    }

/*// Тест провепрки на замкнутость маршрута
   //NachPostTS[5][6]=3;
   //NachPostTS[6][5]=3;
   //NachPostTS[0][9]=1000;
   //NachPostTS[8][6]=100;
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@poisk - %d\n",circle(NachPostTS,N));
*/
///////////////////////////////////Прокладываем нулевую стрелку по необходимости/////////////////////////
//NachPostTS[0][9]=100;
    if (nado_strelok!=kolvo_strelok)
    {
        y=0;
        do
        {
            for (i=0;i<N;i+=1)
                {
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
                        if ((F[i][j]==1)&&(Pf[i]>0)&&(Pf[j]<0)&&(NachPostTS[i][j]==-1))
                        {
                            massa=0;

                            save=NachPost[i][j];
                            NachPost[i][j]=massa;
                            NachPostTS[i][j]=massa;
                            NachPostTS[j][i]=massa;
                            if (circle(NachPostTS,N)==1)
                            {
                                NachPost[i][j]=save;
                                NachPostTS[i][j]=save;
                                NachPostTS[j][i]=save;
                                //printf("_______Ne pustil %d->%d\n",i+1,j+1);//
                            }
                            else
                            {
                                Pfo[i]-=massa;
                                Pfo[j]+=massa;
                                kolvo_strelok+=1;
                                //printf("***********pustil %d->%d\n",i+1,j+1);//
                                //printf("kolvo_strelok = %d\n",kolvo_strelok);//
                                break;
                            }
                        }
                    }
                    if (kolvo_strelok==nado_strelok) break;
                }
                if (kolvo_strelok==nado_strelok) break;
                y+=1;
                if (y==3) {vadimtupoi(); return(0);}
        }while (kolvo_strelok!=nado_strelok);
//##############################################################################################//
        printf("\n\n");
        printf("[The new matrix of the initial supply plan]\n");
        printf("            [with zero arrow:]\n");
        printmatrix(NachPost,N,flag);
        printf("\n");
        for(i=0;i<N;i+=1)
            for(j=0;j<N;j+=1)
                if (NachPost[i][j]!=-1)
                {
                    printf("%d -> %d = %d\n",i+1,j+1,NachPost[i][j]);
                }
        printf("\n");
        printf("the required number of arrows = %d\n",nado_strelok);
        printf("the number of arrows = %d\n\n",kolvo_strelok);
    }


    loop11:
    printf("\n\n                   ///////////////////////______CHECK THE SUPPLY PLAN ON THE OPTIMALITY______///////////////////////\n");
    printf("                       /////////////______the calculation of the potentials of the vertices______///////////\n\n");
    //NachPost[0][9]=-1;
    //NachPostTS[0][9]=-1;
    //NachPostTS[9][0]=-1;
    int potenc[N];
    int haractr[N][N];
    int haractrest[N][N];
    int potest[N];
    int puut[N];
    int sv,p,z,fl;
    p=0;
    fl=1;
    for (i=0;i<N;i+=1)
    {
        potenc[i]=0;
        potest[i]=0;
        puut[i]=-1;
        for (j=0;j<N;j+=1)
        {
            haractr[i][j]=0;
            haractrest[i][j]=0;
        }
    }

    for (i=0;i<N;i+=1)
    {
        puut[p]=i;
        p+=1;
        loop2:
        if (puut[0]==-1)
        {
            puut[0]=i;
            p=1;
        }
        for (j=0;j<N;j+=1)
        {
            if(potest[i]==0)
            {
                if(NachPostTS[i][j]!=-1)
                {
                    if(potest[j]==1)
                    {
                        if(NachPost[j][i]!=-1)
                        {
                            potenc[i]=potenc[j]+FS[i][j];
                            potest[i]=1;
                        }
                        else
                        {
                            potenc[i]=potenc[j]-FS[i][j];
                            potest[i]=1;
                        }
                    }
                    fl=1;
                    for (z=j+1;z<N;z+=1)
                    {
                        if(NachPostTS[i][z]!=-1)
                        {
                            fl=0;
                        }
                    }
                    if ((fl==1)&&(potest[j]==0)&&(potest[i]==0))
                    {
                        potenc[i]=0;
                        potest[i]=1;
                        goto loop2;
                    }
                }
            }
            else //potest[i]==1
            {
                if(NachPostTS[i][j]!=-1)
                {
                    if(potest[j]==0)
                    {
                        if(NachPost[j][i]!=-1)
                        {
                            potenc[j]=potenc[i]-FS[i][j];
                            potest[j]=1;
                            i=j;
                            puut[p]=j;
                            p+=1;
                            goto loop2;
                        }
                        else
                        {
                            potenc[j]=potenc[i]+FS[i][j];
                            potest[j]=1;
                            i=j;
                            puut[p]=j;
                            p+=1;
                            goto loop2;
                        }
                    }
                    fl=1;
                    for (z=j+1;z<N;z+=1)
                    {
                        if(NachPostTS[i][z]!=-1)
                        {
                            fl=0;
                        }
                    }
                    if ((fl==1)&&(potest[j]==1)&&(potest[i]==1)&&(poiskravn(potest,N,0)==-1))
                        {
                            //printf("exit");
                            goto metka;
                        }
                    if ((fl==1)&&(potest[j]==1)&&(potest[i]==1))
                    {
                        sv=poiskravn(puut,N,-1);
                        if((sv==1)&&(i==puut[0]))
                        {
                            i=poiskravn(potest,N,0);
                            puut[0]=i;
                            p=1;
                            goto loop2;
                        }
                        sv=sv-1;
                        i=puut[sv];
                        puut[sv]=-1;
                        p=p-1;
                        goto loop2;
                    }
                }
            }
        }
    }
    metka:

    if(poiskravn(potest,N,0)==-1)
    {
        printf("\n\n");
        printf("[The matrix of potential:]\n");
        printmatrixone(potenc,N);
    }
    else
    {
        vadimtupoipotenc();return(0);
    }
    /*
    printf("\n\n");
    printf("[The matrix of property potential:]\n");
    printmatrixone(potest,N);
    */
    printf("\n\n\n                       /////////////______the calculation of the characteristics of the ribs______///////////\n\n\n");
    fl=0;
    int min,mini,minj=0;
    printf("ribs without arrows and their characteristics:\n");
    for (i=0;i<N;i+=1)
        for (j=i;j<N;j+=1)
        {
            if ((F[i][j]==1)&&(NachPostTS[i][j]==-1))
            {
                sv=FS[i][j]-(mmax(potenc[i],potenc[j]))+(mmin(potenc[i],potenc[j]));
                if(sv<0) fl=1;
                //printf("(%d;%d) = %d - %d + %d = %d\n",i+1,j+1,FS[i][j],mmax(potenc[i],potenc[j]),mmin(potenc[i],potenc[j]),sv);
                printf("(%d;%d) = %d\n",i+1,j+1,sv);
                if (sv<min)
                {
                    min=sv;
                    mini=i;
                    minj=j;
                }
            }
        }
    printf("\n");
    if (fl==0)
    {
        printf("Supply plan is optimal.\n\n");
        for(i=0;i<NOut;i+=1)
            for(j=0;j<NOut;j+=1)
                if ((NachPost[i][j]!=-1)&&(NachPost[i][j]!=0))
                {
                    printf("%d -> %d = %d\n",i+1,j+1,NachPost[i][j]);
                }
        return(0);
    }

    printf("\n\n\n                       ////////////////////////______improving supply plan______/////////////////////\n\n\n");
   if (potenc[mini]>potenc[minj])
    {
        sv=mini;
        mini=minj;
        minj=sv;
    }
    printf("min=%d  i=%d  j=%d\n",min,mini+1,minj+1);
    printf("\n\n\n                               ////////////////______Search closed circuit______///////////\n\n\n");
    p=0;
    int color[N];
    for(i=0;i<N;i+=1)
        {
            puut[i]=-1;
            color[i]=0;
        }
    puut[0]=minj;
    color[minj]=1;
    p+=1;
    i=minj;

    loop10:
    for (j=0;j<N;j+=1)
    {
        if((i!=mini)&&(j!=minj))
        {
            if ((NachPostTS[i][j]!=-1)&&(j==mini))
            {
                //printf("i=%d j=%d",i+1,j+1);
                goto loop12;
            }
            else
                if ((NachPostTS[i][j]!=-1)&&(color[j]==0))
                {
                    puut[p]=j;
                    p+=1;
                    color[j]=1;
                    i=j;
                    goto loop10;
                }
            fl=1;
            for (z=j+1;z<N;z+=1)
            {
                if(NachPostTS[i][z]!=-1)
                {
                    fl=0;
                }
            }
            if (fl==1)
            {
                sv=poiskravn(puut,N,-1);
                    if((sv==1)&&(i==puut[0]))
                    {
                        puut[0]=i;
                        p=1;
                        goto loop10;
                    }
                    sv=sv-2;
                    i=puut[sv];
                    puut[sv+1]=-1;
                    p=p-1;
                    goto loop10;
            }
        }
    }
    loop12:
    i=0;
    puut[p]=mini;
    int protiv[N];
    for (j=0;j<N;j+=1)
        protiv[j]=-1;
    j=0;
    printf("%d->%d\n",mini+1,minj+1);
    while(puut[i+1]!=-1)
    {
        printf("%d->%d\n",puut[i]+1,puut[i+1]+1);
        if(NachPost[puut[i]][puut[i+1]]==-1)
        {
            protiv[j]=NachPostTS[puut[i]][puut[i+1]];
            j+=1;
        }
        i+=1;
    }

    printf("\n\n\n                               ////////////////______Correct supply plan______///////////\n\n\n");

    min=protiv[0];
    for (i=0;i<j;i+=1)
    {
        if(protiv[i]<min)
            min=protiv[i];
    }
    //printf("minprotiv=%d\n",min);

    i=0;
    fl=0;
    while(puut[i+1]!=-1)
    {
        if(NachPost[puut[i]][puut[i+1]]==-1)
        {
            NachPost[puut[i+1]][puut[i]]-=min;
            NachPostTS[puut[i+1]][puut[i]]-=min;
            NachPostTS[puut[i]][puut[i+1]]-=min;
            if((NachPost[puut[i+1]][puut[i]]==0)&&(fl==0))
            {
                NachPost[puut[i+1]][puut[i]]=-1;
                NachPostTS[puut[i+1]][puut[i]]=-1;
                NachPostTS[puut[i]][puut[i+1]]=-1;
                fl=1;
            }
        }
        else
        {
            NachPost[puut[i]][puut[i+1]]+=min;
            NachPostTS[puut[i+1]][puut[i]]+=min;
            NachPostTS[puut[i]][puut[i+1]]+=min;
        }
        i+=1;
    }
    NachPost[mini][minj]=min;
    NachPostTS[mini][minj]=min;
    NachPostTS[minj][mini]=min;
    printf("\n");
        for(i=0;i<N;i+=1)
            for(j=0;j<N;j+=1)
                if (NachPost[i][j]!=-1)
                {
                    printf("%d -> %d = %d\n",i+1,j+1,NachPost[i][j]);
                }
    printf("\n");

    goto loop11;




  fclose(fp);
  system("PAUSE");
}
































