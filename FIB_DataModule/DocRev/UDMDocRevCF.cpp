#include "vcl.h"
#pragma hdrstop  
#include "UDMDocRevCF.h"   
#include "UDMDocRevImpl.h"  
#include "IDMDocRev.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMDocRevCF::TDMDocRevCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMDocRevCF::~TDMDocRevCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMDocRevCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMDocRevCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMDocRevCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMDocRevCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMDocRevImpl * ob=new TDMDocRevImpl();  
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
