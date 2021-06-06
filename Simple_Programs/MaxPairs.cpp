#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
	int elementA;
	int elementB;
};

int calculateUniquePairs(vector<int> skillLevel, vector<Pair> possiblePairs) {
	int max = 0;
	
	for(int i = possiblePairs.size() - 1; i >= 0; i--) {
		Pair pair = possiblePairs[i];
		
		if(	find(skillLevel.begin(), skillLevel.end(), pair.elementA) != skillLevel.end() && 
			find(skillLevel.begin(), skillLevel.end(), pair.elementB) != skillLevel.end()) {
			
			skillLevel.erase(remove(skillLevel.begin(), skillLevel.end(), pair.elementA), skillLevel.end());
			skillLevel.erase(remove(skillLevel.begin(), skillLevel.end(), pair.elementB), skillLevel.end());
			
        	max++;
    	}
		
	}
	
	return max;
}

int maxPairs(vector<int> skillLevel, int minDiff) {
    int i = 0;
    int j = 1;
    int n = skillLevel.size();
    int m = skillLevel.size();
    vector<Pair> possiblePairs;
    
    do {
        int element1 = skillLevel[i];
        int element2 = skillLevel[i + j];

        if(abs(element1 - element2) >= minDiff) {
            struct Pair pair;
            
            pair.elementA = element1;
            pair.elementB = element2;
            
            possiblePairs.push_back(pair);
        }
        
        j++;
        
        if(j == m) {
            i++;
            j = 1;
            m--;
        }
        
        if(i == n - 1) {
            break;
        }
        
    } while(true);
    
    return calculateUniquePairs(skillLevel, possiblePairs);
}

int main() {
	vector<int> skillLevel;
	
	skillLevel.push_back(1);
	skillLevel.push_back(2);
	skillLevel.push_back(3);
	skillLevel.push_back(4);
	skillLevel.push_back(5);
	skillLevel.push_back(6);
	skillLevel.push_back(7);
	skillLevel.push_back(8);
	
	cout << "Max number of pairs: " << maxPairs(skillLevel, 4) << endl;

	return 0;
}
