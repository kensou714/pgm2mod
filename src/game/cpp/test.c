#include <stdlib.h>
#include <stdio.h>

#include "../game_type.h"
#include "../xyj2_func.h"
#include "../game_wave.h"
#include "../pgm2_key.h"

/*
*===================================================
*					����ģʽ
*===================================================
*/

/*
*
*
*
*
*/
/*
	MainMenu[0].String = (int *)"IO";
	MainMenu[0].Function =(int *)(hook_io_test+1);
	MainMenu[1].String = (int *)"COUNTER";
	MainMenu[1].Function =(int *) 0x10039491;
	MainMenu[2].String = (int *)"AUDIO";
	MainMenu[2].Function =(int *) 0x10039541;
	MainMenu[3].String = (int *)"SOBJECT";
	MainMenu[3].Function =(int *) 0x10039CF7;
	MainMenu[4].String = (int *)"SIGNATURE";
	MainMenu[4].Function =(int *) 0x10039DD1;
	MainMenu[5].String = (int *)"RANKING";
	MainMenu[5].Function =(int *) 0x10039E2F;
	MainMenu[6].String = (int *)"DIALOG";
	MainMenu[6].Function =(int *) 0x1003C381;
	MainMenu[7].String = (int *)"DIALOGSPEC";
	MainMenu[7].Function =(int *) 0x1003C5F9;
	MainMenu[8].String = (int *)"SYSOBJ";
	MainMenu[8].Function =(int *) 0x10039E7D;
	MainMenu[9].String = (int *)"FOOD";
	MainMenu[9].Function =(int *) 0x1003A107;
	MainMenu[10].String = (int *)"WEAPON";
	MainMenu[10].Function =(int *) 0x1003A2B1;
	MainMenu[11].String = (int *)"ROLE";
	MainMenu[11].Function =(int *) 0x1003A7E7;
	MainMenu[12].String = (int *)"RORO";
	MainMenu[12].Function =(int *) 0x1003B133;
	MainMenu[13].String = (int *)"CHANGEMEN";
	MainMenu[13].Function =(int *) 0x1003BB89;
	MainMenu[14].String = (int *)"PASSSTORY";
	MainMenu[14].Function =(int *) 0x1003C865;
	MainMenu[15].String = (int *)"OVERSTORY";
	MainMenu[15].Function =(int *) 0x1003CA65;
	MainMenu[16].String = (int *)"COMMANDPORT";
	MainMenu[16].Function =(int *) 0x1003CBD1;
	MainMenu[17].String = (int *)"SHARERAM";
	MainMenu[17].Function =(int *) 0x1003CD93;
	MainMenu[18].String = (int *)"CARD DATA";
	MainMenu[18].Function =(int *) 0x1003E0F5;
	MainMenu[19].String = (int *)"TEST BACKFONT";
	MainMenu[19].Function =(int *) 0x10038FBF;
	MainMenu[20].String = (int *)"EXIT";
	MainMenu[20].Function = (int *)0x1003A38B;	
*/


