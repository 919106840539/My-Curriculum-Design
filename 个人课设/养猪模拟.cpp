//养猪模拟器(游戏)
//ver 1.1.1.20200831
//完成初步的结构体定义，尝试实现最基础的链表创建和初始化
//ver 1.1.2.20200901
//使用类封装相关猪圈信息，完成成员函数的大体规划，初步完成一小部分成员函数的定义
//ver 1.1.5.20200905
//完成基本成员函数的构建，初步确立主体功能的实现方式，但仍未解决文件存取的问题
//ver 1.1.8.20200910
//解决文件存取问题，进入调试整体代码阶段 
//调试阶段：
//20200911:无法买猪卖猪

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<Windows.h>
#include<algorithm>
using namespace std;

double money;				//资金信息
int month, day;
int sell_count;				//销售次数
int allpig;					//猪圈里全部的猪

struct pig_info
{
	double weight;			//猪的体重，使用千克作为单位
	int species;			//猪的种类：1代表黑猪，2代表小花猪，3代表大花白猪
	int growday=0;			//累计饲养天数
	int growmonth=0;		//累计饲养月数
	int num;				//猪的编号
	pig_info* next;			//指向下一节点的指针
};

class pig_farm
{
private:
	int count;				//猪圈里猪的总数
	int black;				//1代表:是黑猪猪圈；  2代表:不是黑猪猪圈
	pig_info* head;			//头节点
public:
	pig_farm();							//自定义缺省构造函数
	void addpig(pig_info* ptr);			//加入新的猪
	bool findpig(int num);				//找到某个编号的猪
	void insertpig(int species);		//插入某品种的一只猪
	int getcount();						//读出某个猪圈内猪的总数
	int getallpigs(pig_farm pf[]);		//读出整个养猪场的猪总数
	int getgrowmonth(int x);			//读出生长的月数
	int getgrowday(int x);				//读出生长的天数
	int getspecies(int x);				//读出猪的品种
	int getspecies1();					//找出一个猪圈里品种代号为1的猪的数目
	int getspecies2();					//找出一个猪圈里品种代号为2的猪的数目
	int getspecies3();					//找出一个猪圈里品种代号为3的猪的数目
	double getprice();					//计算猪的售价
	double getweight(int x);			//读出猪的体重
	void setblack(int x);				//设定x号猪圈为黑猪猪圈
	int getblack();						//鉴别是否为黑猪猪圈
	void next(int nexttime);			//时间推移，相关属性数值变化
	void check_print();					//查询并打印所有猪的基本信息
	void print_black();					//查询并打印黑猪的体重和饲养时间
	void print_little(int index);		//查询并打印小花猪的体重和饲养时间
	void print_big (int index);		//查询并打印大花白猪的体重和饲养时间
	void save(ofstream& savefile);		//存储猪圈内各种猪的信息
	void clear_pig_farm();				//清除猪圈信息，释放内存
	pig_info* gethead();				//获取头节点
};

/*
弃用的结构体思路
struct single_pigfarm
{
	int num;				//单个猪圈的编号
	int total;				//单个猪圈内总猪数目
	int small, big, black;	//对应小花猪、大花白猪、黑猪的数目
	pig_info info[10];		//猪圈最多十只猪的信息

	single_pigfarm* next;	//指向链表下一个节点的指针
};
single_pigfarm* create_and_init()					//创建并初始化全空的猪圈链表
{
	single_pigfarm* head = new single_pigfarm;		//先创建并初始化链表头节点
	head->num = 0;
	head->total = 0;
	head->small = 0;
	head->big = 0;
	head->black = 0;
	for (int j = 0; j < 10; j++)
	{
		head->info[j].growday = 0;
		head->info[j].species = 0;
		head->info[j].weight = 0.0;
	}
	//p1为本次操作节点，p2为前一节点
	single_pigfarm* p1 = head;
	for (int i = 1; i < 100; i++)
	{
		single_pigfarm* p2 = new single_pigfarm;

		p2->num = i;
		p2->total = 0;
		p2->small = 0;
		p2->big = 0;
		p2->black = 0;
		for (int j = 0; j < 10; j++)
		{
			p2->info[j].growday = 0;
			p2->info[j].species = 0;
			p2->info[j].weight = 0.0;
		}
		if (i == 99)
		{
			p1->next = p2;
			p2->next = nullptr;
		}
		else
		{
			p1->next = p2;
			p1 = p2;
		}
	}
	return head;
}
*/

