#include <stdio.h>
void main(){
	int n,i,j,q,t,P[40],time[40],wait=0,turn; float totalturn=0,totalwait=0 ;
	
	printf("Enter No. of process: "); scanf("%d",&n);
	
	for (i=0; i<n; i++){	 
		P[i]=i+1;
		printf("Enter Burst time of Process %d: ",i+1); scanf("%d",&time[i]);	
	}
	
	for (i=0; i<n; i++){	
		for (j=0; j<n-1-i; j++){
			if (time[j+1]<time[j]){
				q=P[j]; t=time[j];
				P[j]=P[j+1]; time[j]=time[j+1];
				P[j+1]=q; time[j+1]=t;				
			}			
		}
	}
	
	for (i=0; i<n; i++){
		
		turn = wait + time[i]; 				
		printf("PID:\t%d\tBT:\t%d\twait:\t%d\tturn:\t%d\n",P[i],time[i],wait,turn);		
		totalwait = totalwait + wait;
		wait = wait + time[i]; 
		totalturn = totalturn + turn; 
			
	}
	printf("Avg waiting time:\t%0.2f\n", totalwait/n);
	printf("Avg turnaround time:\t%0.2f", totalturn/n);	
}