void RoleSelect(){
	int i;
	int x;
	int y;
	int Box_w;
	int Box_h;
	x=0;
	y=0;
	Box_w=4;
	Box_h=2;
	sub_1000F0B0();	//���ｫͼ��RAM���
	sub_1000EEB2(1,0,0);//һ�����أ�
	Snd_Stop_All();//ֹͣ��������
	Play_Music_Repeat(WAVE_SELECT,112);


	vPalette_LoadDirect(2, 18, 0x1012D980, 0);
	vPalette_LoadDirect(2, 20, 0x10433B68, ubArea_Get());
	vPalette_LoadDirect(2, 22, 0x10433C68, 0);
	vPalette_LoadDirect(2, 21, 0x10433E68, 0);
	V8(0x200203FC) = vPalette_LoadDirect(2, 19, 0x10431A68, 0);
	vPalette_LoadDirect(2, 27, 0x1042F668, 0);
	vPalette_LoadDirect(2, 16, 0x1042F768, 0);
	vPalette_LoadDirect(2, 17, 0x10430768, 0);
	vPalette_LoadDirect(2, 23, 0x10430968, 0);
	vPalette_LoadDirect(2, 24, 0x10430A68, 0);
	vPalette_LoadDirect(2, 25, 0x10430B68, 0);
	vPalette_LoadDirect(2, 26, 0x10430C68, 0);
	vPalette_LoadDirect(2, 0, 0x10395AB4, 0);
	vPalette_LoadDirect(2, 1, 0x10395BB4, 0);
	vPalette_LoadDirect(2, 2, 0x10395CB4, 0);
	vPalette_LoadDirect(2, 3, 0x10395DB4, 0);
	vPalette_LoadDirect(2, 4, 0x10395EB4, 0);
	vPalette_LoadDirect(2, 28, 0x10433768, 0);
	vPalette_LoadDirect(2, 29, 0x10433868, 0);
	vPalette_LoadDirect(2, 30, 0x10433968, 0);
	vPalette_LoadDirect(2, 31, 0x10434068, 0);
	vPalette_LoadDirect(2, 42, 0x10434168, 0);	
	sub_10081FF0(19, 19); //����ǻ���������
	sub_10081440(0,0,0,19,20,1,0);//����ǻ�SELECT CHARACTER��	
	
	
	
	
	
	
	while(1){//������ѭ��

		sub_1000F106();//����
		sub_1000EEB2(0, 0, 0);//����
		SetBankPal();//����ϵͳ����ɫ��
		for(i=0;i<10;i++)
		{
			vPalette_LoadDirect(0,5+i,0x10392E98 + 64*i);//����10������ͷ��ɫ��
			sub_10001794(0,4+i*5,5,0x10395800,i+1,0,0,5+i,2306);//����10������ͷ��
		}
		for(i=0;i<10;i++)
		{
			vPalette_LoadDirect(0,15+i,0x10392E98 + 64*(i+10));//����10��BOSSͷ��ɫ��
			sub_10001794(0,4+i*5,8,0x10395800,i+10+1,0,0,15+i,2306);//����10��BOSSͷ��
		}
		for(i=0;i<6;i++)
		{
			vPalette_LoadDirect(0,25+i,0x10392E98 + 64*(i+20));//����10��BOSSͷ��ɫ��
			sub_10001794(0,4+i*5,11,0x10395800,i+20+1,0,0,25+i,2306);//����10��BOSSͷ��
		}

		
//		while(1){//����˵�ѡ��ѭ��
		
			sub_10001238(3+x*5, 4+y*3, (int)&Box_w, 1, (int)&Box_h, 1, -1, 1);//�Ѿɿ�ɾ��
			if(uwInputKick(KEY_P1_DOWN)){//��
				if((y==1 && x<6) || y==0)
					y++;
				Play_Voice(657,112);
			}
			else if(uwInputKick(KEY_P1_UP)){//��
				if(y>0)
					y--;
				Play_Voice(657,112);
			}
			else if(uwInputKick(KEY_P1_LEFT)){//��
				if(x>0)
					x--;
				Play_Voice(657,112);
			}
			else if(uwInputKick(KEY_P1_RIGHT)){//��
				if(y<2 && x<9)
					x++;
				else if(y==2 && x<5)
					x++;
				Play_Voice(657,112);
			}
			sub_10001238(3+x*5, 4+y*3, (int)&Box_w, 1, (int)&Box_h, 1, 0, 1);//��ʾ�¿�
			if(uwInputKick(KEY_P1_START))//��ʼ��
				break;
//			ScreenUpdate();//ˢ����Ļ
//		}


		ScreenUpdate();
	}
}














const char *MainMenuString[]={
	"GAME TEST",
	"ROLE SELECT",
	"EXIT"
};

const int MainMenuFunc[]={
	(int)(0x1003F38A+1),
	(int)(&RoleSelect+1),
};

const int MainMenuCnt = 3;//�˵�����
void TestMain(){
	int i;
	int pos;


	pos = 0;
	sub_1000F0B0();	//���ｫͼ��RAM���
	sub_1000EEB2(1,0,0);//һ�����أ�

	while(1){//������ѭ��
		Snd_Stop_All();//ֹͣ��������
		sub_1000F106();//����
		sub_1000EEB2(0, 0, 0);//����
		SetBankPal();//����ϵͳ����ɫ��
		vPuts(10,0,4,3,"---MAIN MENU---");//��ʾ������Ϣ
		for(i=0;i<MainMenuCnt;i++)
			vPuts(14,3+i,0,0,MainMenuString[i]);//ѭ����ʾ���˵��ı�
		while(1){//����˵�ѡ��ѭ��
			if(uwInputKick(KEY_P1_DOWN)){//��
				vPuts(14,3+pos,0,0,MainMenuString[pos]);//�Ѿɵ�ѡ���ԭ�ɰ�ɫ
				if(pos+1>=MainMenuCnt)
					pos = 0;
				else
					pos++;
			}
			else if(uwInputKick(KEY_P1_UP)){//��
				vPuts(14,3+pos,0,0,MainMenuString[pos]);//�Ѿɵ�ѡ���ԭ�ɰ�ɫ
				if(!pos)
					pos = MainMenuCnt-1;
				else
					pos--;
			}
			vPuts(14,3+pos,4,0,MainMenuString[pos]);//���µ�ѡ�������óɻ�ɫ
			if(uwInputKick(KEY_P1_START))//��ʼ��
				break;
			ScreenUpdate();//ˢ����Ļ
		}
		if(pos==MainMenuCnt-1)//EXIT
			break;
		sub_1000F094();//����
		sub_1002E5F8();//�����ڴ�
		sub_10011B04();//�����ڴ�
		sub_100035CA();//����ͼ�λ���
		sub_1004C738();//��ʼ����Ϸ�����ñ���(�ؿ���������ʱ���)
		sub_100299C0();//��ʼ����������
		sub_10019F3A();//��ʼ���з�����
		SetBankPal();//����ϵͳ������ɫ
		vPrint(10,0,0,3,"-%s-",MainMenuString[pos]);//��ʾѡ�в˵��Ķ�����Ϣ
		FUNC32(MainMenuFunc[pos])();//ִ��ѡ�еĳ���
		ScreenUpdate();
	}
}



