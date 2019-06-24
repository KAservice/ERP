#include "vcl.h"
#pragma hdrstop  
#include "UFormaDialogaRepSaleCheckCF.h"   
#include "UFormaDialogaRepSaleCheckImpl.h"  
#pragma package(smart_init)
extern int NumObject;  
//---------------------------------------------------------------
TFormaDialogaRepSaleCheckCF::TFormaDialogaRepSaleCheckCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaDialogaRepSaleCheckCF::~TFormaDialogaRepSaleCheckCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaDialogaRepSaleCheckCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaDialogaRepSaleCheckCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaDialogaRepSaleCheckCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaDialogaRepSaleCheckCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaDialogaRepSaleCheckImpl * ob=new TFormaDialogaRepSaleCheckImpl();  
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
