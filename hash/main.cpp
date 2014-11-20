//
//  main.cpp
//  hash
//
//  Created by Rishab Mehra on 11/1/14.
//  Copyright (c) 2014 Rishab Mehra. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "sha256.h"
#include <sstream>
#include <random>
#include <fstream>
#include <map>
using namespace std;

void generate(string &startx, string &endx, string);
string wordToHex(string);
bool crack(string sha, map<string, string> m );

int chainLength = 4000; //1000 for hashNew 10000 for hashLong

int main(int argc, const char * argv[]) {
    srand (time(0));
    
    string startx= "";
    string endx= "";
    int count = 100000;
    
    SHA256 sha256;
    
    ofstream fout("hashFour.txt", ios::app);
 
 /*  for (int i=0; i<count; i++) {
       
        if(i%100 == 0)
            cout<<i<<" "<<endl;
        
        string s="";
        
        generate(startx, endx, s);
        fout<<startx<<endl<<endx<<endl;
        
    } */
  
  

 x:
    fstream fin("hashFour.txt"); //hashNew
    string s1,s2;
    count = 0;
    
    map<string, string> m;
    while (fin>>s1) {
        fin>>s2;
        m.insert(pair<string,string>(s2,s1));
    }

    
    for(int i= 0; i<1; i++) {
        char c;
        string a;
        
        for (int m=0; m<6; m++) {
            c= rand()%26 + 'a';
            a += c;
        }
         a="fucker";
        
        if(crack(sha256(a), m )) {count++;}
        else {
            cout<<"Not found"<<endl;
            generate(startx, endx, a);
            fout<<startx<<endl<<endx<<endl;
        }
            //cout<<" "<<i<<endl;
    }
    
    cout<<count<<endl;
    fin.close();
   // if(count<90) goto x; */
    
}

string reduction (string temp1, string sha, int j) {
    string temp = "";
    stringstream stream;
    int x ;
    char c;
    
    for (int i=0; i<60; i+=10) {
        temp += sha[i];
        temp += sha[i+1];
        temp += sha[i+2];
        temp += sha[i+5];
        temp += sha[i+6];
        
        stream<<temp;
        stream>>hex>>x;
        if(j>0)
            x /= j;
        
        c = x%26 + 'a';
        temp1 += c;
        temp = "";
        
        stream.clear();
    }
    
   // cout<<temp1<<endl;
    return temp1;
}

