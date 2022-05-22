#include <iostream>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QtGlobal>
#include <stdio.h>
#include <QList>
#include <QFile>
#include <map>
#include <tuple>
#include <string>
#include <fstream>
#include "tasks_rk1.h"
#include <QDebug>

using namespace std;

//task1
void WorkWithFile::readFromFile(const char* fileName) {}
void WorkWithFile::prepareTestFile(const char* fileName){}

WorkWithFile::WorkWithFile() {}
WorkWithFile::~WorkWithFile() {}

void WorkWithFile::writeStatInfoToFile(const char* outFile) {}

//task2
char *convertDecToBin(int number){}





//task3
char* convertBinToHex(const char *binNum){
    QString stroka;
    int count=-1;
    for(int i=3;binNum[i]!=NULL;i=i+5){
        if(binNum[i]=='1'){
            stroka+="1";
            count++;

        }
        if(binNum[i]=='0'){
            cout<<"you"<<endl;
            stroka+="0";
            count++;
        }
        if(binNum[i+1]==NULL)
            i++;
    }
    int count1=count;
    unsigned int summa=0;

    for(int i=0;i<=count;i++){
        if (stroka[i]=='1'){

            summa+=pow(2,count1);
            count1-=1;
        }
        if (stroka[i]=='0'){
            count1-=1;
        }
    }
 //   qDebug()<<stroka;
 //   qDebug()<<summa;
    QString strokafin;
    strokafin=QString("%1");
    strokafin=strokafin.arg(summa,32,16);

    char* cstr;
    string fname = strokafin.toStdString();
    cstr = new char [fname.size()+1];
    strcpy( cstr, fname.c_str() );


    return cstr;

}



//task4
void buildTree(int height){
    int col=1;
    int probel=height-1;
    for(int i=1;i<=height;i++){
        for(int j=1;j<=probel;j++){
            cout<<" ";
        }
        for(int j=1;j<=col;j++){
            cout<<"*";
        }
        cout<<endl;
        col+=2;
        probel-=1;
    }
}




//task5
std::vector<std::pair<int, float> > averStr2DArray(const float *ar, int colCount, int rowCount)
{
    return std::vector<std::pair<int,float>>();
}




//task6

LinkedList::LinkedList() {
    Head=nullptr;
    Tail=nullptr;
}
LinkedList::~LinkedList() {
    while(Head!=nullptr){
        Tail=Head->next;
        delete Head;
        Head=Tail;
    }
}

void LinkedList::push_back(int nameNode) {
    Node* tempnode=new Node;
    tempnode->nameNode=nameNode;
    tempnode->next=nullptr;
    if(Head==nullptr){


         tempnode->prev=nullptr;
         Head=tempnode;
         Tail=tempnode;
     //    cout<<"first ok"<<endl;

    }
    else{
        tempnode->prev=Tail;
        Tail->next=tempnode;
        Tail=tempnode;
    }
}
void LinkedList::writeToFileFromTail() {
    QFile f("task6.txt");
    f.open(QIODevice::WriteOnly);
    if (!f.exists()){
        qDebug()<<"task6 No exists";
    }
    else{
        QTextStream writeStream(&f);
        Node* current=Tail;
        while(current!=nullptr){
            writeStream<<(current->nameNode)<<"\n";
            current=current->prev;
        }
        cout<<"task6 wrote from Tail"<<endl;
      }

   f.close();

}
void LinkedList::writeToFileFromHead() {
    QFile f("task6.txt");
    f.open(QIODevice::WriteOnly);
    if (!f.exists()){
        qDebug()<<"task6 No exists";
    }
    else{
        QTextStream writeStream(&f);
        Node* current=Head;
        while(current!=nullptr){
            writeStream<<(current->nameNode)<<"\n";
            current=current->next;
        }
        cout<<"task6 wrote from Head"<<endl;
      }

   f.close();

}





