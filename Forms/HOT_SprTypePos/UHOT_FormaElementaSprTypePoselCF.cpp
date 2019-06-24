#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaElementaSprTypePoselCF.h"   
#include "UHOT_FormaElementaSprTypePoselImpl.h"  
#include "IHOT_FormaElementaSprTypePosel.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaElementaSprTypePoselCF::THOT_FormaElementaSprTypePoselCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaElementaSprTypePoselCF::~THOT_FormaElementaSprTypePoselCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaElementaSprTypePoselCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaElementaSprTypePoselCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaElementaSprTypePoselCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaElementaSprTypePoselCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaElementaSprTypePoselImpl * ob=new THOT_FormaElementaSprTypePoselImpl();  
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
