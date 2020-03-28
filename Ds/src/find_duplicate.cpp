#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int> &arr){
    for ( auto &a: arr){
        cout<< a <<" ";
    }
    cout << endl;
}
int main() {
    vector<int> x = {1,2,3,44,5 , 44 , 1 };
    // for ( vector<int>::iterator it1 = x.begin(); it1 != x.end() ; it1++ ){
    //     for ( vector<int>::iterator it2 = it1+1 ; it2 != x.end() ; it2++ ){
    //         if ( *it1 == *it2){
    //             cout << "Duplicate entry found " << *it2 << endl;
    //             x.erase(it2);
    //         }
    //     }
    // }
    
    for ( int i = 0 ; i < x.size() ; i++ ){
        for ( int j = i+1 ; j < x.size() ; j++ ){
            if ( x[i] == x[j] ){
                cout << "found duplicate "<< x[j] << endl;
                x.erase(x.begin() + j );
                j--;
            }
        }
    }
    
    printArr(x);
}