pig_farm::pig_farm()					//自定义构造函数用于初始化
{
	count = 0;
	black = 0;
	head = nullptr;
}

void pig_farm::addpig(pig_info* ptr)
{
	count++;
	ptr->next = nullptr;
	if (head == nullptr)				//第一只猪入圈的情况
		head = ptr;
	else
	{									//后续猪入圈的情况
		pig_info* q = head;				//用活动节点q从头扫描到末尾
		while ((q->next) != nullptr)
			q = q->next;
		q->next = ptr;					//q节点在末尾时，把新进节点作为新的尾结点连接
	}
}

bool pig_farm::findpig(int num)
{
	pig_info* ptr = head;				//活动节点ptr从头到尾遍历一次，寻找指定编号的猪
	while (ptr)
	{
		if (ptr->num == num)
			return true;
		else
			ptr = ptr->next;
	}
	return false;
}

void pig_farm::insertpig(int species)
{
	pig_info* ptr = new pig_info;
	srand((unsigned)time(NULL));			//根据时间设置随机数种子
	ptr->species = species;
	ptr->weight = double(20 + rand() % 30);	//取20~50之间的随机整数作为体重初始值
	ptr->growday = 0;
	ptr->growmonth = 0;
	if (head == nullptr)
	{
		ptr->num = 0;
		ptr->next = nullptr;
		head = ptr;
		count++;
	}
	else if (head->num != 0)
	{
		ptr->num = 0;
		ptr->next = head;
		head = ptr;
		count++;
	}
	else
	{
		pig_info* p1 = head, * p2 = p1;
		int t = 0;
		while (p1->num == t && p1->next != nullptr)
		{
			t++;
			p2 = p1;
			p1 = p1->next;
		}
		if (p1->next == nullptr)
		{
			ptr->num = count;
			ptr->next = nullptr;
			p1->next = ptr;
		}
		else
		{
			ptr->num = t;
			p2->next = ptr;
			ptr->next = p1;
		}
		count++;
	}
}

int pig_farm::getcount()
{
	return count;
}

int pig_farm::getallpigs(pig_farm pf[])
{
	int allcount = 0;
	for (int i = 0; i < 100; i++)
	{
		allcount += pf[i].getcount();
	}
	return allcount;
}

int pig_farm::getgrowmonth(int x)
{
	pig_info* ptr = head;
	for (int i = 0; i < x; i++)
		ptr = ptr->next;
	int growmonth = ptr->growmonth;
	return growmonth;
}

int pig_farm::getgrowday(int x)
{
	pig_info* ptr = head;
	for (int i = 0; i < x && ptr; i++)
		ptr = ptr->next;				//活动指针ptr移动到相应位置读取growday
	int growday = ptr->growday;
	return growday;
}

int pig_farm::getspecies(int x)
{
	pig_info* ptr = head;
	for (int i = 0; i < x; i++)
		ptr = ptr->next;
	int species = ptr->species;
	return species;
}

int pig_farm::getspecies1()
{
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		if (getspecies(i) == 1)
			total++;
	}
	return total;
}

int pig_farm::getspecies2()
{
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		if (getspecies(i) == 2)
			total++;
	}
	return total;
}

int pig_farm::getspecies3()
{
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		if (getspecies(i) == 3)
			total++;
	}
	return total;
}

double pig_farm::getprice()
{
	double price = 0;
	if (head == nullptr)
		return 0;
	int month, day;
	int flag = 0;
	pig_info* ptr = head, * p1 = ptr;
	while (ptr != nullptr)
	{
		month = ptr->growmonth;
		day = ptr->growday;
		while (day >= 30)
		{
			day -= 30;
			month++;
		}
		if (month >= 12 || ptr->weight > 75)
		{
			if (count == 1)
			{
				setblack(0);
				head = nullptr;
				delete ptr;
				count--;
				break;
			}
			if (ptr->species == 1)
				price += 30 * ptr->weight;
			if (ptr->species == 2)
				price += 14 * ptr->weight;
			if (ptr->species == 3)
				price += 12 * ptr->weight;
			p1 = ptr->next;
			delete ptr;
			ptr = p1;
			count--;
			continue;
		}
		else if (flag == 0)
		{
			flag = 1;
			head = ptr;
		}
		p1 = ptr;
		ptr = p1->next;
	}
	return price;
}

