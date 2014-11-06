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

void generate(string &startx, string &endx);
bool crack(string sha, map<string, string> m );

int main(int argc, const char * argv[]) {
    srand (time(0));
    
    string startx= "";
    string endx= "";
    int count = 200000;
    
    SHA256 sha256;
    
    /*ofstream fout("hashFinal10.txt", ios::app);
    
    for (int i=0; i<count; i++) {
       
          if(i%100 == 0)  cout<<i<<" "<<endl;
        generate(startx, endx);
      //  cout<<i<<endl;
        fout<<startx<<endl<<endx<<endl;
        
        //cout<<i;
    }
    */
   
  
   ifstream fin("hashFinal10.txt");
    string s1,s2;
    count = 0;
    
    map<string, string> m;
    while (fin>>s1) {
        fin>>s2;
        m.insert(pair<string,string>(s2,s1));
    }
    
    for(int i= 0; i<100; i++) {
   

    char c;
    string a;
    
    for (int m=0; m<6; m++) {
        c= rand()%26 + 'a';
        a += c;
    }
        
      //  cout<<a<<endl; //sahami, anaika, jialin, mehran
        
        // a="rishab";
    
        if(crack(sha256(a), m )) count++;
        else cout<<"Not found";
        cout<<endl;
    }
    
    cout<<count;
    
   // cout<<"done";
    
}

void generate(string &startx, string &endx) {
    
    

    SHA256 sha256;
    
    //cout<<sha256("aaaaaaa");
  
    string chainEnd[500];
    string temp = "";
    string temp1 = "";
    stringstream stream;
    
    int x;
    char c;
    
    for (int m=0; m<6; m++) {
        c= rand()%26 + 'a';
        chainEnd[0] += c;
    }
    
   // cout<<chainEnd[0]<<endl;
    //chainEnd[0] = "aaaaaaaa";
    //chainEnd[0] = "hvtlij";
    //cout<<chainEnd[0]<<endl;
    string sha = sha256(chainEnd[0]);
    //
    
    int j = 0;
   // cout<<"yeah"<<endl;
    //cout<<chainEnd[0];
    startx = sha;
    
    while (chainEnd[0] != temp1 && j<1000) {
      //if (j==50000)
         // cout<<temp1<<endl;
       // cout<<temp1<<endl;
       // if(j%10000)cout<<j<<endl;
        endx = temp1;
        //cout<<"yeah";
        temp1 = "";
        
      
        
       
        
        
        for (int i=0; i<60; i+=10) {
           // temp = sha.substr(0,6);
            temp += sha[i];
            //temp += sha[i+3];
            temp += sha[i+1];
            temp += sha[i+2];
            temp += sha[i+5];
            temp += sha[i+6];
          
            //temp += sha[i+7];
           // temp += sha[i+2];
          //  temp += sha[i+3];
           // temp += sha[i+4];
          //  temp += sha[i+5];
            
           
           
            
            
            //temp += endx[0];
            //temp += endx[1];
            //cout<<temp<<endl;
            stream<<temp;
            stream>>hex>>x;
            if(j>0)
                x /= j;
           // x+= endx[0];
           // x+=endx[1];
            //int y = endx[3] +1;
            
        //    x= x%y;
            //x%=53;
           // cout<<x<<endl;
            /*int y=0;
            for(int i=0; i<4; i++) {
                y+= x%10;
                x=x/10;
            } */
          //  x=y;
            c = x%26 + 'a';
            temp1 += c;
            temp = "";
            
            stream.clear();
        }
        
        //cout<<temp1<<endl;
        
        
      //  if (sha=="4fbfe1e8e936db1e210ed68f3f193320c1007509cbfaf3b23349954db861614d")
        //    cout<<j<<endl;
         
        
        
        //cout<<temp1<<endl;
        /*if(j>0) {
            chainEnd[j]=temp1;
        } */
        if (j==10000) {
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
        }
        
       // else if (temp1==chainEnd[15] && j != 150000) {
         //   break;
      //  }
        
        
        
     //   int x=false;
       /* for(int i=1; i<j; i++)
        {
            if(chainEnd[i]==temp1) {
                //cout<<"eeee";
                x=true;
                cout<<endl<<i<<endl;
                break;
                
            }
        }
        
        if(x)
            break; */
        
        sha = sha256(temp1);
        
        j++;
        
        //2840 4370
        //27387 3356 24031
        //32858 8827
        
        
        
    }
    
  //  if (j<100000) {
      //  cout<<temp1<<endl<<endx<<endl<<j;
        
            //startx=sha256(temp1);
            endx=sha256(endx);
    
  //  cout<<j<<endl;
        
          //  cout<<endl<<j;
 //   }
    
 /*   else {
      //  cout<<"ERROR"<<endl;
        startx="";
        endx="";
    } */
   // cout<<startx<<endl<<endx<<endl;
   // cout<<j;
    
   // return 0;
}

