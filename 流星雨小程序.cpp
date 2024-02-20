#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

#include<easyx.h>//图形库
//注：凡是用easyx图形库的字符串都要用_T()函数来转换。


//导入播放音乐所需文件
#include<MMSystem.h>
#pragma comment(lib,"winmm.lib")


//定义结构体，弄星星
#define Start 500
#define liu 60
#define LOVE 20

struct Star
{
	int x,y,r,speed;
	COLORREF color;
}star[Start];

struct liuXin
{
	int x,y,speed;
}liuX[liu];

//初始化星星
void xin(int i)
{
	star[i].x=rand()%getwidth();
	star[i].y=rand()%getheight();
	star[i].r=rand()%3+1;
	star[i].speed=rand()%5;
	star[i].color=RGB(rand()%256,rand()%256,rand()%256);
}
//绘制小星星
void drawXin()
{
	for(int i=0;i<Start;i++)
	{
		
		//putpixel(star[i].x,star[i].y,star[i].color);//绘制像素点
		setfillcolor(star[i].color);//设置星星颜色
		solidcircle(star[i].x,star[i].y,star[i].r);//绘制圆,第三个参数为半径
	}
}
// 移动星星
void moveXin()
{
	for(int i=0;i<Start;i++)
	{
		star[i].x+=star[i].speed;
		if(star[i].x>getwidth())
			star[i].x=0;
	}
}

//流星
IMAGE img[2],bk[7];

#define SIZE 55
void loadImg()
{
	//加载图片
	loadimage(img+0,_T("img/259.jpg"),SIZE,SIZE);//图片数组地址 图片地址 图片宽度 图片高度
	loadimage(img+1,_T("img/258.png"),SIZE,SIZE);
	loadimage(bk+0,_T("img/1.jpg"),getwidth(),getheight());
	loadimage(bk+1,_T("img/2.jpg"),getwidth(),getheight());
	loadimage(bk+2,_T("img/3.jpg"),getwidth(),getheight());
	loadimage(bk+3,_T("img/4.jpg"),getwidth(),getheight());
	loadimage(bk+4,_T("img/5.jpg"),getwidth(),getheight());
	loadimage(bk+5,_T("img/6.jpg"),getwidth(),getheight());
	loadimage(bk+6,_T("img/bk.jpg"),getwidth(),getheight());

}
using namespace std;

//初始化流量
void Liu(int i)
{
	//0~1200
	liuX[i].x=rand()%(getwidth()*2)-getwidth();
	liuX[i].y=-100;
	liuX[i].speed=rand()%16+1;
}
//画流量
void drawLiu()
{
	for(int i=0;i<liu;i++)
	{
		//SRCPAINT参数可以让图片背景不把其他背景遮盖点
		//SRCAND可让两个图片重合在一起
		putimage(liuX[i].x,liuX[i].y,img+rand()%2,SRCPAINT);//输出图片，  离左边办距离 与上边界距离
	}
		
}

//移动流星
void moveLiu()
{
	for(int i=0;i<liu;i++)
	{
		liuX[i].x+=liuX[i].speed;
		liuX[i].y+=liuX[i].speed;
		if(liuX[i].x>getwidth()||liuX[i].y>getheight())
		{
			liuX[i].x=rand()%(getwidth()*2)-getwidth();
			liuX[i].y=-100;
		}
	}
}

#define Text1 "天道酬勤!"
#define Text2 "不抛弃不放弃!"
#define Text3 "Never never give up!"
#define Text4 "笑对未来，勇往直前!"
#define Text5 "如果事与原违，那一定另有安排!"