double pig_farm::getweight(int x)
{
	pig_info* ptr = head;
	for (int i = 0; i < x && ptr; i++)
		ptr = ptr->next;
	return ptr->weight;
}

void pig_farm::setblack(int x)
{
	black = x;
}

int pig_farm::getblack()
{
	return black;
}

void pig_farm::next(int nexttime)
{
	srand((unsigned)time(NULL));
	pig_info* ptr = head;
	while (ptr)
	{
		ptr->weight += (double)(rand() % 12) * nexttime / 10;
		if (nexttime == 1)
			ptr->growday++;
		else
			ptr->growmonth++;
		ptr = ptr->next;
	}
}

void pig_farm::check_print()
{
	if (count == 0)
	{
		cout << "这个猪圈是空的" << endl;
		return;
	}
	else if (black == 1)
		cout << "这个是黑猪猪圈" << endl;
	else
		cout << "这个不是黑猪猪圈" << endl;
	pig_info* ptr = head;
	while (ptr)
	{
		int month = ptr->growmonth;
		int day = ptr->growday;
		while (day >= 30)
		{
			day -= 30;
			month++;
		}
		cout << "总共有" << count << "头猪" << endl;
		int index = ptr->num;
		cout << index << "号猪总计饲养了" << month << "个月" << day << "天，重量为：" << ptr->weight << "Kg，";
		if (ptr->species == 1)
			cout << "种类是黑猪" << endl;
		if (ptr->species == 2)
			cout << "种类是小花猪" << endl;
		if (ptr->species == 3)
			cout << "种类是大花白猪" << endl;
		ptr = ptr->next;
	}
}

void pig_farm::print_black()
{
	pig_info* ptr = head, *p1 = ptr;
	while (ptr!=nullptr)
	{
		int month = ptr->growmonth;
		int day = ptr->growday;
		while (day >= 30)
		{
			day -= 30;
			month++;
		}
		int index = ptr->num;
		cout << index << "号黑猪总计饲养了" << month << "个月" << day << "天，重量为：" << ptr->weight << "Kg" << endl;
		p1 = ptr->next;
		ptr = p1;
	}
}

void pig_farm::print_little(int index)
{
	pig_info* ptr = head, * p1 = ptr;
	int flag = 1;
	while (ptr!=nullptr)
	{
		if (ptr->species == 2)
		{
			if (flag)
			{
				cout << "第" << index << "号猪圈中：" << endl;
				flag = 0;
			}
			int month = ptr->growmonth;
			int day = ptr->growday;
			while (day >= 30)
			{
				day -= 30;
				month++;
			}
			int index = ptr->num;
			cout << index << "号小花猪总计饲养了" << month << "个月" << day << "天，重量为：" << ptr->weight << "Kg" << endl;
			p1 = ptr->next;
			ptr = p1;
		}
		else
		{
			p1 = ptr->next;
			ptr = p1;
		}
	}
}

void pig_farm::print_big(int index)
{
	pig_info* ptr = head, * p1 = ptr;
	int flag = 1;
	while (ptr!=nullptr)
	{
		if (ptr->species == 3)
		{
			if (flag)
			{
				cout << "第" << index << "号猪圈中：" << endl;
				flag = 0;
			}
			int month = ptr->growmonth;
			int day = ptr->growday;
			while (day >= 30)
			{
				day -= 30;
				month++;
			}
			int index = ptr->num;
			cout << index << "号大花白猪总计饲养了" << month << "个月" << day << "天，重量为：" << ptr->weight << "Kg" << endl;
			p1 = ptr->next;
			ptr = p1;
		}
		else
		{
			p1 = ptr->next;
			ptr = p1;
		}
	}
}

void pig_farm::clear_pig_farm()
{
	if (head == nullptr)
		return;
	else
	{
		pig_info* ptr = head;
		pig_info* p1 = ptr;
		count = 0;
		setblack(0);
		head = nullptr;
		while (ptr)
		{
			p1 = ptr;
			ptr = ptr->next;
			delete p1;
		}
		delete ptr;
	}
}

