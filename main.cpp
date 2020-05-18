#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
//freopen("./in1.txt", "r", stdin)
//не улитка
int diagon(int n,int m)
{
    vector <vector<int> > a(n, vector<int>(m, 0));
    vector < vector<int> >::iterator row;
    vector < vector<int> >::reverse_iterator rerow;
    vector <int>::iterator col;
    vector <int>::reverse_iterator recol;
    vector<int> rowp(m,0);
    int num = 0;
    row = a.begin();
    for (col = row->begin(); col != row->end(); col++){
        num++;
        *col = num;
    }
    rowp = *row;
    for (row = a.begin()+1; row != a.end(); row++){
        *row = rowp;
        row->pop_back();
        row->insert(row->begin(), *(row->begin())+1);
        rowp = *row;
    }
    cout << endl;

    //int sum=0;
    for (row = a.begin(); row != a.end(); row++){
        for (col = row->begin(); col != row->end(); col++)
            {
                cout <<setw(3)<< *col<< "  ";
                //sum+=*col;
            }
        cout << endl;

    }
    //cout <<endl<<sum;
    return 0;
}
int ulitka(int n, int m)
{
    vector <vector<int> > a(n, vector<int>(m, 0));
    vector < vector<int> >::iterator row;
    vector < vector<int> >::reverse_iterator rerow;
    vector <int>::iterator col;
    vector <int>::reverse_iterator recol;


// улитка
    int num = 0 , k = 0;
    row = a.begin();
    col = row->begin();
    while (num <= n*m) {
        for (col = (a.begin()+k)->begin()+k; col != (a.begin()+k)->end()-k; col++){
            num++;
            *col = num;
        };
        if (num == n*m) break;
        for (row = a.begin()+k+1; row != a.end()-k; row++){
            num++;
            *(row->end()-k-1) = num;
        };
        if (num == n*m) break;
        for (recol = (a.rbegin()+k)->rbegin()+k+1; recol != (a.rbegin()+k)->rend()-k; recol++){
            num++;
            *(recol) = num;
        };
        if (num == n*m) break;
        for (rerow = a.rbegin()+k+1; rerow != a.rend()-k-1; rerow++){
            num++;
            *((rerow->rend()-k-1)) = num;
        };
        if (num == n*m) break;
        k++;
    }

    cout << endl;
    for (row = a.begin(); row != a.end(); row++){
        for (col = row->begin(); col != row->end(); col++)
            cout <<setw(3)<< *col<< "  ";
        cout << endl;
    }
    return 0;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n0, m0;
    cout<<"Программа заполняет двумерный массив размером n x m так, как представлено в таблице для 5х5"<<endl;
    cout<<"Введите размеры улитки"<<endl;
    cin >> n0 >> m0;
    ulitka(n0,m0);
    cout<<"Введите размеры не улитки"<<endl;
    cin >> n0 >> m0;
    diagon(n0,m0);
    return 0;
}
