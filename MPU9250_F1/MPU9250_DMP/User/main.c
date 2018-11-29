/***************************************************

*�ļ�����:
*         ���ݹٷ�DMP����MPU9250����̬
          ���ΪYaw,pitch,Rollֵ���Ƕ�ֵ��
					�ο����ϲ��ִ���
*Author:
*         ��ܰ @ UESTC
*Time:
*					2015.3.30
*version:
*         v1.0
***************************************************/
 
#include "stm32f10x.h"
#include "delay.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "inv_mpu.h"
#include "math.h"
#include "usart.h"
#include "stm32_iic.h"
#include "stdio.h"
#include "mpu_user_api.h"



int main(void)
{  
    USART1_Config();  //���ڳ�ʼ��
    i2cInit();      //IIC���ߵĳ�ʼ��
    delay_ms(10);
		Mpu_Init(1);


    while(1)
    {
        
        Update_attitude_Angle();

            printf("Pitch:");
            printf("%f ",Pitch);


            printf("Roll:");
            printf("%f ",Roll);     


            printf("Yaw:");        
            printf("%f ",Yaw);
  
				
						Update_Magnetometer();
						printf("M:%d \n",Direction);
    }
}

 

