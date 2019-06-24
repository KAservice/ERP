#include "vcl.h"
#pragma hdrstop  
#include "UDMDocRealCF.h"   
#include "UDMDocRealImpl.h"  
#include "IDMDocReal.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMDocRealCF::TDMDocRealCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMDocRealCF::~TDMDocRealCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMDocRealCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMDocRealCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMDocRealCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMDocRealCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMDocRealImpl * ob=new TDMDocRealImpl();  
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
