#ifndef _XMLPARSER_H_
#define _XMLPARSER_H_

#include <string>
#include <iostream>
#include <vector>


/* 型の割り振り
#define XMLRPC_PARAM_BOOL 1  // OK
#define XMLRPC_PARAM_INT 2   // OK
#define XMLRPC_PARAM_DOUBLE 3  //OK
#define XMLRPC_PARAM_STRING 4  //OK
#define XMLRPC_PARAM_ARRAY 5
#define XMLRPC_PARAM_DATETIME 6
#define XMLRPC_PARAM_BINARY 7
#define XMLRPC_PARAM_STRUCT 8
*/
using namespace std;


//XMLノードの構造体
//arrayとstructはそのままstringに2次元展開する
typedef struct xmlNode{
    string  methodName;
    vector<string> params;    //paramベクトル
    int e_num;  //param数
    bool fault; //foult ならfalse デフォルト true
    xmlNode(){
        e_num=0;
        fault = true;
    }
}xmlNode;


string getbool(string param);
string getint(string param);
string getdouble(string param);
string getstring(string param);
string getarray(string param);
string getdate(string param);
string getbinary(string param);
string getstruct(string param);
string gettagless(string param);

void paramparser(xmlNode *node,string params,int num);
void faultperser(xmlNode *node,string body);

void callparser(xmlNode *node,string xml);
void resparser(xmlNode *node,string xml);

bool parser(xmlNode *node,string xml);
int ParseReceiveMessage(string http,xmlNode *node);
string get_port(string http);
string get_port2(string http);

//タスク用
string get_ttype(string xml);
string get_tname(string xml);
string get_cid(string xml);
string get_msgdef(string xml);
string get_fptr(string xml);
//string get_prt(string xml);
string get_ip(string ip);
string req_topic_name(string xml);
#endif /* _XMLPARSER_H_ */  