void pig_farm::save(ofstream&savefile)
{
	if (head == nullptr)
	{
		savefile << '$' << endl;			//$表示文件内容为空
		return;
	}
	else
	{
		pig_info* ptr = head;
		int i = 0;
		savefile << count << endl;
		while (ptr)
		{
			savefile << getspecies(i) << "  " << getweight(i) << "  " << getgrowmonth(i) << "  " << getgrowday(i) << endl;
			i++;
			ptr = ptr->next;
		}
	}
}

pig_info* pig_farm::gethead()
{
	return head;
}

int get_allpigs(pig_farm pf[])
{
	int allcount=0;
	for(int i=0;i<100;i++){
		allcount+=pf[i].getcount();
	}
	return allcount;

}

void read_init_info(pig_farm pf[])								//读取“init_info.txt”中的初始信息，包括猪圈信息和资金信息
{
	ifstream get_quanju;
	get_quanju.open("quanju_data.txt");
	get_quanju>>allpig>>money>>month>>day>>sell_count; 
	get_quanju.close();
	ifstream readfile1;
	readfile1.open("init_info.txt");							//init_info.txt文件负责存储初始化所需要的猪圈和资金信息
	readfile1 >> allpig >> money >> month >> day >> sell_count;
	readfile1.close();
	ifstream readfile2;
	readfile2.open("pig_farm data.txt");
	if (!readfile2)
	{
		cout << "错误：未能读取保存文件" << endl;
		exit(0);
	}
	int x, count;
	pig_info* ptr;
	readfile2 >> x;
	for (int i = 0; i < 100; i++)
	{
		readfile2 >> count;
		for (int j = 0; j < count; j++)
		{
			ptr = new pig_info;
			ptr->num = j;
			readfile2 >> ptr->species;
			if (ptr->species == '$')
			{
				delete ptr;
				break;
			}
			else
				readfile2 >> ptr->weight >> ptr->growmonth >> ptr->growday;
			pf[i].addpig(ptr);
		}
	}
	readfile2.close();
}

void save_pig_farm(pig_farm pf[])								//将猪圈信息存储到“pig_farm data.txt”文件中
{
	ofstream savefile;
	savefile.open("pig_farm data.txt");
	if (!savefile)
	{
		cout << "错误：未能打开保存文件" << endl;
		exit(0);
	}
	savefile << 1 << endl;
	for (int i = 0; i < 100; i++)
		pf[i].save(savefile);
	savefile.close();
}

void save_outpig_info(int outpig_num, int black, int little, int big, double price)		//将出圈的猪的信息和售价存储到“outpig_info.txt”文件中
{
	ifstream readfile;
	readfile.open("outpig_info.txt");
	char flag;
	readfile >> flag;
	if (flag == '#')
	{
		readfile.close();
		//ofstream savefile1;
		//savefile1.open("outpig_info.txt");
		//savefile1 << '$';
		//savefile1.close();
	}
	else
		readfile.close();
	ofstream save("outpig_info.txt", ios::app);			//ios::app在ofstream下功能：如果没有文件，生成空文件；如果有文件，在文件尾追加
	save << sell_count << endl;
	save << outpig_num << "  " << price << "   " << black << "  " << little << "  " << big << 2000 * black + 1500 * little + 300 * big << endl;
	save.close();
}

void read_outpig_info()
{
	ifstream read;
	read.open("outpig_info.txt");
	if (!read)
	{
		cout << "读取出圈信息失败";
		exit(0);
	}
	char flag;
	read >> flag;
	if (flag == '#')
	{
		cout << "未找到记录" << endl;
		return;
	}
	int time, outpig_num, sellprice, black, little, big, cost, last = 0;
	while (!read.eof())
	{
		read >> time;
		if (time == last)
		{
			flag = 1;
			continue;
		}
		last = time;
		read >> outpig_num >> sellprice >> black >> little >> big >> cost;
		cout << "第" << time / 4 + 1 << "年";
		cout << "第" << (time % 4 + 1) << "月" << endl;
		cout << "出圈猪数：" << outpig_num << "   获得收益：" << sellprice << "   购买的黑猪数：" << black << "   购买的小花猪数：" << little << "   购买的大花白猪数：" << big << "   花费：" << cost << endl;
	}
	read.close();
}

