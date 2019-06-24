#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaElementaSprPrOsnUslugCF.h"   
#include "UHOT_FormaElementaSprPrOsnUslugImpl.h"  
#include "IHOT_FormaElementaSprPrOsnUslug.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaElementaSprPrOsnUslugCF::THOT_FormaElementaSprPrOsnUslugCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaElementaSprPrOsnUslugCF::~THOT_FormaElementaSprPrOsnUslugCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaElementaSprPrOsnUslugCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaElementaSprPrOsnUslugCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaElementaSprPrOsnUslugCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaElementaSprPrOsnUslugCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaElementaSprPrOsnUslugImpl * ob=new THOT_FormaElementaSprPrOsnUslugImpl();  
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
