


//QUESTION 3-SHORTEST JOB FIRST SCHEDULING ALGORITHM 
    
#include<stdio.h>
 int BT[20],p[20],WT[20],TAT[20],i,j,n,total=0,loc,c,ch;
 float avWT,avTAT;
struct SJF
{
    int  pid;
    int pid_AT ;
    int pid_BT;

};
struct calculate
{
    int last;
    int WAT ;
    int TAT;
};
int main()
{
	
	struct SJF SJF1[30];
	struct calculate cal[30];
	int i,no,j,loc,m,pre_complete,Time_unit=0,l,k,counter,Rest,s=0,count=0,s1=0,count1=0;
	printf("\t \t  **************SHORTEST  JOB  FIRST  SCHEDULING  ALGORITHM ******************");
	printf(" \n CALCULATION  OF  THE  WAITING  TIME  AND  TURNAROUND  TIME  BY CHECKING  AND  ARRANGING  PROCESS  ACCORDING  TO  SHORTEST  JOB TIME  UNIT =2 ");
 P:	printf("\n \n How  may  process  do  you  want  to  enter \n ");
	scanf("%d",&no); 
	for(i=1;i<=no;i++)
	{
		printf("\n\nPROCESS P%d\n",i);
		SJF1[i].pid=i;
		printf("ENTER  THE   ARRIVAL  TIME  OF  THE  PROCESS   %d \n ",i);
		scanf("%d",&SJF1[i].pid_AT);
		
		printf("ENTER  THE  BURST TIME OF  THE  PROCESS  %d \n" ,i);
		scanf("%d",&SJF1[i].pid_BT);

	}
	Time_unit!=0;
	for(i=1;i<=no;i++)
	{
		if(SJF1[i].pid_AT==0)
        {
        	printf("\t\tProcess- %d PLEASE  ENTER  THE  OTHER  ARRIVAL  TIME  THAN  0 DICARD ",i);
            for(j=i;j<no;j++)
            {
                SJF1[j]=SJF1[j+1];
            }
            Time_unit=SJF1[1].pid_AT;
            no--;
            i--;
        }
        if(SJF1[i].pid_AT<Time_unit )
        {
            Time_unit=SJF1[i].pid_AT;
        }
	}
	l = no;
	m=0;
	k=1;
	while(no>0)
	{
		 int s=0,count=0;
	    pre_complete=SJF1[1].pid_BT;
	    Rest=Time_unit+1;
	    counter=0;
		for(j=1;j<=no;j++)
		{

			if(pre_complete>=SJF1[j].pid_BT && SJF1[j].pid_AT<=Time_unit)
			{
				pre_complete= SJF1[j].pid_BT;
				loc=j;
				counter=1;
			}
			if(Rest>Time_unit && Rest>SJF1[j].pid_AT && SJF1[j].pid_AT!=Time_unit)
            {
                Rest=SJF1[j].pid_AT;
            }
		}
		if(counter==1)
        {
            if(loc==1)
            {
                cal[k].WAT=Time_unit-SJF1[loc].pid_AT;
                Time_unit = Time_unit + pre_complete;
                cal[k].TAT=Time_unit-SJF1[loc].pid_AT;
            }
            else
            {
                cal[k].WAT=Time_unit-SJF1[loc].pid_AT+2;
                Time_unit= Time_unit + pre_complete;
                cal[k].TAT=Time_unit-SJF1[loc].pid_AT+2;
            }
            cal[k].last=SJF1[loc].pid;
            for(i=loc;i<no;i++)
            {
               SJF1[i]=SJF1[i+1];
            }
            no--;
            k++;

        }
        else 
        {
            Time_unit = Rest;
        }

        }
            printf("\n\n\nPROCESS     WAITING TIME      TURNAROUND TIME ****  ");
        for(i=1;i<=l;i++)
        {
                 
            printf("\nP%d            %d                   %d  ",cal[i].last,cal[i].WAT,cal[i].TAT);

        }
        printf("\n \n AVERAGE WAITING OF  THE  PROCESS IS----");
         for(i=1;i<=l;i++)
        {
                 count++;   	
        	 	s=s+cal[i].WAT;
        }

		printf("\n \n %f",(float)s/count);
		printf("\n \nAVERAGE TURNAROUND  TIME OF THE  PROCESS  IS----");
           for(i=1;i<=l;i++)
        {
                 count1++;   	
        	 	s1=s1+cal[i].TAT;
        }
        
        printf("\n \n %f",(float)s1/count1);
          printf("\n\t  if  you  want  to  continue Press 1 to calculate again and 0 to  continue further  ");
	scanf("%d",&ch);
	if(ch==1){

			system("cls");
			goto P;
	}

	printf("\n \n CALCULATION  OF  THE  WAITING  TIME  AND  TURNAROUND  TIME  WITHOUT   CHECKING  AND  ARRANGING  PROCESS  ACCORDING  TO  SHORTEST  JOB TIME  UNIT =2 ");
//  CALCULATION  OF  THE  WAITING  TIME   AND  TURNAROUNF  TIME   OF  THE  PROCESS  WITHOUT   CHECKING  AND ARRANGING  THE  PROCESS  ACCORDING  TO  SHORTEST  JOB  TIME  UNIT 2
 printf("\n \n \nEnter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&BT[i]);
        p[i]=i+1;           //contains process number
    }
 
    
    Burst(); 	
}

void Burst()
{
       //sorting  in  ascending  order  according  to  burst  time
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(BT[j]<BT[loc])
                loc=j;
        }
 
        c=BT[i];
        BT[i]=BT[loc];
        BT[loc]=c;
 
        c=p[i];
        p[i]=p[loc];
        p[loc]=c;
    }
 
    WT[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
            WT[i]+=BT[j];
 
        total+=WT[i];
    }
 
    avWT=(float)total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];     //calculate turnaround time
        total+=TAT[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],BT[i],WT[i],TAT[i]);
    }
 
    avTAT=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avWT);
    printf("\nAverage Turnaround Time=%f\n",avTAT);
 	
}



