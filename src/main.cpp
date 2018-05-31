//CS700-34 Project8 BucketSort
//Shawn Yang

#include <iostream>
#include <fstream>
using namespace std;

class BucketSort{
public:
    int maxNum;
    int *bucketAry;
    ifstream *infile;
    ofstream *outfile;
    
    BucketSort(int in_maxNum, ifstream *in_infile, ofstream *in_outfile){
        maxNum=in_maxNum;
        bucketAry=new int[maxNum+1];
        for (int i=0; i<maxNum+1; i++){
            bucketAry[i]=0;
        }
        infile = in_infile;
        outfile = in_outfile;
    }
    
    void start(){
        int index;
        while (*infile>>index){
            cout<< index<<endl;
        //step1 Data<-get data from file
        //step2 index <- Hash(data)
        //step3 bucketAry(index)++
            bucketAry[index]++;
        }//step4 repeat step1,2,3 until eof
        //step5 index <-0
        index=0;
        while (index<maxNum+1){
            //step6 print the index as many as # in bucketAry(index)
            while (bucketAry[index]!=0){
                *outfile << index << endl;
                cout<< index<<endl;
                bucketAry[index]--;
            }
            //step7 index++
            index++;
        }//step8 repeat step6-7 while index <= maxNum
    }
};

int main(int argc, const char * argv[]) {
    ifstream *infile = new ifstream();
    ofstream *outfile = new ofstream();
    int maxNum=0;
    int tempNum=0;
    if (argc<3){
        cout<<"Please provide the required input and output files."<<endl;
        return 0;
    }
    try {
        infile->open(argv[1]);
        outfile->open(argv[2]);
    } catch (exception *e) {
        cout<<"problem opening the files"<<endl;
        return 0;
    }
    cout<< argv[1]<<" "<<argv[2]<<endl;
    
    
    *infile >> maxNum;
    
    while (*infile >> tempNum){
        if (tempNum > maxNum)
            maxNum = tempNum;
    }
    cout<<"maxNum"<<maxNum<<endl;
    //reset reading position back to the beginning of the file.
    infile->clear();
    infile->seekg(0, std::ios::beg);
    BucketSort *bs = new BucketSort(maxNum, infile, outfile);
    bs->start();
    
    infile->close();
    
    
    return 0;
}
