//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *TB_field_hex;
	TButton *Button1;
	TButton *BT_showResult;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TLabel *Label1;
	TButton *Button2;
	TButton *Button14;
	TButton *Button15;
	TEdit *TB_accuracy;
	TLabel *Label2;
	TButton *Button21;
	TEdit *TB_field_dec;
	TEdit *TB_field_oct;
	TEdit *TB_field_bin;
	TButton *Button22;
	TButton *Button23;
	TButton *Button24;
	TButton *Button25;
	TButton *Button26;
	TButton *Button27;
	TButton *Button28;
	TButton *Button29;
	TButton *Button30;
	TButton *Button31;
	TButton *Button32;
	TButton *Button33;
	TButton *Button34;
	TButton *Button35;
	TButton *Button36;
	TButton *Button37;
	TButton *Button38;
	TButton *Button39;
	TButton *Button40;
	TEdit *TB_field;
	TLabel *Label3;
	TButton *Button41;
	TButton *Button42;
	TButton *Button43;
	TProgressBar *ProgressBar1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BT_showResultClick(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall TB_field_hexKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button43Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
