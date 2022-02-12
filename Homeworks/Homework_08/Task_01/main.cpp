#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    multiset<double> collection;
    multiset<double>::iterator it;

    public:
        void insert(double number) {
            collection.insert(number);

            int size = this->collection.size();

            if (size == 1) {
                this->it = collection.begin();
                printf("%.1f \n", *(this->it));
                return;
            }
            else {
                
                if(size % 2 != 0){
                    
                    if (number >= *(this->it)) {
                    ++this->it;
                    }  
                    printf("%.1f \n", *(this->it));
                }
                else {
                    if (number < *(this->it)) {
                    --this->it;
                    }   
                    
                    double firstElement = *(this->it++);
                    double secondElement = *(this->it--);
                    printf("%.1f \n", (firstElement + secondElement) / 2);
                }
            }            
        }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    Solution sol;
    double number;

    for (int i = 0; i < n; i++) {
        cin >> number;
        sol.insert(number);
    }
    return 0;
}
