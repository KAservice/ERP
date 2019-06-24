#include "vcl.h"
#pragma hdrstop  
#include "UDMSprDepartmentCF.h"
#include "UDMSprDepartmentImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprDepartmentCF::TDMSprDepartmentCF()
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprDepartmentCF::~TDMSprDepartmentCF()
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprDepartmentCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TDMSprDepartmentCF::kanAddRef(void)
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprDepartmentCF::kanRelease(void)
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprDepartmentCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{  
int result=0;  
		TDMSprDepartmentImpl * ob=new TDMSprDepartmentImpl();
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