//task7
void LinkedList::insert(int nameNode, int position) {
    Node* tempnode=new Node;
    tempnode->nameNode=nameNode;
    Node* currnode= Head;
    int count =1;
    for (int i=1; i<position-1 && currnode->next!=nullptr;i++ ){
        currnode=currnode->next;
        count++;
    }
    if (position - count >1 || position <1){
        qDebug()<<"Wrong position";
        return;
    }
    else{
        if (position==1){
            tempnode->prev=nullptr;
            tempnode->next=Head;
            Head->prev=tempnode;
            Head=tempnode;

        }
        else{
            if(currnode->next==nullptr){
                tempnode->next=nullptr;
                tempnode->prev=Tail;
                Tail->next=tempnode;

                Tail=tempnode;
            }
            else{
                tempnode->next=currnode->next;
                currnode->next=tempnode;
                tempnode->prev=currnode;

           }
        }
   }
}




//task8

StudentInfo::StudentInfo(){
    get<0>(info)="Druchevskii";
    get<1>(info)="Ivan";
    get<2>(info)="1234";
}

int StudentInfo::addMark(const string& subjName, int mark){
    int count=0;
    for (map<string,pair<list<int>,float>>::iterator iter=subjMark.begin();iter!=subjMark.end();iter++){
        if (iter->first==subjName){
           count++;
           iter->second.first.push_back(mark);
           float l=iter->second.first.size();
           float summa=0;
           for (auto i=iter->second.first.cbegin();i!=iter->second.first.end();i++){
              summa+=(*i/l);
           }
           iter->second.second=summa;
           cout<<" 0-predmet est,ocenka dobavlema"<<endl;
           return 0;
        }
    }
    if (count==0){
        cout<<"1-predmet net"<<endl;
        return 1;
    }


}


int StudentInfo::addSubj(const string& subjName){
    //    int count=0;
       for (map<string,pair<list<int>,float>>::iterator iter=subjMark.begin();iter!=subjMark.end();iter++){
            if (iter->first==subjName){
                cout<<"1-Predmet est"<<endl;
                return 1;
            }
        }
       pair<list<int>,float> pair;
       subjMark.insert_or_assign(subjName,pair);
       cout<<"0-Predmet dobavlen"<<endl;
       return 0;
   }



float StudentInfo::getAverMark(const string& subjName) {
    for (map<string,pair<list<int>,float>>::iterator iter=subjMark.begin();iter!=subjMark.end();iter++){
        if (iter->first==subjName){
            return iter->second.second;
        }
    }
}

void StudentInfo::printInfoStudent(){
    string surname = get<0>(info);
    string name = get<1>(info);
    string number = get<2>(info);
        cout<<surname.c_str()<<"\t"<<name.c_str()<<"\t"<<number.c_str()<<endl;
        map<string,pair<list<int>,float>>::iterator iter;
        for(map<string,pair<list<int>,float>>::iterator iter=subjMark.begin();iter!=subjMark.end();iter++)
        {
            string pr = iter->first;
            cout<<pr.c_str()<<"\t";
            foreach(int valu,iter->second.first)
            {
                cout <<"\t"<< valu;
            }
            getAverMark(iter->first);
            cout<<"\t"<<" average - "<<iter->second.second;
            cout<<endl;

        }
}

void StudentInfo::writeAllInfoToFile() {
    QFile f("result_task8.txt");
    f.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!f.exists()){
        qDebug()<<"resultask3 No exists";
    }
    else{
        QTextStream writeStream(&f);
        writeStream<<"["<<get<0>(info).c_str()<<"]"<<"\t"<<"["<<get<1>(info).c_str()<<"]"<<" "<<":"<<" "<<"["<<get<2>(info)<<"]"<<"\n";
         for (map<string,pair<list<int>,float>>::iterator iter=subjMark.begin();iter!=subjMark.end();iter++){
            writeStream<<"["<<iter->first.c_str()<<"]"<<" "<<":"<<" ";
            foreach(int valu,iter->second.first){
                writeStream<<"["<<valu<<"]"<<", ";
            }
            writeStream<<"--"<<iter->second.second<<"\n";
         }
   }

  f.close();
}

int maint(){

}

