#include <stdio.h>
#include <stdlib.h>

void sampleCollect(int n,float array[2][5],float total_prob[5]);

void main()
{
    int n;        //���������ĸ���
    float good_prob[2][5],notgood_prob[2][5];//��good_prob�ĵ����а�total-prob������
    int i,j;
    float info[4],aspect[4];//info�û�����������б�,aspect�����Ҫ�������������
    float p_marry=1,p_notmarry=1;
    float cons=1,total_prob[5];//˧,�Ը��,��,�Ͻ����ܸ���


    printf("������������\n");

    printf("��������������n:");
    scanf("%d",&n);

    sampleCollect(n,good_prob,total_prob);
    //��notgood_prob�����ֵ
    for(i=0; i<2; i++)
        for(j=0; j<5; j++)
            notgood_prob[i][j]=1-good_prob[i][j];

    //��ӡgood_prob
    printf("good_prob array:\n");
    for(i=0; i<2; i++)
        for(j=0; j<5; j++)
            printf("%f\t",good_prob[i][j]);
    //��ӡnotgood_prob
    printf("notgood_prob array:\n");
    for(i=0; i<2; i++)
        for(j=0; j<5; j++)
            printf("%f\t",notgood_prob[i][j]);
    //��ӡtotal_prob
    printf("total_prob list:\n");
    for(i=0; i<5; i++)
        printf("%f\t",total_prob[i]);

    while(info[0]!=6)
    {
        //����
        printf("����������:(��6�˳�)\n");
        printf("����˧����1,��������0:");
        scanf("%f",&info[0]);

        printf("�Ը������1,��������0:");
        scanf("%f",&info[1]);

        printf("�����ø�����1,������0:");
        scanf("%f",&info[2]);

        printf("�����Ͻ�����1,��������0:");
        scanf("%f",&info[3]);

        //����޵ĸ���,��ÿһ�����Խ����ж�
        cons=total_prob[4];
        for(j=0; j<4; j++)
        {
            if(1==info[j])
            {
                aspect[j]=good_prob[0][j];//����Ǻ�Ʒ�ʾʹ�goog_prob�б���ȡ��
                cons/=total_prob[j];
            }
            else
            {
                aspect[j]=notgood_prob[0][j];
                cons/=(1-total_prob[j]);
            }
        }
        p_marry=(aspect[0])*(aspect[1])*(aspect[2])*(aspect[3])*cons;
        printf("\n�޵ĸ�����:%f\n",p_marry);

        //���㲻�޵ĸ���:
        cons=1-total_prob[4];
        for(j=0; j<4; j++)
        {
            if(1==info[j])
            {
                aspect[j]=good_prob[1][j];//�������������õ�,��goog_prob�б���ȡ��
                cons/=total_prob[j];
            }
            else
            {
                aspect[j]=notgood_prob[1][j];//�������������õ�
                cons/=(1-total_prob[j]);
            }
        }
        p_notmarry=(aspect[0])*(aspect[1])*(aspect[2])*(aspect[3])*cons;
        printf("���޵ĸ�����:%f\n",p_notmarry);

        if(p_marry>p_notmarry)
            printf("������˿��Լ�\n");
        else
            printf("������˲��ܼ�\n");
    }
}

void sampleCollect(int n,float array[2][5],float total_prob[5])
{
    int i,j,k=0;
    float features[n][5];
    float handsome=0,kind=0,tall=0,posit=0,marry=0;
    float good_m=0,good_nm=0;

    //��¼����
    for(i=0; i<n; i++)
    {
        printf("����4������:˧,�Ը��,���ø�,�Ͻ�,����1��0:");
        scanf("%f %f %f %f %f",&features[i][0],&features[i][1],&features[i][2],&features[i][3],&features[i][4]);
        if(features[i][0]==1)
        {
            handsome++;
            total_prob[0]=handsome/n;
        }
        if(1==features[i][1])
        {
            kind++;
            total_prob[1]=kind/n;
        }
        if(1==features[i][2])
        {
            tall++;
            total_prob[2]=tall/n;
        }
        if(1==features[i][3])
        {
            posit++;
            total_prob[3]=posit/n;
        }
        if(1==features[i][4])
        {
            marry++;
            total_prob[4]=marry/n;
        }
    }

    //����good����
    for(j=0; j<4; j++)
    {
        good_m=0;
        good_nm=0;
        for(i=0; i<n; i++)
        {
            if(features[i][j]==1)//��
            {
                if(features[i][4]==1)//��_��
                    good_m++;
                else
                    good_nm++;//��_����
            }
        }
        array[0][j]= good_m/marry;
        //printf("%f\n",array[0][j]);
        array[1][j]=good_nm/(n-marry);
        //printf("%f\n",array[1][j]);
    }
    array[0][4]=marry/n;
    array[1][4]=(n-marry)/n;
}


