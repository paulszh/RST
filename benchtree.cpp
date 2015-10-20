#include "RST.hpp"
#include "countint.hpp"
#include <vector>
#include <set>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {

    if(argc != 5){
        cout << "The number of arguments is invalid, please check" << endl;
        return 0;
    }

    int range = atoi(argv[3]);

    if(range < 1){
        cout << "The range is invalid, please check" << endl;
        return 0;
    }

    int numRun = atoi(argv[4]);

    string bststr ("bst");
    string rststr ("rst");
    string setstr ("set");
    string sortstr("sorted");
    string shufflestr("shuffle");
    string current = argv[1];
    string datatype = argv[2];

    double stdev,difference,acpr,cpr,total,totalstd,avgstd;

    int expo, val;   // the expo of the

    cout << "# Benchmarking average number of comparisons for successful find" << endl;
    cout << "# Data structure: " << current << endl;
    cout << "# Data structure: " << datatype << endl;
    cout << "# N is the power of 2, minus 1, from 1 to " << range << endl;
    cout << "# Averaging "<< numRun << " runs for each N" <<endl;
    cout << "#" << endl;
    cout << "# N 	 avgcomps 	 stdev" << endl;


    if(current.compare(rststr) == 0){

        RST<countint> r = RST<countint>();   //ceate a rst which contains countint
        std::vector<countint> v;             //
        countint::clearcount();
        v.clear();

        if(datatype.compare(shufflestr) == 0){
            random_shuffle ( v.begin(), v.end());
        }

        for(expo = 1; exp2(expo)<= range; expo++){
            val = exp2(expo)-1;
            for(int i=0; i<val; ++i) {    //Add 0 to N to the vector
                v.push_back(i);
            }

            std::vector<countint>::iterator vit = v.begin();
            std::vector<countint>::iterator ven = v.end();

            for(int i = 0; i < numRun; i++){  //the outer loop runs for numRun times

                for(vit = v.begin(); vit != ven; ++vit){
                    r.insert(*vit);
                }

                countint::clearcount();
                for(vit = v.begin(); vit != ven; ++vit) {
                    r.find(*vit);
                }

                cpr = countint::getcount()/(double)val;
                total = total + cpr;
                totalstd += cpr * cpr;
            }
            acpr = total/(double)numRun;  // average comparison per run
            avgstd = totalstd/(double)numRun;
            stdev = sqrt(abs(avgstd-acpr * acpr));
            cout << val << "   "<< acpr <<"   " <<stdev <<endl;
            total = 0;
            totalstd = 0;
        }
    }

    if(current.compare(bststr) == 0){

        BST<countint> r = BST<countint>();   //ceate a rst which contains countint
        std::vector<countint> v;             //
        countint::clearcount();
        v.clear();

        if(datatype.compare(shufflestr) == 0){
            random_shuffle ( v.begin(), v.end());
        }

        for(expo = 1; exp2(expo)<= range; expo++){
            val = exp2(expo)-1;
            for(int i=0; i<val; ++i) {    //Add 0 to N to the vector
                v.push_back(i);
            }

            std::vector<countint>::iterator vit = v.begin();
            std::vector<countint>::iterator ven = v.end();

            for(int i = 0; i < numRun; i++){  //the outer loop runs for numRun times

                for(vit = v.begin(); vit != ven; ++vit){
                    r.insert(*vit);
                }

                countint::clearcount();
                for(vit = v.begin(); vit != ven; ++vit) {
                    r.find(*vit);
                }

                cpr = countint::getcount()/(double)val;
                total = total + cpr;
                totalstd += cpr * cpr;
            }
            acpr = total/(double)numRun;  // average comparison per run
            avgstd = totalstd/(double)numRun;
            stdev = sqrt(abs(avgstd-acpr * acpr));
            cout << val << "   "<< acpr <<"   " <<stdev <<endl;
            total = 0;
            totalstd = 0;
        }
    }

    if(current.compare(setstr) == 0){

        set<countint> r = set<countint>();   //ceate a rst which contains countint
        std::vector<countint> v;             //
        countint::clearcount();
        v.clear();

        if(datatype.compare(shufflestr) == 0){
            random_shuffle ( v.begin(), v.end());
        }

        for(expo = 1; exp2(expo)<= range; expo++){
            val = exp2(expo)-1;
            for(int i=0; i<val; ++i) {    //Add 0 to N to the vector
                v.push_back(i);
            }

            std::vector<countint>::iterator vit = v.begin();
            std::vector<countint>::iterator ven = v.end();

            for(int i = 0; i < numRun; i++){  //the outer loop runs for numRun times

                for(vit = v.begin(); vit != ven; ++vit){
                    r.insert(*vit);
                }

                countint::clearcount();
                for(vit = v.begin(); vit != ven; ++vit) {
                    r.find(*vit);
                }

                cpr = countint::getcount()/(double)val;
                total = total + cpr;
                totalstd += cpr * cpr;
            }
            acpr = total/(double)numRun;  // average comparison per run
            avgstd = totalstd/(double)numRun;
            stdev = sqrt(abs(avgstd-acpr * acpr));
            cout << val << "   "<< acpr <<"   " <<stdev <<endl;
            total = 0;
            totalstd = 0;
        }
    }
}
