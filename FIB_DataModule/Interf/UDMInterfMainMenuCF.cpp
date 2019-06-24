#include "vcl.h"
#pragma hdrstop  
#include "UDMInterfMainMenuCF.h"   
#include "UDMInterfMainMenuImpl.h"  
#include "IDMInterfMainMenu.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMInterfMainMenuCF::TDMInterfMainMenuCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMInterfMainMenuCF::~TDMInterfMainMenuCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMInterfMainMenuCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMInterfMainMenuCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMInterfMainMenuCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMInterfMainMenuCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMInterfMainMenuImpl * ob=new TDMInterfMainMenuImpl();  
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
