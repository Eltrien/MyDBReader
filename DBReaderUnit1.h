//---------------------------------------------------------------------------

#ifndef DBReaderUnit1H
#define DBReaderUnit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	TButton *Button1;
	TComboBox *ComboBox1;
	TEdit *Edit1;
	TMenuItem *Close1;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TOpenDialog *OpenDialog1;
	TADOQuery *ADOQuery1;
	TMenuItem *Open1;
	TMenuItem *Close2;
	TEdit *Edit2;
	TLabel *Label1;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Close1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Close2Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
