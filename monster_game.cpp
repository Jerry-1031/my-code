#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int diff;//�����Ѷ�
int xiaozhen;//����ѡ����Ŀ

double health;//�������ǳ�ʼ����
double max_health;//�����������
int attack;//�������ǳ�ʼ������
int defen;//�������ǳ�ʼ������
int money;//�������ǳ�ʼ��Ǯ����
int energy;//�������Ǿ���

bool clear;//�����Ƿ�ͨ���ж�
bool do_load = false;//�����Ƿ�����Ϸ��ʼʱ����(debug)
//bool is_read = false;//�����Ƿ��Ѿ���ȡ�浵 

void store_weapon();//���������꺯��
void store_potion();//����ҩ�꺯��
void mon1();//����С���ﺯ�����汾1.5.4����ǿ
void mon2();//�������ﺯ��
void talk();//��̸��1.2.6���
void ads();//�����ӽ�� ��1.4���
void load();//���ؽ��棬1.4.6���
void train();//ѵ������1.5.3����
void game();//С��Ϸ��̽�����ռǡ� 
void skill();//���� 1.8.3
void check();//����Լ�״̬ 
/*
void read();//��ȡ��¼
void save();//���д洢 

void read()
{
    is_read = true;
    freopen("pos.txt","r",stdin);
    cin >> attack;
    attack -= 522;
    cin>>money;
    money-=1321;
    cin>>energy;
    energy-=1428;
    cin>>defen;
    defen-=1530;
    cin>>diff;
    diff-=1823;
    fclose(stdin);
}
void save()
{
    freopen("pos.txt","w",stdout);
    cout << 1321 << endl;
    remove("pos.txt");
    freopen("pos.txt","w",stdout);
    cout<<attack+522<<endl;
    cout<<money+1321<<endl;
    cout<<energy+1428<<endl;
    cout<<defen+1530<<endl;
    cout<<diff+1823<<endl;
    fclose(stdin);
}
*/
void store_weapon()
{
    cout << "��ӭ���������꣡" << endl;
    cout << "1��С����10M��2��������" << endl;
    cout << "2���̽���80M��20��������" << endl;
    cout << "3���󿳵���140M��40������)" << endl;
    cout << "4��˫�ڹ���200M��60��������" << endl;
    cout << "5�����ƣ�60M��30��������" << endl;
    cout << "6�����ף�100M��60��������" << endl;
    cout << "7���뿪������" << endl;
    int c;
    cin >> c;
    while(c != 7) //����7ʱ��������
    {
        switch(c)
        {
        case 1:
            if(money < 10)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                attack += 2;
                money -= 10;
            }
            break;
        case 2:
            if(money < 80)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                attack += 20;
                money -= 80;
            }
            break;
        case 3:
            if(money < 140)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                attack += 40;
                money -= 140;
            }
            break;
        case 4:
            if(money < 200)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                attack += 60;
                money -= 200;
            }
            break;
        case 5:
            if(money < 60)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                defen += 30;
                money -= 60;
            }
            break;
        case 6:
            if(money < 100)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                defen += 60;
                money -= 100;
            }
            break;
        default:
            cout << "����Ʒ��" << endl;
            break;
        }
        system("pause");
        system("cls");
        cout << "��ӭ���������꣡" << endl;
        cout << "1����С����10M��2��������" << endl;
        cout << "2����̽���80M��20��������" << endl;
        cout << "3����󿳵���140M��40������)" << endl;
        cout << "4����˫�ڹ���200M��60��������" << endl;
        cout << "5������ƣ�60M��30��������" << endl;
        cout << "6�������ף�100M��60��������" << endl;
        cout << "7���뿪������" << endl;
        cin>>c;
    }
    cout << "��ӭ�´�������" << endl;
    system("pause");
}
void store_potion()
{
    cout << "��ӭ����ҩƷ�꣡" << endl;
    cout << "1����1��ҩ��10Ԫ+200������+2������" << endl;
    cout << "2����2��ҩ��50MԪ+1000������+6������" << endl;
    cout << "3����3��ҩ��100MԪ+2200������+12����)" << endl;
    cout << "4���뿪ҩ��" << endl;
    int c;
    cin >> c;
    while(c != 4)
    {
        switch(c)
        {
        case 1:
            if(money < 10)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                health = min(max_health, health + 200);
                money -= 10;
                energy += 1;
            }
            break;
        case 2:
            if(money < 50)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                health = min(max_health, health + 1000);
                money -= 50;
                energy += 6;
            }
            break;
        case 3:
            if(money < 100)
                cout << "���Ǯ����" << endl;
            else
            {
                cout << "����ɹ���" << endl;
                health = min(max_health, health + 2200);
                money -= 100;
                energy += 12;
            }
            break;
        default:
            cout << "����Ʒ��" << endl;
            break;
        }
        system("pause");
        system("cls");
        cout << "��ӭ����ҩƷ�꣡" << endl;
        cout << "1����1�Ų�Ѫҩ��10M��200������1������" << endl;
        cout << "2����2�Ų�Ѫҩ��50M��1000������6������" << endl;
        cout << "3����3�Ų�Ѫҩ��100M��2200������12����)" << endl;
        cout << "4���뿪ҩ��" << endl;
        cin >> c;
    }
    cout << "��ӭ�´�������" << endl;
    system("pause");
}
void mon1()
{
    system("cls");
    cout << "��ʼ��С����ս��������" << endl;
    double g_shengmingli;//�����������
    int g_gongjili;//������﹥����
    int g_fangyuli;//������������
    int g_money;//��������Ǯ
    g_shengmingli = rand() % 100 + 300;
    g_gongjili = rand() % 100 + 30;
    g_fangyuli = rand() % 100 + 30;
    g_money = rand() % 20 + 20;
    double tongji1 = 0;//�����������ǶԹ����ɱ��
    double tongji2 = 0;//���������������ǵ�ɱ��
    int huihe = 1;//����غ���
    cout << "�㿪ʼ��С������й�����" << endl;
    //�������㹫ʽ��ɱ��=������*2-�����������ÿ�غϿ���ѡ�񹥻�������
    int c;
    while(g_shengmingli>0 && health > 0 && c != 2)
    {
        int g_suiji;
        if(diff < 2)
            g_suiji=0;
        else
            g_suiji = rand() % 110 + 5;
        cout << "�����ǵ�" << huihe << "�غϣ�" << endl;
        cout << "��ѡ����Ķ�����" << endl;
        cout << "1������\n2������" << endl;
        cin >> c;
        switch(c)
        {
        case 1:
            cout << "���С���﷢���˹�����" << endl;
            cout << "����С����ս��������-1" << endl;
            energy--;
            tongji1 = int(attack * 2 - g_fangyuli);
            if(tongji1 <= 0)
                tongji1 = 1;
            cout << "������С����" << tongji1 << "��������" << endl;
            g_shengmingli -= tongji1;
            if(g_shengmingli <= 0)
                cout << "С���ﻹʣ0������" << endl;
            else
                cout << "С���ﻹʣ" << g_shengmingli << "������" << endl;
            if(g_shengmingli <= 0)
            {
                //ɱ�������ķ���
                cout << "С���ﱻ��ɱ���ˣ�����������" << endl;
                cout << "������" << g_money << "Ԫ��";
                money += g_money;
                cout << "������" << money << "Ԫ" << endl;
                int g_jingli = rand() % 3 + 1;
                cout << "�㾫�����ǣ�����+" << g_jingli << endl;
                energy += g_jingli;
                system("pause");
                break;
            }
            tongji2 = int(g_gongjili * 2 - defen + g_suiji);
            if(tongji2 <= 0)
                tongji2=1;
            health -= tongji2;
            cout << "С������㷢���˹�����" << endl;
            if(huihe % 4 == 0 && diff >= 3 && rand() % 2)
            {
                cout << "С��ʹ���˼��ܡ�ն�����������1500����" << endl;
                health -= 1500;
            }
            else
                cout << "С����������"<<tongji2<<"��������" << endl;
            cout << "�㻹ʣ" << max(0.0, health) << "������" << endl;
            break;
        case 2:
            cout << "��������ܣ�" << endl;
            if(!rand() % 10)
            {
                cout << "�������ܹ�����Ť�����ȣ�����-1" << endl;
                energy--;
            }
            else 
                cout << "���ܳɹ���" << endl;
            continue;
        default:
            cout << "�������" << endl;
            huihe--;
        }
        huihe++;
    }
    if(health <= 0)
    {
        //������ɱ����ķ���
        cout << "�㱻С����ɱ���ˣ���Ϸ����������" << endl;
        cout << "����������ҳ��..." << endl;
        system("pause");
    }
    if(c == 2)
    {
        //���ܵķ���
        cout << "���ӻ���С��" << endl;
        system("pause");
    }
}
void mon2()
{
    cout << "��ʼ������ս��������-1" << endl;
    energy--;
    double g_shengmingli = rand() % 5000 + 7500;
    int g_gongjili = rand() % 100 + 150;
    int g_fangyuli = rand() % 30 + 85;
    double tongji1 = 0;
    double tongji2 = 0;
    int huihe = 1;
    cout << "�㿪ʼ�Դ������й�����" << endl;
    int c;
    while(g_shengmingli > 0 && health > 0 && c != 2)
    {
        int suiji = rand() % 100 + 20, g_suiji = rand() % 90 + 20;
        cout << "�����ǵ�" << huihe << "�غϣ�" << endl;
        cout << "��ѡ����Ķ���:" << endl;
        cout << "1������\n2������" << endl;
        cin >> c;
        switch(c)
        {
        case 1:
            cout << "��Դ���﷢���˹�����" << endl;
            g_shengmingli -= int(attack * 3.5 - g_fangyuli + suiji);
            tongji1 = int(attack * 3.5- g_fangyuli+suiji);
            cout << "�����˴����" << tongji1 << "��������" << endl;
            if(g_shengmingli <= 0)
                cout << "����ﻹʣ0������" << endl;
            else
                cout << "����ﻹʣ" << g_shengmingli << "������" << endl;
            if(g_shengmingli <= 0)
            {
                cout << "����ﱻ��ɱ���ˣ�������������" << endl;
                clear = true;
                system("pause");
                break;
            }
            health -= int(g_gongjili * 2 - defen + g_suiji);
            tongji2 = int(g_gongjili * 2 - defen + g_suiji);
            cout << "�������㷢���˹�����" << endl;
            if(huihe >= 4 && diff >= 4 && rand() % 2)
            {
                cout << "�����ɱ������һ��С�ı������У���Ѫ������" << endl;
                health = 0;
            }
            else
                cout << "�����������" << tongji2 << "��������" << endl;
            if(health <= 0)
                cout << "�㻹ʣ0������" << endl;
            else
                cout << "�㻹ʣ" << health << "������" << endl;
            break;
        case 2:
            cout << "��������ܣ�" << endl;
            if(rand() % 2)
            {
                cout << "���������ŵ��ˣ��㻹������ʱŤ�����ȣ�����ֵ-2" << endl;
                energy -= 2;
            }
            continue;
        default:
            cout << "�������" << endl;
            huihe--;
        }
        huihe++;
    }
    if(health <= 0)
    {
        cout << "�㱻�����ɱ���ˣ���Ϸ����������" << endl;
        cout << "����������ҳ��..." << endl;
        system("pause");
    }
    if(c == 2)
    {
        cout << "���ӻ���С��" << endl;
        system("pause");
    }
}
void talk()
{
    int c1, c2;
    cout << "һ���������ޱ����˵������á���" << endl;
    cout << "��Ҫ��1.˵��������ô��ô��Į������2.˵������Ҳ�á�����3.�뿪��" << endl;
    cin >> c1;
    switch(c1)
    {
    case 1:
        cout << "���ˣ���Ȼ��Ϊ����̽��ѽ��" << endl;
        cout << "���ڸ���̸�ĺ�Ͷ�ϣ����˸����㣬ɱ�˴����Ϳ����뿪���" << endl;
        break;
    case 2:
        cout << "���ˣ��ţ�����֪����ô�뿪������" << endl;
        cout << "1.�룻2.���ˡ�" << endl;
        cin >> c2;
        switch(c2)
        {
        case 1:
            cout << "���ڸ���̸�ĺ�Ͷ�ϣ����˸����㣬ɱ�˴����Ϳ����뿪���" << endl;
            break;
        case 2:
            cout << "���ˣ�Ŷ���ټ���" << endl;
            break;
        default:
            cout << "�������" << endl;
            break;
        }
        break;
    case 3:
        system("pause");
        break;
    default:
        cout << "�������" << endl;
        break;
    }
    system("pause");
}
void ads()
{
    int c = rand() % 4;
    system("cls");
    switch(c)
    {
    case 0:
        cout<< "��ӭ�������ǵ�����Ŷӣ�https://www.luogu.com.cn/team/27254" << endl;
        break;
    case 1:
        cout << "�������Ѿ�ɾ����" << endl;
        break;
    case 2:
        cout << "����֮·��2020��3���������Ѿ�������ɣ���ӭ�������أ�����ѡ�" << endl;
        cout << "���Ƿ�Ҫ��һ��С��Ϸ����1��ʼ����������" << endl;
        int x;
        cin >> x;
        if(x == 1)
            game(); 
        break;
    case 3:
        cout << "�������޹�棬���Ի�2Ԫ�ڴ˷����Լ��Ĺ�棡\n��Ҫ�󣺹��������С��80������в���ӵ�д�³�����������ԣ����÷������������У����ĳ�˵Ĺ�档" << endl;
        break;
    default:
        cout << "������˳ɾͣ������ܵ���ս��" << endl;
        cout << "������һ��bug��������������ϵ����)" << endl;
        cout << "��Ϊ�㷢��bug�Ľ���������һ�����Լӳ�" << endl;
        health += rand();
        attack += rand();
        defen += rand();
        money += rand();
        energy += rand();
        break;
    }
    Sleep(15000);
    cout << "��ɹۿ�������˽���:";
    int m = rand() % 200 * 2 + 30;
    cout << "���" << m << "Ԫ" << endl;
    money += m;
    system("pause");
}
void load()
{
    int prs[5] = {0, 23, 51, 82, 100};
    string progress[5] = 
    {
        "-------------",
        "===----------",
        "=======------",
        "==========---",
        "============="
    };
    string tips[5] = 
    {
        "С֪ʶ�������Ѫ���͹�������������Ҳ��ɼ��ģ��������������׼���ú�������",
        "С֪ʶ�����˻����������ͨ����Ϸ��",
        "С֪ʶ�����ʵ��ûǮ�����Կ�һ�ι�棬���ʱ��ʮ���룡",
        "С֪ʶ���������bug����ϵ����",
        "С֪ʶ������ֵ���ܳ����������ֵ"
    };
    for(int i = 0; i < 5; i++)
    {
        system("cls");
        cout << "�����С���" << prs[i] << "%" << endl;
        cout << progress[i] << endl;
        cout << tips[i] << endl;
        Sleep(rand() % 2000 + 1000);
    }
    system("cls");
    cout << "��Ϸ���سɹ���" << endl;
    system("pause");
}
void train()
{
    int train_time = rand() % 5 + 5;
    cout << "����ѵ������Ҫ����" << train_time << "�롭��" << endl;
    for(int i = train_time; i >= 0; i--)
    {
        system("cls");
        cout << "����ѵ������Ҫ����" << train_time << "�롭��" << endl;
        cout << "ʣ��" << i << "�롭��" << endl;
        Sleep(1000);
    }
    int xz = rand() % 12 + 3, gz = rand() % 15 + 4;
    if(xz <= 0)
        xz = 1;
    if(gz <= 0)
        gz = 1;
    cout << "ѵ����ɣ�����-1��Ѫ��+" << xz << "������+" << gz << endl;
    energy -- ; 
    health = min(max_health, health + xz);
    attack += gz;
    system("pause");
}
void check()
{
    cout << "�������ֵ��" << health << endl;
    cout << "����������ֵ��" << max_health << endl;
    cout << "��Ĺ�������" << attack <<endl;
    cout << "��ķ�������" << defen << endl;
    cout << "��ӵ�е�Ǯ��" << money << endl;
    cout << "��ľ�����" << energy << endl;
    system("pause");
}
void game()
{
    //����ֵֹ���Ϸ
    cout << "��ӭ����С��Ϸ��������棺350����Ѿ����ˡ�" << endl;
    money += 350;
    int c1, c2, c3, c4, c5;//���������������� 
    cout << "����һ���ܶ���̽�ռң�����ǰ��5��·�����ѡ��" << endl;
    cout << "1.һ�����ѵ�С·" << endl;
    cout << "2.һ������·" << endl;
    cout << "3.һ��ͨ�����е�·" << endl;
    cout << "4.һ��ͨ������С���·" << endl;
    cout << "5.һ��ͨ������·" << endl;
    cin >> c1;
    switch(c1)
    {
    case 1:
        cout << "��ѡ�������ѵ�С·" << endl;
        cout << "�����飩�������ߣ�������һ��������" << endl;
        cout << "��Ҫѡ��" <<endl;
        cout << "1.�ص���·��" << endl;
        cout << "2.�߽�ȥ" <<endl;
        cin >> c2;
        switch(c2)
        {
        case 1:
            cout << "�����˻�ȥ�������Ѿ������ꤣ�������ˡ�" << endl;
            cout << "��Ϸ����" << endl;
            break;
        case 2:
            cout << "����˹�����û���ջ�" << endl;
            cout << "����ʱ������һ���⣬����ˣ���˯��һ��" << endl;
            cout << "�ڶ��졭��" << endl;
            cout << "�����ˣ���������һ��Ҫ����" << endl;
            cout << "1.�������" << endl;
            cout << "2.�ص���·��" << endl;
            cin >> c3;
            switch(c3)
            {
                case 1:
                    cout << "����������ߣ������ˡ�" << endl;
                    cout << "��Ϸ����" << endl;
                    break;
                case 2:
                    cout << "�����˻�ȥ�������Ѿ������ꤣ�������ˡ�" << endl;
                    cout << "��Ϸ����" << endl;
                    break;
                default:
                    cout << "�������" << endl; 
            }
            break;
        default:
            cout << "�������" << endl; 
        }
        break;
    case 2:
        cout << "��ѡ���˴���·" << endl;
        cout << "�������ߣ���Ϊȱˮ������" << endl;
        cout << "��Ϸ����" << endl;
        break;
    case 3:
        cout << "��ѡ���˴����" << endl;
        cout << "����һ��Ҫ����" << endl;
        cout << "1.�ɾ�һ����ҵ" << endl;
        cout << "2.ƽ������" << endl;
        cin >> c4;
        switch(c4)
        {
        case 1:
            cout << "�������ɣ���Ҫѡ����" << endl;
            cout << "1.��͹� ��ֵ1299.99һ�ɣ�ʮ����" << endl;
            cout << "2.CP�� ��ֵ50.45һ�ɣ�ʮ����" << endl; 
            cin >> c5;
            switch(c5)
            {
            case 1:
                cout << "���׬��һ�ʣ������˽��1����" << endl;
                cout << "������˳ɾ͡����̡�" << endl;
                break;
            case 2:
                cout << "��С׬��һ�ʣ������˽��2����" << endl;
                cout << "������˳ɾ͡�����һ����" << endl;
                break;
            }
            break;
        case 2:
            cout << "�㰲�ֶȹ���һ���������˽��3����" << endl;
            cout << "������˳ɾ͡����ֹ���" << endl;
            break;
        }
        break;
    case 4:
        cout << "��ص�������С��." << endl;
        break;
    case 5:
        cout << "��ѡ�������С·" << endl;
        cout << "�㷢����һ�����˴塭��" << endl;
        cout << "�뾲�����£�" << endl;
        break; 
    default:
        cout << "�������" << endl; 
    }
} 
void skill()
{
    cout << "�ȴ������С���";
}
int main()
{
    srand(time(0));
    int xuanze;
    if(do_load)
        load();
    system("cls");
    while(true)
    {
        cout << "ѡ��1.��ʼ����Ϸ��2.�˳�����Ϸ"/*3.��ȡ�浵*/ << endl;
        cin>>xuanze;
        if(xuanze==2)
        {
            /*
            int xuanze888;
            cout << "�Ƿ�洢��0.no,1.yes" << endl; 
            cin>>xuanze888;
            if(xuanze888==0);
            else
                save();
            */
            cout << "��ӭ�´����棡" << endl;
            return 0;
        }
        /*
        if(xuanze==3)
        {
            read();
            is_read = true;
            cout << "��ȡ�浵�ɹ���" << endl; 
        }
        */
        cout << "ѡ���Ѷȣ�\n0.��\n1.����\n2.�߼�\n3.��Ӣ\n4.ج��\n5.��ս�����ܣ���Ŀǰδ���ţ�" << endl;
        cin >> xuanze;
        switch(xuanze)
        {
        case 0:
            max_health = health = 2500;//���¶������ǳ�ʼ����ֵ���������ֵ 
            attack = 140;//���¶������ǳ�ʼ������
            defen = 250;//���¶������ǳ�ʼ������
            money = 65;//���¶������ǳ�ʼ��Ǯ����
            energy = 30;
            break;
        case 1:
            system("color 3F");
            max_health = health = 2150;
            attack = 115;
            defen = 180;
            money = 45;
            energy = 25;
            break;
        case 2:
            system("color 59");
            max_health = health = 1890;
            attack = 90;
            defen = 145;
            money = 25;
            energy = 20;
            break;
        case 3:
            system("color 4E");
            max_health = health = 1500;
            attack = 75;
            defen = 120;
            money = 15;
            energy = 15;
            break;
        case 4:
            cout << "���Ѷȼ��ѣ�����������׼����" << endl;
            system("color 04");
            max_health = health = 700;
            attack = 45;
            defen = 75;
            money = 10;
            energy = 10;
            break;
        default:
            //read();
            //cout << "�ѻ�ȡ�浵" << endl;
            break;
        }
        diff = xuanze;
        while(true)
        {
            int qxiaozhen = xiaozhen;
            system("cls");
            cout << "��ӭ����������С��Ϸ��" << endl;
            cout << "����С��10���и��ʱ���Ӵ��" << endl;
            cout << "��������һ��1000��ǰ��С��" << endl;
            cout << "��Χ��һ���ӣ���һƬ���֣��ܶ෿�Ӻͺܶ��ˡ�"<< endl;
            cout << "���ﻹ��һ��ҩ���һ��������" << endl;
            cout << "���������ѡ��" << endl;
            cout << "1.ȥ������" << endl;
            cout << "2.ȥҩƷ��" << endl;
            cout << "3.ȥ��С����" << endl;
            cout << "4.ȥ������" << endl;
            cout << "5.�˳���Ϸ" << endl;
            cout << "6.��ʾ���״̬" << endl;
            cout << "7.��̸"  <<endl;
            if(xuanze != 8 && xuanze != 6 && diff <= 2)
                cout << "8.�������������" << endl;
            cout << "9.ȥѵ����" << endl;
            cout << "10.ѧϰ����" << endl; 
            if(health <= 0)//����������С�ڵ���0ʱ����
            { 
                cout << "��������" << endl;
                system("pause");
                system("cls");
                break;
            }
            if(energy < 10)//���Ǿ���С��10ʱ�м�������
            {
                if(rand () % energy == 1)
                    cout << "�㾫�����㣬��ɢ���Ĺ�������Ѫ�����ˡ�" << endl;
                system("pause");
                system("cls");
                break;
            }
            if(clear)
            {
                cout << "��ϲͨ�أ�" << endl;
                system("pause");
                system("cls");
                break;
            }
            cin >> xiaozhen;
            switch(xiaozhen)
            {
            case 1:
                system("cls");
                store_weapon();
                break;
            case 2:
                system("cls");
                store_potion();
                break;
            case 3:
                system("cls");
                mon1();
                break;
            case 4:
                system("cls");
                mon2();
                break;
            case 5:
                system("cls");
                cout << "��ӭ�´����棡" << endl; 
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                check();
                break;
            case 7:
                system("cls");
                talk();
                break;
            case 8:
                if(qxiaozhen == 8 || qxiaozhen == 6)
                {
                    cout << "��ղ��Ѿ������ˣ����ȸ��������£�" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                if(diff >= 3)
                {
                    cout << "���ѶȲ����Ź�棡" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                system("cls");
                ads();
                break;
            case 9:
                system("cls");
                train();
                break;
            case 10:
                system("cls");
                skill();
                break;
            default:
                cout << "�������" << endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }
    return 0;
}
