#include "vcl.h"
#pragma hdrstop  
#include "UHOT_DMSprTypePoselCF.h"   
#include "UHOT_DMSprTypePoselImpl.h"  
#include "IHOT_DMSprTypePosel.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_DMSprTypePoselCF::THOT_DMSprTypePoselCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_DMSprTypePoselCF::~THOT_DMSprTypePoselCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_DMSprTypePoselCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_DMSprTypePoselCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_DMSprTypePoselCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_DMSprTypePoselCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_DMSprTypePoselImpl * ob=new THOT_DMSprTypePoselImpl();  
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
