#include "vcl.h"
#pragma hdrstop  
#include "UFormaSpiskaInterfMainMenuParCF.h"   
#include "UFormaSpiskaInterfMainMenuParImpl.h"  
#include "IFormaSpiskaInterfMainMenuPar.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaSpiskaInterfMainMenuParCF::TFormaSpiskaInterfMainMenuParCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaSpiskaInterfMainMenuParCF::~TFormaSpiskaInterfMainMenuParCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaSpiskaInterfMainMenuParCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaSpiskaInterfMainMenuParImpl * ob=new TFormaSpiskaInterfMainMenuParImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
