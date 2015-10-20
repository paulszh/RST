#include "RST.hpp"
#include "countint.hpp"
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    int N = 16;
    int numRun = 5;
    bool rst = true;
    double stdev,difference;
    int expo, val,cpr,acpr,total,totalstd;   // the expo of the
    cout << "# Benchmarking average number of comparisons for successful find" << endl;
    cout << "# Data structure: ";
    cout << "# rst" << endl;
    cout << "# N is the power of 2, minus 1, from 1 to ";
    cout << N << endl;
    cout << "# Averaging "<< numRun << " runs for each N" <<endl;
    cout << "#" << endl;
    cout << "# N 	 avgcomps 	 stdev" << endl;
    RST<countint> r = RST<countint>();   //ceate a rst which contains countint
    BST<countint> b = BST<countint>();
    //print the case for number of nodes from 1 to N-1
    vector<countint> v;
    for(expo = 1; exp2(expo)<= N; expo++){
        val = exp2(expo)-1;
        v.clear();
        //push j elements into the vector v
        for(int j = 0; j<val; j++) {
            v.push_back(j);
        }
        std::vector<countint>::iterator vit = v.begin();
        std::vector<countint>::iterator ven = v.end();
        //this loop will run numRun times according to user input
        for(int i = 0; i < numRun; i++){
            random_shuffle ( v.begin(), v.end());//disorder the elements in the v
            //insert the elements to the rst tree
            for(; vit != ven; ++vit) {
                r.insert(*vit);
            }
            //clear the count value before search
            countint::clearcount();
            for(; vit != ven; ++vit){
                r.find(*vit);
            }
            //finish the search
            cpr = countint::getcount()/(double)val;
            total += cpr;
            totalstd += cpr * cpr;
        }
        acpr = cpr/numRun;  // average comparison per run
        totalstd = cpr/numRun;
        stdev = sqrt(abs(totalstd-acpr * acpr));
        cout << val << "   "<< acpr <<"   " <<stdev <<endl;
        total = 0;
        totalstd = 0;
        v.clear();
    }






        /*
        for(expo = 1; exp2(expo)<= N; ++expo){
        std::vector<countint> v;             //
        v.clear();
        val = exp2(expo)-1;
        for(int i=0; i<val; ++i) {    //Add 0 to N to the vector
        v.push_back(i);
    }

    random_shuffle ( v.begin(), v.end());
    std::vector<countint>::iterator vit = v.begin();
    std::vector<countint>::iterator ven = v.end();
    for(int i = 0; i < numRun; i++){  //the outer loop runs for numRun times
    //std::random_shuffle ( v.begin(), v.end());
    for(vit = v.begin(); vit != ven; ++vit){
    r.insert(*vit);
}
/*else{
for(vit = v.begin(); vit != ven; ++vit){
r.BSTinsert(*vit);
countint::clearcount();
for(vit = v.begin(); vit != ven; ++vit) {
r.find(*vit);
}
comps = countint::getcount()/(double)val;
totalcomps += comps;
totalstd += comps * comps;
}
avgcomps = totalcomps/numRun;  //the overall average comparison;
difference = (totalstd/numRun - pow(avgcomps,2));
stdev = sqrt(abs(difference));
cout << val << "   "<< avgcomps <<"   " <<stdev <<endl;
totalcomps = 0;
totalstd = 0;
v.clear();
}*/

}