#define CO RGB(rand()%256,rand()%256,rand()%256)
void welcome()
{

	//导入音乐  mci(media device interface)多媒体设备接口
	mciSendString(_T("open ./music/LYQ.mp3"),NULL,0,NULL);//第一个参数为字符串，指给多媒体设备的指令,后面的三个参数不用管，赋NULL 0 NULL即可
	mciSendString(_T("play ./music/LYQ.mp3"),NULL,0,NULL);
	//文本输出中能用outtextxy
	//_T() 此函数可以将其字符串进行转换
	srand(time(NULL));
	//字体高度 字体宽度（若设置为0表自适应） 字体名

	//设置背景模式为透明
	setbkmode(TRANSPARENT);//transparent，此模式保持文字背景色不变

	//窗口宽度 getwidth(); 文本宽度：textwidth(a);

	int T1=(getwidth()-textwidth(_T(Text1)))/2-textwidth(_T(Text1))*2;
	int T2=(getwidth()-textwidth(_T(Text2)))/2-textwidth(_T(Text2))*2;
	int T3=(getwidth()-textwidth(_T(Text3)))/2-textwidth(_T(Text3))*2;
	int T4=(getwidth()-textwidth(_T(Text4)))/2-textwidth(_T(Text4))*2;
	int T5=(getwidth()-textwidth(_T(Text5)))/2-textwidth(_T(Text5))*2;


	//返回随机数rand()但要种种子，方法和C一样
	//设置文字颜色settextcolor
	int j=0,m=0;
	COLORREF C1,C2;
	//是否按键，是为1，不是为0
	while(!_kbhit())
	{
		//清屏
		cleardevice();
		if(j==7) j=0;

		C1=CO;

		putimage(0,0,bk+j);
		
		
		/*settextcolor(RED);*///可以是颜色的英文，也可以用RGB（int,int,int）来定义指定的颜色
		//outtextxy(Tx,0,_T("Hello Everone！"));//离左边界的距离  离上边界的距离  输出的文本
		start:
		switch(m)
		{
			case 0:		settextcolor(RED);
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T1,0,_T(Text1));
						
						settextcolor(CO);

						outtextxy(T2,150,_T(Text2));

						settextstyle(80,0,_T("华文彩云"));
						outtextxy(T3,300,_T(Text3));
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T4,450,_T(Text4));
						outtextxy(T5,600,_T(Text5));
						break;
			case 1:		C2=C1;
						settextcolor(C2);
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T1,0,_T(Text1));

						settextcolor(RED);
						outtextxy(T2,150,_T(Text2));

						settextcolor(C2);
						settextstyle(80,0,_T("华文彩云"));
						outtextxy(T3,300,_T(Text3));
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T4,450,_T(Text4));
						outtextxy(T5,600,_T(Text5));
						break;
			case 2:		C2=C1;
						settextcolor(C2);
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T1,0,_T(Text1));
						outtextxy(T2,150,_T(Text2));

						settextcolor(RED);
						settextstyle(80,0,_T("华文彩云"));
						outtextxy(T3,300,_T(Text3));
						settextstyle(80,0,_T("华文行楷"));

						settextcolor(C2);
						outtextxy(T4,450,_T(Text4));
						outtextxy(T5,600,_T(Text5));
						break;break;
			case 3:		C2=C1;
						settextcolor(C2);
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T1,0,_T(Text1));
						outtextxy(T2,150,_T(Text2));

						settextstyle(80,0,_T("华文彩云"));
						outtextxy(T3,300,_T(Text3));
						settextstyle(80,0,_T("华文行楷"));

						settextcolor(RED);
						outtextxy(T4,450,_T(Text4));

						settextcolor(C2);
						outtextxy(T5,600,_T(Text5));
						break; 
			case 4:		C2=C1;
						settextcolor(C2);
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T1,0,_T(Text1));
						outtextxy(T2,150,_T(Text2));

						settextstyle(80,0,_T("华文彩云"));
						outtextxy(T3,300,_T(Text3));
						settextstyle(80,0,_T("华文行楷"));

						outtextxy(T4,450,_T(Text4));

						settextcolor(RED);
						outtextxy(T5,600,_T(Text5));
						break;
			default :  m=0;goto start;
		}
		
		for(int i=0;i<LOVE;i++)
		{
			settextcolor(RGB(rand()%255,rand()%255,rand()%255));
			outtextxy(rand()%getwidth(),rand()%getheight(),_T("❤"));
		}
		m++;
		j++;
		Sleep(1000);//延迟函数，形参为毫秒

	}
}

int main()
{
	
	//initgraph(400,400);
	//setbkcolor(RGB(255,255,255));
	//settextcolor(RED);
	//setlinecolor(RED);
	//for(int i=0;i<=getwidth();i+=getwidth()/10)//画五子棋
	//{
	//		line(i,0,i,getheight());
	//		line(0,i,getwidth(),i);
	//}
	//
	//circle(getwidth()/2,getheight()/2,100);
	//setfillcolor(RED);
	///*fillcircle(getwidth()/2,getheight()/4,20);
	//setfillcolor(BLUE);*/
	//
	//rectangle(getwidth()/2,getheight()/2,getwidth()/3,getheight()/3);
	//fillrectangle(200,200,400,400);
	//
	//getch();
	//closegraph();



	//1.创建图形窗口
	initgraph(1500,800,1);//宽 高 加上1表示显示控制台窗口
	//设置背景颜色
	setbkcolor(BLACK);
	//closegraph(); 关闭窗口

	//加载背景图片
	loadImg();
	for(int i=0;i<Start;i++)
	{
		xin(i);
	}

	for(int i=0;i<liu;i++)
	{
		Liu(i);
	}

	welcome();
	
	int i=1,r;
	//双缓冲绘图，解决闪屏问题
	BeginBatchDraw();
	while(1)
	{

		
		cleardevice(); //作用相当于cls
		if(i%160==0)r=rand()%7;
		putimage(0,0,bk+r);

		drawXin();
		moveXin();

		drawLiu();
		moveLiu();

		Sleep(20);
		i++;
		FlushBatchDraw();
	}

	EndBatchDraw();

	return 0;
}

/*函数知识点：
	1创建图形窗口
	initgraph(1500,800,8);//宽 高 显示控制台窗口

	2设置背景颜色
	setbkcolor(BLACK);
	参数可是颜色英文大写字母和三原色形式(RGB(0,0,0)即黑色)

	3关闭窗口
	closegraph();

	4.作用相当于cls,用于刷新屏幕
	cleardevice(); 

	5.画图函数
	【1】画直线
	设置线性颜色：setlinecolor(COLOR a); 
	line(int x,int y,int xx ,int yy) 起点坐标(x,y)与终点坐标(xx,yy)

	【2】画圆
	设置填充颜色 setfillcolor(COLOR a);值与前面的设置背景颜色一样。
	
	circle(int x,int y,int r) 圆心的坐标x,y 半径r为像素值。
	带线填充 fillcircle(int x,int y,int r); 与画圆一样，只不过多了填充和有外框线的效果
	不带填充 solidcircle(int x,int y,int r); 与画圆一样，只不过多了填充和无外框线的效果

	【3】画矩形
	rectangle(int x,int y,int xx,int yy) 矩形的左上角坐标和右下角坐标
	设置填充颜色 setfillcolor(COLOR a);值与前面的设置背景颜色一样。
	带线填充 fillrectangle(int x,int y,int xx,int yy); 与画圆一样，只不过多了填充和有外框线的效果
	不带填充 solidrectangle(int x,int y,int xx,int yy); 与画圆一样，只不过多了填充和无外框线的效果
	*/

	//新的知识
