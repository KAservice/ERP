#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaDocOtmenaBronCF.h"   
#include "UHOT_FormaDocOtmenaBronImpl.h"  
#include "IHOT_FormaDocOtmenaBron.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaDocOtmenaBronCF::THOT_FormaDocOtmenaBronCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaDocOtmenaBronCF::~THOT_FormaDocOtmenaBronCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaDocOtmenaBronCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaDocOtmenaBronCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaDocOtmenaBronCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaDocOtmenaBronCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaDocOtmenaBronImpl * ob=new THOT_FormaDocOtmenaBronImpl();  
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
