#include <iostream>
using namespace std;

int main() {
    
    int space, movies, size, rating, test, result, maxRating, tempRating;
    
    cin >> test;
    
    while(test--){
        
        cin >> movies >> space;
        
        for(int i = 0; i < movies; i++){
            
            cin >> size >> rating;
            
            tempRating = rating;
            
            maxRating = 0;
            
            if(size <= space){
                
                if(tempRating > maxRating)
                    maxRating = tempRating;
                    
            }
        }
        
        cout<<maxRating<<endl;
    }
    
    
    
	// your code goes here
	return 0;
}
