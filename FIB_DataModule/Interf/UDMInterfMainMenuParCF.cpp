#include "vcl.h"
#pragma hdrstop  
#include "UDMInterfMainMenuParCF.h"   
#include "UDMInterfMainMenuParImpl.h"  
#include "IDMInterfMainMenuPar.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMInterfMainMenuParCF::TDMInterfMainMenuParCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMInterfMainMenuParCF::~TDMInterfMainMenuParCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMInterfMainMenuParCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMInterfMainMenuParCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMInterfMainMenuParCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMInterfMainMenuParCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMInterfMainMenuParImpl * ob=new TDMInterfMainMenuParImpl();  
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
