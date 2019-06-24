#include "vcl.h"
#pragma hdrstop  
#include "UHOT_DMDocOtmenaBronCF.h"   
#include "UHOT_DMDocOtmenaBronImpl.h"  
#include "IHOT_DMDocOtmenaBron.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_DMDocOtmenaBronCF::THOT_DMDocOtmenaBronCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_DMDocOtmenaBronCF::~THOT_DMDocOtmenaBronCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_DMDocOtmenaBronCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_DMDocOtmenaBronCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_DMDocOtmenaBronCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_DMDocOtmenaBronCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_DMDocOtmenaBronImpl * ob=new THOT_DMDocOtmenaBronImpl();  
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
