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

class Recursion_analysis
{
public:
    Recursion_analysis()
    {
		grammer_in_head = new Token;
		ReadToken();

    }
	~Recursion_analysis(){}


	/* 关于语法树结点的相关操作 */
	void print_tree(grammer_tree* root,int deep)
	{
		grammer_tree* S_queue[100];
		int tail=0;
		int head = -1;
		while(root!=NULL)
		{
			S_queue[tail++]=root;
			root=root->next;
		}
		while(tail - head - 1!=0 && tail != 0)
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
			int value = S_queue[head + 1]->value;
			printf("%s\n",decode(S_queue[head+1]->value).c_str() );
			head ++;
			print_tree(S_queue[head]->child,deep+1);
		}
	}
		/*void print_tree(grammer_tree* root,int deep)
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
		int max = S_top;
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
	}*/

	grammer_tree* newNode(int code)
	{
		grammer_tree* node = new grammer_tree;
		node->value = code;
		node->next = NULL;
		node->child = NULL;
		return node;
	}


    int ReadCH(void)
	{
		string temp_name = grammer_in_head->Typename;
		string value = grammer_in_head->value;
		nowValue = value;
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

    int encode(string tempName)
	{
		if(tempName == "error")
		{
			return 155;
		}
		else if (tempName=="ID")
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
			case 155: return "error";
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
    /******************子程序*********************/
    void rdToken() 
    {
		if(grammer_in_head->next == NULL)
		{
			flag = 0;
			return;
		}
		nowInput = ReadCH();
		while (nowInput == 137)
		{
			line ++;
			nowInput = ReadCH();
		}
		

    }

	int matchAll(string nowOperator)//匹配所有终极符
	{
		if(nowInput == encode(nowOperator) && flag == 1)
		{
			rdToken();
			return 1;
		}
		else
		{
			error(encode(nowOperator));
			return 0;
		}
	}
	void error(int code)
	{
		errorFlag = 1;
		printf("There is an error in line %d! ",line/2);
		if(code >= 101 && code <= 140) //匹配终极符时出错对应的error
		{
			printf("There should be a %s but is a %s",decode(code).c_str(), decode(nowInput).c_str());
		}
		else
		{
			switch (code)
			{
			case 1: printf("There should be a program but is a %s",decode(nowInput).c_str());
				break;//Program
			case 2: printf("There should be a program but is a %s",decode(nowInput).c_str());
				break;//ProgramHead
			case 3: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//ProgramName
			case 4: printf("There should be a type or var or procedure or begin but is a %s",decode(nowInput).c_str());
				break;//DeclarePart
			case 5: printf("There should be a var or procedure or begin or type but is a %s",decode(nowInput).c_str());
				break;//TypeDecpart
			case 6: printf("There should be a type but is a %s",decode(nowInput).c_str());
				break;//TypeDec
			case 7: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//TypeDecList
			case 8: printf("There should be a ID or var or procedure or begin but is a %s",decode(nowInput).c_str());
				break;//TypeDecMore
			case 9: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//TypeId
			case 10: printf("There should be a ID or integer or char or array or record but is a %s",decode(nowInput).c_str());
				break;//TypeDef
			case 11: printf("There should be a integer or char but is a %s",decode(nowInput).c_str());
				break;//BaseType
			case 12: printf("There should be a array or record but is a %s",decode(nowInput).c_str());
				break;//StructureType
			case 13: printf("There should be an array but is a %s",decode(nowInput).c_str());
				break;//ArrayType
			case 14: printf("There should be a INTC but is a %s",decode(nowInput).c_str());
				break;//Low
			case 15: printf("There should be a INTC but is a %s",decode(nowInput).c_str());
				break;//Top
			case 16: printf("There should be a record but is a %s",decode(nowInput).c_str());
				break;//Rectype
			case 17: printf("There should be a integer or char or array but is a %s",decode(nowInput).c_str());
				break;//FieldDecList
			case 18: printf("There should be a end or integer or char or array but is a %s",decode(nowInput).c_str());
				break;//FieldDecMore
			case 19: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//idList
			case 20: printf("There should be a ; or , but is a %s",decode(nowInput).c_str());
				break;//Idmore
			case 21: printf("There should be a procedure or begin but is a %s",decode(nowInput).c_str());
				break;//VarDecPart
			case 22: printf("There should be a var but is a %s",decode(nowInput).c_str());
				break;//VarDec
			case 23: printf("There should be a integer or char or array or record or ID but is a %s",decode(nowInput).c_str());
				break;//VarDecList
			case 24: printf("There should be a integer or char or array or record or ID but is a %s",decode(nowInput).c_str());
				break;//VarDecMore
			case 25: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//VarIdList
			case 26: printf("There should be a ; or , but is a %s",decode(nowInput).c_str());
				break;//VarIdMore
			case 27: printf("There should be a begin or procedure but is a %s",decode(nowInput).c_str());
				break;//procDecPart
			case 28: printf("There should be a procedure but is a %s",decode(nowInput).c_str());
				break;//ProcDec
			case 29: printf("There should be a begin or procedure but is a %s",decode(nowInput).c_str());
				break;//ProcDecMore
			case 30: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//ProcName
			case 31: printf("There should be a ) or integer or char or array or record or ID or var but is a %s",decode(nowInput).c_str());
				break;//ParamList
			case 32: printf("There should be a integer or char or array or record or ID or var but is a %s",decode(nowInput).c_str());
				break;//ParamDecList
			case 33: printf("There should be a ) or ; but is a %s",decode(nowInput).c_str());
				break;//ParamMore
			case 34: printf("There should be a integer or char or array or record or ID or var but is a %s",decode(nowInput).c_str());
				break;//Param
			case 35: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//FormList
			case 36: printf("There should be a ; or ) or , but is a %s",decode(nowInput).c_str());
				break;//FidMore
			case 37: printf("There should be a type or var or procedure or begin but is a %s",decode(nowInput).c_str());
				break;//ProcDecParts
			case 38: printf("There should be a begin but is a %s",decode(nowInput).c_str());
				break;//ProcBody
			case 39: printf("There should be a begin but is a %s",decode(nowInput).c_str());
				break;//ProgramBody
			case 40: printf("There should be a ID or if or while or return or read or write but is a %s",decode(nowInput).c_str());
				break;//StmList
			case 41: printf("There should be a else or fi or end or endwh or ; but is a %s",decode(nowInput).c_str());
				break;//StmMore
			case 42: printf("There should be a if or while or read or write or return or id but is a %s",decode(nowInput).c_str());
				break;//Stm
			case 43: printf("There should be a := or ( but is a %s",decode(nowInput).c_str());
				break;//AssCall
			case 44: printf("There should be a [ or . or := but is a %s",decode(nowInput).c_str());
				break;//AssignmentRest
			case 45: printf("There should be a if but is a %s",decode(nowInput).c_str());
				break;//ConditionalStm
			case 46: printf("There should be a while but is a %s",decode(nowInput).c_str());
				break;//LoopStm
			case 47: printf("There should be a read but is a %s",decode(nowInput).c_str());
				break;//InputStm
			case 48: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//Invar
			case 49: printf("There should be a write but is a %s",decode(nowInput).c_str());
				break;//OutputStm
			case 50: printf("There should be a return but is a %s",decode(nowInput).c_str());
				break;//ReturnStm
			case 51: printf("There should be a ( but is a %s",decode(nowInput).c_str());
				break;//CallStmRest
			case 52: printf("There should be a ) or ( or INTC or ID but is a %s",decode(nowInput).c_str());
				break;//ActParamList
			case 53: printf("There should be a ) or , but is a %s",decode(nowInput).c_str());
				break;//ActParamMore
			case 54: printf("There should be a ( or INTC or ID but is a %s",decode(nowInput).c_str());
				break;//RelExp
			case 55: printf("There should be a < or = but is a %s",decode(nowInput).c_str());
				break;//OtherRelE
			case 56: printf("There should be a ( or INTC or ID but is a %s",decode(nowInput).c_str());
				break;//Exp
			case 57: printf("There should be a < or = or ] or then or else or fi or do or endwh or ) or end or ; or , or + or - but is a %s",decode(nowInput).c_str());
				break;//OtherTerm
			case 58: printf("There should be a ( or INTC or ID but is a %s",decode(nowInput).c_str());
				break;//Term
			case 59: printf("There should be a + or - or < or = or ] or then or else or fi or do or endwh or ) or end or ; or , or * or / but is a %s",decode(nowInput).c_str());
				break;//OtherFactor
			case 60: printf("There should be a ( or INTC or ID but is a %s",decode(nowInput).c_str());
				break;//Factor
			case 61:printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//Variable
			case 62: printf("There should be a := or * or / or + or - or < or = or then or else or fi or do or endwh or ) or end or ; or , or [ or . but is a %s",decode(nowInput).c_str());
				break;//VariMore
			case 63: printf("There should be a ID but is a %s",decode(nowInput).c_str());
				break;//FieldVar
			case 64: printf("There should be a := or * or / or + or - or < or = or then or else or fi or do or endwh or ) or end or ; or , or [ but is a %s",decode(nowInput).c_str());
				break;//FieldVarMore
			case 65: printf("There should be a < or = but is a %s",decode(nowInput).c_str());
				break;//CmpOp
			case 66: printf("There should be a + or - but is a %s",decode(nowInput).c_str());
			    break;//AddOp
			case 67: printf("There should be a * or /  but is a %s",decode(nowInput).c_str());
				break;//MultOp
			default:
			    break;
			}
		}
		printf("\n");
		rdToken();
	}
    //对应编码1
    grammer_tree* aProgram()
    {
		grammer_tree* root = newNode(1);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == 101)
		{
			nowNode->child = aProgramHead();
			nowNode = nowNode->child;
			nowNode->next = aDeclarePart();
			nowNode = nowNode->next;
			nowNode->next = aProgramBody();
		}
		else 
		{
			error(1);
		}
		return root;

    }


    //对应编码2
    grammer_tree* aProgramHead()
    {
		grammer_tree* root = newNode(2);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("program"))
		{
			rdToken();
			nowNode->child = newNode(encode("program"));
			nowNode = nowNode->child;
			nowNode->next = aProgramName();
			nowNode = nowNode->next;;
		}
		else
		{
			error(2);
		}
		return root;
    }

    //对应编码3
    grammer_tree* aProgramName() 
    {
		grammer_tree* root = newNode(3);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			rdToken();
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("ID"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("ID"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(3);
		}
		return root;
    }

    //对应编码4
    grammer_tree* aDeclarePart() 
    {
		grammer_tree* root = newNode(4);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("type") || nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			if(root == nowNode)
			{
			nowNode->child = aTypeDecPart();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDecPart();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aVarDecpart();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarDecpart();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aProcDecPart();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProcDecPart();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(4);
		}
		return root;
    }

    //对应编码5,文法5，6
    grammer_tree* aTypeDecPart() 
    {
		grammer_tree* root = newNode(5);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return root;
		}
		else if(nowInput == encode("type"))
		{
			if(root == nowNode)
			{
			nowNode->child = aTypeDec();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDec();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(5);
		}
		return root;
    }
    
    //对应编码6,文法7
    grammer_tree* aTypeDec()
    {
		grammer_tree* root = newNode(6);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("type"))
		{
			rdToken();
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("type"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("type"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aTypeDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDecList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(6);
		}
		return root;
    }

    //对应编码7,文法8
    grammer_tree* aTypeDecList() 
    {
		grammer_tree* root = newNode(7);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aTypeId();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeId();
			nowNode = nowNode->next;
			}
			if(nowInput == encode("=") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("="));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("="));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("="));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aTypeDef();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDef();
			nowNode = nowNode->next;
			}
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode(";"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode(";"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode(";"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aTypeDecMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDecMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(7);
		}
		return root;
    }
    //对应编码8,文法9，10
    grammer_tree* aTypeDecMore() 
    {
		grammer_tree* root = newNode(8);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return root;
		}
		else if(nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aTypeDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDecList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(8);
		}
		return root;
    }
    //对应编码9,文法11
    grammer_tree* aTypeId()
    {
		grammer_tree* root = newNode(9);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("ID"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("ID"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("ID"));
				return root;
			}
		}
		else
		{
			error(9);
		}
		return root;
    }

    //对应编码10,文法12，13，14
    grammer_tree* aTypeDef()
    {
		grammer_tree* root = newNode(10);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("integer") || nowInput == encode("char"))
		{
			if(root == nowNode)
			{
			nowNode->child = aBaseType();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aBaseType();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("array") || nowInput == encode("record"))
		{
			if(root == nowNode)
			{
			nowNode->child = aStructureType();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStructureType();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("ID"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("ID"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("ID"));
				return root;
			}
		}
		else
		{
			error(10);
		}
		return root;
    }

    //对应编码11,文法15，16
    grammer_tree* aBaseType()
    {
		grammer_tree* root = newNode(11);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("integer"))
		{
			if(nowInput == encode("integer") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("integer"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("integer"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("integer"));
				return root;
			}
			
		}
		else if(nowInput == encode("char"))
		{
			if(nowInput == encode("char") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("char"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("char"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("char"));
				return root;
			}
		}
		else
		{
			error(11);
		}
		return root;
    }

    //对应编码12,文法17，18
    grammer_tree* aStructureType()
    {
		grammer_tree* root = newNode(12);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("array"))
		{
			if(root == nowNode)
			{
			nowNode->child = aArrayType();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aArrayType();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("record"))
		{
			if(root == nowNode)
			{
			nowNode->child = aRecType();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aRecType();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(12);
		}
		return root;
    }

    //对应编码13,文法19
    grammer_tree* aArrayType()
    {
		grammer_tree* root = newNode(13);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("array"))
		{
			if(nowInput == encode("array") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("array"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("array"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("array"));
				return root;
			}
			if(nowInput == encode("[") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("["));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("["));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("["));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aLow();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aLow();
			nowNode = nowNode->next;
			}
			if(nowInput == encode("..") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode(".."));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode(".."));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode(".."));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aTop();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTop();
			nowNode = nowNode->next;
			}
			if(nowInput == encode("]") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("]"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("]"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("]"));
				return root;
			}
			if(nowInput == encode("of") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("of"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("of"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("of"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aBaseType();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aBaseType();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(13);
		}
		return root;
    }

    //对应编码14,文法20
    grammer_tree* aLow()
    {
		grammer_tree* root = newNode(14);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("INTC"))
		{
			if(nowInput == encode("INTC") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("INTC"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("INTC"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("INTC"));
				return root;
			}
			
		}
		else
		{
			error(14);
		}
		return root;
    }

    //对应编码15,文法21
    grammer_tree* aTop()
    {
		grammer_tree* root = newNode(15);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("INTC"))
		{
			if(nowInput == encode("INTC") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("INTC"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("INTC"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("INTC"));
				return root;
			}
		}
		else
		{
			error(15);
		}
		return root;
    }

    //对应编码16,文法22
    grammer_tree* aRecType()
    {
		grammer_tree* root = newNode(16);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("record"))
		{
			if(nowInput == encode("record") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("record"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("record"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("record"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aFieldDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFieldDecList();
			nowNode = nowNode->next;
			}
			if(nowInput == encode("end") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("end"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("end"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("end"));
				return root;
			}
		}
		else
		{
			error(16);
		}
		return root;
    }

    //对应编码17,文法23，24
    grammer_tree* aFieldDecList()
    {
		grammer_tree* root = newNode(17);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("integer") || nowInput == encode("char"))
		{
			if(root == nowNode)
			{
			nowNode->child = aBaseType();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aBaseType();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aIdList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aIdList();
			nowNode = nowNode->next;
			}
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode(";"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode(";"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode(";"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aFieldDecMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFieldDecMore();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("array"))
		{
			if(root == nowNode)
			{
			nowNode->child = aArrayType();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aArrayType();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aIdList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aIdList();
			nowNode = nowNode->next;
			}
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode(";"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode(";"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode(";"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aFieldDecMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFieldDecMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(17);
		}
		return root;
    }

    //对应编码18,文法25，26
    grammer_tree* aFieldDecMore()
    {
		grammer_tree* root = newNode(18);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("end"))
		{
			return root;
		}
		else if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array"))
		{
			if(root == nowNode)
			{
			nowNode->child = aFieldDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFieldDecList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(18);
		}
		return root;
    }

    //对应编码19,文法27
    grammer_tree* aIdList()
    {
		grammer_tree* root = newNode(19);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("ID"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("ID"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("ID"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aIdMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aIdMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(19);
		}
		return root;
    }

    //对应编码20,文法28，29
    grammer_tree* aIdMore()
    {
		grammer_tree* root = newNode(20);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(";"))
		{
			return root;
		}
		else if(nowInput == encode(","))
		{
			if(nowInput == encode(",") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode(","));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode(","));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode(","));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aIdList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aIdList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(20);
		}
		return root;
    }

    //对应编码21,文法30，31
    grammer_tree* aVarDecpart()
    {
		grammer_tree* root = newNode(21);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return root;
		}
		else if(nowInput == encode("var"))
		{
			if(root == nowNode)
			{
			nowNode->child = aVarDec();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarDec();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(21);
			return root;
		}
		return root;
    }

    //对应编码22,文法32
    grammer_tree* aVarDec()
    {
		grammer_tree* root = newNode(22);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("var"))
		{
			if(nowInput == encode("var") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("var"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("var"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("var"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aVarDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarDecList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(22);
		}
		return root;
    }

    //对应编码23,文法33
    grammer_tree* aVarDecList()
    {
		grammer_tree* root = newNode(23);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aTypeDef();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDef();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aVarIdList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarIdList();
			nowNode = nowNode->next;
			}
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode(";"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode(";"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode(";"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aVarDecMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarDecMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(23);
		}
		return root;
    }

    //对应编码24,文法34，35
    grammer_tree* aVarDecMore()
    {
		grammer_tree* root = newNode(24);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return root;
		}
		else if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aVarDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarDecList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(24);
		}
		return root;
    }

    //对应编码25,文法36
    grammer_tree* aVarIdList()
    {
		grammer_tree* root = newNode(25);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode("ID"));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode("ID"));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode("ID"));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aVarIdMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarIdMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(25);
		}
		return root;
    }

    //对应编码26,文法37，38
    grammer_tree* aVarIdMore()
    {
		grammer_tree* root = newNode(26);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(";"))
		{
			return root;
		}
		else if(nowInput == encode(","))
		{
			if(nowInput == encode(",") && flag == 1)
			{
				rdToken();
				if(root == nowNode)
				{
				nowNode->child = newNode(encode(","));
				nowNode = nowNode->child;
				}
				else
				{
				nowNode->next = newNode(encode(","));
				nowNode = nowNode->next;
				}
			}
			else
			{
				error(encode(","));
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = aVarIdList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVarIdList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(26);
		}
		return root;
    }

    //对应编码27,文法39，40
    grammer_tree* aProcDecPart()
    {
		grammer_tree* root = newNode(27);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("begin"))
		{
			return root;
		}
		else if(nowInput == encode("procedure"))
		{
			if(root == nowNode)
			{
			nowNode->child = aProcDec();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProcDec();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(27);
		}
		return root;
    }

    //对应编码28,文法41
    grammer_tree* aProcDec()
    {
		grammer_tree* root = newNode(28);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("procedure"))
		{
			matchResult = matchAll("procedure");
			if(matchResult == 0)
			{
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("procedure"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("procedure"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aProcName();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProcName();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("("));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("("));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aParamList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aParamList();
			nowNode = nowNode->next;
			}
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(")"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(")"));
			nowNode = nowNode->next;
			}
			matchResult = matchAll(";");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(";"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(";"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aProcDecParts();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProcDecParts();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aProcBody();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProcBody();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aProcDecMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProcDecMore();
			nowNode = nowNode->next;
			}

		}
		else
		{
			error(28);
		}
		return root;
    }

    //对应编码29,文法42，43
    grammer_tree* aProcDecMore()
    {
		grammer_tree* root = newNode(29);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("begin"))
		{
			return root;
		}
		else if(nowInput == encode("procedure"))
		{
			if(root == nowNode)
			{
			nowNode->child = aProcDec();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProcDec();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(29);
		}
		return root;
    }

    //对应编码30,文法44
    grammer_tree* aProcName()
    {
		grammer_tree* root = newNode(30);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("ID"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("ID"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(30);
		}
		return root;
    }

    //对应编码31,文法45，46
    grammer_tree* aParamList()
    {
		grammer_tree* root = newNode(31);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(")"))
		{
			return root;
		}
		else if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID") || nowInput == encode("var"))
		{
			if(root == nowNode)
			{
			nowNode->child = aParamDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aParamDecList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(31);
		}
		return root;
    }

    //对应编码32,文法47
    grammer_tree* aParamDecList()
    {
		grammer_tree* root = newNode(32);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID") || nowInput == encode("var"))
		{
			if(root == nowNode)
			{
			nowNode->child = aParam();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aParam();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aParamMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aParamMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(32);
		}
		return root;
    }

    //对应编码33,文法48，49
    grammer_tree* aParamMore()
    {
		grammer_tree* root = newNode(33);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(")"))
		{
			return root;
		}
		else if(nowInput == encode(";"))
		{
			matchResult = matchAll(";");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(";"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(";"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aParamDecList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aParamDecList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(33);
		}
		return root;
    }

    //对应编码34,文法50，51
    grammer_tree* aParam()
    {
		grammer_tree* root = newNode(34);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aTypeDef();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDef();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aFormList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFormList();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("var"))
		{
			matchResult = matchAll("var");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("var"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("var"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aTypeDef();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTypeDef();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aFormList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFormList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(34);
		}
		return root;
    }

    //对应编码35,文法52
    grammer_tree* aFormList()
    {
		grammer_tree* root = newNode(35);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("ID"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("ID"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aFidMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFidMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(35);
		}
		return root;
    }

    //对应编码36,文法53，54
    grammer_tree* aFidMore()
    {
		grammer_tree* root = newNode(36);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(";") || nowInput == encode(")"))
		{
			return root;
		}
		else if(nowInput == encode(","))
		{
			matchResult = matchAll(",");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(","));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(","));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aFormList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFormList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(36);
		}
		return root;
    }

    //对应编码37,文法55
    grammer_tree* aProcDecParts()
    {
		grammer_tree* root = newNode(37);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("type") || nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			if(root == nowNode)
			{
			nowNode->child = aDeclarePart();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aDeclarePart();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(37);
		}
		return root;
    }

    //对应编码38,文法56
    grammer_tree* aProcBody()
    {
		grammer_tree* root = newNode(38);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("begin"))
		{
			if(root == nowNode)
			{
			nowNode->child = aProgramBody();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aProgramBody();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(38);
		}
		return root;
    }

    //对应编码39,文法57
    grammer_tree* aProgramBody()
    {
		grammer_tree* root = newNode(39);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("begin"))
		{
			matchResult = matchAll("begin");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("begin"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("begin"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aStmList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStmList();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("end");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("end"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("end"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(39);
		}
		return root;
    }

    //对应编码40,文法58
    grammer_tree* aStmList()
    {
		grammer_tree* root = newNode(40);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID") || nowInput == encode("if") || nowInput == encode("while") || nowInput == encode("return") || nowInput == encode("read") || nowInput == encode("write"))
		{
			if(root == nowNode)
			{
			nowNode->child = aStm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStm();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aStmMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStmMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(40);
		}
		return root;
    }

    //对应编码41,文法59，60
    grammer_tree* aStmMore()
    {
		grammer_tree* root = newNode(41);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("end") || nowInput == encode("endwh"))
		{
			return root;
		}
		else if(nowInput == encode(";"))
		{
			matchResult = matchAll(";");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(";"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(";"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aStmList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStmList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(41);
		}
		return root;
    }

    //对应编码42,文法61，62，63，64，65，66
    grammer_tree* aStm()
    {
		grammer_tree* root = newNode(42);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("if"))
		{
			if(root == nowNode)
			{
			nowNode->child = aConditionalStm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aConditionalStm();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("while"))
		{
			if(root == nowNode)
			{
			nowNode->child = aLoopStm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aLoopStm();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("read"))
		{
			if(root == nowNode)
			{
			nowNode->child = aInputStm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aInputStm();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("write"))
		{
			if(root == nowNode)
			{
			nowNode->child = aOutputStm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aOutputStm();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("return"))
		{
			if(root == nowNode)
			{
			nowNode->child = aReturnStm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aReturnStm();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("ID"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("ID"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aAssCall();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aAssCall();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(42);
		}
		return root;
    }

    //对应编码43,文法67，68
    grammer_tree* aAssCall()
    {
		grammer_tree* root = newNode(43);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(":="))
		{
			if(root == nowNode)
			{
			nowNode->child = aAssignmentRest();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aAssignmentRest();
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("("))
		{
			if(root == nowNode)
			{
			nowNode->child = aCallStmRest();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aCallStmRest();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(43);
		}
		return root;
    }

    //对应编码44,文法69
    grammer_tree* aAssignmentRest()
    {
		grammer_tree* root = newNode(44);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("[") || nowInput == encode(".") || nowInput == encode(":="))
		{
			if(root == nowNode)
			{
			nowNode->child = aVariMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVariMore();
			nowNode = nowNode->next;
			}
			matchResult = matchAll(":=");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(":="));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(":="));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(44);
			return root;
		}
		return root;
    }

    //对应编码45,文法70
    grammer_tree* aConditionalStm()
    {
		grammer_tree* root = newNode(45);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("if"))
		{
			matchResult = matchAll("if");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("if"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("if"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aRelExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aRelExp();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("then");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("then"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("then"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aStmList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStmList();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("else");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("else"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("else"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aStmList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStmList();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("fi");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("fi"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("fi"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(45);
			return root;
		}
		return root;
    }

    //对应编码46,文法71
    grammer_tree* aLoopStm()
    {
		grammer_tree* root = newNode(46);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("while"))
		{
			matchResult = matchAll("while");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("while"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("while"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aRelExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aRelExp();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("do");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("do"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("do"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aStmList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aStmList();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("endwh");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("endwh"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("endwh"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(46);
		}
		return root;
    }

    //对应编码47,文法72
    grammer_tree* aInputStm()
    {
		grammer_tree* root = newNode(47);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("read"))
		{
			matchResult = matchAll("read");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("read"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("read"));
			nowNode = nowNode->next;
			}
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("("));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("("));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aInvar();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aInvar();
			nowNode = nowNode->next;
			}
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(")"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(")"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(47);
		}
		return root;
    }

    //对应编码48,文法73
    grammer_tree* aInvar()
    {
		grammer_tree* root = newNode(48);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("ID"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("ID"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(48);
		}
		return root;
    }

    //对应编码49,文法74
    grammer_tree* aOutputStm()
    {
		grammer_tree* root = newNode(49);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("write"))
		{
			matchResult = matchAll("write");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("write"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("write"));
			nowNode = nowNode->next;
			}
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("("));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("("));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(")"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(")"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(49);
		}
		return root;
    }

    //对应编码50,文法75
    grammer_tree* aReturnStm()
    {
		grammer_tree* root = newNode(50);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("return"))
		{
			matchResult = matchAll("return");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("return"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("return"));
			nowNode = nowNode->next;
			}
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("("));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("("));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(")"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(")"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(50);
		}
		return root;
    }

    //对应编码51,文法76
    grammer_tree* aCallStmRest()
    {
		grammer_tree* root = newNode(51);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("("))
		{
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("("));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("("));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aActParamList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aActParamList();
			nowNode = nowNode->next;
			}
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(")"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(")"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(51);
		}
		return root;
    }

    //对应编码52,文法77，78
    grammer_tree* aActParamList()
    {
		grammer_tree* root = newNode(52);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(")"))
		{
			return root;
		}
		else if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aActParamMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aActParamMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(52);
		}
		return root;
    }

    //对应编码53,文法79,80
    grammer_tree* aActParamMore()
    {
		grammer_tree* root = newNode(53);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(")"))
		{
			return root;
		}
		else if(nowInput == encode(","))
		{
			matchResult = matchAll(",");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(","));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(","));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aActParamList();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aActParamList();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(53);
		}
		return root;
    }

    //对应编码54,文法81
    grammer_tree* aRelExp()
    {
		grammer_tree* root = newNode(54);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aOtherRelE();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aOtherRelE();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(54);
		}
		return root;
    }

    //对应编码55,文法82
    grammer_tree* aOtherRelE()
    {
		grammer_tree* root = newNode(55);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("<") || nowInput == encode("="))
		{
			if(root == nowNode)
			{
			nowNode->child = aCmpOp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aCmpOp();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(55);
		}
		return root;
    }

    //对应编码56,文法83
    grammer_tree* aExp()
    {
		grammer_tree* root = newNode(56);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aTerm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTerm();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aOtherTerm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aOtherTerm();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(56);
		}
		return root;
    }

    //对应编码57,文法84，85
    grammer_tree* aOtherTerm()
    {
		grammer_tree* root = newNode(57);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("<") || nowInput == encode("=")|| nowInput == encode("]") || nowInput == encode("then")
		|| nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("do") || nowInput == encode("endwh")
		|| nowInput == encode(")") || nowInput == encode("end") || nowInput == encode(";") || nowInput == encode(","))
		{
			return root;
		}
		else if(nowInput == encode("+") || nowInput == encode("-"))
		{
			if(root == nowNode)
			{
			nowNode->child = aAddOp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aAddOp();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(57);
		}
		return root;
    }

    //对应编码58,文法86
    grammer_tree* aTerm()
    {
		grammer_tree* root = newNode(58);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aFactor();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFactor();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aOtherFactor();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aOtherFactor();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(58);
		}
		return root;
    }

    //对应编码59,文法87，88
    grammer_tree* aOtherFactor()
    {
		grammer_tree* root = newNode(59);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("+") || nowInput == encode("-") || nowInput == encode("<") || nowInput == encode("=")
		|| nowInput == encode("]") || nowInput == encode("then") || nowInput == encode("else") || nowInput == encode("fi")
		|| nowInput == encode("do") || nowInput == encode("endwh") || nowInput == encode(")") || nowInput == encode(";")
		|| nowInput == encode(",") || nowInput == encode("end"))
		{
			return root;
		}
		else if(nowInput == encode("*") || nowInput == encode("/"))
		{
			if(root == nowNode)
			{
			nowNode->child = aMultOp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aMultOp();
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aTerm();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aTerm();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(59);
		}
		return root;
    }

    //对应编码60,文法89，90，91
    grammer_tree* aFactor()
    {
		grammer_tree* root = newNode(60);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("("))
		{
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("("));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("("));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode(")"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode(")"));
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("INTC"))
		{
			matchResult = matchAll("INTC");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("INTC"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("INTC"));
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("ID"))
		{
			if(root == nowNode)
			{
			nowNode->child = aVariable();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVariable();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(60);
		}
		return root;
    }

    //对应编码61,文法92
    grammer_tree* aVariable()
    {
		grammer_tree* root = newNode(61);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("ID"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("ID"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aVariMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aVariMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(61);
		}
		return root;
    }

    //对应编码62,文法93，94，95
    grammer_tree* aVariMore()
    {
		grammer_tree* root = newNode(62);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(":=") || nowInput == encode("*") || nowInput == encode("/") || nowInput == encode("+")
		|| nowInput == encode("-") || nowInput == encode("<") || nowInput == encode("=") || nowInput == encode("then")
		|| nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("do") || nowInput == encode("endwh")
		|| nowInput == encode(")") || nowInput == encode("end") || nowInput == encode(";") || nowInput == encode(","))
		{
			return root;
		}
		else if(nowInput == encode("["))
		{
			matchResult = matchAll("[");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("["));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("["));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("]");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("]"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("]"));
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("."))
		{
			matchResult = matchAll(".");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("."));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("."));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aFieldVar();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFieldVar();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(62);
		}
		return root;
    }

    //对应编码63,文法96
    grammer_tree* aFieldVar()
    {
		grammer_tree* root = newNode(63);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("ID"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("ID"));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aFieldVarMore();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aFieldVarMore();
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(63);
		}
		return root;
    }

    //对应编码64,文法97，98
    grammer_tree* aFieldVarMore()
    {
		grammer_tree* root = newNode(64);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode(":=") || nowInput == encode("*") || nowInput == encode("/") || nowInput == encode("+")
		|| nowInput == encode("-") || nowInput == encode("<") || nowInput == encode("=") || nowInput == encode("then")
		|| nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("do") || nowInput == encode("endwh")
		|| nowInput == encode(")") || nowInput == encode("end") || nowInput == encode(";") || nowInput == encode(","))
		{
			return root;
		}
		else if(nowInput == encode("["))
		{
			matchResult = matchAll("[");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("["));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("["));
			nowNode = nowNode->next;
			}
			if(root == nowNode)
			{
			nowNode->child = aExp();
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = aExp();
			nowNode = nowNode->next;
			}
			matchResult = matchAll("]");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("]"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("]"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(64);
		}
		return root;
    }

    //对应编码65,文法99,100
    grammer_tree* aCmpOp()
    {
		grammer_tree* root = newNode(65);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("<"))
		{
			matchResult = matchAll("<");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("<"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("<"));
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("="))
		{
			matchResult = matchAll("=");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("="));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("="));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(65);
		}
		return root;
    }

    //对应编码66,文法101，102
    grammer_tree* aAddOp()
    {
		grammer_tree* root = newNode(66);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("+"))
		{
			matchResult = matchAll("+");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("+"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("+"));
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("-"))
		{
			matchResult = matchAll("-");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("-"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("-"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(66);
		}
		return root;
    }

    //对应编码67,文法103，104
    grammer_tree* aMultOp()
    {
		grammer_tree* root = newNode(67);
		grammer_tree* nowNode = root;
		if(flag == 0)
		{
			return root;
		}
		if(nowInput == encode("*"))
		{
			matchResult = matchAll("*");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("*"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("*"));
			nowNode = nowNode->next;
			}
		}
		else if(nowInput == encode("/"))
		{
			matchResult = matchAll("/");
			if(matchResult == 0)
			{
				
				return root;
			}
			if(root == nowNode)
			{
			nowNode->child = newNode(encode("/"));
			nowNode = nowNode->child;
			}
			else
			{
			nowNode->next = newNode(encode("/"));
			nowNode = nowNode->next;
			}
		}
		else
		{
			error(67);
		}
		return root;
    }
	void analysis()
	{
		rdToken();
		roots = aProgram();
		if(errorFlag == 0)
		{
			print_tree(roots,0);
		}
		printf("grammer_analysis_complete!");
		
	}
    /***************子程序*****************/
	bool isOver(){
		return (flag == 0);
	}


private:
    Token* grammer_in_head=NULL;//输入流链表（token）
    char filepath[10000]="222.txt";
    int nowInput = -1;//当前检测的字符，在每次调用match后更新
    int line=2;
	int flag = 1;
	int matchResult;
	int errorFlag = 0;
	string nowValue;
	grammer_tree* roots = NULL;

};

int main()
{
	Recursion_analysis ra;
	/*while (1)
	{
		if(ra.isOver())
		{
			break;
		}
		ra.rdToken();
	}*/
	ra.analysis();
	return 0;
	
	

}