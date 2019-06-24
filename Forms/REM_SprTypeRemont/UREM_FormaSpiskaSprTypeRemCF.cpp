#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaSpiskaSprTypeRemCF.h"   
#include "UREM_FormaSpiskaSprTypeRemImpl.h"  
#include "IREM_FormaSpiskaSprTypeRem.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaSpiskaSprTypeRemCF::TREM_FormaSpiskaSprTypeRemCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaSpiskaSprTypeRemCF::~TREM_FormaSpiskaSprTypeRemCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaSpiskaSprTypeRemCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaSpiskaSprTypeRemCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaSpiskaSprTypeRemCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaSpiskaSprTypeRemCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaSpiskaSprTypeRemImpl * ob=new TREM_FormaSpiskaSprTypeRemImpl();  
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
