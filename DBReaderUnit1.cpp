//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBReaderUnit1.h"
#include <shellapi.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//----------------variables-----------------
String DBDir = "";
String MyDBDirMDB = "C:\\Users\\User\\Documents\\Embarcadero\\Studio\\Projects\\DBReader\\Win32\\Debug\\myDB.mdb";
String MyDBDirACCDB = "C:\\Users\\User\\Documents\\Embarcadero\\Studio\\Projects\\DBReader\\Win32\\Debug\\myDB.accdb";
String TableName = "";
int ColNum;

void split(TStringList* lout, char* str, const char* separator) {
	  for(char* tok = strtok(str, separator); tok; tok = strtok(NULL, separator))
		  lout->Add(tok);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	DBGrid1->Visible = false;
	ADOQuery1->Active = false;
	Label2->Visible = false;
	Button1->Enabled = false;
	Button2->Enabled = false;
	Edit1->Enabled = false;
	Edit2->Enabled = false;
	ComboBox1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Open1Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		TStringList*  lst = new TStringList();
		split(lst, AnsiString(OpenDialog1->FileName).c_str(), AnsiString(".").c_str());
		if (lst->Strings[1] == "mdb")
		{
			if (ADOConnection1->Connected == true)
			{
				Edit1->Clear();
				Edit2->Clear();
				ComboBox1->Enabled = false;
				ComboBox1->Clear();
				Button1->Enabled = false;
				Edit1->Enabled = false;
				ADOQuery1->Active = false;
				ADOConnection1->Connected = false;
				ADOConnection1->ConnectionString = "";
				ADOQuery1->SQL->Clear();
				DBGrid1->Visible = false;
				TStringList*  str = new TStringList();
				split(str, AnsiString(DBDir).c_str(), AnsiString(".").c_str());
				if (str->Strings[1] == "mdb") CopyFile(MyDBDirMDB.w_str(),DBDir.w_str(),false);
				if (str->Strings[1] == "accbd") CopyFile(MyDBDirACCDB.w_str(),DBDir.w_str(),false);
			}
			DBDir = OpenDialog1->FileName;
			CopyFile(DBDir.w_str(),MyDBDirMDB.w_str(),false);

			DBDir = OpenDialog1->FileName;
			ADOConnection1->ConnectionString = "Provider=MSDASQL.1; Persist Security info=False; data source=DBReaderMDB";
			ADOConnection1->Connected = true;
			Label2->Visible = true;
			Edit2->Enabled = true;
			Button2->Enabled = true;
		}
		else if (lst->Strings[1] == "accdb")
		{
			if (ADOConnection1->Connected == true)
			{
				Edit1->Clear();
				Edit2->Clear();
				ComboBox1->Enabled = false;
				ComboBox1->Clear();
				Button1->Enabled = false;
				Edit1->Enabled = false;
				ADOQuery1->Active = false;
				ADOConnection1->Connected = false;
				ADOConnection1->ConnectionString = "";
				ADOQuery1->SQL->Clear();
				DBGrid1->Visible = false;
				TStringList*  str = new TStringList();
				split(str, AnsiString(DBDir).c_str(), AnsiString(".").c_str());
				if (str->Strings[1] == "mdb") CopyFile(MyDBDirMDB.w_str(),DBDir.w_str(),false);
				if (str->Strings[1] == "accbd")	CopyFile(MyDBDirACCDB.w_str(),DBDir.w_str(),false);
			}
			DBDir = OpenDialog1->FileName;
			CopyFile(DBDir.w_str(),MyDBDirACCDB.w_str(),false);
			ADOConnection1->ConnectionString = "Provider=MSDASQL.1; Persist Security info=False; data source=DBReaderACCDB";
			ADOConnection1->Connected = true;
			Label2->Visible = true;
			Button2->Enabled = true;
			Edit2->Enabled = true;
		}
		else {ShowMessage("Please choose MS Access Database");}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Close1Click(TObject *Sender)
{
	Edit1->Clear();
	Edit2->Clear();
	ComboBox1->Enabled = false;
	ComboBox1->Clear();
	Button1->Enabled = false;
	Edit1->Enabled = false;
	ADOQuery1->Active = false;
	ADOConnection1->Connected = false;
	ADOConnection1->ConnectionString = "";
	ADOQuery1->SQL->Clear();
	DBGrid1->Visible = false;
	try{TStringList*  str = new TStringList();
	split(str, AnsiString(DBDir).c_str(), AnsiString(".").c_str());
	if (str->Strings[1] == "mdb") CopyFile(MyDBDirMDB.w_str(),DBDir.w_str(),false);
	if (str->Strings[1] == "accbd") CopyFile(MyDBDirACCDB.w_str(),DBDir.w_str(),false);}
	catch (Exception *e){}
	Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Close2Click(TObject *Sender)
{
	Edit1->Clear();
	Edit2->Clear();
	ComboBox1->Enabled = false;
	ComboBox1->Clear();
	Button1->Enabled = false;
	Button2->Enabled = false;
	Edit1->Enabled = false;
	Edit2->Enabled = false;
	ADOQuery1->Active = false;
	ADOConnection1->Connected = false;
	ADOConnection1->ConnectionString = "";
	ADOQuery1->SQL->Clear();
	DBGrid1->Visible = false;
	try{TStringList*  str = new TStringList();
	split(str, AnsiString(DBDir).c_str(), AnsiString(".").c_str());
	if (str->Strings[1] == "mdb") CopyFile(MyDBDirMDB.w_str(),DBDir.w_str(),false);
	if (str->Strings[1] == "accbd") CopyFile(MyDBDirACCDB.w_str(),DBDir.w_str(),false);}
	catch (Exception *e){}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	ADOQuery1->Active = false;
	ADOQuery1->SQL->Clear();
	TableName = Edit2->Text;
	try
	{
		ADOQuery1->SQL->Add("SELECT * FROM "+TableName);
		ADOQuery1->Open();
	}
	catch(Exception *e)
	{
		DBGrid1->Visible = false;
		Label2->Visible = true;
		Button1->Enabled = false;
		Edit1->Enabled = false;
		ComboBox1->Enabled = false;
		ShowMessage("There is no such table");
		return;
	}
	ComboBox1->Clear();
	int i;
	for (i = 0; i < 20; i++)
	{
		try
		{
			ComboBox1->Items->Add(DBGrid1->Columns->Items[i]->FieldName);
			DBGrid1->Columns->Items[i]->Width = 100;
		}
		catch (EArgumentOutOfRangeException *e) {break;}
		ColNum = i;
	}
	ComboBox1->Items->Delete(0);
	DBGrid1->Columns->Items[0]->Visible = false;
	Label2->Visible = false;
	DBGrid1->Visible = true;
	Edit1->Enabled = true;
	Button1->Enabled = true;
	ComboBox1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ADOQuery1->Active = false;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM "+TableName+" WHERE "+ComboBox1->Text+" = '"+Edit1->Text+"'");
	try
	{
		ADOQuery1->Active = true;
	}
	catch (Exception *e)
	{
		ADOQuery1->SQL->Clear();
		ShowMessage("There is no such field");
		ADOQuery1->Open();
			ADOQuery1->SQL->Add("SELECT * FROM "+TableName);
	}
	for (int i = 0; i <= ColNum; i++)
	{
		DBGrid1->Columns->Items[i]->Width = 100;
	}
	DBGrid1->Columns->Items[0]->Visible = false;
}

/*		//ADOQuery1->Active = false;
		//ADOQuery1->SQL->Clear();
//		ADOConnection1->Connected = false;
//		ADOConnection1->ConnectionString = "";
		ADOQuery1->Active = false;
		ADOQuery1->SQL->Clear();
		DBGrid1->Visible = false;
		ADOConnection1->Connected = false;
		ADOConnection1->ConnectionString = "";
		ADOQuery1->Close();
		DBDir = OpenDialog1->FileName;
		if (CopyFile(DBDir.w_str(),MyDBDirMDB.w_str(),false))
		{
			ADOConnection1->ConnectionString = "Provider=MSDASQL.1; Persist Security info=False; data source=DBReaderMDB";
//			ADOQuery1->Active = false;
//			ADOQuery1->SQL->Clear();
//			ADOQuery1->SQL->Add("SELECT COUNT(*) AS ColNum FROM schedule");
//			ShowMessage(DBGrid1->Columns->Items[1]->FieldName);
//			ADOQuery1->SQL->Add("SELECT FROM schedule");
//			ADOQuery1->SQL->Count("SELECT * AS ColNum FROM schedule");
//DBGrid.Cells[3,4] считывает информацию из €чейки 3,4

//			ADOQuery1->Active = true;
/*			DBGrid1->DataSource->DataSet->First();
			ShowMessage(DBGrid1->Fields[1]->AsString);
//			ShowMessage(DBGrid1->FieldByName("ColNum")->AsString);*/
			//ADOQuery1->Active = false;
	  /*		ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("SELECT * FROM schedule");
			ADOQuery1->Open();
		   //	ADOQuery1->Active = true;
			DBGrid1->Visible = true;
//			DBGrid1->Columns.Add;
	   //	DBGrid1->Columns->Items[3]->FieldName= "QWERTY";
		}
		//else ShowMessage( SysErrorMessage( GetLastError() ) ); //ShowMessage("!"+OpenDialog1->FileName+"!");    */
		//---------------------------------------------------------------------------
	/*DBGrid1->Columns->Items[0]->FieldName = "qwerty";
	DBGrid1->Columns->Items[1]->FieldName = "qwerty2";
	DBGrid1->Columns->Items[2]->FieldName = "qwerty3";
	int i;
	for (i = 0; i <= 20; i++) {
		DBGrid1->Columns->Items[i]->Visible = false;
	}
			Provider=MSDASQL.1;Persist Security Info=False;User ID=root;Data Source=myDB;Mode=ReadWrite;Initial Catalog=mydb;
			Provider=MSDASQL.1; Persist Security info=False; data source=DBReader
			//ShowMessage(a);  	//DBGrid1->Visible = true;
			//ADODataSet1->CommandText = c;
//			ADODataSet1->Open();
		SELECT * FROM sys.objects WHERE type in (N'U') USE [MyDataBase]
DBGrid->FieldByName("Name")->AsString;
	*/