void generate(string &startx, string &endx, string word) {
    
    

    SHA256 sha256;
  
    string chainEnd[500];
    string temp = "";
    string temp1 = "";
    stringstream stream;
    
    int x;
    char c;
    
    if (word+"" == "") {
        for (int m=0; m<6; m++) {
            c= rand()%26 + 'a';
            chainEnd[0] += c;
        }
    
    }
    
    else
        chainEnd[0] = word+"";
    
    string sha = sha256(chainEnd[0]);
    
    int j = 0;
    startx = chainEnd[0];
    
    while (chainEnd[0] != temp1 && j<chainLength) {
        endx = temp1;
        temp1 = "";
        temp1 = reduction(temp1, sha, j);
        
     /*   if (j==10000) {
            chainEnd[1] = temp1;
        }
    
        else if (j==20000) {
            chainEnd[2] = temp1;
        }
        
        else if (j==30000) {
            chainEnd[3] = temp1;
        }
        
        else if (j==40000) {
            chainEnd[4] = temp1;
        }
        
       else if (j==50000) {
            chainEnd[5] = temp1;
        }
        
        else if (j==60000) {
            chainEnd[6] = temp1;
        }
        
        else if (j==70000) {
            chainEnd[7] = temp1;
        }
        
        else if (j==80000) {
            chainEnd[8] = temp1;
        }
        
        else if (j==90000) {
            chainEnd[9] = temp1;
        }
        
        else if (j==1000000) {
            chainEnd[10] = temp1;
        }
        
        else if (j==1500000) {
            chainEnd[11] = temp1;
        }
        
        else if (j==2000000) {
            chainEnd[12] = temp1;
        }
        
        else if (j==2500000) {
            chainEnd[13] = temp1;
        }
        
        else if (j==3000000) {
            chainEnd[14] = temp1;
        }
       
       if (temp1==chainEnd[1] && j != 10000) {
            cout<<j-10000<<endl;
            break;
        }
        
        
        else if (temp1==chainEnd[2] && j != 20000) {
            cout<<j-20000<<endl;
            break;
        }
        
        else if (temp1==chainEnd[3] && j != 30000) {
            cout<<j-30000<<endl;
            break;
        }
        
        else if (temp1==chainEnd[4] && j != 40000) {
            cout<<j-40000<<endl;
            break;
        }
        
        else if (temp1==chainEnd[5] && j != 50000) {
            break;
        }
        
        else if (temp1==chainEnd[6] && j != 60000) {
            break;
        }
        
        else if (temp1==chainEnd[7] && j != 70000) {
            break;
        }
    
        else if (temp1==chainEnd[8] && j != 80000) {
            break;
        }
        
        else if (temp1==chainEnd[9] && j != 90000) {
            break;
        }
        
        else if (temp1==chainEnd[10] && j != 100000) {
            break;
        }
        
        else if (temp1==chainEnd[11] && j != 150000) {
            break;
        }
        
        else if (temp1==chainEnd[12] && j != 200000) {
            break;
        }
        
        else if (temp1==chainEnd[13] && j != 250000) {
            break;
        }
        
        else if (temp1==chainEnd[14] && j != 300000) {
            break;
        } */
        
        sha = sha256(temp1);
        
        j++;
        
    }

            endx=sha256(endx);
 
}

bool crack(string sha, map<string, string> m )
{
    SHA256 sha256;
    string tempSha = sha;
    string tempString = "";
    stringstream stream;
    string temp = "";
    int j;
    
    j=0;
    
    for(int l=0; l<chainLength; l++) {
       
        int p,q,r;
        p=q=r=l;
        j=0;
        string tempf="";
        int jprev = 0;
    a:
        p=l;
        tempSha = sha;
        
        temp="";
        tempString = "";
     for (j=l; j<chainLength; j++) {
        if(m.find(tempSha) != m.end() && j>jprev)
            break;
        tempString = "";
        /*for (int i=0; i<60; i+=10) {
            temp += tempSha[i];
            temp += tempSha[i+1];
            temp += tempSha[i+2];
            temp += tempSha[i+5];
            temp += tempSha[i+6];
            stream<<temp;
            stream>>hex>>x;
            if(p!=0)
                x/=p;
            c = x%26 + 'a';
            tempString += c;
            temp = "";
            stream.clear();
        } */
         tempString = reduction(tempString, tempSha, p);

         p++;
        
        tempSha = sha256(tempString);
        
    }
        tempString = "";
        
    string tempSha1 = tempSha;
    if(j<chainLength) {
        jprev=j;
               tempString = m[tempSha];
        tempSha = sha256 (tempString);
        r=0;
        
        tempSha = sha256(tempString);
        
        
        temp="";
        int z=0;
        while (tempSha!=sha && z<chainLength) {
            z++;
            tempString="";
        /*    for (int i=0; i<60; i+=10) {
                temp += tempSha[i];
                temp += tempSha[i+1];
                temp += tempSha[i+2];
                temp += tempSha[i+5];
                temp += tempSha[i+6];
                stream<<temp;
                stream>>hex>>x;
                if(r!=0)
                    x/=r;
                c = x%26 + 'a';
                tempString += c;
                temp = "";
                
                stream.clear();
            } */
            tempString = reduction(tempString, tempSha, r);

            
            r++;
            
            tempSha = sha256(tempString);
            
            
        }
        if (z<chainLength) {
            cout<<tempString<<" "<<z<<endl;
            return true;
             break;
        }
        
        else {
            goto a;
        }
    }
        
       
        
        
        
 }
    return false;
}

string wordToHex(string s) {
    
    return s;
}