bool crack(string sha, map<string, string> m )
{
    SHA256 sha256;
    string tempSha = sha;
    string tempString = "";
    stringstream stream;
    string temp = "";
    int x;
    char c;
    int j;
    
  //  cout<<sha<<endl;
    
    j=0;
//    int l=0;
    
    for(int l=0; l<1000; l++) {
       
        int p,q,r;
        p=q=r=l;
     //   if(l%100==0)cout<<l<<endl;
        j=0;
        string tempf="";
        int jprev = 0;
    a:
       // if (tempf!="") {
            
         //   tempSha = tempf;
        //}
        p=l;
        tempSha = sha;
        
        temp="";
        tempString = "";
     for (j=0; j<1000; j++) {
        if(m.find(tempSha) != m.end() && j>jprev)
            break;
        tempString = "";
        for (int i=0; i<60; i+=10) {
            temp += tempSha[i];
            temp += tempSha[i+1];
            temp += tempSha[i+2];
            temp += tempSha[i+5];
            temp += tempSha[i+6];
            //cout<<temp<<endl;
            stream<<temp;
            stream>>hex>>x;
            // cout<<x<<endl;
            if(p!=0)
                x/=p;
            c = x%26 + 'a';
            tempString += c;
            temp = "";
            stream.clear();
        }
         p++;
         
        
        //cout<<tempString<<endl;
        
        tempSha = sha256(tempString);
        
    }
        //tempf=tempSha;
        tempString = "";
        /*for (int i=0; i<60; i+=10) {
            temp += tempSha[i];
            temp += tempSha[i+1];
            temp += tempSha[i+2];
            temp += tempSha[i+5];
            temp += tempSha[i+6];
            //cout<<temp<<endl;
            stream<<temp;
            stream>>hex>>x;
            // cout<<x<<endl;
            x+=p;
            c = x%26 + 'a';
            tempString += c;
            temp = "";
            stream.clear();
        }
        tempf = sha256(tempString);
        p++; */

    
    //cout<<j;
    //cout<<j<<endl;
   // cout<<tempSha<<endl;
    string tempSha1 = tempSha;
    if(j<1000) {
        jprev=j;
        //cout<<"In found section"<<endl;
        tempSha = m[tempSha];
        //cout<<tempSha<<endl;
        temp="";
        //string temp1 ="";
        tempString = "";
        q=0;
        for (int i=0; i<60; i+=10) {
            
            temp += tempSha[i];
            temp += tempSha[i+1];
            temp += tempSha[i+2];
            temp += tempSha[i+5];
            temp += tempSha[i+6];
            //cout<<temp<<endl;
            stream<<temp;
            stream>>hex>>x;
            if(q!=0)
                x/=q;
            // cout<<x<<endl;
            c = x%26 + 'a';
            tempString += c;
            temp = "";
            
            stream.clear();
        }
        q++;
        r=q;
        
        //cout<<sha256(tempString)<<endl;
        
        tempSha = sha256(tempString);
        
        
        temp="";
        int z=0;
       // cout<<"yeah"<<endl;
       // tempSha1 = tempSha;
       // cout<<tempSha1<<endl;
        while (tempSha!=sha && z<1000) {
            //cout<<z++<<endl;
            z++;
            tempString="";
            for (int i=0; i<60; i+=10) {
                temp += tempSha[i];
                temp += tempSha[i+1];
                temp += tempSha[i+2];
                temp += tempSha[i+5];
                temp += tempSha[i+6];
                //cout<<temp<<endl;
                stream<<temp;
                stream>>hex>>x;
                // cout<<x<<endl;
                
                x/=r;
                c = x%26 + 'a';
                tempString += c;
                temp = "";
                
                stream.clear();
            }
            
            r++;
            // cout<<tempString<<endl;
    
            tempSha = sha256(tempString);
            
            
        }
        if (z<1000) {
             cout<<l<<" "<<tempString;
            return true;
             break;
        }
        
        else {
            //cout<<j<<endl;
            goto a;
           // cout<<"not found";
        }
    }
         //else
            // cout<<"not found";
            //break;
        
       
        
        
        
 }
    return false;
    cout<<"end";
    
    
  //  else
    //    cout<<"not found1";
    
    string crack;
    //return sha;
}