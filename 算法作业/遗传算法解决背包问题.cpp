#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>

#define PACK_MAX_CAPACITY  80
#define PACK_MAX_VOLUME 75
#define MAX_GENERATION 100
using namespace std;
static string data("11,12,8,22,15,9,12,4,15,21,5,6,21,10,16,13,19,9,1,21,1,\
10,20,4,13,8,14,8,13,9,6,2,3,25,3,7,13,3,12,27,17,4,12,12,15,23,5,5,12,12,18,\
24,4,5,23,1,15,11,21,4,6,14,6,24,23,2,28,17,12,10,15,14,20,20,11,13,22,9,25,25,13,\
23,0,13,5,22,14,26,15,13,30,25,19,15,13,4");
struct Item{
    Item(int vol, int w, int v) : volume(vol), weight(w), value(v) {}
    int volume;
    int weight;
    int value;
};
struct Entity{
    Entity(int goods_num): fitness(0),sum_weight(0),generation_id(0) {InitGene(goods_num);};
    Entity() : fitness(0),sum_weight(0),generation_id(0) {gene.clear();};
    void InitGene(int goods_num){gene.assign(goods_num, 0); }
    int fitness;
    int sum_weight;
    int sum_volume;
    int generation_id;
    vector<int> gene;
};
static float Rand_Float()
{


    return rand() % 1000 / 1000.0 ;
}
static std::string Int_2_String(int n)
{
    ostringstream out;
    out<< n ;
    return out.str();
}
class GA{
public:
    static bool EntitySort(const Entity &one,const Entity &two){return one.fitness <= two.fitness;};

    static float TotalFitness(const std::vector<Entity> &group)
    {
        float sum = 0.0;
        for (size_t i = 0; i < group.size(); i++)
        {
            sum += group[i].fitness;
        }
        return sum;
    }
public:
    GA(int gn,float cr,float vr,int goods_n) : t_group_num(gn), t_cross_rate(cr),
        t_varia_rate(vr), t_goods_num(goods_n)
    {Init_Goods();}

    void Run(){
        //初始化种群
        Init_Group();
        //开始迭代
        for(int i=0;i< MAX_GENERATION; i++){
            // 计算本代个体适应度
            CalcFitness();
            //排序，记录良好的点
            RecordOptimalEntity(i) ;
            //自然选择 1 选择最好的10% 2 随机出40%的基因
            Select();
            //交流 将个体扩展到原始群体大小
            Cross();
            //变异
            if(i%10==0&& i!= 0) Variation();
        }
    }

    void PrintOptimal()
    {
        std::cout << "最优解在第" + Int_2_String(best_entity.generation_id) + "代" << std::endl;
        std::cout << "总体积： "<<  best_entity.sum_volume <<"，总重量：" << best_entity.sum_weight << "，总价值：" << best_entity.fitness << std::endl;
        std::cout << "放入物品排列为：";
        for (size_t i = 0; i < best_entity.gene.size(); i++)
        {
            std::cout << best_entity.gene[i] << ",";
        }
        std::cout << std::endl;
    }

private:
    vector<vector<int> > split(string str,string pattern){
    string::size_type pos;
    vector<int> input_line;
    vector<vector<int> > res;
    str+=pattern;
    int size = str.size();
    for(int i=0;i<size;i++){
        pos = str.find(pattern,i);
        if(pos<size){
            string s = str.substr(i,pos-i);
            istringstream iss(s);
            int num ;
            iss >> num ;
            input_line.push_back(num);
            i = pos+pattern.size()-1;
        }
    }
    for(int i=0;(i+2)<input_line.size();i+=3){
        vector<int> temp;
        temp.push_back(input_line[i]);
        temp.push_back(input_line[i+1]);
        temp.push_back(input_line[i+2]);
        res.push_back(temp);
    }
    return res;
}
    void Init_Goods(){
        vector<vector<int> > res = split(data,",");
        for(int i=0;i<t_goods_num;i++){
        // cout<< "first:" << res[i].first << "second:" << res[i].second << endl ;
        t_goods.push_back(Item(res[i][0],res[i][1],res[i][2]));
        }
    }

