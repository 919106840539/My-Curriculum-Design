//����ģ����(��Ϸ)
//ver 1.1.1.20200831
//��ɳ����Ľṹ�嶨�壬����ʵ����������������ͳ�ʼ��
//ver 1.1.2.20200901
//ʹ�����װ�����Ȧ��Ϣ����ɳ�Ա�����Ĵ���滮���������һС���ֳ�Ա�����Ķ���
//ver 1.1.5.20200905
//��ɻ�����Ա�����Ĺ���������ȷ�����幦�ܵ�ʵ�ַ�ʽ������δ����ļ���ȡ������
//ver 1.1.8.20200910
//����ļ���ȡ���⣬��������������׶� 
//���Խ׶Σ�
//20200911:�޷���������δ���check3������ ͳ��ÿֻ�����Ϣ

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<Windows.h>
#include<algorithm>
using namespace std;

double money;				//�ʽ���Ϣ
int month, day;
int sell_count;				//���۴���
int allpig;					//��Ȧ��ȫ������

struct pig_info
{
	double weight;			//������أ�ʹ��ǧ����Ϊ��λ
	int species;			//������ࣺ1�������2����С����3����󻨰���
	int growday=0;			//�ۼ���������
	int growmonth=0;		//�ۼ���������
	int num;				//��ı��
	pig_info* next;			//ָ����һ�ڵ��ָ��
};

class pig_farm
{
private:
	int count;				//��Ȧ���������
	int black;				//1����:�Ǻ�����Ȧ��  2����:���Ǻ�����Ȧ
	pig_info* head;			//ͷ�ڵ�
public:
	pig_farm();							//�Զ���ȱʡ���캯��
	void addpig(pig_info* ptr);			//�����µ���
	bool findpig(int num);				//�ҵ�ĳ����ŵ���
	void insertpig(int species);		//����ĳƷ�ֵ�һֻ��
	int getcount();						//����ĳ����Ȧ���������
	int getallpigs(pig_farm pf[]);		//��������������������
	int getgrowmonth(int x);			//��������������
	int getgrowday(int x);				//��������������
	int getspecies(int x);				//�������Ʒ��
	int getspecies1();					//�ҳ�һ����Ȧ��Ʒ�ִ���Ϊ1�������Ŀ
	int getspecies2();					//�ҳ�һ����Ȧ��Ʒ�ִ���Ϊ2�������Ŀ
	int getspecies3();					//�ҳ�һ����Ȧ��Ʒ�ִ���Ϊ3�������Ŀ
	double getprice();					//��������ۼ�
	double getweight(int x);			//�����������
	void setblack(int x);				//�趨x����ȦΪ������Ȧ
	int getblack();						//�����Ƿ�Ϊ������Ȧ
	void next(int nexttime);			//ʱ�����ƣ����������ֵ�仯
	void check_print();					//��ѯ����ӡ������Ļ�����Ϣ
	void print_black();					//��ѯ����ӡ��������غ�����ʱ��
	void print_little(int index);		//��ѯ����ӡС��������غ�����ʱ��
	void print_big (int index);		//��ѯ����ӡ�󻨰�������غ�����ʱ��
	void save(ofstream& savefile);		//�洢��Ȧ�ڸ��������Ϣ
	void clear_pig_farm();				//�����Ȧ��Ϣ���ͷ��ڴ�
	pig_info* gethead();				//��ȡͷ�ڵ�
};

