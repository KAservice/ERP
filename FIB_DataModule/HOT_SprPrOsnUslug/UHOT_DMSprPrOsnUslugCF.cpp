#include "vcl.h"
#pragma hdrstop  
#include "UHOT_DMSprPrOsnUslugCF.h"   
#include "UHOT_DMSprPrOsnUslugImpl.h"  
#include "IHOT_DMSprPrOsnUslug.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_DMSprPrOsnUslugCF::THOT_DMSprPrOsnUslugCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_DMSprPrOsnUslugCF::~THOT_DMSprPrOsnUslugCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_DMSprPrOsnUslugCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_DMSprPrOsnUslugCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_DMSprPrOsnUslugImpl * ob=new THOT_DMSprPrOsnUslugImpl();  
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
