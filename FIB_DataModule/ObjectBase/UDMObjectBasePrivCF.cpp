#include "vcl.h"
#pragma hdrstop  
#include "UDMObjectBasePrivCF.h"   
#include "UDMObjectBasePrivImpl.h"  
#include "IDMObjectBasePriv.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMObjectBasePrivCF::TDMObjectBasePrivCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMObjectBasePrivCF::~TDMObjectBasePrivCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMObjectBasePrivCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMObjectBasePrivCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMObjectBasePrivCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMObjectBasePrivCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMObjectBasePrivImpl * ob=new TDMObjectBasePrivImpl();  
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
