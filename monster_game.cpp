#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int diff;//定义难度
int xiaozhen;//定义选择项目

double health;//定义主角初始生命
double max_health;//定义最大生命
int attack;//定义主角初始攻击力
int defen;//定义主角初始防御力
int money;//定义主角初始金钱数量
int energy;//定义主角精力

bool clear;//定义是否通关判定
bool do_load = false;//定义是否在游戏开始时加载(debug)
//bool is_read = false;//定义是否已经读取存档 

void store_weapon();//定义武器店函数
void store_potion();//定义药店函数
void mon1();//定义小怪物函数，版本1.5.4后增强
void mon2();//定义大怪物函数
void talk();//交谈，1.2.6添加
void ads();//看广告加金币 ，1.4添加
void load();//加载界面，1.4.6添加
void train();//训练场，1.5.3增加
void game();//小游戏“探险者日记” 
void skill();//技能 1.8.3
void check();//检测自己状态 
/*
void read();//读取记录
void save();//进行存储 

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
    cout << "欢迎来到武器店！" << endl;
    cout << "1、小刀（10M加2攻击力）" << endl;
    cout << "2、短剑（80M加20攻击力）" << endl;
    cout << "3、大砍刀（140M加40攻击力)" << endl;
    cout << "4、双节棍（200M加60攻击力）" << endl;
    cout << "5、盾牌（60M加30防御力）" << endl;
    cout << "6、铠甲（100M加60防御力）" << endl;
    cout << "7、离开武器店" << endl;
    int c;
    cin >> c;
    while(c != 7) //输入7时结束函数
    {
        switch(c)
        {
        case 1:
            if(money < 10)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                attack += 2;
                money -= 10;
            }
            break;
        case 2:
            if(money < 80)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                attack += 20;
                money -= 80;
            }
            break;
        case 3:
            if(money < 140)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                attack += 40;
                money -= 140;
            }
            break;
        case 4:
            if(money < 200)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                attack += 60;
                money -= 200;
            }
            break;
        case 5:
            if(money < 60)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                defen += 30;
                money -= 60;
            }
            break;
        case 6:
            if(money < 100)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                defen += 60;
                money -= 100;
            }
            break;
        default:
            cout << "无商品！" << endl;
            break;
        }
        system("pause");
        system("cls");
        cout << "欢迎来到武器店！" << endl;
        cout << "1、买小刀（10M加2攻击力）" << endl;
        cout << "2、买短剑（80M加20攻击力）" << endl;
        cout << "3、买大砍刀（140M加40攻击力)" << endl;
        cout << "4、买双节棍（200M加60攻击力）" << endl;
        cout << "5、买盾牌（60M加30防御力）" << endl;
        cout << "6、买铠甲（100M加60防御力）" << endl;
        cout << "7、离开武器店" << endl;
        cin>>c;
    }
    cout << "欢迎下次再来！" << endl;
    system("pause");
}
void store_potion()
{
    cout << "欢迎来到药品店！" << endl;
    cout << "1、买1号药（10元+200生命，+2精力）" << endl;
    cout << "2、买2号药（50M元+1000生命，+6精力）" << endl;
    cout << "3、买3号药（100M元+2200生命，+12精力)" << endl;
    cout << "4、离开药店" << endl;
    int c;
    cin >> c;
    while(c != 4)
    {
        switch(c)
        {
        case 1:
            if(money < 10)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                health = min(max_health, health + 200);
                money -= 10;
                energy += 1;
            }
            break;
        case 2:
            if(money < 50)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                health = min(max_health, health + 1000);
                money -= 50;
                energy += 6;
            }
            break;
        case 3:
            if(money < 100)
                cout << "你的钱不够" << endl;
            else
            {
                cout << "购买成功！" << endl;
                health = min(max_health, health + 2200);
                money -= 100;
                energy += 12;
            }
            break;
        default:
            cout << "无商品！" << endl;
            break;
        }
        system("pause");
        system("cls");
        cout << "欢迎来到药品店！" << endl;
        cout << "1、买1号补血药（10M加200生命和1精力）" << endl;
        cout << "2、买2号补血药（50M加1000生命和6精力）" << endl;
        cout << "3、买3号补血药（100M加2200生命和12精力)" << endl;
        cout << "4、离开药店" << endl;
        cin >> c;
    }
    cout << "欢迎下次再来！" << endl;
    system("pause");
}
void mon1()
{
    system("cls");
    cout << "开始与小怪物战斗！！！" << endl;
    double g_shengmingli;//定义怪物生命
    int g_gongjili;//定义怪物攻击力
    int g_fangyuli;//定义怪物防御力
    int g_money;//定义怪物金钱
    g_shengmingli = rand() % 100 + 300;
    g_gongjili = rand() % 100 + 30;
    g_fangyuli = rand() % 100 + 30;
    g_money = rand() % 20 + 20;
    double tongji1 = 0;//用来计算主角对怪物的杀伤
    double tongji2 = 0;//用来计算怪物对主角的杀伤
    int huihe = 1;//定义回合数
    cout << "你开始对小怪物进行攻击！" << endl;
    //攻击计算公式：杀伤=攻击力*2-防御力，玩家每回合可以选择攻击与逃跑
    int c;
    while(g_shengmingli>0 && health > 0 && c != 2)
    {
        int g_suiji;
        if(diff < 2)
            g_suiji=0;
        else
            g_suiji = rand() % 110 + 5;
        cout << "现在是第" << huihe << "回合！" << endl;
        cout << "请选择你的动作：" << endl;
        cout << "1、攻击\n2、逃跑" << endl;
        cin >> c;
        switch(c)
        {
        case 1:
            cout << "你对小怪物发动了攻击！" << endl;
            cout << "你与小怪物战斗，精力-1" << endl;
            energy--;
            tongji1 = int(attack * 2 - g_fangyuli);
            if(tongji1 <= 0)
                tongji1 = 1;
            cout << "你打掉了小怪物" << tongji1 << "的生命！" << endl;
            g_shengmingli -= tongji1;
            if(g_shengmingli <= 0)
                cout << "小怪物还剩0点生命" << endl;
            else
                cout << "小怪物还剩" << g_shengmingli << "点生命" << endl;
            if(g_shengmingli <= 0)
            {
                //杀死怪物后的返回
                cout << "小怪物被你杀死了！你真厉害！" << endl;
                cout << "你挣了" << g_money << "元，";
                money += g_money;
                cout << "你现有" << money << "元" << endl;
                int g_jingli = rand() % 3 + 1;
                cout << "你精力大涨，精力+" << g_jingli << endl;
                energy += g_jingli;
                system("pause");
                break;
            }
            tongji2 = int(g_gongjili * 2 - defen + g_suiji);
            if(tongji2 <= 0)
                tongji2=1;
            health -= tongji2;
            cout << "小怪物对你发动了攻击！" << endl;
            if(huihe % 4 == 0 && diff >= 3 && rand() % 2)
            {
                cout << "小怪使用了技能“斩将”，你减少1500生命" << endl;
                health -= 1500;
            }
            else
                cout << "小怪物打掉了你"<<tongji2<<"的生命！" << endl;
            cout << "你还剩" << max(0.0, health) << "点生命" << endl;
            break;
        case 2:
            cout << "你决定逃跑！" << endl;
            if(!rand() % 10)
            {
                cout << "你在逃跑过程中扭伤了腿，精力-1" << endl;
                energy--;
            }
            else 
                cout << "逃跑成功！" << endl;
            continue;
        default:
            cout << "输入错误！" << endl;
            huihe--;
        }
        huihe++;
    }
    if(health <= 0)
    {
        //被怪物杀死后的返回
        cout << "你被小怪物杀死了！游戏结束！！！" << endl;
        cout << "即将返回主页面..." << endl;
        system("pause");
    }
    if(c == 2)
    {
        //逃跑的返回
        cout << "你逃回了小镇！" << endl;
        system("pause");
    }
}
void mon2()
{
    cout << "开始与大怪物战斗，精力-1" << endl;
    energy--;
    double g_shengmingli = rand() % 5000 + 7500;
    int g_gongjili = rand() % 100 + 150;
    int g_fangyuli = rand() % 30 + 85;
    double tongji1 = 0;
    double tongji2 = 0;
    int huihe = 1;
    cout << "你开始对大怪物进行攻击！" << endl;
    int c;
    while(g_shengmingli > 0 && health > 0 && c != 2)
    {
        int suiji = rand() % 100 + 20, g_suiji = rand() % 90 + 20;
        cout << "现在是第" << huihe << "回合！" << endl;
        cout << "请选择你的动作:" << endl;
        cout << "1、攻击\n2、逃跑" << endl;
        cin >> c;
        switch(c)
        {
        case 1:
            cout << "你对大怪物发动了攻击！" << endl;
            g_shengmingli -= int(attack * 3.5 - g_fangyuli + suiji);
            tongji1 = int(attack * 3.5- g_fangyuli+suiji);
            cout << "你打掉了大怪物" << tongji1 << "的生命！" << endl;
            if(g_shengmingli <= 0)
                cout << "大怪物还剩0点生命" << endl;
            else
                cout << "大怪物还剩" << g_shengmingli << "点生命" << endl;
            if(g_shengmingli <= 0)
            {
                cout << "大怪物被你杀死了，你真厉害！！" << endl;
                clear = true;
                system("pause");
                break;
            }
            health -= int(g_gongjili * 2 - defen + g_suiji);
            tongji2 = int(g_gongjili * 2 - defen + g_suiji);
            cout << "大怪物对你发动了攻击！" << endl;
            if(huihe >= 4 && diff >= 4 && rand() % 2)
            {
                cout << "大怪物杀神附身，你一不小心被刀砍中，流血身亡。" << endl;
                health = 0;
            }
            else
                cout << "大怪物打掉了你" << tongji2 << "的生命！" << endl;
            if(health <= 0)
                cout << "你还剩0点生命" << endl;
            else
                cout << "你还剩" << health << "点生命" << endl;
            break;
        case 2:
            cout << "你决定逃跑！" << endl;
            if(rand() % 2)
            {
                cout << "大怪物把你吓到了，你还在逃跑时扭伤了腿，精力值-2" << endl;
                energy -= 2;
            }
            continue;
        default:
            cout << "输入错误！" << endl;
            huihe--;
        }
        huihe++;
    }
    if(health <= 0)
    {
        cout << "你被大怪物杀死了！游戏结束！！！" << endl;
        cout << "即将返回主页面..." << endl;
        system("pause");
    }
    if(c == 2)
    {
        cout << "你逃回了小镇！" << endl;
        system("pause");
    }
}
void talk()
{
    int c1, c2;
    cout << "一个妇人面无表情地说：“你好。”" << endl;
    cout << "你要：1.说：“你怎么这么冷漠？”；2.说：“你也好。”；3.离开。" << endl;
    cin >> c1;
    switch(c1)
    {
    case 1:
        cout << "妇人：当然是为了试探你呀！" << endl;
        cout << "你于妇人谈的很投合，妇人告诉你，杀了大怪物，就可以离开这里。" << endl;
        break;
    case 2:
        cout << "妇人：嗯，你想知道怎么离开这里吗？" << endl;
        cout << "1.想；2.算了。" << endl;
        cin >> c2;
        switch(c2)
        {
        case 1:
            cout << "你于妇人谈的很投合，妇人告诉你，杀了大怪物，就可以离开这里。" << endl;
            break;
        case 2:
            cout << "妇人：哦，再见。" << endl;
            break;
        default:
            cout << "输入错误" << endl;
            break;
        }
        break;
    case 3:
        system("pause");
        break;
    default:
        cout << "输入错误" << endl;
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
        cout<< "欢迎来到我们的洛谷团队！https://www.luogu.com.cn/team/27254" << endl;
        break;
    case 1:
        cout << "公开版已经删除。" << endl;
        break;
    case 2:
        cout << "秘密之路，2020年3月制作，已经更新完成，欢迎找我下载，纯免费。" << endl;
        cout << "你是否要玩一下小游戏？入1开始，其他跳过" << endl;
        int x;
        cin >> x;
        if(x == 1)
            game(); 
        break;
    case 3:
        cout << "此栏暂无广告，可以花2元在此放置自己的广告！\n（要求：广告字数需小于80；广告中不得拥有粗鲁、下流的语言，不得发布有政治敏感，针对某人的广告。" << endl;
        break;
    default:
        cout << "你完成了成就：不可能的挑战！" << endl;
        cout << "（这是一个bug，遇到请速速联系作者)" << endl;
        cout << "作为你发现bug的奖励，给你一堆属性加成" << endl;
        health += rand();
        attack += rand();
        defen += rand();
        money += rand();
        energy += rand();
        break;
    }
    Sleep(15000);
    cout << "完成观看，获得了奖励:";
    int m = rand() % 200 * 2 + 30;
    cout << "获得" << m << "元" << endl;
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
        "小知识：怪物的血量和攻击力都是随机且不可见的，如果运气不好请准备好后再来！",
        "小知识：妇人会告诉你怎样通关游戏！",
        "小知识：如果实在没钱，可以看一段广告，广告时间十五秒！",
        "小知识：如果还有bug请联系作者",
        "小知识：生命值不能超过最大生命值"
    };
    for(int i = 0; i < 5; i++)
    {
        system("cls");
        cout << "加载中……" << prs[i] << "%" << endl;
        cout << progress[i] << endl;
        cout << tips[i] << endl;
        Sleep(rand() % 2000 + 1000);
    }
    system("cls");
    cout << "游戏加载成功！" << endl;
    system("pause");
}
void train()
{
    int train_time = rand() % 5 + 5;
    cout << "正在训练，需要花费" << train_time << "秒……" << endl;
    for(int i = train_time; i >= 0; i--)
    {
        system("cls");
        cout << "正在训练，需要花费" << train_time << "秒……" << endl;
        cout << "剩余" << i << "秒……" << endl;
        Sleep(1000);
    }
    int xz = rand() % 12 + 3, gz = rand() % 15 + 4;
    if(xz <= 0)
        xz = 1;
    if(gz <= 0)
        gz = 1;
    cout << "训练完成，精力-1，血量+" << xz << "，攻击+" << gz << endl;
    energy -- ; 
    health = min(max_health, health + xz);
    attack += gz;
    system("pause");
}
void check()
{
    cout << "你的生命值：" << health << endl;
    cout << "你的最大生命值：" << max_health << endl;
    cout << "你的攻击力：" << attack <<endl;
    cout << "你的防御力：" << defen << endl;
    cout << "你拥有的钱：" << money << endl;
    cout << "你的精力：" << energy << endl;
    system("pause");
}
void game()
{
    //奇奇怪怪的游戏
    cout << "欢迎来到小游戏，你的收益：350金币已经到账。" << endl;
    money += 350;
    int c1, c2, c3, c4, c5;//定义输入的五个变量 
    cout << "你是一个很饿的探险家，你面前有5条路，你会选择：" << endl;
    cout << "1.一条蜿蜒的小路" << endl;
    cout << "2.一条大马路" << endl;
    cout << "3.一条通往城市的路" << endl;
    cout << "4.一条通往秘密小镇的路" << endl;
    cout << "5.一条通往乡村的路" << endl;
    cin >> c1;
    switch(c1)
    {
    case 1:
        cout << "你选择了蜿蜒的小路" << endl;
        cout << "（剧情）你走了走，发现有一个古庙……" << endl;
        cout << "你要选择：" <<endl;
        cout << "1.回到岔路口" << endl;
        cout << "2.走进去" <<endl;
        cin >> c2;
        switch(c2)
        {
        case 1:
            cout << "你退了回去，但你已经饥肠辘辘，你饿死了。" << endl;
            cout << "游戏结束" << endl;
            break;
        case 2:
            cout << "你进了古庙，并没有收获。" << endl;
            cout << "你走时看见了一块肉，你吃了，并睡了一晚。" << endl;
            cout << "第二天……" << endl;
            cout << "你醒了，请问你下一步要……" << endl;
            cout << "1.随便走走" << endl;
            cout << "2.回到岔路口" << endl;
            cin >> c3;
            switch(c3)
            {
                case 1:
                    cout << "你随便走了走，饿死了。" << endl;
                    cout << "游戏结束" << endl;
                    break;
                case 2:
                    cout << "你退了回去，但你已经饥肠辘辘，你饿死了。" << endl;
                    cout << "游戏结束" << endl;
                    break;
                default:
                    cout << "输入错误！" << endl; 
            }
            break;
        default:
            cout << "输入错误！" << endl; 
        }
        break;
    case 2:
        cout << "你选择了大马路" << endl;
        cout << "你走了走，因为缺水而死。" << endl;
        cout << "游戏结束" << endl;
        break;
    case 3:
        cout << "你选择了大城市" << endl;
        cout << "你下一步要……" << endl;
        cout << "1.成就一番事业" << endl;
        cout << "2.平凡生活" << endl;
        cin >> c4;
        switch(c4)
        {
        case 1:
            cout << "你打算入股，你要选……" << endl;
            cout << "1.瑞和股 市值1299.99一股，十股起步" << endl;
            cout << "2.CP股 市值50.45一股，十股起步" << endl; 
            cin >> c5;
            switch(c5)
            {
            case 1:
                cout << "你大赚了一笔，触发了结局1……" << endl;
                cout << "你解锁了成就“大富翁”" << endl;
                break;
            case 2:
                cout << "你小赚了一笔，触发了结局2……" << endl;
                cout << "你解锁了成就“快乐一生”" << endl;
                break;
            }
            break;
        case 2:
            cout << "你安乐度过了一生，触发了结局3……" << endl;
            cout << "你解锁了成就“安乐公”" << endl;
            break;
        }
        break;
    case 4:
        cout << "你回到了秘密小镇." << endl;
        break;
    case 5:
        cout << "你选择了乡村小路" << endl;
        cout << "你发现了一个无人村……" << endl;
        cout << "请静待更新！" << endl;
        break; 
    default:
        cout << "输入错误！" << endl; 
    }
} 
void skill()
{
    cout << "等待更新中……";
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
        cout << "选择：1.开始新游戏，2.退出本游戏"/*3.读取存档*/ << endl;
        cin>>xuanze;
        if(xuanze==2)
        {
            /*
            int xuanze888;
            cout << "是否存储？0.no,1.yes" << endl; 
            cin>>xuanze888;
            if(xuanze888==0);
            else
                save();
            */
            cout << "欢迎下次来玩！" << endl;
            return 0;
        }
        /*
        if(xuanze==3)
        {
            read();
            is_read = true;
            cout << "读取存档成功！" << endl; 
        }
        */
        cout << "选择难度：\n0.简单\n1.正常\n2.高级\n3.精英\n4.噩梦\n5.挑战不可能！（目前未开放）" << endl;
        cin >> xuanze;
        switch(xuanze)
        {
        case 0:
            max_health = health = 2500;//重新定义主角初始生命值和最大生命值 
            attack = 140;//重新定义主角初始攻击力
            defen = 250;//重新定义主角初始防御力
            money = 65;//重新定义主角初始金钱数量
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
            cout << "此难度极难，请做好心理准备！" << endl;
            system("color 04");
            max_health = health = 700;
            attack = 45;
            defen = 75;
            money = 10;
            energy = 10;
            break;
        default:
            //read();
            //cout << "已获取存档" << endl;
            break;
        }
        diff = xuanze;
        while(true)
        {
            int qxiaozhen = xiaozhen;
            system("cls");
            cout << "欢迎你来玩打怪物小游戏！" << endl;
            cout << "精力小于10会有概率暴毙哟！" << endl;
            cout << "你来到了一个1000年前的小镇" << endl;
            cout << "周围有一条河，有一片树林，很多房子和很多人。"<< endl;
            cout << "这里还有一家药店和一家武器店" << endl;
            cout << "请做出你的选择：" << endl;
            cout << "1.去武器店" << endl;
            cout << "2.去药品店" << endl;
            cout << "3.去打小怪物" << endl;
            cout << "4.去打大怪物" << endl;
            cout << "5.退出游戏" << endl;
            cout << "6.显示你的状态" << endl;
            cout << "7.交谈"  <<endl;
            if(xuanze != 8 && xuanze != 6 && diff <= 2)
                cout << "8.看广告得随机奖励" << endl;
            cout << "9.去训练场" << endl;
            cout << "10.学习技能" << endl; 
            if(health <= 0)//主角生命力小于等于0时死亡
            { 
                cout << "你死啦！" << endl;
                system("pause");
                system("cls");
                break;
            }
            if(energy < 10)//主角精力小于10时有几率死亡
            {
                if(rand () % energy == 1)
                    cout << "你精力不足，在散步的过程中吐血身亡了。" << endl;
                system("pause");
                system("cls");
                break;
            }
            if(clear)
            {
                cout << "恭喜通关！" << endl;
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
                cout << "欢迎下次来玩！" << endl; 
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
                    cout << "你刚才已经来过了，请先干其他的事！" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                if(diff >= 3)
                {
                    cout << "此难度不开放广告！" << endl;
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
                cout << "输入错误" << endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }
    return 0;
}