void save_quanju_data()
{
	ofstream savedata;
	savedata.open("quanju_data.txt");
	if(!savedata)
	{
		cout<<"无法打开文件，保存失败！";
		exit(0);
	}
	else 
	{
		savedata<<allpig<<"   "<<money<<"   "<<month<<"   "<<day<<"   "<<sell_count<<endl;
		cout<<"保存成功！"<<endl;
		savedata.close();
	}
}

void buy_pig(int black, int little, int big, pig_farm pf[])		//参数依次为买入的黑猪数目，小白猪数目，大花白猪数目，以及类数组
{
	while (black--)
	{
		for (int i = 0; i < 100; i++)
		{
			if (pf[i].getblack() == 1 && pf[i].getcount() < 10)
			{
				pf[i].insertpig(1);
				break;
			}
			else if (pf[i].gethead() == nullptr)			//如果猪圈为空，设定为黑猪猪圈，插入黑猪信息
			{
				pf[i].insertpig(1);			
				pf[i].setblack(1);
				break;
			}
		}
	}
	int average = allpig / 100 + 1;
	while (true)
	{
		for (int i = 0; i < 100; i++)
		{
			if (pf[i].getblack() == 0)
			{
				if (little > 0 && pf[i].getcount() <= average)
				{
					pf[i].insertpig(2);
					little--;
				}
				if (big > 0 && pf[i].getcount() <= average)
				{
					pf[i].insertpig(3);
					big--;
				}
			}
		}
		if (little == 0 && big == 0)
			break;
	}
}

void set_pigfarm(pig_farm pf[])			//设定初始存档，资金两万，猪有200只，猪的属性随机
{
	allpig = 200;
	money = 20000;
	month = 0;
	day = 0;
	sell_count = 0;
	ofstream file;
	file.open("pig_data.txt");
	file << 0;
	file.close();
	file.open("outpig_info.txt");
	file << '#';
	file.close();
	pig_info* p;
	srand((unsigned)time(NULL));
	int count = 200;
	while (count--)
	{
		p = new pig_info;
		p->species = rand() % 3 + 1;
		p->weight = rand() % 30 + 20;
		p->growday = 0;
		p->growmonth = 0;
		for (int i = 0; i < 100; i++)
		{
			if (p->species == 1 && (pf[i].getblack() == 1 || pf[i].gethead() == nullptr) && pf[i].getcount() < 10)
			{
				p->num = pf[i].getcount();
				pf[i].addpig(p);
				pf[i].setblack(1);
				break;
			}
			if (p->species != 1 && pf[i].getblack() == 0 && pf[i].getcount() < 5) 
			{
				p->num = pf[i].getcount();
				pf[i].addpig(p);
				break;
			}
		}
	}
} 

void print_menu()
{ 
	cout << "\n\n";
	cout << "            ======================================================\n";
	cout << '\n';
	cout << "                                  养猪模拟器                      \n";
	cout << '\n';
	cout << "                                请选择操作：\n";
	cout << '\n';
	cout << "                                 1.开始模拟\n";
	cout << '\n';
	cout << "                                 2.如何成功完成模拟？\n";
	cout << '\n';
	cout << "                                 3.退出\n";
	cout << '\n';
	cout << "            ======================================================\n";
}

void menu_init()
{
	system("cls");		//执行清屏操作
	cout << "\n\n";
	cout << "            ======================================================\n";
	cout << "                                    养猪场                        \n";
	cout << '\n';
	cout << "                       请选择操作：\n";
	cout << '\n';
	cout << "                                 1.查询\n";
	cout << "                                 2.出圈并购猪\n";
	cout << "                                 3.重新开始模拟\n";
	cout << "                                 4.保存模拟情况\n";
	cout << "                    5.下一天                      6.下个月        \n";
	cout << '\n';
	cout << "               当前资金：" << money << "    总猪数：" << allpig << "   饲养时间:"; 
						    if (month > 0) cout << month << "个月";
						    if (day >= 0) cout << day << "天";
	cout << '\n';
	cout << "            ======================================================\n";
}

