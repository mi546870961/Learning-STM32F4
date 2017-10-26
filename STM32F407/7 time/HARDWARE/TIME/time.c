#include "time.h"


void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 ,ENABLE);//ʹ��TIME3
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=arr;
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;
	//TIM_TimeBaseInitStructure.TIM_RepetitionCounter �߼���ʱ����	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);	
	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);//������ʱ��3�����ж�
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn ;//�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);		
	
	TIM_Cmd(TIM3, ENABLE);//ʹ�ܶ�ʱ��3
}

void TIM3_IRQHandler (void)
{
	if(TIM_GetFlagStatus(TIM3, TIM_FLAG_Update)==SET)
		LED1=!LED1;
	TIM_ClearITPendingBit(TIM3, TIM_FLAG_Update);
}