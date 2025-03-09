//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TsplashScreen *splashScreen;
//---------------------------------------------------------------------------
__fastcall TsplashScreen::TsplashScreen(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
