#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TwoSum {
    int target;
    vector<int> v;

public:
    TwoSum(vector<int> _v):v(_v){}

    vector<int> find_indices(vector<int>& indx, int target) {

        // look-up time = 0(n^2)
        // for each 0(n) elements, we run through the rest of element 0(n)
        for (auto i = 0; i < v.size(); i++){
            for (auto j = i + 1; j < v.size(); j++){
                if (v[i] + v[j] == target){
                    indx[0] = i;
                    indx[1] = j;
                    return indx;
                }
            }
        }
        throw invalid_argument("No two sum solution");
    }
    vector<int> find_indices_with_map(vector<int>& indx, int target) {
        map<int, int> m;

        int i = 0;

        for (auto elem_v : v) {
            m[elem_v] = i++;
        }
        for (int i = 0; i < v.size(); i++){
            auto it = m.find(target - v[i]); // O(1)
            int j = m[target - v[i]]; // O(1)
            if (it != end(m) && i != j){
                indx[0] = i;
                indx[1] = j;
                return indx;
            }
        }
        throw invalid_argument("No two sum solution");
    }

    vector<int> find_indices_with_map_2(vector<int>& indx, int target) {
        map<int, int> m;
        for (int i = 0; i < v.size(); i++){
            // we are looking back at already passed elements
            auto it = m.find(target - v[i]);
            int j = m[target - v[i]];
            if (it != end(m) && i != j){
                indx[0] = i;
                indx[1] = j;
                return indx;
            }
            m[v[i]] = i; // making the hash table dynamically
        }
        throw invalid_argument("No two sum solution");
    }
};

int main() {

    vector<int> v = {-6, 1, 11, 2, 7, 15};
    TwoSum twosum(v);
    int target = 9;
    vector<int> indices(2);

    try {
        // O(n^2) speed complexity
        indices = twosum.find_indices(indices, target);
        cout << "brute force: two elemnts, which give 9 as a sum, are located at position "
             << "i1 = " << indices[0] << " and i2 = " << indices[1] << endl;

        // O(n) speed complexity, O(n) space complexity
        indices = twosum.find_indices_with_map(indices, target);
        cout << "hasp_mash (2 goes): two elemnts, which give 9 as a sum, are located at position "
             << "i1 = " << indices[0] << " and i2 = " << indices[1] << endl;

        // O(n) speed complexity, O(n) space complexity
        indices = twosum.find_indices_with_map_2(indices, target);
        cout << "hasp_mash (1 go): two elemnts, which give 9 as a sum, are located at position "
             << "i1 = " << indices[0] << " and i2 = " << indices[1] << endl;

    }catch (exception& e){
        cout << "ERROR: " << e.what() << endl;
    }

    return 0;
}
