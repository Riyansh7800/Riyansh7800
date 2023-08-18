#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Knapsack{
public:
    int size;
    T* weights;
    T* values;

    Knapsack(int n){
        size = n;
        weights = new T[n+1];
        values = new T[n+1];
    }
    
    void inputArray() {
        for (int i = 1; i <= size; i++) {
            cout << "Enter weight for item [" << i << "]: ";
            cin >> weights[i];
            cout << "Enter value for item [" << i << "]: ";
            cin >> values[i];
        }
    }

    void printArray() {
        for (int i = 1; i <= size; i++) {
            cout << "Weight of item " << i << " is " << weights[i] << " and value is " << values[i] << endl;
        }
    }
    
    void computeOPT(T w[], T v[], int n, int W){
        int OPT[n+1][W+1];

        // Initialize OPT matrix
        for(int i=0; i<=n; i++){
            for(int j=0; j<=W; j++){
                if(i==0 || j==0)
                    OPT[i][j] = 0;
                else if(w[i] <= j)
                    OPT[i][j] = max(OPT[i-1][j], v[i] + OPT[i-1][j-w[i]]);
                else
                    OPT[i][j] = OPT[i-1][j];
            }
        }
        int total=0;
        cout << "Optimal solution: ";
        int i=n, j=W;
        while(i>0 && j>0){
            if(OPT[i][j] != OPT[i-1][j]){
                cout << i << " ";
                j -= w[i];
                 total+=v[i];
            }
            i--;
             
        }
        cout << endl;
        cout<<"Total profit : "<<total<<endl;
    }    
};

int main(){
    cout << "\n------------------------  0-1 KNAPSACK PROBLEM -----------------------\n\n";
    cout << "Enter the number of items: ";
    int n;
    cin >> n;

    cout << "Enter the maximum weight capacity of knapsack: ";
    int W;
    cin >> W;

    Knapsack<int> obj(n);
    obj.inputArray();
   
    cout<<endl;
    obj.printArray();
    cout<<endl;

    obj.computeOPT(obj.weights, obj.values, n, W);
    
    return 0;
}
