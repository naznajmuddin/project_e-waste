/** NAME:       NAZWA NAJMUDDIN BIN MOHD NIZWARUDDIN
    MATRICS NO: FB20083
    TITLE:      PROJECT BCI1103	COMPUTER PROGRAMMING
                E-WASTE STATISTICS & TRENDS IN KUALA LUMPUR CITY
    OBJECTIVES: This program calculates the statistics of e-Waste
                & identify the trends of e-Waste generation in Kuala Lumpur City (2016-2019)
    LECTURER:   TS. DR. HOH WEI SIANG **/
#include<stdio.h>
#include<stdlib.h>
#define size 4 //size of year = 4
void choose(int choseYr, int year[size],int tv[size],int pc[size],int cellphone[size],int fridge[size],int airconditioner[size],int washingmachine[size],int battery[size]);
int diff(int sum16,int sum17,int sum18,int sum19,int sum20);
void check(int firstYr,int secondYr,int sum16,int sum17,int sum18,int sum19);
int main()
{
    FILE *IN;
    FILE *OUT;
    IN=fopen("data1.txt","r+");
    OUT=fopen("data2.txt","r+");
    int i,j;
    int firstYr,secondYr;
    int sum16,sum17,sum18,sum19,sum20,tv19;
    char choice;
    int year[size],tv[size],pc[size],cellphone[size],fridge[size],airconditioner[size],washingmachine[size],battery[size];
    //check if the text file can be open
    if(IN==NULL)
    {
        printf("Error reading the file.\n");
        exit(0);
    }
    if(OUT==NULL)
    {
        printf("Error reading the file.\n");
        exit(0);
    }
    //SCAN ALL DATA FROM TEXT FILE
    for(i=0;i<4;i++)
    {
        fscanf(IN,"%d %d %d %d %d %d %d %d",&year[i],&tv[i],&pc[i],&cellphone[i],&fridge[i],&airconditioner[i],&washingmachine[i],&battery[i]);
    }
    //calculate specific row
    for(i=0;i<1;i++)
    {
        fscanf(IN,"%d %d %d %d %d %d %d %d",&year[i],&tv[i],&pc[i],&cellphone[i],&fridge[i],&airconditioner[i],&washingmachine[i],&battery[i]);
        sum16=tv[i]+pc[i]+cellphone[i]+fridge[i]+airconditioner[i]+washingmachine[i]+battery[i];
    }
    for(i=1;i<2;i++)
    {
        fscanf(IN,"%d %d %d %d %d %d %d %d",&year[i],&tv[i],&pc[i],&cellphone[i],&fridge[i],&airconditioner[i],&washingmachine[i],&battery[i]);
        sum17=tv[i]+pc[i]+cellphone[i]+fridge[i]+airconditioner[i]+washingmachine[i]+battery[i];
    }
    for(i=2;i<3;i++)
    {
        fscanf(IN,"%d %d %d %d %d %d %d %d",&year[i],&tv[i],&pc[i],&cellphone[i],&fridge[i],&airconditioner[i],&washingmachine[i],&battery[i]);
        sum18=tv[i]+pc[i]+cellphone[i]+fridge[i]+airconditioner[i]+washingmachine[i]+battery[i];
    }
    for(i=3;i<4;i++)
    {
        fscanf(IN,"%d %d %d %d %d %d %d %d",&year[i],&tv[i],&pc[i],&cellphone[i],&fridge[i],&airconditioner[i],&washingmachine[i],&battery[i]);
        sum19=tv[i]+pc[i]+cellphone[i]+fridge[i]+airconditioner[i]+washingmachine[i]+battery[i];
    }
    printf("\t\t\te-Waste Statistics & Trends in Kuala Lumpur City (2016 - 2019)\n");
    printf("This program calculates the statistics of e-Waste & identify the trends of e-Waste generation in Kuala Lumpur City\n");

    while((choice!='N')&&(choice!='n'))//loop until user choose NO
    {
        printf("\nPlease enter the first year to display: \n");
        printf("\t1. 2016\n\t2. 2017\n\t3. 2018\n\t4. 2019\n");
        scanf("%d", &firstYr);
            if(firstYr==1)
                firstYr=2016;//if user choose 1, declare it is 2016
            else if(firstYr==2)
                firstYr=2017;//if user choose 2, declare it is 2017
            else if(firstYr==3)
                firstYr=2018;//if user choose 3, declare it is 2018
            else if(firstYr==4)
                firstYr=2019;//if user choose 4, declare it is 2019

        printf("Please enter the second year to compare with: \n");
        printf("\t1. 2016\n\t2. 2017\n\t3. 2018\n\t4. 2019\n");
        scanf("%d", &secondYr);
            if(secondYr==1)
                secondYr=2016;//if user choose 1, declare it is 2016
            else if(secondYr==2)
                secondYr=2017;//if user choose 2, declare it is 2017
            else if(secondYr==3)
                secondYr=2018;//if user choose 3, declare it is 2018
            else if(secondYr==4)
                secondYr=2019;//if user choose 4, declare it is 2019
        //function call
        choose(firstYr,year,tv,pc,cellphone,fridge,airconditioner,washingmachine,battery);
        choose(secondYr,year,tv,pc,cellphone,fridge,airconditioner,washingmachine,battery);
        check(firstYr,secondYr,sum16,sum17,sum18,sum19);
        diff(sum16,sum17,sum18,sum19,sum20);
        printf("\nDo you want to observe the data again? (Y=Yes/N=No): ");
        scanf("%s",&choice);
    }
    fprintf(OUT,"2016\t%d\n2017\t%d\n2018\t%d\n2019\t%d",sum16,sum17,sum18,sum19);
    fclose(IN);
    fclose(OUT);
}
void choose(int choseYr, int year[size],int tv[size],int pc[size],int cellphone[size],int fridge[size],int airconditioner[size],int washingmachine[size],int battery[size])
{
    int i,sum;

    for(i=0;i<4;i++)
    {
        if(choseYr==year[i])//proceed to display data if the chosen data is correct with the array
        {
        printf("\n%d e-Waste DATA",choseYr);
        printf("\nTelevisions: %d\nComputers: %d\nCellphones: %d\nRefridgerators: %d\nAirconditioners: %d\nWashing Machines: %d\nRechargeable Batteries: %d\n",tv[i],pc[i],cellphone[i],fridge[i],airconditioner[i],washingmachine[i],battery[i]);
        sum=tv[i]+pc[i]+cellphone[i]+fridge[i]+airconditioner[i]+washingmachine[i]+battery[i];
        }
    }
    if((choseYr<1)||(choseYr>4)&&(choseYr<2016)||(choseYr>2019))//if user insert wrong value, it is INVALID
    {
        printf("\nYour input: %d is INVALID.\n", choseYr);
        exit(0);//break the program
    }
    printf("Total e-Waste Generated in Kuala Lumpur City %d: %d Metric Tonne\n", choseYr,sum);
}
int diff(int sum16,int sum17,int sum18,int sum19,int sum20)
{
    FILE *diff;
    diff=fopen("data3.txt","r+");
    int diff1617,diff1718,diff1819,diff1920;
    diff1617=sum17-sum16;
    diff1718=sum18-sum17;
    diff1819=sum19-sum18;
    fprintf(diff,"1617\t%d\n1718\t%d\n1819\t%d",diff1617,diff1718,diff1819);
    fclose(diff);
}
void check(int firstYr,int secondYr,int sum16,int sum17,int sum18,int sum19)
{
    float diff1617,diff1618,diff1619,diff1716,diff1718,diff1719,diff1819,diff1817,diff1816,diff1916,diff1917,diff1918;
    float percent;
    printf("\n\tCOMPARISON\n");
    if(firstYr==2016)
    {
        if(secondYr==2017)
        {
            diff1617=sum17-sum16;
            percent=(diff1617/(sum16+sum17))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1617,percent);
            if(sum17<sum16)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum17>sum16)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
        else if(secondYr==2018)
        {
            diff1618=sum18-sum16;
            percent=(diff1618/(sum18+sum16))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1618,percent);
            if(sum18<sum16)
                printf("The data is DECREASING.\n");
            else if(sum18>sum16)
                printf("WARNING: The data is INCREASING.\n");
        }
        else if(secondYr==2019)
        {
            diff1619=sum19-sum16;
            percent=(diff1619/(sum19+sum16))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1619,percent);
            if(sum19<sum16)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum19>sum16)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
    }
    else if(firstYr==2017)
    {
        if(secondYr==2016)
        {
            diff1716=sum17-sum16;
            percent=(diff1716/(sum17+sum16))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1716,percent);
            if(sum17<sum16)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum17>sum16)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
        else if(secondYr==2018)
        {
            diff1718=sum18-sum16;
            percent=(diff1718/(sum18+sum16))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1718,percent);
            if(sum18<sum17)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum18>sum17)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
        else if(secondYr==2019)
        {
            diff1719=sum19-sum16;
            percent=(diff1719/(sum19+sum16))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1719,percent);
            if(sum19<sum18)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum19>sum18)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
    }
    else if(firstYr==2018)
    {
        if(secondYr==2016)
        {
            diff1816=sum18-sum16;
            percent=(diff1816/(sum18+sum16))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1816,percent);
            if(sum18<sum16)
            {
                printf("The data is DECREASING.\n");

            }
            else if(sum18>sum17)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
        else if(secondYr==2017)
        {
            diff1817=sum18-sum17;
            percent=(diff1817/(sum18+sum17))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1817,percent);
            if(sum18<sum16)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum18>sum17)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
        else if(secondYr==2019)
        {
            diff1819=sum19-sum18;
            percent=(diff1819/(sum19+sum18))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1819,percent);
            if(sum19<sum18)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum19>sum18)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
    }
    else if(firstYr==2019)
    {
        if(secondYr==2016)
        {
            diff1916=sum19-sum16;
            percent=(diff1916/(sum19+sum16))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1916,percent);
            if(sum19<sum16)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum19>sum16)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
        else if(secondYr==2017)
        {
            diff1917=sum19-sum17;
            percent=(diff1917/(sum19+sum17))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1917,percent);
             if(sum19<sum17)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum19>sum17)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
        else if(secondYr==2018)
        {
            diff1918=sum19-sum18;
            percent=(diff1918/(sum19+sum18))*100;
            printf("Difference between %d & %d: %.0f (%.2f percent)\n",firstYr,secondYr,diff1918,percent);
             if(sum19<sum18)
            {
                printf("The data is DECREASING.\n");
            }
            else if(sum19>sum18)
            {
                printf("WARNING: The data is INCREASING.\n");
            }
        }
    }
}