/*
���õĽṹ��˼·
struct single_pigfarm
{
	int num;				//������Ȧ�ı��
	int total;				//������Ȧ��������Ŀ
	int small, big, black;	//��ӦС�����󻨰����������Ŀ
	pig_info info[10];		//��Ȧ���ʮֻ�����Ϣ

	single_pigfarm* next;	//ָ��������һ���ڵ��ָ��
};
single_pigfarm* create_and_init()					//��������ʼ��ȫ�յ���Ȧ����
{
	single_pigfarm* head = new single_pigfarm;		//�ȴ�������ʼ������ͷ�ڵ�
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
	//p1Ϊ���β����ڵ㣬p2Ϊǰһ�ڵ�
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

pig_farm::pig_farm()					//�Զ��幹�캯�����ڳ�ʼ��
{
	count = 0;
	black = 0;
	head = nullptr;
}

void pig_farm::addpig(pig_info* ptr)
{
	count++;
	ptr->next = nullptr;
	if (head == nullptr)				//��һֻ����Ȧ�����
		head = ptr;
	else
	{									//��������Ȧ�����
		pig_info* q = head;				//�û�ڵ�q��ͷɨ�赽ĩβ
		while ((q->next) != nullptr)
			q = q->next;
		q->next = ptr;					//q�ڵ���ĩβʱ�����½��ڵ���Ϊ�µ�β�������
	}
}

bool pig_farm::findpig(int num)
{
	pig_info* ptr = head;				//��ڵ�ptr��ͷ��β����һ�Σ�Ѱ��ָ����ŵ���
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
	srand((unsigned)time(NULL));			//����ʱ���������������
	ptr->species = species;
	ptr->weight = double(20 + rand() % 30);	//ȡ20~50֮������������Ϊ���س�ʼֵ
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
		ptr = ptr->next;				//�ָ��ptr�ƶ�����Ӧλ�ö�ȡgrowday
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
		cout << "�����Ȧ�ǿյ�" << endl;
		return;
	}
	else if (black == 1)
		cout << "����Ǻ�����Ȧ" << endl;
	else
		cout << "������Ǻ�����Ȧ" << endl;
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
		cout << "�ܹ���" << count << "ͷ��" << endl;
		int index = ptr->num;
		cout << index << "�����ܼ�������" << month << "����" << day << "�죬����Ϊ��" << ptr->weight << "Kg��";
		if (ptr->species == 1)
			cout << "�����Ǻ���" << endl;
		if (ptr->species == 2)
			cout << "������С����" << endl;
		if (ptr->species == 3)
			cout << "�����Ǵ󻨰���" << endl;
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
		cout << index << "�ź����ܼ�������" << month << "����" << day << "�죬����Ϊ��" << ptr->weight << "Kg" << endl;
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
				cout << "��" << index << "����Ȧ�У�" << endl;
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
			cout << index << "��С�����ܼ�������" << month << "����" << day << "�죬����Ϊ��" << ptr->weight << "Kg" << endl;
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
				cout << "��" << index << "����Ȧ�У�" << endl;
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
			cout << index << "�Ŵ󻨰����ܼ�������" << month << "����" << day << "�죬����Ϊ��" << ptr->weight << "Kg" << endl;
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
		savefile << '$' << endl;			//$��ʾ�ļ�����Ϊ��
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

void read_init_info(pig_farm pf[])								//��ȡ��init_info.txt���еĳ�ʼ��Ϣ��������Ȧ��Ϣ���ʽ���Ϣ
{
	ifstream get_quanju;
	get_quanju.open("quanju_data.txt");
	get_quanju>>allpig>>money>>month>>day>>sell_count; 
	get_quanju.close();
	ifstream readfile1;
	readfile1.open("init_info.txt");							//init_info.txt�ļ�����洢��ʼ������Ҫ����Ȧ���ʽ���Ϣ
	readfile1 >> allpig >> money >> month >> day >> sell_count;
	readfile1.close();
	ifstream readfile2;
	readfile2.open("pig_farm data.txt");
	if (!readfile2)
	{
		cout << "����δ�ܶ�ȡ�����ļ�" << endl;
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

void save_pig_farm(pig_farm pf[])								//����Ȧ��Ϣ�洢����pig_farm data.txt���ļ���
{
	ofstream savefile;
	savefile.open("pig_farm data.txt");
	if (!savefile)
	{
		cout << "����δ�ܴ򿪱����ļ�" << endl;
		exit(0);
	}
	savefile << 1 << endl;
	for (int i = 0; i < 100; i++)
		pf[i].save(savefile);
	savefile.close();
}

void save_outpig_info(int outpig_num, int black, int little, int big, double price)		//����Ȧ�������Ϣ���ۼ۴洢����outpig_info.txt���ļ���
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
	ofstream save("outpig_info.txt", ios::app);			//ios::app��ofstream�¹��ܣ����û���ļ������ɿ��ļ���������ļ������ļ�β׷��
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
		cout << "��ȡ��Ȧ��Ϣʧ��";
		exit(0);
	}
	char flag;
	read >> flag;
	if (flag == '#')
	{
		cout << "δ�ҵ���¼" << endl;
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
		cout << "��" << time / 4 + 1 << "��";
		cout << "��" << (time % 4 + 1) << "��" << endl;
		cout << "��Ȧ������" << outpig_num << "   ������棺" << sellprice << "   ����ĺ�������" << black << "   �����С��������" << little << "   ����Ĵ󻨰�������" << big << "   ���ѣ�" << cost << endl;
	}
	read.close();
}

void save_quanju_data()
{
	ofstream savedata;
	savedata.open("quanju_data.txt");
	if(!savedata)
	{
		cout<<"�޷����ļ�������ʧ�ܣ�";
		exit(0);
	}
	else 
	{
		savedata<<allpig<<"   "<<money<<"   "<<month<<"   "<<day<<"   "<<sell_count<<endl;
		cout<<"����ɹ���"<<endl;
		savedata.close();
	}
}

void buy_pig(int black, int little, int big, pig_farm pf[])		//��������Ϊ����ĺ�����Ŀ��С������Ŀ���󻨰�����Ŀ���Լ�������
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
			else if (pf[i].gethead() == nullptr)			//�����ȦΪ�գ��趨Ϊ������Ȧ�����������Ϣ
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

void set_pigfarm(pig_farm pf[])			//�趨��ʼ�浵���ʽ���������200ֻ������������
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
	cout << "                                  ����ģ����                      \n";
	cout << '\n';
	cout << "                                ��ѡ�������\n";
	cout << '\n';
	cout << "                                 1.��ʼģ��\n";
	cout << '\n';
	cout << "                                 2.��γɹ����ģ�⣿\n";
	cout << '\n';
	cout << "                                 3.�˳�\n";
	cout << '\n';
	cout << "            ======================================================\n";
}

void menu_init()
{
	system("cls");		//ִ����������
	cout << "\n\n";
	cout << "            ======================================================\n";
	cout << "                                    ����                        \n";
	cout << '\n';
	cout << "                       ��ѡ�������\n";
	cout << '\n';
	cout << "                                 1.��ѯ\n";
	cout << "                                 2.��Ȧ������\n";
	cout << "                                 3.���¿�ʼģ��\n";
	cout << "                                 4.����ģ�����\n";
	cout << "                    5.��һ��                      6.�¸���        \n";
	cout << '\n';
	cout << "               ��ǰ�ʽ�" << money << "    ��������" << allpig << "   ����ʱ��:"; 
						    if (month > 0) cout << month << "����";
						    if (day >= 0) cout << day << "��";
	cout << '\n';
	cout << "            ======================================================\n";
}

void check() {
	system("cls");
	cout << "\n\n";
	cout << "            ======================================================\n";
	cout << "                                     ��ѯ                          \n";
	cout << '\n';
	cout << "             ��ѡ�������\n";
	cout << '\n';
	cout << "               1.��ѯĳ����Ȧ�������������\n";
	cout << "               2.��ѯĳ��Ȧĳͷ���״̬��Ϣ\n";
	cout << "               3.ͳ�Ƶ�ǰ����ÿ��Ʒ��������������ء�����ʱ��ֲ����\n";
	cout << "               4.��ѯ��5��������ۼ�¼�����̵Ĺ����¼\n";
	cout << "               5.��ʾ��ǰ�������������Ϣ\n";
	cout << "               6.����\n";
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
	cout << "            ��������Ҫ��Ҫ�Ĳ�����ţ�";
	while (cin >> mode)
	{
		switch (mode)
		{
			case 1:
			{
				menu_init();
				int choice1;
				while (cout << "            ��������Ҫ��Ҫ�Ĳ�����ţ�",cin >> choice1)
				{
					switch (choice1)
					{
						case 1:
						{
							check();
							int choice2;
							while(cout << "            ��������Ҫ��Ҫ�Ĳ�����ţ�",cin >> choice2)
							{
								switch (choice2)
								{
									case 1:
									{
										int num;
										cout << "��������Ȧ��ţ�";
										cin >> num;
										cout << "����Ȧ��" << pf[num].getcount() << "ͷ�������к���" << pf[num].getspecies1() << "ͷ��С����" << pf[num].getspecies2() << "ͷ����׻���" << pf[num].getspecies3() << "ͷ\n";
										break;
									}
									case 2: 
									{
										int num1, num2;
										cout << "��������Ȧ�ţ�";
										cin >> num1;
										while (1) 
										{
											if (num1 >= 0 && num1 < 100 && pf[num1].getcount() != 0)
												break;
											else 
												cout << "����ȦΪ�գ�����������"; cin >> num1;
										}
										cout << "����Ȧ����" << pf[num1].getcount() << "ͷ��,��������ı�ţ�";
										cin >> num2;
										while (1) 
										{
											if (!pf[num1].findpig(num2)) 
											{
												cout << "�������ڣ������ѳ�Ȧ,���߿��ܱ�Ź������������룺";
												cin >> num2;
											}
											else 
												break;
										}
										cout << "����Ϊ";
										if (pf[num1].getspecies(num2) == 1)
											cout << "��������Ϊ";
										if (pf[num1].getspecies(num2) == 2)
											cout << "С��������Ϊ";
										if (pf[num1].getspecies(num2) == 3)
											cout << "��׻�������Ϊ";
										cout << pf[num1].getweight(num2) << "kg,����ʱ��Ϊ";
										int month = pf[num1].getgrowmonth(num2), day = pf[num1].getgrowday(num2);
										while (day >= 30) 
										{
											day -= 30;
											month++;
										}
										if (month > 0)
											cout << month << "����"; 
										cout << day << "��\n";
										break;
									}
									case 3: 
									{
										if (pf->gethead() == nullptr)
										{
											cout << "Ŀǰ����������" << endl;
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
											cout << "��ǰ���У����������Ϊ��" << black_cnt << endl;
											for (int i = 0; i < 100; i++)
											{
												if (pf[i].getblack() == 1)
												{
													cout << "��" << i << "����Ȧ�Ǻ�����Ȧ��";
													pf[i].print_black();
													continue;
												}
												else
													continue;
											}
											cout << endl;
											cout << "��ǰ���У�С���������Ϊ��" << little_cnt << endl;
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
											cout << "��ǰ���У��󻨰��������Ϊ��" << big_cnt << endl;
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
											cout<<i<<"��Ȧ��";
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
								cout<<"����ʱ�䲻��3����,���߾����ϴγ�Ȧ�������ʱ�䲻��3����"<<endl;
								break;
							}
							double sellprice=0.0;
							for(int i=0;i<100;i++)
								sellprice+=pf[i].getprice();
							int temp=get_allpigs(pf),outpignum=allpig-temp;
							allpig=temp;
							cout<<"�˴γ�Ȧ������"<<outpignum<<"ͷ�������ۼ�Ϊ:"<<sellprice<<"Ԫ\n";
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
							cout << "δ���ĺ���Ȧ�ɹ���" << blackpig << "ͷ����ʣ�����Ȧ����" << blank_zj << endl;
							int black = 0, little = 0, big = 0, cost = 0;
							cout << "��ʾ��ÿͷ����2000Ԫ��ÿͷС����1500Ԫ��ÿͷ�󻨰���3000Ԫ����ǰ��" << money << endl;
							cout << "���������뱾�ι���ĺ���С�����󻨰�����" << endl;
							while(cin >> black >> little >> big)
							{
								cost = 2000 * black + 1500 * little + 3000 * big;
								if(black>blackpig+blank_zj*10||little>blank_zj*10+count||big>blank_zj*10+count||little+big>blank_zj*10+count)
									cout<<"�����������������������������룺\n";
								else if(money<cost)
									cout<<"ʣ���ʽ��㣬����������\n";
								else if(((blank_zj-(black-blackpig)/10)*10<=little+big)&&black>blackpig)
									cout<<"�������������ܻ��������������룺\n";
								else if(allpig+black+little+big>=1000)
								{
									cout<<"��������ģ��ǳ��ɹ���"<<endl;
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
				cout << "                                    ����                          \n";
				cout << '\n';
				cout << '\n';
				cout << "                  ��ʼ������200ֻ�����������20000Ԫ��ʼ�ʽ�\n";
				cout << "                  �ʽ𲻿��գ�������������Ӯ��\n";
				cout << '\n';
				cout << '\n';
				cout << "		                                       ����0�Է���\n";
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
