#include<stdio.h>
int main()
{
        int rs[30],st[10],ru[10],place_rank[10],n,f,i,j,k,pf=0,min=0,ind,count=0;
        printf("enter no of references:");
        scanf("%d",&n);
        printf("enter  reference string:");
        for(i=0;i<n;i++)
        {
         scanf("%d",&rs[i]);
        }
        printf("enter no of frames:");
        scanf("%d",&f);
        for(j=0;j<f;j++)
        {
                st[j]=-1;
                ru[j]=0;
                place_rank[j]=0;
        }
        printf("page replacement process:\n");
        for(i=0;i<n;i++)
        {
                for(k=0;k<f;k++)
                {
                        if(st[k]==rs[i])
                        {
                                ru[k]++;
                                break;
                        }
                }
                if(k==f)
                {
                        min=0;
                        for(k=0;k<f;k++)
                                if(ru[k]<ru[min])
                                        min=k;
                        for(j=0;j<f;j++)
                        {
                                 if(ru[j]==ru[min] && place_rank[j]<place_rank[min])    
                                        {
                                          min=j;
                                        }
                                   }

                        st[min]=rs[i];
                        place_rank[min]=++count;
                        ru[min]=1;
                        pf++;
                }
                for(j=0;j<f;j++)
                        printf("\t%d\t",st[j]);
                if(k==f)
                        printf("PF no.%d",pf);
                printf("\n");

        }
        printf("no of page faults:%d",pf);
}