void check() {
	system("cls");
	cout << "\n\n";
	cout << "            ======================================================\n";
	cout << "                                     查询                          \n";
	cout << '\n';
	cout << "             请选择操作：\n";
	cout << '\n';
	cout << "               1.查询某个猪圈猪的数量和种类\n";
	cout << "               2.查询某猪圈某头猪的状态信息\n";
	cout << "               3.统计当前养猪场每个品种猪的数量和体重、饲养时间分布情况\n";
	cout << "               4.查询近5年猪的销售记录和猪崽的购入记录\n";
	cout << "               5.显示当前养猪场猪的所有信息\n";
	cout << "               6.返回\n";
	cout << '\n';
	cout << "            ======================================================\n";
}

int main()
{
	pig_farm pf[100];
	print_menu();
	int flag = 0;
	ifstream readfile;
	readfile.open("pig_farm data.txt");
	readfile>>flag;
	if (flag == 0)
		set_pigfarm(pf);
	else
		read_init_info(pf);
	readfile.close();
	allpig = get_allpigs(pf);
	int mode;
	cout << "            请输入你要想要的操作编号：";
	while (cin >> mode)
	{
		switch (mode)
		{
			case 1:
			{
				menu_init();
				int choice1;
				while (cout << "            请输入你要想要的操作编号：",cin >> choice1)
				{
					switch (choice1)
					{
						case 1:
						{
							check();
							int choice2;
							while(cout << "            请输入你要想要的操作编号：",cin >> choice2)
							{
								switch (choice2)
								{
									case 1:
									{
										int num;
										cout << "请输入猪圈编号：";
										cin >> num;
										cout << "此猪圈有" << pf[num].getcount() << "头猪，其中有黑猪" << pf[num].getspecies1() << "头，小花猪" << pf[num].getspecies2() << "头，大白花猪" << pf[num].getspecies3() << "头\n";
										break;
									}
									case 2: 
									{
										int num1, num2;
										cout << "请输入猪圈号：";
										cin >> num1;
										while (1) 
										{
											if (num1 >= 0 && num1 < 100 && pf[num1].getcount() != 0)
												break;
											else 
												cout << "此猪圈为空，请重新输入"; cin >> num1;
										}
										cout << "此猪圈共有" << pf[num1].getcount() << "头猪,请输入猪的编号：";
										cin >> num2;
										while (1) 
										{
											if (!pf[num1].findpig(num2)) 
											{
												cout << "此猪不存在，可能已出圈,或者可能编号过大，请重新输入：";
												cin >> num2;
											}
											else 
												break;
										}
										cout << "此猪为";
										if (pf[num1].getspecies(num2) == 1)
											cout << "黑猪，体重为";
										if (pf[num1].getspecies(num2) == 2)
											cout << "小花猪，体重为";
										if (pf[num1].getspecies(num2) == 3)
											cout << "大白花猪，体重为";
										cout << pf[num1].getweight(num2) << "kg,饲养时间为";
										int month = pf[num1].getgrowmonth(num2), day = pf[num1].getgrowday(num2);
										while (day >= 30) 
										{
											day -= 30;
											month++;
										}
										if (month > 0)
											cout << month << "个月"; 
										cout << day << "天\n";
										break;
									}
									case 3: 
									{
										if (pf->gethead() == nullptr)
										{
											cout << "目前养猪场内无猪" << endl;
											break;
										}
										else
										{
											//pig_info* ptr = pf->gethead();
											int black_cnt = 0, little_cnt = 0, big_cnt = 0;
											for (int i = 0; i < 100; i++)
											{
												if (pf[i].getblack() == 1)
												{
													black_cnt += pf[i].getspecies1();
													continue;
												}
												else
												{
													little_cnt += pf[i].getspecies2();
													big_cnt += pf[i].getspecies3();
													continue;
												}
											}
											cout << "当前猪场中，黑猪的总数为：" << black_cnt << endl;
											for (int i = 0; i < 100; i++)
											{
												if (pf[i].getblack() == 1)
												{
													cout << "第" << i << "号猪圈是黑猪猪圈，";
													pf[i].print_black();
													continue;
												}
												else
													continue;
											}
											cout << endl;
											cout << "当前猪场中，小花猪的总数为：" << little_cnt << endl;
											for (int i = 0; i < 100; i++)
											{
												if (pf[i].getblack() != 1)
												{
													pf[i].print_little(i);
													continue;
												}
												else
													continue;
											}
											cout << endl;
											cout << "当前猪场中，大花白猪的总数为：" << big_cnt << endl;
											for (int i = 0; i < 100; i++)
											{
												if (pf[i].getblack() != 1)
												{
													pf[i].print_big(i);
													continue;
												}
												else
													continue;
											}
										}
										break;
									}
									case 4:
									{
										read_outpig_info();
										break;
									}
									case 5:
									{
										for(int i=0;i<100;i++)
										{
											cout<<i<<"号圈，";
											pf[i].check_print();
										}
										break;
									}
									case 6:
										break;
					   			}
					   			if(choice2==6)
								   break;
					   		}
					   		menu_init();
							break;
						}
						case 2:
						{
							if(month+day/30<3)
							{
								cout<<"饲养时间不足3个月,或者距离上次出圈后的饲养时间不足3个月"<<endl;
								break;
							}
							double sellprice=0.0;
							for(int i=0;i<100;i++)
								sellprice+=pf[i].getprice();
							int temp=get_allpigs(pf),outpignum=allpig-temp;
							allpig=temp;
							cout<<"此次出圈的猪有"<<outpignum<<"头，总体售价为:"<<sellprice<<"元\n";
							money+=sellprice;
							int blackpig=0,blank_zj=0,count=0;
							for(int i=0;i<100;i++)
							{
								if(pf[i].getcount()==0)
								{
									blank_zj++;
									continue;
								}
								if(pf[i].getspecies1())
									blackpig+=10-pf[i].getspecies1();
								else 
									count+=10-pf[i].getcount();
							}
							cout << "未满的黑猪圈可购入" << blackpig << "头黑猪，剩余空猪圈数：" << blank_zj << endl;
							int black = 0, little = 0, big = 0, cost = 0;
							cout << "提示：每头黑猪2000元，每头小花猪1500元，每头大花白猪3000元，当前余额：" << money << endl;
							cout << "请依次输入本次购入的黑猪，小花猪，大花白猪数" << endl;
							while(cin >> black >> little >> big)
							{
								cost = 2000 * black + 1500 * little + 3000 * big;
								if(black>blackpig+blank_zj*10||little>blank_zj*10+count||big>blank_zj*10+count||little+big>blank_zj*10+count)
									cout<<"猪的数量超过猪场最大量，请重新输入：\n";
								else if(money<cost)
									cout<<"剩余资金不足，请重新输入\n";
								else if(((blank_zj-(black-blackpig)/10)*10<=little+big)&&black>blackpig)
									cout<<"黑猪与其他猪不能混养，请重新输入：\n";
								else if(allpig+black+little+big>=1000)
								{
									cout<<"养满猪场，模拟非常成功！"<<endl;
									exit(0);
								}
								else 
									break; 
							}
							money -= cost;
							allpig += black+little+big;
							//cout<<allpig<<endl;	
							buy_pig(black,little,big,pf);
							save_outpig_info(outpignum,black,little,big,sellprice);
							sell_count++;
							while(day>=30)
							{
								day-=30;
								month++;
							}
							//month-=3;
							//cin.get(); 
							//cin.get(); 
							menu_init();
							break;
						}
						case 3: 
						{
							for(int i=0;i<100;i++)
								pf[i].clear_pig_farm(); 
							set_pigfarm(pf);
							menu_init();
							break;
						}
						case 4:
						{ 
							save_pig_farm(pf);
							save_quanju_data(); 
							break;
						}
						case 5:
						{
							for(int i=0;i<100;i++)
								pf[i].next(1);
							day++;
							menu_init();
							break;
						}
						case 6:
						{
							for(int i=0;i<100;i++)
								pf[i].next(30);
							month++;
							menu_init();
							break;
						}
						default:
							break;
					}
				}
				break;	
			}
			case 2:
			{
				int back;
				system("cls");
				cout << "\n\n";
				cout << "            ======================================================\n";
				cout << "                                    帮助                          \n";
				cout << '\n';
				cout << '\n';
				cout << "                  初始条件是200只猪，属性随机，20000元起始资金\n";
				cout << "                  资金不亏空，养满猪场，您就赢了\n";
				cout << '\n';
				cout << '\n';
				cout << "		                                       输入0以返回\n";
				cout << '\n';
				cout << "            ======================================================\n";
				cout<<"\n";
				cin >> back;
				if (back == 0)
				{
					system("cls");
					print_menu();
					break;
				}
			}
		}
		if(mode==3)
			exit(0);
	}
	return 0;
}
