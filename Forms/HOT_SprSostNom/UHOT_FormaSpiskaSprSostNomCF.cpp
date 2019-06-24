#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaSpiskaSprSostNomCF.h"   
#include "UHOT_FormaSpiskaSprSostNomImpl.h"  
#include "IHOT_FormaSpiskaSprSostNom.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaSpiskaSprSostNomCF::THOT_FormaSpiskaSprSostNomCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaSpiskaSprSostNomCF::~THOT_FormaSpiskaSprSostNomCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaSpiskaSprSostNomCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaSpiskaSprSostNomCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaSpiskaSprSostNomCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaSpiskaSprSostNomCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaSpiskaSprSostNomImpl * ob=new THOT_FormaSpiskaSprSostNomImpl();  
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