    void Init_Group(){
        t_group.clear();
        best_entity.InitGene(t_goods_num);

        int volume=0, weight =0, count_n = 0;
        for(int i =0;i< t_group_num ;i++){
            t_group.push_back(Entity(t_goods_num));
            Entity &en = t_group.back();
            float capcity = (rand()%50 + 50) * PACK_MAX_CAPACITY;
            float vol = (rand()%50 + 50) * PACK_MAX_VOLUME;
            volume =0;
            weight = 0;
            count_n = 0;
            while(weight <= capcity&&volume<vol){
                int idx = rand() % t_goods_num ;
                if(count_n == 3) break;
                if(en.gene[idx]){count_n++ ; continue ;}
                en.gene[idx] =1;
                weight+= t_goods[idx].weight;
            }
        }
    };

    void CalcFitness(){
        for(int i=0;i<t_group.size();i++){
            Entity &en = t_group[i];
            int volume = 0 , weight = 0, value =0;
            for(int j=0;j<en.gene.size();j++){
                if(en.gene[j]){
                    volume += t_goods[j].volume;
                    weight += t_goods[j].weight;
                    value += t_goods[j].value;
                }
            }
            if(weight > PACK_MAX_CAPACITY||volume>PACK_MAX_VOLUME ) {en.fitness = 0; continue; }

            en.fitness = value;
            en.sum_weight = weight;
            en.sum_volume = volume;
        }
    }

    void RecordOptimalEntity(int id){
        stable_sort(t_group.begin(),t_group.end(),GA::EntitySort);
        Entity &en = t_group.back();
        if(en.fitness > best_entity.fitness ){
            best_entity = en ;
            best_entity.generation_id = id;
        }
        cout<<"第"+Int_2_String(id)+"代最优个体体积"+Int_2_String(en.sum_volume)+"重量:"+Int_2_String(en.sum_weight)+"总价值:"+Int_2_String(en.fitness)+"该序列为";
        for(int i=0;i<en.gene.size();i++){
            cout<<en.gene[i]<<",";
        }
        cout<<endl;
    }

    void Select(){
        vector<Entity> new_group;
        stable_sort(t_group.begin(),t_group.end(),GA::EntitySort);
        int src_group_num = t_group.size();
        int reserve_num = (int)(src_group_num*0.1);
        for(int i=0;i< reserve_num;i++){
            new_group.push_back(t_group.back());
            t_group.pop_back();
        }
        std::vector<float>  selected_rate;
        float sum_fitness = GA::TotalFitness(t_group);
        selected_rate.push_back(t_group[0].fitness / sum_fitness);
        for(int i = 1; i < t_group.size(); i++)
        {
            float cur_rate = selected_rate.back() + (t_group[i].fitness / sum_fitness);
            selected_rate.push_back(cur_rate);
        }

        int left_num = (int)(src_group_num * 0.4);
        for(int i = 0; i < left_num; i++)
        {
            float rand_rate = Rand_Float();
            for (int idx = 0; idx < selected_rate.size(); idx++)
            {
                if(rand_rate <= selected_rate[idx])
                {
                    new_group.push_back(t_group[idx]);
                    break;
                }
            }
        }
        t_group.clear();
        t_group = new_group;
    }

    bool IsCross() { return ( Rand_Float() <= t_cross_rate ); };
    void Cross()
    {
        int src_group_num = t_group.size();

        for (int i = 0; i < src_group_num ; i ++)
        {
            Entity en1 = t_group[i];
            Entity en2 = t_group[i + 1];

            for(int j = 0; j < en1.gene.size(); j++)
            {
                if(IsCross())
                {
                    int tmp = en1.gene[j];
                    en1.gene[j] = en2.gene[j];
                    en2.gene[j] = tmp;
                }
            }

            t_group.push_back(en1);

        }
    }
    bool IsVariation() { return ( Rand_Float() <= t_varia_rate ); }

    void Variation()
    {
        for(size_t i = 0; i < t_group.size(); i++)
        {
            if(IsVariation())
            {
                Entity &en = t_group[i];
                for (int j = 0; j < en.gene.size(); j++)
                {
                    if(IsVariation())
                    {
                        en.gene[j] = (en.gene[j] ? 0 : 1);
                    }
                }
            }
        }
    }

    int t_group_num;
    float t_cross_rate;
    float t_varia_rate;
    int t_goods_num;
    Entity best_entity;
    vector<Entity> t_group;
    vector<Item> t_goods;
};

int main()
{
    // 随机数种子，
    // srand((unsigned)time(NULL));
    //初始化种群
    GA ga(10000,0.5,0.1,32);
    //种群迭代过程
    ga.Run();
    //种群优化
    ga.PrintOptimal();
    return 0;
}
