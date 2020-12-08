#include <iostream>
#define N 100
using namespace std;
int n;
double W;
double w[N];
double v[N];
bool x[N];  //���ڼ�¼ĳ�λ������
bool best_x[N]; //�洢���Ż������
double now_v;   //��ǰ��ֵ
double remain_v;    //ʣ���ֵ
double now_w;   //��ǰ����
double best_v;  //���ż�ֵ

double Bound(int k)
{
    remain_v = 0;
    while(k <= n){
        remain_v += v[k];
        k++;
    }
    return remain_v + now_v;
}

void Backtrack(int t)
{
    if(t > n){  //�Ƿ񵽴�Ҷ�ڵ�
        for(int i = 1; i <= n; i++){
            best_x[i] = x[i];   //��¼���ݵ��������
        }
        best_v = now_v; //��¼�����е����ż�ֵ
        return;
    }
    if(now_w + w[t] <= W){  //Լ���������Ƿ���롣���뿼����������������������
        x[t] = 1;
        now_w += w[t];
        now_v += v[t];
        Backtrack(t+1); //������һ���ڵ�ķ���
        now_w -= w[t];  //�ڵ���Ҷ�ڵ����л���
        now_v -= v[t];
    }
    if(Bound(t+1) > best_v){    //�޽��������Ƿ��֦��������t������Լ����������е��˴���Ȼ���ж�����ǰ��ֵ��ʣ���ֵ���ﲻ�����ţ���û��Ҫ������ȥ
        x[t] = 0;
        Backtrack(t+1);
    }

}

void Knapsack(double W, int n)
{
    double sum_w = 0;
    double sum_v = 0;
    best_v = 0;
    for(int i = 0; i < n; i++){
        sum_w += w[i];
        sum_v += v[i];
    }
    if(sum_w <= W){
        best_v = sum_v;
        cout << "These goods could be put in the shopping car";
        cout << "The best value is:" << best_v <<endl;
        return;
    }
    Backtrack(1);
    cout << "The best value is:" << best_v << endl;
    cout << "The condiction of these goods are:" << endl;
    for(int i = 1; i <= n; i ++){
        cout << i << " ";
        cout << best_x[i] << endl;   //��ӡ������Ʒ�ķ����������Ϊ1��ʾ���룬��Ϊ0���ʾ������
    }
}

int main()
{
    cout << "Please input the num of goods:";
    cin >> n;
    cout << "Please input the capacity of the shopping car:";
    cin >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    Knapsack(W,n);
    return 0;
}
