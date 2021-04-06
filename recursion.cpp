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


class Recursion_analysis
{
public:
    Recursion_analysis()
    {
		grammer_in_head = new Token;
		ReadToken();

    }
	~Recursion_analysis(){}


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
    void aProgram()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == 101)
		{
			aProgramHead();
			aDeclarePart();
			aProgramBody();
		}
		else 
		{
			error(1);
		}

    }


    //对应编码2
    void aProgramHead()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("program"))
		{
			rdToken();
			aProgramName();
		}
		else
		{
			error(2);
		}
    }

    //对应编码3
    void aProgramName() 
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			rdToken();
		}
		else
		{
			error(3);
		}

    }

    //对应编码4
    void aDeclarePart() 
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("type") || nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			aTypeDecPart();
			aVarDecpart();
			aProcDecPart();
		}
		else
		{
			error(4);
		}

    }

    //对应编码5,文法5，6
    void aTypeDecPart() 
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return;
		}
		else if(nowInput == encode("type"))
		{
			aTypeDec();
		}
		else
		{
			error(5);
		}
    }
    
    //对应编码6,文法7
    void aTypeDec()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("type"))
		{
			rdToken();
			aTypeDecList();
		}
		else
		{
			error(6);
		}
    }

    //对应编码7,文法8
    void aTypeDecList() 
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			aTypeId();
			if(nowInput == encode("=") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("="));
				return;
			}
			aTypeDef();
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode(";"));
				return;
			}
			aTypeDecMore();
		}
		else
		{
			error(7);
		}
    }
    //对应编码8,文法9，10
    void aTypeDecMore() 
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return;
		}
		else if(nowInput == encode("ID"))
		{
			aTypeDecList();
		}
		else
		{
			error(8);
		}
    }
    //对应编码9,文法11
    void aTypeId()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("ID"));
				return;
			}
		}
		else
		{
			error(9);
		}
    }

    //对应编码10,文法12，13，14
    void aTypeDef()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("integer") || nowInput == encode("char"))
		{
			aBaseType();
		}
		else if(nowInput == encode("array") || nowInput == encode("record"))
		{
			aStructureType();
		}
		else if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("ID"));
				return;
			}
		}
		else
		{
			error(10);
		}
    }

    //对应编码11,文法15，16
    void aBaseType()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("integer"))
		{
			if(nowInput == encode("integer") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("integer"));
				return;
			}
		}
		else if(nowInput == encode("char"))
		{
			if(nowInput == encode("char") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("char"));
				return;
			}
		}
		else
		{
			error(11);
		}
    }

    //对应编码12,文法17，18
    void aStructureType()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("array"))
		{
			aArrayType();
		}
		else if(nowInput == encode("record"))
		{
			aRecType();
		}
		else
		{
			error(12);
		}
    }

    //对应编码13,文法19
    void aArrayType()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("array"))
		{
			if(nowInput == encode("array") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("array"));
				return;
			}
			if(nowInput == encode("[") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("["));
				return;
			}
			aLow();
			if(nowInput == encode("..") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode(".."));
				return;
			}
			aTop();
			if(nowInput == encode("]") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("]"));
				return;
			}
			if(nowInput == encode("of") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("of"));
				return;
			}
			aBaseType();
		}
		else
		{
			error(13);
		}
    }

    //对应编码14,文法20
    void aLow()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("INTC"))
		{
			if(nowInput == encode("INTC") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("INTC"));
				return;
			}
		}
		else
		{
			error(14);
		}
    }

    //对应编码15,文法21
    void aTop()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("INTC"))
		{
			if(nowInput == encode("INTC") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("INTC"));
				return;
			}
		}
		else
		{
			error(15);
		}
    }

    //对应编码16,文法22
    void aRecType()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("record"))
		{
			if(nowInput == encode("record") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("record"));
				return;
			}
			aFieldDecList();
			if(nowInput == encode("end") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("end"));
				return;
			}
		}
		else
		{
			error(16);
		}
    }

    //对应编码17,文法23，24
    void aFieldDecList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("integer") || nowInput == encode("char"))
		{
			aBaseType();
			aIdList();
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode(";"));
				return;
			}
			aFieldDecMore();
		}
		else if(nowInput == encode("array"))
		{
			aArrayType();
			aIdList();
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode(";"));
				return;
			}
			aFieldDecMore();
		}
		else
		{
			error(17);
		}
    }

    //对应编码18,文法25，26
    void aFieldDecMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("end"))
		{
			return;
		}
		else if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array"))
		{
			aFieldDecList();
		}
		else
		{
			error(18);
		}
    }

    //对应编码19,文法27
    void aIdList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("ID"));
				return;
			}
			aIdMore();
		}
		else
		{
			error(19);
		}
    }

    //对应编码20,文法28，29
    void aIdMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(";"))
		{
			return;
		}
		else if(nowInput == encode(","))
		{
			if(nowInput == encode(",") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode(","));
				return;
			}
			aIdList();
		}
		else
		{
			error(20);
		}
    }

    //对应编码21,文法30，31
    void aVarDecpart()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return;
		}
		else if(nowInput == encode("var"))
		{
			aVarDec();
		}
		else
		{
			error(21);
			return;
		}
    }

    //对应编码22,文法32
    void aVarDec()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("var"))
		{
			if(nowInput == encode("var") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("var"));
				return;
			}
			aVarDecList();
		}
		else
		{
			error(22);
		}
    }

    //对应编码23,文法33
    void aVarDecList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID"))
		{
			aTypeDef();
			aVarIdList();
			if(nowInput == encode(";") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode(";"));
				return;
			}
			aVarDecMore();
		}
		else
		{
			error(23);
		}
    }

    //对应编码24,文法34，35
    void aVarDecMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			return;
		}
		else if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID"))
		{
			aVarDecList();
		}
		else
		{
			error(24);
		}
    }

    //对应编码25,文法36
    void aVarIdList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			if(nowInput == encode("ID") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode("ID"));
				return;
			}
			aVarIdMore();
		}
		else
		{
			error(25);
		}
    }

    //对应编码26,文法37，38
    void aVarIdMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(";"))
		{
			return;
		}
		else if(nowInput == encode(","))
		{
			if(nowInput == encode(",") && flag == 1)
			{
				rdToken();
			}
			else
			{
				error(encode(","));
				return;
			}
			aVarIdList();
		}
		else
		{
			error(26);
		}
    }

    //对应编码27,文法39，40
    void aProcDecPart()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("begin"))
		{
			return;
		}
		else if(nowInput == encode("procedure"))
		{
			aProcDec();
		}
		else
		{
			error(27);
		}
    }

    //对应编码28,文法41
    void aProcDec()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("procedure"))
		{
			matchResult = matchAll("procedure");
			if(matchResult == 0)
			{
				
				return;
			}
			aProcName();
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return;
			}
			aParamList();
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return;
			}
			matchResult = matchAll(";");
			if(matchResult == 0)
			{
				
				return;
			}
			aProcDecParts();
			aProcBody();
			aProcDecMore();

		}
		else
		{
			error(28);
		}
    }

    //对应编码29,文法42，43
    void aProcDecMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("begin"))
		{
			return;
		}
		else if(nowInput == encode("procedure"))
		{
			aProcDec();
		}
		else
		{
			error(29);
		}
    }

    //对应编码30,文法44
    void aProcName()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(30);
		}
    }

    //对应编码31,文法45，46
    void aParamList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(")"))
		{
			return;
		}
		else if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID") || nowInput == encode("var"))
		{
			aParamDecList();
		}
		else
		{
			error(31);
		}
    }

    //对应编码32,文法47
    void aParamDecList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID") || nowInput == encode("var"))
		{
			aParam();
			aParamMore();
		}
		else
		{
			error(32);
		}
    }

    //对应编码33,文法48，49
    void aParamMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(")"))
		{
			return;
		}
		else if(nowInput == encode(";"))
		{
			matchResult = matchAll(";");
			if(matchResult == 0)
			{
				
				return;
			}
			aParamDecList();
		}
		else
		{
			error(33);
		}
    }

    //对应编码34,文法50，51
    void aParam()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("integer") || nowInput == encode("char") || nowInput == encode("array") || nowInput == encode("record") || nowInput == encode("ID"))
		{
			aTypeDef();
			aFormList();
		}
		else if(nowInput == encode("var"))
		{
			matchResult = matchAll("var");
			if(matchResult == 0)
			{
				
				return;
			}
			aTypeDef();
			aFormList();
		}
		else
		{
			error(34);
		}
    }

    //对应编码35,文法52
    void aFormList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return;
			}
			aFidMore();
		}
		else
		{
			error(35);
		}
    }

    //对应编码36,文法53，54
    void aFidMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(";") || nowInput == encode(")"))
		{
			return;
		}
		else if(nowInput == encode(","))
		{
			matchResult = matchAll(",");
			if(matchResult == 0)
			{
				
				return;
			}
			aFormList();
		}
		else
		{
			error(36);
		}
    }

    //对应编码37,文法55
    void aProcDecParts()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("type") || nowInput == encode("var") || nowInput == encode("procedure") || nowInput == encode("begin"))
		{
			aDeclarePart();
		}
		else
		{
			error(37);
		}
    }

    //对应编码38,文法56
    void aProcBody()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("begin"))
		{
			aProgramBody();
		}
		else
		{
			error(38);
		}
    }

    //对应编码39,文法57
    void aProgramBody()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("begin"))
		{
			matchResult = matchAll("begin");
			if(matchResult == 0)
			{
				
				return;
			}
			aStmList();
			matchResult = matchAll("end");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(39);
		}
    }

    //对应编码40,文法58
    void aStmList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID") || nowInput == encode("if") || nowInput == encode("while") || nowInput == encode("return") || nowInput == encode("read") || nowInput == encode("write"))
		{
			aStm();
			aStmMore();
		}
		else
		{
			error(40);
		}
    }

    //对应编码41,文法59，60
    void aStmMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("end") || nowInput == encode("endwh"))
		{
			return;
		}
		else if(nowInput == encode(";"))
		{
			matchResult = matchAll(";");
			if(matchResult == 0)
			{
				
				return;
			}
			aStmList();
		}
		else
		{
			error(41);
		}
    }

    //对应编码42,文法61，62，63，64，65，66
    void aStm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("if"))
		{
			aConditionalStm();
		}
		else if(nowInput == encode("while"))
		{
			aLoopStm();
		}
		else if(nowInput == encode("read"))
		{
			aInputStm();
		}
		else if(nowInput == encode("write"))
		{
			aOutputStm();
		}
		else if(nowInput == encode("return"))
		{
			aReturnStm();
		}
		else if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return;
			}
			aAssCall();
		}
		else
		{
			error(42);
		}
    }

    //对应编码43,文法67，68
    void aAssCall()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(":="))
		{
			aAssignmentRest();
		}
		else if(nowInput == encode("("))
		{
			aCallStmRest();
		}
		else
		{
			error(43);
		}
    }

    //对应编码44,文法69
    void aAssignmentRest()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("[") || nowInput == encode(".") || nowInput == encode(":="))
		{
			aVariMore();
			matchResult = matchAll(":=");
			if(matchResult == 0)
			{
				
				return;
			}
			aExp();
		}
		else
		{
			error(44);
			return;
		}
    }

    //对应编码45,文法70
    void aConditionalStm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("if"))
		{
			matchResult = matchAll("if");
			if(matchResult == 0)
			{
				
				return;
			}
			aRelExp();
			matchResult = matchAll("then");
			if(matchResult == 0)
			{
				
				return;
			}
			aStmList();
			matchResult = matchAll("else");
			if(matchResult == 0)
			{
				
				return;
			}
			aStmList();
			matchResult = matchAll("fi");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(45);
			return;
		}
    }

    //对应编码46,文法71
    void aLoopStm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("while"))
		{
			matchResult = matchAll("while");
			if(matchResult == 0)
			{
				
				return;
			}
			aRelExp();
			matchResult = matchAll("do");
			if(matchResult == 0)
			{
				
				return;
			}
			aStmList();
			matchResult = matchAll("endwh");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(46);
		}
    }

    //对应编码47,文法72
    void aInputStm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("read"))
		{
			matchResult = matchAll("read");
			if(matchResult == 0)
			{
				
				return;
			}
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return;
			}
			aInvar();
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(47);
		}
    }

    //对应编码48,文法73
    void aInvar()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(48);
		}
    }

    //对应编码49,文法74
    void aOutputStm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("write"))
		{
			matchResult = matchAll("write");
			if(matchResult == 0)
			{
				
				return;
			}
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return;
			}
			aExp();
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(49);
		}
    }

    //对应编码50,文法75
    void aReturnStm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("return"))
		{
			matchResult = matchAll("return");
			if(matchResult == 0)
			{
				
				return;
			}
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return;
			}
			aExp();
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(50);
		}
    }

    //对应编码51,文法76
    void aCallStmRest()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("("))
		{
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return;
			}
			aActParamList();
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(51);
		}
    }

    //对应编码52,文法77，78
    void aActParamList()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(")"))
		{
			return;
		}
		else if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			aExp();
			aActParamMore();
		}
		else
		{
			error(52);
		}
    }

    //对应编码53,文法79,80
    void aActParamMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(")"))
		{
			return;
		}
		else if(nowInput == encode(","))
		{
			matchResult = matchAll(",");
			if(matchResult == 0)
			{
				
				return;
			}
			aActParamList();
		}
		else
		{
			error(53);
		}
    }

    //对应编码54,文法81
    void aRelExp()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			aExp();
			aOtherRelE();
		}
		else
		{
			error(54);
		}
    }

    //对应编码55,文法82
    void aOtherRelE()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("<") || nowInput == encode("="))
		{
			aCmpOp();
			aExp();
		}
		else
		{
			error(55);
		}
    }

    //对应编码56,文法83
    void aExp()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			aTerm();
			aOtherTerm();
		}
		else
		{
			error(56);
		}
    }

    //对应编码57,文法84，85
    void aOtherTerm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("<") || nowInput == encode("=")|| nowInput == encode("]") || nowInput == encode("then")
		|| nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("do") || nowInput == encode("endwh")
		|| nowInput == encode(")") || nowInput == encode("end") || nowInput == encode(";") || nowInput == encode(","))
		{
			return;
		}
		else if(nowInput == encode("+") || nowInput == encode("-"))
		{
			aAddOp();
			aExp();
		}
		else
		{
			error(57);
		}
    }

    //对应编码58,文法86
    void aTerm()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("(") || nowInput == encode("INTC") || nowInput == encode("ID"))
		{
			aFactor();
			aOtherFactor();
		}
		else
		{
			error(58);
		}
    }

    //对应编码59,文法87，88
    void aOtherFactor()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("+") || nowInput == encode("-") || nowInput == encode("<") || nowInput == encode("=")
		|| nowInput == encode("]") || nowInput == encode("then") || nowInput == encode("else") || nowInput == encode("fi")
		|| nowInput == encode("do") || nowInput == encode("endwh") || nowInput == encode(")") || nowInput == encode(";")
		|| nowInput == encode(",") || nowInput == encode("end"))
		{
			return;
		}
		else if(nowInput == encode("*") || nowInput == encode("/"))
		{
			aMultOp();
			aTerm();
		}
		else
		{
			error(59);
		}
    }

    //对应编码60,文法89，90，91
    void aFactor()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("("))
		{
			matchResult = matchAll("(");
			if(matchResult == 0)
			{
				
				return;
			}
			aExp();
			matchResult = matchAll(")");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else if(nowInput == encode("INTC"))
		{
			matchResult = matchAll("INTC");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else if(nowInput == encode("ID"))
		{
			aVariable();
		}
		else
		{
			error(60);
		}
    }

    //对应编码61,文法92
    void aVariable()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return;
			}
			aVariMore();
		}
		else
		{
			error(61);
		}
    }

    //对应编码62,文法93，94，95
    void aVariMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(":=") || nowInput == encode("*") || nowInput == encode("/") || nowInput == encode("+")
		|| nowInput == encode("-") || nowInput == encode("<") || nowInput == encode("=") || nowInput == encode("then")
		|| nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("do") || nowInput == encode("endwh")
		|| nowInput == encode(")") || nowInput == encode("end") || nowInput == encode(";") || nowInput == encode(","))
		{
			return;
		}
		else if(nowInput == encode("["))
		{
			matchResult = matchAll("[");
			if(matchResult == 0)
			{
				
				return;
			}
			aExp();
			matchResult = matchAll("]");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else if(nowInput == encode("."))
		{
			matchResult = matchAll(".");
			if(matchResult == 0)
			{
				
				return;
			}
			aFieldVar();
		}
		else
		{
			error(62);
		}
    }

    //对应编码63,文法96
    void aFieldVar()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("ID"))
		{
			matchResult = matchAll("ID");
			if(matchResult == 0)
			{
				
				return;
			}
			aFieldVarMore();
		}
		else
		{
			error(63);
		}
    }

    //对应编码64,文法97，98
    void aFieldVarMore()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode(":=") || nowInput == encode("*") || nowInput == encode("/") || nowInput == encode("+")
		|| nowInput == encode("-") || nowInput == encode("<") || nowInput == encode("=") || nowInput == encode("then")
		|| nowInput == encode("else") || nowInput == encode("fi") || nowInput == encode("do") || nowInput == encode("endwh")
		|| nowInput == encode(")") || nowInput == encode("end") || nowInput == encode(";") || nowInput == encode(","))
		{
			return;
		}
		else if(nowInput == encode("["))
		{
			matchResult = matchAll("[");
			if(matchResult == 0)
			{
				
				return;
			}
			aExp();
			matchResult = matchAll("]");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(64);
		}
    }

    //对应编码65,文法99,100
    void aCmpOp()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("<"))
		{
			matchResult = matchAll("<");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else if(nowInput == encode("="))
		{
			matchResult = matchAll("=");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(65);
		}
    }

    //对应编码66,文法101，102
    void aAddOp()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("+"))
		{
			matchResult = matchAll("+");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else if(nowInput == encode("-"))
		{
			matchResult = matchAll("-");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(66);
		}
    }

    //对应编码67,文法103，104
    void aMultOp()
    {
		if(flag == 0)
		{
			return;
		}
		if(nowInput == encode("*"))
		{
			matchResult = matchAll("*");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else if(nowInput == encode("/"))
		{
			matchResult = matchAll("/");
			if(matchResult == 0)
			{
				
				return;
			}
		}
		else
		{
			error(67);
		}
    }
	void analysis()
	{
		rdToken();
		aProgram();
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