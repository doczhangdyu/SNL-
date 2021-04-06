/*
* @Author: 22486
* @Date:   2021-03-25 15:48:59
* @Last Modified by:   远浪
* @Last Modified time: 2021-04-02 16:24:08
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

struct Token
{
	string Typename;
	string value;
	int    isInterger;
	Token* next;
};

struct grammer_tree{
	int value;//vaule
	grammer_tree* next;
	grammer_tree* child;
};

class Grammer_Analysis
{
public:
	Grammer_Analysis()
	{
		grammer_in_head=new Token;//哨兵头
		grammer_stack=new int[stack_len];//初始化符号栈
		input_stack=new int[100000];
		ReadToken();//先读取token序列
		ReadArray();//先读取 状态转换矩阵 序列
		CreatReadStack();
	}
	~Grammer_Analysis(){}
	//读取token序列
	void ReadToken(void)
	{
		FILE* fp=NULL;//文件指针
		if((fp=fopen(filepath,"r"))==NULL)
		{
			printf("cannot open this file\n");
			exit(0);
		}
		Token* current=NULL;
		Token* bef_current=grammer_in_head;
		char key[100];
		char value[100];
		while(!feof(fp))
		{
			fscanf(fp,"< %s , %s >%*[\n]",key,value);
			// printf("KEY : %s   VALUE : %s\n",key,value );
			if (strcmp(key,"STR")==0 || strcmp(value,"\'")==0  )
			{
				continue;
			}
                current=new Token;
                current->Typename=key;
                current->value=value;
                current->next=NULL;
                bef_current->next=current;
                bef_current=current;
		}

		current=new Token;
		current->next=NULL;
		bef_current->next=current;

		bef_current=grammer_in_head;
		grammer_in_head=grammer_in_head->next;
		delete bef_current;
		fclose(fp);
	}
	//读取状态转换矩阵
	void ReadArray(void)
	{
		FILE* fp=NULL;//文件指针
		if((fp=fopen(StateArrayFilePath,"r"))==NULL)
		{
			printf("cannot open this file\n");
			exit(0);
		}
		StateArray=new char*[hight];
		for (int i = 0; i < hight; ++i)
		{
			char* temp_line=new char[width];
			for (int j = 0; j < width; ++j)
			{
				fscanf(fp,"%d",temp_line+j);
			}
			StateArray[i]=temp_line;
		}
		fclose(fp);
	}
	//读取一个字符
	int ReadCH(void)
	{
		if (grammer_in_head->next==NULL)
		{
			return -2;
		}
		string temp_name = grammer_in_head->Typename;
		string value = grammer_in_head->value;
		Token *p =grammer_in_head;
		grammer_in_head=grammer_in_head->next;
		delete p;
		if (temp_name=="ID")
		{
			return 102;
		}
		else if (value=="program")
		{
			return 101;
		}
		else if (value=="type")
		{
			return 103;
		}
		else if (value=="var")
		{
			return 104;
		}
		else if (value=="procedure")
		{
			return 105;
		}
		else if (value=="begin")
		{
			return 106;
		}
		else if (value=="integer")
		{
			return 107;
		}
		else if (value=="char")
		{
			return 108;
		}
		else if (value=="array")
		{
			return 109;
		}
		else if (value=="record")
		{
			return 110;
		}
		else if (temp_name=="INTC")
		{
			return 111;
		}
		else if (value=="end")
		{
			return 112;
		}
		else if (value==";")
		{
			return 113;
		}
		else if (value==",")
		{
			return 114;
		}
		else if (value==")")
		{
			return 115;
		}
		else if (value=="if")
		{
			return 116;
		}
		else if (value=="while")
		{
			return 117;
		}
		else if (value=="return")
		{
			return 118;
		}
		else if (value=="read")
		{
			return 119;
		}
		else if (value=="write")
		{
			return 120;
		}
		else if (value=="else")
		{
			return 121;
		}
		else if (value=="fi")
		{
			return 122;
		}
		else if (value=="endwh")
		{
			return 123;
		}
		else if (value==":=")
		{
			return 124;
		}
		else if (value=="(")
		{
			return 125;
		}
		else if (value=="[")
		{
			return 126;
		}
		else if (value==".")
		{
			return 127;
		}
		else if (value=="<")
		{
			return 128;
		}

		else if (value=="=")
		{
			return 129;
		}
		else if (value=="]")
		{
			return 130;
		}
		else if (value=="then")
		{
			return 131;
		}
		else if (value=="+")
		{
			return 132;
		}
		else if (value=="-")
		{
			return 133;
		}else if (value=="do")
		{
			return 134;
		}
		else if (value=="*")
		{
			return 135;
		}
		else if (value=="/")
		{
			return 136;
		}
		else if (value=="\\n")
		{
			return 137;
		}
		else if (value=="..")
		{
			return 138;
		}
		else if (value=="of")
		{
			return 139;
		}
		else if (value=="'")
		{
			return 140;
		}
		else
		{
			printf("error token<%s,%s>\n",temp_name.c_str(),value.c_str() );
			return -1;
		}
	}
	void push(int num)
	{
		grammer_stack[stack_top++]=num;
	}
	int pop(void)
	{
		return grammer_stack[--stack_top];
	}
	int get_top(void)
	{
		return grammer_stack[stack_top-1];
	}
	int empty(void)
	{
		return (stack_top==0)? 1:0;
	}
	int encode(string tempName)
	{
		if (tempName=="ID")
		{
			return 102;
		}
		else if (tempName=="program")
		{
			return 101;
		}
		else if (tempName=="type")
		{
			return 103;
		}
		else if (tempName=="var")
		{
			return 104;
		}
		else if (tempName=="procedure")
		{
			return 105;
		}
		else if (tempName=="begin")
		{
			return 106;
		}
		else if (tempName=="integer")
		{
			return 107;
		}
		else if (tempName=="char")
		{
			return 108;
		}
		else if (tempName=="array")
		{
			return 109;
		}
		else if (tempName=="record")
		{
			return 110;
		}
		else if (tempName=="INTC")
		{
			return 111;
		}
		else if (tempName=="end")
		{
			return 112;
		}
		else if (tempName==";")
		{
			return 113;
		}
		else if (tempName==",")
		{
			return 114;
		}
		else if (tempName==")")
		{
			return 115;
		}
		else if (tempName=="if")
		{
			return 116;
		}
		else if (tempName=="while")
		{
			return 117;
		}
		else if (tempName=="return")
		{
			return 118;
		}
		else if (tempName=="read")
		{
			return 119;
		}
		else if (tempName=="write")
		{
			return 120;
		}
		else if (tempName=="else")
		{
			return 121;
		}
		else if (tempName=="fi")
		{
			return 122;
		}
		else if (tempName=="endwh")
		{
			return 123;
		}
		else if (tempName==":=")
		{
			return 124;
		}
		else if (tempName=="(")
		{
			return 125;
		}
		else if (tempName=="[")
		{
			return 126;
		}
		else if (tempName==".")
		{
			return 127;
		}
		else if (tempName=="<")
		{
			return 128;
		}

		else if (tempName=="=")
		{
			return 129;
		}
		else if (tempName=="]")
		{
			return 130;
		}
		else if (tempName=="then")
		{
			return 131;
		}
		else if (tempName=="+")
		{
			return 132;
		}
		else if (tempName=="-")
		{
			return 133;
		}else if (tempName=="do")
		{
			return 134;
		}
		else if (tempName=="*")
		{
			return 135;
		}
		else if (tempName=="/")
		{
			return 136;
		}
		else if (tempName=="Program")
		{
			return 1;
		}
		else if (tempName=="ProgramHead")
		{
			return 2;
		}
		else if (tempName=="ProgramName")
		{
			return 3;
		}
		else if (tempName=="DeclarePart")
		{
			return 4;
		}
		else if (tempName=="TypeDecpart")
		{
			return 5;
		}
		else if (tempName=="TypeDec")
		{
			return 6;
		}
		else if (tempName=="TypeDecList")
		{
			return 7;
		}
		else if (tempName=="TypeDecMore")
		{
			return 8;
		}
		else if (tempName=="TypeId")
		{
			return 9;
		}
		else if (tempName=="TypeDef")
		{
			return 10;
		}
		else if (tempName=="BaseType")
		{
			return 11;
		}
		else if (tempName=="StructureType")
		{
			return 12;
		}
		else if (tempName=="ArrayType")
		{
			return 13;
		}
		else if (tempName=="Low")
		{
			return 14;
		}
		else if (tempName=="Top")
		{
			return 15;
		}
		else if (tempName=="RecType")
		{
			return 16;
		}
		else if (tempName=="FieldDecList")
		{
			return 17;
		}
		else if (tempName=="FieldDecMore")
		{
			return 18;
		}
		else if (tempName=="IdList")
		{
			return 19;
		}
		else if (tempName=="IdMore")
		{
			return 20;
		}
		else if (tempName=="VarDecpart")
		{
			return 21;
		}
		else if (tempName=="VarDec")
		{
			return 22;
		}
		else if (tempName=="VarDecList")
		{
			return 23;
		}
		else if (tempName=="VarDecMore")
		{
			return 24;
		}
		else if (tempName=="VarIdList")
		{
			return 25;
		}
		else if (tempName=="VarIdMore")
		{
			return 26;
		}
		else if (tempName=="ProcDecPart")
		{
			return 27;
		}
		else if (tempName=="ProcDec")
		{
			return 28;
		}
		else if (tempName=="ProcDecMore")
		{
			return 29;
		}
		else if (tempName=="ProcName")
		{
			return 30;
		}
		else if (tempName=="ParamList")
		{
			return 31;
		}
		else if (tempName=="ParamDecList")
		{
			return 32;
		}
		else if (tempName=="ParamMore")
		{
			return 33;
		}
		else if (tempName=="Param")
		{
			return 34;
		}
		else if (tempName=="FormList")
		{
			return 35;
		}
		else if (tempName=="FidMore")
		{
			return 36;
		}
		else if (tempName=="ProcDecParts")
		{
			return 37;
		}
		else if (tempName=="ProcBody")
		{
			return 38;
		}
		else if (tempName=="ProgramBody")
		{
			return 39;
		}
		else if (tempName=="StmList")
		{
			return 40;
		}
		else if (tempName=="StmMore")
		{
			return 41;
		}
		else if (tempName=="Stm")
		{
			return 42;
		}
		else if (tempName=="AssCall")
		{
			return 43;
		}
		else if (tempName=="AssignmentRest")
		{
			return 44;
		}
		else if (tempName=="ConditionalStm")
		{
			return 45;
		}
		else if (tempName=="LoopStm")
		{
			return 46;
		}
		else if (tempName=="InputStm")
		{
			return 47;
		}
		else if (tempName=="Invar")
		{
			return 48;
		}
		else if (tempName=="OutputStm")
		{
			return 49;
		}
		else if (tempName=="ReturnStm")
		{
			return 50;
		}
		else if (tempName=="CallStmRest")
		{
			return 51;
		}
		else if (tempName=="ActParamList")
		{
			return 52;
		}
		else if (tempName=="ActParamMore")
		{
			return 53;
		}
		else if (tempName=="RelExp")
		{
			return 54;
		}
		else if (tempName=="OtherRelE")
		{
			return 55;
		}
		else if (tempName=="Exp")
		{
			return 56;
		}
		else if (tempName=="OtherTerm")
		{
			return 57;
		}
		else if (tempName=="Term")
		{
			return 58;
		}
		else if (tempName=="OtherFactor")
		{
			return 59;
		}
		else if (tempName=="Factor")
		{
			return 60;
		}
		else if (tempName=="Variable")
		{
			return 61;
		}
		else if (tempName=="VariMore")
		{
			return 62;
		}
		else if (tempName=="FieldVar")
		{
			return 63;
		}
		else if (tempName=="FieldVarMore")
		{
			return 64;
		}
		else if (tempName=="CmpOp")
		{
			return 65;
		}
		else if (tempName=="AddOp")
		{
			return 66;
		}
		else if (tempName=="MultOp")
		{
			return 67;
		}
		else if (tempName=="\n")
		{
			return 137;
		}
		else if (tempName=="..")
		{
			return 138;
		}
		else if (tempName=="of")
		{
			return 139;
		}
		else if (tempName=="'")
		{
			return 140;
		}
		else
		{
			printf("Unkonwn error：%s\n",tempName );
			return -1;
		}
	}
	string decode(int num)
	{
		switch(num)
		{
			case 101: return "program";
			case 102: return "ID";
			case 103: return "type";
			case 104: return "var";
			case 105: return "procedure";
			case 106: return "begin";
			case 107: return "integer";
			case 108: return "char";
			case 109: return "array";
			case 110: return "record";
			case 111: return "INTC";
			case 112: return "end";
			case 113: return ";";
			case 114: return ",";
			case 115: return ")";
			case 116: return "if";
			case 117: return "while";
			case 118: return "return";
			case 119: return "read";
			case 120: return "write";
			case 121: return "else";
			case 122: return "fi";
			case 123: return "endwh";
			case 124: return ":=";
			case 125: return "(";
			case 126: return "[";
			case 127: return ".";
			case 128: return "<";
			case 129: return "=";
			case 130: return "]";
			case 131: return "then";
			case 132: return "+";
			case 133: return "-";
			case 134: return "do";
			case 135: return "*";
			case 136: return "/";

			case 137: return "\n";
			case 138: return "..";
			case 139: return "of";
			case 140: return "'";
			case 1: return "Program";
			case 2: return "ProgramHead";
			case 3: return "ProgramName";
			case 4: return "DeclarePart";
			case 5: return "TypeDecpart";
			case 6: return "TypeDec";
			case 7: return "TypeDecList";
			case 8: return "TypeDecMore";
			case 9: return "TypeId";
			case 10: return "TypeDef";
			case 11: return "BaseType";
			case 12: return "StructureType";
			case 13: return "ArrayType";
			case 14: return "Low";
			case 15: return "Top";
			case 16: return "RecType";
			case 17: return "FieldDecList";
			case 18: return "FieldDecMore";
			case 19: return "IdList";
			case 20: return "IdMore";
			case 21: return "VarDecpart";
			case 22: return "VarDec";
			case 23: return "VarDecList";
			case 24: return "VarDecMore";
			case 25: return "VarIdList";
			case 26: return "VarIdMore";
			case 27: return "ProcDecPart";
			case 28: return "ProcDec";
			case 29: return "ProcDecMore";
			case 30: return "ProcName";
			case 31: return "ParamList";
			case 32: return "ParamDecList";
			case 33: return "ParamMore";
			case 34: return "Param";
			case 35: return "FormList";
			case 36: return "FidMore";
			case 37: return "ProcDecParts";
			case 38: return "ProcBody";
			case 39: return "ProgramBody";
			case 40: return "StmList";
			case 41: return "StmMore";
			case 42: return "Stm";
			case 43: return "AssCall";
			case 44: return "AssignmentRest";
			case 45: return "ConditionalStm";
			case 46: return "LoopStm";
			case 47: return "InputStm";
			case 48: return "Invar";
			case 49: return "OutputStm";
			case 50: return "ReturnStm";
			case 51: return "CallStmRest";
			case 52: return "ActParamList";
			case 53: return "ActParamMore";
			case 54: return "RelExp";
			case 55: return "OtherRelE";
			case 56: return "Exp";
			case 57: return "OtherTerm";
			case 58: return "Term";
			case 59: return "OtherFactor";
			case 60: return "Factor";
			case 61: return "Variable";
			case 62: return "VariMore";
			case 63: return "FieldVar";
			case 64: return "FieldVarMore";
			case 65: return "CmpOp";
			case 66: return "AddOp";
			case 67: return "MultOp";
		}
		return "Unkonwn error";
	}
	void analysis_init(void)
	{
		push(1);//压入开始符
		grammer_tree* roots = new grammer_tree;

		roots->value=encode("Program");
		roots->next=NULL;
		roots->child=NULL;

		roots->child=analysis();
		print_tree(roots,0);
		printf("grammer_analysis_complete!\n");
	}
	void print_tree(grammer_tree* root,int deep)
	{
		// while(root!=NULL)
		// {
		// 	for (int i = 0; i < deep; ++i)
		// 	{
		// 		printf("-");
		// 	}
		// 	printf("%s\n",decode(root->value).c_str() );
		// 	root=root->next;
		// }
		grammer_tree* S_stack[100];
		int S_top=0;
		while(root!=NULL)
		{
			S_stack[S_top++]=root;
			root=root->next;
		}
		while(S_top!=0)
		{
			for (int i = 0; i < deep; ++i)
			{
				if (i==deep-1)
				{
					printf("|--");
				}
				else
					printf("|   ");
			}
			printf("%s\n",decode(S_stack[S_top-1]->value).c_str() );
			print_tree(S_stack[--S_top]->child,deep+1);
		}
	}
	void CreatReadStack()
	{
		int t=ReadCH();
		while(t!=-2)
		{
			input_stack[input_top++]=t;
			t=ReadCH();
		}
	}
	void ReadNext(void)
	{
		input_bottom++;
	}
	int ReadSimple(void)
	{
		int ch_stack=input_stack[input_bottom];
		while (ch_stack==137)
		{
			line++;
			ch_stack=input_stack[++input_bottom];
		}
		return ch_stack;
	}
	grammer_tree* analysis(void)
	{
		grammer_tree* head=new grammer_tree;//哨兵节点
		head->next=head->child=NULL;
		grammer_tree* tail=head;//尾部指针
		int ch_stack=-1;
		int in_stack=-1;
		ch_stack=ReadSimple();
		in_stack=get_top();
		// printf("%s\n",decode(in_stack).c_str() );
		if (in_stack>100)
		{

			if (in_stack==ch_stack)
			{
				// printf("match lines%d : %s ==%s \n",line/2,decode(in_stack).c_str(),decode(ch_stack).c_str() );
				pop();
			}
			else
			{
				printf("Error! line:%d there should be %s but is %s\n",line/2,decode(in_stack).c_str(),decode(ch_stack).c_str());
				pop();
			}
			ReadNext();
			return NULL;
		}
		else if ( in_stack <=100 && in_stack > 0 )
		{
			int re=StateArray[in_stack-1][ch_stack-100-1]-1;
			while (re==-1)
			{
				printf("ErrorS! line:%d there should be ",line/2);
				int f=0;
				for (int h = 0; h < width; ++h)
				{
					if (StateArray[in_stack-1][h]!=0)
					{
						if (f==0)
						{
							f=h;
						}
						else
							printf("%s OR ",decode(h+100+1).c_str() );
					}
				}
				printf("%s but is %s\n",decode(f+100+1).c_str(),decode(ch_stack).c_str());
				ReadNext();
				ch_stack=ReadSimple();
				re=StateArray[in_stack-1][ch_stack-100-1]-1;
			}

			//打开产生式文件找到所在行
			FILE* fp=NULL;//文件指针
			if((fp=fopen("equation.txt","r"))==NULL)
			{
				printf("cannot open this file\n");
				exit(0);
			}
			string tt;
			int ministack[100];
			int minitop=0;
			while(re!=0)
			{
				fscanf(fp,"%*[^\n]\n");
				re--;
			}
			while(1)
			{
				char* a=new char[100];
				fscanf(fp,"%s",a);
				// printf("%s\n",a);
				tt=a;
				delete a;
				if (tt == "#")
				{
					break;
				}
				ministack[minitop++]=encode(tt);
			}
			fclose(fp);
			pop();
			//读取数据并逆序压栈
			for (int i = minitop; i > 0; --i)
			{
				push(ministack[i-1]);
				grammer_tree* temp_se=new grammer_tree;
				temp_se->value=ministack[i-1];
				temp_se->next=NULL;
				temp_se->child=NULL;
				tail->next=temp_se;
				tail=temp_se;
			}
			grammer_tree* ac_point=head->next;
			// while(ac_point!=NULL)
			// {
			// 	ac_point->child=analysis();
			// 	ac_point=ac_point->next;
			// }
			
			grammer_tree* S_stack[100];
			int S_top=0;
			while(ac_point!=NULL)
			{
				S_stack[S_top++]=ac_point;
				ac_point=ac_point->next;
			}
			while(S_top!=0)
			{
				S_stack[--S_top]->child=analysis();
			}
			// printf("###################################################\n");
			ac_point=head;
			head=head->next;
			delete ac_point;
			return head;
		}
		else
		{
			printf("Unknown Grammer Error!\n");
			return NULL;
		}
		return NULL;
	}
private:
	Token* grammer_in_head=NULL;//输入流链表（token）
	char filepath[10000]="222.txt";
	char StateArrayFilePath[10000]="StateArray.txt";
	char** StateArray=NULL;//状态转换矩阵
	int hight=67;
	int width=36;//矩阵长与宽
	int* grammer_stack=NULL;
	int* input_stack=NULL;//输入栈
	int input_top=0;
	int input_bottom=0;
	int stack_top=0;
	int stack_len=1000000;
	int line=2;//行号
	grammer_tree* roots=NULL;//语法树根节点
};



int main(){
	Grammer_Analysis ga;
	ga.analysis_init();
    return 0;
}

//输入栈

//符号栈
//分析表


// void grammer_analysis()
// {
// 	while(1)
// 	{
// 		//建立输入流

// 		//建立符号栈
//
// 		//状态转换函数
// 		//状态转换矩阵（LL(1)分析表）



// 		//正常退出
// 			//输入流空,符号栈空，处于终止状态正常退出
// 			//
// 		//异常退出
// 			//输入流空结束
// 			//符号栈空结束
// 			//处于非终止状态结束
// 	}
// }
