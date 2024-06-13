#include<stdio.h>
 
struct robin
{
       int p,art,but,wtt,tat,rnt;
};
 
 
void rrsa(struct robin a[],int process)
{
       int i,j;
       struct robin temp;
       for(i=0;i<process;i++)
       {
              for(j=i+1;j<process;j++)
              {
                     if(a[i].art > a[j].art)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
       return;
}
 
int main()
{
       int i,j,process,time,remain,flag=0,ts;
       struct robin a[100];
       float avgwt=0,avgtt=0;
       printf("Round Robin Scheduling Algorithm\n");
       printf("Enter Number Of Processes : ");
       scanf("%d",&process);
       remain=process;
       for(i=0;i<process;i++)
       {
              printf("Enter arrival time and Burst time for Process P%d : ",i);
              scanf("%d%d",&a[i].art,&a[i].but);
              a[i].p = i;
              a[i].rnt = a[i].but;
       }
       rrsa(a,process);
       printf("Enter Quantum Number : ");
       scanf("%d",&ts);
       printf("\n******************************************************************************\n");
       printf("Gantt Chart\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
              if(a[i].rnt<=ts && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
                     printf(" -> [P%d] <- %d",a[i].p,time);
                     a[i].rnt=0;
                     flag=1;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - ts;
                     time = time + ts;
                     printf(" -> [P%d] <- %d",a[i].p,time);
              }
              if(a[i].rnt==0 && flag==1)
              {
                     remain--;
                     a[i].tat = time-a[i].art;
                     a[i].wtt = time-a[i].art-a[i].but;
                     avgwt = avgwt + time-a[i].art-a[i].but;
                     avgtt = avgtt + time-a[i].art;
                     flag=0;
              }
              if(i==process-1)
                     i=0;
              else if(a[i+1].art <= time)
                     i++;
              else
                     i=0;
       }
       printf("\n\n");
       printf("******************************************************************************\n");
       printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
       printf("******************************************************************************\n");
       for(i=0;i<process;i++)
       {
              printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",a[i].p,a[i].art,a[i].but,a[i].tat,a[i].wtt);
       }
       printf("******************************************************************************\n");
       avgwt = avgwt/process;
       avgtt = avgtt/process;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtt);
       return 0;
}

